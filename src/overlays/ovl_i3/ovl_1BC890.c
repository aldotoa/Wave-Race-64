#include "global.h"

#ifdef NON_MATCHING
Gfx* func_i3_802C5800(Gfx* arg0) {
    /* Marine Fortress master overlay display list and water gate coordinator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5800.s")
#endif

void func_i3_802C5AE8(void) {
}

void func_i3_802C5AF0(void) {
    func_80069798(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C7024, &D_80198310, &D_80198350);
}

#ifdef NON_MATCHING
void func_i3_802C5B40(void) {
    /* Marine Fortress breakwater surge heightfield updater */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5B40.s")
#endif

#ifdef NON_MATCHING
void func_i3_802C5D54(void) {
    /* Storm lock gate opening/closing kinematic animator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5D54.s")
#endif

#ifdef NON_MATCHING
void func_i3_802C6344(void) {
    /* Breakwater splash particle emitter and collision response */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C6344.s")
#endif

void func_i3_802C6E9C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    D_800D461C = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    func_801E6A4C(0, 0);
    AudioGeneral_PlaySound(58, 0);
}
