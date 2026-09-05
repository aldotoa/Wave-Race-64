#include "ctx.c"

#define ARR_VAL(arr) (*(s32*)((u8*)(arr) + offset))
#define ARR_PTR(arr) ((s32*)((u8*)(arr) + offset))

u32 func_i2_802C5E28(void) {
    s32 player;
    s32 v0;
    s32 offset;
    s32 can_select;
    s32 rider_idx;
    s32* s1;
    s32 sound_mode;
    s32* s2;
    s32* s5;
    UnkStruct_801CE658* s6;
    u16 pressed;
    s32* p;

    player = 0;
    if (D_801CE60C > 0) {
        offset = 0;
        s2 = D_802C8C58.as_array;
        do {
            s32 is_p2_same;
            if (player == 0) {
                rider_idx = D_800D48DC;
                v0 = 0;
            } else {
                rider_idx = D_800D48E0;
                v0 = 1;
            }
            s6 = &D_801CE658[v0];
            pressed = s6->unk_00.unk_2;

            if ((pressed & 0xB000) && (D_i2_802C8BC0 != 0)) {
                sound_mode = 1;
                switch (*s2) {
                    case 0:
                        *s2 = 1;
                        if ((D_800DAB64 != 0) && (pressed & 0x2000)) {
                            D_801CE6F4[player] = 1;
                        }
                        p = ARR_PTR(D_800DA9C0);
                        if (D_801CE6F4[player] != 0) {
                            D_802C8C70[*p] |= 2;
                        } else {
                            D_802C8C70[*p] |= 1;
                        }
                        break;
                    case 1:
                        if (ARR_VAL(D_800DA9C8) == 0) {
                            if (player == 0) {
                                D_801CB32C = 0;
                            }
                            if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
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
                    case 4:
                        if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 11)) {
                            func_i2_802C6864(player);
                            sound_mode = 2;
                        } else {
                            *s2 = 5;
                        }
                        break;
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
                        p = ARR_PTR(D_800DA9C0);
                        if (D_801CE6F4[player] != 0) {
                            D_802C8C70[*p] &= ~2;
                        } else {
                            D_802C8C70[*p] &= ~1;
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
                    case 5:
                        if (ARR_VAL(D_800DA9C8) == 0) {
                            *s2 = 1;
                        } else {
                            *s2 = 4;
                        }
                        break;
                    default:
                        sound_mode = 0;
                        break;
                }

                if (sound_mode != 0) {
                    AudioGeneral_PlaySound(0x16, 0);
                }
            } else {
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
                    s1 = &D_i2_802C8BB0[player];
                    s5 = &D_i2_802C8BB8[player];
                    can_select = 0;
                    is_p2_same = 1;
                    if ((gPlayers != ONE_PLAYER) && (D_800DA9C0[0] == D_800DA9C0[1])) {
                        is_p2_same = 0;
                    }

                    if (*s2 == 0) {
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
                        switch (*s2) {
                            case 0:
                                if (can_select != 0) {
                                    sound_mode = 0;
                                } else {
                                    p = ARR_PTR(D_800DA9C0);
                                    (*p)--;
                                    if (*p < 0) {
                                        *p = 3;
                                    }
                                    ARR_VAL(D_802C8C60) = 0x200;
                                }
                                break;
                            case 1:
                                p = ARR_PTR(D_800DA9C8);
                                (*p)--;
                                if (*p < 0) {
                                    *p = 1;
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
                        switch (*s2) {
                            case 0:
                                if (can_select != 0) {
                                    sound_mode = 0;
                                } else {
                                    p = ARR_PTR(D_800DA9C0);
                                    (*p)++;
                                    if (*p == 4) {
                                        *p = 0;
                                    }
                                    ARR_VAL(D_802C8C60) = 0x200;
                                }
                                break;
                            case 1:
                                p = ARR_PTR(D_800DA9C8);
                                (*p)++;
                                if (*p == 2) {
                                    *p = 0;
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
                        (*s5)++;
                        if (*s5 >= 4) {
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

            player++;
            if (*s2 == 0) {
                s32 char_idx = D_i2_802C8BD8[ARR_VAL(D_800DA9C0)];
                UnkStruct_func_i8_802C6E00* ptr = &D_800DA950[char_idx];
                struct UnkStruct_80192690* rider = &D_80192690[rider_idx];
                rider->unkB68 = char_idx;
                rider->unkB6C = ptr->unk_B[0];
                rider->unkB70 = ptr->unk_B[1];
                rider->unkB74 = ptr->unk_B[2];
            }
            offset += 4;
            s2++;
        } while (player < D_801CE60C);
    }

    return SysUtils_Rand();
}
