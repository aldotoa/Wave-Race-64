#include "common.h"

struct SelectionState {
    s32 player_1_ready;
    s32 player_2_ready;
};

Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y);
Gfx* func_i2_802C70EC(Gfx* gdl, s32 player);
Gfx* func_801E4FE8(Gfx* gdl, s32 a1, s32 a2, s32 a3, void* a4);

extern Gfx D_80BE248[];
extern Gfx D_80BE2B8[];
extern u8 D_80B6590[];
extern s16 D_i2_802C8BD0[];
extern s16 D_802C8C6A;
extern s16 D_802C8C68;
extern struct SelectionState D_802C8C58;
extern s32 D_800DA9C0[];
extern Vp D_802C8C50;
extern Mtx D_7000A40;
extern Mtx D_7000A80;
extern Mtx D_7000AC0;
extern Mtx D_7000B00;
extern Mtx D_7000B40;
extern Gfx D_106F488[];
extern Gfx D_80BE468[];
extern Gfx D_80BE478[];
extern Gfx D_80BE488[];
extern Gfx D_80BE498[];

Gfx* func_i2_802C6ADC(Gfx* gdl) {
    u32 alpha;
    f32 f4 = 4.0f;

    gSPDisplayList(gdl++, &D_80BE248);
    gSPDisplayList(gdl++, D_106F628);
    gdl = func_80094338(gdl, 0, 0x1C, 0x16, 0x108, 0x1E);
    gdl = func_80094338(gdl, 0, 0x1C, 0x60, 0x82, 0xD);
    gdl = func_80094338(gdl, 0, 0x20, 0x6E, 0x3B, 0xD);
    gdl = func_80094338(gdl, 0, 0x5F, 0x6E, 0x3B, 0xD);
    gdl = func_i2_802C86E4(gdl, 0x13, 0x68);

    if (D_802C8C58.player_1_ready != 5) {
        gSPDisplayList(gdl++, &D_80BE2B8);
    }

    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(gdl++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);

    if (D_802C8C6A == 0) {
        alpha = (u32) ((D_802C8C68 * 255.0f) / f4);
    } else {
        alpha = (u32) (((f4 - D_802C8C68) * 255.0f) / f4);
    }

    D_802C8C68++;
    if (D_802C8C68 >= 4) {
        D_802C8C68 = 0;
        D_802C8C6A ^= 1;
    }

    gDPSetPrimColor(gdl++, 0, 0, alpha, 255, alpha, 255);
    gDPLoadTextureTile(gdl++, D_80B6590, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 64 - 1, 36 - 1, 0,
                       G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gdl++, 55 << 2, (D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2, 91 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[0]] + 72) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gdl = func_i2_802C70EC(gdl, 0);

    gSPViewport(gdl++, &D_802C8C50);
    gSPMatrix(gdl++, &D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(gdl++, &D_106F488);
    gSPDisplayList(gdl++, &D_80BE468);
    gSPMatrix(gdl++, &D_7000A80, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 0, 0, 0, (u8*) D_801CE5F8 + 0xC80);

    gSPDisplayList(gdl++, &D_80BE478);
    gSPMatrix(gdl++, &D_7000AC0, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 2, 0, 0, (u8*) D_801CE5F8 + 0xD40);

    gSPDisplayList(gdl++, &D_80BE488);
    gSPMatrix(gdl++, &D_7000B00, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gdl = func_801E4FE8(gdl, 3, 0, 0, (u8*) D_801CE5F8 + 0xE00);

    gSPDisplayList(gdl++, &D_80BE498);
    gSPMatrix(gdl++, &D_7000B40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    return func_801E4FE8(gdl, 1, 0, 0, (u8*) D_801CE5F8 + 0xEC0);
}
