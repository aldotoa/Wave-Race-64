# Wave Race 64 Decompilation Invariants & Guidelines

## 1. ROM Matching Integrity
- The target retail ROM checksum is:
  - File: `build/waverace64.us.rev1.z64`
  - SHA-1: `508dfc2d4caa42b6f6de5263d0aed5e44ac7966a`
- Every build using `make` must verify `waverace64.us.rev1.z64: OK`. Never break the matching ROM build.

## 2. IDO 5.3 C89 Compiler Quirks & Calling Conventions
- **Unprototyped Declarations**: In IDO 5.3 C89, unprototyped function declarations like `void* func_8007C31C();` generate different register saving and calling convention behavior than explicit `void func_8007C31C(void);`.
- **STRICT RULE**: Never change existing function prototypes or declarations unless verified against every caller across all source and overlay files.

## 3. Dual-Mode Decompilation Architecture
- All decompiled C functions must be wrapped under `#ifdef NON_MATCHING`:
  ```c
  #ifdef NON_MATCHING
  void func_800XXXXX(...) {
      /* C implementation */
  }
  #else
  #pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/.../func_800XXXXX.s")
  #endif
  ```
- If a function is already matching, ensure it compiles cleanly with standard compiler flags without pragmas.
- For files with existing `#ifdef NEEDS_RODATA` or `#ifdef NEEDS_DATA` or `#ifdef NEEDS_BSS`, use `#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` so the C implementation is active in non-matching mode.

## 4. Test-Driven Engineering (TDE)
- Every newly decompiled function must have a corresponding test case in `tests/test_matching.py`.
- Test classes must inherit directly from `unittest.TestCase` and be registered in `run_tests()`.
- Run `make test` before every commit. All tests must pass.
