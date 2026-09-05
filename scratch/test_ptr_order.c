#include <ultra64.h>
extern s32 D_800DA9C8[];
extern s32 D_802C8C58[];
extern s32 D_800DA9C0[];
extern s32 D_i2_802C8BD8[];
extern s16 D_801CE60C;
extern u8 D_801CB298[];
extern u16 D_80B6518[];
extern u8 D_80BBFA8[];
typedef struct { u8 pad[0x0B]; s8 unk_B[3]; } UnkStruct_func_i8_802C6E00;
extern UnkStruct_func_i8_802C6E00 D_800DA950[];
Gfx* func_801E3EE0(Gfx* gdl, s32, s32, s32, s32, s32);
Gfx* func_801E946C(Gfx* gdl, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
Gfx* func_801E9858(Gfx* gdl, s32, void*, s32, s32);

Gfx* func_i2_802C70EC(Gfx* gdl, s32 player) {
    s32 show_stats;
    s32 show_banner;
    s32 show_name;
    s32 spE8;
    s32 spE4;
    UnkStruct_func_i8_802C6E00* ptr;
    s32 x_pos;
    s32 x_name;
    s32 ready;

    if (player == 0) {
        x_pos = 0x13;
    } else {
        x_pos = 0x99;
    }

    if ((D_800DA9C8[player] == 0) || (D_802C8C58[player] == 0)) {
        ptr = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]];
        ready = D_802C8C58[player];
    } else {
        ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[player][D_i2_802C8BD8[D_800DA9C0[player]]];
    }

    show_stats = 0;
    show_banner = 0;
    show_name = 0;
    spE8 = 0;
    spE4 = 0;

    if (D_802C8C58[player] >= 2) {
        spE8 = 1;
    }
    if ((D_802C8C58[player] > 0) && (D_802C8C58[player] != 6)) {
        spE4 = 1;
    }

    if (D_801CE60C == 1) {
        if (D_802C8C58[player] != 5) {
            show_stats = 1;
        }
        show_banner = 1;
        show_name = 1;
        x_name = x_pos + 0xA1;
    } else {
        if ((D_802C8C58[player] > 0) && (D_802C8C58[player] < 5)) {
            show_stats = 1;
        }
        if (D_802C8C58[player] > 0) {
            show_banner = 1;
        }
        if (D_802C8C58[player] == 0) {
            show_name = 1;
        }
        x_name = x_pos + 0x1B;
    }

    if (show_stats != 0) {
        gDPPipeSync(gdl++);
        gDPSetRenderMode(gdl++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPLoadTextureTile(gdl++, D_80B6518, G_IM_FMT_RGBA, G_IM_SIZ_16b, 9, 6, 0, 0, 8, 5, 0,
                           G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gSPTextureRectangle(gdl++, ((ptr->unk_B[0] * 10) + x_pos + 0xE) << 2, 0x93 << 2,
                            ((ptr->unk_B[0] * 10) + x_pos + 0x17) << 2, 0x99 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gdl++, ((ptr->unk_B[1] * 10) + x_pos + 0xE) << 2, 0xB0 << 2,
                            ((ptr->unk_B[1] * 10) + x_pos + 0x17) << 2, 0xB6 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
        gSPTextureRectangle(gdl++, ((ptr->unk_B[2] * 10) + x_pos + 0xE) << 2, 0xCD << 2,
                            ((ptr->unk_B[2] * 10) + x_pos + 0x17) << 2, 0xD3 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    gdl = func_801E946C(gdl, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

    if (player == 0) {
        gdl = func_801E3EE0(gdl, 2, 3, 0x26, 0x1C, 0);
        gdl = func_801E3EE0(gdl, 4, 0xC, 0xDE, 0x1A, 0);
        gdl = func_801E3EE0(gdl, 4, 0xD, 0xDE, 0x25, 0);
    }

    if (show_stats != 0) {
        if ((D_802C8C58[player] != 2) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 6, x_pos + 0xD, 0x8A, 0);
        gdl = func_801E3EE0(gdl, 0, 7, x_pos + 0x62, 0x8A, 0);

        if ((D_802C8C58[player] != 3) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 9, x_pos + 0xD, 0xA7, 0);
        gdl = func_801E3EE0(gdl, 0, 0xA, x_pos + 0x59, 0xA7, 0);

        if ((D_802C8C58[player] != 4) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xA, x_pos + 0xD, 0xB9, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 0xC, x_pos + 0xD, 0xC4, 0);
        gdl = func_801E3EE0(gdl, 0, 0xB, x_pos + 0x67, 0xC4, 0);
    }

    if (show_name != 0) {
        if (player == 0) {
            gdl = func_801E9858(gdl, 1, ((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[0][D_i2_802C8BD8[D_800DA9C0[player]]].unk_B, x_name, 0xCB);
        } else {
            gdl = func_801E9858(gdl, 1, D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]].unk_B, x_name, 0xCB);
        }
    }

    if (show_banner != 0) {
        gdl = func_801E3EE0(gdl, 0, 0x25, x_pos + 0xC, 0x62, 0);
        if ((D_800DA9C8[player] != 0) || (spE4 == 0)) {
            gdl = func_801E3EE0(gdl, 0, 3, x_pos + 0x15, 0x70, 0);
        }
        if ((D_800DA9C8[player] != 1) || (spE4 == 0)) {
            gdl = func_801E3EE0(gdl, 0, 0x26, x_pos + 0x54, 0x70, 0);
        }
    }

    if (D_802C8C58[player] >= 5) {
        gdl = func_801E946C(gdl, (D_802C8C58[player] == 5) ? 6 : 7, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPLoadTextureTile(gdl++, D_80BBFA8, G_IM_FMT_IA, G_IM_SIZ_8b, 87, 22, 0, 0, 86, 21, 0,
                           G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, (x_pos + 0x1D) << 2, 0xA2 << 2,
                            (x_pos + 0x75) << 2, 0xAC << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    gdl = func_801E946C(gdl, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

    if (show_stats != 0) {
        if ((D_802C8C58[player] == 2) && (spE8 != 0)) {
            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
        }
        if ((D_802C8C58[player] == 3) && (spE8 != 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
        }
        if ((D_802C8C58[player] == 4) && (spE8 != 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xA, x_pos + 0xD, 0xB9, 0);
        }
    }

    if (show_banner != 0) {
        if ((D_800DA9C8[player] == 0) && (spE4 != 0)) {
            gdl = func_801E3EE0(gdl, 0, 3, x_pos + 0x15, 0x70, 0);
        }
        if ((D_800DA9C8[player] == 1) && (spE4 != 0)) {
            gdl = func_801E3EE0(gdl, 0, 0x26, x_pos + 0x54, 0x70, 0);
        }
    }

    return gdl;
}
