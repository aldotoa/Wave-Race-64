#include "global.h"

#ifdef NON_MATCHING
Gfx* func_i13_802C5800(Gfx* arg0) { return arg0; }
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C5F6C(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C5F6C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6068(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6068.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C61E0(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C61E0.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C62EC(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C62EC.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C64AC(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C64AC.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C65D4(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C65D4.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6700(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6700.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C69CC(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C69CC.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6ABC(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6ABC.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6BC4(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6BC4.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C6CE4(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6CE4.s")
#endif

extern s32 D_i13_802C8D54;
extern s32 D_i13_802C8D74;
extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
s32 func_8007D2D4(s32);
s32 func_8007D614(s32);
void func_800C3E6C(s32);

s32 func_i13_802C6E48(void) {
    s32 temp = 0;

    if (D_i13_802C8D80 == 0) {
        return 0;
    }

    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 0;

    if (D_i13_802C8D54 == 0) {
        D_i13_802C8D74 = func_8007D2D4(5);
    } else {
        D_i13_802C8D74 = func_8007D614(5);
    }

    if (D_i13_802C8D74 == 0) {
        D_801CE640 = 1;
        temp = 1;
    } else {
        D_801CE640 = 3;
    }

    if (temp != 0) {
        func_800C3E6C(1);
    }

    return 0;
}

#ifdef NON_MATCHING
void func_i13_802C6F0C(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C6F0C.s")
#endif

void func_i13_802C7060(void) {
    switch (D_i13_802C8D78) {
        case 1:
            if (D_802C8E98 >= 5) {
                D_i13_802C8D78 = 2;
                D_802C8E98 = 0;
            }
            break;

        case 2:
            if (++D_802C8E98 >= 0xA) {
                D_i13_802C8D78 = 3;
                D_802C8E98 = 0;
            }
            break;

        case 3:
            if (++D_i13_802C8DC0 >= 0x5B) {
                D_i13_802C8D78 = 0;
                D_802C8E98 = 0;
                D_i13_802C8DC0 = 0;
            }
            break;
    }
}

#ifdef NON_MATCHING
void func_i13_802C711C(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C711C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C81AC(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C81AC.s")
#endif

extern s32 D_i13_802C8D80;
extern s32 D_i13_802C8D84;
extern s32 D_802C8E90;
extern s32 D_802C8E94;
extern s32 D_802C8E98;
extern s32 D_802C8E9C;

void func_i13_802C82A4(s32 arg0) {
    D_i13_802C8D80 = 0;
    D_i13_802C8D84 = 1;
    D_802C8E90 = 0x1C;
    D_802C8E94 = 0x44;
    D_802C8E98 = 0;
    switch (arg0) {
        case 2:
            D_802C8E9C = 5;
            break;
        case 3:
            D_802C8E9C = 7;
            break;
        case 4:
            D_802C8E9C = 8;
            break;
    }
}

#ifdef NON_MATCHING
void func_i13_802C832C(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C832C.s")
#endif

#ifdef NON_MATCHING
void func_i13_802C8484(void) {}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i13/ovl_1CBAF0/func_i13_802C8484.s")
#endif

void func_i13_802C8CBC(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 0x41;
    D_801CE638 = 0xB;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 4, 0);
}
