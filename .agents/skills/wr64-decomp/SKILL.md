---
name: wr64-decomp
description: >-
  Workflows, build commands, testing procedures, IDO 5.3 compiler matching
  techniques, and debugging tools for the Wave Race 64 (N64) decompilation
  project. Use whenever building, testing, matching functions, or auditing
  source files in this repository.
---

# Wave Race 64 Decompilation Workflow Runbook

| Attribute | Value |
|---|---|
| **Name** | `wr64-decomp` |
| **Description** | Workflows, build commands, testing procedures, IDO 5.3 compiler matching techniques, and debugging tools for the Wave Race 64 (N64) decompilation project. Use whenever building, testing, matching functions, or auditing source files in this repository. |

---

## Core Commands Quick Reference

| Command | Purpose |
|---|---|
| `make` | Builds the ROM and verifies byte-for-byte SHA-1 retail match |
| `make test` | Runs the 416-test Test-Driven Engineering (TDE) verification suite |
| `make clean` | Cleans all build artifacts in `build/` |
| `make progress` | Displays current function count, byte count, and percentage progress |
| `./diff <func_name>` | Interactive assembly differ comparing compiled C against retail ROM |
| `tools/m2ctx src/<path>/<file>.c` | Generates preprocessed C context (`ctx.c` in repo root) for decomp.me and m2c |
| `python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c <func.s>` | Converts raw assembly to an initial IDO C89 candidate function (`-t` accepts `mips-ido-c`; check `--help`) |
| `python3 tools/stack_diff.py <func> <target.s> [current.o]` | Side-by-side stack layout and frame size differ (<50ms feedback) |

---

## Verification Procedures

### 1. TDE Test Suite
Always verify that all unit and matching tests pass cleanly:
```bash
make test
```

### 2. Checksum Verification
Ensure the generated ROM matches the target retail hash:
```bash
sha1sum build/waverace64.us.rev1.z64
# Expected: 508dfc2d4caa42b6f6de5263d0aed5e44ac7966a
```

### 3. Non-Matching Pragma Audit
To verify that a source file has 0 assembly pragmas remaining under `NON_MATCHING`:
```bash
gcc -E -DNON_MATCHING -Iinclude -Iinclude/libc <path/to/file.c> | grep -c "#pragma GLOBAL_ASM"
# Expected: 0
```

---

## Decompilation Matching Workflow

### Step 1: Candidate Selection
Query nonmatching assembly stubs by line count to prioritize small leaf functions and overlay stubs:
```bash
find asm/us/rev1/nonmatchings -name "*.s" -exec wc -l {} + | awk '$1 <= 60 {print $1, $2}' | sort -n
```

### Step 2: Context Generation & Initial Translation
Generate preprocessed context for the file:
```bash
tools/m2ctx src/<path>/<file>.c
```
Run automated m2c translation to produce starting C scaffolding:
```bash
python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c asm/us/rev1/nonmatchings/<path>/<func_name>.s > scratch/<func_name>.c
```

### Step 3: Interactive Differ
Always pass `-m` (recompile `.o`), `-o` (diff object file directly to prevent self-matching false positives), `-s` (stop at return), and `-U 2` (compress identical runs):
```bash
.venv/bin/python3 tools/asm-differ/diff.py -m -o -s -U 2 <func_name>
```

> [!WARNING]
> **The `GLOBAL_ASM` Self-Match Trap**:
> For functions wrapped under `#ifdef NON_MATCHING`, running standard `diff.py -m -o -s` will falsely show `CURRENT (0)` because asm-processor substitutes the raw assembly from `#pragma GLOBAL_ASM`.
> To accurately diff your C implementation:
> - Either compile directly via:
>   ```bash
>   make NON_MATCHING=1 build/src/<path>/<file>.o && .venv/bin/python3 tools/asm-differ/diff.py -o -s <func_name>
>   ```
> - Or use the automated dry-run check:
>   ```bash
>   python3 tools/promote.py --dry-run <func_name> <path/to/file.c>
>   ```
> - Or, when `make NON_MATCHING=1` fails on an unrelated draft's stale prototype (do NOT touch unrelated scaffolding to fix it), compile the draft as a standalone probe with the Makefile's exact flags (see Step 4) and diff without `-m`:
>   ```bash
>   # scratch/probe_<func>.c = needed includes + draft body only
>   mips-linux-gnu-objdump -dr build/src/<path>/<file>.o \
>     | awk '/^0.*<func_name>:/{f=1} f{print} f&&/^$/{c++; if(c==1) exit}' > scratch/base_<func>.s
>   cp scratch/probe_<func>.o expected/scratch/probe_<func>.o   # -f resolves under expected/
>   .venv/bin/python3 tools/asm-differ/diff.py -o -s <func_name> -f scratch/probe_<func>.o \
>     --base-asm scratch/base_<func>.s --format plain --no-pager
>   ```
>   `--base-asm` must be sliced to the single function (a whole-object dump anchors TARGET on the wrong function). Rebuild the base from a matching tree — never trust `build/` objects when src holds in-progress drafts. Delete `scratch/probe_*`, `scratch/base_*`, and any probe copies under `expected/` before committing.
- Drop `-s` for functions with multiple `jr $ra`: stop-at-ret truncates the diff at the first return and reports vacuous scores. Always confirm full-function output reaches the final `jr` before trusting a score.

### Step 4: Scratchpad Fast Prototyping (Direct IDO Invocation)
When iterating on fine register allocation or compiler quirks, do not run a full project build. Determine the exact compiler flags used by the Makefile:
```bash
make -n build/src/<path>/<file>.o
```
Then invoke the recompiled IDO 5.3 compiler directly against a scratch file for sub-50ms feedback:
```bash
tools/ido-static-recomp/build/5.3/out/cc -c -G 0 -non_shared -Xcpluscomm \
    -I include -I . -I include/libc -I include/PR -I bin \
    -nostdinc -Wab,-r4300_mul -woff 649,838,712,516 -DVERSION_US=1 \
    -mips2 -32 -EB -D_MIPS_SZLONG=32 -DNDEBUG -DF3D_OLD -D_FINALROM \
    -DTARGET_N64 -DLANGUAGE_C -D_LANGUAGE_C -O2 \
    -o scratch/test.o scratch/test.c
mips-linux-gnu-objdump -dr scratch/test.o
```

### Step 5: Promotion on 100% Match (`CURRENT (0)`)
> **Commit or stash first — even for `--dry-run`.** `tools/promote.py` reverts the source file to HEAD whenever the post-promotion matching build fails, wiping ALL uncommitted drafts in that file (not just the promoted function). The `--dry-run` path prints `Reverting...` and does the same. Proven 2026-09-06: a `--dry-run` on `func_8009934C` reverted `src/game/code_52CD0.c` to HEAD, deleting the in-progress `func_800998B0`/`func_800AC098` bodies (only `include/structs.h` survived, different file). Never run any `promote.py` invocation with uncommitted work in the target file.
Once 0 diffs are verified, promote the function:
```bash
# Automated promotion (recommended)
python3 tools/promote.py <func_name> <path/to/source.c>
```

Manual promotion sequence:
1. Remove `#ifdef NON_MATCHING` and `#pragma GLOBAL_ASM` wrappers in the `.c` file.
2. Delete the assembly stub file from disk:
   ```bash
   rm asm/us/rev1/nonmatchings/.../<func_name>.s
   ```
3. Invalidate intermediate objects and verify matching ROM:
   ```bash
   touch src/<path>/<file>.c && make
   ```
4. Verify tests and progress:
   ```bash
   make test && make progress
   ```

### Step 6: `NON_MATCHING=1` Object File Hygiene
Compiling a target with `make NON_MATCHING=1 build/src/<file>.o` leaves an unmatching object file in `build/`. A subsequent standard `make` will treat this `.o` as up-to-date and fail at the link stage with unresolved symbols. Always invalidate the object cache before running matching verification:
```bash
touch src/<file>.c && make
```
- **Stale-build guard**: `touch` + immediate `make` in the same second can silently skip recompilation (coarse mtime comparison) and diff a stale `.o`, producing identical scores across different sources. Always `sleep 2` before `touch`, and confirm the `Compiling:` line appears in make output before trusting any diff score.
- A stale `NON_MATCHING=1` object linked into the ROM changes its SHA-1 and fails all 400+ ROM-dependent tests in `make test`. If the suite suddenly fails with SHA mismatches, rebuild the matching object (`touch src/<file>.c && make build/src/<file>.o`) and re-run.

### Step 7: Switch Case Order Must Match Jump-Table Layout
IDO emits switch-case bodies in source order. If `diff.py` shows a whole case body misaligned (stores where the target loads, `|` chaos across a case), check the jump-table label addresses in the target `.s`: if a later case number's label sits EARLIER in the binary (e.g. case 5 at `0x6150` before case 2 at `0x6174`), move that `case N:` block earlier in source (keeping its number). One reorder fixed ~1600 diff points in `ovl_1B9440`.

---

## Token-Efficient Diffing & Testing Protocols

- **Compressed Assembly Diffs (`-U 2`)**: Always pass `-U 2` (`--compress-matching 2`) to collapse runs of identical instructions and preserve terminal context.
- **Terse Test Output**: Avoid running verbose `make test` which prints 700+ lines into context. Pipe through `tail`:
  ```bash
  make test 2>&1 | tail -n 5
  ```
- **Quick Match Score Check**: Check whether a function matches without emitting full disassembly:
  ```bash
  .venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func_name> 2>/dev/null | head -n 3
  ```
- **Automated Micro-Permutation Search (Score < 50)**:
  When a function is 90%+ matched and differences are restricted to small setup blocks, declaration orders, or comma expression sequences:
  - **Do NOT** manually edit and recompile in a multi-turn conversation loop (costs ~3,800 tokens and 5s roundtrip per test).
  - **Do** write a standalone Python script in `scratch/test_perm.py` that invokes `tools/ido-static-recomp/build/5.3/out/cc` directly against permutations of the candidate expression. Testing 100+ permutations locally in under 5 seconds consumes <1,000 tokens total (~70x efficiency gain).
- **Stack Layout Inspection via `tools/stack_diff.py`**:
  Instead of manual `objdump` and decimal offset calculations, run:
  ```bash
  python3 tools/stack_diff.py <func_name> <path/to/target.s> <path/to/current.o>
  ```
  to immediately verify frame sizes, identify shifted offsets, detect missing slots, and map padding gaps in under 50 tokens.
- **Compact Metric Diffing (`tools/diff_summary.py`)**:
  Avoid printing full assembly diffs into the terminal/context window. Run:
  ```bash
  python3 tools/diff_summary.py <func_name> <path/to/current.o>
  ```
  to output diff score, frame size match status, saved register mapping, and the first divergent instruction block in <50 tokens.
- **Automated Regalloc & Stack Search (`tools/regalloc_search.py`)**:
  When tuning variable declarations to match target stack frame size (e.g., 0x58 vs 0x60) or register allocations ($s0-$s8), let `tools/regalloc_search.py` evaluate permutations locally against direct IDO 5.3 rather than manual multi-turn trial-and-error.
- **No Multi-Line Inline Python via Shell**:
  Never execute multiline scripts or complex regex via `python3 -c '...'` in `zsh` as shell expansions (`[]`, `\`, quotes) trigger syntax errors and waste conversational turns. Always save helper scripts to `.py` files in `tools/` or `scratch/`.

---

## IDO 5.3 C89 Optimization & Register Matching Techniques

### Float Precision & Single-Precision Promotion
Wave Race 64 relies heavily on MIPS Coprocessor 1 (`cop1`) math for buoyancy, wave modeling, and physics simulations.
- **Literal Discipline**: Always append `f` to floating-point constants (e.g., `1.0f`, `0.5f`). An untyped literal like `0.5` causes IDO to treat the constant as `f64` (`double`), pulling it from `.rodata`, emitting `cvt.d.s`, and executing `mul.d` / `add.d` in register pairs (`$f0`/`$f1`) instead of single-precision `mul.s` / `add.s`.
- **Float Argument Regalloc (MIPS O32)**: Floating-point arguments that follow integer or pointer arguments occupy integer registers (`$a2`, `$a3`) and are loaded using `lw` rather than `lwc1`. Ensure full, explicit prototypes are used so IDO enforces this ABI rule.

### Callee-Saved Float Registers (`$f20`, `$f22`) & 64-bit Alignment
- In functions making external calls, local `f32` variables that stay live across function calls force IDO to allocate callee-saved floating-point registers (`$f20`, `$f22`).
- Under `-mips2 -32`, IDO emits `s.d` / `l.d` to save/restore float pairs only if the allocated stack slot is 8-byte aligned.
- If your diff shows `s.d $f20, 0x30($sp)` in the target but your compiler generates two `swc1` instructions (`swc1 $f20`, `swc1 $f21`), your stack frame or local variable alignment is misaligned by 4 bytes. Reorder scalar declarations to realign the float save block to an 8-byte boundary.

### Chow-Hennessy Priority Coloring (`$s0` vs `$s1`)
IDO 5.3's global optimizer (`uopt`) allocates callee-saved registers using Chow-Hennessy priority coloring:
$$\text{Priority} = \frac{\text{Savings}}{\text{Live Range Length}}$$
Registers (`$s0`, `$s1`, `$s2`, ...) are assigned in descending priority order among live ranges spanning function calls.
- **Live-Range Dilution Across Calls**: Reusing a pointer or local variable after a function call extends its live range length (increasing the denominator) and lowers its priority. This causes another variable with tight loop references to steal `$s0`.
- **Remediation Techniques**:
  - *Scope Isolation*: Restrict variable declarations to inner blocks (`{ ... }`) to prevent `uopt` from coalescing disjoint webs across calls.
  - *Syntactic Address-of Indexing (`&arr[idx]`) vs Pointer Arithmetic*: Accessing arrays via pointer arithmetic `*(arr + offset)` or `ARR_PTR` increments references to `offset`, causing `offset` to steal higher-priority callee-saved registers (`$s0`). Writing direct array indexing with address-of `&arr[index]` increments the reference count of `index`. This boosts `index`'s priority score in Chow-Hennessy coloring, ensuring it claims `$s0` over dependent pointers or offsets.
  - *Register Caching Across Branch Fan-out*: In complex branching logic (e.g. D-pad Left/Right), explicitly caching `state = *s2;` binds `state` to a temporary register (`$a2`), preventing `uopt` from placing global pointers into `$a2` and locking globals into target registers (`$t0`).
  - *Priority Equalization*: Reusing or extending the live range of a competing variable after a loop can artificially degrade its priority score and restore the desired register ordering.
  - In leaf functions, the `register` keyword (e.g., `register s32 s0 = arg1->unk4;`) or declaration ordering can guide initial register selection.

### Loop Induction Variable Elimination (`blt` vs `li $reg, limit; bne`)
- **Problem**: In small counted loops (e.g., `for (i = 0; i < 2; i++)`), `uopt` frequently converts inequalities to `!= limit`, hoists the bound into a dedicated register before the loop (`li $a2, 2`), and branches with `bne $v0, $a2, .Lloop`. When target assembly uses `slti $at, $v0, limit; bnez $at, .Lloop` (the pseudo-instruction `blt`), bound hoisting must be suppressed.
- **Heuristic**: If counter `i` is dead after the loop, `uopt` eliminates it and hoists the bound. Reusing `i` across subsequent logic (such as an immediately following loop `for (i = 0; i < 4; i++)`) marks `i` as live across loop boundaries, suppressing bound hoisting and forcing `uopt` to emit the canonical `blt`.

### Single-Line Statement Binding for Assembler Store Ordering (`.loc` Directive Quirk)
- **Problem**: Contiguous array element stores often emit out of offset order (e.g., `2($at)`, `4($at)`, `6($at)`, `0($at)`). IDO attaches distinct `.loc` source line directives to unrolled body iterations, and the SGI assembler (`as1`) treats `.loc` transitions as instruction scheduling boundaries.
- **Solution**: Placing the entire unrolled loop on a single line:
  ```c
  for (i = 0; i < 4; i++) D_802C8C70[i] = 0;
  ```
  binds all unrolled stores to a single `.loc` directive, compelling `as1` to emit stores in strictly sequential offset order (`0($at)`, `2($at)`, `4($at)`, `6($at)`).

### Loop Construct Selection (`for` vs `while` vs `do-while`)
- `for` loops: `for (i = 0; i < N; i++)` produces a test-at-bottom structure with an unconditional initial branch (`b .test; nop`), matching most retail N64 loops.
- `while` loops: Produce top-of-loop branch tests directly without an entry jump.
- `do-while` loops: Emit no initial entry guard and test condition strictly at the bottom.
- **Diagnostic**:
  - If assembly shows a leading unconditional branch (`b`) jumping down to a `blt`/`bne` at the loop bottom: use `for`.
  - If assembly executes condition testing immediately at the top before the body: use `while`.
  - If loop body executes immediately with only a bottom branch: use `do-while`.

### Loop Body Statement Order & Negative-Offset Delay Slot Stores
In loops updating multiple arrays or pointers, statement sequence controls whether IDO emits strength-reduced pointer post-increments with negative offsets (`sw $zero, -4($reg)`).
Storing the induction variable last (e.g., `arr1[i] = 0; arr2[i] = 0; arr3[i] = i;`) causes IDO to emit the dependent store `sh $v0, 0($a1)` first, increment `$v0`, test the loop condition, increment the pointers (`addiu $v1, 4; addiu $a0, 4; addiu $a1, 2`), and schedule the final zero store into the branch delay slot with a `-4` offset (`bnez $at, .Lloop; sw $zero, -4($a0)`).

### IDO 5.3 Stack Frame Layout & Local Variable Ordering
- **High-to-Low Stack Order**: Local variables are allocated on the stack in descending address order based on their declaration sequence. The first declared locals occupy the highest stack addresses (directly below caller arguments); later declared variables sit closer to `$sp` (just above the callee-saved register save area).
- **Alignment & Buffer Padding Management**: When large buffers (e.g., `MtxF`, `Mtx`) are shifted by 8 bytes due to alignment constraints, declare small scalar variables (such as loop index `i`) after the matrix structures. IDO absorbs scalars declared last into the bottom padding area above the saved registers, preventing an unwanted `+8` byte shift across earlier stack buffers.
  ```c
  /* Example: 504-byte frame with five nested matrices */
  s32 angle;      /* 0x1F0 - top of stack, declared first */
  s32 cond;       /* 0x1EC */
  s32 j;          /* 0x1E8 - intentionally above floats */
  f32 var_fs1;    /* 0x1E4 */
  f32 var_fs2;    /* 0x1E0 */
  MtxF sp1A4;     /* 0x1A4 */
  MtxF sp164;     /* 0x164 */
  MtxF sp124;     /* 0x124 */
  Mtx spE0;       /* 0xE0 */
  Mtx spA0;       /* 0xA0 */
  s32 i;          /* 0x88 - declared last, absorbs padding above saved regs */
  ```
- **`cfe` Outer-Scope Variable Stack Inflation & Offset Shifting**:
  - In IDO 5.3 C89, `cfe` reserves stack slots for **all** scalar variables declared in the outer function scope, even if `uopt` later keeps them purely in registers or eliminates them entirely.
  - In m2c output, extraneous intermediate assignment variables (e.g. `s32 ready = *ready_ptr;`, `s32 v0;`, or scratch pointers `p`) can cause the total variable count to cross an 8-byte alignment boundary. This triggers an unwanted 8- or 16-byte stack frame expansion (e.g. `0x58` inflated to `0x60`, or `0xF8` to `0x100`) and shifts subsequent stack offsets by 4 or 8 bytes (`0x40 -> 0x44`, `0x48 -> 0x4c`).
  - *Remediation*: Audit variables used only locally. Eliminate intermediate scalar holders (evaluating `*ready_ptr` directly) or isolate temporary holders inside inner `{ ... }` blocks (e.g., inside `do { ... }` or `if`). Moving variable declarations to inner scopes completely suppresses their outer stack allocation.
- **4-Tier Stack Zone Architecture**:
  IDO stack frames adhere to a predictable 4-tier layout:
  1. *Top Zone* (`$sp + FrameSize - 4` down): Declared outer locals in descending declaration sequence.
  2. *Middle Zone*: Large structs, matrix buffers, or padding gaps.
  3. *Spill Zone* (`$sp + 0x48` up): Low temporary spill slots allocated dynamically by `uopt`.
  4. *Base Zone* (`$sp + 0x00` to `0x44`): Outgoing argument space (minimum 0x10 or 0x40 aligned) followed by callee-saved registers (`$s0`, `$ra`).

### Pointer Materialization & Offset Folding
- **Base Pointer Materialization**: IDO at `-O2` eagerly folds constant offsets (e.g., `(base + 0x5C) + 0x18` folds into `0x74(base)`). To force IDO to materialize the base pointer into a register (`addiu $v0, $a0, 0x5c`) and emit relative stores (`0x18($v0)`, `0x24($v0)`), initialize the sub-struct pointer at declaration (`Struct_B* b = (Struct_B*)(dst + 0x5C);`) and access `b` across multiple conditional branch blocks (`if (src1 != NULL) ... if (src2 != NULL) ...`). IDO treats `b` as live across blocks and preserves the pointer in `$v0`.
- **Multi-Symbol `%hi` Address Sharing**: When consecutive stores share a single `lui $at, %hi(...)` (e.g., storing to consecutive `s16` addresses), declare symbols as an array (`s16 D_802C8C70[4]`) or struct rather than separate scalar globals. Independent globals force IDO to reload `%hi` for each store.
- **Sub-struct Strength Reduction**: When targeting unrolled vector stores like `swc1 $f4, -4($t0)` or `swc1 $f16, 0x20($a1)`, cast the base pointer to a local sub-struct pointer (`(SubStruct*)(dst + offset)`) rather than indexing a flat float array.

### Branch-Likely (`beql` / `bnel`) & Delay Slot Control
- `while ((val = arr[s0]) == 0) { arr[idx = ++s0]; }` generates `beql` with delay-slot index increments.
- A void function call pattern `if (cond) { func(arg); } return arg;` generates `bnel` with `jal` delay-slot stack spilling (`sw $v0, 0x18($sp)`) and restoration (`lw $a0, 0x18($sp)`).
- **Early Return vs Single Epilogue**:
  - If the assembly ends with multiple `jr $ra` statements, use early returns (`return;` or `return val;`) within conditional branches.
  - If the assembly routes all paths through a single shared epilogue label (one `jr $ra` preceded by callee-saved register restores), structure the C code as a single-exit function (avoid early returns; use unified control flow or `goto end;`).
- **Dense 0..N Switch Dispatch**: keep an explicit `case 0: break;` first — without it the leading `beqz` check vanishes and the dispatch reshapes around a trailing branch with different delay fills. Addend order in the switch-value computation feeds temp-register coloring (`D[0] + (D[1] * 2)` vs `(D[1] * 2) + D[0]` rotate the same `lhu`/`sll`/`addu` tail across different temps) — try both orders before touching declarations.
- **Micro-Bisect Scheduler Quirks**: identical dispatch C can emit `beqz`+delay-fill when flat but `beqzl`+target-hoist when nested in `if/else`. Compile tiny shape variants (switch vs if-chain vs goto, nested vs flat) with direct IDO (Step 4) and compare — find the matching shape in micro before editing the full draft.
- **Batched Variant Sweeps**: when 3+ structural variants are queued, sweep them with `.agents/skills/wr64-decomp/scripts/probe_sweep.sh` instead of hand-rolled build+diff loops. It captures the exact IDO command via `make -n -B <obj> NON_MATCHING=1` (refuses to run without `-DNON_MATCHING`), `touch`es and mtime-checks every variant, mirrors objects under `expected/`, and prints one `CURRENT (n)` line each:
  ```bash
  .agents/skills/wr64-decomp/scripts/probe_sweep.sh --obj build/src/<tu>.o --func <name> --base scratch/base_<name>.slice scratch/probe_A.c scratch/probe_B.c
  ```

### Delay-Slot Store Merging & Fill Selection (`bne` vs `bnel`)
- A store in a non-likely branch delay slot (`bne`/`beqz` + `sw`) executes on BOTH paths: model it as straight-line code before the `if`, not inside either branch.
- A redundant doubled store (`D = 1; if (f == 1) { D = 1; }`) merges to a single store in a normal (`bne`) branch delay slot, while the single-store form emits a likely (`bnel`) branch. Try the doubled store when the stub shows a normal branch with the store in its delay slot.
- Empty `else {}` arms can be load-bearing for the branch skeleton — never delete one without re-diffing.
- Anonymous `D++` keeps the incremented value in a t-reg (`t8`); a named `s32 temp = D + 1` local parks it in a v-reg instead. Drop the named local when the stub holds the temp in `t8`/`t9`.
- Equivalent tail spellings can emit identical bytes when the join coincides with function end (`if (t < K) goto end; ...` vs nested `if (t >= K) { ... }`); if the tail already matches, try the other spelling to shift upstream scheduling.
- Park at the floor when only scheduler-opaque rows remain (e.g. one adjacent fill-order swap after dozens of structural variants): keep the draft behind `#ifdef NON_MATCHING` with the floor score and load-bearing constructs noted in a comment.

### Unmigrated Rodata & Jump Tables
Functions containing jump tables (`switch`) whose tables reside in unmigrated `.rodata.s` files (e.g. `A5CC0.rodata.s`) must be kept under:
```c
#if defined(NEEDS_RODATA) || defined(NON_MATCHING)
```
Do not migrate individual jump tables to C until all functions referencing that specific `.rodata` block are ready to be matched, preventing linker collisions and section misalignments.
- **Diagnostic fingerprint**: a text-identical switch body still scores ~100 (`105`) from a single phantom row `> .rodata+0x0` (compiler's private table vs the blob's named `jtbl_`). Re-run with `-R` (`--no-show-rodata-refs`) to see through it; near-0 with `-R` means the C is correct.
- **Do not `--force` promote blob-table switches**: even after repointing blob entries to `func+offset` (links fine), the ROM mismatches because compiled code references the private table copy (`lui`/`lw` point at the `.o`'s own address, e.g. `0x800EB4C0` instead of the blob's `0x800EBAE4`). Proven 2026-09: `func_800ADC8C` text-identical yet unpromotable; parked under `NEEDS_RODATA || NON_MATCHING`.
- **Blob carve does not work either** (measured 2026-09-05): splitting `A5CC0.rodata.s` around the table and sandwiching `code_52CD0.o(.rodata)` between the halves in the link order still shifts everything after by **+12 bytes** (`jtbl_800EBB14` landed at `0x800EBB20`): 4 B gas tail-padding (split halves inherit section align-8 from the blob's `.double`s) + 8 B start-alignment padding (IDO emits `.rodata` with align-16, but the vacated slot at `0xA62E4` is only 4-aligned). There is no placement that puts 48 align-16 bytes at a 4-aligned address with zero padding — promotion needs whole-file rodata reconstruction, not a per-function carve. (Note: `linker_scripts/us/rev1/waverace64.ld` is git-ignored/generated; the yaml is the durable config.)

---

## Common Engine Architecture Patterns

### Scene Exit & Transition Functions
Across game and overlay segments (`ovl_i8`, `ovl_i9`, `ovl_i10`, `ovl_i13`), scene transitions share an identical structure:
```c
gPrevGameState = gGameState;
D_801CE630 = arg0;
gGameState = <target_state>;
D_801CE638 = <target_substate>;
D_801CE63C = 1;
D_801CE640 = 0;
D_801CE644 = 0;
D_800DAB1C = 0;
D_800D461C = 2; // or 3
FadeTransition_SetProps(1, 4, 0);
```

### Overlay Display List Rendering Pipeline
Course overlays typically route display lists through standard graphics stages:
```c
glistp = func_ovl_render(Draw_Water);
```
