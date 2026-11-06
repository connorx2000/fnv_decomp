"""Run only the locally built executable, with crash mapping and file guards."""
import json
import os
from pathlib import Path
import time

from config import LOCAL
from standalone_common import dump
from run_guards import ReadOnlyInstallGuard, SaveGuard, documents_folder


def inventory(folder):
    return {p.relative_to(folder).as_posix(): (p.stat().st_size,p.stat().st_mtime_ns)
            for p in folder.rglob('*') if p.is_file()}


def run(game_dir, timeout=120, on_start=None):
    if not 1<=timeout<=14400:raise ValueError('timeout must be 1..14400 seconds')
    game_dir=Path(game_dir).resolve()
    if not (game_dir/'FalloutNV.exe').is_file() or not (game_dir/'Data').is_dir():
        raise ValueError('game-dir must be an existing Fallout: New Vegas installation')
    if LOCAL.is_relative_to(game_dir) or game_dir.is_relative_to(LOCAL):
        raise ValueError('output folder must be separate from the game folder')
    if not json.loads((LOCAL/'static_checks.json').read_text())['passed']:
        raise ValueError('build has not passed static checks')
    if not (LOCAL/'FalloutNV_src.exe').exists():raise ValueError('run build first')
    from custom_exe import digest,source_digest
    build=json.loads((LOCAL/'build_result.json').read_text())
    if (not build['passed'] or build['source_digest']!=source_digest()
            or build['exe_sha256']!=digest(LOCAL/'FalloutNV_src.exe')):
        raise ValueError('source or executable changed; run extract and build again')
    before=inventory(game_dir)
    stamp=time.strftime('%Y%m%d_%H%M%S')+'_'+str(time.time_ns())
    backup=LOCAL/'runs'/stamp
    backup.mkdir(parents=True)
    saves=documents_folder()/'My Games'/'FalloutNV'/'Saves'
    old_path=os.environ.get('PATH','')
    try:
        # Existing installed files are opened read-only, denying write/delete
        # sharing for the lifetime of the child, including engine diagnostics.
        with SaveGuard(saves,backup/'saves',backup/'save_checks.json'), ReadOnlyInstallGuard(
                [game_dir/name for name in before]):
            os.environ['PATH']=str(game_dir)+os.pathsep+old_path
            from debugger import smoke
            result=smoke(LOCAL,timeout,game_dir,on_start)
    finally:
        os.environ['PATH']=old_path
        after=inventory(game_dir)
        changed=sorted(n for n in before.keys()|after.keys() if before.get(n)!=after.get(n))
        dump(backup/'installation_checks.json',dict(passed=not changed,changed=changed))
    dump(backup/'debug_report.json',result)
    for error in result.get('exceptions',[]):
        mapping=error.get('mapping') or {}
        print('%s %s at %s: %s+0x%x' % ('first chance' if error['first_chance'] else 'UNHANDLED',
              error['code'],error['address'],mapping.get('symbol','outside mapped image'),mapping.get('offset',0)))
    print('Run report: '+str(backup))
    if changed:raise RuntimeError('installation changed during run: '+str(changed))
    if not result.get('launched') or any(not e['first_chance'] for e in result.get('exceptions',[])):
        raise RuntimeError('launch failed or unhandled exception recorded')
    return result
