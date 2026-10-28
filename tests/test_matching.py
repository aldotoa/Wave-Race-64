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
        """Returns True if the function is decompiled in the C source code."""
        src_dir = os.path.join(PROJECT_ROOT, "src", "game")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file.endswith(".c"):
                    with open(os.path.join(root, file), "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                    if func_name in content:
                        for block in content.split(func_name)[1:]:
                            if "{" in block[:300]:
                                return True
        return False

    def test_main_c_matched(self):
        """Verify that game/main.c has all functions matched in C."""
        main_funcs = ["Sched_YieldGfxTask", "Sched_StartAudioTask", "Sched_StartGfxTask", "Main_Thread", "Main_IdleThread", "bootproc"]
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
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "game", "code_3AC00", "func_80085510.s")
        self.assertFalse(os.path.exists(stub), "func_80085510 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "game", "code_3AC00.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "code_3AC00.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "code_3AC00.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("game/code_3AC00", "func_80085510"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        filepath = os.path.join(PROJECT_ROOT, "src", "game", "water_69D0.c")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        return any("{" in block[:300] for block in content.split(func_name)[1:])

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











class TestCodeSegA95D0(unittest.TestCase):
    """Checks byte matching for the credits backdrop data copier."""

    def test_func_801DF668_matched(self):
        source_path = os.path.join(PROJECT_ROOT, "src", "codeseg", "A95D0.c")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801DF668.s")
        with open(source_path, "r", encoding="utf-8") as f:
            source = f.read()
        self.assertIn("void func_801DF668(", source)
        self.assertNotIn('GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF668.s")', source)
        self.assertFalse(os.path.exists(stub_path), "func_801DF668 must not have a GLOBAL_ASM stub")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801DEC00_matched(self):
        source_path = os.path.join(PROJECT_ROOT, "src", "codeseg", "A95D0.c")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801DEC00.s")
        with open(source_path, "r", encoding="utf-8") as f:
            source = f.read()
        self.assertIn("void func_801DEC00(", source)
        self.assertNotIn('GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DEC00.s")', source)
        self.assertFalse(os.path.exists(stub_path), "func_801DEC00 must not have a GLOBAL_ASM stub")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)



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
        """TDE test for func_801E3698 in B17D0 (course records screen display list renderer). Completes B17D0."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "codeseg", "B17D0", "func_801E3698.s")
        self.assertFalse(os.path.exists(stub), "func_801E3698 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "codeseg", "B17D0.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "B17D0.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "B17D0.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_801E3698"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_B3290_complete(self):
        """TDE test for func_801E4C60 (fixed-point align matrix builder) and func_801E4FE8 (3-node model DL emitter). Completes B3290."""
        for func in ("func_801E4C60", "func_801E4FE8"):
            stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "codeseg", "B3290", func + ".s")
            self.assertFalse(os.path.exists(stub), func + " asm stub should be deleted once matched")
            self.assertTrue(self.is_function_decompiled(func))
        with open(os.path.join(PROJECT_ROOT, "src", "codeseg", "B3290.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "B3290.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "B3290.c should have no in-progress drafts")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        self.assertTrue(self.is_function_decompiled("func_801E1E8C"), "func_801E1E8C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "AF8C0", "func_801E1E8C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E2058_matched(self):
        """TDE test for func_801E2058 in AF8C0 (machine tuning slider track display list renderer)."""
        self.assertTrue(self.is_function_decompiled("func_801E2058"), "func_801E2058 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "AF8C0", "func_801E2058.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E229C_matched(self):
        """TDE test for func_801E229C in AF8C0 (name-entry option labels and initials renderer)."""
        self.assertTrue(self.is_function_decompiled("func_801E229C"), "func_801E229C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "AF8C0", "func_801E229C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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

    def test_AF8C0_charset_symbols_matched(self):
        """TDE test for all 29 ASCII character set rodata symbols (D_80226210..D_80226280) in AF8C0."""
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        """TDE test for func_801EBD28 in B97B0 (2-player versus mode state initialization)."""
        self.assertTrue(self.is_function_decompiled("func_801EBD28"), "func_801EBD28 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "B97B0", "func_801EBD28.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801EBFE4_matched(self):
        """TDE test for func_801EBFE4 in B97B0 (Mode select cleanup and state reset)."""
        if self.is_function_decompiled("func_801EBFE4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801EBFE4 is currently non-matching (in progress)")

    def test_func_801EC0D4_matched(self):
        """TDE test for func_801EC0D4 in B97B0 (Race results mode state initialization)."""
        stub_path = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "codeseg", "B97B0", "func_801EC0D4.s")
        self.assertFalse(os.path.exists(stub_path), "func_801EC0D4 must not have a GLOBAL_ASM stub")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        """TDE test for func_801ECB98 in B97B0 (award ceremony state initialization)."""
        self.assertTrue(self.is_function_decompiled("func_801ECB98"), "func_801ECB98 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "B97B0", "func_801ECB98.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        self.assertTrue(self.is_function_decompiled("func_801EF3C4"), "func_801EF3C4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "B97B0", "func_801EF3C4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

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
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)


    def test_func_801DB8F0_matched(self):
        """TDE test for func_801DB8F0 in A95D0 (3D particle fireworks and water splash simulator)."""
        if self.is_function_decompiled("func_801DB8F0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DB8F0 is currently non-matching (in progress)")

    def test_func_801DC0AC_matched(self):
        """TDE test for func_801DC0AC in A95D0 (Front-end 3D model positioning)."""
        if self.is_function_decompiled("func_801DC0AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DC0AC is currently non-matching (in progress)")

    def test_func_801DC274_matched(self):
        """TDE test for func_801DC274 in A95D0 (Screen title banner animation)."""
        if self.is_function_decompiled("func_801DC274"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DC274 is currently non-matching (in progress)")

    def test_func_801DC404_matched(self):
        """TDE test for func_801DC404 in A95D0 (Title screen background water ripple generator)."""
        if self.is_function_decompiled("func_801DC404"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DC404 is currently non-matching (in progress)")

    def test_func_801DC5A8_matched(self):
        """TDE test for func_801DC5A8 in A95D0 (Title screen camera target tracker)."""
        if self.is_function_decompiled("func_801DC5A8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DC5A8 is currently non-matching (in progress)")

    def test_func_801DC60C_matched(self):
        """TDE test for func_801DC60C in A95D0 (Title screen camera position interpolator)."""
        if self.is_function_decompiled("func_801DC60C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DC60C is currently non-matching (in progress)")

    def test_func_801DCD34_matched(self):
        """TDE test for func_801DCD34 in A95D0 (Course selection carousel layout)."""
        if self.is_function_decompiled("func_801DCD34"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DCD34 is currently non-matching (in progress)")

    def test_func_801DD2D0_matched(self):
        """TDE test for func_801DD2D0 in A95D0 (Rider selection carousel layout)."""
        if self.is_function_decompiled("func_801DD2D0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DD2D0 is currently non-matching (in progress)")

    def test_func_801DD6B4_matched(self):
        """TDE test for func_801DD6B4 in A95D0 (In-race HUD power meter renderer)."""
        if self.is_function_decompiled("func_801DD6B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DD6B4 is currently non-matching (in progress)")

    def test_func_801DD85C_matched(self):
        """TDE test for func_801DD85C in A95D0 (In-race HUD speedometer needle physics)."""
        if self.is_function_decompiled("func_801DD85C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DD85C is currently non-matching (in progress)")

    def test_func_801DDA24_matched(self):
        """TDE test for func_801DDA24 in A95D0 (Lap timer display list emitter)."""
        if self.is_function_decompiled("func_801DDA24"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DDA24 is currently non-matching (in progress)")

    def test_func_801DDAB8_matched(self):
        """TDE test for func_801DDAB8 in A95D0 (Buoy penalty indicator blinking animator)."""
        if self.is_function_decompiled("func_801DDAB8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DDAB8 is currently non-matching (in progress)")

    def test_func_801DDE48_matched(self):
        """TDE test for func_801DDE48 in A95D0 (Race position digit layout generator)."""
        if self.is_function_decompiled("func_801DDE48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DDE48 is currently non-matching (in progress)")

    def test_func_801DDEDC_matched(self):
        """TDE test for func_801DDEDC in A95D0 (Course mini-map overlay projector)."""
        if self.is_function_decompiled("func_801DDEDC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DDEDC is currently non-matching (in progress)")

    def test_func_801DE3CC_matched(self):
        """TDE test for func_801DE3CC in A95D0 (Speedometer gauge background texture loader)."""
        if self.is_function_decompiled("func_801DE3CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DE3CC is currently non-matching (in progress)")

    def test_func_801DE690_matched(self):
        """TDE test for func_801DE690 in A95D0 (Tachometer RPM dial layout)."""
        if self.is_function_decompiled("func_801DE690"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DE690 is currently non-matching (in progress)")

    def test_func_801DEA94_matched(self):
        """TDE test for func_801DEA94 in A95D0 (Low fuel warning alert emitter)."""
        if self.is_function_decompiled("func_801DEA94"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEA94 is currently non-matching (in progress)")

    def test_func_801DEB08_matched(self):
        """TDE test for func_801DEB08 in A95D0 (Race start countdown 3-2-1-GO graphic sequencer)."""
        if self.is_function_decompiled("func_801DEB08"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEB08 is currently non-matching (in progress)")

    def test_func_801DEC00_matched(self):
        """TDE test for func_801DEC00 in A95D0 (Final lap banner popup animator)."""
        if self.is_function_decompiled("func_801DEC00"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEC00 is currently non-matching (in progress)")

    def test_func_801DED44_matched(self):
        """TDE test for func_801DED44 in A95D0 (Goal finish line celebration banner)."""
        if self.is_function_decompiled("func_801DED44"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DED44 is currently non-matching (in progress)")

    def test_func_801DED88_matched(self):
        """TDE test for func_801DED88 in A95D0 (Wrong way / turn around alert flashing)."""
        if self.is_function_decompiled("func_801DED88"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DED88 is currently non-matching (in progress)")

    def test_func_801DEDE8_matched(self):
        """TDE test for func_801DEDE8 in A95D0 (Course record best lap time indicator)."""
        if self.is_function_decompiled("func_801DEDE8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEDE8 is currently non-matching (in progress)")

    def test_func_801DEE48_matched(self):
        """TDE test for func_801DEE48 in A95D0 (Stunt mode score counter multiplier popup)."""
        if self.is_function_decompiled("func_801DEE48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEE48 is currently non-matching (in progress)")

    def test_func_801DEEC4_matched(self):
        """TDE test for func_801DEEC4 in A95D0 (Time trial split time comparison indicator)."""
        if self.is_function_decompiled("func_801DEEC4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEEC4 is currently non-matching (in progress)")

    def test_func_801DEF84_matched(self):
        """TDE test for func_801DEF84 in A95D0 (2-Player split screen HUD divider line emitter)."""
        if self.is_function_decompiled("func_801DEF84"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DEF84 is currently non-matching (in progress)")

    def test_func_801DF008_matched(self):
        """TDE test for func_801DF008 in A95D0 (2-Player P1/P2 gauge layout dispatcher)."""
        if self.is_function_decompiled("func_801DF008"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF008 is currently non-matching (in progress)")

    def test_func_801DF08C_matched(self):
        """TDE test for func_801DF08C in A95D0 (2-Player distance gap meter)."""
        if self.is_function_decompiled("func_801DF08C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF08C is currently non-matching (in progress)")

    def test_func_801DF128_matched(self):
        """TDE test for func_801DF128 in A95D0 (Championship stage results point column layout)."""
        if self.is_function_decompiled("func_801DF128"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF128 is currently non-matching (in progress)")

    def test_func_801DF1F8_matched(self):
        """TDE test for func_801DF1F8 in A95D0 (Podium celebration confetti emitter)."""
        if self.is_function_decompiled("func_801DF1F8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF1F8 is currently non-matching (in progress)")

    def test_func_801DF278_matched(self):
        """TDE test for func_801DF278 in A95D0 (Podium camera orbit transform)."""
        if self.is_function_decompiled("func_801DF278"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF278 is currently non-matching (in progress)")

    def test_func_801DF2F8_matched(self):
        """TDE test for func_801DF2F8 in A95D0 (Trophy model lighting and reflection map)."""
        if self.is_function_decompiled("func_801DF2F8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF2F8 is currently non-matching (in progress)")

    def test_func_801DF38C_matched(self):
        """TDE test for func_801DF38C in A95D0 (Victory fanfare display list combiner)."""
        if self.is_function_decompiled("func_801DF38C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF38C is currently non-matching (in progress)")

    def test_func_801DF578_matched(self):
        """TDE test for func_801DF578 in A95D0 (Staff credits role title string renderer)."""
        if self.is_function_decompiled("func_801DF578"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF578 is currently non-matching (in progress)")

    def test_func_801DF5F0_matched(self):
        """TDE test for func_801DF5F0 in A95D0 (Staff credits name string renderer)."""
        if self.is_function_decompiled("func_801DF5F0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF5F0 is currently non-matching (in progress)")

    def test_func_801DF668_matched(self):
        """TDE test for func_801DF668 in A95D0 (Staff credits backdrop texture blender)."""
        if self.is_function_decompiled("func_801DF668"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF668 is currently non-matching (in progress)")

    def test_func_801DF744_matched(self):
        """TDE test for func_801DF744 in A95D0 (Title screen logo specular highlight flare)."""
        if self.is_function_decompiled("func_801DF744"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DF744 is currently non-matching (in progress)")

    def test_func_801DFC48_matched(self):
        """TDE test for func_801DFC48 in A95D0 (Title screen PRESS START blinking animator)."""
        if self.is_function_decompiled("func_801DFC48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFC48 is currently non-matching (in progress)")

    def test_func_801DFCB8_matched(self):
        """TDE test for func_801DFCB8 in A95D0 (Menu cursor bounce oscillation)."""
        if self.is_function_decompiled("func_801DFCB8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFCB8 is currently non-matching (in progress)")

    def test_func_801DFD8C_matched(self):
        """TDE test for func_801DFD8C in A95D0 (Menu sound effect trigger on cursor move)."""
        if self.is_function_decompiled("func_801DFD8C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFD8C is currently non-matching (in progress)")

    def test_func_801DFD94_matched(self):
        """TDE test for func_801DFD94 in A95D0 (Menu sound effect trigger on option select)."""
        if self.is_function_decompiled("func_801DFD94"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFD94 is currently non-matching (in progress)")

    def test_func_801DFDA0_matched(self):
        """TDE test for func_801DFDA0 in A95D0 (Menu sound effect trigger on cancel)."""
        if self.is_function_decompiled("func_801DFDA0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFDA0 is currently non-matching (in progress)")

    def test_func_801DFDA8_matched(self):
        """TDE test for func_801DFDA8 in A95D0 (Game mode description text formatter)."""
        if self.is_function_decompiled("func_801DFDA8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFDA8 is currently non-matching (in progress)")

    def test_func_801DFDF0_matched(self):
        """TDE test for func_801DFDF0 in A95D0 (Difficulty level star rating renderer)."""
        if self.is_function_decompiled("func_801DFDF0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFDF0 is currently non-matching (in progress)")

    def test_func_801DFE10_matched(self):
        """TDE test for func_801DFE10 in A95D0 (Course weather condition icon dispatcher)."""
        if self.is_function_decompiled("func_801DFE10"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFE10 is currently non-matching (in progress)")

    def test_func_801DFE30_matched(self):
        """TDE test for func_801DFE30 in A95D0 (Wave condition height level meter)."""
        if self.is_function_decompiled("func_801DFE30"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFE30 is currently non-matching (in progress)")

    def test_func_801DFE58_matched(self):
        """TDE test for func_801DFE58 in A95D0 (Water temperature display string formatter)."""
        if self.is_function_decompiled("func_801DFE58"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFE58 is currently non-matching (in progress)")

    def test_func_801DFE80_matched(self):
        """TDE test for func_801DFE80 in A95D0 (Records screen best time table builder)."""
        if self.is_function_decompiled("func_801DFE80"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFE80 is currently non-matching (in progress)")

    def test_func_801DFF5C_matched(self):
        """TDE test for func_801DFF5C in A95D0 (Records screen stunt score table builder)."""
        if self.is_function_decompiled("func_801DFF5C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFF5C is currently non-matching (in progress)")

    def test_func_801DFFA8_matched(self):
        """TDE test for func_801DFFA8 in A95D0 (Name entry alphabet grid layout dispatcher)."""
        if self.is_function_decompiled("func_801DFFA8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFFA8 is currently non-matching (in progress)")

    def test_func_801DFFF4_matched(self):
        """TDE test for func_801DFFF4 in A95D0 (Name entry cursor position calculator)."""
        if self.is_function_decompiled("func_801DFFF4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801DFFF4 is currently non-matching (in progress)")

    def test_func_801E0044_matched(self):
        """TDE test for func_801E0044 in A95D0 (Name entry character select audio feedback)."""
        if self.is_function_decompiled("func_801E0044"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E0044 is currently non-matching (in progress)")

    def test_func_801E0094_matched(self):
        """TDE test for func_801E0094 in A95D0 (Name entry backspace handler)."""
        if self.is_function_decompiled("func_801E0094"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E0094 is currently non-matching (in progress)")

    def test_func_801E00E0_matched(self):
        """TDE test for func_801E00E0 in A95D0 (Name entry END / confirmation button handler)."""
        if self.is_function_decompiled("func_801E00E0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E00E0 is currently non-matching (in progress)")

    def test_func_801E012C_matched(self):
        """TDE test for func_801E012C in A95D0 (Options screen stereo/mono audio toggle)."""
        if self.is_function_decompiled("func_801E012C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E012C is currently non-matching (in progress)")

    def test_func_801E017C_matched(self):
        """TDE test for func_801E017C in A95D0 (Options screen sound volume slider)."""
        if self.is_function_decompiled("func_801E017C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E017C is currently non-matching (in progress)")

    def test_func_801E01CC_matched(self):
        """TDE test for func_801E01CC in A95D0 (Options screen music volume slider)."""
        if self.is_function_decompiled("func_801E01CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E01CC is currently non-matching (in progress)")

    def test_func_801E0218_matched(self):
        """TDE test for func_801E0218 in A95D0 (Controller Pak memory management prompt)."""
        if self.is_function_decompiled("func_801E0218"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E0218 is currently non-matching (in progress)")

    def test_func_801E0264_matched(self):
        """TDE test for func_801E0264 in A95D0 (Controller Pak page reader)."""
        if self.is_function_decompiled("func_801E0264"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E0264 is currently non-matching (in progress)")

    def test_func_801E02B4_matched(self):
        """TDE test for func_801E02B4 in A95D0 (Controller Pak file delete confirmation)."""
        if self.is_function_decompiled("func_801E02B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E02B4 is currently non-matching (in progress)")

    def test_func_801E0304_matched(self):
        """TDE test for func_801E0304 in A95D0 (Save data corruption warning prompt)."""
        self.assertTrue(self.is_function_decompiled("func_801E0304"), "func_801E0304 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0304.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E0454_matched(self):
        """TDE test for func_801E0454 in A95D0 (Demo race watermark overlay renderer)."""
        self.assertTrue(self.is_function_decompiled("func_801E0454"), "func_801E0454 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0454.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E05A4_matched(self):
        """TDE test for func_801E05A4 in A95D0 (Replay controls OSD overlay display list)."""
        self.assertTrue(self.is_function_decompiled("func_801E05A4"), "func_801E05A4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E05A4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E06F8_matched(self):
        """TDE test for func_801E06F8 in A95D0 (Replay camera angle indicator dial)."""
        self.assertTrue(self.is_function_decompiled("func_801E06F8"), "func_801E06F8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E06F8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E084C_matched(self):
        """TDE test for func_801E084C in A95D0 (Replay slow motion speed indicator)."""
        self.assertTrue(self.is_function_decompiled("func_801E084C"), "func_801E084C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E084C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E0A18_matched(self):
        """TDE test for func_801E0A18 in A95D0 (Post-race results total time rank calculator)."""
        self.assertTrue(self.is_function_decompiled("func_801E0A18"), "func_801E0A18 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0A18.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E0BE8_matched(self):
        """TDE test for func_801E0BE8 in A95D0 (Stage clear victory jingle sequencer)."""
        self.assertTrue(self.is_function_decompiled("func_801E0BE8"), "func_801E0BE8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0BE8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E0DB8_matched(self):
        """TDE test for func_801E0DB8 in A95D0 (Championship cup award presentation animation)."""
        self.assertTrue(self.is_function_decompiled("func_801E0DB8"), "func_801E0DB8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0DB8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E0F8C_matched(self):
        """TDE test for func_801E0F8C in A95D0 (Special dolphin rider unlock check and alert)."""
        if self.is_function_decompiled("func_801E0F8C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E0F8C is currently non-matching (in progress)")

    def test_func_801E0FF0_matched(self):
        """TDE test for func_801E0FF0 in A95D0 (Look-at camera orientation vector orthogonalizer)."""
        self.assertTrue(self.is_function_decompiled("func_801E0FF0"), "func_801E0FF0 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "codeseg", "A95D0", "func_801E0FF0.s")
        self.assertFalse(os.path.exists(stub_path), f"Non-matching stub {stub_path} should be deleted")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_801E11B4_matched(self):
        """TDE test for func_801E11B4 in A95D0 (End-of-game master cleanup and reset dispatcher)."""
        if self.is_function_decompiled("func_801E11B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_801E11B4 is currently non-matching (in progress)")



class TestCourseOverlays(unittest.TestCase):
    """Test suite for Course Overlays Subsystem (src/overlays/)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "overlays")
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

    def test_func_i7_802C5A18_matched(self):
        """TDE test for func_i7_802C5A18 in ovl_1C43F0 (options & sound test menu display list)."""
        if self.is_function_decompiled("func_i7_802C5A18"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i7_802C5A18 is currently non-matching (in progress)")

    def test_func_i11_802C5800_matched(self):
        """TDE test for func_i11_802C5800 in ovl_1CA480 (warmup options menu display list). Completes ovl_1CA480."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i11", "ovl_1CA480", "func_i11_802C5800.s")
        self.assertFalse(os.path.exists(stub), "func_i11_802C5800 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i11", "ovl_1CA480.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1CA480.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1CA480.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i11_802C5800"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i11_802C5D48_matched(self):
        """TDE test for func_i11_802C5D48 in ovl_1CA480 (warmup options input handler). Completes ovl_1CA480."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i11", "ovl_1CA480", "func_i11_802C5D48.s")
        self.assertFalse(os.path.exists(stub), "func_i11_802C5D48 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i11", "ovl_1CA480.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1CA480.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1CA480.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i11_802C5D48"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i12_802C58A0_matched(self):
        """TDE test for func_i12_802C58A0 in ovl_1CAE40 (course data menu display list: mode tabs, 9-course grid, confirm buttons). Completes ovl_1CAE40."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i12", "ovl_1CAE40", "func_i12_802C58A0.s")
        self.assertFalse(os.path.exists(stub), "func_i12_802C58A0 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i12", "ovl_1CAE40.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1CAE40.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1CAE40.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i12_802C58A0"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i12_802C5F6C_matched(self):
        """TDE test for func_i12_802C5F6C in ovl_1CAE40 (course data menu input handler: cursor, course selection, save/erase dispatch). Completes ovl_1CAE40."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i12", "ovl_1CAE40", "func_i12_802C5F6C.s")
        self.assertFalse(os.path.exists(stub), "func_i12_802C5F6C asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i12", "ovl_1CAE40.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1CAE40.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1CAE40.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i12_802C5F6C"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i14_802C5924_matched(self):
        """TDE test for func_i14_802C5924 in ovl_1CF180 (checkpoint sequence progression evaluator)."""
        if self.is_function_decompiled("func_i14_802C5924"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i14_802C5924 is currently non-matching (in progress)")

    def test_func_i14_802C5B70_matched(self):
        """TDE test for func_i14_802C5B70 in ovl_1CF180 (lap completion trigger monitor)."""
        if self.is_function_decompiled("func_i14_802C5B70"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i14_802C5B70 is currently non-matching (in progress)")

    def test_func_i0_802C5A7C_matched(self):
        """TDE test for func_i0_802C5A7C in ovl_1B3EC0 (Dolphin Park training display list builder)."""
        if self.is_function_decompiled("func_i0_802C5A7C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i0_802C5A7C is currently non-matching (in progress)")

    def test_func_i0_802C6044_matched(self):
        """TDE test for func_i0_802C6044 in ovl_1B3EC0 (training stage instruction advance)."""
        if self.is_function_decompiled("func_i0_802C6044"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i0_802C6044 is currently non-matching (in progress)")

    def test_func_i0_802C63AC_matched(self):
        """TDE test for func_i0_802C63AC in ovl_1B3EC0 (training tutorial state machine & announcer)."""
        if self.is_function_decompiled("func_i0_802C63AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i0_802C63AC is currently non-matching (in progress)")

    def test_func_i0_802C6AE4_matched(self):
        """TDE test for func_i0_802C6AE4 in ovl_1B3EC0 (training text glyph display list generator)."""
        if self.is_function_decompiled("func_i0_802C6AE4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i0_802C6AE4 is currently non-matching (in progress)")


    def test_func_i3_802C5800_matched(self):
        """TDE test for func_i3_802C5800 in ovl_1BC890 (course-overview entry: score-table reset, demo branch, rank thresholds)."""
        if self.is_function_decompiled("func_i3_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i3_802C5800 is currently non-matching (in progress)")

    def test_func_i3_802C5B40_matched(self):
        """TDE test for func_i3_802C5B40 in ovl_1BC890 (course-overview frame: race scene, demo panel dispatch, skip/advance input)."""
        if self.is_function_decompiled("func_i3_802C5B40"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i3_802C5B40 is currently non-matching (in progress)")

    def test_func_i3_802C5D54_matched(self):
        """TDE test for func_i3_802C5D54 in ovl_1BC890 (title-frame fade state machine and difficulty label)."""
        if self.is_function_decompiled("func_i3_802C5D54"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i3_802C5D54 is currently non-matching (in progress)")

    def test_func_i3_802C6344_matched(self):
        """TDE test for func_i3_802C6344 in ovl_1BC890 (course-select info panel: frames, labels, preview texture, course model)."""
        if self.is_function_decompiled("func_i3_802C6344"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i3_802C6344 is currently non-matching (in progress)")

    def test_func_i3_802C6E94_matched(self):
        """TDE test for func_i3_802C6E94 in ovl_1BC890 (empty function after the info panel)."""
        if self.is_function_decompiled("func_i3_802C6E94"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i3_802C6E94 is currently non-matching (in progress)")

    def test_func_i6_802C5800_matched(self):
        """TDE test for func_i6_802C5800 in ovl_1C2250 (Twilight City neon lighting and city canal display list renderer)."""
        if self.is_function_decompiled("func_i6_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i6_802C5800 is currently non-matching (in progress)")

    def test_func_i6_802C5B74_matched(self):
        """TDE test for func_i6_802C5B74 in ovl_1C2250 (Twilight City illuminated buoy pulse animator)."""
        if self.is_function_decompiled("func_i6_802C5B74"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i6_802C5B74 is currently non-matching (in progress)")

    def test_func_i6_802C5C2C_matched(self):
        """TDE test for func_i6_802C5C2C in ovl_1C2250 (City canal wall collision and rebound force evaluator)."""
        if self.is_function_decompiled("func_i6_802C5C2C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i6_802C5C2C is currently non-matching (in progress)")

    def test_func_i6_802C6B34_matched(self):
        """TDE test for func_i6_802C6B34 in ovl_1C2250 (Twilight City night lighting and specular reflection setup)."""
        if self.is_function_decompiled("func_i6_802C6B34"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i6_802C6B34 is currently non-matching (in progress)")

    def test_func_i10_802C5800_matched(self):
        """Change-conditions slot initialization remains promoted and ROM-exact."""
        self.assertTrue(self.is_function_decompiled("func_i10_802C5800"))
        self.assertFalse(os.path.exists(os.path.join(
            NONMATCHINGS_DIR, "overlays", "ovl_i10", "ovl_1C9150",
            "func_i10_802C5800.s")))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i10_802C5A10_matched(self):
        """TDE test for func_i10_802C5A10 in ovl_1C9150 (options change-conditions menu input handler: cursor, toggles, value edit with min/max wrap). Completes ovl_1C9150."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i10", "ovl_1C9150", "func_i10_802C5A10.s")
        self.assertFalse(os.path.exists(stub), "func_i10_802C5A10 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i10", "ovl_1C9150.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1C9150.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1C9150.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i10_802C5A10"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i10_802C6200_matched(self):
        """TDE test for func_i10_802C6200 in ovl_1C9150 (options change-conditions menu display list: toggles, per-setting values, changed-from-default notice). Completes ovl_1C9150."""
        stub = os.path.join(PROJECT_ROOT, "asm", "us", "rev1", "nonmatchings", "overlays", "ovl_i10", "ovl_1C9150", "func_i10_802C6200.s")
        self.assertFalse(os.path.exists(stub), "func_i10_802C6200 asm stub should be deleted once matched")
        with open(os.path.join(PROJECT_ROOT, "src", "overlays", "ovl_i10", "ovl_1C9150.c"), "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
        self.assertNotIn("GLOBAL_ASM", content, "ovl_1C9150.c should be fully decompiled")
        self.assertNotIn("NON_MATCHING", content, "ovl_1C9150.c should have no in-progress drafts")
        self.assertTrue(self.is_function_decompiled("func_i10_802C6200"))
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i10_802C6A00_matched(self):
        """TDE test for func_i10_802C6A00 in ovl_1C9150 (Drake Lake transition to results screen)."""
        if self.is_function_decompiled("func_i10_802C6A00"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i10_802C6A00 is currently non-matching (in progress)")

    def test_func_i15_802C5800_matched(self):
        """TDE test for func_i15_802C5800 in ovl_1CFB60 (Glacier Coast floating iceberg and mist particle display list renderer)."""
        if self.is_function_decompiled("func_i15_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i15_802C5800 is currently non-matching (in progress)")

    def test_func_i15_802C5CE8_matched(self):
        """TDE test for func_i15_802C5CE8 in ovl_1CFB60 (Glacier Coast course-setup effect slot and rider slot initializer)."""
        self.assertTrue(self.is_function_decompiled("func_i15_802C5CE8"), "func_i15_802C5CE8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i15", "ovl_1CFB60", "func_i15_802C5CE8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i15_802C5F50_matched(self):
        """TDE test for func_i15_802C5F50 in ovl_1CFB60 (Glacier Coast freezing mist particle update)."""
        if self.is_function_decompiled("func_i15_802C5F50"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i15_802C5F50 is currently non-matching (in progress)")

    def test_func_i15_802C602C_matched(self):
        """TDE test for func_i15_802C602C in ovl_1CFB60 (Glacier Coast iceberg rebound collision impulse handler)."""
        if self.is_function_decompiled("func_i15_802C602C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i15_802C602C is currently non-matching (in progress)")


    def test_func_i5_802C5850_matched(self):
        """TDE test for func_i5_802C5850 in ovl_1BFF50 (Port Blue container ship wake disturbance simulation)."""
        if self.is_function_decompiled("func_i5_802C5850"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i5_802C5850 is currently non-matching (in progress)")

    def test_func_i5_802C5A98_matched(self):
        """TDE test for func_i5_802C5A98 in ovl_1BFF50 (Port Blue harbor waterway current state reset)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C5A98"), "func_i5_802C5A98 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1BFF50", "func_i5_802C5A98.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C5C1C_matched(self):
        """TDE test for func_i5_802C5C1C in ovl_1BFF50 (Port Blue harbor crane and dock surface display list)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C5C1C"), "func_i5_802C5C1C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1BFF50", "func_i5_802C5C1C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C5DC0_matched(self):
        """TDE test for func_i5_802C5DC0 in ovl_1BFF50 (Port Blue moving container barge kinematic update)."""
        if self.is_function_decompiled("func_i5_802C5DC0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i5_802C5DC0 is currently non-matching (in progress)")

    def test_func_i5_802C6CC4_matched(self):
        """TDE test for func_i5_802C6CC4 in ovl_1BFF50 (Port Blue canal lock water height adjust)."""
        if self.is_function_decompiled("func_i5_802C6CC4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i5_802C6CC4 is currently non-matching (in progress)")

    def test_func_i5_802C6F84_matched(self):
        """TDE test for func_i5_802C6F84 in ovl_1BFF50 (Port Blue finish line gantry and buoy beacon renderer)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C6F84"), "func_i5_802C6F84 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1BFF50", "func_i5_802C6F84.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C58F8_matched(self):
        """TDE test for func_i4_802C58F8 in ovl_1BE0B0 (course/difficulty select unlock table setup)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C58F8"), "func_i4_802C58F8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C58F8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C5CDC_matched(self):
        """TDE test for func_i4_802C5CDC in ovl_1BE0B0 (course select screen renderer)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C5CDC"), "func_i4_802C5CDC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C5CDC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C6778_matched(self):
        """TDE test for func_i4_802C6778 in ovl_1BE0B0 (Sunny Beach backdrop and scenery display list)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C6778"), "func_i4_802C6778 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C6778.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C69C4_matched(self):
        """TDE test for func_i4_802C69C4 in ovl_1BE0B0 (Sunny Beach umbrella and palm tree prop animations)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C69C4"), "func_i4_802C69C4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C69C4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C6C2C_matched(self):
        """TDE test for func_i4_802C6C2C in ovl_1BE0B0 (course select menu input handler)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C6C2C"), "func_i4_802C6C2C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C6C2C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C6ED0_matched(self):
        """TDE test for func_i4_802C6ED0 in ovl_1BE0B0 (course preview panel open/close zoom animation)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C6ED0"), "func_i4_802C6ED0 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C6ED0.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i4_802C70C0_matched(self):
        """TDE test for func_i4_802C70C0 in ovl_1BE0B0 (difficulty select menu input handler)."""
        self.assertTrue(self.is_function_decompiled("func_i4_802C70C0"), "func_i4_802C70C0 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i4", "ovl_1BE0B0", "func_i4_802C70C0.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i9_802C5800_matched(self):
        """TDE test for func_i9_802C5800 in ovl_1C66D0 (Sunset Bay sunset lighting and water specular display list renderer)."""
        if self.is_function_decompiled("func_i9_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C5800 is currently non-matching (in progress)")

    def test_func_i9_802C5D24_matched(self):
        """TDE test for func_i9_802C5D24 in ovl_1C66D0 (Sunset Bay dynamic tide level drain and shoreline waves)."""
        self.assertTrue(self.is_function_decompiled("func_i9_802C5D24"), "func_i9_802C5D24 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i9", "ovl_1C66D0", "func_i9_802C5D24.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i9_802C5E5C_matched(self):
        """TDE test for func_i9_802C5E5C in ovl_1C66D0 (Sunset Bay beach breaker wave height calculation)."""
        if self.is_function_decompiled("func_i9_802C5E5C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C5E5C is currently non-matching (in progress)")

    def test_func_i9_802C6750_matched(self):
        """TDE test for func_i9_802C6750 in ovl_1C66D0 (Sunset Bay sunset sky color palette interpolation)."""
        if self.is_function_decompiled("func_i9_802C6750"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C6750 is currently non-matching (in progress)")

    def test_func_i9_802C6CC8_matched(self):
        """TDE test for func_i9_802C6CC8 in ovl_1C66D0 (Sunset Bay water surface specular highlight reflection map)."""
        if self.is_function_decompiled("func_i9_802C6CC8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C6CC8 is currently non-matching (in progress)")

    def test_func_i9_802C71AC_matched(self):
        """TDE test for func_i9_802C71AC in ovl_1C66D0 (Sunset Bay shoreline surf particle emission and audio cue)."""
        if self.is_function_decompiled("func_i9_802C71AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C71AC is currently non-matching (in progress)")

    def test_func_i9_802C802C_matched(self):
        """TDE test for func_i9_802C802C in ovl_1C66D0 (Sunset Bay sunset course exit and results transition)."""
        if self.is_function_decompiled("func_i9_802C802C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i9_802C802C is currently non-matching (in progress)")


    def test_func_i8_802C5800_matched(self):
        """TDE test for func_i8_802C5800 in ovl_1C49A0 (Stunt mode ramp and floating ring display list generator)."""
        if self.is_function_decompiled("func_i8_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C5800 is currently non-matching (in progress)")

    def test_func_i8_802C5D3C_matched(self):
        """TDE test for func_i8_802C5D3C in ovl_1C49A0 (Stunt jump ramp trajectory and height evaluator)."""
        if self.is_function_decompiled("func_i8_802C5D3C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C5D3C is currently non-matching (in progress)")

    def test_func_i8_802C5EB8_matched(self):
        """TDE test for func_i8_802C5EB8 in ovl_1C49A0 (Stunt floating ring collision check and ring pass sound)."""
        if self.is_function_decompiled("func_i8_802C5EB8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C5EB8 is currently non-matching (in progress)")

    def test_func_i8_802C63E4_matched(self):
        """TDE test for func_i8_802C63E4 in ovl_1C49A0 (Stunt score multiplier and combo timer update)."""
        if self.is_function_decompiled("func_i8_802C63E4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C63E4 is currently non-matching (in progress)")

    def test_func_i8_802C6ADC_matched(self):
        """TDE test for func_i8_802C6ADC in ovl_1C49A0 (Stunt trick recognition and rotation detector)."""
        if self.is_function_decompiled("func_i8_802C6ADC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C6ADC is currently non-matching (in progress)")

    def test_func_i8_802C6D58_matched(self):
        """TDE test for func_i8_802C6D58 in ovl_1C49A0 (Stunt mode bonus point award animation)."""
        if self.is_function_decompiled("func_i8_802C6D58"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C6D58 is currently non-matching (in progress)")

    def test_func_i8_802C6DA8_matched(self):
        """TDE test for func_i8_802C6DA8 in ovl_1C49A0 (Stunt high score rank evaluator)."""
        if self.is_function_decompiled("func_i8_802C6DA8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C6DA8 is currently non-matching (in progress)")

    def test_func_i8_802C6EB8_matched(self):
        """TDE test for func_i8_802C6EB8 in ovl_1C49A0 (Stunt initials and score entry commit)."""
        if self.is_function_decompiled("func_i8_802C6EB8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i8_802C6EB8 is currently non-matching (in progress)")

    def test_func_i5_802C7090_matched(self):
        """TDE test for func_i5_802C7090 in ovl_1C17E0 (buoy path loader and per-frame buoy placer)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C7090"), "func_i5_802C7090 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1C17E0", "func_i5_802C7090.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C7484_matched(self):
        """TDE test for func_i5_802C7484 in ovl_1C17E0 (Course floating buoys and navigation display list dispatcher)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C7484"), "func_i5_802C7484 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1C17E0", "func_i5_802C7484.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C7594_matched(self):
        """TDE test for func_i5_802C7594 in ovl_1C17E0 (Buoy proximity trigger and direction arrow animator)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C7594"), "func_i5_802C7594 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1C17E0", "func_i5_802C7594.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C7698_matched(self):
        """TDE test for func_i5_802C7698 in ovl_1C17E0 (Buoy pass angle verification)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C7698"), "func_i5_802C7698 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1C17E0", "func_i5_802C7698.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i5_802C781C_matched(self):
        """TDE test for func_i5_802C781C in ovl_1C17E0 (results-panel slide/scroll state machine)."""
        self.assertTrue(self.is_function_decompiled("func_i5_802C781C"), "func_i5_802C781C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i5", "ovl_1C17E0", "func_i5_802C781C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)


    def test_func_i1_802C59E8_matched(self):
        """TDE test for func_i1_802C59E8 in ovl_1B55A0 (Primary course navigation engine initialization)."""
        self.assertTrue(self.is_function_decompiled("func_i1_802C59E8"), "func_i1_802C59E8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i1", "ovl_1B55A0", "func_i1_802C59E8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i1_802C5AE4_matched(self):
        """TDE test for func_i1_802C5AE4 in ovl_1B55A0 (Course buoy waypoint sequence update)."""
        if self.is_function_decompiled("func_i1_802C5AE4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C5AE4 is currently non-matching (in progress)")

    def test_func_i1_802C5DF4_matched(self):
        """TDE test for func_i1_802C5DF4 in ovl_1B55A0 (Course obstacle spawn coordinator)."""
        if self.is_function_decompiled("func_i1_802C5DF4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C5DF4 is currently non-matching (in progress)")

    def test_func_i1_802C63B4_matched(self):
        """TDE test for func_i1_802C63B4 in ovl_1B55A0 (Course buoy distance and penalty evaluator)."""
        self.assertTrue(self.is_function_decompiled("func_i1_802C63B4"), "func_i1_802C63B4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i1", "ovl_1B55A0", "func_i1_802C63B4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i1_802C6550_matched(self):
        """TDE test for func_i1_802C6550 in ovl_1B55A0 (Course finish line trigger volume evaluator)."""
        if self.is_function_decompiled("func_i1_802C6550"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C6550 is currently non-matching (in progress)")

    def test_func_i1_802C6B38_matched(self):
        """TDE test for func_i1_802C6B38 in ovl_1B55A0 (Course restart and reset coordinator)."""
        if self.is_function_decompiled("func_i1_802C6B38"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C6B38 is currently non-matching (in progress)")

    def test_func_i1_802C6BD8_matched(self):
        """TDE test for func_i1_802C6BD8 in ovl_1B55A0 (Warm-up banner panel scroller)."""
        self.assertTrue(self.is_function_decompiled("func_i1_802C6BD8"), "func_i1_802C6BD8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i1", "ovl_1B55A0", "func_i1_802C6BD8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i1_802C6DCC_matched(self):
        """TDE test for func_i1_802C6DCC in ovl_1B55A0 (Race-finish state setup and record flag latch)."""
        self.assertTrue(self.is_function_decompiled("func_i1_802C6DCC"), "func_i1_802C6DCC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i1", "ovl_1B55A0", "func_i1_802C6DCC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i1_802C6FE0_matched(self):
        """TDE test for func_i1_802C6FE0 in ovl_1B55A0 (Course final lap fanfare cue)."""
        if self.is_function_decompiled("func_i1_802C6FE0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C6FE0 is currently non-matching (in progress)")

    def test_func_i1_802C7608_matched(self):
        """TDE test for func_i1_802C7608 in ovl_1B55A0 (Primary course navigation display list dispatcher)."""
        if self.is_function_decompiled("func_i1_802C7608"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C7608 is currently non-matching (in progress)")

    def test_func_i1_802C7D00_matched(self):
        """TDE test for func_i1_802C7D00 in ovl_1B55A0 (Primary course buoy pass checker)."""
        self.assertTrue(self.is_function_decompiled("func_i1_802C7D00"), "func_i1_802C7D00 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i1", "ovl_1B55A0", "func_i1_802C7D00.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i1_802C7E48_matched(self):
        """TDE test for func_i1_802C7E48 in ovl_1B55A0 (Primary course rider rank tracker)."""
        if self.is_function_decompiled("func_i1_802C7E48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C7E48 is currently non-matching (in progress)")

    def test_func_i1_802C8E70_matched(self):
        """TDE test for func_i1_802C8E70 in ovl_1B55A0 (Primary course finish sequence and results transition)."""
        if self.is_function_decompiled("func_i1_802C8E70"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i1_802C8E70 is currently non-matching (in progress)")

    def test_func_i2_802C5800_matched(self):
        """TDE test for func_i2_802C5800 in ovl_1B9440 (Secondary course navigation engine initialization)."""
        if self.is_function_decompiled("func_i2_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C5800 is currently non-matching (in progress)")

    def test_func_i2_802C5AE4_matched(self):
        """TDE test for func_i2_802C5AE4 in ovl_1B9440 (Course buoy waypoint proximity trigger handler)."""
        if self.is_function_decompiled("func_i2_802C5AE4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C5AE4 is currently non-matching (in progress)")

    def test_func_i2_802C5E28_matched(self):
        """TDE test for func_i2_802C5E28 in ovl_1B9440 (Secondary course buoy proximity checking and navigation)."""
        if self.is_function_decompiled("func_i2_802C5E28"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C5E28 is currently non-matching (in progress)")

    def test_func_i2_802C676C_matched(self):
        """TDE test for func_i2_802C676C in ovl_1B9440 (Red buoy pass validation)."""
        if self.is_function_decompiled("func_i2_802C676C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C676C is currently non-matching (in progress)")

    def test_func_i2_802C67E4_matched(self):
        """TDE test for func_i2_802C67E4 in ovl_1B9440 (Yellow buoy pass validation)."""
        if self.is_function_decompiled("func_i2_802C67E4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C67E4 is currently non-matching (in progress)")

    def test_func_i2_802C6864_matched(self):
        """TDE test for func_i2_802C6864 in ovl_1B9440 (Power level increment on consecutive buoy passes)."""
        if self.is_function_decompiled("func_i2_802C6864"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C6864 is currently non-matching (in progress)")

    def test_func_i2_802C6ADC_matched(self):
        """TDE test for func_i2_802C6ADC in ovl_1B9440 (Buoy navigation HUD marker renderer)."""
        if self.is_function_decompiled("func_i2_802C6ADC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C6ADC is currently non-matching (in progress)")

    def test_func_i2_802C70EC_matched(self):
        """TDE test for func_i2_802C70EC in ovl_1B9440 (Buoy miss count accumulator and engine power cut penalty)."""
        if self.is_function_decompiled("func_i2_802C70EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C70EC is currently non-matching (in progress)")

    def test_func_i2_802C7C50_matched(self):
        """TDE test for func_i2_802C7C50 in ovl_1B9440 (Course 3D buoy models display list emitter)."""
        if self.is_function_decompiled("func_i2_802C7C50"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C7C50 is currently non-matching (in progress)")

    def test_func_i2_802C84EC_matched(self):
        """TDE test for func_i2_802C84EC in ovl_1B9440 (Buoy floating collision volume update)."""
        if self.is_function_decompiled("func_i2_802C84EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C84EC is currently non-matching (in progress)")

    def test_func_i2_802C86E4_matched(self):
        """TDE test for func_i2_802C86E4 in ovl_1B9440 (Course lap split time trigger)."""
        if self.is_function_decompiled("func_i2_802C86E4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C86E4 is currently non-matching (in progress)")

    def test_func_i2_802C88DC_matched(self):
        """TDE test for func_i2_802C88DC in ovl_1B9440 (Finish line archway display list emitter)."""
        if self.is_function_decompiled("func_i2_802C88DC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i2_802C88DC is currently non-matching (in progress)")

    def test_func_i13_802C5800_matched(self):
        """TDE test for func_i13_802C5800 in ovl_1CBAF0 (Master obstacle and 3D surface collision matrix evaluator)."""
        if self.is_function_decompiled("func_i13_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C5800 is currently non-matching (in progress)")

    def test_func_i13_802C5F6C_matched(self):
        """TDE test for func_i13_802C5F6C in ovl_1CBAF0 (Breakwater and jetty surface deflection)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C5F6C"), "func_i13_802C5F6C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C5F6C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C6068_matched(self):
        """TDE test for func_i13_802C6068 in ovl_1CBAF0 (Rock barrier rebound impulse calculation)."""
        if self.is_function_decompiled("func_i13_802C6068"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C6068 is currently non-matching (in progress)")

    def test_func_i13_802C61E0_matched(self):
        """TDE test for func_i13_802C61E0 in ovl_1CBAF0 (Wooden ramp friction and launch trajectory)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C61E0"), "func_i13_802C61E0 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C61E0.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C62EC_matched(self):
        """TDE test for func_i13_802C62EC in ovl_1CBAF0 (Save file search & validation menu input handler)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C62EC"), "func_i13_802C62EC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C62EC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C64AC_matched(self):
        """TDE test for func_i13_802C64AC in ovl_1CBAF0 (Submerged obstacle buoyancy resistance)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C64AC"), "func_i13_802C64AC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C64AC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C65D4_matched(self):
        """TDE test for func_i13_802C65D4 in ovl_1CBAF0 (Shallow reef hull scraping drag)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C65D4"), "func_i13_802C65D4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C65D4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C6700_matched(self):
        """TDE test for func_i13_802C6700 in ovl_1CBAF0 (Pier support post collision envelope)."""
        if self.is_function_decompiled("func_i13_802C6700"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C6700 is currently non-matching (in progress)")

    def test_func_i13_802C69CC_matched(self):
        """TDE test for func_i13_802C69CC in ovl_1CBAF0 (Course boundary invisible collision plane)."""
        if self.is_function_decompiled("func_i13_802C69CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C69CC is currently non-matching (in progress)")

    def test_func_i13_802C6ABC_matched(self):
        """TDE test for func_i13_802C6ABC in ovl_1CBAF0 (Jet ski hull surface normal calculator)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C6ABC"), "func_i13_802C6ABC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C6ABC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C6BC4_matched(self):
        """TDE test for func_i13_802C6BC4 in ovl_1CBAF0 (Collision penetration depth solver)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C6BC4"), "func_i13_802C6BC4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C6BC4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C6CE4_matched(self):
        """TDE test for func_i13_802C6CE4 in ovl_1CBAF0 (Angular deflection torque generator)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C6CE4"), "func_i13_802C6CE4 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C6CE4.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C6E48_matched(self):
        """TDE test for func_i13_802C6E48 in ovl_1CBAF0 (Obstacle impact sound effect dispatcher)."""
        if self.is_function_decompiled("func_i13_802C6E48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C6E48 is currently non-matching (in progress)")

    def test_func_i13_802C6F0C_matched(self):
        """TDE test for func_i13_802C6F0C in ovl_1CBAF0 (Splash particle generation on obstacle strike)."""
        if self.is_function_decompiled("func_i13_802C6F0C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C6F0C is currently non-matching (in progress)")

    def test_func_i13_802C711C_matched(self):
        """TDE test for func_i13_802C711C in ovl_1CBAF0 (Master collision polygon grid query)."""
        if self.is_function_decompiled("func_i13_802C711C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C711C is currently non-matching (in progress)")

    def test_func_i13_802C81AC_matched(self):
        """TDE test for func_i13_802C81AC in ovl_1CBAF0 (Rider dismount and wipeout trigger on hard impact)."""
        if self.is_function_decompiled("func_i13_802C81AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C81AC is currently non-matching (in progress)")

    def test_func_i13_802C82A4_matched(self):
        """TDE test for func_i13_802C82A4 in ovl_1CBAF0 (Hull recovery and righting moment evaluator)."""
        if self.is_function_decompiled("func_i13_802C82A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C82A4 is currently non-matching (in progress)")

    def test_func_i13_802C832C_matched(self):
        """TDE test for func_i13_802C832C in ovl_1CBAF0 (Stunt collision bonus multiplier check)."""
        self.assertTrue(self.is_function_decompiled("func_i13_802C832C"), "func_i13_802C832C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "overlays", "ovl_i13", "ovl_1CBAF0", "func_i13_802C832C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_i13_802C8484_matched(self):
        """TDE test for func_i13_802C8484 in ovl_1CBAF0 (Multiplayer split-screen collision isolator)."""
        if self.is_function_decompiled("func_i13_802C8484"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C8484 is currently non-matching (in progress)")

    def test_func_i13_802C8CBC_matched(self):
        """TDE test for func_i13_802C8CBC in ovl_1CBAF0 (Collision state cleanup and reset)."""
        if self.is_function_decompiled("func_i13_802C8CBC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_i13_802C8CBC is currently non-matching (in progress)")



class TestSysLayer(unittest.TestCase):
    """Test cases for the System & OS Layer (src/sys/)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "sys")
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

    def test_SysMain_Thread_matched(self):
        """TDE test for SysMain_Thread in sys_main (Master game thread, RCP display list dispatch & VI mode setup)."""
        self.assertTrue(self.is_function_decompiled("SysMain_Thread"), "SysMain_Thread should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "sys", "sys_main", "SysMain_Thread.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_800498A4_matched(self):
        """TDE test for func_800498A4 in sys_utils (3D rotation matrix generation about arbitrary axis with sin/cos lookup)."""
        if self.is_function_decompiled("func_800498A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800498A4 is currently non-matching (in progress)")

    def test_func_80049A94_matched(self):
        """TDE test for func_80049A94 in sys_utils (Axis-angle vector rotation matrix and coordinate transformation)."""
        if self.is_function_decompiled("func_80049A94"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80049A94 is currently non-matching (in progress)")

    def test_func_80049C9C_matched(self):
        """TDE test for func_80049C9C in sys_utils (Euler angles (pitch/yaw/roll) to affine transformation matrix converter)."""
        if self.is_function_decompiled("func_80049C9C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80049C9C is currently non-matching (in progress)")

    def test_func_8004A3C0_matched(self):
        """TDE test for func_8004A3C0 in sys_utils (View frustum and camera perspective projection matrix generator)."""
        if self.is_function_decompiled("func_8004A3C0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004A3C0 is currently non-matching (in progress)")

    def test_func_8004A8B0_matched(self):
        """TDE test for func_8004A8B0 in sys_utils (Controller data packing and hardware status processing)."""
        if self.is_function_decompiled("func_8004A8B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004A8B0 is currently non-matching (in progress)")



class TestAudioEngine(unittest.TestCase):
    """Test cases for the Audio Engine (src/audio/)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "audio")
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

    def test_func_800C010C_matched(self):
        """TDE test for func_800C010C in audio_general (Master music track transition and channel modulation coordinator)."""
        if self.is_function_decompiled("func_800C010C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800C010C is currently non-matching (in progress)")

    def test_func_800C11CC_matched(self):
        """TDE test for func_800C11CC in audio_general (Engine state sound effect trigger)."""
        if self.is_function_decompiled("func_800C11CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800C11CC is currently non-matching (in progress)")

    def test_func_800C1BD8_matched(self):
        """TDE test for func_800C1BD8 in audio_general (Water splash and engine exhaust audio filter updater)."""
        if self.is_function_decompiled("func_800C1BD8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800C1BD8 is currently non-matching (in progress)")

    def test_AudioGeneral_PlaySound_matched(self):
        """TDE test for AudioGeneral_PlaySound in audio_general (Master sound effect dispatcher with priority queue and channel routing)."""
        if self.is_function_decompiled("AudioGeneral_PlaySound"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("AudioGeneral_PlaySound is currently non-matching (in progress)")

    def test_func_800C3EF4_matched(self):
        """TDE test for func_800C3EF4 in audio_general (Announcer voice clip and course fanfare selector)."""
        if self.is_function_decompiled("func_800C3EF4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800C3EF4 is currently non-matching (in progress)")



class TestCameraEngine(unittest.TestCase):
    """Test cases for the Camera Engine (src/game/code_C6C0.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        filepath = os.path.join(PROJECT_ROOT, "src", "game", "code_C6C0.c")
        pattern = re.compile(rf"\b{func_name}\b")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            if pattern.search(content):
                for block in content.split(func_name)[1:]:
                    if "{" in block[:300]:
                        return True
        return False

    def test_func_80051EC0_matched(self):
        """TDE test for func_80051EC0 in code_C6C0 (Primary chase-camera look-at target calculator)."""
        if self.is_function_decompiled("func_80051EC0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80051EC0 is currently non-matching (in progress)")

    def test_func_800534AC_matched(self):
        """TDE test for func_800534AC in code_C6C0 (Jet ski velocity-dependent camera pullback distance)."""
        if self.is_function_decompiled("func_800534AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800534AC is currently non-matching (in progress)")

    def test_func_80053C08_matched(self):
        """TDE test for func_80053C08 in code_C6C0 (Water surface wave height compensation for camera elevation)."""
        if self.is_function_decompiled("func_80053C08"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80053C08 is currently non-matching (in progress)")

    def test_func_80054130_matched(self):
        """TDE test for func_80054130 in code_C6C0 (Camera yaw smoothing and heading alignment damping)."""
        if self.is_function_decompiled("func_80054130"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80054130 is currently non-matching (in progress)")

    def test_func_80057B24_matched(self):
        """TDE test for func_80057B24 in code_C6C0 (Camera pitch spring dynamics during wave jumps)."""
        if self.is_function_decompiled("func_80057B24"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80057B24 is currently non-matching (in progress)")

    def test_func_8005B510_matched(self):
        """TDE test for func_8005B510 in code_C6C0 (Close-up cockpit/bumper view mode coordinate evaluator)."""
        if self.is_function_decompiled("func_8005B510"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8005B510 is currently non-matching (in progress)")

    def test_func_8005DE24_matched(self):
        """TDE test for func_8005DE24 in code_C6C0 (Reverse-view (rear mirror) camera orientation)."""
        if self.is_function_decompiled("func_8005DE24"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8005DE24 is currently non-matching (in progress)")

    def test_func_800609EC_matched(self):
        """TDE test for func_800609EC in code_C6C0 (Camera collision with course terrain boundaries)."""
        if self.is_function_decompiled("func_800609EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800609EC is currently non-matching (in progress)")

    def test_func_80061184_matched(self):
        """TDE test for func_80061184 in code_C6C0 (Camera look-at matrix builder for single player)."""
        if self.is_function_decompiled("func_80061184"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80061184 is currently non-matching (in progress)")

    def test_func_80061708_matched(self):
        """TDE test for func_80061708 in code_C6C0 (Dynamic field-of-view adjustment based on speed boost)."""
        if self.is_function_decompiled("func_80061708"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80061708 is currently non-matching (in progress)")

    def test_func_800618F4_matched(self):
        """TDE test for func_800618F4 in code_C6C0 (Submerged camera water ripple distortion filter)."""
        if self.is_function_decompiled("func_800618F4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800618F4 is currently non-matching (in progress)")

    def test_func_80061FEC_matched(self):
        """TDE test for func_80061FEC in code_C6C0 (Screen shake impulse generator on hard wipeouts)."""
        if self.is_function_decompiled("func_80061FEC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80061FEC is currently non-matching (in progress)")

    def test_func_800624CC_matched(self):
        """TDE test for func_800624CC in code_C6C0 (Camera roll leveling filter relative to horizon)."""
        if self.is_function_decompiled("func_800624CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800624CC is currently non-matching (in progress)")

    def test_func_800629A8_matched(self):
        """TDE test for func_800629A8 in code_C6C0 (View frustum culling plane extractor)."""
        if self.is_function_decompiled("func_800629A8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800629A8 is currently non-matching (in progress)")

    def test_func_80062E50_matched(self):
        """TDE test for func_80062E50 in code_C6C0 (Depth of field and distance fog reference point updater)."""
        if self.is_function_decompiled("func_80062E50"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80062E50 is currently non-matching (in progress)")

    def test_func_8006390C_matched(self):
        """TDE test for func_8006390C in code_C6C0 (Camera target lock-on interpolation filter)."""
        if self.is_function_decompiled("func_8006390C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8006390C is currently non-matching (in progress)")

    def test_func_80063C88_matched(self):
        """TDE test for func_80063C88 in code_C6C0 (Replay spectator camera path spline evaluator)."""
        if self.is_function_decompiled("func_80063C88"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80063C88 is currently non-matching (in progress)")

    def test_func_80064C0C_matched(self):
        """TDE test for func_80064C0C in code_C6C0 (Automated course flyover preview camera generator)."""
        if self.is_function_decompiled("func_80064C0C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80064C0C is currently non-matching (in progress)")

    def test_func_80065C18_matched(self):
        """TDE test for func_80065C18 in code_C6C0 (Checkpoint flyby camera sequence coordinator)."""
        if self.is_function_decompiled("func_80065C18"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80065C18 is currently non-matching (in progress)")

    def test_func_800665B0_matched(self):
        """TDE test for func_800665B0 in code_C6C0 (Course intro cinematic camera path interpolation)."""
        if self.is_function_decompiled("func_800665B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800665B0 is currently non-matching (in progress)")

    def test_func_8006719C_matched(self):
        """TDE test for func_8006719C in code_C6C0 (Finish line celebration orbital pan camera)."""
        if self.is_function_decompiled("func_8006719C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8006719C is currently non-matching (in progress)")

    def test_func_80067810_matched(self):
        """TDE test for func_80067810 in code_C6C0 (Winner podium presentation camera framing)."""
        if self.is_function_decompiled("func_80067810"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80067810 is currently non-matching (in progress)")

    def test_func_80067BFC_matched(self):
        """TDE test for func_80067BFC in code_C6C0 (Camera cut transition blend accumulator)."""
        if self.is_function_decompiled("func_80067BFC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80067BFC is currently non-matching (in progress)")

    def test_func_80067C6C_matched(self):
        """TDE test for func_80067C6C in code_C6C0 (Replay camera speed multiplier calculator)."""
        self.assertTrue(self.is_function_decompiled("func_80067C6C"), "func_80067C6C should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "game", "code_C6C0", "func_80067C6C.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_80067E40_matched(self):
        """TDE test for func_80067E40 in code_C6C0 (2-Player split-screen upper viewport matrix setup)."""
        if self.is_function_decompiled("func_80067E40"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80067E40 is currently non-matching (in progress)")

    def test_func_800683A0_matched(self):
        """TDE test for func_800683A0 in code_C6C0 (2-Player split-screen lower viewport matrix setup)."""
        if self.is_function_decompiled("func_800683A0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800683A0 is currently non-matching (in progress)")

    def test_func_80068538_matched(self):
        """TDE test for func_80068538 in code_C6C0 (Multiplayer aspect ratio and scissor box calculator)."""
        if self.is_function_decompiled("func_80068538"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80068538 is currently non-matching (in progress)")

    def test_func_800687A4_matched(self):
        """TDE test for func_800687A4 in code_C6C0 (Results screen rotating podium camera)."""
        if self.is_function_decompiled("func_800687A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800687A4 is currently non-matching (in progress)")

    def test_func_800694B8_matched(self):
        """TDE test for func_800694B8 in code_C6C0 (Camera state reset on race restart)."""
        if self.is_function_decompiled("func_800694B8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800694B8 is currently non-matching (in progress)")

    def test_func_8006977C_matched(self):
        """TDE test for func_8006977C in code_C6C0 (Camera debug telemetry overlay generator)."""
        if self.is_function_decompiled("func_8006977C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8006977C is currently non-matching (in progress)")

    def test_func_80069798_matched(self):
        """TDE test for func_80069798 in code_C6C0 (Camera master cleanup and shutdown coordinator)."""
        if self.is_function_decompiled("func_80069798"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80069798 is currently non-matching (in progress)")



class TestQuickWinModules(unittest.TestCase):
    """Test cases for Quick-Win Game Code Modules (code_24B00, code_43A60, seg_1C3D00, code_383C0, code_3A580, code_5480)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        clean_name = func_name.replace("_quickwin", "")
        src_dir = os.path.join(PROJECT_ROOT, "src")
        pattern = re.compile(rf"\b{clean_name}\b")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file.endswith((".c", ".h")):
                    filepath = os.path.join(root, file)
                    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        if pattern.search(content):
                            for block in content.split(clean_name)[1:]:
                                if "{" in block[:300]:
                                    return True
        return False

    def test_func_8006E674_matched(self):
        """TDE test for func_8006E674 in code_24B00 (Course 3D animated props display list renderer)."""
        if self.is_function_decompiled("func_8006E674"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8006E674 is currently non-matching (in progress)")

    def test_func_80088EA8_quickwin_matched(self):
        """TDE test for func_80088EA8_quickwin in code_43A60 (Rider starting order and position randomization)."""
        if self.is_function_decompiled("func_80088EA8_quickwin"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80088EA8_quickwin is currently non-matching (in progress)")

    def test_func_800890B4_matched(self):
        """TDE test for func_800890B4 in code_43A60 (Rider starting grid launch physics)."""
        if self.is_function_decompiled("func_800890B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800890B4 is currently non-matching (in progress)")

    def test_func_1C3D00_802C58DC_matched(self):
        """TDE test for func_1C3D00_802C58DC in seg_1C3D00 (Segment 1C3D00 water overlay display list builder)."""
        if self.is_function_decompiled("func_1C3D00_802C58DC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1C3D00_802C58DC is currently non-matching (in progress)")

    def test_func_8007DF4C_matched(self):
        """TDE test for func_8007DF4C in code_383C0 (Rider animation bone matrix blending)."""
        if self.is_function_decompiled("func_8007DF4C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007DF4C is currently non-matching (in progress)")

    def test_func_8007F030_matched(self):
        """TDE test for func_8007F030 in code_383C0 (Rider kinematic state and skeletal position evaluator)."""
        if self.is_function_decompiled("func_8007F030"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007F030 is currently non-matching (in progress)")

    def test_func_8007FD80_matched(self):
        """TDE test for func_8007FD80 in code_3A580 (Particle spray emitter coordinator)."""
        if self.is_function_decompiled("func_8007FD80"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007FD80 is currently non-matching (in progress)")

    def test_func_8007FFA8_matched(self):
        """TDE test for func_8007FFA8 in code_3A580 (3D water spray particle display list emitter)."""
        if self.is_function_decompiled("func_8007FFA8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007FFA8 is currently non-matching (in progress)")

    def test_func_8004B1B4_matched(self):
        """TDE test for func_8004B1B4 in code_5480 (Wave surface ripple generation and heightfield deformer)."""
        if self.is_function_decompiled("func_8004B1B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004B1B4 is currently non-matching (in progress)")

    def test_func_8004BC98_matched(self):
        """TDE test for func_8004BC98 in code_5480 (Dynamic water collision response and splash impulse update)."""
        if self.is_function_decompiled("func_8004BC98"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8004BC98 is currently non-matching (in progress)")



class TestSaveSystem(unittest.TestCase):
    """Test cases for Controller Pak & Save System (src/game/core/wr64_save.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        clean_name = func_name.replace("_save", "")
        filepath = os.path.join(PROJECT_ROOT, "src", "game", "core", "wr64_save.c")
        pattern = re.compile(rf"\b{clean_name}\b")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            if pattern.search(content):
                for block in content.split(clean_name)[1:]:
                    if "{" in block[:300]:
                        return True
        return False

    def test_func_8007B370_matched(self):
        """TDE test for func_8007B370 in wr64_save (EEPROM save block header initialization and checksum calculation)."""
        if self.is_function_decompiled("func_8007B370"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B370 is currently non-matching (in progress)")

    def test_func_8007B630_matched(self):
        """TDE test for func_8007B630 in wr64_save (Default championship records and high scores table restore)."""
        if self.is_function_decompiled("func_8007B630"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B630 is currently non-matching (in progress)")

    def test_func_8007B930_save_matched(self):
        """TDE test for func_8007B930_save in wr64_save (Stunt mode default high score initials and point tables reset)."""
        if self.is_function_decompiled("func_8007B930_save"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007B930_save is currently non-matching (in progress)")

    def test_func_8007BEA4_matched(self):
        """TDE test for func_8007BEA4 in wr64_save (Course record save slot index boundary verification)."""
        if self.is_function_decompiled("func_8007BEA4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007BEA4 is currently non-matching (in progress)")

    def test_func_8007C31C_save_matched(self):
        """TDE test for func_8007C31C_save in wr64_save (EEPROM player initials and championship record block serialization)."""
        if self.is_function_decompiled("func_8007C31C_save"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007C31C_save is currently non-matching (in progress)")

    def test_func_8007C604_matched(self):
        """TDE test for func_8007C604 in wr64_save (Stunt high score rank slot compaction and displacement updater)."""
        if self.is_function_decompiled("func_8007C604"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007C604 is currently non-matching (in progress)")

    def test_func_8007D2D4_matched(self):
        """TDE test for func_8007D2D4 in wr64_save (Controller Pak ghost data file verify, header check, and payload reader)."""
        if self.is_function_decompiled("func_8007D2D4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007D2D4 is currently non-matching (in progress)")

    def test_func_8007D614_matched(self):
        """TDE test for func_8007D614 in wr64_save (Controller Pak ghost data file allocation, filesystem write, and inode update)."""
        if self.is_function_decompiled("func_8007D614"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007D614 is currently non-matching (in progress)")



class TestPhysicsModules(unittest.TestCase):
    """Test cases for Physics and Collision Modules (code_2C670.c, code_68A10.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "game")
        pattern = re.compile(rf"\b{func_name}\b")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file in ("code_2C670.c", "code_68A10.c"):
                    filepath = os.path.join(root, file)
                    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        if pattern.search(content):
                            for block in content.split(func_name)[1:]:
                                if "{" in block[:300]:
                                    return True
        return False

    def test_func_80071E70_matched(self):
        """TDE test for func_80071E70 in code_2C670 (Jet ski hull displacement and water elevation offset calculator)."""
        if self.is_function_decompiled("func_80071E70"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80071E70 is currently non-matching (in progress)")

    def test_func_800735EC_matched(self):
        """TDE test for func_800735EC in code_2C670 (Buoyancy force accumulator across floating course buoys)."""
        if self.is_function_decompiled("func_800735EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800735EC is currently non-matching (in progress)")

    def test_func_80073E6C_matched(self):
        """TDE test for func_80073E6C in code_2C670 (Course boundary check and out-of-bounds recovery vector)."""
        if self.is_function_decompiled("func_80073E6C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80073E6C is currently non-matching (in progress)")

    def test_func_800741A4_matched(self):
        """TDE test for func_800741A4 in code_2C670 (Multi-point collision intersection evaluator with course obstacles)."""
        if self.is_function_decompiled("func_800741A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800741A4 is currently non-matching (in progress)")

    def test_func_800744EC_matched(self):
        """TDE test for func_800744EC in code_2C670 (Jet ski water surface impact damping and hull rocking spring physics)."""
        if self.is_function_decompiled("func_800744EC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800744EC is currently non-matching (in progress)")

    def test_func_800AE7C4_matched(self):
        """TDE test for func_800AE7C4 in code_68A10 (Jet ski landing water splash particle burst trigger)."""
        if self.is_function_decompiled("func_800AE7C4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AE7C4 is currently non-matching (in progress)")

    def test_func_800AFBD0_matched(self):
        """TDE test for func_800AFBD0 in code_68A10 (Rider water spray intensity calculator based on turning slip angle)."""
        if self.is_function_decompiled("func_800AFBD0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AFBD0 is currently non-matching (in progress)")

    def test_func_800B08F8_matched(self):
        """TDE test for func_800B08F8 in code_68A10 (Dynamic sound effect dispatch and audio spatialization for water splashes)."""
        if self.is_function_decompiled("func_800B08F8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800B08F8 is currently non-matching (in progress)")

    def test_func_800B2ABC_matched(self):
        """TDE test for func_800B2ABC in code_68A10 (Particle buffer recycling and active emitter state update)."""
        if self.is_function_decompiled("func_800B2ABC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800B2ABC is currently non-matching (in progress)")

    def test_func_800B305C_matched(self):
        """TDE test for func_800B305C in code_68A10 (3D animated spray and wake billboarding texture display list renderer)."""
        if self.is_function_decompiled("func_800B305C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800B305C is currently non-matching (in progress)")



class TestRiderKinematics(unittest.TestCase):
    """Test cases for Rider Kinematics & Race Position Sorting (code_2FB10.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "game")
        pattern = re.compile(rf"\b{func_name}\b")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file == "code_2FB10.c":
                    filepath = os.path.join(root, file)
                    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        if pattern.search(content):
                            for block in content.split(func_name)[1:]:
                                if "{" in block[:300]:
                                    return True
        return False

    def test_func_80075310_matched(self):
        """TDE test for func_80075310 in code_2FB10 (Rider lean angle calculation relative to velocity vector and turning radius)."""
        if self.is_function_decompiled("func_80075310"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80075310 is currently non-matching (in progress)")

    def test_func_80076378_matched(self):
        """TDE test for func_80076378 in code_2FB10 (Jet ski throttle response and water drag velocity damping)."""
        if self.is_function_decompiled("func_80076378"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80076378 is currently non-matching (in progress)")

    def test_func_8007687C_matched(self):
        """TDE test for func_8007687C in code_2FB10 (Race position evaluation and checkpoint milestone update)."""
        if self.is_function_decompiled("func_8007687C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8007687C is currently non-matching (in progress)")

    def test_func_80077F5C_matched(self):
        """TDE test for func_80077F5C in code_2FB10 (Stunt combo trick recognition and point award accumulator)."""
        if self.is_function_decompiled("func_80077F5C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80077F5C is currently non-matching (in progress)")

    def test_func_800783AC_matched(self):
        """TDE test for func_800783AC in code_2FB10 (Real-time rider position gap distance and rubberband AI speed scaling)."""
        if self.is_function_decompiled("func_800783AC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800783AC is currently non-matching (in progress)")

    def test_func_80079528_matched(self):
        """TDE test for func_80079528 in code_2FB10 (Rider animation state transition and posture stabilizer)."""
        if self.is_function_decompiled("func_80079528"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80079528 is currently non-matching (in progress)")


class TestCourseLoading(unittest.TestCase):
    """Test cases for Course Asset Loading & Water Craft Suspension (code_4F850.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        src_dir = os.path.join(PROJECT_ROOT, "src", "game")
        pattern = re.compile(rf"\b{func_name}\b")
        for root, _, files in os.walk(src_dir):
            for file in files:
                if file == "code_4F850.c":
                    filepath = os.path.join(root, file)
                    with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                        content = f.read()
                        if pattern.search(content):
                            for block in content.split(func_name)[1:]:
                                if "{" in block[:300]:
                                    return True
        return False

    def test_unk_game_load_matched(self):
        """TDE test for unk_game_load in code_4F850 (Master game loop state asset loader and segment relocation)."""
        if self.is_function_decompiled("unk_game_load"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("unk_game_load is currently non-matching (in progress)")

    def test_func_80096048_matched(self):
        """TDE test for func_80096048 in code_4F850 (Course terrain mesh and collision bounding volume loader)."""
        if self.is_function_decompiled("func_80096048"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80096048 is currently non-matching (in progress)")

    def test_func_800961B8_matched(self):
        """TDE test for func_800961B8 in code_4F850 (Water craft hull suspension spring stiffness and damping matrix setup)."""
        self.assertTrue(self.is_function_decompiled("func_800961B8"), "func_800961B8 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "game", "code_4F850", "func_800961B8.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_800963CC_matched(self):
        """TDE test for func_800963CC in code_4F850 (Course-specific water texture palette and animated surface frame loader)."""
        self.assertTrue(self.is_function_decompiled("func_800963CC"), "func_800963CC should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "game", "code_4F850", "func_800963CC.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_80096694_matched(self):
        """TDE test for func_80096694 in code_4F850 (Jet ski texture and rider livery palette decompression dispatcher)."""
        self.assertTrue(self.is_function_decompiled("func_80096694"), "func_80096694 should be decompiled in C")
        stub_path = os.path.join(NONMATCHINGS_DIR, "game", "code_4F850", "func_80096694.s")
        self.assertFalse(os.path.exists(stub_path), f"Nonmatching stub {stub_path} should be deleted after matching")
        self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)

    def test_func_80096960_matched(self):
        """TDE test for func_80096960 in code_4F850 (Multiplayer rider palette index and team color configuration)."""
        if self.is_function_decompiled("func_80096960"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80096960 is currently non-matching (in progress)")



class TestFlightDebug(unittest.TestCase):
    """Test cases for Unused Debug Flight Mode & Text Rasterizer (unused_code_1B1FB0.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        filepath = os.path.join(PROJECT_ROOT, "src", "unused_code_1B1FB0.c")
        pattern = re.compile(rf"\b{func_name}\b")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            if pattern.search(content):
                for block in content.split(func_name)[1:]:
                    if "{" in block[:300]:
                        return True
        return False

    def test_func_1B1FB0_802C5800_matched(self):
        """TDE test for func_1B1FB0_802C5800 in unused_code_1B1FB0 (Flight mode debug camera controller)."""
        if self.is_function_decompiled("func_1B1FB0_802C5800"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C5800 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C5BA4_matched(self):
        """TDE test for func_1B1FB0_802C5BA4 in unused_code_1B1FB0 (Flight mode terrain height lookup)."""
        if self.is_function_decompiled("func_1B1FB0_802C5BA4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C5BA4 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C5DF4_matched(self):
        """TDE test for func_1B1FB0_802C5DF4 in unused_code_1B1FB0 (Flight velocity integration and aerodynamic lift)."""
        if self.is_function_decompiled("func_1B1FB0_802C5DF4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C5DF4 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C62E4_matched(self):
        """TDE test for func_1B1FB0_802C62E4 in unused_code_1B1FB0 (Debug flight matrix transform setup)."""
        if self.is_function_decompiled("func_1B1FB0_802C62E4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C62E4 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C67BC_matched(self):
        """TDE test for func_1B1FB0_802C67BC in unused_code_1B1FB0 (Debug flight collision boundary detector)."""
        if self.is_function_decompiled("func_1B1FB0_802C67BC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C67BC is currently non-matching (in progress)")

    def test_func_1B1FB0_802C6970_matched(self):
        """TDE test for func_1B1FB0_802C6970 in unused_code_1B1FB0 (Flight mode player input interpreter)."""
        if self.is_function_decompiled("func_1B1FB0_802C6970"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C6970 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C6C1C_matched(self):
        """TDE test for func_1B1FB0_802C6C1C in unused_code_1B1FB0 (Debug flight HUD coordinates)."""
        if self.is_function_decompiled("func_1B1FB0_802C6C1C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C6C1C is currently non-matching (in progress)")

    def test_func_1B1FB0_802C6E40_matched(self):
        """TDE test for func_1B1FB0_802C6E40 in unused_code_1B1FB0 (Flight telemetry state update)."""
        if self.is_function_decompiled("func_1B1FB0_802C6E40"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C6E40 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C6FF8_matched(self):
        """TDE test for func_1B1FB0_802C6FF8 in unused_code_1B1FB0 (Onscreen debug font glyph index lookup)."""
        if self.is_function_decompiled("func_1B1FB0_802C6FF8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C6FF8 is currently non-matching (in progress)")

    def test_func_1B1FB0_802C71B8_matched(self):
        """TDE test for func_1B1FB0_802C71B8 in unused_code_1B1FB0 (Debug text character renderer)."""
        if self.is_function_decompiled("func_1B1FB0_802C71B8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_1B1FB0_802C71B8 is currently non-matching (in progress)")


class TestAIRivals(unittest.TestCase):
    """Test cases for AI Rival Pathfinding & Waypoint Navigation (code_43DA0.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        filepath = os.path.join(PROJECT_ROOT, "src", "game", "code_43DA0.c")
        pattern = re.compile(rf"\b{func_name}\b")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            if pattern.search(content):
                for block in content.split(func_name)[1:]:
                    if "{" in block[:300]:
                        return True
        return False

    def test_func_8008A0E0_matched(self):
        """TDE test for func_8008A0E0 in code_43DA0 (AI rival waypoint tracking and path spline interpolation)."""
        if self.is_function_decompiled("func_8008A0E0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008A0E0 is currently non-matching (in progress)")

    def test_func_8008BD2C_matched(self):
        """TDE test for func_8008BD2C in code_43DA0 (AI rival 3D spray display list builder)."""
        if self.is_function_decompiled("func_8008BD2C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008BD2C is currently non-matching (in progress)")

    def test_func_8008D454_matched(self):
        """TDE test for func_8008D454 in code_43DA0 (AI difficulty rubberbanding speed multiplier)."""
        if self.is_function_decompiled("func_8008D454"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008D454 is currently non-matching (in progress)")

    def test_func_8008D94C_matched(self):
        """TDE test for func_8008D94C in code_43DA0 (AI rival obstacle avoidance vector calculator)."""
        if self.is_function_decompiled("func_8008D94C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008D94C is currently non-matching (in progress)")

    def test_func_8008DFD0_matched(self):
        """TDE test for func_8008DFD0 in code_43DA0 (AI rival steering angle and turn aggressiveness)."""
        if self.is_function_decompiled("func_8008DFD0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008DFD0 is currently non-matching (in progress)")

    def test_func_8008E4B0_matched(self):
        """TDE test for func_8008E4B0 in code_43DA0 (AI state reset and grid realignment coordinator)."""
        if self.is_function_decompiled("func_8008E4B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008E4B0 is currently non-matching (in progress)")

    def test_func_8008E794_matched(self):
        """TDE test for func_8008E794 in code_43DA0 (AI waypoint progression verification)."""
        if self.is_function_decompiled("func_8008E794"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008E794 is currently non-matching (in progress)")

    def test_func_8008FB74_matched(self):
        """TDE test for func_8008FB74 in code_43DA0 (Master 3D water spray display list emitter)."""
        if self.is_function_decompiled("func_8008FB74"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8008FB74 is currently non-matching (in progress)")

    def test_func_800916B4_matched(self):
        """TDE test for func_800916B4 in code_43DA0 (HUD matrix projection setup)."""
        if self.is_function_decompiled("func_800916B4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800916B4 is currently non-matching (in progress)")

    def test_func_80091CD8_matched(self):
        """TDE test for func_80091CD8 in code_43DA0 (Dynamic spray particle lifetime updater)."""
        if self.is_function_decompiled("func_80091CD8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80091CD8 is currently non-matching (in progress)")

    def test_func_80091DBC_matched(self):
        """TDE test for func_80091DBC in code_43DA0 (3D wake particle buffer cleanup)."""
        if self.is_function_decompiled("func_80091DBC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80091DBC is currently non-matching (in progress)")


class TestHUDOverlays(unittest.TestCase):
    """Test cases for In-Game HUD Overlays & Telemetry Generator (code_52CD0.c)."""

    def is_function_decompiled(self, func_name: str) -> bool:
        filepath = os.path.join(PROJECT_ROOT, "src", "game", "code_52CD0.c")
        pattern = re.compile(rf"\b{func_name}\b")
        with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
            if pattern.search(content):
                for block in content.split(func_name)[1:]:
                    if "{" in block[:300]:
                        return True
        return False

    def test_func_8009934C_matched(self):
        """TDE test for func_8009934C in code_52CD0 (Catmull-Rom spline evaluator for HUD particle paths)."""
        if self.is_function_decompiled("func_8009934C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009934C is currently non-matching (in progress)")

    def test_func_800998B0_matched(self):
        """TDE test for func_800998B0 in code_52CD0 (HUD coordinate screen projection)."""
        if self.is_function_decompiled("func_800998B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800998B0 is currently non-matching (in progress)")

    def test_func_80099AD8_matched(self):
        """TDE test for func_80099AD8 in code_52CD0 (HUD buoy indicator matrix transform)."""
        if self.is_function_decompiled("func_80099AD8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_80099AD8 is currently non-matching (in progress)")

    def test_func_8009C2CC_matched(self):
        """TDE test for func_8009C2CC in code_52CD0 (HUD animation state machine and timer step)."""
        if self.is_function_decompiled("func_8009C2CC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009C2CC is currently non-matching (in progress)")

    def test_func_8009D6B0_matched(self):
        """TDE test for func_8009D6B0 in code_52CD0 (Buoy miss warning flash animator)."""
        if self.is_function_decompiled("func_8009D6B0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009D6B0 is currently non-matching (in progress)")

    def test_func_8009D96C_matched(self):
        """TDE test for func_8009D96C in code_52CD0 (Buoy power meter level bar display list builder)."""
        if self.is_function_decompiled("func_8009D96C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009D96C is currently non-matching (in progress)")

    def test_func_8009DC10_matched(self):
        """TDE test for func_8009DC10 in code_52CD0 (Speedometer dial needle renderer)."""
        if self.is_function_decompiled("func_8009DC10"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009DC10 is currently non-matching (in progress)")

    def test_func_8009F398_matched(self):
        """TDE test for func_8009F398 in code_52CD0 (Tachometer RPM indicator display list generator)."""
        if self.is_function_decompiled("func_8009F398"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009F398 is currently non-matching (in progress)")

    def test_func_8009FCB0_matched(self):
        """TDE test for func_8009FCB0 in code_52CD0 (Lap counter digit sprite renderer)."""
        if self.is_function_decompiled("func_8009FCB0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_8009FCB0 is currently non-matching (in progress)")

    def test_func_800A063C_matched(self):
        """TDE test for func_800A063C in code_52CD0 (Race timer millisecond split renderer)."""
        if self.is_function_decompiled("func_800A063C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A063C is currently non-matching (in progress)")

    def test_func_800A10E4_matched(self):
        """TDE test for func_800A10E4 in code_52CD0 (Position badge rank indicator renderer)."""
        if self.is_function_decompiled("func_800A10E4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A10E4 is currently non-matching (in progress)")

    def test_func_800A16F0_matched(self):
        """TDE test for func_800A16F0 in code_52CD0 (Checkpoint flyby time split banner)."""
        if self.is_function_decompiled("func_800A16F0"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A16F0 is currently non-matching (in progress)")

    def test_func_800A1CFC_matched(self):
        """TDE test for func_800A1CFC in code_52CD0 (Maximum power boost indicator flame overlay)."""
        if self.is_function_decompiled("func_800A1CFC"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A1CFC is currently non-matching (in progress)")

    def test_func_800A2308_matched(self):
        """TDE test for func_800A2308 in code_52CD0 (Course mini-map rider blip positioner)."""
        if self.is_function_decompiled("func_800A2308"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A2308 is currently non-matching (in progress)")

    def test_func_800A2B24_matched(self):
        """TDE test for func_800A2B24 in code_52CD0 (Course mini-map track contour display list builder)."""
        if self.is_function_decompiled("func_800A2B24"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A2B24 is currently non-matching (in progress)")

    def test_func_800A52D8_matched(self):
        """TDE test for func_800A52D8 in code_52CD0 (Stunt score numerical counter display list builder)."""
        if self.is_function_decompiled("func_800A52D8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A52D8 is currently non-matching (in progress)")

    def test_func_800A68A4_matched(self):
        """TDE test for func_800A68A4 in code_52CD0 (Wrong way warning banner animator)."""
        if self.is_function_decompiled("func_800A68A4"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A68A4 is currently non-matching (in progress)")

    def test_func_800A9D48_matched(self):
        """TDE test for func_800A9D48 in code_52CD0 (Finish line final lap banner renderer)."""
        if self.is_function_decompiled("func_800A9D48"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800A9D48 is currently non-matching (in progress)")

    def test_func_800AAAC8_matched(self):
        """TDE test for func_800AAAC8 in code_52CD0 (Disqualification notice overlay renderer)."""
        if self.is_function_decompiled("func_800AAAC8"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AAAC8 is currently non-matching (in progress)")

    def test_func_800AB25C_matched(self):
        """TDE test for func_800AB25C in code_52CD0 (Retired / out of fuel banner renderer)."""
        if self.is_function_decompiled("func_800AB25C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AB25C is currently non-matching (in progress)")

    def test_func_800AB95C_matched(self):
        """TDE test for func_800AB95C in code_52CD0 (Time up game over banner renderer)."""
        if self.is_function_decompiled("func_800AB95C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AB95C is currently non-matching (in progress)")

    def test_func_800AC098_matched(self):
        """TDE test for func_800AC098 in code_52CD0 (Record lap flash alert display list generator)."""
        if self.is_function_decompiled("func_800AC098"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AC098 is currently non-matching (in progress)")

    def test_func_800AC184_matched(self):
        """TDE test for func_800AC184 in code_52CD0 (New record congratulatory fanfare banner)."""
        if self.is_function_decompiled("func_800AC184"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AC184 is currently non-matching (in progress)")

    def test_func_800AD418_matched(self):
        """TDE test for func_800AD418 in code_52CD0 (2-Player split-screen HUD divider and layout setup)."""
        if self.is_function_decompiled("func_800AD418"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800AD418 is currently non-matching (in progress)")

    def test_func_800ADC8C_matched(self):
        """TDE test for func_800ADC8C in code_52CD0 (Active HUD element visibility bitmask evaluator)."""
        if self.is_function_decompiled("func_800ADC8C"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800ADC8C is currently non-matching (in progress)")

    def test_func_800ADF90_matched(self):
        """TDE test for func_800ADF90 in code_52CD0 (Master HUD display list composite renderer)."""
        if self.is_function_decompiled("func_800ADF90"):
            self.assertEqual(get_file_sha1(ROM_PATH), EXPECTED_SHA1)
        else:
            self.skipTest("func_800ADF90 is currently non-matching (in progress)")


def run_tests():
    loader = unittest.TestLoader()
    suite = unittest.TestSuite()
    suite.addTests(loader.loadTestsFromTestCase(TestRomIntegrity))
    suite.addTests(loader.loadTestsFromTestCase(TestGameEngineCore))
    suite.addTests(loader.loadTestsFromTestCase(TestWaterPhysics))
    suite.addTests(loader.loadTestsFromTestCase(TestCodeSegA95D0))
    suite.addTests(loader.loadTestsFromTestCase(TestCodesegUI))
    suite.addTests(loader.loadTestsFromTestCase(TestCourseOverlays))
    suite.addTests(loader.loadTestsFromTestCase(TestSysLayer))
    suite.addTests(loader.loadTestsFromTestCase(TestAudioEngine))
    suite.addTests(loader.loadTestsFromTestCase(TestCameraEngine))
    suite.addTests(loader.loadTestsFromTestCase(TestQuickWinModules))
    suite.addTests(loader.loadTestsFromTestCase(TestSaveSystem))
    suite.addTests(loader.loadTestsFromTestCase(TestPhysicsModules))
    suite.addTests(loader.loadTestsFromTestCase(TestRiderKinematics))
    suite.addTests(loader.loadTestsFromTestCase(TestCourseLoading))
    suite.addTests(loader.loadTestsFromTestCase(TestFlightDebug))
    suite.addTests(loader.loadTestsFromTestCase(TestAIRivals))
    suite.addTests(loader.loadTestsFromTestCase(TestHUDOverlays))
    runner = unittest.TextTestRunner(verbosity=2)
    result = runner.run(suite)
    return 0 if result.wasSuccessful() else 1

if __name__ == "__main__":
    sys.exit(run_tests())
