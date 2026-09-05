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
| `python3 tools/m2ctx.py <file.c>` | Generates preprocessed C context (`ctx.c`) for decomp.me and m2c |
| `python3 tools/m2c/m2c.py --target mips-ido-c89 --context ctx.c <func.s>` | Converts raw assembly to an initial IDO C89 candidate function |

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
python3 tools/m2ctx.py src/<path>/<file>.c
```
Run automated m2c translation to produce starting C scaffolding:
```bash
python3 tools/m2c/m2c.py --target mips-ido-c89 --context ctx.c asm/us/rev1/nonmatchings/<path>/<func_name>.s > scratch/<func_name>.c
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
  - *Pointer Arithmetic vs. Array Indexing*: Explicit pointer increments (`ptr++`) generate distinct induction webs compared to indexed access (`arr[i]`), which triggers strength reduction and induction variable creation.
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

### Unmigrated Rodata & Jump Tables
Functions containing jump tables (`switch`) whose tables reside in unmigrated `.rodata.s` files (e.g. `A5CC0.rodata.s`) must be kept under:
```c
#if defined(NEEDS_RODATA) || defined(NON_MATCHING)
```
Do not migrate individual jump tables to C until all functions referencing that specific `.rodata` block are ready to be matched, preventing linker collisions and section misalignments.

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
