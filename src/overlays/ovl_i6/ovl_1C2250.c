#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i6_802C5800(Gfx* arg0) {
    /* Twilight City neon lighting and city canal display list renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5800.s")
#endif

Gfx* func_80093C44(Gfx*);
Gfx* func_8008FB74(Gfx*);
Gfx* func_800949B8(Gfx*, s32);
Gfx* Draw_WaterEffects(Gfx*);
Gfx* func_i6_802C5C2C(Gfx*);
void func_i6_802C6B34(Gfx*);

Gfx* func_i6_802C5B74(Gfx* glistp) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 0x32 && gPrevGameState != 0x64) {
            return func_80093C44(glistp);
        }
    }
    D_800DAB2C = 0;
    glistp = func_i6_802C5C2C(Draw_WaterEffects(func_800949B8(func_8008FB74(glistp), gCourseID)));
    if (gGameState == 0x32) {
        func_i6_802C6B34(glistp);
    }
    return glistp;
}

#ifdef NON_MATCHING
void func_i6_802C5C2C(void) {
    /* City canal wall collision and rebound force evaluator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C5C2C.s")
#endif

#ifdef NON_MATCHING
void func_i6_802C6B34(void) {
    /* Twilight City night lighting and specular reflection setup */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i6/ovl_1C2250/func_i6_802C6B34.s")
#endif
