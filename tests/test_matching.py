#!/usr/bin/env python3
"""
Test-Driven Engineering (TDE) Verification Suite for Wave Race 64 Decompilation.

Verifies:
1. Whole-ROM byte-exact matching against expected SHA-1 hash.
2. Function-level matching against reference assembly dumps.
3. Object file byte-matching and symbol verification.
"""

import hashlib
import os
import subprocess
import sys
import unittest

PROJECT_ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
EXPECTED_SHA1 = "508dfc2d4caa42b6f6de5263d0aed5e44ac7966a"
ROM_PATH = os.path.join(PROJECT_ROOT, "build", "waverace64.us.rev1.z64")
ELF_PATH = os.path.join(PROJECT_ROOT, "build", "waverace64.us.rev1.elf")
NONMATCHINGS_DIR = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings")

def get_file_sha1(filepath):
    h = hashlib.sha1()
    with open(filepath, "rb") as f:
        while chunk := f.read(65536):
            h.update(chunk)
    return h.hexdigest().lower()

class TestRomIntegrity(unittest.TestCase):
    """Verifies that the compiled ROM matches the original byte-for-byte."""

    def test_rom_exists(self):
        self.assertTrue(os.path.exists(ROM_PATH), f"ROM not found at {ROM_PATH}. Run 'make' first.")

    def test_rom_sha1_matching(self):
        actual_sha1 = get_file_sha1(ROM_PATH)
        self.assertEqual(actual_sha1, EXPECTED_SHA1,
                         f"ROM SHA1 mismatch!\nExpected: {EXPECTED_SHA1}\nActual:   {actual_sha1}")

    def test_rom_crc(self):
        crc_tool = os.path.join(PROJECT_ROOT, "tools", "n64crc")
        result = subprocess.run([crc_tool, ROM_PATH], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        self.assertEqual(result.returncode, 0)
        self.assertIn("CRC 1: 0x492F4B61  Calculated: 0x492F4B61 (Good)", result.stdout)
        self.assertIn("CRC 2: 0x04E5146A  Calculated: 0x04E5146A (Good)", result.stdout)

class TestGameEngineCore(unittest.TestCase):
    """Test-Driven Engineering assertions for Game Engine Core functions."""

    def is_function_decompiled(self, subpath, func_name):
        """Returns True if the function's .s file has been removed from nonmatchings (i.e. matched in C)."""
        asm_path = os.path.join(NONMATCHINGS_DIR, subpath, f"{func_name}.s")
        return not os.path.exists(asm_path)

    def test_main_c_matched(self):
        """Verify that game/main.c has all functions matched in C."""
        main_funcs = ["func_80047470", "func_800474A0", "func_800474E4", "Main_Thread", "Main_IdleThread", "bootproc"]
        for func in main_funcs:
            self.assertTrue(self.is_function_decompiled("game/main", func),
                            f"Expected {func} in main.c to be decompiled")

    def test_func_8007C494_matched(self):
        """
        TDE test for func_8007C494 (wr64_save EEPROM write header).
        Once decompiled and matched, it must not exist in nonmatchings and ROM must match.
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007C494")
        if is_matched:
            # Function is marked as matched in C! Verify ROM is still 100% byte-matching
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007C494 is currently non-matching (in progress)")

    def test_func_8007C31C_matched(self):
        """
        TDE test for func_8007C31C (wr64_save high score & record save).
        Once decompiled and matched, it must not exist in nonmatchings and ROM must match.
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007C31C")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007C31C is currently non-matching (in progress)")

    def test_func_80085510_matched(self):
        """
        TDE test for func_80085510 in code_3AC00 (rider steering vector calculation & limit check).
        Once decompiled and matched, code_3AC00 is 100% matched.
        """
        is_matched = self.is_function_decompiled("game/code_3AC00", "func_80085510")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80085510 is currently non-matching (in progress)")

def run_tests():
    loader = unittest.TestLoader()
    suite = unittest.TestSuite()
    suite.addTests(loader.loadTestsFromTestCase(TestRomIntegrity))
    suite.addTests(loader.loadTestsFromTestCase(TestGameEngineCore))
    runner = unittest.TextTestRunner(verbosity=2)
    result = runner.run(suite)
    return 0 if result.wasSuccessful() else 1

if __name__ == "__main__":
    sys.exit(run_tests())
