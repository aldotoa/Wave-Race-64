#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i6_802C5800(Gfx* arg0) {
    /* Twilight City neon lighting and city canal display list renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5800.s")
#endif

Gfx* Gfx_ClearFrameBuffers(Gfx*);
Gfx* func_8008FB74(Gfx*);
Gfx* Gfx_FillCourseColor(Gfx*, s32);
Gfx* Draw_WaterEffects(Gfx*);
Gfx* func_i6_802C5C2C(Gfx*);
void func_i6_802C6B34();

Gfx* func_i6_802C5B74(Gfx* glistp) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x32 && gPrevGameState != 0x64) {
            return Gfx_ClearFrameBuffers(glistp);
        }
    }
    D_800DAB2C = 0;
    glistp = func_i6_802C5C2C(Draw_WaterEffects(Gfx_FillCourseColor(func_8008FB74(glistp), gCourseID)));
    if (gGameState == 0x32) {
        func_i6_802C6B34(glistp);
    }
    return glistp;
}

#ifdef NON_MATCHING
Gfx* func_i6_802C5C2C(Gfx* arg0) {
    /* City canal wall collision and rebound force evaluator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5C2C.s")
#endif

extern s32 D_802C6D30;
extern s32 D_802C6D34;
extern s32 D_802C6D38;
extern s32 D_802C6D3C;
void func_801EC830(void);

void func_i6_802C6B34() {
    s32 var_a2;

    var_a2 = 0;
    switch (D_802C6D30) {
        case 0:
            D_802C6D30 = 1;
            break;
        case 1:
            D_802C6D34 -= 0x14;
            if (D_802C6D34 < 0x14) {
                D_802C6D30 = 2;
                D_802C6D34 = 0x14;
            }
            D_802C6D38 = 0x28 - D_802C6D34;
            break;
        case 2:
            if (D_801CE692[0].unk0 & 0xB000) {
                var_a2 = 1;
                D_802C6D30 = 3;
            }
            break;
        case 3:
            D_802C6D34 -= 0x14;
            if (D_802C6D34 < -0x108) {
                D_802C6D30 = 4;
                D_802C6D34 = -0x108;
                D_802C6D3C = 0;
            }
            D_802C6D38 = 0x28 - D_802C6D34;
            break;
        case 4:
            D_802C6D3C++;
            if (D_802C6D3C >= 3) {
                func_801EC830();
            }
            break;
    }
    if (var_a2 != 0) {
        AudioGeneral_PlaySound(0x31, 0);
    }
}
