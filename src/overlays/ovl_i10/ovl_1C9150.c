#include "common.h"

#ifdef NON_MATCHING
void func_i10_802C5800(void) {
    /* Drake Lake fog and floating log state initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C5800.s")
#endif

Gfx* func_i10_802C5968(Gfx* gfxP) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 68) {
            return func_80093C44(gfxP);
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

#ifdef NON_MATCHING
void func_i10_802C6A00(s32 arg0) {
    /* Drake Lake transition to results screen */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i10/ovl_1C9150/func_i10_802C6A00.s")
#endif
