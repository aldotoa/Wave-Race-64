#include "common.h"
#include "sys_utils.h"

extern u16 D_802C8C50;
extern s32 D_802C8C60[];
extern f32 gSinTable[];
extern s32 D_800DA9C0[];
void func_i2_802C5AE4(void);

void func_i2_802C5800(void) {
    s32 angle;
    s32 cond;
    s32 j;
    f32 var_fs1;
    f32 var_fs2;
    MtxF sp1A4;
    MtxF sp164;
    MtxF sp124;
    Mtx spE0;
    Mtx spA0;
    s32 i;

    if (D_801CE63C != 0) {
        if (gGameState == GAME_STATE_RIDER_SELECT) {
            func_i2_802C5AE4();
        }
    }

    func_800481E0(D_801CE5F8->unkA40, &D_802C8C50, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spE0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.07f);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < D_801CE608.player; j++) {
            cond = 0;
            if (i == D_800DA9C0[j]) {
                cond = 1;
            }
            if (cond) {
                angle = D_802C8C60[j] % 0x1000;
                var_fs1 = gSinTable[(angle + 0x400) & 0xFFF] * 500.0f;
                var_fs2 = gSinTable[angle & 0xFFF] * 500.0f;
            } else {
                var_fs1 = gSinTable[0x600] * 500.0f;
                var_fs2 = gSinTable[0x200] * 500.0f;
            }
            if (cond) {
                break;
            }
        }

        func_800484C8(&spA0, &sp164, var_fs1, 500.0f, var_fs2, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        SysUtils_MtxToMtxF(&spE0, &sp1A4);
        SysUtils_MatrixAffineMultiply(&sp164, &sp1A4, &sp124);
        SysUtils_MtxFToMtx(&sp124, &D_801CE5F8->unkA80[i]);
    }

    for (i = 0; i < D_801CE608.player; i++) {
        D_802C8C60[i] += 0x30;
        if (D_802C8C60[i] >= 0x1000) {
            D_802C8C60[i] -= 0x1000;
        }
    }
}

struct SelectionState {
    s32 player_1_ready;
    s32 player_2_ready;
};

extern union {
    struct {
        s32 player_1_ready;
        s32 player_2_ready;
    };
    s32 as_array[2];
} D_802C8C58;

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

    /* clang-format off */
    for (i = 0; i < 4; i++) D_802C8C70[i] = 0;
    /* clang-format on */
    D_802C8C68 = 0;
    D_802C8C6A = 0;
}

void* func_8007C31C(void);
void* func_801EB91C(void);
u32 func_i2_802C5E28(void);
s32 func_i2_802C676C(s32 player, s32 param);
s32 func_i2_802C67E4(s32 player, s32 param);
void func_i2_802C6864(s32 player);
extern s32 D_i2_802C8BB0[];
extern s32 D_i2_802C8BB8[];
extern UnkStruct_801CE658 D_801CE658[];
extern s16 D_80228A32;
extern s32 D_801CB32C;
extern s16 D_800DAB60;
extern s16 D_800DAB64;
Gfx* func_i2_802C6ADC(Gfx*);
Gfx* func_i2_802C7C50(Gfx*);
Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y);
void func_i2_802C84EC(s32);
Gfx* func_i2_802C88DC(Gfx*);
void func_800C1F60(s32);
extern u16 D_80B0008[];
extern u16 D_80B77A0[];
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
extern s32 D_800DA9C8[];
extern s32 D_800D48E0;
extern s32 D_800D48DC;
extern s32 D_800DA9B0[];
Gfx* func_i2_802C70EC(Gfx* gdl, s32 player);
Gfx* func_801E4FE8(Gfx* gdl, s32 a1, s32 a2, s32 a3, void* a4);
Gfx* func_801E9858(Gfx* gdl, s32 a1, void* a2, s32 a3, s32 a4);
Gfx* func_801E946C(Gfx* gdl, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
Gfx* func_801E3EE0(Gfx* gdl, s32, s32, s32, s32, s32);
extern Gfx D_80BE248[];
extern Gfx D_80BE2B8[];
extern Gfx D_80BE358[];
extern Gfx D_80BE3C8[];
extern u8 D_80B6590[];
extern u8 D_80B6E98[];
extern u8 D_80B6518[];
extern u8 D_80BBFA8[];
extern s16 D_i2_802C8BD0[];
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

Gfx* func_i2_802C5B4C(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == GAME_STATE_RIDER_SELECT) {
            return Gfx_ClearFrameBuffers(gdl);
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
        gdl = Game_BuildRaceScene(gdl);
    } else {
        if (D_802C8C58.player_1_ready == 0) {
            D_800DAB2C = 0;
            gdl = Game_BuildRaceViewport(gdl);
        }
        if (D_802C8C5C == 0) {
            D_800DAB2C = 1;
            gdl = Game_BuildRaceViewport(gdl);
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
#define ARR_VAL(arr) (*(s32*)((u8*)(arr) + offset))
#define ARR_PTR(arr) ((s32*)((u8*)(arr) + offset))

u32 func_i2_802C5E28() {
    s32 player;
    s32 offset;
    s32 can_select;
    s32 rider_idx;
    s32* s1;
    s32 sound_mode;
    s32* s2;
    s32* s5;

    player = 0;
    if (D_801CE60C > 0) {
        s2 = D_802C8C58.as_array;
        do {
            UnkStruct_801CE658* s6;
            u16 pressed;
            s32 v0;
            if (player == 0) {
                rider_idx = D_800D48DC;
                v0 = 0;
            } else {
                rider_idx = D_800D48E0;
                v0 = 1;
            }
            s6 = &D_801CE658[v0];
            pressed = s6->unk_00.unk_2;
            offset = player * 4;

            if ((pressed & 0xB000) && (D_i2_802C8BC0 != 0)) {
                sound_mode = 1;
                switch (*s2) {
                    case 0:
                        *s2 = 1;
                        if ((D_800DAB64 != 0) && (pressed & 0x2000)) {
                            D_801CE6F4[player] = 1;
                        }
                        if (D_801CE6F4[player] != 0) {
                            D_802C8C70[D_800DA9C0[player]] |= 2;
                        } else {
                            D_802C8C70[D_800DA9C0[player]] |= 1;
                        }
                        break;
                    case 1:
                        if (ARR_VAL(D_800DA9C8) == 0) {
                            s32 mode = D_801CE608.gameMode;
                            if (player == 0) {
                                D_801CB32C = 0;
                            }
                            if ((mode == 0) || (mode == 11)) {
                                func_i2_802C6864(player);
                                sound_mode = 2;
                            } else {
                                *s2 = 5;
                            }
                        } else {
                            if (player == 0) {
                                D_801CB32C = 1;
                            }
                            *s2 = 2;
                        }
                        break;
                    case 2:
                        *s2 = 3;
                        break;
                    case 3:
                        *s2 = 4;
                        break;
                    case 4: {
                        s32 mode = D_801CE608.gameMode;
                        if ((mode == 0) || (mode == 11)) {
                            func_i2_802C6864(player);
                            sound_mode = 2;
                        } else {
                            *s2 = 5;
                        }
                        break;
                    }
                    case 5:
                        func_i2_802C6864(player);
                        break;
                }

                if (sound_mode != 0) {
                    if (D_80228A32 == 1) {
                        AudioGeneral_PlaySound(0x2A, 0);
                    } else if (sound_mode == 1) {
                        AudioGeneral_PlaySound(0x11, 0);
                    } else {
                        AudioGeneral_PlaySound(0x37, 0);
                    }
                }
            } else if (pressed & 0x4000) {
                sound_mode = 1;
                switch (*s2) {
                    case 0:
                        func_i2_802C84EC(2);
                        break;
                    case 1:
                        *s2 = 0;
                        if (D_801CE6F4[player] != 0) {
                            D_802C8C70[D_800DA9C0[player]] &= ~2;
                        } else {
                            D_802C8C70[D_800DA9C0[player]] &= ~1;
                        }
                        break;
                    case 5:
                        if (ARR_VAL(D_800DA9C8) == 0) {
                            *s2 = 1;
                        } else {
                            *s2 = 4;
                        }
                        break;
                    case 2:
                        *s2 = 1;
                        break;
                    case 3:
                        *s2 = 2;
                        break;
                    case 4:
                        *s2 = 3;
                        break;
                    default:
                        sound_mode = 0;
                        break;
                }

                if (sound_mode != 0) {
                    AudioGeneral_PlaySound(0x16, 0);
                }
            } else {
                s32 is_p2_same = 1;
                if (pressed & 0xF) {
                    s32 char_idx = D_i2_802C8BD8[ARR_VAL(D_800DA9C0)];
                    UnkStruct_func_i8_802C6E00 (*arr)[4] = (UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298;
                    switch (*s2) {
                        case 2:
                            arr[player][char_idx].unk_B[0] = D_800DA950[char_idx].unk_B[0];
                            break;
                        case 3:
                            arr[player][char_idx].unk_B[1] = D_800DA950[char_idx].unk_B[1];
                            break;
                        case 4:
                            arr[player][char_idx].unk_B[2] = D_800DA950[char_idx].unk_B[2];
                            break;
                    }
                } else {
                    s32 state;
                    s1 = &D_i2_802C8BB0[player];
                    s5 = &D_i2_802C8BB8[player];
                    can_select = 0;
                    if ((gPlayers != ONE_PLAYER) && (D_800DA9C0[0] == D_800DA9C0[1])) {
                        is_p2_same = 0;
                    }

                    state = *s2;
                    if (state == 0) {
                        if (is_p2_same != 0) {
                            if (s6->unk_00.unk_0 & 0x800) {
                                can_select = 1;
                                D_801CE6F4[player] = player ^ 1;
                            } else {
                                D_801CE6F4[player] = player;
                            }
                        } else {
                            s32 c = D_802C8C70[ARR_VAL(D_800DA9C0)];
                            if (c == 0) {
                                D_801CE6F4[player] = player;
                            } else if (c & 1) {
                                D_801CE6F4[player] = 1;
                            } else {
                                D_801CE6F4[player] = 0;
                            }
                        }

                        if ((D_800DAB60 != 0) && (D_801CE60C == 1)) {
                            if (s6->unk_00.unk_0 & 0x400) {
                                D_800DAB64 = 1;
                            } else {
                                D_800DAB64 = 0;
                            }
                        }
                    }

                    *s1 = 0;
                    if (pressed & 0x200) {
                        sound_mode = 1;
                        switch (state) {
                            case 0: {
                                s32* p = ARR_PTR(D_800DA9C0);
                                s32* q = ARR_PTR(D_802C8C60);
                                if (can_select != 0) {
                                    sound_mode = 0;
                                } else {
                                    if (--(*p) < 0) {
                                        *p = 3;
                                    }
                                    *q = 0x200;
                                }
                                break;
                            }
                            case 1:
                                {
                                    s32* p = ARR_PTR(D_800DA9C8);
                                    if (--(*p) < 0) {
                                        *p = 1;
                                    }
                                }
                                break;
                            case 2:
                                *s1 = 1;
                                sound_mode = func_i2_802C676C(player, 0);
                                break;
                            case 3:
                                *s1 = 1;
                                sound_mode = func_i2_802C676C(player, 1);
                                break;
                            case 4:
                                *s1 = 1;
                                sound_mode = func_i2_802C676C(player, 2);
                                break;
                            default:
                                sound_mode = 0;
                                break;
                        }

                        if (sound_mode != 0) {
                            AudioGeneral_PlaySound(0x10, 0);
                        }
                    } else if (pressed & 0x100) {
                        sound_mode = 1;
                        switch (state) {
                            case 0: {
                                s32* p = ARR_PTR(D_800DA9C0);
                                s32* q = ARR_PTR(D_802C8C60);
                                if (can_select != 0) {
                                    sound_mode = 0;
                                } else {
                                    if (++(*p) == 4) {
                                        *p = 0;
                                    }
                                    *q = 0x200;
                                }
                                break;
                            }
                            case 1:
                                {
                                    s32* p = ARR_PTR(D_800DA9C8);
                                    if (++(*p) == 2) {
                                        *p = 0;
                                    }
                                }
                                break;
                            case 2:
                                *s1 = 1;
                                sound_mode = func_i2_802C67E4(player, 0);
                                break;
                            case 3:
                                *s1 = 1;
                                sound_mode = func_i2_802C67E4(player, 1);
                                break;
                            case 4:
                                *s1 = 1;
                                sound_mode = func_i2_802C67E4(player, 2);
                                break;
                            default:
                                sound_mode = 0;
                                break;
                        }

                        if (sound_mode != 0) {
                            AudioGeneral_PlaySound(0x10, 0);
                        }
                    }

                    if (*s1 != 0) {
                        *s5 = -3;
                    } else {
                        if (++(*s5) >= 4) {
                            *s5 = 0;
                            if (s6->unk_00.unk_0 & 0x200) {
                                switch (*s2) {
                                    case 2:
                                        sound_mode = func_i2_802C676C(player, 0);
                                        break;
                                    case 3:
                                        sound_mode = func_i2_802C676C(player, 1);
                                        break;
                                    case 4:
                                        sound_mode = func_i2_802C676C(player, 2);
                                        break;
                                    default:
                                        sound_mode = 0;
                                        break;
                                }
                                if (sound_mode != 0) {
                                    AudioGeneral_PlaySound(0x10, 0);
                                }
                            } else if (s6->unk_00.unk_0 & 0x100) {
                                switch (*s2) {
                                    case 2:
                                        sound_mode = func_i2_802C67E4(player, 0);
                                        break;
                                    case 3:
                                        sound_mode = func_i2_802C67E4(player, 1);
                                        break;
                                    case 4:
                                        sound_mode = func_i2_802C67E4(player, 2);
                                        break;
                                    default:
                                        sound_mode = 0;
                                        break;
                                }
                                if (sound_mode != 0) {
                                    AudioGeneral_PlaySound(0x10, 0);
                                }
                            }
                        }
                    }
                }
            }

            {
                s32 s2val = *s2;
                player++;
                if (s2val == 0) {
                    s32 char_idx = D_i2_802C8BD8[ARR_VAL(D_800DA9C0)];
                    UnkStruct_func_i8_802C6E00* ptr = &D_800DA950[char_idx];
                    struct UnkStruct_80192690* rider = &D_80192690[rider_idx];
                    rider->unkB68 = char_idx;
                    rider->unkB6C = ptr->unk_B[0];
                    rider->unkB70 = ptr->unk_B[1];
                    rider->unkB74 = ptr->unk_B[2];
                }
            }
            s2++;
        } while (player < D_801CE60C);
    }

    return SysUtils_Rand();
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i2/ovl_1B9440/func_i2_802C5E28.s")
#endif

s32 func_i2_802C676C(s32 player, s32 param) {
    s32 ret = 1;
    UnkStruct_func_i8_802C6E00(*arr)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) D_801CB298;
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
    UnkStruct_func_i8_802C6E00(*arr)[4] = (UnkStruct_func_i8_802C6E00(*)[4]) D_801CB298;
    s32 idx = D_i2_802C8BD8[D_800DA9C0[player]];

    arr[player][idx].unk_B[param]++;
    if (arr[player][idx].unk_B[param] == 12) {
        ret = 0;
        arr[player][idx].unk_B[param] = 11;
    }
    return ret;
}

void func_i2_802C6864(s32 arg0) {
    s32 i;
    s32 j;
    s32 cond = 0;
    s32 sp38;
    s8 sp34[4];

    if (D_801CE608.player == 1) {
        cond = 1;
    } else {
        ((s32*) &D_802C8C58)[arg0] = 6;
        if (D_802C8C58.player_1_ready == 6 && D_802C8C58.player_2_ready == 6) {
            cond = 1;
        }
    }

    if (cond) {
        cond = D_801CE608.gameMode;
        switch (cond) {
            case 4:
                for (i = 0; i < 4; i++) {
                    sp34[i] = 0;
                }
                sp34[D_800DA9C0[0]] = 1;
                for (i = 0; i < 4; i++) {
                    if (i != D_800D48DC) {
                        for (j = 0; j < 4; j++) {
                            if (sp34[j] == 0) {
                                sp34[j] = 1;
                                break;
                            }
                        }
                        if (j == 4) {
                            j--;
                        }
                        D_80192690[i].unkB68 = D_800DA9B0[i] = D_i2_802C8BD8[j];
                        D_80192690[i].unkB6C = D_800D96A4[gCourseID][D_800DA9B0[i]].unk0;
                        D_80192690[i].unkB70 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk4;
                        D_80192690[i].unkB74 = D_800D96A4[gCourseID][D_800DA9B0[i]].unk8;
                    } else {
                        D_800DA9B0[i] = D_i2_802C8BD8[D_800DA9C0[0]];
                    }
                }
                sp38 = 30;
                break;
            case 0:
            case 11:
                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
                D_800DA9B0[1] = 0;
                D_800DA9B0[2] = 0;
                D_800DA9B0[3] = 0;
                sp38 = 20;
                break;
            case 1:
                D_800DA9B0[0] = D_i2_802C8BD8[D_800DA9C0[0]];
                D_800DA9B0[1] = D_i2_802C8BD8[D_800DA9C0[1]];
                D_800DA9B0[2] = 0;
                D_800DA9B0[3] = 0;
                sp38 = 20;
                break;
        }
        func_i2_802C84EC(sp38);
    }
}

Gfx* func_i2_802C6ADC(Gfx* gdl) {
    u32 alpha;
    f32 f4 = 4.0f;

    gSPDisplayList(gdl++, &D_80BE248);
    gSPDisplayList(gdl++, D_106F628);
    gdl = Menu_DrawFrame(gdl, 0, 0x1C, 0x16, 0x108, 0x1E);
    gdl = Menu_DrawFrame(gdl, 0, 0x1C, 0x60, 0x82, 0xD);
    gdl = Menu_DrawFrame(gdl, 0, 0x20, 0x6E, 0x3B, 0xD);
    gdl = Menu_DrawFrame(gdl, 0, 0x5F, 0x6E, 0x3B, 0xD);
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

    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[0]] + 72) << 2, 91 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gdl = func_i2_802C70EC(gdl, 0);

    gdl->words.w0 = 0xB4000000;
    gdl->words.w1 = D_802C8C50;
    gdl++;

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

Gfx* func_i2_802C70EC(Gfx* gdl, s32 player) {
    s32 show_stats;
    s32 show_banner;
    s32 show_name;
    s32 spE8;
    s32 spE4;
    UnkStruct_func_i8_802C6E00* ptr;
    s32 x_pos;
    s32 x_name;

    if (player == 0) {
        x_pos = 0x13;
    } else {
        x_pos = 0x99;
    }

    if ((D_800DA9C8[player] == 0) || (D_802C8C58.as_array[player] == 0)) {
        ptr = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]];
    } else {
        ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[player][D_i2_802C8BD8[D_800DA9C0[player]]];
    }

    show_stats = 0;
    show_banner = 0;
    show_name = 0;
    spE8 = 0;
    spE4 = 0;

    if (D_802C8C58.as_array[player] >= 2) {
        spE8 = 1;
    }
    if ((D_802C8C58.as_array[player] > 0) && (D_802C8C58.as_array[player] != 6)) {
        spE4 = 1;
    }

    if (D_801CE60C == 1) {
        if (D_802C8C58.as_array[player] != 5) {
            show_stats = 1;
        }
        show_banner = 1;
        show_name = 1;
        x_name = x_pos + 0xA1;
    } else {
        if ((D_802C8C58.as_array[player] > 0) && (D_802C8C58.as_array[player] < 5)) {
            show_stats = 1;
        }
        if (D_802C8C58.as_array[player] > 0) {
            show_banner = 1;
        }
        if (D_802C8C58.as_array[player] == 0) {
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
        if ((D_802C8C58.as_array[player] != 2) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 6, x_pos + 0xD, 0x8A, 0);
        gdl = func_801E3EE0(gdl, 0, 7, x_pos + 0x62, 0x8A, 0);

        if ((D_802C8C58.as_array[player] != 3) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 9, x_pos + 0xD, 0xA7, 0);
        gdl = func_801E3EE0(gdl, 0, 0xA, x_pos + 0x59, 0xA7, 0);

        if ((D_802C8C58.as_array[player] != 4) || (spE8 == 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xA, x_pos + 0xD, 0xB9, 0);
        }
        gdl = func_801E3EE0(gdl, 0, 0xC, x_pos + 0xD, 0xC4, 0);
        gdl = func_801E3EE0(gdl, 0, 0xB, x_pos + 0x67, 0xC4, 0);
    }

    if (show_name != 0) {
        if (player == 0) {
            gdl = func_801E9858(gdl, 1, ((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[0][D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, x_name, 0xCB);
        } else {
            gdl = func_801E9858(gdl, 1, D_800DA950[D_i2_802C8BD8[D_800DA9C0[player]]].unk_0, x_name, 0xCB);
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

    if (D_802C8C58.as_array[player] >= 5) {
        gdl = func_801E946C(gdl, (D_802C8C58.as_array[player] == 5) ? 6 : 7, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        gDPLoadTextureTile(gdl++, D_80BBFA8, G_IM_FMT_IA, G_IM_SIZ_8b, 88, 10, 0, 0, 87, 9, 0,
                           G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, (x_pos + 0x1D) << 2, 0xA2 << 2,
                            (x_pos + 0x75) << 2, 0xAC << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    gdl = func_801E946C(gdl, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);

    if (show_stats != 0) {
        if ((D_802C8C58.as_array[player] == 2) && (spE8 != 0)) {
            gdl = func_801E3EE0(gdl, 4, 9, x_pos + 0xD, 0x80, 0);
        }
        if ((D_802C8C58.as_array[player] == 3) && (spE8 != 0)) {
            gdl = func_801E3EE0(gdl, 4, 0xB, x_pos + 0xD, 0x9C, 0);
        }
        if ((D_802C8C58.as_array[player] == 4) && (spE8 != 0)) {
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

Gfx* func_i2_802C7C50(Gfx* gdl) {
    u32 alpha;
    s32 offset;
    f32 f4 = 4.0f;

    gSPDisplayList(gdl++, &D_80BE358);
    gSPDisplayList(gdl++, D_106F628);
    gdl = Menu_DrawFrame(gdl, 0, 0x1C, 0x16, 0x108, 0x1E);

    if (D_802C8C58.player_1_ready != 0) {
        gdl = Menu_DrawFrame(gdl, 0, 0x1C, 0x60, 0x82, 0xD);
        gdl = Menu_DrawFrame(gdl, 0, 0x20, 0x6E, 0x3B, 0xD);
        gdl = Menu_DrawFrame(gdl, 0, 0x5F, 0x6E, 0x3B, 0xD);
    }

    if (D_802C8C58.player_2_ready != 0) {
        gdl = Menu_DrawFrame(gdl, 0, 0xA1, 0x60, 0x82, 0xD);
        gdl = Menu_DrawFrame(gdl, 0, 0xA5, 0x6E, 0x3B, 0xD);
        gdl = Menu_DrawFrame(gdl, 0, 0xE4, 0x6E, 0x3B, 0xD);
    }

    if (D_802C8C58.player_1_ready != 0) {
        gdl = func_i2_802C86E4(gdl, 0x13, 0x68);
    }

    if (D_802C8C58.player_2_ready != 0) {
        gdl = func_i2_802C86E4(gdl, 0x99, 0x68);
    }

    if ((D_802C8C58.player_1_ready != 0) && (D_802C8C58.player_1_ready < 5)) {
        gSPDisplayList(gdl++, &D_80BE2B8);
    }

    if ((D_802C8C58.player_2_ready != 0) && (D_802C8C58.player_2_ready < 5)) {
        gSPDisplayList(gdl++, &D_80BE3C8);
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

    if (D_800DA9C0[0] == D_800DA9C0[1]) {
        offset = 0x20;
    } else {
        offset = 0x40;
    }

    gDPSetPrimColor(gdl++, 0, 0, 255, alpha, alpha, 255);
    gDPLoadTextureTile(gdl++, D_80B6E98, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 64 - 1, 36 - 1, 0,
                       G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[1]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[1]] + 72) << 2, 91 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gDPSetPrimColor(gdl++, 0, 0, alpha, 255, alpha, 255);
    gDPLoadTextureTile(gdl++, D_80B6590, G_IM_FMT_IA, G_IM_SIZ_8b, 64, 36, 0, 0, 64 - 1, 36 - 1, 0,
                       G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gSPTextureRectangle(gdl++, (D_i2_802C8BD0[D_800DA9C0[0]] + 8) << 2, 55 << 2,
                        (D_i2_802C8BD0[D_800DA9C0[0]] + offset + 8) << 2, 91 << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);

    gdl = func_i2_802C70EC(gdl, 0);
    gdl = func_i2_802C70EC(gdl, 1);

    gdl->words.w0 = 0xB4000000;
    gdl->words.w1 = D_802C8C50;
    gdl++;

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

void func_i2_802C84EC(s32 arg0) {
    s32 i;
    UnkStruct_func_i8_802C6E00* ptr;
    struct UnkStruct_80192690* rider;
    s32 rider_idx;

    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = 0xB;
    D_801CE638 = 4;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 3;

    for (i = 0; i < D_801CE60C; i++) {
        if (D_800DA9C8[i] == 0) {
            ptr = &D_800DA950[D_i2_802C8BD8[D_800DA9C0[i]]];
        } else {
            ptr = &((UnkStruct_func_i8_802C6E00 (*)[4]) D_801CB298)[i][D_i2_802C8BD8[D_800DA9C0[i]]];
        }

        rider_idx = (i == 0) ? D_800D48DC : D_800D48E0;
        rider = &D_80192690[rider_idx];
        rider->unkB6C = ptr->unk_B[0];
        rider->unkB70 = ptr->unk_B[1];
        rider->unkB74 = ptr->unk_B[2];
    }

    if (D_801CE608.gameMode == 4 && D_801CE630 == 30) {
        FadeTransition_SetProps(5, 0, 0);
    } else {
        FadeTransition_SetProps(1, 4, 0);
    }

    func_801E6A4C(0, 0);

    if (D_801CE630 == 30) {
        func_800C1F60(2);
    }
}

Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {
    s32 cur_y;
    s32 tex_offset;
    s32 i;
    s32 y2;
    s32 height;

    while (0) {
        cur_y = 0;
    }
    for (tex_offset = 0, i = 0, cur_y = y, y2 = y + 20; i != 105; i += 15, y2 += 15, cur_y += 15, tex_offset += 1950) {
        if (i != 90) {
            height = 15;
        } else {
            height = 2;
        }

        gDPLoadTextureTile(gdl++, (u8*) D_80B0008 + (tex_offset << 1), G_IM_FMT_RGBA, G_IM_SIZ_16b, 130, 0, 0, 0, 130 - 1,
                           height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, (x + 8) << 2, y2 << 2, (x + 138) << 2, (cur_y + height + 20) << 2, G_TX_RENDERTILE,
                            0, 0, 1 << 10, 1 << 10);
    }

    return gdl;
}

Gfx* func_i2_802C88DC(Gfx* gdl) {
    s32 pad[15];
    s32 outer;
    s32 tex_offset;
    s32 height;
    s32 row;
    s32 cur_y = 0;
    s32 next_y;
    s32 col;
    s32 cur_x;

    for (outer = 0, tex_offset = 0; outer != 100; outer += 5, tex_offset += 480) {
        if (outer == 95) {
            height = 1;
        } else {
            height = 5;
        }

        gDPLoadTextureBlock(gdl++, D_80B77A0 + tex_offset, G_IM_FMT_RGBA, G_IM_SIZ_16b, 96, height, 0,
                            G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        for (row = 0, cur_y = outer, next_y = outer + height; row != 288; row += 96, cur_y += 96, next_y += 96) {
            for (cur_x = 0, col = 96; col != 480; cur_x += 96, col += 96) {
                gSPScisTextureRectangle(gdl++, cur_x << 2, cur_y << 2, col << 2, next_y << 2, G_TX_RENDERTILE, 0, 0,
                                        1 << 10, 1 << 10);
            }
        }
    }

    return gdl;
}

const s32 D_i2_802C8BE0[] = { 3, 1 };
