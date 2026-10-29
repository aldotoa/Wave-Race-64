#include "global.h"

extern s32 D_800D45DC[]; // array pointing to some mio0 adresses
extern u8 D_8000008[];

Gfx* func_1B1FB0_802C71B8(Gfx*, char, s32, s32);
extern s32 D_802C7718;

#ifdef NON_MATCHING
void func_1B1FB0_802C5800(void) {
    /* Flight mode debug camera controller */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C5800.s")
#endif

#ifdef NON_MATCHING
/* Flight mode terrain height lookup & boot/fade-in display list builder
 * PARKED at floor diff (6 instructions):
 * - 142 of 148 instructions match 100% byte-for-byte (all display lists, scissor,
 *   prim color, branch logic, function calls, stack frame, and epilogue match).
 * - Remaining gap: at 0x1E0, subu t9, t8, v1 vs retail subu t8, t8, v1.
 *   Writing as `v1 * 255` strength-reduces to `sll reg, v1, 8` + `subu reg, reg, v1`
 *   in isolation, but within this function uopt hoists the literal 255 to $a0 for CSE
 *   with the clamp and equality checks, emitting `multu v1, a0`. Writing as
 *   `((v1 << 8) - v1)` prevents the hoist but IDO allocates t9 for the subtract result.
 * - Load-bearing constructs:
 *   1) `D_1B1FB0_802C76F0 = ((v1 << 8) - v1) / 10; if ((u32)D_1B1FB0_802C76F0 >= 256) D_1B1FB0_802C76F0 = 255;`
 *      retains the branch delay slot store `sw v0, 0(a0)` and subsequent clamp store.
 *   2) Direct store `D_1B1FB0_802C76F4 = v1 + 1;` executes in delay slot of `bne v0, at`.
 *   3) Re-check `D_1B1FB0_802C76F4 >= 14` triggers reload `lw t2, 0(a1)` after `osViBlack`.
 */
Gfx* func_1B1FB0_802C73B0(Gfx* gdl);
Gfx* func_1B1FB0_802C62E4(Gfx* gdl);
Gfx* func_1B1FB0_802C6970(Gfx* gdl);
Gfx* func_1B1FB0_802C6C1C(Gfx* gdl);
Gfx* func_1B1FB0_802C6E40(Gfx* gdl, s32 arg1, s32 arg2);
void* func_1B1FB0_802C7578(Gfx* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void func_1B1FB0_802C5DF4(s32* arg0);
void func_801EB180(void);

extern s32 D_801CE63C;
extern s32 D_800DAB2C;
extern Gfx D_8066180[];
extern Gfx D_80661F8[];
extern Gfx D_8066A80[];
extern Gfx D_80671B8[];
extern s32 D_802C7710;
extern s32 D_1B1FB0_802C76A8;
extern s32 D_1B1FB0_802C76B4[];
extern s32 D_1B1FB0_802C76A4;
extern s32 D_1B1FB0_802C76AC;
extern s32 D_1B1FB0_802C76F0;
extern s32 D_1B1FB0_802C76F4;

Gfx* func_1B1FB0_802C5BA4(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_BOOT_UP) {
            return func_1B1FB0_802C73B0(gdl);
        }
    }

    D_800DAB2C = 0;
    gSPDisplayList(gdl++, D_8066180);
    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 0, 0, 639, 479);
    gSPDisplayList(gdl++, D_80661F8);

    gdl = func_1B1FB0_802C62E4(gdl);

    gSPDisplayList(gdl++, D_8066A80);
    gSPDisplayList(gdl++, D_80671B8);

    gdl = func_1B1FB0_802C6970(gdl);
    gdl = func_1B1FB0_802C6C1C(gdl);

    gDPSetPrimColor(gdl++, 0, 0, 255, D_802C7710, 0, 255);

    gdl = func_1B1FB0_802C6E40(gdl, D_1B1FB0_802C76B4[D_1B1FB0_802C76A8], 0x86);

    if (D_1B1FB0_802C76A4 == 2) {
        gdl = func_1B1FB0_802C6E40(gdl, D_1B1FB0_802C76B4[D_1B1FB0_802C76AC], 0x18A);
    }

    if (gGameState == GAME_STATE_6) {
        gdl = func_1B1FB0_802C7578(gdl, 0x40, 0x32, 0x240, 0x1B0, D_1B1FB0_802C76F0);
    }

    if (gGameState == GAME_STATE_BOOT_UP) {
        func_1B1FB0_802C5DF4(&D_1B1FB0_802C76F0);
        return gdl;
    }

    {
        s32 v1 = D_1B1FB0_802C76F4;
        D_1B1FB0_802C76F0 = ((v1 << 8) - v1) / 10;
        if ((u32) D_1B1FB0_802C76F0 >= 256) {
            D_1B1FB0_802C76F0 = 255;
        }
        D_1B1FB0_802C76F4 = v1 + 1;
        if (D_1B1FB0_802C76F0 == 255) {
            osViBlack(1);
        }
        if (D_1B1FB0_802C76F4 >= 14) {
            func_801EB180();
        }
    }

    return gdl;
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

extern u16 D_804A460[];

Gfx* func_1B1FB0_802C67BC(Gfx* gdl, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < 5; i++) {
        gDPLoadTextureBlock(gdl++, &D_804A460[i * 2048], G_IM_FMT_RGBA, G_IM_SIZ_16b, 512, 4, 0, G_TX_CLAMP,
                            G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, arg1 << 2, (arg2 + i * 4) << 2, (arg1 + 511) << 2, (arg2 + i * 4 + 3) << 2,
                            G_TX_RENDERTILE, 0, 0, 4 << 10, 1 << 10);
    }
    return gdl;
}

extern s32 D_1B1FB0_802C7660;
extern u8* D_1B1FB0_802C7664[];

Gfx* func_1B1FB0_802C6970(Gfx* gdl) {
    s32 i;
    u8* tex;

    for (i = 0, tex = D_1B1FB0_802C7664[D_1B1FB0_802C7660]; i < 8; i++) {
        gDPLoadTextureTile(gdl++, tex, G_IM_FMT_IA, G_IM_SIZ_8b, 360, 8, 0, 0, 359, 7, 0, G_TX_CLAMP, G_TX_CLAMP,
                           G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, 140 << 2, (i * 8 + 59) << 2, 500 << 2, (i * 8 + 67) << 2, G_TX_RENDERTILE, 0, 0,
                            1 << 10, 1 << 10);
        tex += 0xB40;
    }
    return gdl;
}

#ifdef NON_MATCHING
/* Debug flight HUD coordinates (137 instructions).
 * Emits variable iterations (1 to 3) of 10 8-byte RDP commands for HUD digit rendering.
 * Parked behind NON_MATCHING: loop-invariant hoisting and register allocator
 * scheduling across the 10 RDP word stores per iteration. */
Gfx* func_1B1FB0_802C6C1C(Gfx* gdl) {
    s32 count;
    s32 i;
    s32 t1;
    s32 t2;
    s32 val;
    s32 ten;

    val = D_801CB410;
    if (val < 10) {
        count = 1;
    } else if (val < 100) {
        count = 2;
    } else {
        count = 3;
    }

    i = 0;
    t1 = 0x230;
    t2 = 0x220;
    ten = 10;
    if (count > 0) {
        do {
            gdl->words.w0 = 0xFD700000;
            gdl->words.w1 = (u32) D_1B1FB0_802C767C[val % ten];
            gdl++;

            gdl->words.w0 = 0xF5700000;
            gdl->words.w1 = 0x07080200;
            gdl++;

            gdl->words.w0 = 0xE6000000;
            gdl->words.w1 = 0;
            gdl++;

            gdl->words.w0 = 0xF3000000;
            gdl->words.w1 = 0x0708F400;
            gdl++;

            gdl->words.w0 = 0xE7000000;
            gdl->words.w1 = 0;
            gdl++;

            gdl->words.w0 = 0xF5680400;
            gdl->words.w1 = 0x00080200;
            gdl++;

            gdl->words.w0 = 0xF2000000;
            gdl->words.w1 = 0x0003C044;
            gdl++;

            gdl->words.w0 = 0xE4000608 | (((t1 * 4) & 0xFFF) << 12);
            gdl->words.w1 = (((t2 * 4) & 0xFFF) << 12) | 0x5C0;
            gdl++;

            gdl->words.w0 = 0xB3000000;
            gdl->words.w1 = 0;
            gdl++;

            gdl->words.w0 = 0xB2000000;
            gdl->words.w1 = 0x04000400;
            gdl++;

            i++;
            val /= ten;
            t2 -= 18;
            t1 -= 18;
        } while (i != count);
    }

    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/unused_code_1B1FB0/func_1B1FB0_802C6C1C.s")
#endif

extern u8 D_8008510[];

/* Debug flight telemetry banner: four IA8 192x11 strips stacked at (arg1, arg2). */
Gfx* func_1B1FB0_802C6E40(Gfx* gdl, s32 arg1, s32 arg2) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gdl++, &D_8008510[i * 0x840], G_IM_FMT_IA, G_IM_SIZ_8b, 192, 11, 0, 0, 191, 10, 0,
                           G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, arg1 << 2, (arg2 + i * 11) << 2, (arg1 + 192) << 2, (arg2 + i * 11 + 11) << 2,
                            G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}

extern u8 D_800A618[];
extern s32 D_1B1FB0_802C76B0;

/* Debug text banner: four IA8 496x5 strips stacked at y = 248 + D_1B1FB0_802C76B0 * 20. */
Gfx* func_1B1FB0_802C6FF8(Gfx* gdl) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gDPLoadTextureTile(gdl++, &D_800A618[i * 0x9B0], G_IM_FMT_IA, G_IM_SIZ_8b, 496, 5, 0, 0, 495, 4, 0,
                           G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, 72 << 2, (D_1B1FB0_802C76B0 * 20 + i * 5 + 248) << 2, 568 << 2,
                            (D_1B1FB0_802C76B0 * 20 + i * 5 + 253) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }
    return gdl;
}

/* Debug text character renderer: emits one IA8 16x16 glyph at (arg2, arg3)
   and returns the advanced display list. Values below 0x10 emit nothing;
   values at or above 0x42 use glyph 0x3B. */
Gfx* func_1B1FB0_802C71B8(Gfx* gdl, char arg1, s32 arg2, s32 arg3) {
    if (arg1 < 0x10) {
        return gdl;
    }
    if (arg1 >= 0x42) {
        arg1 = 0x3B;
    }
    // Self-assignments are load-bearing: they shift the texrect cursor registers.
    arg2 = arg2;
    arg3 = arg3;
    arg1 -= 0x10;
    gDPLoadTextureBlock(gdl++, &D_8000008[arg1 << 8], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 16, 0, G_TX_CLAMP, G_TX_CLAMP,
                        G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gdl++, arg2 << 2, arg3 << 2, (arg2 + 16) << 2, (arg3 + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10,
                        1 << 10);
    return gdl;
}

s32 func_1B1FB0_802C7304(s32 arg0, s8* arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 s1 = arg3;

    D_802C7718 = 0;

    while (arg2) {
        if (*arg1 != 0) {
            D_802C7718++;
        }
        arg0 = (s32)func_1B1FB0_802C71B8((Gfx*)arg0, *(arg1++), s1, arg4);
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
