#include "common.h"

#ifdef NON_MATCHING
void func_i2_802C5800(void) {
    /* Secondary course navigation engine initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C5800.s")
#endif

struct SelectionState {
    s32 player_1_ready;
    s32 player_2_ready;
};

extern struct SelectionState D_802C8C58;
extern s32 D_802C8C60[];
s16 D_802C8C70[4];
extern s16 D_802C8C68;
extern s16 D_802C8C6A;

void func_i2_802C5AE4(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        ((s32*) &D_802C8C58)[i] = 0;
        D_802C8C60[i] = 0;
        D_801CE6F4[i] = i;
    }

    for (i = 0; i < 4; i++) D_802C8C70[i] = 0;
    D_802C8C68 = 0;
    D_802C8C6A = 0;
}

void* func_8007C31C();
void* func_801EB91C();
void* func_i2_802C5E28();
void* func_i2_802C6ADC(Gfx*);
Gfx* func_i2_802C7C50(Gfx*);
Gfx* func_i2_802C88DC(Gfx*);
extern Gfx* D_106F808;
extern Gfx D_106FAF0[];
extern Vtx* D_2000A40;
extern Mtx* D_7000000;
extern s16 D_801CE60C;
extern s32 D_802C8C5C;
extern Gfx D_80BE4A8[];
extern Gfx D_80BE500[];
extern s32 D_i2_802C8BC0;
extern s32 D_i2_802C8BD8[];

Gfx* func_i2_802C5B4C(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_RIDER_SELECT) {
            return func_80093C44(gdl);
        }
    }

    D_800DAB2C = 0;

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);
    gSPDisplayList(gdl++, &D_106FAF0);

    gdl = func_i2_802C88DC(gdl);
    gSPMatrix(gdl++, &D_7000000, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPMatrix(gdl++, &D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, &D_106F808);

    if (D_801CE60C == 1) {
        gdl = func_8009328C(gdl);
    } else {
        if (D_802C8C58.player_1_ready == 0) {
            D_800DAB2C = 0;
            gdl = func_800933C4(gdl);
        }
        if (D_802C8C5C == 0) {
            D_800DAB2C = 1;
            gdl = func_800933C4(gdl);
        }
        D_800DAB2C = 0;
    }

    gDPPipeSync(gdl++);
    gDPSetScissor(gdl++, G_SC_NON_INTERLACE, 8, 20, 311, 219);

    if (D_801CE60C == 1) {
        gdl = func_i2_802C6ADC(gdl);
        gSPDisplayList(gdl++, &D_80BE500);
    } else {
        gdl = func_i2_802C7C50(gdl);
        if (D_802C8C58.player_1_ready == 0) {
            gSPDisplayList(gdl++, &D_80BE4A8);
        }
        if (D_802C8C58.player_2_ready == 0) {
            gSPDisplayList(gdl++, &D_80BE500);
        }
    }
    if (gGameState == GAME_STATE_RIDER_SELECT) {
        func_i2_802C5E28();
        if (D_80228A16 == 1) {
            D_i2_802C8BC0 = 1;
        }
    } else if (D_80228A16 == 1) {
        func_8007C31C();
        switch (D_801CE630) {
            case 2:
                func_801EB180();
                break;
            case 30:
                func_801EB91C();
                break;
            case 20:
                func_801EBFE4();
                break;
        }
    }
    return gdl;
}

#ifdef NON_MATCHING
void* func_i2_802C5E28(void) {
    /* Secondary course buoy proximity checking and navigation */
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C5E28.s")
#endif

s32 func_i2_802C676C(s32 player, s32 param) {
    s32 ret = 1;
    UnkStruct_func_i8_802C6E00 (*arr)[4] = (UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298;
    s32 idx = D_i2_802C8BD8[D_800DA9C0[player]];

    arr[player][idx].unk_B[param]--;
    if (arr[player][idx].unk_B[param] < 0) {
        ret = 0;
        arr[player][idx].unk_B[param] = 0;
    }
    return ret;
}

s32 func_i2_802C67E4(s32 player, s32 param) {
    s32 ret = 1;
    UnkStruct_func_i8_802C6E00 (*arr)[4] = (UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298;
    s32 idx = D_i2_802C8BD8[D_800DA9C0[player]];

    arr[player][idx].unk_B[param]++;
    if (arr[player][idx].unk_B[param] == 12) {
        ret = 0;
        arr[player][idx].unk_B[param] = 11;
    }
    return ret;
}

#ifdef NON_MATCHING
void func_i2_802C6864(void) {
    /* Power level increment on consecutive buoy passes */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C6864.s")
#endif

#ifdef NON_MATCHING
void* func_i2_802C6ADC(Gfx* gdl) {
    /* Buoy navigation HUD marker renderer */
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C6ADC.s")
#endif

#ifdef NON_MATCHING
void func_i2_802C70EC(void) {
    /* Buoy miss count accumulator and engine power cut penalty */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C70EC.s")
#endif

#ifdef NON_MATCHING
Gfx* func_i2_802C7C50(Gfx* gdl) {
    /* Course 3D buoy models display list emitter */
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C7C50.s")
#endif

#ifdef NON_MATCHING
void func_i2_802C84EC(void) {
    /* Buoy floating collision volume update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C84EC.s")
#endif

#ifdef NON_MATCHING
void func_i2_802C86E4(void) {
    /* Course lap split time trigger */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C86E4.s")
#endif

#ifdef NON_MATCHING
Gfx* func_i2_802C88DC(Gfx* gdl) {
    /* Finish line archway display list emitter */
    return gdl;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C88DC.s")
#endif

#ifdef NON_MATCHING
s32 D_i2_802C8BE0 = 0;
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/D_i2_802C8BE0.s")
#endif
