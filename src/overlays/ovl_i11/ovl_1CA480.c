#include "global.h"

#ifdef NON_MATCHING
Gfx* func_i11_802C5800(Gfx* glistp) {
    /* Warmup course ramp and obstacle display list renderer */
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i11/ovl_1CA480/func_i11_802C5800.s")
#endif

typedef struct {
    s32 min;
    s32 max;
} Limit_802C618C;
extern Limit_802C618C D_i11_802C618C[];

void func_800C3050(s32);
void func_i11_802C6098(s32);
void func_i11_802C5F7C(void);

#ifdef NON_MATCHING
/* Warmup course controller input and obstacle parameter adjuster (141 instructions).
 * Parked behind NON_MATCHING: IDO 5.3 allocator inverts v0/v1 register assignments
 * for controller button checks. */
void func_i11_802C5D48(void) {
    s32 pad;
    s32 sp18;
    s32* temp_v0;
    s32 temp_t4;
    s32 temp_t7;
    s32 temp_t9;
    Limit_802C618C* temp_a0;

    if (*(u16*) ((u8*) &D_801CE658 + 0x3A) & 0xB000) {
        if (D_i11_802C6150 == 2) {
            sp18 = 1;
            func_800C3050(D_800DA9EC[D_i11_802C6150]);
        } else if (D_i11_802C6150 == 3) {
            sp18 = 1;
            func_i11_802C6098(0x3C);
        }
        if (sp18 != 0) {
            AudioGeneral_PlaySound(0x11, 0);
        }
    } else {
        if (*(u16*) ((u8*) &D_801CE658 + 0x3A) & 0x4000) {
            func_i11_802C6098(0x3C);
            AudioGeneral_PlaySound(0x16, 0);
            return;
        }
        if (*(u16*) ((u8*) &D_801CE658 + 2) & 0x800) {
            temp_t4 = D_i11_802C6150 - 1;
            D_i11_802C6150 = temp_t4;
            if (temp_t4 < 0) {
                D_i11_802C6150 = 3;
            }
            AudioGeneral_PlaySound(0x10, 0);
            return;
        }
        if (*(u16*) ((u8*) &D_801CE658 + 2) & 0x400) {
            temp_t9 = D_i11_802C6150 + 1;
            D_i11_802C6150 = temp_t9;
            if (temp_t9 >= 4) {
                D_i11_802C6150 = 0;
            }
            AudioGeneral_PlaySound(0x10, 0);
            return;
        }
        if (*(u16*) ((u8*) &D_801CE658 + 2) & 0x200) {
            if (D_i11_802C6150 != 3) {
                temp_a0 = &D_i11_802C618C[D_i11_802C6150];
                temp_v0 = &D_800DA9EC[D_i11_802C6150];
                temp_t7 = *temp_v0 - 1;
                *temp_v0 = temp_t7;
                if (temp_t7 < temp_a0->min) {
                    *temp_v0 = temp_a0->max;
                }
                func_i11_802C5F7C();
            }
            AudioGeneral_PlaySound(0x10, 0);
            return;
        }
        if (*(u16*) ((u8*) &D_801CE658 + 2) & 0x100) {
            if (D_i11_802C6150 != 3) {
                temp_a0 = &D_i11_802C618C[D_i11_802C6150];
                temp_v0 = &D_800DA9EC[D_i11_802C6150];
                temp_t7 = *temp_v0 + 1;
                *temp_v0 = temp_t7;
                if (temp_a0->max < temp_t7) {
                    *temp_v0 = temp_a0->min;
                }
                func_i11_802C5F7C();
            }
            AudioGeneral_PlaySound(0x10, 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i11/ovl_1CA480/func_i11_802C5D48.s")
#endif

void func_i11_802C5F7C(void) {
    if (D_i11_802C6150 == 0) {
        if (D_800DA9EC[D_i11_802C6150] == 0) {
            func_800C2FDC(0);
            D_801CB280 &= 0x3F;
        } else if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C2FDC(3);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x40;
        } else {
            func_800C2FDC(1);
            D_801CB280 &= 0x3F;
            D_801CB280 |= 0x80;
        }
    } else if (D_i11_802C6150 == 1) {
        if (D_800DA9EC[D_i11_802C6150] == 1) {
            func_800C3034();
            D_801CB280 &= 0xDF;
        } else {
            func_800C3044();
            D_801CB280 |= 0x20;
        }
    }
}

void func_i11_802C6098(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 73;
    D_801CE638 = 20;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;

    FadeTransition_SetProps(1, 4, 0);
    func_801E6A4C(0, 0);

    if (D_801CE630 == 60) {
        func_800C1F60(9);
    }
}
