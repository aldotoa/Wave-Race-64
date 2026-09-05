typedef struct UnkStruct_801CE5F8_s {
    /* 0x0000 */ char pad0[0xA40];
    /* 0x0A40 */ Mtx unkA40[1];
    /* 0x0A80 */ Mtx unkA80[1];
    /* 0x0AC0 */ char padAC0[0x1C0];                /* maybe part of unkA80[8]? */
    /* 0x0C80 */ ? unkC80;                          /* inferred */
    /* 0x0C80 */ char padC80[0xC0];
    /* 0x0D40 */ ? unkD40;                          /* inferred */
    /* 0x0D40 */ char padD40[0xC0];
    /* 0x0E00 */ ? unkE00;                          /* inferred */
    /* 0x0E00 */ char padE00[0xC0];
    /* 0x0EC0 */ ? unkEC0;                          /* inferred */
    /* 0x0EC0 */ char padEC0[0x3C0];
    /* 0x1280 */ Vp unk1280[3];
    /* 0x12B0 */ char pad12B0[0x50];                /* maybe part of unk1280[2]? */
    /* 0x1300 */ Mtx unk1300[1];
    /* 0x1340 */ Mtx unk1340[1];
    /* 0x1380 */ char pad1380[0x400];               /* maybe part of unk1340[0x11]? */
    /* 0x1780 */ Mtx unk1780[1];
} UnkStruct_801CE5F8;                               /* size = 0x17C0 */

void *func_801E4FE8(void *, ?, ?, ?, ? *);          /* extern */
void *func_i2_802C70EC(Gfx *, ?, Gfx *, Gfx *);     /* extern */
extern ? D_106F488;
extern ? D_7000A40;
extern ? D_7000A80;
extern ? D_7000AC0;
extern ? D_7000B00;
extern ? D_7000B40;
extern u16 D_802C8C50;
extern ? D_80B6590;
extern ? D_80BE248;
extern ? D_80BE2B8;
extern ? D_80BE468;
extern ? D_80BE478;
extern ? D_80BE488;
extern ? D_80BE498;
extern ? D_i2_802C8BD0;

void *func_i2_802C6ADC(Gfx *arg0) {
    Gfx *temp_a0;
    Gfx *temp_a0_10;
    Gfx *temp_a0_11;
    Gfx *temp_a0_12;
    Gfx *temp_a0_13;
    Gfx *temp_a0_14;
    Gfx *temp_a0_2;
    Gfx *temp_a0_3;
    Gfx *temp_a0_4;
    Gfx *temp_a0_5;
    Gfx *temp_a0_6;
    Gfx *temp_a0_7;
    Gfx *temp_a0_8;
    Gfx *temp_a0_9;
    Gfx *temp_v0_2;
    Gfx *var_a0;
    f32 temp_ft4;
    s32 temp_v1;
    s32 var_t0;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;

    temp_a0 = arg0 + 8;
    arg0->words.w1 = (u32) &D_80BE248;
    arg0->words.w0 = 0x06000000;
    temp_a0->words.w1 = (u32) D_106F628;
    arg0->unk8 = 0x06000000;
    temp_v0_2 = func_i2_802C86E4(func_80094338(func_80094338(func_80094338(func_80094338(temp_a0 + 8, 0, 0x1C, 0x16, 0x108, 0x1E), 0, 0x1C, 0x60, 0x82, 0xD), 0, 0x20, 0x6E, 0x3B, 0xD), 0, 0x5F, 0x6E, 0x3B, 0xD), 0x13, 0x68);
    var_a0 = temp_v0_2;
    if (D_802C8C58.player_1_ready != 5) {
        temp_v0_2->words.w1 = (u32) &D_80BE2B8;
        var_a0 = temp_v0_2 + 8;
        temp_v0_2->words.w0 = 0x06000000;
    }
    temp_a0_2 = var_a0 + 8;
    var_a0->words.w0 = 0xE7000000;
    var_a0->words.w1 = 0;
    temp_a0_3 = temp_a0_2 + 8;
    var_a0->unk8 = 0xB900031D;
    temp_a0_2->words.w1 = 0x504240;
    temp_a0_2->unk8 = 0xFC119623;
    temp_a0_3->words.w1 = 0xFF2FFFFF;
    temp_a0_4 = temp_a0_3 + 8;
    if (D_802C8C6A == 0) {
        temp_ft4 = ((f32) D_802C8C68 * 255.0f) / 4.0f;
        if (M2C_ERROR(/* cfc1 */) & 0x78) {
            if (!(M2C_ERROR(/* cfc1 */) & 0x78)) {
                var_t0 = (s32) (temp_ft4 - 2.1474836e9f) | 0x80000000;
            } else {
                goto block_6;
            }
        } else {
            var_t0 = (s32) temp_ft4;
            if (var_t0 >= 0) {

            } else {
block_6:
                var_t0 = -1;
            }
        }
    } else {
        var_t0 = (s32) (u32) (((4.0f - (f32) D_802C8C68) * 255.0f) / 4.0f);
    }
    D_802C8C68 += 1;
    temp_a0_5 = temp_a0_4 + 8;
    if (D_802C8C68 >= 4) {
        D_802C8C68 = 0;
        D_802C8C6A ^= 1;
    }
    temp_v1 = var_t0 & 0xFF;
    temp_a0_3->unk8 = 0xFA000000;
    temp_a0_4->words.w1 = (temp_v1 << 0x18) | 0xFF0000 | (temp_v1 << 8) | 0xFF;
    temp_a0_5->words.w1 = (u32) &D_80B6590;
    temp_a0_4->unk8 = 0xFD68003F;
    temp_a0_6 = temp_a0_5 + 8;
    temp_a0_7 = temp_a0_6 + 8;
    temp_a0_6->words.w1 = 0x07080200;
    temp_a0_8 = temp_a0_7 + 8;
    temp_a0_5->unk8 = 0xF5681000;
    temp_a0_6->unk8 = 0xE6000000;
    temp_a0_9 = temp_a0_8 + 8;
    temp_a0_7->words.w1 = 0;
    temp_a0_7->unk8 = 0xF4000000;
    temp_a0_10 = temp_a0_9 + 8;
    temp_a0_8->words.w1 = 0x070FC08C;
    temp_a0_9->words.w1 = 0;
    temp_a0_8->unk8 = 0xE7000000;
    temp_a0_11 = temp_a0_10 + 8;
    temp_a0_10->words.w1 = 0x80200;
    temp_a0_9->unk8 = 0xF5681000;
    temp_a0_10->unk8 = 0xF2000000;
    temp_a0_11->words.w1 = 0xFC08C;
    temp_a0_12 = temp_a0_11 + 8;
    temp_a0_11->unk8 = (s32) (((((*(&D_i2_802C8BD0 + (*D_800DA9C0 * 2)) + 0x48) * 4) & 0xFFF) << 0xC) | 0xE4000000 | 0x16C);
    temp_a0_13 = temp_a0_12 + 8;
    temp_a0_14 = temp_a0_13 + 8;
    temp_a0_12->words.w1 = ((((*(&D_i2_802C8BD0 + (*D_800DA9C0 * 2)) + 8) * 4) & 0xFFF) << 0xC) | 0xDC;
    temp_a0_12->unk8 = 0xB3000000;
    temp_a0_13->words.w1 = 0;
    temp_a0_13->unk8 = 0xB2000000;
    temp_a0_14->words.w1 = 0x04000400;
    temp_v0_3 = func_i2_802C70EC(temp_a0_14 + 8, 0, temp_a0_12, temp_a0_13);
    temp_v0_3->unk0 = 0xB4000000;
    temp_v0_3->unk8 = 0x01030040;
    temp_v0_3->unk4 = (s32) D_802C8C50;
    temp_v0_3->unkC = &D_7000A40;
    temp_v0_3->unk14 = &D_106F488;
    temp_v0_3->unk10 = 0x06000000;
    temp_v0_3->unk1C = &D_80BE468;
    temp_v0_3->unk18 = 0x06000000;
    temp_v0_3->unk20 = 0x01020040;
    temp_v0_3->unk24 = &D_7000A80;
    temp_v0_4 = func_801E4FE8(temp_v0_3 + 0x28, 0, 0, 0, &D_801CE5F8->unkC80);
    temp_v0_4->unk4 = &D_80BE478;
    temp_v0_4->unk0 = 0x06000000;
    temp_v0_4->unk8 = 0x01020040;
    temp_v0_4->unkC = &D_7000AC0;
    temp_v0_5 = func_801E4FE8(temp_v0_4 + 0x10, 2, 0, 0, &D_801CE5F8->unkD40);
    temp_v0_5->unk4 = &D_80BE488;
    temp_v0_5->unk0 = 0x06000000;
    temp_v0_5->unk8 = 0x01020040;
    temp_v0_5->unkC = &D_7000B00;
    temp_v0 = func_801E4FE8(temp_v0_5 + 0x10, 3, 0, 0, &D_801CE5F8->unkE00);
    temp_v0->unk4 = &D_80BE498;
    temp_v0->unk0 = 0x06000000;
    temp_v0->unk8 = 0x01020040;
    temp_v0->unkC = &D_7000B40;
    return func_801E4FE8(temp_v0 + 0x10, 1, 0, 0, &D_801CE5F8->unkEC0);
}
