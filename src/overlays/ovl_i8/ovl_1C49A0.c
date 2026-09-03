#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i8_802C5800(Gfx* arg0) {
    /* Stunt mode ramp and floating ring display list generator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C5D3C(void) {
    /* Stunt jump ramp trajectory and height evaluator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5D3C.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C5EB8(void) {
    /* Stunt floating ring collision check and ring pass sound */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C5EB8.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C63E4(void) {
    /* Stunt score multiplier and combo timer update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C63E4.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C6ADC(void) {
    /* Stunt trick recognition and rotation detector */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C6ADC.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C6D58(void) {
    /* Stunt mode bonus point award animation */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C6D58.s")
#endif

#ifdef NON_MATCHING
void func_i8_802C6DA8(void) {
    /* Stunt high score rank evaluator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C6DA8.s")
#endif

void func_i8_802C6E00(void) {
    if ((D_802C7548) != 0) {
        func_i8_802C6FD4(&D_802C7548, (s8*) &D_801CB298[D_i8_802C74F8[D_i8_802C7040]].unk_0, 11);
    }
    D_802C756C = 1;
}

void func_i8_802C6E68(void* arg0) {
    func_i8_802C6FD4(arg0, &D_802C7548, 0xB);
    D_802C7564 = Strlen2(&D_802C7548);
    if (D_802C7564 >= 9) {
        D_802C7564 = 9;
    }
}

#ifdef NON_MATCHING
void func_i8_802C6EB8(void) {
    /* Stunt initials and score entry commit */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i8/ovl_1C49A0/func_i8_802C6EB8.s")
#endif

void func_i8_802C6F4C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x3F;
    D_801CE638 = 0xA;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;
    FadeTransition_SetProps(1, 4, 0);
}

void func_i8_802C6FD4(s8* src, s8* dest, s32 count) {
    s32 i;

    for (i = 0; i < count; i++) {
        *dest++ = *src++;
    }
}
