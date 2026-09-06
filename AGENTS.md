# Wave Race 64 Decompilation Invariants & Agent Guidelines

## 1. ROM Matching Invariant
- **Target Retail ROM:** `build/waverace64.us.rev1.z64`
- **SHA-1 Checksum:** `508dfc2d4caa42b6f6de5263d0aed5e44ac7966a`
- **Rule:** Never commit code if `make` does not output `waverace64.us.rev1.z64: OK`. Every build must verify byte-for-byte SHA-1 retail match.

## 2. Compiler Environment & Target Architecture
- **Compiler:** Silicon Graphics IDO 5.3 C89 (`-O2 -g3` depending on the file).
- **Architecture:** MIPS III (32-bit big-endian).
- **Prototyping Discipline:** 
  - Do NOT modernize prototypes. In IDO C89, `void func()` behaves differently from `void func(void)`.
  - Do NOT change types or parameter counts without checking all callers across overlays and source files.
- **Float Handling:**
  - Wave Race 64 makes heavy use of single-precision floating point math. Always append `f` to float literals (e.g., `1.0f`, not `1.0`), otherwise IDO defaults to `double`, loading constants from `.rodata` and emitting `f64` instructions (`cvt.d.s`, `add.d`, etc.).
  - If register allocation is off on float calculations, refactor intermediate variables rather than complex chained expressions.

## 3. Workflow & Decompilation Lifecycle

### Context Generation
Before running diffs or translators, generate the latest header context:
```bash
tools/m2ctx src/<path>/<file>.c
```

### Initial Translation
To produce starting C scaffolding from assembly:
```bash
python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c asm/us/rev1/nonmatchings/<path>/<func>.s
```
`tools/m2ctx` writes `ctx.c` (+ cache) to the repo root; `-t` accepts `mips-ido-c` — check `--help` before trusting documented values.

### In-Progress Scaffolding
All functions in progress must remain wrapped inside `#ifdef NON_MATCHING` with `#pragma GLOBAL_ASM` intact under `#else`:
```c
#ifdef NON_MATCHING
void func_800XXXXX(...) {
    /* In-progress implementation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/.../func_800XXXXX.s")
#endif
```
**NEVER** remove `#pragma GLOBAL_ASM` or leave unverified/syntax-broken C code outside `#ifdef NON_MATCHING`.

### Verifying Drafts
`make NON_MATCHING=1 build/src/<path>/<file>.o` compiles every draft in the translation unit, so one stale prototype in an unrelated function breaks the whole build — do NOT touch unrelated scaffolding to fix it. Instead compile the draft as a standalone IDO probe (`scratch/probe_<func>.c` = needed includes + draft body) with the Makefile's exact flags, and diff with `tools/asm-differ/diff.py -o -s <func> -f <probe.o> --base-asm <sliced-objdump>`. Delete all `scratch/probe_*` files and any probe copies under `expected/` before committing.

### Control Flow Matching Rules
- If diffs show instructions at the loop exit rather than the loop head, favor `do { ... } while (...)` over `for` or `while`.
- Avoid early returns (`return;`) if the original assembly uses branch-likely jumps to a unified epilogue block.
- Match register allocations by ordering local variable declarations from highest to lowest usage, or introducing explicit scope blocks `{ ... }`.

### Handling .rodata, .data, and .bss
- Do not migrate global or static variables unless all functions accessing that symbol's offsets are matching.
- If a function requires matched `.rodata` (e.g., switch jump tables or float pools), preserve the `#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` wrapper until the whole translation unit matches.

## 4. Promotion Checklist

A function may ONLY be promoted when `.venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func>` reports zero diffs (`TARGET CURRENT (0)`):

1. **Verify C Implementation**: Ensure clean C compilation without warnings or syntax errors.
2. **Remove Wrappers**: Remove `#ifdef NON_MATCHING` and `#pragma GLOBAL_ASM`, leaving raw C.
3. **Delete Stub**: Delete the associated `.s` stub: `rm asm/us/rev1/nonmatchings/.../<func>.s`.
4. **Verify Matching ROM**: Run `make` to verify binary hash integrity (`waverace64.us.rev1.z64: OK`).
5. **Update Test Suite**: Add or update the matching test case in `tests/test_matching.py`. Test classes must inherit directly from `unittest.TestCase` and be registered in `run_tests()`.
6. **Run Tests**: Run `make test` and ensure all suites pass cleanly.
7. **Record Progress**: Run `make progress` to record progress gain.
