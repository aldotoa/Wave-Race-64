#include "global.h"

extern s32 D_800D45DC[]; // array pointing to some mio0 adresses
extern u8 D_8000008[];

s32 func_1B1FB0_802C71B8(s32, char, s32, s32);
extern s32 D_802C7718;

#ifdef NON_MATCHING
void func_1B1FB0_802C5800(void) {
    /* Flight mode debug camera controller */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5800.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C5BA4(void) {
    /* Flight mode terrain height lookup */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5BA4.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C5DF4(void) {
    /* Flight velocity integration and aerodynamic lift */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5DF4.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C62E4(void) {
    /* Debug flight matrix transform setup */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C62E4.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C67BC(void* arg0, s32 arg1) {
    /* Debug flight collision boundary detector */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C67BC.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C6970(void) {
    /* Flight mode player input interpreter */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6970.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C6C1C(void) {
    /* Debug flight HUD coordinates */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6C1C.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C6E40(void* arg0, s32 arg1) {
    /* Flight telemetry state update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6E40.s")
#endif

#ifdef NON_MATCHING
void func_1B1FB0_802C6FF8(void) {
    /* Onscreen debug font glyph index lookup */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6FF8.s")
#endif

#ifdef NON_MATCHING
/* Debug text character renderer: emits one glyph's RDP packets at arg0,
   returns the advanced cursor. Values below 0x10 emit nothing; values at
   or above 0x42 use glyph 0x3B.
 * PARKED at floor 5735 (probe D, per-pair scoped-temp blocks on a gdl
   cursor, same idiom as matched sibling func_1B1FB0_802C7578 -- that idiom
   is what keeps IDO's pointer walk; plain chains and single-cursor walks
   fold to base+offset, ~7300; const-table loop keeps its branch, dead).
 * Load-bearing: `char` arg1 (free dead spill `sw a1,4(sp)` via IDO arg
   homing, micro-proven); two C returns (stub has two `jr ra`); per-pair
   `{ Gfx* _g = gdl++; ... }` blocks (the walk collapses without them).
 * Remaining gap, all in the head rows: retail fills the first branch delay
   slot with the spill (`beqz` + `sw`) and needs no index save; every probe
   instead spills before the branch and spends the delay slot on
   `move tX,v0`, stealing t0 and cascading one register off through the
   body (pair-5/6 cursors v0/v1 already match). Tried, all 5735 unless
   noted: decl reorder, lazy gdl init, cursor threaded through s32 arg0
   (worse, 6335), empty-else clamp, test-original/write-copy, named index
   temp, doubled dummy store (byte-identical to D -- dummy eliminated),
   ternary clamp (identical), `char` homing micro-proven as the free spill
   source (s32 arg: no spill), volatile (builds a frame, dead end).
 * Next: find the no-split head form -- likely the clamp/index variable
   split (PHI in one reg, no save) -- then re-diff; the body walk is done. */
s32 func_1B1FB0_802C71B8(s32 arg0, char arg1, s32 arg2, s32 arg3) {
    s32 v0 = arg1 & 0xFF;
    Gfx* gdl = (Gfx*) arg0;

    if (v0 < 0x10) {
        return arg0;
    }
    if (v0 >= 0x42) {
        v0 = 0x3B;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xFD700000;
        _g->words.w1 = (u32) &D_8000008[((v0 - 0x10) & 0xFF) << 8];
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xF5700000;
        _g->words.w1 = 0x07080200;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xE6000000;
        _g->words.w1 = 0;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xF3000000;
        _g->words.w1 = 0x0707F400;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xE7000000;
        _g->words.w1 = 0;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xF5680400;
        _g->words.w1 = 0x00080200;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xF2000000;
        _g->words.w1 = 0x0003C03C;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = ((((arg2 + 0x10) * 4) & 0xFFF) << 0xC) | 0xE4000000 | (((arg3 + 0x10) * 4) & 0xFFF);
        _g->words.w1 = (((arg2 * 4) & 0xFFF) << 0xC) | ((arg3 * 4) & 0xFFF);
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xB3000000;
        _g->words.w1 = 0;
    }
    {
        Gfx* _g = gdl++;
        _g->words.w0 = 0xB2000000;
        _g->words.w1 = 0x04000400;
    }
    return (s32) gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C71B8.s")
#endif

s32 func_1B1FB0_802C7304(s32 arg0, s8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s1 = arg3;

    D_802C7718 = 0;

    while (arg2) {
        if (*arg1 != 0) {
            D_802C7718++;
        }
        arg0 = func_1B1FB0_802C71B8(arg0, *(arg1++), s1, arg4);
        arg2--;
        s1 += 0x10;
    }
    return arg0;
}

Gfx* func_1B1FB0_802C73B0(Gfx* gdl) {
    size_t i;

    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);

    gSPTexture(gdl++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(gdl++);
    gDPSetCycleType(gdl++, G_CYC_1CYCLE | 0x300000);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdl++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetAlphaCompare(gdl++, G_AC_NONE);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);

    for (i = 0; i < 2; i++) {
        gDPPipeSync(gdl++);
        gDPSetColorImage(gdl++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 640, VIRTUAL_TO_PHYSICAL2(D_800D45DC[i]));

        gDPSetFillColor(gdl++, 0x10001);
        gDPFillRectangle(gdl++, 0, 0, 639, 479);
    }

    return gdl;
}

void func_1B1FB0_802C7510(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 6;
    D_801CE638 = 0x13;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 3;
    D_800D461C = 2;
}

void* func_1B1FB0_802C7578(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {

    gSPTexture(arg0++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPPipeSync(arg0++);
    gDPSetCycleType(arg0++, G_CYC_1CYCLE);
    gDPSetPrimColor(arg0++, 0, 0, 0, 0, 0, arg5);
    gDPSetCombineMode(arg0++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(arg0++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetAlphaCompare(arg0++, G_AC_NONE);
    gDPFillRectangle(arg0++, arg1, arg2, arg3, arg4);

    return arg0;
}
