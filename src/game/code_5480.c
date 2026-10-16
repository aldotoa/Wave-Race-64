#include "global.h"

typedef struct UnkStruct_801603E0_s {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ s32 unk1C;
} UnkStruct_801603E0; /* size = 0x20 */

extern UnkStruct_801603E0 D_80160400[];
extern UnkStruct_801603E0 D_801603E0[];
extern UnkStruct_801603E0 D_80158520[];

extern s32 D_1000140;
extern s32 D_800D4610;
extern s32 D_800D4654;
extern s32 D_800D4670;
extern s32 D_800D4674;
extern f32 D_800D4678;
extern u16 D_800D467C;
extern s32 D_80160420;
extern Vec3f D_80158450[];
void func_8004B6E0(void);

extern s32 D_10001E0;
extern s32 D_800D4650;
extern s32 D_800D4658[];
extern Mtx D_8011F860;
extern Mtx D_8011F8A0;
extern s16 D_8011F8AA;

void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3);
void func_8004AE88(struct UnkStruct_8004B0F8* arg0);

void func_8004AC80(struct UnkStruct_8004B0F8* arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 sp6C[15];
    f32 temp_f0_3;
    f32 var_f20;
    s32 i;

    var_f20 = 0.0f;

    for (i = arg0->unk28; i >= 0; i--) {
        f32 temp_f0 = arg0->unk30[i].unk0 - arg1;
        f32 temp_f2 = arg0->unk30[i].unk4 - arg2;
        f32 temp_f14 = arg0->unk30[i].unk8 - arg3;
        temp_f0 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        sp6C[i] = temp_f0;
        if (var_f20 < temp_f0) {
            var_f20 = sp6C[i];
        }
    }

    temp_f0_3 = ((arg0->unk8 - arg0->unk4) / var_f20);
    for (i = arg0->unk28; i >= 0; i--) {
        arg0->unk30[i].unk18 = (sp6C[i] * temp_f0_3) + arg0->unk4;
    }
}

void func_8004ADEC(struct UnkStruct_8004B0F8* arg0) {
    f32* var_a2;
    UnkStruct_8004B0F8_unk34* var_v0;
    f32 var_f0;

    var_f0 = (0.5f / ((arg0->unk20 * (arg0->unk28 - 1)) + 1.0f));

    var_v0 = &arg0->unk34[arg0->unk2C];
    var_a2 = &arg0->unk38[arg0->unk2C];

    while (var_v0 >= arg0->unk34) {
        var_v0->unk8 = *var_a2 * var_f0;
        var_v0--, var_a2--;
    }
}

void func_8004AE88(struct UnkStruct_8004B0F8* arg0) {
    UnkStruct_8004B0F8_1* temp_v0_2;
    UnkStruct_8004B0F8_1* temp_v1_2;
    UnkStruct_8004B0F8_unk34* var_s0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f14;
    f32 temp_fs0;
    f32 temp_f2;
    f32* var_s1;
    s32 temp_v1;

    temp_fs0 = 0.5f / (arg0->unk20 * (arg0->unk28 - 1) + 1.0f);
    var_s0 = &arg0->unk34[arg0->unk2C];
    arg0->unk3C = 99999.9f;
    arg0->unk40 = 0.0f;
    var_s1 = &arg0->unk38[arg0->unk2C];

    while (var_s0 >= arg0->unk34) {
        temp_v0_2 = var_s0->unk0;
        temp_v1_2 = var_s0->unk4;
        temp_f0 = temp_v1_2->unk0 - temp_v0_2->unk0;
        temp_f2 = temp_v1_2->unk4 - temp_v0_2->unk4;
        temp_f14 = temp_v1_2->unk8 - temp_v0_2->unk8;
        temp_f0_2 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        *var_s1 = temp_f0_2;
        if (temp_f0_2 < arg0->unk3C) {
            arg0->unk3C = *var_s1;
        }
        if (arg0->unk40 < *var_s1) {
            arg0->unk40 = *var_s1;
        }
        var_s0->unk8 = (f32) (*var_s1 * temp_fs0);
        var_s0--;
        var_s1--;
    }
}

void func_8004AFE8(struct UnkStruct_8004B0F8* arg0, s32 arg1, s32 arg2) {
    s32 var_a1;
    s32 var_v1;
    UnkStruct_8004B0F8_unk34* var_v0;

    var_v0 = arg0->unk34;
    var_v1 = arg1;

    while (arg2 - 1 >= var_v1) {
        for (var_a1 = var_v1 + 1; var_a1 <= arg2; var_a1++, var_v0++) {
            var_v0->unk0 = &arg0->unk30[var_v1];
            var_v0->unk4 = &arg0->unk30[var_a1];
        }
        var_v1++;
    }
}

void func_8004B0F8(struct UnkStruct_8004B0F8* arg0) {
    f32 var_f0;
    f32 var_f12;
    f32 var_f14;
    f32 var_f2;
    struct UnkStruct_8004B0F8_1* var_v0;

    var_f0 = 0.0f;
    var_f2 = 0.0f;
    var_f12 = 0.0f;
    arg0->unk64 = 0.0f;
    arg0->unk60 = 0.0f;
    arg0->unk5C = 0.0f;
    arg0->unk58 = 0.0f;
    arg0->unk54 = 0.0f;
    arg0->unk50 = 0.0f;
    arg0->unk68 = 0.0f;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        var_v0->unk14 = 0.0f;
        var_v0->unk10 = 0.0f;
        var_v0->unkC = 0.0f;
        var_v0->unk1C = 0.0f;

        var_f12 += var_v0->unk0;
        var_f2 += var_v0->unk4;
        var_f0 += var_v0->unk8;
    }

    var_f14 = arg0->unk28 + 1;

    arg0->unk44 = (f32) (var_f12 / var_f14);
    arg0->unk48 = (f32) (var_f2 / var_f14);
    arg0->unk4C = (f32) (var_f0 / var_f14);
}

/* PARKED DRAFT (probe floor 83 rows of 307). Levers found: chained assign
 * `s->x = (v->x = s->x) + dt * s->vx` shares the load; one C variable reused
 * (var_s1 as loop pointer and constraint endpoint, temp_fs5 as dt/inv/new_y)
 * gives callee-saved f-regs; dead `i` counter forces the `multu 12` form.
 * Left: float-register priority (d/dz order, sums volatile) and fp temp
 * queue (f0 vs f2) - empty `if (d) {}` insertions move priority. */
#ifdef NON_MATCHING
void func_8004B1B4(struct UnkStruct_8004B0F8* arg0) {
    UnkStruct_8004B0F8_1* var_s1;
    UnkStruct_8004B0F8_unk34* var_s2;
    UnkStruct_8004B0F8_1* b;
    s32 pa0;
    s32 pa1;
    f32 old_x;
    f32 old_y;
    f32 old_z;
    s32 pb0;
    s32 pb1;
    s32 pb2;
    s32 pb3;
    s32 pb4;
    f32 new_z;
    Vec3f* var_v1;
    s32 var_s4;
    f32 temp_fs5;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 new_x;
    f32 new_y;
    f32 ln;
    s32 i;
    f32 cnt;

    i = arg0->unk28;
    var_s1 = &arg0->unk30[i];
    var_v1 = &D_80158450[i];
    temp_fs5 = arg0->unkC;
    while (var_s1 >= arg0->unk30) {
        var_s1->unk0 = (var_v1->x = var_s1->unk0) + temp_fs5 * var_s1->unkC;
        var_s1->unk4 = (var_v1->y = var_s1->unk4) + temp_fs5 * var_s1->unk10;
        var_s1->unk8 = (var_v1->z = var_s1->unk8) + temp_fs5 * var_s1->unk14;
        var_s1--;
        var_v1--;
        i--;
    }
    var_s1 = &arg0->unk30[arg0->unk28];

    temp_fs5 = 0.5f / (arg0->unk20 * (arg0->unk28 - 1) + 1.0f);
    var_s4 = arg0->unk24;
    if (var_s4 != 0) {
        do {
            while (var_s1 >= arg0->unk30) {
                var_s1->unkC = var_s1->unk10 = var_s1->unk14 = 0.0f;
                var_s1--;
            }
            var_s2 = &arg0->unk34[arg0->unk2C];
            while (var_s2 >= arg0->unk34) {
                var_s1 = var_s2->unk0;
                b = var_s2->unk4;
                dx = b->unk0 - var_s1->unk0;
                dy = b->unk4 - var_s1->unk4;
                dz = b->unk8 - var_s1->unk8;
                d = var_s2->unk8 / sqrtf(dx * dx + dy * dy + dz * dz) - temp_fs5;
                var_s2--;
                b->unkC = b->unkC + dx * d;
                b->unk10 = b->unk10 + dy * d;
                b->unk14 = b->unk14 + dz * d;
                var_s1->unkC = var_s1->unkC - dx * d;
                var_s1->unk10 = var_s1->unk10 - dy * d;
                var_s1->unk14 = var_s1->unk14 - dz * d;
            }
            var_s4--;
            var_s1 = &arg0->unk30[arg0->unk28];
            while (var_s1 >= arg0->unk30) {
                var_s1->unk0 = var_s1->unk0 + var_s1->unkC;
                var_s1->unk4 = var_s1->unk4 + var_s1->unk10;
                var_s1->unk8 = var_s1->unk8 + var_s1->unk14;
                var_s1--;
            }
            var_s1 = &arg0->unk30[arg0->unk28];
        } while (var_s4 != 0);
    }

    sx = sy = sz = 0.0f;
    i = arg0->unk28;
    var_v1 = &D_80158450[i];
    if (cnt) {
    }
    while (var_s1 >= arg0->unk30) {
        sx += var_s1->unk0;
        dx = var_s1->unk0 - var_v1->x;
        dy = var_s1->unk4 - var_v1->y;
        sy += var_s1->unk4;
        if (sy) {
        }
        dz = var_s1->unk8 - var_v1->z;
        if (new_x) {
        }
        sz += var_s1->unk8;
        d = (1.0f - var_s1->unk18) * (dx * arg0->unk5C + dy * arg0->unk60 + dz * arg0->unk64);
        if (sz) {
        }
        var_s1->unkC = arg0->unk5C * d + var_s1->unk18 * dx;
        var_s1->unk10 = arg0->unk60 * d + var_s1->unk18 * dy;
        var_s1->unk14 = arg0->unk64 * d + var_s1->unk18 * dz;
        var_s1--;
        var_v1--;
        i--;
    }

    cnt = arg0->unk28 + 1;
    new_x = sx / cnt;
    old_x = arg0->unk44;
    old_y = arg0->unk48;
    new_y = sy / cnt;
    arg0->unk44 = new_x;
    dx = new_x - old_x;
    arg0->unk50 = dx;
    old_z = arg0->unk4C;
    new_z = sz / cnt;
    arg0->unk48 = new_y;
    dy = new_y - old_y;
    arg0->unk54 = dy;
    arg0->unk4C = new_z;
    dz = new_z - old_z;
    arg0->unk58 = dz;
    d = dx * dx + dy * dy + dz * dz;
    if (d != 0.0f) {
        ln = sqrtf(d);
        arg0->unk68 = ln;
        arg0->unk5C = dx / ln;
        arg0->unk60 = dy / ln;
        arg0->unk64 = dz / ln;
    } else {
        arg0->unk68 = arg0->unk5C = arg0->unk60 = arg0->unk64 = 0.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_5480/func_8004B1B4.s")
#endif

void func_8004B680(void) {
}

void func_8004B684(void) {
}

UNUSED void stub_5480(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_5484(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_5488(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

UNUSED void stub_548C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
}

void func_8004B6E0(void) {
    s32 temp_s1;
    s32 temp_s2;
    s32 var_v0;

    if (D_800DAB1C == 1) {
        D_801603E0->unk0 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x260) >> 0x10) - 0x90;
        D_80160400->unk0 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x260) >> 0x10) - 0x90;
        D_801603E0->unk4 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x190) >> 0x10) - 0x50;
        D_80160400->unk4 = ((u32) ((SysUtils_Rand() >> 0x10) * 0x190) >> 0x10) - 0x50;
    } else {
        D_801603E0->unk0 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0x130) >> 0xE) + 8;
        D_801603E0->unk4 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0xC8) >> 0xE) + 0x14;
        do {
            D_80160400->unk0 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0x130) >> 0xD) - 0x90;
            D_80160400->unk4 = ((u32) ((SysUtils_Rand() & 0x3FFF) * 0xC8) >> 0xD) - 0x50;
        } while ((D_80160400->unk0 >= 8) && (D_80160400->unk0 < 0x138) && (D_80160400->unk4 >= 0x14) &&
                 (D_80160400->unk4 < 0xDC));
    }

    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        D_80158520[var_v0].unk0 = (s32) (((var_v0 % 39) * 8) + 8);
        D_80158520[var_v0].unk4 = (s32) (((var_v0 / 39) * 8) + 0x14);
    }
    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        D_80158520[var_v0].unk10 = 0;
        D_80158520[var_v0].unk14 = 0;
        D_80158520[var_v0].unk8 = D_80158520[var_v0].unk0;
        D_80158520[var_v0].unkC = D_80158520[var_v0].unk4;
    }
    D_801603E0->unk8 = D_801603E0->unk0;
    D_801603E0->unkC = D_801603E0->unk4;
    D_801603E0->unk10 = D_801603E0->unk14 = 0;
    D_80160400->unk8 = D_80160400->unk0;
    D_80160400->unkC = D_80160400->unk4;
    D_80160400->unk10 = D_80160400->unk14 = 0;

    for (var_v0 = 0; var_v0 < 0x3F6; var_v0++) {
        temp_s1 = D_80158520[var_v0].unk8 - D_801603E0->unk8;
        temp_s2 = D_80158520[var_v0].unkC - D_801603E0->unkC;
        D_80158520[var_v0].unk18 = (sqrtf((SQ(temp_s1) + SQ(temp_s2))) + 0.5);
        temp_s1 = D_80158520[var_v0].unk8 - D_80160400->unk8;
        temp_s2 = D_80158520[var_v0].unkC - D_80160400->unkC;
        D_80158520[var_v0].unk1C = (sqrtf((SQ(temp_s1) + SQ(temp_s2))) + 0.5);
    }
}

void func_8004BA18(void) {
    GfxPool* poolIter;
    s32 i;
    s32 j;
    s32 temp_lo;
    s32 temp_hi;
    s32 temp_v1;
    s32 temp_a0;
    Vtx* vtx;

    for (i = 0; i < 2; i++) {
        poolIter = &D_8011F8E8[i];

        for (j = 0; j < 0x3F6; j++) {
            temp_hi = j % 39;
            temp_lo = j / 39;

            temp_v1 = temp_hi * 8;
            temp_a0 = temp_lo * 8;

            vtx = &poolIter->unkFE08[j];

            vtx->v.ob[0] = temp_v1 + 8;
            vtx->v.ob[1] = temp_a0 + 0x14;
            vtx->v.ob[2] = 0;
            vtx->v.tc[0] = (temp_v1 * 0x59) + 0x2F4;
            vtx->v.tc[1] = (temp_a0 * 0x59) + 0x720;

            if (temp_hi == 38) {
                vtx->v.tc[0] -= 0xDE;
            }
            if (temp_lo == 25) {
                vtx->v.tc[1] -= 0xDE;
            }

            if (i == 0) {
                vtx->v.cn[0] = SysUtils_Rand() & 0xFF;
                vtx->v.cn[1] = SysUtils_Rand() & 0xFF;
                vtx->v.cn[2] = SysUtils_Rand() & 0xFF;
            } else {
                vtx->v.cn[0] = D_8011F8E8[0].unkFE08[j].v.cn[0];
                vtx->v.cn[1] = D_8011F8E8[0].unkFE08[j].v.cn[1];
                vtx->v.cn[2] = D_8011F8E8[0].unkFE08[j].v.cn[2];
            }
            vtx->v.cn[3] = 0xFF;
        }
    }

    guOrtho(&D_8011F860, -160.0f, 160.0f, -120.0f, 120.0f, 0.0f, 2.0f, 1.0f);
    guTranslate(&D_8011F8A0, -160.0f, 120.0f, -1.0f);

    D_8011F8AA = -1;
    func_8004B6E0();
}

Gfx* func_8004BC40(Gfx* gdl) {
    gSPDisplayList(gdl++, &D_1000140);
    gDPSetFillColor(gdl++, D_800D4658[D_800D4650]);
    gSPDisplayList(gdl++, &D_10001E0);
    return gdl;
}

/* PARKED DRAFT (probe floor ~71 rows of 331 with load-bearing alias symbols,
 * 177 without). The u32 prefix globals (D_800D467C/4674/4610/80160420) are
 * address-CSE'd into s-regs by IDO when a loop with a call exists; the target
 * keeps separate lui/lw, which only reproduced by giving ld and st different
 * symbol names for the same address. `if (fa) {}` in each arm makes the arm
 * result live in $f0 like the target. Remaining: one hidden t-reg queue
 * rotation at the sin/cos join (v0 vs t9). */
#ifdef NON_MATCHING
void func_8004BC98(void) {
    s32 temp_s6;
    f32 fa;
    s32 temp_s2;
    s32 temp_s1;
    s32 i;
    s32 prev;
    s32 tmr;
    Vtx* vtx;
    UnkStruct_801603E0* var_s0;

    if (gControllerOne[D_80154330[0]].unk_2 & 0x800) {
        D_800D467C = D_800D467C ^ 1;
    }
    if (gControllerOne[D_80154330[0]].unk_2 & 0x10) {
        func_8004B6E0();
        D_800D4670 ^= 1;
    }
    if (gControllerOne[D_80154330[0]].unk_0 & 0x10) {
        D_80160400->unk10 = gControllerOne[D_80154330[0]].unk_8 * 5;
        D_80160400->unk14 = gControllerOne[D_80154330[0]].unk_9 * -5;
    } else {
        prev = D_80160420;
        D_80160420 = D_800D4610;
        tmr = D_800D4674 + D_800D4610 - prev;
        D_800D4674 = tmr;
        if (tmr >= 0x12D) {
            if ((D_800D4654 = D_800D4654 + 1) == 7) {
                D_800D4650 = (u32) ((SysUtils_Rand() & 0xFFFF) * 6) >> 16;
                D_800D4654 = 0;
            }
            D_800D4674 = 0;
            func_8004B6E0();
            D_800D4670 ^= 1;
            if (D_800DAB1C == 1) {
                fa = (u32) ((SysUtils_Rand() >> 16) * 50) / 65536.0 + 50.0;
                D_800D4678 = fa;
            } else {
                fa = (u32) ((SysUtils_Rand() >> 16) * 5) / 65536.0 + 7.0;
                D_800D4678 = fa;
            }
        }
        D_80160400->unk10 = COS(D_800D4610 * 8) * D_800D4678;
        D_80160400->unk14 = SIN(D_800D4610 * 8) * D_800D4678;
        if (D_800D467C == 0) {
            D_80160400->unk14 = 0;
            D_80160400->unk10 = 0;
        }
    }
    D_80160400->unk0 = D_80160400->unk8 + D_80160400->unk10;
    D_80160400->unk4 = D_80160400->unkC + D_80160400->unk14;

    var_s0 = D_80158520;
    i = 0;
    do {
        vtx = &gGfxPool->unkFE08[i];
        temp_s1 = D_80160400->unk10;
        temp_s2 = D_80160400->unk14;
        temp_s6 = sqrtf(temp_s1 * temp_s1 + temp_s2 * temp_s2) + 0.5;
        temp_s1 = D_80160400->unk0 - var_s0->unk8;
        temp_s2 = D_80160400->unk4 - var_s0->unkC;
        fa = (var_s0->unk1C + var_s0->unk18) * (s32) (sqrtf(temp_s1 * temp_s1 + temp_s2 * temp_s2) + 0.5);
        if (fa != 0.0f) {
            fa = (f32) (var_s0->unk18 * temp_s6) / fa;
            if (D_800D4670 != 0) {
                var_s0->unk10 = 0.5 - temp_s1 * fa;
                var_s0->unk14 = 0.5 - temp_s2 * fa;
            } else {
                var_s0->unk10 = temp_s1 * fa + 0.5;
                var_s0->unk14 = temp_s2 * fa + 0.5;
            }
        }
        var_s0->unk0 = var_s0->unk10 + var_s0->unk8;
        vtx->v.ob[0] = var_s0->unk0;
        var_s0->unk4 = var_s0->unk14 + var_s0->unkC;
        vtx->v.ob[1] = var_s0->unk4;
        i++;
        var_s0++;
    } while (var_s0 != D_801603E0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_5480/func_8004BC98.s")
#endif
