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
       (best probe: clear/flag/div shapes match; scan latch + tail diverge):
       - Clear loop: assign `end` before the cursor to land end->v0 and
         cursor->v1 (reversed order mirrors them); scope the pair so the
         base dies with the loop. IDO still shares the base into later
         stores via a copied cursor instead of bumping it directly.
       - Scan loop: `if (*p) { k = 3; goto done; }` + post-loop `k = 3`
         is the only shape putting k=3 on both exit paths, but IDO either
         merges the two stores into one hoisted li (losing the bnel delay
         fill) or keeps them with a beqzl+b head; the `i < 5` latch is
         always canonicalized to `li + bne`, never retail's `slti + bnez`
         (20+ latch spellings probed, including hand-rolled goto loops;
         variable trips unroll instead).
       - Tail counter loop: computable trip (same globals) sends IDO's
         unroller off the rails (peel + unrolled copies + remainder
         masking); retail keeps it rolled behind bnel.
       Revisit with whole-file context or a new lever. */
    s32 i;
    s32* p;
    s32 k;
    s32 t;
    s32 t5;
    s32* ctr;
    s32* end2;

    if (D_801CE63C != 0) {
        if (gGameState == GAME_STATE_OPTIONS_CHANGE_CONDITIONS) {
            /* Assign end before pc: that order puts the end in v0 and the
               cursor in v1, matching retail (reversed order mirrors the
               pair into v0/v1). Scoped so the base dies with the loop;
               later stores recompute it fresh instead of sharing. */
            {
                s32* end = &D_802C6B58;
                s32* pc = D_802C6B40;
                do {
                    pc++;
                    pc[-1] = 0;
                } while ((u32) pc < (u32) end);
            }
            D_802C6B40[4] = 1;
            D_802C6B40[3] = 1;
            t = D_801CB280;
            if ((t & 1) != 0) {
                D_802C6B40[0] = 1;
            }
            if ((t & 2) != 0) {
                D_802C6B40[1] = 1;
            }
            /* i = 0 sits in the next beqz delay slot in the stub (both
               paths); p is assigned alongside so both span the flags. */
            i = 0;
            p = D_802C6B40;
            if ((t & 4) != 0) {
                D_802C6B40[2] = 1;
            }
            do {
                if (*p != 0) {
                    k = 3;
                    goto scan_done;
                }
                i++;
                p++;
            } while (i < 5);
            k = 3;
        scan_done:;
            if (i == k) {
                D_802C6B30 = 1;
                D_802C6B34 = 1;
            } else {
                D_802C6B30 = i % k;
                D_802C6B34 = i / k;
            }
            ctr = &D_i10_802C6B14;
            *ctr = 0;
            p = D_802C6B40;
            end2 = &D_802C6B4C;
            t5 = *p;
            do {
                p++;
                if (t5 != 0) {
                    *ctr = *ctr + 1;
                }
                t5 = *p;
            } while (p != end2);
            if (*ctr == 0) {
                D_802C6B40[3] = 0;
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
