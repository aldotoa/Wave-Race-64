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
- **WIP Functions Must Remain Wrapped**:
  - While actively researching, decompiling, or iterating on a function, the C implementation MUST remain enclosed inside `#ifdef NON_MATCHING` with the assembly pragma intact under `#else`:
    ```c
    #ifdef NON_MATCHING
    void func_800XXXXX(...) {
        /* In-progress C implementation */
    }
    #else
    #pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/.../func_800XXXXX.s")
    #endif
    ```
  - **NEVER** remove `#pragma GLOBAL_ASM` or leave unverified/syntax-broken C code outside `#ifdef NON_MATCHING`, as this immediately breaks the retail ROM matching build.
- **Strict Function Promotion Procedure**:
  - A function is ONLY eligible for promotion when `.venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func>` reports a 100% byte-for-byte exact match (`TARGET CURRENT (0)`).
  - Promotion sequence:
    1. Verify clean C compilation without warnings or syntax errors.
    2. Remove the `#ifdef NON_MATCHING` / `#pragma GLOBAL_ASM` wrapper, leaving the clean C implementation.
    3. Delete the assembly stub file on disk: `rm asm/us/rev1/nonmatchings/.../<func>.s`.
    4. Run `make` to verify `waverace64.us.rev1.z64: OK`.
    5. Run `make test` to verify all unit tests pass.
    6. Run `make progress` to record the promoted function and byte count.
- If a function is already matching, ensure it compiles cleanly with standard compiler flags without pragmas.
- For files with existing `#ifdef NEEDS_RODATA` or `#ifdef NEEDS_DATA` or `#ifdef NEEDS_BSS`, use `#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` so the C implementation is active in non-matching mode.

## 4. Test-Driven Engineering (TDE)
- Every newly decompiled function must have a corresponding test case in `tests/test_matching.py`.
- Test classes must inherit directly from `unittest.TestCase` and be registered in `run_tests()`.
- Run `make test` before every commit. All tests must pass.
