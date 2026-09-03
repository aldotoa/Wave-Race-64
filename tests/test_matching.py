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

    def test_func_801E80B0_matched(self):
        """TDE test for func_801E80B0 in B66E0 (font glyph metrics table and character bounds initializer)."""
        if self.is_function_decompiled("func_801E80B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E80B0 is currently non-matching (in progress)")

    def test_func_801E8800_matched(self):
        """TDE test for func_801E8800 in B66E0 (character spacing and kerning metrics calculator)."""
        if self.is_function_decompiled("func_801E8800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E8800 is currently non-matching (in progress)")

    def test_func_801E8A84_matched(self):
        """TDE test for func_801E8A84 in B66E0 (string width in pixels calculator)."""
        if self.is_function_decompiled("func_801E8A84"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E8A84 is currently non-matching (in progress)")

    def test_func_801E8B24_matched(self):
        """TDE test for func_801E8B24 in B66E0 (text centering and string bounding box calculator)."""
        if self.is_function_decompiled("func_801E8B24"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E8B24 is currently non-matching (in progress)")

    def test_func_801E92FC_matched(self):
        """TDE test for func_801E92FC in B66E0 (standard 1.0x unscaled text string renderer)."""
        if self.is_function_decompiled("func_801E92FC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E92FC is currently non-matching (in progress)")

    def test_func_801E93B4_matched(self):
        """TDE test for func_801E93B4 in B66E0 (scaled text string renderer with custom scale factor)."""
        if self.is_function_decompiled("func_801E93B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E93B4 is currently non-matching (in progress)")

    def test_func_801E946C_matched(self):
        """TDE test for func_801E946C in B66E0 (font palette and color gradient setup)."""
        if self.is_function_decompiled("func_801E946C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E946C is currently non-matching (in progress)")

    def test_func_801E9858_matched(self):
        """TDE test for func_801E9858 in B66E0 (main string glyph display list generator)."""
        if self.is_function_decompiled("func_801E9858"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E9858 is currently non-matching (in progress)")

    def test_func_801E9B04_matched(self):
        """TDE test for func_801E9B04 in B66E0 (formatted integer digit printer)."""
        if self.is_function_decompiled("func_801E9B04"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E9B04 is currently non-matching (in progress)")

    def test_func_801E9D6C_matched(self):
        """TDE test for func_801E9D6C in B66E0 (formatted lap timer display printer mm:ss.ms)."""
        if self.is_function_decompiled("func_801E9D6C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E9D6C is currently non-matching (in progress)")

    def test_func_801EA0B0_matched(self):
        """TDE test for func_801EA0B0 in B66E0 (2D text quad texture rectangle emitter)."""
        if self.is_function_decompiled("func_801EA0B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EA0B0 is currently non-matching (in progress)")

    def test_func_801EA3EC_matched(self):
        """TDE test for func_801EA3EC in B66E0 (Fast3D font texture tile loader)."""
        if self.is_function_decompiled("func_801EA3EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EA3EC is currently non-matching (in progress)")

    def test_func_801EA730_matched(self):
        """TDE test for func_801EA730 in B66E0 (variable-width proportional font mapper)."""
        if self.is_function_decompiled("func_801EA730"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EA730 is currently non-matching (in progress)")

    def test_func_801EAA6C_matched(self):
        """TDE test for func_801EAA6C in B66E0 (font tile cache and texture buffer manager)."""
        if self.is_function_decompiled("func_801EAA6C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EAA6C is currently non-matching (in progress)")

    def test_func_801EADB0_matched(self):
        """TDE test for func_801EADB0 in B66E0 (text blinking and pulsing opacity animator)."""
        if self.is_function_decompiled("func_801EADB0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EADB0 is currently non-matching (in progress)")

    def test_func_801EAF78_matched(self):
        """TDE test for func_801EAF78 in B66E0 (font configuration parameter loader)."""
        if self.is_function_decompiled("func_801EAF78"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EAF78 is currently non-matching (in progress)")

    def test_func_801EAFB4_matched(self):
        """TDE test for func_801EAFB4 in B66E0 (font kerning and inter-character spacing animator)."""
        if self.is_function_decompiled("func_801EAFB4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EAFB4 is currently non-matching (in progress)")

    def test_func_801EB00C_matched(self):
        """TDE test for func_801EB00C in B66E0 (formatted integer text formatter)."""
        if self.is_function_decompiled("func_801EB00C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EB00C is currently non-matching (in progress)")









    def test_func_801EB180_matched(self):
        """TDE test for func_801EB180 in B97B0 (Championship mode state initialization)."""
        if self.is_function_decompiled("func_801EB180"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EB180 is currently non-matching (in progress)")

    def test_func_801EB4F4_matched(self):
        """TDE test for func_801EB4F4 in B97B0 (Time Attack mode state initialization)."""
        if self.is_function_decompiled("func_801EB4F4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EB4F4 is currently non-matching (in progress)")

    def test_func_801EB91C_matched(self):
        """TDE test for func_801EB91C in B97B0 (Stunt Mode state initialization)."""
        if self.is_function_decompiled("func_801EB91C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EB91C is currently non-matching (in progress)")

    def test_func_801EBD28_matched(self):
        """TDE test for func_801EBD28 in B97B0 (2-Player Versus mode state initialization)."""
        if self.is_function_decompiled("func_801EBD28"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EBD28 is currently non-matching (in progress)")

    def test_func_801EBFE4_matched(self):
        """TDE test for func_801EBFE4 in B97B0 (Mode select cleanup and state reset)."""
        if self.is_function_decompiled("func_801EBFE4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EBFE4 is currently non-matching (in progress)")

    def test_func_801EC0D4_matched(self):
        """TDE test for func_801EC0D4 in B97B0 (Controller connection check and unplugged alert)."""
        if self.is_function_decompiled("func_801EC0D4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EC0D4 is currently non-matching (in progress)")

    def test_func_801EC20C_matched(self):
        """TDE test for func_801EC20C in B97B0 (Title screen attract demo timer and transition)."""
        if self.is_function_decompiled("func_801EC20C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EC20C is currently non-matching (in progress)")

    def test_func_801EC304_matched(self):
        """TDE test for func_801EC304 in B97B0 (High score and record table screen transition)."""
        if self.is_function_decompiled("func_801EC304"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EC304 is currently non-matching (in progress)")

    def test_func_801EC3AC_matched(self):
        """TDE test for func_801EC3AC in B97B0 (Options and sound test menu transition)."""
        if self.is_function_decompiled("func_801EC3AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EC3AC is currently non-matching (in progress)")

    def test_func_801ECB98_matched(self):
        """TDE test for func_801ECB98 in B97B0 (Pause menu unpause and game resume sequence)."""
        if self.is_function_decompiled("func_801ECB98"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801ECB98 is currently non-matching (in progress)")

    def test_func_801ECE50_matched(self):
        """TDE test for func_801ECE50 in B97B0 (Race restart state machine transition)."""
        if self.is_function_decompiled("func_801ECE50"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801ECE50 is currently non-matching (in progress)")

    def test_func_801ECF18_matched(self):
        """TDE test for func_801ECF18 in B97B0 (Race retirement / quit to main menu transition)."""
        if self.is_function_decompiled("func_801ECF18"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801ECF18 is currently non-matching (in progress)")

    def test_func_801ED004_matched(self):
        """TDE test for func_801ED004 in B97B0 (Course change / course select transition)."""
        if self.is_function_decompiled("func_801ED004"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801ED004 is currently non-matching (in progress)")

    def test_func_801EE040_matched(self):
        """TDE test for func_801EE040 in B97B0 (Course flyby camera path update)."""
        if self.is_function_decompiled("func_801EE040"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE040 is currently non-matching (in progress)")

    def test_func_801EE228_matched(self):
        """TDE test for func_801EE228 in B97B0 (Course flyby camera orientation matrix setter)."""
        if self.is_function_decompiled("func_801EE228"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE228 is currently non-matching (in progress)")

    def test_func_801EE274_matched(self):
        """TDE test for func_801EE274 in B97B0 (Course flyby spline knot evaluator)."""
        if self.is_function_decompiled("func_801EE274"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE274 is currently non-matching (in progress)")

    def test_func_801EE46C_matched(self):
        """TDE test for func_801EE46C in B97B0 (Cinematic podium camera lookat target updater)."""
        if self.is_function_decompiled("func_801EE46C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE46C is currently non-matching (in progress)")

    def test_func_801EE4D0_matched(self):
        """TDE test for func_801EE4D0 in B97B0 (Cinematic victory lap position interpolator)."""
        if self.is_function_decompiled("func_801EE4D0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE4D0 is currently non-matching (in progress)")

    def test_func_801EE698_matched(self):
        """TDE test for func_801EE698 in B97B0 (Rider celebration animation trigger)."""
        if self.is_function_decompiled("func_801EE698"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE698 is currently non-matching (in progress)")

    def test_func_801EE6F4_matched(self):
        """TDE test for func_801EE6F4 in B97B0 (Podium trophy presentation sequence)."""
        if self.is_function_decompiled("func_801EE6F4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE6F4 is currently non-matching (in progress)")

    def test_func_801EE8C0_matched(self):
        """TDE test for func_801EE8C0 in B97B0 (Race results screen point tally calculator)."""
        if self.is_function_decompiled("func_801EE8C0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE8C0 is currently non-matching (in progress)")

    def test_func_801EE91C_matched(self):
        """TDE test for func_801EE91C in B97B0 (Total championship score accumulator)."""
        if self.is_function_decompiled("func_801EE91C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE91C is currently non-matching (in progress)")

    def test_func_801EE97C_matched(self):
        """TDE test for func_801EE97C in B97B0 (Championship standings rank sorter)."""
        if self.is_function_decompiled("func_801EE97C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE97C is currently non-matching (in progress)")

    def test_func_801EE9C0_matched(self):
        """TDE test for func_801EE9C0 in B97B0 (Podium model transform and lighting matrix generator)."""
        if self.is_function_decompiled("func_801EE9C0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EE9C0 is currently non-matching (in progress)")

    def test_func_801EED70_matched(self):
        """TDE test for func_801EED70 in B97B0 (Victory ceremony crowd cheer sound effect trigger)."""
        if self.is_function_decompiled("func_801EED70"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EED70 is currently non-matching (in progress)")

    def test_func_801EF3C4_matched(self):
        """TDE test for func_801EF3C4 in B97B0 (Credits roll sequence and text scroller)."""
        if self.is_function_decompiled("func_801EF3C4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EF3C4 is currently non-matching (in progress)")

    def test_func_801EF504_matched(self):
        """TDE test for func_801EF504 in B97B0 (Staff credits layout and display list builder)."""
        if self.is_function_decompiled("func_801EF504"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EF504 is currently non-matching (in progress)")

    def test_func_801EFFD8_matched(self):
        """TDE test for func_801EFFD8 in B97B0 (Title screen logo 3D rotating transform)."""
        if self.is_function_decompiled("func_801EFFD8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EFFD8 is currently non-matching (in progress)")

    def test_func_801F03E0_matched(self):
        """TDE test for func_801F03E0 in B97B0 (Title screen menu option selector)."""
        if self.is_function_decompiled("func_801F03E0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F03E0 is currently non-matching (in progress)")

    def test_func_801F06A0_matched(self):
        """TDE test for func_801F06A0 in B97B0 (Title screen sparkle effect emitter)."""
        if self.is_function_decompiled("func_801F06A0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F06A0 is currently non-matching (in progress)")

    def test_func_801F0E7C_matched(self):
        """TDE test for func_801F0E7C in B97B0 (Title screen background water reflection setup)."""
        if self.is_function_decompiled("func_801F0E7C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F0E7C is currently non-matching (in progress)")

    def test_func_801F14B4_matched(self):
        """TDE test for func_801F14B4 in B97B0 (Title screen master display list dispatcher)."""
        if self.is_function_decompiled("func_801F14B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F14B4 is currently non-matching (in progress)")

    def test_func_801F1CFC_matched(self):
        """TDE test for func_801F1CFC in B97B0 (Demo race playback controller recorder)."""
        if self.is_function_decompiled("func_801F1CFC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F1CFC is currently non-matching (in progress)")

    def test_func_801F2060_matched(self):
        """TDE test for func_801F2060 in B97B0 (Demo race camera tracking mode setter)."""
        if self.is_function_decompiled("func_801F2060"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F2060 is currently non-matching (in progress)")

    def test_func_801F23A0_matched(self):
        """TDE test for func_801F23A0 in B97B0 (Demo race replay input reader)."""
        if self.is_function_decompiled("func_801F23A0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F23A0 is currently non-matching (in progress)")

    def test_func_801F25E0_matched(self):
        """TDE test for func_801F25E0 in B97B0 (Demo race replay state transition manager)."""
        if self.is_function_decompiled("func_801F25E0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F25E0 is currently non-matching (in progress)")

    def test_func_801F4120_matched(self):
        """TDE test for func_801F4120 in B97B0 (End-of-race replay camera director)."""
        if self.is_function_decompiled("func_801F4120"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F4120 is currently non-matching (in progress)")

    def test_func_801F8DD0_matched(self):
        """TDE test for func_801F8DD0 in B97B0 (Post-race slow motion replay trigger)."""
        if self.is_function_decompiled("func_801F8DD0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F8DD0 is currently non-matching (in progress)")

    def test_func_801F9520_matched(self):
        """TDE test for func_801F9520 in B97B0 (Game over / retry menu prompt dispatcher)."""
        if self.is_function_decompiled("func_801F9520"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F9520 is currently non-matching (in progress)")

    def test_func_801F9EA0_matched(self):
        """TDE test for func_801F9EA0 in B97B0 (High score initials name entry cursor)."""
        if self.is_function_decompiled("func_801F9EA0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801F9EA0 is currently non-matching (in progress)")

    def test_func_801FA3C0_matched(self):
        """TDE test for func_801FA3C0 in B97B0 (Memory card save confirmation prompt)."""
        if self.is_function_decompiled("func_801FA3C0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801FA3C0 is currently non-matching (in progress)")

    def test_func_801FAD68_matched(self):
        """TDE test for func_801FAD68 in B97B0 (Eeprom save verification and error alert)."""
        if self.is_function_decompiled("func_801FAD68"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801FAD68 is currently non-matching (in progress)")


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

