#include "common.h"

extern s32 D_802C6B30;
extern s32 D_802C6B34;
extern s32 D_802C6B40[];
extern s32 D_802C6B58;
extern s32 D_802C6B4C;
extern s32 D_i10_802C6B14;

#ifdef NON_MATCHING
void func_i10_802C5800(void) {
    /* Drake Lake state reset: clear scratch words, set flag words from
       option bits, scan for the selected slot, then derive quotient /
       remainder (or defaults) and count nonzero words. PARKED at floor
       (score 1325, 90 of 90 instructions match in shape and control flow):
       - Scan loop: `if (*scanCursor == 0) { slotIdx++; scanCursor++; if (slotIdx < 5) goto scan_loop; }`
         matches retail's `bnezl` with delay slot `li v1, 3`, `addiu v0, 1`,
         `slti at, v0, 5`, `bnez`, `addiu v1, 4`, `bne v0, v1` byte-for-byte.
       - Division/Remainder: `if (slotIdx == 3)` branch and modulo/division with
         `mfhi`/`mflo` matches byte-for-byte.
       - Flag stores: `D_802C6B40[4] = 1; D_802C6B40[3] = 1; if (optionBits & 1) ...`
         matches byte-for-byte.
       - Tail loop: Rolled `count_loop` with delay slot load `bnel v1, a1`
         matches byte-for-byte.
       - Remaining gap (51 rows): IDO CSEs `D_802C6B40` into `$a0` before the
         clear loop and reuses `$a0` for `$v1` (`move $v1, $a0`), whereas retail
         reloads `D_802C6B40` into `$a0` at line 0x40 and keeps independent `$v1`
         cursor loads. Retail also keeps `&D_i10_802C6B14` in `$v0` rather than
         inlining `%lo` offsets. */
    s32 slotIdx;
    s32 optionBits;
    s32* scanCursor;

    if (D_801CE63C != 0) {
        if (gGameState == GAME_STATE_OPTIONS_CHANGE_CONDITIONS) {
            {
                s32* clearEnd = &D_802C6B58;
                s32* clearCursor = D_802C6B40;
                do {
                    clearCursor++;
                    clearCursor[-1] = 0;
                } while ((u32) clearCursor < (u32) clearEnd);
            }
            D_802C6B40[4] = 1;
            D_802C6B40[3] = 1;
            optionBits = D_801CB280;
            scanCursor = D_802C6B40;
            if ((optionBits & 1) != 0) {
                D_802C6B40[0] = 1;
            }
            if ((optionBits & 2) != 0) {
                D_802C6B40[1] = 1;
            }
            if ((optionBits & 4) != 0) {
                D_802C6B40[2] = 1;
            }
            slotIdx = 0;
        scan_loop:
            if (*scanCursor == 0) {
                slotIdx++;
                scanCursor++;
                if (slotIdx < 5) {
                    goto scan_loop;
                }
            }
            if (slotIdx == 3) {
                D_802C6B30 = 1;
                D_802C6B34 = 1;
            } else {
                D_802C6B30 = slotIdx % 3;
                D_802C6B34 = slotIdx / 3;
                slotIdx = 0;
            }
            {
                s32* activeCountPtr;
                s32* countCursor;
                s32* slotEnd;

                activeCountPtr = &D_i10_802C6B14;
                *activeCountPtr = 0;
                countCursor = D_802C6B40;
                slotEnd = &D_802C6B4C;
            count_loop:
                if (*countCursor != 0) {
                    *activeCountPtr = *activeCountPtr + 1;
                }
                countCursor++;
                if (countCursor != slotEnd) {
                    goto count_loop;
                }
                if (*activeCountPtr == 0) {
                    D_802C6B40[3] = 0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C5800.s")
#endif

Gfx* func_i10_802C5968(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return Gfx_ClearFrameBuffers(gfxP);
        }
    }

    D_800DAB2C = 0;

    gfxP = func_i10_802C6200(gfxP);

    if (gGameState == 68) {
        func_i10_802C5A10();
    } else if (D_80228A16 == 1) {
        func_8007C50C();
        func_801EC304();
    }

    return gfxP;
}

#ifdef NON_MATCHING
void func_i10_802C5A10(void) {
    /* Drake Lake calm water disturbance and log bobbing physics */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C5A10.s")
#endif

#ifdef NON_MATCHING
Gfx* func_i10_802C6200(Gfx* gfxP) {
    /* Drake Lake distance fog display list and wooden logs */
    return gfxP;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C6200.s")
#endif

void func_i10_802C6A00(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x45;
    D_801CE638 = 0xE;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);
}
