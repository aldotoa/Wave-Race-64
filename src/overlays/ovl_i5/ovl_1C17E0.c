#include "common.h"

#ifdef NON_MATCHING
Gfx* func_i5_802C7090(Gfx* arg0) {
    /* Course floating buoys and navigation arrow display list */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C7090.s")
#endif

Gfx* func_i5_802C7594(Gfx*);
Gfx* func_i5_802C7698(Gfx*);
void func_i5_802C781C(void);
Gfx* Gfx_DrawCoursePanel(Gfx*, s32);
extern s32 D_i5_802C7AC8;
extern s32 D_i5_802C7ACC;
extern s32 D_i5_802C7AD0;
extern s32 D_802C7B30;
extern s32 D_802C7B34;
Gfx* func_801EB00C(Gfx*, s32, s32, s32, s32);
extern Mtx D_8011F820;

Gfx* func_i5_802C7484(Gfx* glistp) {
    /* Port Blue race frame: clears the buffer, fills the course color, draws
     * buoys when the tide state calls for them, then appends the course
     * panel, water effects, and results panels before the attract tail. */
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }

    glistp = Gfx_ClearCurrentBuffer(glistp);

    D_800DAB2C = 0;

    glistp = Gfx_FillCourseColor(glistp, gCourseID);
    glistp = func_8008FB74(glistp);

    if (D_i5_802C7AC8 == 2 || D_i5_802C7AC8 == 3 || D_i5_802C7AC8 == 4) {
        glistp = func_i5_802C7594(glistp);
    }

    gSPMatrix(glistp++, &D_8011F820, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    glistp = Gfx_DrawCoursePanel(glistp, gCourseID);
    glistp = Draw_WaterEffects(glistp);
    glistp = func_i5_802C7698(glistp);

    if (gGameState == GAME_STATE_5A) {
        func_i5_802C781C();
    } else if (D_80228A16 == 1) {
        func_801EB180();
    }

    return glistp;
}

extern u32 D_106F6C0;
extern u32 D_i5_802C7AA8[];
extern u32 D_7001380;
extern u32 D_70013C0;
extern u32 D_7001400;
extern u32 D_7001440;
extern u32 D_7001640;

Gfx* func_i5_802C7594(Gfx* arg0) {
    Gfx* v0;
    Gfx* v1;
    u32 var_a1;
    u32* src;
    u32 var_a3;
    u32 var_t0;
    u8* var_t1;
    u8* var_t4;

    /* clang-format off */
    v0 = arg0++; v0->words.w0 = 0x06000000; v0->words.w1 = (u32)&D_106F6C0; v1 = 0;
    var_a1 = (u32) &D_7001380; src = D_i5_802C7AA8; var_a3 = (u32) &D_70013C0; var_t0 = (u32) &D_7001400; var_t1 = (u8*) &D_7001440; var_t4 = (u8*) &D_7001640; loop:
    /* clang-format on */
    v0 = arg0++;
    v0->words.w0 = 0x01020040;
    v0->words.w1 = var_a1;
    v1 = arg0++;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[0];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = var_a3;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[1];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = var_t0;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[2];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = (u32) var_t1;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[3];

    var_t1 += 0x100;
    var_t0 += 0x100;
    var_a3 += 0x100;
    var_a1 += 0x100;
    src += 4;
    if (var_t1 != var_t4) {
        goto loop;
    }
    return arg0;
}

Gfx* func_i5_802C7698(Gfx* glistp) {
    /* Draws the two Port Blue leaderboard panels: frames, full-bright text
     * rows, position numbers, and the two course-record lines. */
    gSPDisplayList(glistp++, D_106F628);
    glistp = Menu_DrawFrame(glistp, 0, D_i5_802C7ACC, 0x91, 0xD0, 0xF);
    glistp = Menu_DrawFrame(glistp, 0, D_i5_802C7AD0, 0xA6, 0xD0, 0xF);
    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 1, 6, D_i5_802C7ACC + 10, 0x93, 0);
    glistp = func_801E3EE0(glistp, 1, 7, D_i5_802C7AD0 + 10, 0xA8, 0);
    glistp = func_801EB00C(glistp, 2, D_802C7B34, D_i5_802C7ACC + 0xBA, 0x93);
    return func_801EB00C(glistp, 2, D_802C7B30, D_i5_802C7AD0 + 0xBA, 0xA8);
}

#ifdef NON_MATCHING
void func_i5_802C781C(void) {
    /* Buoy miss penalty check */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/func_i5_802C781C.s")
#endif

void func_i5_802C79F4(void) {
}

#ifdef NON_MATCHING
s32 D_i5_802C7AA0[2] = { 0, 0 };
u32 D_i5_802C7AA8[8] = {
    0x0808EB68, 0x08091C40, 0x080924E0, 0x0808F878, 0x08092D80, 0x080940A0, 0x0808FE58, 0x08091C40
};
s32 D_i5_802C7AC8 = 0;
s32 D_i5_802C7ACC = 0;
s32 D_i5_802C7AD0 = 0;
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
#endif
