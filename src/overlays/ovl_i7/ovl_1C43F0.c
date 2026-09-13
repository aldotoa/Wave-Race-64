#include "global.h"

void func_801EC3AC(void);
void func_801EC500(void);
void func_801EC5B4(void);
void func_801EC650(void);
void func_801EC6EC(void);
void func_801EC780(void);
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Struct_i7_802C5D3C;

extern Struct_i7_802C5D3C D_i7_802C5D3C[];
extern Mtx D_7000000;
extern Mtx D_2000A40;
extern Gfx D_106F550[];

Gfx* func_i7_802C5A18(Gfx*);
void func_i7_802C5C94(s32);
extern s32 gCurrentOptionsMenuItem;
extern s32 D_i7_802C5D20[];

Gfx* func_i7_802C5800(Gfx* arg0) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x3C) {
            if (gPrevGameState == 4) {
                gCurrentOptionsMenuItem = 0;
            }
            return Gfx_ClearFrameBuffers(arg0);
        }
    }
    D_800DAB2C = 0;
    arg0 = func_i7_802C5A18(arg0);
    if (gGameState == 0x3C) {
        if (D_801CE65A->unk0 & (CONT_A | CONT_G | CONT_START)) {
            func_i7_802C5C94(D_i7_802C5D20[gCurrentOptionsMenuItem]);
            AudioGeneral_PlaySound(0x11, 0);
        } else if (D_801CE65A->unk0 & CONT_B) {
            func_i7_802C5C94(2);
            AudioGeneral_PlaySound(0x16, 0);
        } else if (D_801CE65A->unk0 & CONT_UP) {
            if ((--gCurrentOptionsMenuItem) < 0) {
                gCurrentOptionsMenuItem = 6;
            }
            AudioGeneral_PlaySound(0x10, 0);
        } else if (D_801CE65A->unk0 & CONT_DOWN) {
            if ((++gCurrentOptionsMenuItem) == 7) {
                gCurrentOptionsMenuItem = 0;
            }
            AudioGeneral_PlaySound(0x10, 0);
        }
    } else if (D_80228A16 == 1) {
        switch (D_801CE630) {
            case 0x3E:
                func_801EC3AC();
                break;
            case 0x42:
                func_801EC500();
                break;
            case 0x44:
                func_801EC5B4();
                break;
            case 0x46:
                func_801EC6EC();
                break;
            case 0x40:
                func_801EC780();
                break;
            case 0x48:
                func_801EC650();
                break;
            default:
                func_801EB180();
                break;
        }
    }
    return arg0;
}

#ifdef NON_MATCHING
/*
 * Decompilation Floor Analysis for func_i7_802C5A18 (Parked at Floor Score: 400,
 * down from 950; baseline re-verified against directly-assembled stub, 160/160 insns):
 * - Lines 0x00 - 0x35C (prologue, GBI matrices/display lists, frame loop, mid calls): 100% bit-for-bit match.
 * - Lines 0x360 - 0x48C (options loop and tail call): opcodes, immediates, and memory
 *   offsets all match 1-to-1; only register names differ.
 * - Fixed vs prior floor: empty `else {}` on the skip branch corrected the
 *   &gCurrentOptionsMenuItem -> $s3 / bound 7 -> $s4 coloring, recovered the
 *   pre-branch sll/addu hoist (load-delay fill), and collapsed most of the
 *   coordinate chain into $v0.
 * - Remaining floor difference: IDO GRA pairs ptr/i ($s0 <-> $s1) only.
 *   Target allocates: ptr -> $s0, i -> $s1.
 *   Current allocates: i -> $s0, ptr -> $s1 (plus consequent t-reg rotation
 *   in the chain head and 0xFF block).
 * - Swept inert (~30 probes): decl order, `register` on/off/both, init order,
 *   continue/goto/if-else/while spellings, bound `7`/`!= 7`/`<= 6`, pre/post
 *   increments, hoisted temp, indexed access (no strength reduction), tail forms.
 * - Load-bearing constructs:
 *   1. Loop 1 counter reuse: `for (i = 0x49; i < 0xCE; i += 0x13)` reuses `i` across loops,
 *      suppressing bound hoisting to callee-saved registers and emitting exact `slti/bnez`
 *      matching Target prologue saves and frame layout 100%. A separate loop 1 counter
 *      hoists the bound into a saved reg (`bne`) and breaks Loop 1.
 *   2. Coordinate formula: `((i * 4 + i) * 4 - i) + 0x4C` emits exact sll/addu/sll/subu/addiu sequence
 *      without emitting multu (-Wab,-r4300_mul active).
 *   3. Loop header: `for (ptr = D_i7_802C5D3C, i = 0; i < 7; i++, ptr++)` emits exact 7 setup instructions.
 *   4. Empty `else {}` (branch-skeleton filler): required for the $s3/$s4 coloring and
 *      the pre-branch hoist; removing it regresses to the 950 floor.
 */
Gfx* func_i7_802C5A18(Gfx* glistp) {
    register Struct_i7_802C5D3C* ptr;
    s32 i;

    gSPMatrix(glistp++, &D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(glistp++, &D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(glistp++, D_106F550);
    gSPDisplayList(glistp++, D_106F628);

    for (i = 0x49; i < 0xCE; i += 0x13) {
        glistp = Menu_DrawFrame(glistp, 0, 0x3A, i, 0xCC, 0x10);
    }

    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 2, 5, 0x6B, 0x22, 0);

    for (ptr = D_i7_802C5D3C, i = 0; i < 7; i++, ptr++) {
        if (i == gCurrentOptionsMenuItem) {
            continue;
        } else {
        }
        glistp = func_801E3EE0(glistp, 1, ptr->unk4, ptr->unk0 + 0x6D, ((i * 4 + i) * 4 - i) + 0x4C, 0);
    }

    glistp = func_801E946C(glistp, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    ptr = &D_i7_802C5D3C[gCurrentOptionsMenuItem];
    return func_801E3EE0(glistp, 1, ptr->unk4, ptr->unk0 + 0x6D, gCurrentOptionsMenuItem * 0x13 + 0x4C, 0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i7/ovl_1C43F0/func_i7_802C5A18.s")
#endif

void func_i7_802C5C94(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x3D;
    D_801CE638 = 7;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}
