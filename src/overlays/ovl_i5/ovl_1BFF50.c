#include "common.h"

void func_i5_802C5800(void) {
    if ((D_801CE63C != 0) && (gGameState == 52)) {
        Race_UpdateStandings();
        func_i5_802C5A98();
    }
    func_i5_802C5850();
}

#ifdef NON_MATCHING
void func_i5_802C5850(void) {
    /* Port Blue container ship wake disturbance simulation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5850.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C5A98(void) {
    /* Port Blue harbor waterway current state reset */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5A98.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C5C1C(void) {
    /* Port Blue harbor crane and dock surface display list */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5C1C.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C5DC0(void) {
    /* Port Blue moving container barge kinematic update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C5DC0.s")
#endif

#ifdef NON_MATCHING
void func_i5_802C6CC4(void) {
    /* Port Blue canal lock water height adjust */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C6CC4.s")
#endif

void func_i5_802C6F84(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x35;
    D_801CE638 = 9;
    D_801CE63C = 1;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    if (D_801CE630 == 0x66) {
        FadeTransition_SetProps(1, 4, 0);
    } else if (D_801CE630 == 0x1E) {
        FadeTransition_SetProps(5, 2, 0);
    } else {
        FadeTransition_SetProps(5, 1, 0);
    }

    if (D_801CE630 == 0x66) {
        func_800C1F60(0xB);
        return;
    }
    if (D_801CE630 == 0x1E) {
        func_800C1F60(2);
    }
}
