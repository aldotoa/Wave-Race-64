u32 func_i2_802C5E28(void) {
    s32 sp48;
    s32 sp40;
    UnkStruct_80192690 *temp_v0_16;
    UnkStruct_801CE658 *temp_s6;
    UnkStruct_func_i8_802C6E00 *temp_v1_7;
    s16 *temp_v0;
    s16 *temp_v0_10;
    s16 *temp_v0_2;
    s16 *temp_v0_3;
    s16 *temp_v0_4;
    s16 *temp_v0_5;
    s16 temp_t0;
    s16 temp_v1_4;
    s32 *temp_s1;
    s32 *temp_s5;
    s32 *temp_v0_11;
    s32 *temp_v0_12;
    s32 *temp_v1;
    s32 *temp_v1_2;
    s32 *temp_v1_5;
    s32 *temp_v1_6;
    s32 temp_a0_2;
    s32 temp_a2;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t8;
    s32 temp_t8_2;
    s32 temp_t9;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a1_5;
    s32 var_a1_6;
    s32 var_a3;
    s32 var_s0;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    u16 temp_a0;
    u16 temp_v0_13;
    union _anonymous *var_s2;

    temp_t0 = D_801CE60C;
    var_s0 = 0;
    if (temp_t0 > 0) {
        var_s2 = &D_802C8C58;
        var_s4 = 0;
        do {
            if (var_s0 == 0) {
                var_v0 = 0;
                sp48 = D_800D48DC;
            } else {
                var_v0 = 1;
                sp48 = D_800D48E0;
            }
            temp_s6 = &D_801CE658[var_v0];
            temp_a0 = temp_s6->unk_00.unk_2;
            if ((temp_a0 & 0xB000) && (D_i2_802C8BC0 != 0)) {
                temp_t3 = var_s2->player_1_ready;
                var_a1 = 1;
                switch (temp_t3) {                  /* switch 1 */
                case 0:                             /* switch 1 */
                    var_s2->player_1_ready = 1;
                    temp_v0 = &D_801CE6F4[var_s0];
                    temp_v1 = D_800DA9C0 + var_s4;
                    if ((D_800DAB64 != 0) && (temp_a0 & 0x2000)) {
                        *temp_v0 = 1;
                    }
                    if (*temp_v0 != 0) {
                        temp_v0_2 = &D_802C8C70[*temp_v1];
                        *temp_v0_2 |= 2;
                    } else {
                        temp_v0_3 = &D_802C8C70[*temp_v1];
                        *temp_v0_3 |= 1;
                    }
                    break;
                case 1:                             /* switch 1 */
                    if (*(D_800DA9C8 + var_s4) == 0) {
                        if (var_s0 == 0) {
                            D_801CB32C = 0;
                        }
                        if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 0xB)) {
                            func_i2_802C6864(var_s0);
                            var_a1 = 2;
                        } else {
                            var_s2->player_1_ready = 5;
                        }
                    } else {
                        if (var_s0 == 0) {
                            D_801CB32C = 1;
                        }
                        var_s2->player_1_ready = 2;
                    }
                    break;
                case 2:                             /* switch 1 */
                    var_s2->player_1_ready = 3;
                    break;
                case 3:                             /* switch 1 */
                    var_s2->player_1_ready = 4;
                    break;
                case 4:                             /* switch 1 */
                    if ((D_801CE608.gameMode == 0) || (D_801CE608.gameMode == 0xB)) {
                        func_i2_802C6864(var_s0);
                        var_a1 = 2;
                    } else {
                        var_s2->player_1_ready = 5;
                    }
                    break;
                case 5:                             /* switch 1 */
                    sp40 = 1;
                    func_i2_802C6864(var_s0);
                    var_a1 = 1;
                    break;
                }
                if (var_a1 != 0) {
                    if (D_80228A32 == 1) {
                        AudioGeneral_PlaySound(0x2A, 0);
                    } else if (var_a1 == 1) {
                        AudioGeneral_PlaySound(0x11, 0);
                    } else {
                        AudioGeneral_PlaySound(0x37, 0);
                    }
                }
            } else if (temp_a0 & 0x4000) {
                temp_t8 = var_s2->player_1_ready;
                var_a1_2 = 1;
                switch (temp_t8) {                  /* switch 2 */
                case 0:                             /* switch 2 */
                    sp40 = 1;
                    func_i2_802C84EC(2);
                    var_a1_2 = 1;
                    break;
                case 1:                             /* switch 2 */
                    var_s2->player_1_ready = 0;
                    temp_v1_2 = D_800DA9C0 + var_s4;
                    if (D_801CE6F4[var_s0] != 0) {
                        temp_v0_4 = &D_802C8C70[*temp_v1_2];
                        *temp_v0_4 &= 0xFFFD;
                    } else {
                        temp_v0_5 = &D_802C8C70[*temp_v1_2];
                        *temp_v0_5 &= 0xFFFE;
                    }
                    break;
                case 5:                             /* switch 2 */
                    if (*(D_800DA9C8 + var_s4) == 0) {
                        var_s2->player_1_ready = 1;
                    } else {
                        var_s2->player_1_ready = 4;
                    }
                    break;
                case 2:                             /* switch 2 */
                    var_s2->player_1_ready = 1;
                    break;
                case 3:                             /* switch 2 */
                    var_s2->player_1_ready = 2;
                    break;
                case 4:                             /* switch 2 */
                    var_s2->player_1_ready = 3;
                    break;
                default:                            /* switch 2 */
                    var_a1_2 = 0;
                    break;
                }
                if (var_a1_2 != 0) {
                    AudioGeneral_PlaySound(0x16, 0);
                }
            } else {
                var_v1 = 1;
                if (temp_a0 & 0xF) {
                    temp_v0_6 = var_s2->player_1_ready;
                    temp_v1_3 = D_i2_802C8BD8[*(D_800DA9C0 + var_s4)];
                    switch (temp_v0_6) {            /* switch 3; irregular */
                    case 2:                         /* switch 3 */
                        temp_v0_7 = temp_v1_3 * 0xE;
                        D_801CB298->unk_B[(var_s0 * 0x38) + temp_v0_7] = *(D_800DA950->unk_B + temp_v0_7);
                        break;
                    case 3:                         /* switch 3 */
                        temp_v0_8 = temp_v1_3 * 0xE;
                        (&D_801CB298->unk_B[1])[(var_s0 * 0x38) + temp_v0_8] = *(&D_800DA950->unk_B[1] + temp_v0_8);
                        break;
                    case 4:                         /* switch 3 */
                        temp_v0_9 = temp_v1_3 * 0xE;
                        (&D_801CB298->unk_B[2])[(var_s0 * 0x38) + temp_v0_9] = *(&D_800DA950->unk_B[2] + temp_v0_9);
                        break;
                    }
                } else {
                    temp_s1 = var_s4 + D_i2_802C8BB0;
                    temp_s5 = var_s4 + D_i2_802C8BB8;
                    var_a3 = 0;
                    if ((gPlayers != ONE_PLAYER) && (D_800DA9C0->unk0 == D_800DA9C0->unk4)) {
                        var_v1 = 0;
                    }
                    temp_a2 = var_s2->player_1_ready;
                    if (temp_a2 == 0) {
                        temp_v0_10 = &D_801CE6F4[var_s0];
                        if (var_v1 != 0) {
                            if (temp_s6->unk_00.unk_0 & 0x800) {
                                var_a3 = 1;
                                *temp_v0_10 = var_s0 ^ 1;
                            } else {
                                *temp_v0_10 = (s16) var_s0;
                            }
                        } else {
                            temp_v1_4 = D_802C8C70[*(D_800DA9C0 + var_s4)];
                            if (temp_v1_4 == 0) {
                                *temp_v0_10 = (s16) var_s0;
                            } else if (temp_v1_4 & 1) {
                                *temp_v0_10 = 1;
                            } else {
                                *temp_v0_10 = 0;
                            }
                        }
                        if ((D_800DAB60 != 0) && (temp_t0 == 1)) {
                            if (temp_s6->unk_00.unk_0 & 0x400) {
                                D_800DAB64 = 1;
                            } else {
                                D_800DAB64 = 0;
                            }
                        }
                    }
                    *temp_s1 = 0;
                    if (temp_a0 & 0x200) {
                        var_a1_3 = 1;
                        switch (temp_a2) {          /* switch 4 */
                        case 0:                     /* switch 4 */
                            temp_v1_5 = D_800DA9C0 + var_s4;
                            if (var_a3 != 0) {
                            default:                /* switch 4 */
                                var_a1_3 = 0;
                            } else {
                                temp_t1 = *temp_v1_5 - 1;
                                *temp_v1_5 = temp_t1;
                                if (temp_t1 < 0) {
                                    *temp_v1_5 = 3;
                                }
                                *(var_s4 + D_802C8C60) = 0x200;
                            }
                            break;
                        case 1:                     /* switch 4 */
                            temp_v0_11 = var_s4 + D_800DA9C8;
                            temp_t9 = *temp_v0_11 - 1;
                            *temp_v0_11 = temp_t9;
                            if (temp_t9 < 0) {
                                *temp_v0_11 = 1;
                            }
                            break;
                        case 2:                     /* switch 4 */
                            *temp_s1 = 1;
                            var_a1_3 = func_i2_802C676C(var_s0, 0);
                            break;
                        case 3:                     /* switch 4 */
                            *temp_s1 = 1;
                            var_a1_3 = func_i2_802C676C(var_s0, 1);
                            break;
                        case 4:                     /* switch 4 */
                            *temp_s1 = 1;
                            var_a1_3 = func_i2_802C676C(var_s0, 2);
                            break;
                        }
                        if (var_a1_3 != 0) {
                            AudioGeneral_PlaySound(0x10, 0);
                        }
                    } else if (temp_a0 & 0x100) {
                        var_a1_4 = 1;
                        switch (temp_a2) {          /* switch 5 */
                        case 0:                     /* switch 5 */
                            temp_v1_6 = D_800DA9C0 + var_s4;
                            if (var_a3 != 0) {
                            default:                /* switch 5 */
                                var_a1_4 = 0;
                            } else {
                                temp_t4 = *temp_v1_6 + 1;
                                *temp_v1_6 = temp_t4;
                                if (temp_t4 == 4) {
                                    *temp_v1_6 = 0;
                                }
                                *(var_s4 + D_802C8C60) = 0x200;
                            }
                            break;
                        case 1:                     /* switch 5 */
                            temp_v0_12 = var_s4 + D_800DA9C8;
                            temp_t1_2 = *temp_v0_12 + 1;
                            *temp_v0_12 = temp_t1_2;
                            if (temp_t1_2 == 2) {
                                *temp_v0_12 = 0;
                            }
                            break;
                        case 2:                     /* switch 5 */
                            *temp_s1 = 1;
                            var_a1_4 = func_i2_802C67E4(var_s0, 0);
                            break;
                        case 3:                     /* switch 5 */
                            *temp_s1 = 1;
                            var_a1_4 = func_i2_802C67E4(var_s0, 1);
                            break;
                        case 4:                     /* switch 5 */
                            *temp_s1 = 1;
                            var_a1_4 = func_i2_802C67E4(var_s0, 2);
                            break;
                        }
                        if (var_a1_4 != 0) {
                            AudioGeneral_PlaySound(0x10, 0);
                        }
                    }
                    if (*temp_s1 != 0) {
                        *temp_s5 = -3;
                    } else {
                        temp_t8_2 = *temp_s5 + 1;
                        *temp_s5 = temp_t8_2;
                        if (temp_t8_2 >= 4) {
                            temp_v0_13 = temp_s6->unk_00.unk_0;
                            *temp_s5 = 0;
                            if (temp_v0_13 & 0x200) {
                                temp_v0_14 = var_s2->player_1_ready;
                                switch (temp_v0_14) { /* switch 6; irregular */
                                default:            /* switch 6 */
                                    var_a1_5 = 0;
                                    break;
                                case 2:             /* switch 6 */
                                    var_v0_2 = func_i2_802C676C(var_s0, 0);
block_123:
                                    var_a1_5 = var_v0_2;
                                    break;
                                case 3:             /* switch 6 */
                                    var_v0_2 = func_i2_802C676C(var_s0, 1);
                                    goto block_123;
                                case 4:             /* switch 6 */
                                    var_v0_2 = func_i2_802C676C(var_s0, 2);
                                    goto block_123;
                                }
                                if (var_a1_5 != 0) {
                                    AudioGeneral_PlaySound(0x10, 0);
                                }
                            } else if (temp_v0_13 & 0x100) {
                                temp_v0_15 = var_s2->player_1_ready;
                                switch (temp_v0_15) { /* switch 7; irregular */
                                default:            /* switch 7 */
                                    var_a1_6 = 0;
                                    break;
                                case 2:             /* switch 7 */
                                    var_v0_3 = func_i2_802C67E4(var_s0, 0);
block_134:
                                    var_a1_6 = var_v0_3;
                                    break;
                                case 3:             /* switch 7 */
                                    var_v0_3 = func_i2_802C67E4(var_s0, 1);
                                    goto block_134;
                                case 4:             /* switch 7 */
                                    var_v0_3 = func_i2_802C67E4(var_s0, 2);
                                    goto block_134;
                                }
                                if (var_a1_6 != 0) {
                                    AudioGeneral_PlaySound(0x10, 0);
                                }
                            }
                        }
                    }
                }
            }
            var_s0 += 1;
            if (var_s2->player_1_ready == 0) {
                temp_a0_2 = D_i2_802C8BD8[*(D_800DA9C0 + var_s4)];
                temp_v1_7 = &D_800DA950[temp_a0_2];
                temp_v0_16 = &D_80192690[sp48];
                temp_v0_16->unkB68 = temp_a0_2;
                temp_v0_16->unkB6C = (s32) temp_v1_7->unk_B[0];
                temp_v0_16->unkB70 = (s32) temp_v1_7->unk_B[1];
                temp_v0_16->unkB74 = (s32) temp_v1_7->unk_B[2];
            }
            var_s4 += 4;
            var_s2 += 4;
        } while (var_s0 < D_801CE60C);
    }
    return SysUtils_Rand();
}
