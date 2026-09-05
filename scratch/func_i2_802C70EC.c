Gfx *func_801E9858(Gfx *, ?, UnkStruct_func_i8_802C6E00 *, s32, s32); /* extern */
extern ? D_800DA9C8;
extern ? D_80B6518;
extern ? D_80BBFA8;

Gfx *func_i2_802C70EC(Gfx *arg0, s32 arg1) {
    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spDC;
    s32 spD8;
    s32 sp5C;
    s32 *sp58;
    s32 *sp54;
    s32 *sp4C;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    Gfx *temp_v0_4;
    Gfx *var_s0;
    Gfx *var_s0_2;
    Gfx *var_s0_3;
    Gfx *var_s0_4;
    Gfx *var_s0_5;
    Gfx *var_v0;
    s32 *temp_a0;
    s32 *temp_a0_2;
    s32 *temp_t4;
    s32 *temp_t7;
    s32 *temp_t9;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_t1;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s8 *var_t0;
    void *temp_s0;
    void *temp_s0_10;
    void *temp_s0_11;
    void *temp_s0_12;
    void *temp_s0_13;
    void *temp_s0_14;
    void *temp_s0_15;
    void *temp_s0_16;
    void *temp_s0_17;
    void *temp_s0_18;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_s0_4;
    void *temp_s0_5;
    void *temp_s0_6;
    void *temp_s0_7;
    void *temp_s0_8;
    void *temp_s0_9;

    var_s0_2 = arg0;
    if (arg1 == 0) {
        spDC = 0x13;
    } else {
        spDC = 0x99;
    }
    temp_v0 = arg1 * 4;
    temp_t9 = temp_v0 + &D_800DA9C8;
    sp58 = temp_t9;
    temp_t7 = temp_v0 + &D_802C8C58;
    if ((*temp_t9 == 0) || (sp54 = temp_t7, var_v1 = *temp_t7, (var_v1 == 0))) {
        temp_t4 = &D_800DA9C0[arg1];
        sp4C = temp_t4;
        temp_a0 = temp_v0 + &D_802C8C58;
        var_v1 = *temp_a0;
        sp54 = temp_a0;
        var_t0 = D_800DA950[D_i2_802C8BD8[*temp_t4]].unk_0;
    } else {
        temp_a0_2 = &D_800DA9C0[arg1];
        var_t0 = &D_801CB298->unk_0[(arg1 * 0x38) + (D_i2_802C8BD8[*temp_a0_2] * 0xE)];
        sp4C = temp_a0_2;
    }
    var_t1 = 0;
    spF0 = 0;
    spEC = 0;
    spE8 = 0;
    spE4 = 0;
    if (var_v1 >= 2) {
        spE8 = 1;
    }
    if ((var_v1 > 0) && (var_v1 != 6)) {
        spE4 = 1;
    }
    if (D_801CE60C == 1) {
        if (var_v1 != 5) {
            var_t1 = 1;
        }
        spF0 = 1;
        spEC = 1;
        spD8 = spDC + 0xA1;
    } else {
        if ((var_v1 > 0) && (var_v1 < 5)) {
            var_t1 = 1;
        }
        if (var_v1 > 0) {
            spF0 = 1;
        }
        if (var_v1 == 0) {
            spEC = 1;
        }
        spD8 = spDC + 0x1B;
    }
    spF4 = var_t1;
    if (var_t1 != 0) {
        temp_s0 = var_s0_2 + 8;
        var_s0_2->words.w0 = 0xE7000000;
        var_s0_2->words.w1 = 0;
        temp_s0_2 = temp_s0 + 8;
        var_s0_2->unk8 = 0xB900031D;
        temp_s0->unk4 = 0x0F0A4000;
        temp_s0_3 = temp_s0_2 + 8;
        temp_s0->unk8 = 0xFCFFFFFF;
        temp_s0_2->unk4 = 0xFFFCF279;
        temp_s0_4 = temp_s0_3 + 8;
        temp_s0_2->unk8 = 0xFD100008;
        temp_s0_3->unk4 = &D_80B6518;
        temp_s0_4->unk4 = 0x07080200;
        temp_s0_3->unk8 = 0xF5100600;
        temp_s0_5 = temp_s0_4 + 8;
        temp_s0_6 = temp_s0_5 + 8;
        spF4 = var_t1;
        temp_s0_4->unk8 = 0xE6000000;
        temp_s0_7 = temp_s0_6 + 8;
        temp_s0_5->unk4 = 0;
        temp_s0_5->unk8 = 0xF4000000;
        temp_s0_8 = temp_s0_7 + 8;
        temp_s0_6->unk4 = 0x07020014;
        temp_s0_7->unk4 = 0;
        temp_s0_6->unk8 = 0xE7000000;
        temp_s0_9 = temp_s0_8 + 8;
        temp_s0_8->unk4 = 0x80200;
        temp_s0_7->unk8 = 0xF5100600;
        temp_s0_8->unk8 = 0xF2000000;
        temp_s0_9->unk4 = 0x20014;
        temp_s0_10 = temp_s0_9 + 8;
        temp_s0_11 = temp_s0_10 + 8;
        temp_s0_12 = temp_s0_11 + 8;
        temp_s0_13 = temp_s0_12 + 8;
        temp_s0_9->unk8 = (s32) ((((((var_t0->unkB * 0xA) + spDC + 0x17) * 4) & 0xFFF) << 0xC) | 0xE4000000 | 0x264);
        temp_s0_14 = temp_s0_13 + 8;
        temp_s0_10->unk4 = (s32) ((((((var_t0->unkB * 0xA) + spDC + 0xE) * 4) & 0xFFF) << 0xC) | 0x24C);
        temp_s0_11->unk4 = 0;
        temp_s0_10->unk8 = 0xB3000000;
        temp_s0_11->unk8 = 0xB2000000;
        temp_s0_12->unk4 = 0x04000400;
        temp_s0_15 = temp_s0_14 + 8;
        temp_s0_16 = temp_s0_15 + 8;
        temp_s0_17 = temp_s0_16 + 8;
        temp_s0_18 = temp_s0_17 + 8;
        temp_s0_12->unk8 = (s32) ((((((var_t0->unkC * 0xA) + spDC + 0x17) * 4) & 0xFFF) << 0xC) | 0xE4000000 | 0x2D8);
        temp_s0_13->unk4 = (s32) ((((((var_t0->unkC * 0xA) + spDC + 0xE) * 4) & 0xFFF) << 0xC) | 0x2C0);
        temp_s0_14->unk4 = 0;
        temp_s0_13->unk8 = 0xB3000000;
        temp_s0_14->unk8 = 0xB2000000;
        temp_s0_15->unk4 = 0x04000400;
        var_s0_2 = temp_s0_18 + 8;
        temp_s0_15->unk8 = (s32) ((((((var_t0->unkD * 0xA) + spDC + 0x17) * 4) & 0xFFF) << 0xC) | 0xE4000000 | 0x34C);
        temp_s0_16->unk4 = (s32) ((((((var_t0->unkD * 0xA) + spDC + 0xE) * 4) & 0xFFF) << 0xC) | 0x334);
        temp_s0_16->unk8 = 0xB3000000;
        temp_s0_17->unk4 = 0;
        temp_s0_17->unk8 = 0xB2000000;
        temp_s0_18->unk4 = 0x04000400;
    }
    temp_v0_2 = func_801E946C(var_s0_2, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    var_s0_3 = temp_v0_2;
    if (sp4C == D_800DA9C0) {
        var_s0_3 = func_801E3EE0(func_801E3EE0(func_801E3EE0(temp_v0_2, 2, 3, 0x26, 0x1C, 0), 4, 0xC, 0xDE, 0x1A, 0), 4, 0xD, 0xDE, 0x25, 0);
    }
    if (spF4 != 0) {
        if ((*sp54 != 2) || (spE8 == 0)) {
            var_s0_3 = func_801E3EE0(var_s0_3, 4, 9, spDC + 0xD, 0x80, 0);
        }
        temp_a3 = spDC + 0xD;
        sp5C = temp_a3;
        var_s0_4 = func_801E3EE0(func_801E3EE0(var_s0_3, 0, 6, temp_a3, 0x8A, 0), 0, 7, spDC + 0x62, 0x8A, 0);
        if ((*sp54 != 3) || (spE8 == 0)) {
            var_s0_4 = func_801E3EE0(var_s0_4, 4, 0xB, sp5C, 0x9C, 0);
        }
        var_s0_5 = func_801E3EE0(func_801E3EE0(var_s0_4, 0, 9, sp5C, 0xA7, 0), 0, 0xA, spDC + 0x59, 0xA7, 0);
        if ((*sp54 != 4) || (spE8 == 0)) {
            var_s0_5 = func_801E3EE0(var_s0_5, 4, 0xA, sp5C, 0xB9, 0);
        }
        var_s0_3 = func_801E3EE0(func_801E3EE0(var_s0_5, 0, 0xC, sp5C, 0xC4, 0), 0, 0xB, spDC + 0x67, 0xC4, 0);
    }
    if (spEC != 0) {
        if (sp4C == D_800DA9C0) {
            var_v0 = func_801E9858(var_s0_3, 1, &D_801CB298[D_i2_802C8BD8[*sp4C]], spD8, 0xCB);
        } else {
            var_v0 = func_801E9858(var_s0_3, 1, &D_800DA950[D_i2_802C8BD8[*sp4C]], spD8, 0xCB);
        }
        var_s0_3 = var_v0;
    }
    if (spF0 != 0) {
        var_s0_3 = func_801E3EE0(var_s0_3, 0, 0x25, spDC + 0xC, 0x62, 0);
        var_v1_2 = *sp58;
        if ((var_v1_2 != 0) || (spE4 == 0)) {
            var_s0_3 = func_801E3EE0(var_s0_3, 0, 3, spDC + 0x15, 0x70, 0);
            var_v1_2 = *sp58;
        }
        if ((var_v1_2 != 1) || (spE4 == 0)) {
            var_s0_3 = func_801E3EE0(var_s0_3, 0, 0x26, spDC + 0x54, 0x70, 0);
        }
    }
    temp_v1 = *sp54;
    if (temp_v1 >= 5) {
        if (temp_v1 == 5) {
            var_a1 = 6;
        } else {
            var_a1 = 7;
        }
        temp_v0_3 = func_801E946C(var_s0_3, var_a1, 0x80, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        temp_v0_3->unk10 = 0xE6000000;
        temp_v0_3->words.w1 = (u32) &D_80BBFA8;
        temp_v0_3->words.w0 = 0xFD680057;
        temp_v0_3->unkC = 0x07080200;
        temp_v0_3->unk18 = 0xF4000000;
        temp_v0_3->unk2C = 0x80200;
        temp_v0_3->unk20 = 0xE7000000;
        temp_v0_3->unk30 = 0xF2000000;
        temp_v0_3->unk34 = 0x15C024;
        temp_v0_3->unk1C = 0x0715C024;
        temp_v0_3->unk8 = 0xF5681600;
        temp_v0_3->unk28 = 0xF5681600;
        temp_v0_3->unk14 = 0;
        temp_v0_3->unk24 = 0;
        var_s0_3 = temp_v0_3 + 0x50;
        temp_v0_3->unk38 = (s32) (((((spDC + 0x75) * 4) & 0xFFF) << 0xC) | 0xE4000000 | 0x2B0);
        temp_v0_3->unk44 = 0;
        temp_v0_3->unk40 = 0xB3000000;
        temp_v0_3->unk48 = 0xB2000000;
        temp_v0_3->unk3C = (s32) (((((spDC + 0x1D) * 4) & 0xFFF) << 0xC) | 0x288);
        temp_v0_3->unk4C = 0x04000400;
    }
    temp_v0_4 = func_801E946C(var_s0_3, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    var_s0 = temp_v0_4;
    if (spF4 != 0) {
        var_v1_3 = *sp54;
        if ((var_v1_3 == 2) && (spE8 != 0)) {
            var_s0 = func_801E3EE0(temp_v0_4, 4, 9, spDC + 0xD, 0x80, 0);
            var_v1_3 = *sp54;
        }
        if ((var_v1_3 == 3) && (spE8 != 0)) {
            var_s0 = func_801E3EE0(var_s0, 4, 0xB, spDC + 0xD, 0x9C, 0);
            var_v1_3 = *sp54;
        }
        if ((var_v1_3 == 4) && (spE8 != 0)) {
            var_s0 = func_801E3EE0(var_s0, 4, 0xA, spDC + 0xD, 0xB9, 0);
        }
    }
    if (spF0 != 0) {
        var_v1_4 = *sp58;
        if ((var_v1_4 == 0) && (spE4 != 0)) {
            var_s0 = func_801E3EE0(var_s0, 0, 3, spDC + 0x15, 0x70, 0);
            var_v1_4 = *sp58;
        }
        if ((var_v1_4 == 1) && (spE4 != 0)) {
            var_s0 = func_801E3EE0(var_s0, 0, 0x26, spDC + 0x54, 0x70, 0);
        }
    }
    return var_s0;
}
