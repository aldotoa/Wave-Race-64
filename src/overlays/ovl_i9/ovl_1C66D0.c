#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i9_802C5800(Gfx* arg0) {
    /* Sunset Bay sunset lighting and water specular display list renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_i9_802C5D24(void) {
    /* Sunset Bay dynamic tide level drain and shoreline waves */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5D24.s")
#endif

#ifdef NON_MATCHING
void func_i9_802C5E5C(void) {
    /* Sunset Bay beach breaker wave height calculation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C5E5C.s")
#endif

#ifdef NON_MATCHING
void func_i9_802C6750(void) {
    /* Sunset Bay sunset sky color palette interpolation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C6750.s")
#endif

#ifdef NON_MATCHING
void func_i9_802C6CC8(void) {
    /* Sunset Bay water surface specular highlight reflection map */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C6CC8.s")
#endif

void func_i9_802C7194(s32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0[0] = arg1;
    arg0[1] = arg2;
    arg0[2] = arg3;
    arg0[3] = arg4;
}

#ifdef NON_MATCHING
void func_i9_802C71AC(void) {
    /* Sunset Bay shoreline surf particle emission and audio cue */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i9/ovl_1C66D0/func_i9_802C71AC.s")
#endif

void func_i9_802C802C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0x43;
    D_801CE638 = 0xC;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}
