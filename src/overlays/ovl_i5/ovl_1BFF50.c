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

#ifdef NON_MATCHING
void func_i5_802C6F84(void) {
    /* Port Blue finish line gantry and buoy beacon renderer */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1BFF50/func_i5_802C6F84.s")
#endif
