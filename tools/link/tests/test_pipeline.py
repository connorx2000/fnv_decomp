"""Pipeline refusal and restoration contracts, using synthetic inputs only."""
import hashlib
import os
from pathlib import Path
import sys
import tempfile
from types import SimpleNamespace
import unittest
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[1]))
sys.path.insert(0,str(Path(__file__).resolve().parents[2]))
import custom_exe
from run_guards import SaveGuard


class PipelineTests(unittest.TestCase):
    def test_wrong_fingerprints_refuse_before_any_output(self):
        class UnrelatedImage:
            def read(self,address,size):return bytes(size)
        with tempfile.TemporaryDirectory() as d:
            image=Path(d)/'synthetic.exe';image.write_bytes(b'synthetic fixture')
            with patch('compare.Pe',return_value=UnrelatedImage()), patch('shutil.copyfile') as copy:
                with self.assertRaisesRegex(ValueError,'IMAGE CHECK FAILED'):
                    custom_exe.extract(SimpleNamespace(image=image,jobs=1))
                copy.assert_not_called()

    def test_source_digest_ignores_local_artifacts_and_detects_header_edits(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);(root/'include').mkdir();h=root/'include/test.h';h.write_text('struct Test {};')
            with patch.object(custom_exe,'ROOT',root):
                before=custom_exe.source_digest()
                (root/'.local').mkdir();(root/'.local/input.exe').write_bytes(b'synthetic')
                self.assertEqual(before,custom_exe.source_digest())
                h.write_text('struct Test { int value; };')
                self.assertNotEqual(before,custom_exe.source_digest())

    def test_save_guard_restores_bytes_times_and_absence_after_failure(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);saves=root/'saves';saves.mkdir();p=saves/'autosave.fos';p.write_bytes(b'synthetic old save')
            os.utime(p,ns=(1234567890000000000,1234567890000000000));before=p.stat().st_mtime_ns
            with self.assertRaisesRegex(RuntimeError,'synthetic failure'):
                with SaveGuard(saves,root/'backup',root/'checks.json'):
                    p.write_bytes(b'synthetic changed save');(saves/'quicksave.fos').write_bytes(b'temporary')
                    raise RuntimeError('synthetic failure')
            self.assertEqual(p.read_bytes(),b'synthetic old save')
            self.assertEqual(p.stat().st_mtime_ns,before)
            self.assertFalse((saves/'quicksave.fos').exists())
            self.assertEqual((root/'backup/autosave.fos.test-output').read_bytes(),b'synthetic changed save')

    def test_map_lookup_reports_symbol_and_offset(self):
        from debugger import map_address
        with tempfile.TemporaryDirectory() as d:
            p=Path(d)/'synthetic.map';p.write_text(' 0001:00000000 _synthetic_entry 00401000 f synthetic.obj\n')
            self.assertEqual(map_address(p,0x401003)['symbol'],'_synthetic_entry')
            self.assertEqual(map_address(p,0x401003)['offset'],3)
            self.assertIsNone(map_address(p,0x400fff))


if __name__=='__main__':unittest.main()
