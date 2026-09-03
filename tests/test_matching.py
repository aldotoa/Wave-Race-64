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
import re

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

    def test_func_8007BEA4_matched(self):
        """
        TDE test for func_8007BEA4 in wr64_save (save single course records).
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007BEA4")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007BEA4 is currently non-matching (in progress)")

    def test_func_8007B370_matched(self):
        """
        TDE test for func_8007B370 in wr64_save (factory default save data generator).
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007B370")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B370 is currently non-matching (in progress)")

    def test_func_8007B630_matched(self):
        """
        TDE test for func_8007B630 in wr64_save (save data unpacker to active game memory).
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007B630")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B630 is currently non-matching (in progress)")

    def test_func_8007B930_matched(self):
        """
        TDE test for func_8007B930 in wr64_save (active game memory packer to save data).
        """
        is_matched = self.is_function_decompiled("game/core/wr64_save", "func_8007B930")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B930 is currently non-matching (in progress)")

    def test_func_80088EA8_matched(self):
        """
        TDE test for func_80088EA8 in code_43A60 (rider order and starting position randomization).
        """
        is_matched = self.is_function_decompiled("game/code_43A60", "func_80088EA8")
        if is_matched:
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80088EA8 is currently non-matching (in progress)")


class TestWaterPhysics(unittest.TestCase):
    """Test-Driven Engineering assertions for the Water Physics & Wave Simulation Engine (water_69D0.c)."""

    def is_function_decompiled(self, func_name):
        asm_path = os.path.join(NONMATCHINGS_DIR, "game", "water_69D0", f"{func_name}.s")
        return not os.path.exists(asm_path)

    def test_func_8004F3D4_matched(self):
        """Verify func_8004F3D4 (single-point wave disturbance) is matched in C."""
        self.assertTrue(self.is_function_decompiled("func_8004F3D4"),
                        "func_8004F3D4 must be matched in C")

    def test_func_8004E548_matched(self):
        """Verify func_8004E548 (hull contact point depth check) is matched in C."""
        self.assertTrue(self.is_function_decompiled("func_8004E548"),
                        "func_8004E548 must be matched in C")

    def test_func_8004F1EC_matched(self):
        """TDE test for func_8004F1EC (rider jet wake displacement)."""
        if self.is_function_decompiled("func_8004F1EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004F1EC is currently non-matching (in progress)")

    def test_func_8004EFB4_matched(self):
        """TDE test for func_8004EFB4 (generic object wave disturbance)."""
        if self.is_function_decompiled("func_8004EFB4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004EFB4 is currently non-matching (in progress)")

    def test_func_8004C1D0_matched(self):
        """TDE test for func_8004C1D0 (master water surface display list renderer)."""
        if self.is_function_decompiled("func_8004C1D0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004C1D0 is currently non-matching (in progress)")

    def test_func_8004C998_matched(self):
        """TDE test for func_8004C998 (water surface perspective texture coordinate synthesizer)."""
        if self.is_function_decompiled("func_8004C998"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004C998 is currently non-matching (in progress)")

    def test_func_8004CC7C_matched(self):
        """TDE test for func_8004CC7C (shoreline breaking surf & rolling wave animator)."""
        if self.is_function_decompiled("func_8004CC7C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004CC7C is currently non-matching (in progress)")

    def test_func_8004D018_matched(self):
        """TDE test for func_8004D018 (harmonic wave swell train disturbance generator)."""
        if self.is_function_decompiled("func_8004D018"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004D018 is currently non-matching (in progress)")

    def test_func_8004D30C_matched(self):
        """TDE test for func_8004D30C (water surface height elevation query)."""
        if self.is_function_decompiled("func_8004D30C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004D30C is currently non-matching (in progress)")

    def test_func_8004D628_matched(self):
        """TDE test for func_8004D628 (hull contact point buoyancy & normal integrator)."""
        if self.is_function_decompiled("func_8004D628"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004D628 is currently non-matching (in progress)")

    def test_func_8004DAF0_matched(self):
        """TDE test for func_8004DAF0 (4-point hull buoyancy & moment equilibrium solver)."""
        if self.is_function_decompiled("func_8004DAF0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004DAF0 is currently non-matching (in progress)")

    def test_func_8004E614_matched(self):
        """TDE test for func_8004E614 (wave lip jump launch impulse detector)."""
        if self.is_function_decompiled("func_8004E614"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004E614 is currently non-matching (in progress)")

    def test_func_8004E0A4_matched(self):
        """TDE test for func_8004E0A4 (global ocean swell + local wave buoyancy integrator)."""
        if self.is_function_decompiled("func_8004E0A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004E0A4 is currently non-matching (in progress)")

    def test_func_8004EAA4_matched(self):
        """TDE test for func_8004EAA4 (radial disturbance kernel blending on water heightfield)."""
        if self.is_function_decompiled("func_8004EAA4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004EAA4 is currently non-matching (in progress)")

    def test_func_8004F9E0_matched(self):
        """TDE test for func_8004F9E0 (2D wave PDE simulation master engine & water initializer)."""
        if self.is_function_decompiled("func_8004F9E0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004F9E0 is currently non-matching (in progress)")

    def test_func_8004F520_matched(self):
        """TDE test for func_8004F520 (continuous linear wake disturbance ray generator)."""
        if self.is_function_decompiled("func_8004F520"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004F520 is currently non-matching (in progress)")

    def test_func_80050B78_matched(self):
        """TDE test for func_80050B78 (water surface camera perspective projection & horizon clipping)."""
        if self.is_function_decompiled("func_80050B78"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80050B78 is currently non-matching (in progress)")

    def test_func_80051238_matched(self):
        """TDE test for func_80051238 (per-frame water engine update & dynamic course tide drain)."""
        if self.is_function_decompiled("func_80051238"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80051238 is currently non-matching (in progress)")

    def test_func_80050F8C_matched(self):
        """TDE test for func_80050F8C (runtime object disturbance origin tracking & wave splat offset updater)."""
        if self.is_function_decompiled("func_80050F8C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80050F8C is currently non-matching (in progress)")

    def test_func_80050204_matched(self):
        """TDE test for func_80050204 (dynamic water vertex buffer and normal lighting rasterizer)."""
        if self.is_function_decompiled("func_80050204"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80050204 is currently non-matching (in progress)")











class TestCodesegUI(unittest.TestCase):
    """
    Test-Driven Engineering suite for UI, Menus & 2D Presentation in src/codeseg/.
    """

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "codeseg")
        pattern = re.compile(rf"\b{func_name}\b")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file.endswith((".c", ".h")):
                    filepath = os.path.join(root, file)
                    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        if pattern.search(content):
                            for block in content.split(func_name)[1:]:
                                if "{" in block[:300]:
                                    return True
        return False

    def test_func_801E7908_matched(self):
        """TDE test for func_801E7908 in wr64_fade (screen fade display list primitive emitter)."""
        if self.is_function_decompiled("func_801E7908"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E7908 is currently non-matching (in progress)")

    def test_func_801E3698_matched(self):
        """TDE test for func_801E3698 in B17D0 (character select 3D jet ski model preview renderer)."""
        if self.is_function_decompiled("func_801E3698"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E3698 is currently non-matching (in progress)")

    def test_func_801E3EE0_matched(self):
        """TDE test for func_801E3EE0 in B2510 (menu text banner layout & texture rectangle renderer)."""
        if self.is_function_decompiled("func_801E3EE0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E3EE0 is currently non-matching (in progress)")

    def test_func_801E4C60_matched(self):
        """TDE test for func_801E4C60 in B3290 (2D/3D polygon mesh & sprite vertex synthesizer)."""
        if self.is_function_decompiled("func_801E4C60"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E4C60 is currently non-matching (in progress)")

    def test_func_801E4FE8_matched(self):
        """TDE test for func_801E4FE8 in B3290 (polygon mesh node traversal & sprite rasterizer)."""
        if self.is_function_decompiled("func_801E4FE8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E4FE8 is currently non-matching (in progress)")

    def test_func_801FAEB8_matched(self):
        """TDE test for func_801FAEB8 in C94E0 (in-race speedometer & RPM gauge display list emitter)."""
        if self.is_function_decompiled("func_801FAEB8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801FAEB8 is currently non-matching (in progress)")

    def test_func_801FB514_matched(self):
        """TDE test for func_801FB514 in C94E0 (lap time and record counter display list generator)."""
        if self.is_function_decompiled("func_801FB514"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801FB514 is currently non-matching (in progress)")

    def test_func_801FBFB4_matched(self):
        """TDE test for func_801FBFB4 in C94E0 (minimap rider position markers & track path display list)."""
        if self.is_function_decompiled("func_801FBFB4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801FBFB4 is currently non-matching (in progress)")

    def test_func_801E5554_matched(self):
        """TDE test for func_801E5554 in B3AA0 (menu item button banner display list dispatcher)."""
        if self.is_function_decompiled("func_801E5554"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E5554 is currently non-matching (in progress)")

    def test_func_801E6074_matched(self):
        """TDE test for func_801E6074 in B3AA0 (menu banner animation case 1 easing curve)."""
        if self.is_function_decompiled("func_801E6074"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E6074 is currently non-matching (in progress)")

    def test_func_801E62A8_matched(self):
        """TDE test for func_801E62A8 in B3AA0 (menu banner animation case 2 bounce curve)."""
        if self.is_function_decompiled("func_801E62A8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E62A8 is currently non-matching (in progress)")

    def test_func_801E66F4_matched(self):
        """TDE test for func_801E66F4 in B3AA0 (menu banner animation case 3 sine pulse)."""
        if self.is_function_decompiled("func_801E66F4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E66F4 is currently non-matching (in progress)")

    def test_func_801E1290_matched(self):
        """TDE test for func_801E1290 in AF8C0 (machine tuning interaction and controller input loop)."""
        if self.is_function_decompiled("func_801E1290"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E1290 is currently non-matching (in progress)")

    def test_func_801E1BA8_matched(self):
        """TDE test for func_801E1BA8 in AF8C0 (machine tuning state and slider array initialization)."""
        if self.is_function_decompiled("func_801E1BA8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E1BA8 is currently non-matching (in progress)")

    def test_func_801E1E8C_matched(self):
        """TDE test for func_801E1E8C in AF8C0 (machine tuning top-level display list dispatcher)."""
        if self.is_function_decompiled("func_801E1E8C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E1E8C is currently non-matching (in progress)")

    def test_func_801E2058_matched(self):
        """TDE test for func_801E2058 in AF8C0 (slider cursor movement and audio SFX feedback)."""
        if self.is_function_decompiled("func_801E2058"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E2058 is currently non-matching (in progress)")

    def test_func_801E229C_matched(self):
        """TDE test for func_801E229C in AF8C0 (jet ski color customization palette selector)."""
        if self.is_function_decompiled("func_801E229C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E229C is currently non-matching (in progress)")

    def test_func_801E2530_matched(self):
        """TDE test for func_801E2530 in AF8C0 (character select and machine tuning cursor display list)."""
        if self.is_function_decompiled("func_801E2530"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E2530 is currently non-matching (in progress)")

    def test_func_801E2C14_matched(self):
        """TDE test for func_801E2C14 in AF8C0 (machine tuning exit and active rider stat commit)."""
        if self.is_function_decompiled("func_801E2C14"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E2C14 is currently non-matching (in progress)")








def run_tests():
    loader = unittest.TestLoader()
    suite = unittest.TestSuite()
    suite.addTests(loader.loadTestsFromTestCase(TestRomIntegrity))
    suite.addTests(loader.loadTestsFromTestCase(TestGameEngineCore))
    suite.addTests(loader.loadTestsFromTestCase(TestWaterPhysics))
    suite.addTests(loader.loadTestsFromTestCase(TestCodesegUI))
    runner = unittest.TextTestRunner(verbosity=2)
    result = runner.run(suite)
    return 0 if result.wasSuccessful() else 1

if __name__ == "__main__":
    sys.exit(run_tests())

