"""Local run guards for installed files and fixed-name saves."""
import ctypes as C
from ctypes import wintypes as W
import hashlib,json,os
from pathlib import Path

FIXED_SAVES=('autosave.fos','autosave.fos.bak','quicksave.fos','quicksave.fos.bak','autosave.nvse','quicksave.nvse')


def documents_folder():
    folder=C.create_unicode_buffer(32768)
    shell=C.WinDLL('shell32',use_last_error=True)
    shell.SHGetFolderPathW.argtypes=[W.HWND,C.c_int,W.HANDLE,W.DWORD,W.LPWSTR]
    shell.SHGetFolderPathW.restype=C.c_long
    if shell.SHGetFolderPathW(None,5,None,0,folder):raise OSError('cannot locate Documents folder')
    return Path(folder.value)


def fixed_save_names(folder):
    return {p.name for p in folder.iterdir() if p.is_file()
            and p.name.lower().startswith(('autosave','quicksave'))} if folder.exists() else set()

class SaveGuard:
    def __init__(self,saves,backup,report):
        self.saves=Path(saves);self.backup=Path(backup);self.report=Path(report)

    def __enter__(self):
        self.backup.mkdir(parents=True,exist_ok=False);self.before={}
        for name in set(FIXED_SAVES)|fixed_save_names(self.saves):
            path=self.saves/name
            if path.exists():
                stat=path.stat();data=path.read_bytes()
                (self.backup/name).write_bytes(data)
                self.before[name]=dict(sha256=hashlib.sha256(data).hexdigest(),
                                      atime_ns=stat.st_atime_ns,mtime_ns=stat.st_mtime_ns)
            else:self.before[name]=None
        (self.backup/'before.json').write_text(json.dumps(self.before,indent=2))
        return self

    def __exit__(self,*exception):
        errors=[];rows=[]
        for name in fixed_save_names(self.saves)-self.before.keys():self.before[name]=None
        for name,old in self.before.items():
            path=self.saves/name
            try:
                now=path.read_bytes() if path.exists() else None
                prior=(self.backup/name).read_bytes() if old else None
                if old and hashlib.sha256(prior).hexdigest()!=old['sha256']:
                    raise RuntimeError('saved backup checksum changed')
                if now!=prior:
                    if now is not None:(self.backup/(name+'.test-output')).write_bytes(now)
                    if prior is None:path.unlink(missing_ok=True)
                    else:path.write_bytes(prior)
                if old:os.utime(path,ns=(old['atime_ns'],old['mtime_ns']))
                found=path.read_bytes() if path.exists() else None
                passed=found==prior and (not old or path.stat().st_mtime_ns==old['mtime_ns'])
                if not passed:raise RuntimeError('restored bytes/timestamp differ')
                rows.append(dict(name=name,passed=True,existed=bool(old)))
            except Exception as exc:errors.append(dict(name=name,error=str(exc)))
        self.report.write_text(json.dumps(dict(passed=not errors,backup=str(self.backup),files=rows,errors=errors),indent=2))
        if errors:raise RuntimeError('fixed-name save restoration failed: '+repr(errors))


class ReadOnlyInstallGuard:
    def __init__(self, paths):
        self.paths = paths
        self.handles = []
        self.k = C.WinDLL('kernel32', use_last_error=True)
        self.k.CreateFileW.argtypes = [W.LPCWSTR, W.DWORD, W.DWORD, C.c_void_p,
                                      W.DWORD, W.DWORD, W.HANDLE]
        self.k.CreateFileW.restype = W.HANDLE
        self.k.CloseHandle.argtypes = [W.HANDLE]

    def __enter__(self):
        try:
            for path in self.paths:
                h = self.k.CreateFileW(str(path), 0x80000000, 1, None, 3, 0x80, None)
                if h == C.c_void_p(-1).value:
                    raise C.WinError(C.get_last_error())
                self.handles.append(h)
            return self
        except BaseException:
            self.__exit__(None, None, None)
            raise

    def __exit__(self, *unused):
        for h in reversed(self.handles):
            self.k.CloseHandle(h)
        self.handles.clear()
