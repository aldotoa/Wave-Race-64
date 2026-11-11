# Wave Race 64 Decompilation Plan & Priority Matrix

An exhaustive, prioritized decompilation plan for all **164 remaining non-matching functions** (137 matched in prioritized matrix, 1,204 matched overall) in Wave Race 64 (US Rev 1).

---

## Executive Status & Metrics

| Metric | Current Status | Total Target | Percentage |
| :--- | :--- | :--- | :--- |
| **Matched Functions** | **1,204** | 1,368 | **88.01%** |
| **Non-Matching Functions** | **164** | 1,368 | **11.99%** |
| **Matched Code Bytes** | **453,136 B** | 834,028 B | **54.33%** |
| **Target Retail ROM** | `waverace64.us.rev1.z64` | SHA-1: `508dfc2d4caa42b6f6de5263d0aed5e44ac7966a` | Byte-for-byte exact (OK) |
| **Passing Regression Tests** | **445** | 445 | **100% OK** |

---

## Prioritization Tiers Overview

The 301 functions are categorized into 6 distinct tiers based on instruction count, control flow complexity, register allocator sensitivity, and `.rodata` / jump table dependencies:

| Tier | Classification | Remaining | Matched | Original | Est. Complexity | Matching Focus |
| :---: | :--- | :---: | :---: | :---: | :--- | :--- |
| **1** | Immediate Quick Wins | 0 | 11 | 11 | Low | High-velocity leaf & overlay routines |
| **2** | Small Refinements & Floor Solvers | 0 | 19 | 19 | Low-Medium | Allocator bisecting & float leaf math |
| **3** | Medium Integer & Overlay Logic | 0 | 31 | 31 | Medium | HUD, menus, and state dispatchers |
| **4** | Medium Floating-Point & Physics | 3 | 20 | 23 | Medium-High | Buoyancy, wave sampling, camera math |
| **5** | Rodata & Jump Table Blocked | 15 | 16 | 31 | High | Multi-case switches & rodata migration |
| **6** | Monolithic Routines & Core Engines | 146 | 40 | 186 | Very High | Physics solver, AI navigation, audio synthesis |
| **Total** | | **164** | **137** | **301** | | |

---


## Tier 1: Immediate Quick Wins (Small Integer Leaf & Overlay Routines)

These functions have the highest matching velocity: **fewer than 100 instructions**, no `.rodata` or jump table blockages, no floating-point math, and straightforward control flow. They typically consist of display list generators, status/state checkers, and simple memory/array manipulations.
* **Recommended approach**: Use the standard probe loop (`scratch/probe_<func>.c` + `tools/asm-differ/diff.py`). Most can match 100% within 1–3 probe sweeps.

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 1 | `func_i5_802C7594` | `src/overlays/ovl_i5/ovl_1C17E0.c` | 65 | 1/0  | Integer Clean  | **MATCHED** | Routine logic  |
| 2 | `func_i13_802C61E0` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 67 | 13/2  | Integer Clean  | **MATCHED** | Routine logic  |
| 3 | `func_801FAD68` | `src/codeseg/B97B0.c` | 80 | 18/0  | Integer Clean  | **MATCHED** | Routine logic  |
| 4 | `func_1B1FB0_802C71B8` | `src/unused_code_1B1FB0.c` | 83 | 2/0  | Integer Clean | **MATCHED** | Debug text character renderer: `gDPLoadTextureBlock` (IA8 16x16) + old-F3D `gSPTextureRectangle` on a `Gfx*` cursor (`Gfx*` param, not an `s32` copy, puts the glyph in `v0` and stores the first packet through `a0`; dead `arg2 = arg2; arg3 = arg3;` self-assignments place the texrect cursors; closed the old 390 floor) |
| 5 | `func_800998B0` | `src/game/code_52CD0.c` | 84 | 2/6  | Integer Clean  | **MATCHED** | Routine logic  |
| 6 | `func_i13_802C6F0C` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 85 | 12/8  | Integer Clean  | **MATCHED** | Routine logic  |
| 7 | `func_80096694` | `src/game/code_4F850.c` | 86 | 5/2  | Integer Clean  | **MATCHED** | Jet ski texture and rider livery palette decompression dispatcher |
| 8 | `func_i13_802C832C` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 86 | 7/5  | Integer Clean  | **MATCHED** | Course-select panel renderer & sliding window animation dispatcher |
| 9 | `func_i10_802C5800` | `src/overlays/ovl_i10/ovl_1C9150.c` | 90 | 18/0  | Integer Clean  | **MATCHED** | Options change-conditions slot selection and counter initialization  |
| 10 | `func_i8_802C5D3C` | `src/overlays/ovl_i8/ovl_1C49A0.c` | 95 | 6/6  | Integer Clean  | **MATCHED** | Stunt mode ramp and floating ring display list generator  |
| 11 | `func_80091DBC` | `src/game/code_43DA0.c` | 98 | 13/0  | Integer Clean  | **MATCHED** | 3D wake particle buffer cleanup  |

## Tier 2: Small Refinements & Floor Solvers (< 100 insns, Minimal Allocator Floors)

Small routines (< 100 instructions) that involve either floating-point registers (`$f0-$f31`) or have an existing draft parked at a low diff floor due to IDO register coloring quirks (e.g. `$a0` vs `$v0` home register).
* **Recommended approach**: Bisect register allocation in a minimal reproducer (`scratch/micro_*.c`) or test declaration ordering / explicit block scopes before promoting.

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 13 | `func_801DF668` | `src/codeseg/A95D0.c` | 55 | 8/0  | Floats  | **MATCHED** | Credits backdrop scattered float data copier  |
| 12 | `func_i0_802C6AE4` | `src/overlays/ovl_i0/ovl_1B3EC0.c` | 52 | 4/1  | Integer Clean | **MATCHED** | Training text glyph display list generator |
| 14 | `func_800AC098` | `src/game/code_57EB0.c` | 59 | 4/0  | Integer Clean  | **MATCHED** | Record lap flash alert queue append  |
| 15 | `func_i13_802C69CC` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 60 | 11/1  | Integer Clean  | **MATCHED** | Course boundary invisible collision plane  |
| 16 | `func_801DEB08` | `src/codeseg/A95D0.c` | 62 | 4/1  | Floats | **MATCHED** | 1-channel animation spline step evaluator |
| 17 | `func_i1_802C59E8` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 63 | 3/1  | Integer Clean  | **MATCHED** | Course warm-up banner table initialization  |
| 18 | `func_i13_802C6ABC` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 66 | 11/1  | Integer Clean  | **MATCHED** | Jet ski hull surface normal calculator  |
| 19 | `func_i13_802C6BC4` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 72 | 11/1  | Integer Clean  | **MATCHED** | Collision penetration depth solver  |
| 20 | `func_i13_802C64AC` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 74 | 12/2  | Integer Clean  | **MATCHED** | Submerged obstacle buoyancy resistance  |
| 21 | `func_i13_802C65D4` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 75 | 11/1  | Integer Clean  | **MATCHED** | Shallow reef hull scraping drag  |
| 22 | `func_801EC0D4` | `src/codeseg/B97B0.c` | 78 | 1/4  | Integer Clean  | **MATCHED** | Race results mode state initialization  |
| 23 | `func_801DEC00` | `src/codeseg/A95D0.c` | 81 | 5/1  | Floats  | **MATCHED** | 3-channel animation spline step evaluator  |
| 24 | `func_801E0304` | `src/codeseg/A95D0.c` | 84 | 0/3  | Floats  | **MATCHED** | Dynamic rotation & spline transform evaluator  |
| 25 | `func_801E0454` | `src/codeseg/A95D0.c` | 84 | 0/3  | Floats  | **MATCHED** | Dynamic rotation & spline transform evaluator  |
| 26 | `func_801EC3AC` | `src/codeseg/B97B0.c` | 85 | 0/3  | Integer Clean  | **MATCHED** | Options change-names state initialization  |
| 27 | `func_801E06F8` | `src/codeseg/A95D0.c` | 85 | 0/3  | Floats  | **MATCHED** | Dynamic rotation & spline transform evaluator  |
| 28 | `func_801E05A4` | `src/codeseg/A95D0.c` | 85 | 0/3  | Floats  | **MATCHED** | Dynamic rotation & spline transform evaluator  |
| 29 | `func_i13_802C6CE4` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 89 | 10/3  | Integer Clean  | **MATCHED** | Routine logic  |
| 30 | `func_i5_802C5A98` | `src/overlays/ovl_i5/ovl_1BFF50.c` | 97 | 12/1  | Integer Clean  | **MATCHED** | Port Blue collision & wave surface displacement calculation |

## Tier 3: Medium Integer & Overlay Logic (100 – 180 insns, No Rodata)

Mid-sized functions (100–180 instructions) covering menu logic, HUD element updates, game loop dispatchers, and camera helpers. They contain clean integer control flow without rodata blockages.
* **Recommended approach**: Map out the control flow graph, establish struct field offsets, and verify loop constructs (`do-while` vs `for`).

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 31 | `func_i1_802C63B4` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 103 | 19/9  | Integer Clean  | **MATCHED** | Course buoy waypoint sequence update  |
| 32 | `func_i5_802C5C1C` | `src/overlays/ovl_i5/ovl_1BFF50.c` | 105 | 15/12  | Integer Clean  | **MATCHED** | Port Blue harbor crane and dock surface display list  |
| 33 | `func_1B1FB0_802C67BC` | `src/unused_code_1B1FB0.c` | 109 | 1/0  | Integer Clean  | **MATCHED** | Debug texture strip renderer: 5 × (`gDPLoadTextureBlock` RGBA16 512x4 from `D_804A460` + old-F3D copy-mode `gSPTextureRectangle`). Load-bearing: `for (i = 0; i < 5; i++)` with `i * 2048` / `i * 4` scaling keeps the `i` counter as the loop test (an `i += 4` loop gets LFTR'd onto the texture pointer) |
| 34 | `func_1B1FB0_802C6E40` | `src/unused_code_1B1FB0.c` | 110 | 1/0  | Integer Clean  | **MATCHED** | Debug telemetry banner renderer: 4 × (`gDPLoadTextureTile` IA8 192x11 from `D_8008510` + old-F3D copy-mode `gSPTextureRectangle`). Load-bearing: `for (i = 0; i < 4; i++)` with `i * 0x840` / `i * 11` scaling (an `i += 11` loop gets LFTR'd onto the texture pointer) |
| 35 | `func_1B1FB0_802C6FF8` | `src/unused_code_1B1FB0.c` | 112 | 1/0  | Integer Clean  | **MATCHED** | Debug text banner renderer: 4 × (`gDPLoadTextureTile` IA8 496x5 from `D_800A618` + old-F3D copy-mode `gSPTextureRectangle` at y = 248 + `D_1B1FB0_802C76B0` * 20 + i * 5). Load-bearing: `for (i = 0; i < 4; i++)` with `i * 0x9B0` / `i * 5` scaling (`i += 5` or a pointer walk gets unrolled 2x) |
| 36 | `func_i13_802C62EC` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 112 | 17/5  | Integer Clean  | **MATCHED** | Save file search & validation menu input handler (chained `result = D_8D74 = call()` stores)  |
| 37 | `func_801DC0AC` | `src/codeseg/A95D0.c` | 114 | 10/5  | Integer Clean | **MATCHED** | Stunt-replay particle range dispatcher (index loop, `s32 i` declared first)  |
| 38 | `func_801E1E8C` | `src/codeseg/AF8C0.c` | 115 | 11/10  | Integer Clean  | **MATCHED** | Machine tuning interaction and controller input loop  |
| 39 | `func_80067C6C` | `src/game/code_C6C0.c` | 117 | 13/12  | Integer Clean  | **MATCHED** | Course intro cinematic camera path interpolation  |
| 40 | `func_i4_802C69C4` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 122 | 3/0  | Integer Clean  | **MATCHED** | Sunny Beach shoreline surf swell display list emitter  |
| 41 | `func_i1_802C6BD8` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 125 | 6/3  | Integer Clean  | **MATCHED** | Warm-up banner panel scroller (pointer re-assigned before the loop splits its live range s0→s4)  |
| 42 | `func_i15_802C5CE8` | `src/overlays/ovl_i15/ovl_1CFB60.c` | 127 | 19/0  | Integer Clean  | **MATCHED** | Course-setup effect slot reset and rider slot scan (indexed struct-copy loop, inline lap-state reads)  |
| 43 | `func_i1_802C6DCC` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 133 | 15/7  | Integer Clean  | **MATCHED** | Race-finish state setup and record flag latch (4-iteration loop fully unrolled by IDO into absolute-address loads/stores)  |
| 44 | `func_i3_802C5B40` | `src/overlays/ovl_i3/ovl_1BC890.c` | 133 | 22/11  | Integer Clean  | **MATCHED** | Course-overview frame: race scene, demo panel dispatch, skip/advance input  |
| 45 | `func_1B1FB0_802C6C1C` | `src/unused_code_1B1FB0.c` | 137 | 11/0  | Integer Clean  | **MATCHED** | Debug flight HUD digit renderer: `D_801CB410` as 1-3 IA8 16x18 digits (`gDPLoadTextureBlock` + `gSPTextureRectangle`), right to left from x=544 in 18 px steps. Load-bearing: the `dp = &D_1B1FB0_802C767C[digit]` pointer temp (direct `[digit]` indexing swaps the remainder's `a3` with the E7 packet's `t3`) and `val`/`count` declared first (else frame 0x40, not 0x38) |
| 46 | `func_i11_802C5D48` | `src/overlays/ovl_i11/ovl_1CA480.c` | 141 | 21/11  | Integer Clean  | **MATCHED** | Warmup options menu controller input handler |
| 47 | `func_801E2058` | `src/codeseg/AF8C0.c` | 145 | 18/2  | Integer Clean  | **MATCHED** | Machine tuning slider track renderer (four empty `if (x) {}` raise i/isWrap/cond priority so the loop bound 16 stays in `$at`)  |
| 48 | `func_i4_802C6778` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 147 | 2/0  | Integer Clean  | **MATCHED** | Sunny Beach backdrop and scenery display list (ovl_i3 template; always-true `if (t2 != 0)` blocks are load-bearing)  |
| 49 | `func_1B1FB0_802C5BA4` | `src/unused_code_1B1FB0.c` | 148 | 10/10  | Integer Clean  | **MATCHED** | Boot/fade-in display list builder: base DLs + scissor, strip renderers, prim color, telemetry banners, then the `D_1B1FB0_802C76F0 = D_1B1FB0_802C76F4 * 255 / 10` fade clamped to 255 (`osViBlack` at full, `func_801EB180` after 14 frames). Load-bearing: `D_1B1FB0_802C76F0` declared `u32` with a plain `> 255` clamp — as `s32`, uopt shares one register for every 255, so the multiply emits `multu` instead of the retail `sll`/`subu` (`(v1 << 8) - v1` gives the right shape but is one t-reg off) |
| 50 | `func_801E9B04` | `src/codeseg/B66E0.c` | 154 | 41/0  | Integer Clean  | **MATCHED** | Proportional-font glyph mapper, (mode, char) -> glyph index (single `return glyph;` with every arm assigning `glyph`: IDO copies the return block into each arm, while per-arm C returns give a `move; jr; nop` tail reached by `bnel` likely-fills; closed the old parked floor)  |
| 51 | `func_80068538` | `src/game/code_C6C0.c` | 155 | 13/0  | Integer Clean  | **MATCHED** | Rider-type-2 jet ski five-part matrix + display list emitter (loop-head `if (i) {}` swaps the hoisted G_DL/G_MTX command words t3/t2)  |
| 52 | `func_i7_802C5A18` | `src/overlays/ovl_i7/ovl_1C43F0.c` | 159 | 3/6  | Integer Clean  | **MATCHED** | Options menu frame and label renderer (completes ovl_1C43F0)  |
| 53 | `func_i4_802C58F8` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 160 | 29/0  | Integer Clean  | **MATCHED** | Course/difficulty select unlock table setup (Expert row must be `D_800EAC14[i - 1][j]`, not `[2][j]`)  |
| 54 | `func_i4_802C70C0` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 161 | 19/6  | Integer Clean  | **MATCHED** | Difficulty select menu input handler (skip loops must be `for (;;) { if (tbl) break; ... }` so IDO does not rotate them)  |
| 55 | `func_801E229C` | `src/codeseg/AF8C0.c` | 165 | 10/6  | Integer Clean  | **MATCHED** | Name-entry option labels and initials renderer (`s8` char tables and buffer give `lb`; no spare locals, or the 0x88 frame grows)  |
| 56 | `func_i4_802C6C2C` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 169 | 21/8  | Integer Clean  | **MATCHED** | Course select menu input handler (chained `D_802C76CC = D_i4_802C754C = i` store shifts the t-reg queue)  |
| 57 | `func_1B1FB0_802C6970` | `src/unused_code_1B1FB0.c` | 171 | 1/0  | Integer Clean  | **MATCHED** | Debug image strip renderer: 8 × (`gDPLoadTextureTile` IA8 360x8 from `D_1B1FB0_802C7664[D_1B1FB0_802C7660]` + old-F3D copy-mode `gSPTextureRectangle` at x 140..500, y = 59 + i * 8); IDO unrolls the loop 2x. Load-bearing: the texture pointer is initialised in the `for` header (`for (i = 0, tex = ...; i < 8; i++)` with `tex += 0xB40`) — initialising it before the loop schedules its `lw` 8 slots early in the prologue, and `&tex[i * 0xB40]` indexing loses the pointer IV |
| 58 | `func_801ECB98` | `src/codeseg/B97B0.c` | 174 | 1/5  | Integer Clean  | **MATCHED** | Award ceremony state init (`GAME_STATE_CEREMONY`, Glacier Coast podium grid; matched first draft, 4-rider loop is unrolled by IDO)  |
| 59 | `func_8007B930` | `src/game/core/wr64_save.c` | 174 | 11/7  | Integer Clean  | **MATCHED** | Packs in-RAM record tables into the EEPROM image (a named `n = i + 1` per loop keeps IDO's dead s5 induction register and turns the initials loop's `i++` into `i = n`)  |
| 60 | `func_801EBD28` | `src/codeseg/B97B0.c` | 175 | 12/7  | Integer Clean  | **MATCHED** | 2-player versus state init (GAME_STATE 10; chained `D_800DA9C8[0] = D_800DA9C8[1] = 0` store shifts the t-reg queue, switch case bodies ordered 4/0/11/1)  |
| 61 | `func_801F03E0` | `src/codeseg/B97B0.c` | 176 | 31/2  | Integer Clean  | **MATCHED** | Race start countdown driver (read `D_80228A90` directly, no local: IDO's spilled CSE temp coalesces with the `abs()` result; `D_80228B58[i] = 1` sits outside the `d < 5` block)  |

## Tier 4: Medium Floating-Point & Physics Routines (100 – 180 insns, Float Math)

Mid-sized functions (100–180 instructions) performing single-precision floating point calculations: buoyant hull forces, wave displacement, coordinate transformation, and Catmull-Rom splines.
* **Recommended approach**: Always use `f` suffixes on float constants (`1.0f`). If intermediate registers mismatch, decompose chained expressions into named locals.

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 62 | `func_801DC404` | `src/codeseg/A95D0.c` | 105 | 9/3  | Floats  | **MATCHED** | 3D particle fireworks and water splash simulator  |
| 63 | `func_801E0FF0` | `src/codeseg/A95D0.c` | 113 | 0/4  | Floats  | **MATCHED** | Look-at camera orientation vector orthogonalizer and normalizer  |
| 64 | `func_801EE4D0` | `src/codeseg/B97B0.c` | 114 | 0/0  | Floats  | **MATCHED** | Routine logic  |
| 65 | `func_8009934C` | `src/game/code_52CD0.c` | 114 | 1/0  | Floats  | **MATCHED** | Uniform cubic B-spline basis evaluator (4 control points → Vec3f + scalar). Load-bearing: `2/3` and `1/6` are the literals `0.6666667f` / `0.16666667f` (rodata migrated into the TU); `/ 2.0f` folds to the `0.5f` immediates  |
| 66 | `func_801DD85C` | `src/codeseg/A95D0.c` | 114 | 1/3  | Floats  | **MATCHED** | Routine logic  |
| 67 | `func_801EADB0` | `src/codeseg/B66E0.c` | 114 | 14/0  | Floats  | **MATCHED** | Formatted lap timer display printer (mm:ss.ms)  |
| 68 | `func_801EE6F4` | `src/codeseg/B97B0.c` | 115 | 0/0  | Floats  | **MATCHED** | Routine logic  |
| 69 | `func_801E084C` | `src/codeseg/A95D0.c` | 115 | 0/4  | Floats  | **MATCHED** | Replay slow motion speed indicator / object trajectory evaluator  |
| 70 | `func_801E0A18` | `src/codeseg/A95D0.c` | 116 | 0/4  | Floats  | **MATCHED** | Post-race results total time rank calculator / 3-triplet spline evaluator  |
| 71 | `func_801E0BE8` | `src/codeseg/A95D0.c` | 116 | 0/4  | Floats  | **MATCHED** | Stage clear victory jingle sequencer / 3-triplet with single scale evaluator  |
| 72 | `func_801E0DB8` | `src/codeseg/A95D0.c` | 117 | 0/4  | Floats  | **MATCHED** | Championship cup award presentation animation / 4-triplet with single scale evaluator  |
| 73 | `func_801EE040` | `src/codeseg/B97B0.c` | 122 | 1/1  | Floats, ParkedFloor  | Pending (Floor 68) | Axis-angle rotation MtxF (sin-table guRotateF with inlined normalize); draft parked behind NON_MATCHING (`one` var + empty if after [0][0] give the $f12 1.0f; FPR choice for xx/yy/zz/c left)  |
| 74 | `func_801DF38C` | `src/codeseg/A95D0.c` | 123 | 6/1  | Floats  | **MATCHED** | Look-at orbit camera update: eases distance/yaw/pitch, builds the offset vector from gSinTable, then writes eye/target by type (2 or 3) and calls func_801DEEC4. Load-bearing: typed sub-struct pointers `a = (A*)(arg0 + 4)`, `b = (B*)(arg0 + 0x5C)` (house style, see func_801DF128) so retail reloads the source after each store; f32 `yaw`/`pitch` inside inline `COS((s32)((yaw * 4096.0f) / 360.0f))`; `i` declared after `vec`  |
| 75 | `func_80061708` | `src/game/code_C6C0.c` | 123 | 11/5  | Floats  | **MATCHED** | Rider controller latch (`OSContPad` copy into `unkB50`, zeroed by a chained `stick_x = stick_y = button = 0` store) and analog stick rescale through `func_80061644` (`scale, x, y, mag` declaration order lays out the 0x30 frame's spill slots)  |
| 76 | `func_i4_802C6ED0` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 124 | 4/0  | Floats  | **MATCHED** | Course preview panel open/close zoom animation (both arms compute the `(5 - n) / 5.0f` term first)  |
| 77 | `func_801EE274` | `src/codeseg/B97B0.c` | 126 | 1/1  | Floats, ParkedFloor  | Pending (Floor 32) | Axis-angle rotation + translation MtxF (sibling of func_801EE040); draft parked behind NON_MATCHING (insn count and frame exact; only xx/zz FPR choice left, retail acts as if a hidden range holds $f2)  |
| 78 | `func_80088EA8` | `src/game/code_43A60.c` | 131 | 17/2  | Floats  | **MATCHED** | Rider grid slot shuffle  |
| 79 | `func_80049C9C` | `src/sys/sys_utils.c` | 135 | 0/1  | Floats, ParkedFloor  | Pending (Floor 36) | Euler angles (degrees) * scale + translation to Mtx via local MtxF; draft parked behind NON_MATCHING (sin(y) before cos(x) aligns all t-regs; left: retail gives $f2 to cx/cycz and keeps sysz in memory)  |
| 80 | `func_8007FD80` | `src/game/code_3A580.c` | 138 | 3/1  | Floats  | **MATCHED** | Spray emitter seeding and quad texcoord init  |
| 81 | `func_801E6074` | `src/codeseg/B3AA0.c` | 141 | 11/4  | Floats  | **MATCHED** | Menu banner slide-in (state 0, func_80048A88 with eased offsets) / hold (state 1, SysUtils_MatrixLookAt, then closes after 11 frames by game mode). Load-bearing: `1 - scale` spelled differently from the `1.0f` call args (breaks IDO constant CSE); param retyped to `UnkStruct_menu_buffer_1*`  |
| 82 | `func_801F23A0` | `src/codeseg/B97B0.c` | 144 | 20/1  | Floats  | **MATCHED** | Per-rider lean target: maps the unkB98 position into 0-180 (with Math_Rand jitter) in unk2CC, then steps unk2C8 toward it. Load-bearing: `ABS()` / `SIGNUM()` from macros.h over the inline `unk2CC - unk2C8` (no named diff), one float var reused for the delta and t; new RiderStruct unk2C8/unk2CC and UnkStruct_80192690 unkB98/BBC/BC0 fields  |
| 83 | `func_801E8800` | `src/codeseg/B66E0.c` | 161 | 16/0  | Floats  | **MATCHED** | Textured quad emitter: fills 4 Vtx (scaled extent, texcoords, per-corner color) in the D_801CE5F8 pool at D_80228A40, then gSPVertex + 2 gSP1Triangle. Load-bearing: byte-offset loop `i += 16`, `u32 j = i` copy used in only some of the compares (found by decomp-permuter), `tc[1] = (h * 2) << 5`  |
| 84 | `func_i13_802C6700` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 179 | 15/1  | Floats  | **MATCHED** | Save menu panel controller: fade-in (state 0) / confirm-back-toggle input (state 1, returns 1-4) / fade-out (state 2), deriving four layout values from `n / 5.0f`. Load-bearing: in the fade-out case `(5 - n) / 5.0f` must be computed before `n / 5.0f` (the reverse swaps `$f4`/`$f16`)  |

## Tier 5: Rodata & Jump Table Blocked Routines (< 180 insns, Switch/Rodata Blocked)

Functions containing `switch` statements with compiler-generated jump tables (`jtbl_*`) or `.late_rodata` float pools. Because jump tables are emitted into `.rodata`, they cannot be promoted in isolation without risking rodata displacement until the enclosing translation unit or data slice is fully migrated.
* **Recommended approach**: Keep drafts behind `#ifdef NON_MATCHING`. Decompile all siblings in the same file first, then migrate the rodata section all at once.

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 85 | `func_800ADC8C` | `src/game/code_57EB0.c` | 34 | 1/0  | JumpTable  | **MATCHED** | Split-screen HUD layout offset lookup; `ret += 1` (not `ret++`) in cases 2/4. Unblocked by migrating code_52CD0 .rodata out of the shared A5CC0.rodata.s |
| 86 | `func_i13_802C81AC` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 62 | 8/1  | JumpTable, Rodata  | **MATCHED** | Options sub-menu cursor reset and selection to sub-state mapper |
| 87 | `func_i6_802C6B34` | `src/overlays/ovl_i6/ovl_1C2250.c` | 79 | 10/2  | JumpTable, Rodata  | **MATCHED** | Twilight City intro banner slide state machine; old-style `()` definition, so arg0 is never homed |
| 88 | `func_80096048` | `src/game/code_4F850.c` | 92 | 7/6  | JumpTable, Rodata  | **MATCHED** | Course asset pointer table loader: relocates each list entry, stores the count, then dispatches on the course kind to the five fixup siblings. Both tables are indexed by the counter (`list[count]`, `dst[count + 2]`) in a `while (1) { if (entry == 0) break; ... }` loop; IDO strength-reduces that into the retail byte-index and cursor registers (hand-written cursor/index variables left a 6-row floor); a leading `s32 pad` keeps the kind at 0x40(sp)  |
| 89 | `func_801EB00C` | `src/codeseg/B66E0.c` | 93 | 18/2  | Rodata  | Pending | Fast3D font texture tile loader  |
| 90 | `func_i13_802C6068` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 94 | 20/16  | JumpTable, Rodata  | **MATCHED** | Options menu state dispatcher plus per-state sound cue if-chain; leading `s32 pad` puts the result at sp+0x18 |
| 91 | `func_801DC274` | `src/codeseg/A95D0.c` | 100 | 4/2  | Floats, Rodata  | Pending | 3D particle fireworks and water splash simulator; Draft: probe score 38 (2026-11-09) |
| 92 | `func_800683A0` | `src/game/code_C6C0.c` | 102 | 8/1  | Floats, Rodata  | **MATCHED** | Rider projected-position entry fill (queued via `func_800AC098`) and `unk16EC` counter step (no `entry`/`t` locals: each costs a stack word past the 0x20 frame; projected position written before the velocity copy; `.late_rodata` 0.1f links in place)  |
| 93 | `func_801DD6B4` | `src/codeseg/A95D0.c` | 106 | 24/2  | JumpTable, Rodata  | **MATCHED** | Course/difficulty intro-camera dispatcher; named `s32* ptr = &D_802287AC; *ptr = D_801C2C70; if (*ptr < 3)` keeps the address in v0 |
| 94 | `func_800C1BD8` | `src/audio/audio_general.c` | 116 | 18/6  | Floats, Rodata  | **MATCHED** | Dynamic music volume and menu-state modulator; case 3 falls through into a shared `case 0: default:` block holding a redundant `var_a1 = 0x40`, which leaves the case-0 `beqz` and default `b` delay slots as nops (the old probe score ignored branch targets and hid this)  |
| 95 | `func_i5_802C781C` | `src/overlays/ovl_i5/ovl_1C17E0.c` | 118 | 15/2  | JumpTable, Rodata  | **MATCHED** | Results-panel slide state machine: slides the panel in, steps the buoy path index, waits for A/B/Start, then slides out and hands off to func_801EC9C8 or func_801EC830  |
| 96 | `func_8004F1EC` | `src/game/water_69D0.c` | 122 | 13/0  | Floats, Rodata  | Pending | Routine logic  |
| 97 | `func_800498A4` | `src/sys/sys_utils.c` | 124 | 0/1  | Floats, Rodata, ParkedFloor  | Pending (Floor 44) | Euler angles (radians) to rotation MtxF/Mtx; draft parked behind NON_MATCHING (mixed 0.5f spellings, sz load routed through sysz; FPR choice for 4096/2pi left); Draft: probe score 35 (2026-11-09) |
| 98 | `func_801E66F4` | `src/codeseg/B3AA0.c` | 126 | 8/2  | Floats, Rodata  | **MATCHED** | Pause-menu cursor spin matrix; three MtxF locals give the 0x100 frame, `D_802C6BD0 + 6 + (D_802C6EE4 * 0x14)` sets the load order, one `0` and one `0.0f` argument stop the zero constants sharing a register |
| 99 | `func_80049A94` | `src/sys/sys_utils.c` | 130 | 0/1  | Floats, Rodata, ParkedFloor  | Pending (Floor 64) | Euler angles (radians) + translation to MtxF/Mtx; draft parked behind NON_MATCHING (insn count exact; target has 3 distinct 2pi pool entries)  |
| 100 | `func_8009D96C` | `src/game/code_57EB0.c` | 137 | 4/5  | Floats, JumpTable  | Pending | Buoy miss warning flash animator  |
| 101 | `func_8004EFB4` | `src/game/water_69D0.c` | 142 | 32/0  | Floats, Rodata  | Pending | Routine logic; Draft: probe score 97 (2026-11-09) |
| 102 | `func_i5_802C5850` | `src/overlays/ovl_i5/ovl_1BFF50.c` | 146 | 3/6  | Floats, Rodata, ParkedFloor  | **MATCHED** | Port Blue banner matrices and viewports (mirrors B17D0 func_801E3250); y arg passed as a literal `0` gives `li a3,0` |
| 103 | `func_i14_802C5924` | `src/overlays/ovl_i14/ovl_1CF180.c` | 147 | 27/15  | JumpTable, Rodata  | **MATCHED** | Results menu frame/draw and post-race state dispatcher  |
| 104 | `func_8004F790` | `src/game/water_69D0.c` | 148 | 10/6  | Floats, Rodata  | Pending | Routine logic  |
| 105 | `func_8004F520` | `src/game/water_69D0.c` | 156 | 34/0  | Floats, Rodata  | Pending | Routine logic; Draft: probe score 97 (2026-11-09) |
| 106 | `func_800ADF90` | `src/game/code_57EB0.c` | 158 | 22/16  | JumpTable  | **MATCHED** | HUD marker display-list emitter with 13-case jump table; unblocked by the code_52CD0 .rodata migration |
| 107 | `func_i8_802C6ADC` | `src/overlays/ovl_i8/ovl_1C49A0.c` | 159 | 21/9  | JumpTable, Rodata  | Pending | Stunt mode ramp and floating ring display list generator; Draft: probe score 62 (2026-11-09) |
| 108 | `func_800534AC` | `src/game/code_C6C0.c` | 168 | 4/3  | Floats, Rodata  | Pending | Routine logic  |
| 109 | `func_80053C08` | `src/game/code_C6C0.c` | 169 | 16/0  | JumpTable, Rodata  | Pending | Water surface wave height compensation for camera elevation  |
| 110 | `func_801E9858` | `src/codeseg/B66E0.c` | 171 | 17/2  | Floats, JumpTable, Rodata  | Pending | Main string glyph display list generator  |
| 111 | `func_80050F8C` | `src/game/water_69D0.c` | 171 | 20/3  | Floats, Rodata  | Pending | Routine logic  |
| 112 | `func_8009D6B0` | `src/game/code_57EB0.c` | 175 | 13/0  | JumpTable  | **MATCHED** | HUD buoy model vertex-table entry lookup (two 12/10-case jump tables); the function has no trailing return, so unhandled selectors leave v0 as the copy of arg0. First function of the new TU `code_57EB0.c`, split from code_52CD0.c at the original file boundary (the 4-byte .rodata pad at 0x800EB54C is now natural section alignment)  |
| 113 | `func_i5_802C6CC4` | `src/overlays/ovl_i5/ovl_1BFF50.c` | 176 | 25/6  | JumpTable, Rodata  | **MATCHED** | Port Blue results banner slide/input state machine |
| 114 | `func_801DE3CC` | `src/codeseg/A95D0.c` | 177 | 25/4  | Floats, Rodata  | Pending | Routine logic  |
| 115 | `func_i1_802C8E70` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 179 | 26/6  | JumpTable, Rodata  | **MATCHED** | Primary course rider rank tracker; case 5 is a 4-trip loop over D_i1_802C9534..9540 (`i == var_v0` operand order) |

## Tier 6: Large Monolithic Routines & Core Engines (>= 180 insns)

Large, monolithic subroutines (180+ instructions, up to 1,500+ instructions) comprising the deepest systems of Wave Race 64: the full 3D wave simulation engine, buoyant hull hydrodynamics, audio voice synthesis, and AI rival pathfinding.
* **Recommended approach**: Tackle incrementally after the smaller supporting routines and shared data structures in their translation units are matched.

| # | Function | Source File | Insns | Br/Jal | Flags / Attributes | Status | Description / Purpose |
| :---: | :--- | :--- | :---: | :---: | :--- | :---: | :--- |
| 116 | `func_80069798` | `src/game/code_C6C0.c` | 181 | 4/5  | Floats, ParkedFloor  | Pending (Floor 9) | Orbit camera: spherical eye from distance/yaw/pitch, yaw wrap to [0,360), look-at * uniform scale MtxF, then perspective; draft parked behind NON_MATCHING (frame 0x120 and insn sequence exact; `Vec3f*` arg5 keeps mul operand order; `if (dist) {}` and a permuter-found `if (1) {}` block fix dist/4096 and adj; only the yaw temp vs <0 adjust f0/f2 swap left)  |
| 117 | `func_8004C998` | `src/game/water_69D0.c` | 185 | 6/2  | Floats  | Pending | Routine logic  |
| 118 | `func_8008E4B0` | `src/game/code_43DA0.c` | 185 | 6/0  | Floats  | Pending | AI difficulty rubberbanding speed multiplier  |
| 119 | `func_801E1BA8` | `src/codeseg/AF8C0.c` | 185 | 26/0  | Floats, Rodata  | Pending | Machine tuning interaction and controller input loop  |
| 120 | `func_i3_802C5800` | `src/overlays/ovl_i3/ovl_1BC890.c` | 186 | 22/4  | Integer Clean  | **MATCHED** | Course-overview entry: score-table reset, demo branch, rank thresholds  |
| 121 | `func_i14_802C5B70` | `src/overlays/ovl_i14/ovl_1CF180.c` | 187 | 15/5  | Integer Clean  | **MATCHED** | Results menu option list renderer (completes ovl_1CF180)  |
| 122 | `func_80051238` | `src/game/water_69D0.c` | 188 | 14/9  | Floats, Rodata  | **MATCHED** | Per-frame water update and Glacier Coast tide drain; its four function statics carry ROM initial values and live in water_69D0's own .data (yaml split at 0x8EFC0, 8EE40.data.s truncated, `s32 D_800D47C0 = 0` defined in the TU) |
| 123 | `func_800890B4` | `src/game/code_43A60.c` | 189 | 18/5  | Floats  | **MATCHED** | Rider and player state init (completes code_43A60)  |
| 124 | `func_8004D018` | `src/game/water_69D0.c` | 189 | 40/0  | Floats, Rodata  | Pending | Routine logic  |
| 125 | `func_8007B630` | `src/game/core/wr64_save.c` | 192 | 12/6  | Integer Clean  | **MATCHED** | Unpacks the EEPROM image into the in-RAM record tables, inverse of `func_8007B930` (dead `n = i + 1` per loop keeps the s4 counter; signed `s8` struct fields give `lb`; the 4-entry copy is a pointer walk so IDO keeps it rolled; `pad[3]` sizes the 0x88 frame)  |
| 126 | `func_80077F5C` | `src/game/code_2FB10.c` | 194 | 27/0  | Floats, Rodata  | Pending | Jet ski throttle response and water drag velocity damping; Draft: probe score 128 (2026-11-09) |
| 127 | `func_i1_802C5AE4` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 196 | 30/20  | JumpTable, Rodata, ParkedFloor  | Pending | Course buoy waypoint sequence update  |
| 128 | `func_8004D30C` | `src/game/water_69D0.c` | 199 | 37/1  | Floats, Rodata  | Pending | Routine logic  |
| 129 | `func_80073E6C` | `src/game/code_2C670.c` | 206 | 20/0  | Floats, Rodata  | Pending | Jet ski hull displacement and water elevation offset calculator  |
| 130 | `func_801EA730` | `src/codeseg/B66E0.c` | 207 | 24/0  | Floats  | **MATCHED** | Fade colour ramp setter (variant of 801E9D6C) |
| 131 | `func_801EA0B0` | `src/codeseg/B66E0.c` | 207 | 24/0  | Floats  | **MATCHED** | Fade colour ramp setter (variant of 801E9D6C; different channel per case) |
| 132 | `func_801F2060` | `src/codeseg/B97B0.c` | 208 | 16/4  | Integer Clean  | Pending | Routine logic; Draft: probe score 51 (2026-11-09) |
| 133 | `func_8007D2D4` | `src/game/core/wr64_save.c` | 208 | 26/16  | JumpTable, Rodata  | Pending | Controller Pak ghost data file verify, header check, and payload reader; Draft: probe score 89 (2026-11-09) |
| 134 | `func_801EAA6C` | `src/codeseg/B66E0.c` | 209 | 24/0  | Floats  | **MATCHED** | Fade colour ramp setter (variant of 801E9D6C; 128.0f scale in cases 0/3) |
| 135 | `func_801EA3EC` | `src/codeseg/B66E0.c` | 209 | 24/0  | Floats  | **MATCHED** | Fade colour ramp setter (variant of 801E9D6C; 0xFF base channels) |
| 136 | `func_801E9D6C` | `src/codeseg/B66E0.c` | 209 | 24/0  | Floats  | **MATCHED** | Fade colour ramp setter: switch on D_80228A78.unk2, `(s16) (u32) ((f32) x * 255.0f / (f32) unk8)` per channel, `break` not `return` |
| 137 | `func_801E7908` | `src/codeseg/wr64_fade.c` | 212 | 14/4  | JumpTable, Rodata  | **MATCHED** | Fade overlay fill and wipe display list (completes wr64_fade)  |
| 138 | `func_801F1CFC` | `src/codeseg/B97B0.c` | 217 | 47/4  | Floats  | Pending | Routine logic  |
| 139 | `func_i0_802C6044` | `src/overlays/ovl_i0/ovl_1B3EC0.c` | 218 | 9/7  | Integer Clean  | Pending | Routine logic  |
| 140 | `func_1C3D00_802C58DC` | `src/seg_1C3D00.c` | 220 | 3/16  | Rodata  | **MATCHED** | 1P/2P menu frame, header and label renderer (completes seg_1C3D00)  |
| 141 | `func_801EB180` | `src/codeseg/B97B0.c` | 221 | 9/6  | Integer Clean  | **MATCHED** | Routine logic  |
| 142 | `func_i6_802C5800` | `src/overlays/ovl_i6/ovl_1C2250.c` | 221 | 10/8  | Floats, Rodata  | Pending | Twilight City neon lighting and city canal display list renderer  |
| 143 | `func_8006390C` | `src/game/code_C6C0.c` | 223 | 11/5  | Floats  | Pending | Camera roll leveling filter relative to horizon; Draft: probe score 92 (2026-11-09) |
| 144 | `func_801E4C60` | `src/codeseg/B3290.c` | 226 | 1/2  | Floats, Rodata  | **MATCHED** | Fixed-point align matrix from fwd/up s8 vectors + translation; recomputed `s` sets the mask regalloc  |
| 145 | `func_801DDAB8` | `src/codeseg/A95D0.c` | 228 | 27/8  | Floats, JumpTable, Rodata  | Pending | Routine logic  |
| 146 | `func_8004CC7C` | `src/game/water_69D0.c` | 231 | 41/0  | Floats, Rodata  | Pending | Routine logic  |
| 147 | `func_1B1FB0_802C5800` | `src/unused_code_1B1FB0.c` | 233 | 39/0  | Floats, Rodata  | Pending | Flight mode debug camera controller  |
| 148 | `func_801EE9C0` | `src/codeseg/B97B0.c` | 236 | 4/0  | Floats  | Pending | Routine logic  |
| 149 | `func_i1_802C6FE0` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 237 | 37/13  | Integer Clean  | **MATCHED** | Results screen state init; per-player flags are the unrolled 4-trip `D_801CE708[i] >= D_801C293C[i].lapCount` loop from the matched sibling; else-if chain for the D_801CE6F0 music cue |
| 150 | `func_8004A8B0` | `src/sys/sys_utils.c` | 242 | 46/0  | Integer Clean  | **MATCHED** | Framebuffer emboss filter (RGBA5551 relief table + per-column luminance diff). IDO hands out caller-saved registers in order of first definition: a local `u32 tbl = (u32) D_80158350` assigned before `col`/`end` gives the inner table base a0 (the cast inside the loop left it in t2). `Seed` and the function-local static `D_800D4644` now form sys_utils' own .data (asm data file renamed 8EE40 -> 8EE50)  |
| 151 | `func_8007C604` | `src/game/core/wr64_save.c` | 244 | 16/11  | Integer Clean  | Pending | Stunt high score rank slot compaction and displacement updater; Draft: probe score 216 (2026-11-09) |
| 152 | `func_801DD2D0` | `src/codeseg/A95D0.c` | 249 | 21/5  | Floats, Rodata  | Pending | Routine logic  |
| 153 | `func_801FBFB4` | `src/codeseg/C94E0.c` | 250 | 12/0  | Floats  | Pending | Routine logic  |
| 154 | `func_80067810` | `src/game/code_C6C0.c` | 251 | 1/0  | Integer Clean  | **MATCHED** | Rider model display-list chain: 22 gSPMatrix/gSPDisplayList pairs, no locals (any local changes the 120-byte frame) |
| 155 | `func_801E946C` | `src/codeseg/B66E0.c` | 251 | 12/6  | JumpTable, Rodata  | Pending | Routine logic  |
| 156 | `func_i5_802C7090` | `src/overlays/ovl_i5/ovl_1C17E0.c` | 253 | 18/6  | Floats, Rodata  | **MATCHED** | Buoy path loader and placer: loads the two 8-path buoy sets once per race, places the 8 active buoys at the current path step, and calls func_8004EFB4 the first time each one surfaces  |
| 157 | `func_801DE690` | `src/codeseg/A95D0.c` | 257 | 10/0  | Floats, Rodata  | Pending | Routine logic  |
| 158 | `func_801EFFD8` | `src/codeseg/B97B0.c` | 258 | 17/1  | Floats  | Pending | Routine logic  |
| 159 | `func_801EB91C` | `src/codeseg/B97B0.c` | 259 | 20/7  | Integer Clean  | Pending | Stunt Mode state initialization; Draft: probe score 172 (2026-11-09) |
| 160 | `func_80050B78` | `src/game/water_69D0.c` | 261 | 8/1  | Floats, Rodata  | Pending | Routine logic  |
| 161 | `func_8007F030` | `src/game/code_383C0.c` | 262 | 20/0  | Floats  | Pending | Rider kinematic state and skeletal position evaluator; Draft: probe score 175 (2026-11-09) |
| 162 | `func_801EB4F4` | `src/codeseg/B97B0.c` | 266 | 10/9  | Integer Clean  | Pending | Routine logic  |
| 163 | `func_800624CC` | `src/game/code_C6C0.c` | 275 | 2/4  | Floats  | Pending | Dynamic field-of-view adjustment based on speed boost  |
| 164 | `func_8007FFA8` | `src/game/code_3A580.c` | 275 | 4/8  | Floats, Rodata  | **MATCHED** | Port Blue spray quad display list builder (completes code_3A580)  |
| 165 | `func_801E62A8` | `src/codeseg/B3AA0.c` | 275 | 30/2  | Floats  | **MATCHED** | Menu panel slide-in matrix (sibling of 801E6074); `MtxF mtx; f32 scale;` decl order and typed parameter place mtx at sp+0x50 |
| 166 | `func_80061FEC` | `src/game/code_C6C0.c` | 276 | 13/3  | Floats, Rodata  | Pending | Camera look-at matrix builder for single player  |
| 167 | `func_80085510` | `src/game/code_3AC00.c` | 277 | 27/7  | Floats, Rodata  | **MATCHED** | Rider steering vector calculation and limit check (completes code_3AC00) |
| 168 | `func_801E4FE8` | `src/codeseg/B3290.c` | 287 | 3/3  | Floats  | **MATCHED** | Three-node model DL emitter (push matrix, DL, pop); `D_80228920_2` alias stops address CSE. Completes B3290  |
| 169 | `func_8004E614` | `src/game/water_69D0.c` | 292 | 39/5  | Floats  | Pending | Routine logic  |
| 170 | `func_8004E0A4` | `src/game/water_69D0.c` | 297 | 42/2  | Floats, Rodata  | Pending | Routine logic  |
| 171 | `func_800629A8` | `src/game/code_C6C0.c` | 298 | 9/1  | Floats, Rodata  | Pending | Submerged camera water ripple distortion filter  |
| 172 | `func_80061184` | `src/game/code_C6C0.c` | 304 | 74/1  | Floats, Rodata  | Pending | Reverse-view (rear mirror) camera orientation  |
| 173 | `func_8004D628` | `src/game/water_69D0.c` | 306 | 42/1  | Floats, Rodata  | Pending | Routine logic  |
| 174 | `func_8004B1B4` | `src/game/code_5480.c` | 307 | 16/2  | Floats, ParkedFloor  | Pending (Floor 83) | Wave surface ripple generation and heightfield deformer; draft parked behind NON_MATCHING (chained-assign load share, shared C vars for f-regs, empty-if priority bias)  |
| 175 | `func_i9_802C6CC8` | `src/overlays/ovl_i9/ovl_1C66D0.c` | 307 | 39/10  | Integer Clean  | Pending | Sunset Bay beach breaker wave height calculation  |
| 176 | `func_i0_802C63AC` | `src/overlays/ovl_i0/ovl_1B3EC0.c` | 307 | 40/8  | JumpTable, Rodata  | Pending | Routine logic  |
| 177 | `func_1B1FB0_802C62E4` | `src/unused_code_1B1FB0.c` | 310 | 43/11  | Integer Clean  | Pending | Flight mode debug camera controller  |
| 178 | `func_8008DFD0` | `src/game/code_43DA0.c` | 312 | 0/0  | Floats  | Pending | AI difficulty rubberbanding speed multiplier  |
| 179 | `func_i15_802C5800` | `src/overlays/ovl_i15/ovl_1CFB60.c` | 314 | 31/9  | Floats, Rodata, ParkedFloor  | Pending | Glacier Coast floating iceberg and mist particle display list renderer  |
| 180 | `func_8004A3C0` | `src/sys/sys_utils.c` | 316 | 10/8  | Floats, Rodata, ParkedFloor  | Pending (Floor 145) | Axis-angle rotation matrix (axis-aligned fast paths delegate to func_800498A4); draft parked behind NON_MATCHING, x homed in $f30 instead of $f14  |
| 181 | `func_801DDEDC` | `src/codeseg/A95D0.c` | 316 | 25/14  | Floats, JumpTable, Rodata  | Pending | Routine logic  |
| 182 | `func_1B1FB0_802C5DF4` | `src/unused_code_1B1FB0.c` | 316 | 55/12  | Integer Clean  | Pending | Flight mode debug camera controller  |
| 183 | `func_i12_802C5F6C` | `src/overlays/ovl_i12/ovl_1CAE40.c` | 317 | 72/12  | Integer Clean  | **MATCHED** | Course data menu input handler (cursor, course selection, save/erase dispatch)  |
| 184 | `func_8008D454` | `src/game/code_43DA0.c` | 318 | 34/0  | Floats  | Pending | AI difficulty rubberbanding speed multiplier  |
| 185 | `func_801DF744` | `src/codeseg/A95D0.c` | 321 | 9/4  | Floats  | Pending | Routine logic  |
| 186 | `func_80076378` | `src/game/code_2FB10.c` | 321 | 38/4  | Floats, Rodata  | Pending | Rider lean angle calculation relative to velocity vector and turning radius  |
| 187 | `func_8004EAA4` | `src/game/water_69D0.c` | 324 | 10/0  | Integer Clean  | Pending | Routine logic  |
| 188 | `func_801F9EA0` | `src/codeseg/B97B0.c` | 328 | 27/5  | Floats  | Pending | Routine logic  |
| 189 | `func_i9_802C5800` | `src/overlays/ovl_i9/ovl_1C66D0.c` | 329 | 23/7  | Floats, Rodata  | Pending | Sunset Bay sunset lighting and water specular display list renderer  |
| 190 | `func_8004BC98` | `src/game/code_5480.c` | 331 | 15/7  | Floats, ParkedFloor  | Pending (Floor 71 with ld/st alias symbols) | Dynamic water collision response and splash impulse update; draft parked behind NON_MATCHING, one hidden t-reg queue rotation left at the sin/cos join  |
| 191 | `func_8007D614` | `src/game/core/wr64_save.c` | 331 | 29/10  | JumpTable, Rodata  | Pending | Controller Pak ghost data file verify, header check, and payload reader  |
| 192 | `func_i8_802C5EB8` | `src/overlays/ovl_i8/ovl_1C49A0.c` | 331 | 58/12  | Integer Clean  | Pending | Stunt mode ramp and floating ring display list generator  |
| 193 | `func_i8_802C5800` | `src/overlays/ovl_i8/ovl_1C49A0.c` | 335 | 26/8  | Floats  | Pending | Stunt mode ramp and floating ring display list generator  |
| 194 | `func_8009C2CC` | `src/game/code_52CD0.c` | 338 | 23/19  | Floats, JumpTable  | **MATCHED** | Camera script step dispatcher (22-case jump table); `D_801CEA94[i] = (s16) D_801CEA94[i] + 1` gives `lh` not `lhu`. Its jtbl is the last .rodata of code_52CD0.c; the 4-byte pad after it is the file boundary with code_57EB0.c |
| 195 | `func_i11_802C5800` | `src/overlays/ovl_i11/ovl_1CA480.c` | 338 | 24/18  | Rodata  | **MATCHED** | Warmup options menu display list renderer (completes ovl_1CA480) |
| 196 | `func_801E3EE0` | `src/codeseg/B2510.c` | 343 | 33/0  | JumpTable, Rodata  | **MATCHED** | Menu text banner renderer: IA8 block/tile strips + scissored texrects (completes B2510)  |
| 197 | `func_80067E40` | `src/game/code_C6C0.c` | 344 | 23/3  | Floats  | Pending | Finish line celebration orbital pan camera  |
| 198 | `func_i9_802C6750` | `src/overlays/ovl_i9/ovl_1C66D0.c` | 350 | 31/6  | JumpTable, Rodata  | Pending | Sunset Bay beach breaker wave height calculation  |
| 199 | `func_801E2C14` | `src/codeseg/AF8C0.c` | 355 | 33/0  | Integer Clean  | Pending | Character select and machine tuning cursor display list renderer  |
| 200 | `func_801DCD34` | `src/codeseg/A95D0.c` | 359 | 19/7  | Floats, Rodata  | Pending | Routine logic  |
| 201 | `func_800B2ABC` | `src/game/code_68A10.c` | 360 | 17/12  | Floats  | Pending | Rider water spray intensity calculator based on turning slip angle  |
| 202 | `func_i1_802C6550` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 364 | 47/16  | Integer Clean  | Pending | Course buoy waypoint sequence update  |
| 203 | `func_8004DAF0` | `src/game/water_69D0.c` | 365 | 10/1  | Floats  | Pending | Routine logic  |
| 204 | `func_80051EC0` | `src/game/code_C6C0.c` | 368 | 17/0  | Floats  | Pending | Primary chase-camera look-at target calculator  |
| 205 | `func_i1_802C5DF4` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 368 | 62/12  | ParkedFloor  | Pending | Course buoy waypoint sequence update  |
| 206 | `func_i0_802C5A7C` | `src/overlays/ovl_i0/ovl_1B3EC0.c` | 370 | 28/12  | Integer Clean  | Pending | Routine logic  |
| 207 | `func_801FAEB8` | `src/codeseg/C94E0.c` | 372 | 29/5  | Floats  | Pending | Routine logic  |
| 208 | `func_800A2308` | `src/game/code_57EB0.c` | 379 | 11/4  | Floats  | **MATCHED** | Rank badge renderer (0.1f scale variant); `s32 pad[4]` between sp68 and index sets the 0xA0 frame |
| 209 | `AudioGeneral_PlaySound` | `src/audio/audio_general.c` | 379 | 72/20  | JumpTable, Rodata  | Pending | switch 2  |
| 210 | `func_i3_802C5D54` | `src/overlays/ovl_i3/ovl_1BC890.c` | 380 | 51/6  | Integer Clean  | **MATCHED** | Title-frame fade state machine and difficulty label  |
| 211 | `func_800A16F0` | `src/game/code_57EB0.c` | 387 | 13/5  | Floats  | **MATCHED** | Rank badge renderer variant (v1[1] anim set); same decl/pad[4] frame layout as 800A2308 |
| 212 | `func_800A1CFC` | `src/game/code_57EB0.c` | 387 | 13/5  | Floats  | **MATCHED** | Rank badge renderer variant; same decl/pad[4] frame layout as 800A2308 |
| 213 | `func_800A10E4` | `src/game/code_57EB0.c` | 387 | 13/5  | Floats  | **MATCHED** | Position badge rank indicator renderer: three func_801E4C60 matrix + DL triples; frame needs decl order `temp_s4, v1, var_s3, sp68, s32 pad[4], index` (0xA0 frame) and no stray `gdl++` after the first DL |
| 214 | `func_800916B4` | `src/game/code_43DA0.c` | 393 | 14/2  | Floats  | Pending | irregular  |
| 215 | `func_800AB25C` | `src/game/code_57EB0.c` | 397 | 27/12  | Floats  | Pending | Finish line final lap banner renderer  |
| 216 | `func_801F0E7C` | `src/codeseg/B97B0.c` | 398 | 53/1  | Floats  | Pending | Routine logic  |
| 217 | `func_i12_802C58A0` | `src/overlays/ovl_i12/ovl_1CAE40.c` | 401 | 45/14  | Integer Clean  | **MATCHED** | Course data menu display list (mode tabs, 9-course grid, confirm buttons)  |
| 218 | `func_801EED70` | `src/codeseg/B97B0.c` | 405 | 40/1  | Floats  | Pending | Routine logic  |
| 219 | `func_801E2530` | `src/codeseg/AF8C0.c` | 407 | 65/15  | Floats, JumpTable, Rodata  | Pending | Character select and machine tuning cursor display list renderer  |
| 220 | `func_8006719C` | `src/game/code_C6C0.c` | 413 | 2/1  | Floats  | **MATCHED** | Rider model display-list chain with optional reflection-map setup (guLookAtReflect + gSPLookAt); the texture load must be the compound `_gDPLoadTextureBlockTile` macro, hand-expanded gDP calls schedule the stores differently |
| 221 | `func_801DB8F0` | `src/codeseg/A95D0.c` | 414 | 34/21  | Floats, Rodata  | Pending | 3D particle fireworks and water splash simulator  |
| 222 | `func_8008D94C` | `src/game/code_43DA0.c` | 417 | 43/0  | Floats  | Pending | AI difficulty rubberbanding speed multiplier  |
| 223 | `SysMain_Thread` | `src/sys/sys_main.c` | 433 | 20/60  | Floats  | **MATCHED** | Routine logic  |
| 224 | `func_800618F4` | `src/game/code_C6C0.c` | 446 | 9/0  | Floats  | Pending | Camera collision with course terrain boundaries  |
| 225 | `func_i8_802C63E4` | `src/overlays/ovl_i8/ovl_1C49A0.c` | 446 | 24/20  | Integer Clean  | Pending | Stunt mode ramp and floating ring display list generator  |
| 226 | `func_i1_802C7608` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 446 | 51/9  | Floats, JumpTable, Rodata  | Pending | Primary course navigation display list dispatcher  |
| 227 | `func_801DC60C` | `src/codeseg/A95D0.c` | 458 | 33/13  | Floats, Rodata  | Pending | Routine logic  |
| 228 | `func_800AB95C` | `src/game/code_57EB0.c` | 463 | 20/5  | Floats  | Pending | Disqualification notice overlay renderer  |
| 229 | `func_801E80B0` | `src/codeseg/B66E0.c` | 468 | 58/1  | Floats, JumpTable, Rodata  | Pending | Font glyph metrics table and character bounds initializer  |
| 230 | `func_801F8DD0` | `src/codeseg/B97B0.c` | 468 | 85/1  | Floats  | Pending | Routine logic  |
| 231 | `func_i13_802C5800` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 475 | 53/6  | Floats, Rodata  | Pending | Routine logic  |
| 232 | `func_800AAAC8` | `src/game/code_57EB0.c` | 485 | 28/17  | Floats  | Pending | Finish line final lap banner renderer  |
| 233 | `func_800609EC` | `src/game/code_C6C0.c` | 486 | 14/9  | Floats, Rodata  | Pending | Reverse-view (rear mirror) camera orientation  |
| 234 | `func_8004C1D0` | `src/game/water_69D0.c` | 498 | 23/14  | Floats, Rodata  | Pending | Routine logic  |
| 235 | `func_801E8B24` | `src/codeseg/B66E0.c` | 502 | 46/8  | Floats, JumpTable, Rodata  | Pending | Font glyph metrics table and character bounds initializer  |
| 236 | `func_801F06A0` | `src/codeseg/B97B0.c` | 503 | 20/4  | Floats  | Pending | Routine logic  |
| 237 | `func_i10_802C5A10` | `src/overlays/ovl_i10/ovl_1C9150.c` | 508 | 105/8  | Integer Clean  | **MATCHED** | Options change-conditions menu input handler (cursor, toggles, value edit with min/max wrap)  |
| 238 | `func_i10_802C6200` | `src/overlays/ovl_i10/ovl_1C9150.c` | 512 | 51/22  | Rodata  | **MATCHED** | Options change-conditions menu display list (toggles, per-setting values, changed-from-default notice)  |
| 239 | `func_8004F9E0` | `src/game/water_69D0.c` | 521 | 17/5  | Floats, Rodata  | Pending | Routine logic  |
| 240 | `func_i13_802C8484` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 526 | 16/6  | JumpTable, Rodata, ParkedFloor  | Pending | Placeholder signature follows the 832C call-site evidence  |
| 241 | `func_801E3698` | `src/codeseg/B17D0.c` | 527 | 27/29  | Rodata  | **MATCHED** | Course records screen display list renderer (completes B17D0) |
| 242 | `func_801F14B4` | `src/codeseg/B97B0.c` | 530 | 37/2  | Floats  | Pending | Routine logic  |
| 243 | `func_800AD418` | `src/game/code_57EB0.c` | 541 | 60/19  | Floats, JumpTable  | Pending | New record congratulatory fanfare banner  |
| 244 | `func_800735EC` | `src/game/code_2C670.c` | 544 | 81/4  | Floats  | Pending | Jet ski hull displacement and water elevation offset calculator  |
| 245 | `func_i9_802C5E5C` | `src/overlays/ovl_i9/ovl_1C66D0.c` | 573 | 97/30  | Integer Clean  | Pending | Sunset Bay beach breaker wave height calculation  |
| 246 | `func_8009F398` | `src/game/code_57EB0.c` | 582 | 14/7  | Floats  | Pending | Tachometer RPM indicator display list generator  |
| 247 | `func_801E1290` | `src/codeseg/AF8C0.c` | 582 | 69/16  | Floats, JumpTable, Rodata  | Pending | Machine tuning interaction and controller input loop  |
| 248 | `func_i2_802C5E28` | `src/overlays/ovl_i2/ovl_1B9440.c` | 593 | 115/25  | JumpTable, Rodata  | Pending | Routine logic  |
| 249 | `func_80050204` | `src/game/water_69D0.c` | 605 | 18/5  | Floats, Rodata  | Pending | Routine logic  |
| 250 | `func_8007DF4C` | `src/game/code_383C0.c` | 607 | 25/10  | Floats, Rodata  | Pending | Rider animation bone matrix blending and kinematics  |
| 251 | `func_801F9520` | `src/codeseg/B97B0.c` | 608 | 33/0  | Floats  | Pending | Routine logic  |
| 252 | `func_8009FCB0` | `src/game/code_57EB0.c` | 611 | 16/9  | Floats  | Pending | Tachometer RPM indicator display list generator  |
| 253 | `func_80065C18` | `src/game/code_C6C0.c` | 614 | 100/9  | Floats, Rodata  | Pending | View frustum culling plane extractor  |
| 254 | `func_800A52D8` | `src/game/code_57EB0.c` | 615 | 40/24  | Floats  | Pending | Course mini-map track contour display list builder  |
| 255 | `func_801FA3C0` | `src/codeseg/B97B0.c` | 618 | 34/2  | Floats  | Pending | Routine logic  |
| 256 | `unk_game_load` | `src/game/code_4F850.c` | 630 | 75/4  | JumpTable, Rodata  | Pending | Master game loop state asset loader and segment relocation  |
| 257 | `func_i4_802C5CDC` | `src/overlays/ovl_i4/ovl_1BE0B0.c` | 679 | 44/29  | Rodata  | **MATCHED** | Course select screen renderer; completes ovl_1BE0B0 (`s32 pad[27]` sets the 0xD8 frame; nested flag/sel color ifs and for-header `I4Label` cursors fix the branch skeleton)  |
| 258 | `func_801FB514` | `src/codeseg/C94E0.c` | 680 | 55/4  | Floats  | Pending | Routine logic  |
| 259 | `func_800A063C` | `src/game/code_57EB0.c` | 682 | 11/8  | Floats  | Pending | Tachometer RPM indicator display list generator  |
| 260 | `func_80062E50` | `src/game/code_C6C0.c` | 687 | 27/8  | Floats, Rodata  | Pending | Screen shake impulse generator on hard wipeouts  |
| 261 | `func_801EF504` | `src/codeseg/B97B0.c` | 693 | 84/14  | Floats  | Pending | Routine logic  |
| 262 | `func_801E5554` | `src/codeseg/B3AA0.c` | 712 | 44/3  | Floats  | Pending | Routine logic  |
| 263 | `func_i3_802C6344` | `src/overlays/ovl_i3/ovl_1BC890.c` | 726 | 37/27  | Rodata  | **MATCHED** | Course-select info panel: frames, labels, preview texture, course model  |
| 264 | `func_800687A4` | `src/game/code_C6C0.c` | 734 | 48/9  | Floats  | Pending | Replay camera speed multiplier calculator  |
| 265 | `func_8009DC10` | `src/game/code_57EB0.c` | 737 | 11/8  | Floats  | Pending | Buoy miss warning flash animator  |
| 266 | `func_800665B0` | `src/game/code_C6C0.c` | 763 | 45/21  | Floats, Rodata  | Pending | Depth of field and distance fog reference point updater  |
| 267 | `func_i15_802C602C` | `src/overlays/ovl_i15/ovl_1CFB60.c` | 764 | 44/29  | JumpTable, Rodata  | Pending | Glacier Coast iceberg rebound collision impulse handler. Signature  |
| 268 | `func_800AE7C4` | `src/game/code_68A10.c` | 786 | 88/2  | Floats, JumpTable, Rodata  | Pending | Routine logic  |
| 269 | `func_80054130` | `src/game/code_C6C0.c` | 825 | 15/35  | Floats, Rodata  | Pending | Camera yaw smoothing and heading alignment damping  |
| 270 | `func_800AFBD0` | `src/game/code_68A10.c` | 842 | 25/4  | Floats, Rodata  | Pending | Rider water spray intensity calculator based on turning slip angle  |
| 271 | `func_800A9D48` | `src/game/code_57EB0.c` | 864 | 71/30  | Floats  | Pending | Finish line final lap banner renderer  |
| 272 | `func_800744EC` | `src/game/code_2C670.c` | 866 | 89/6  | Floats, JumpTable, Rodata  | Pending | Jet ski water surface impact damping and hull rocking spring physics  |
| 273 | `func_i9_802C71AC` | `src/overlays/ovl_i9/ovl_1C66D0.c` | 928 | 70/54  | Rodata  | Pending | Sunset Bay beach breaker wave height calculation  |
| 274 | `func_i5_802C5DC0` | `src/overlays/ovl_i5/ovl_1BFF50.c` | 961 | 72/34  | JumpTable, Rodata  | Pending | Port Blue harbor crane and dock surface display list  |
| 275 | `func_i6_802C5C2C` | `src/overlays/ovl_i6/ovl_1C2250.c` | 962 | 57/59  | Rodata  | Pending | Twilight City neon lighting and city canal display list renderer  |
| 276 | `func_80075310` | `src/game/code_2FB10.c` | 972 | 116/1  | Floats, Rodata  | Pending | Rider lean angle calculation relative to velocity vector and turning radius  |
| 277 | `func_80063C88` | `src/game/code_C6C0.c` | 993 | 136/7  | Floats, JumpTable, Rodata  | Pending | Camera roll leveling filter relative to horizon  |
| 278 | `func_80064C0C` | `src/game/code_C6C0.c` | 1027 | 56/15  | Floats, Rodata  | Pending | View frustum culling plane extractor  |
| 279 | `func_80079528` | `src/game/code_2FB10.c` | 1033 | 129/19  | Floats  | Pending | Real-time rider position gap distance and rubberband AI speed scaling  |
| 280 | `func_i1_802C7E48` | `src/overlays/ovl_i1/ovl_1B55A0.c` | 1034 | 76/39  | JumpTable, Rodata  | Pending | Primary course rider rank tracker  |
| 281 | `func_800C010C` | `src/audio/audio_general.c` | 1056 | 166/44  | Floats, Rodata  | Pending | Routine logic  |
| 282 | `func_i13_802C711C` | `src/overlays/ovl_i13/ovl_1CBAF0.c` | 1060 | 51/42  | JumpTable, Rodata  | Pending | Routine logic  |
| 283 | `func_800783AC` | `src/game/code_2FB10.c` | 1119 | 193/9  | Floats, JumpTable, Rodata  | Pending | Real-time rider position gap distance and rubberband AI speed scaling  |
| 284 | `func_800AC184` | `src/game/code_57EB0.c` | 1168 | 73/23  | Floats, JumpTable  | Pending | New record congratulatory fanfare banner  |
| 285 | `func_8008BD2C` | `src/game/code_43DA0.c` | 1200 | 180/1  | Floats, Rodata  | Pending | AI rival waypoint tracking and path spline interpolation  |
| 286 | `func_800B305C` | `src/game/code_68A10.c` | 1240 | 70/3  | JumpTable, Rodata  | Pending | Rider water spray intensity calculator based on turning slip angle  |
| 287 | `func_8008E794` | `src/game/code_43DA0.c` | 1272 | 52/11  | Floats, Rodata  | Pending | AI difficulty rubberbanding speed multiplier  |
| 288 | `func_8008FB74` | `src/game/code_43DA0.c` | 1273 | 124/7  | Floats  | Pending | AI difficulty rubberbanding speed multiplier  |
| 289 | `func_80096960` | `src/game/code_4F850.c` | 1346 | 232/0  | JumpTable, Rodata  | Pending | Multiplayer rider palette index and team color configuration  |
| 290 | `func_8007687C` | `src/game/code_2FB10.c` | 1464 | 244/22  | Floats, Rodata  | Pending | Jet ski throttle response and water drag velocity damping  |
| 291 | `func_80071E70` | `src/game/code_2C670.c` | 1503 | 183/0  | Floats, JumpTable, Rodata  | Pending | Jet ski hull displacement and water elevation offset calculator  |
| 292 | `func_8005B510` | `src/game/code_C6C0.c` | 1541 | 14/36  | Floats, Rodata  | Pending | Routine logic  |
| 293 | `func_801F25E0` | `src/codeseg/B97B0.c` | 1744 | 178/0  | Integer Clean  | Pending | Routine logic  |
| 294 | `func_8008A0E0` | `src/game/code_43DA0.c` | 1811 | 8/2  | Floats, Rodata  | Pending | AI rival waypoint tracking and path spline interpolation  |
| 295 | `func_800B08F8` | `src/game/code_68A10.c` | 2161 | 206/20  | Floats, Rodata  | Pending | Rider water spray intensity calculator based on turning slip angle  |
| 296 | `func_80057B24` | `src/game/code_C6C0.c` | 2468 | 37/38  | Floats, Rodata  | Pending | Camera pitch spring dynamics during wave jumps  |
| 297 | `func_800A2B24` | `src/game/code_57EB0.c` | 2541 | 233/106  | Floats, JumpTable  | Pending | Course mini-map track contour display list builder  |
| 298 | `func_800A68A4` | `src/game/code_57EB0.c` | 2595 | 171/118  | Floats  | Pending | Wrong way warning banner animator  |
| 299 | `func_8005DE24` | `src/game/code_C6C0.c` | 2802 | 317/36  | Floats, JumpTable, Rodata  | Pending | Reverse-view (rear mirror) camera orientation  |
| 300 | `func_8006E674` | `src/game/code_24B00.c` | 3580 | 206/21  | Floats  | **MATCHED** | Course display list renderer: LookAt/matrix setup, fog, spray (completes code_24B00)  |
| 301 | `func_801F4120` | `src/codeseg/B97B0.c` | 4908 | 273/13  | Floats, ParkedFloor  | Pending (Floor 1797) | Race HUD display-list builder; full C draft parked behind NON_MATCHING (insn count, frame 0x700 and control flow match, 266 register-blind rows; left: IDO hoists &D_80228B50/&D_80228B54 and large GBI constants into s-regs the target rematerializes; 1.8f literal lives in the next TU's rodata at 0x80227A4C)  |

---

## Decompilation Workflow & Invariants Checklist

For every function targeted from this roadmap, adhere strictly to the repository decompilation rules:

1. **Context Generation**: Generate header context before translating:
   ```bash
   tools/m2ctx src/<path>/<file>.c
   ```
2. **Initial M2C Translation**:
   ```bash
   python3 tools/m2c/m2c.py -t mips-ido-c --context ctx.c asm/us/rev1/nonmatchings/<path>/<func>.s
   ```
3. **Isolated Probe Verification**:
   - Write standalone IDO probe in `scratch/probe_<func>.c`.
   - Assemble ground-truth slice:
     ```bash
     mips-linux-gnu-as -march=vr4300 -32 -G0 -I include -o scratch/gt_<func>.o scratch/gt_<func>.s
     mips-linux-gnu-objdump -drz -Mreg-names=mips2 scratch/gt_<func>.o | awk '/<func>:/{f=1} f; /^\s*$/{if(f) exit}' > scratch/base_<func>.slice
     ```
   - Compile and diff:
     ```bash
     tools/ido-static-recomp/build/5.3/out/cc [CFLAGS] -o scratch/probe_<func>.o scratch/probe_<func>.c
     .venv/bin/python3 tools/asm-differ/diff.py -m -o -s <func> -f scratch/probe_<func>.o --base-asm scratch/base_<func>.slice
     ```
4. **Promotion Checklist**:
   - ONLY promote when `diff.py` reports `TARGET CURRENT (0)`.
   - Remove `#ifdef NON_MATCHING` wrapper and `#pragma GLOBAL_ASM`.
   - Remove assembly stub: `rm asm/us/rev1/nonmatchings/.../<func>.s`.
   - Remove stale object: `rm -f build/src/.../<file>.o`.
   - Clean up probe files in `scratch/` and `expected/scratch/`.
   - Verify matching ROM: `make` must report `waverace64.us.rev1.z64: OK`.
   - Update unit test in `tests/test_matching.py`.
   - Run full test suite: `make test`.
   - Record progress: `make progress`.
   - Commit with `feat(decomp): promote <func> to matching C`.
