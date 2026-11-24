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
  - If a draft calls a same-file function defined later in the TU, add a forward declaration copied verbatim from the definition signature (an implicit declaration conflicts with the later definition).
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
**Stale-object hygiene:** the `NON_MATCHING=1` flag is untracked (same `.o` path), so a draft object left in `build/` is silently reused by plain `make`/`make test` — always `rm -f build/src/<path>/<file>.o` before switching back, or a stale draft poisons the ROM hash and the suite.

Probe-loop mechanics that must all hold at once:
- Assemble the ground-truth stub directly: strip the `nonmatching` first line, prepend `.include "macro.inc"` + `.set noreorder` (gas reorder inserts phantom delay-slot nops), assemble with `-I include`, and verify the instruction count equals the stub's opcode-comment count.
- `--base-asm` must be sliced to the single function (`awk '/<func>:/{f=1} ...'` — the `>` matters; a bare `/func:/` pattern silently yields an empty base and a vacuous all-CURRENT diff).
- `-f` resolves under `expected/`: keep the probe object at the CWD-relative path AND `cp` a copy to `expected/<same-path>`.
- Stale objects lie: `sleep 1` + `touch` the probe before every build and check the `.o` is newer than the `.c` afterwards; diff WITHOUT `-m` so the score reflects your C. Identical scores across different sources always mean a stale object, never a real result.
- `-s` (stop-at-ret) truncates multi-return functions at the first `jr` — drop it for truthful full-function scores.
- A `NON_MATCHING=1` object left in `build/` poisons later matching builds (same `.o` path): always `rm -f <obj>` before switching back, or the ROM checksum plus ROM-dependent tests fail bogusly.
- Verify probe flags EXACTLY match the matching build (`make -n` vs probe flags, one per line, `diff`) — a single stray define or include dir invalidates every conclusion.

### Control Flow Matching Rules
- If diffs show instructions at the loop exit rather than the loop head, favor `do { ... } while (...)` over `for` or `while`.
- Avoid early returns (`return;`) if the original assembly uses branch-likely jumps to a unified epilogue block.
- Match register allocations by ordering local variable declarations from highest to lowest usage, or introducing explicit scope blocks `{ ... }`.
- Use a single `return` with `goto end;` for early exits: two C `return`s flip the final epilogue to `move;jr;nop` plus likely-fills (`bnezl`) on late branches.
- A store in a non-likely branch delay slot (`bne`/`beqz` + `sw`) executes on BOTH paths: model it as straight-line code before the `if`, not inside either branch.
- A redundant doubled store (`D = 1; if (f == 1) { D = 1; }`) merges to a single store in a normal (`bne`) branch delay slot, while the single-store form emits a likely (`bnel`) branch.
- Empty `else {}` arms can be load-bearing for the branch skeleton — never delete one without re-diffing.
- Equivalent tail spellings can emit identical bytes when the join coincides with function end (`if (t < K) goto end; ...` vs nested `if (t >= K) { ... }`); if the tail already matches, try the other spelling to shift upstream scheduling.
- Anonymous `D++` keeps the incremented value in a t-reg; a named `s32 temp = D + 1` local parks it in a v-reg. Drop the named local when the stub holds the temp in `t8`/`t9`.

### Generated asm (never committed)
- `asm/` is splat output from the user's baserom (`make extract`) and is gitignored, so the public repo holds no ROM-derived data. Every hand change to asm must instead live in splat config, or the next clean extract breaks the link.
- Renaming a function or data symbol in C: add `Name = 0xADDR; // type:func` (or a data type such as `s32`/`f32`) to `linker_scripts/us/rev1/symbol_addrs.txt` (overlay symbols also need `rom:0x...`).
- Splitting or migrating rodata/data: express it in `waverace64.us.rev1.yaml` or with `// force_migration:True` symbol entries, never by editing a `.s` file.
- Check: `rm -rf asm/us/rev1 && make extract && make` must still report `waverace64.us.rev1.z64: OK`.

### Handling .rodata, .data, and .bss
- Do not migrate global or static variables unless all functions accessing that symbol's offsets are matching.
- If a function requires matched `.rodata` (e.g., switch jump tables or float pools), preserve the `#if defined(NEEDS_RODATA) || defined(NON_MATCHING)` wrapper until the whole translation unit matches.

### Sweep Discipline & Park Rules
- Batch structural variants (3+): build each probe with identical flags, record one score line per variant, and read order/shape in the objdump window — not just the score — before designing the next batch.
- Bisect scheduler quirks in minimal `scratch/micro_*.c` first: shrink to the smallest reproducer, then add one context element at a time until the output flips; that element is the lever the full-probe sweep exploits.
- Park at the floor when only scheduler-opaque rows remain (e.g. one adjacent fill-order swap after dozens of structural variants): keep the draft behind `#ifdef NON_MATCHING`, document the floor score and which constructs are load-bearing in a comment, and move on.

## 4. Promotion Checklist

A function may ONLY be promoted when `.venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func>` reports zero diffs (`TARGET CURRENT (0)`):

1. **Verify C Implementation**: Ensure clean C compilation without warnings or syntax errors.
2. **Remove Wrappers**: Remove `#ifdef NON_MATCHING` and `#pragma GLOBAL_ASM`, leaving raw C.
3. **Delete Stub**: Delete the associated local `.s` stub: `rm asm/us/rev1/nonmatchings/.../<func>.s` (asm/ is untracked; splat will not regenerate a stub once the `GLOBAL_ASM` pragma is gone).
4. **Verify Matching ROM**: Run `make` to verify binary hash integrity (`waverace64.us.rev1.z64: OK`).
5. **Update Test Suite**: Add or update the matching test case in `tests/test_matching.py`. Test classes must inherit directly from `unittest.TestCase` and be registered in `run_tests()`.
6. **Run Tests**: Run `make test` and ensure all suites pass cleanly.
7. **Record Progress**: Run `make progress` to record progress gain.
