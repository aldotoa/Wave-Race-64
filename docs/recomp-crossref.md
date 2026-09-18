# Recomp cross-reference (elliotttate/wave-race-64-recomp)

Static-recompilation PC port (N64Recomp) of the same retail ROM: USA Rev A,
sha1 `508dfc2d4caa42b6f6de5263d0aed5e44ac7966a`, entry `0x80046800` --
identical to this repo's matching target. Its generated C is
semantically-equivalent machine output, NOT IDO-matching source: never copy
it into `src/`. What transfers is triage knowledge, and most of it confirms
what this tree already has.

## Confirmed against this tree (with evidence)

- 19 overlay sections share VRAM `0x802C5800` (16 `ovl_iN` + `segment_1B1FB0`
  + `seg_1C3780` + `seg_1C3D00`). Matches `waverace64.us.rev1.yaml` and the
  build `.map`. `tools/check_overlay_calls.py` re-derives this from the ELF.
- `GameLoad_LoadOverlay` DMAs the selected overlay with `osPiStartDma`
  straight to `0x802C5800` (not via `game_dma_copy`), reading the entry from
  `gOverlayTable`. Already matched in `src/game/wr64_game_load.c`.
- Key RAM addresses agree: `gCourseID = 0x800D8170`, mode struct at
  `0x801CE608`, `gSequencePlayers = 0x8003FCC8` (4 players).
  The recomp's byte-offset description of the sequence players is weaker than
  `SequencePlayer` in `include/wr64audio.h`; prefer ours.

## The one structural warning worth keeping

Resident code calls directly into the overlay window, so a `jal 0x802Cxxxx`
target cannot be resolved statically -- which overlay is resident is a
runtime fact owned by `GameLoad_LoadOverlay`. Three resident callers:

| This tree | Recomp name | Role |
|---|---|---|
| `Game_BuildDisplayList` (`src/game/code_4C750.c:572`, `0x80092CF0`) | `func_80092CF0` | overlay dispatcher, ~20 targets selected per game state |
| `Game_UpdateFrame` (`src/game/code_4C750.c:235`, `0x800922E4`) | `func_800922E4` | 3 targets |
| `PauseMenu_Update` (`src/codeseg/wr64_pause_menu.c:62`, `0x801E4440`) | `PauseMenu_Update` | 1 target (`func_i1_802C744C`) |

Consequences for matching work:

- The `func_802Cxxxx` prototypes in `include/functions.h` are shared across
  overlays that each define the same address differently. Changing one to
  match a single overlay can break the others; check all callers first
  (this restates the AGENTS.md prototyping rule, with the reason attached).
- `Game_BuildDisplayList` cases that name a `func_802Cxxxx` are claims about
  which overlay is resident in that game state. The `VERIFY` comment at
  `src/game/code_4C750.c:610` is exactly this problem. Run
  `python3 tools/check_overlay_calls.py` to list every such site from the
  built ELF when triaging.
- The recomp's `recomp/jal_targets.txt` (call targets with no function
  symbol) overlaps our `func_802Cxxxx` set (`802C5A7C`, `802C5AE4`,
  `802C5BA4`, `802C6944`, `802C7D00`, `802C913C`, ...). If a new undefined
  `jal` target appears during triage, compare against that file before
  inventing a symbol.

## What NOT to take

- Generated recomp C / `recomp_overlays.inl` / `runtime_funcs.inl`: correct
  semantics, wrong codegen, plus ROM-derived. No matching value.
- Port layers (`dlrewrite`, water/music/haptics/texture code, RT64 patches):
  new code for the PC renderer, not original game logic.
- Rev A <-> v1.0 address arithmetic: their phase-01 measurement shows the
  revisions differ by piecewise shifts (`-0x270`...`-0x2A0` bands), not one
  constant. Never port a symbol by adding an offset; function order is
  preserved, so align by sequence and verify by body.
