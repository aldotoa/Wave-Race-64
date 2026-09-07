#include "global.h"

#define TWO_OVER_SQRT_3 1.1547005f
#define DIRLIGHT_DIRECTION (0.57735026f)

typedef struct UnkStruct_80162420_s {
    s16 unk0;
    s16 unk2;
} UnkStruct_80162420;

extern UnkStruct_80162420 D_80162420[];

extern f32 D_800D4740;
extern f32 D_800D4744;

extern s32 D_80223934;
extern s32 D_80223930;
extern s32 D_800D476C;
extern f32 D_801924B4;
extern f32 D_801924CC;
extern s32 D_800D4770;
extern f32 D_801924C0;
extern f32 D_801924D0;
extern f32 D_800D4768;
extern s32 D_80192478[];
extern f32 D_800D477C;
extern s32 D_800D4774;
extern s32 D_800D4778;
extern s32 D_80192498;

typedef struct UnkStruct_80192420 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    f32 unk18;
} UnkStruct_80192420;

#ifdef NON_MATCHING
Gfx* func_8004C1D0(s32 arg0, Gfx* glistp) {
    struct camera_unk_1* cam;
    s32 angle_idx;
    f32 sin_val, cos_val;
    f32 tan_val;
    f32 fv1, ft0;

    if (arg0 != 0) {
        cam = &gCameraPerspective[D_80223934];
    } else {
        cam = &gCameraPerspective[D_80223930];
    }

    angle_idx = SysUtils_Round((*(f32*) ((u8*) cam + 0x88) / 180.0f) * 1024.0f);
    sin_val = gSinTable[angle_idx & 0xFFF];
    cos_val = gSinTable[(angle_idx + 0x400) & 0xFFF];

    tan_val = (*(f32*) ((u8*) cam + 0x9C) * sin_val) / cos_val;
    fv1 = tan_val;
    ft0 = (tan_val * 320.0f) / 240.0f;

    if (gPlayers == 2 && D_801CE638 == 1) {
        fv1 *= 0.5f;
    }

    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C1D0.s")
#endif

#ifdef NON_MATCHING
void func_8004C998(s32 arg0, Vtx* arg1) {
    struct camera_unk_1* cam;
    Vtx* src_vtx;
    Vtx* dst_vtx;
    s32 s1;
    f32 fs0;
    f32 diff_y;
    f32 f_scale;

    if (arg0 != 0) {
        cam = &gCameraPerspective[D_80223934];
        src_vtx = (Vtx*) ((u8*) gGfxPool + 0x170D8);
    } else {
        cam = &gCameraPerspective[D_80223930];
        src_vtx = (Vtx*) ((u8*) gGfxPool + 0x13D68);
    }

    D_801924CC = D_801924B4 / (f32) (D_800D476C << 10);
    D_801924D0 = D_801924C0 / (f32) (D_800D4770 << 13);

    diff_y = gWaterLevel - *(f32*) ((u8*) cam + 0x50);
    if (diff_y == 0.0f) {
        fs0 = 1.0f;
    } else {
        fs0 = (D_800D4768 - *(f32*) ((u8*) cam + 0x50)) / diff_y;
    }

    dst_vtx = arg1;
    for (s1 = 6; s1 >= 0; s1--) {
        s32 idx = D_80192478[s1];
        dst_vtx[s1].v.ob[0] = src_vtx[idx].v.ob[0];
        dst_vtx[s1].v.ob[1] = (s16) gWaterLevel;

        if (s1 != 0) {
            dst_vtx[s1].v.ob[2] = src_vtx[idx].v.ob[2];
        } else {
            f_scale = (f32) D_80192498 * D_800D477C;
            dst_vtx[s1].v.ob[0] -= (s16) (f_scale * *(f32*) ((u8*) cam + 0xF0));
            dst_vtx[s1].v.ob[2] = src_vtx[idx].v.ob[2] - (s16) (f_scale * *(f32*) ((u8*) cam + 0xF4));
        }

        dst_vtx[s1].v.tc[0] = SysUtils_Round((((f32) dst_vtx[s1].v.ob[0] - *(f32*) ((u8*) cam + 0x4C)) * fs0 +
                                              *(f32*) ((u8*) cam + 0x4C)) /
                                             D_801924CC) +
                              D_800D4778;
        dst_vtx[s1].v.tc[1] = SysUtils_Round((((f32) dst_vtx[s1].v.ob[2] - *(f32*) ((u8*) cam + 0x54)) * fs0 +
                                              *(f32*) ((u8*) cam + 0x54)) /
                                             D_801924D0) +
                              D_800D4774;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C998.s")
#endif

typedef struct ShorelineWaveStruct {
    f32 unk0;
    f32 unk4;
    char pad8[0x10];
    f32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
} ShorelineWaveStruct;

#ifdef NON_MATCHING
void func_8004CC7C(ShorelineWaveStruct* arg0) {
    s32 t5, s2, s3;
    s32 t3;
    s32 s4;
    s32 a3;
    f32 fa0, fa1;
    f32 ft2;
    s32 a2;
    s32 temp_hi, temp_hi_2;
    s32 s6, s7;
    s32 s5 = 384;
    s32 step;
    UnkStruct_80162420* var_v0;

    if (D_801CE72C == 1) {
        return;
    }

    t5 = arg0->unk30 << 11;
    s2 = arg0->unk34 << 11;
    s3 = arg0->unk38 << 11;

    arg0->unk28 -= (arg0->unk2C << 2);
    if (arg0->unk28 < 0) {
        arg0->unk28 += t5;
    }

    t3 = arg0->unk28;
    s4 = arg0->unk24 << 2;

    if (arg0->unk20 <= 0) {
        return;
    }

    for (step = 0; step < arg0->unk20; step++) {
        t3 += s4;
        if (t3 >= t5) {
            t3 -= t5;
        }

        if (t3 >= s2 && t3 <= s3) {
            ft2 = gSinTable[t3 & 0xFFF] * arg0->unk18;
            a2 = (s32) ft2 << 8;
            fa0 = arg0->unk0;
            fa1 = arg0->unk4;

            for (a3 = 0; a3 < arg0->unk1C; a3++) {
                temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * fa1) % 24576;
                temp_hi = (s32) ((DIRLIGHT_DIRECTION * fa1) + fa0) % 24576;

                s6 = temp_hi_2 >> 6;
                s7 = temp_hi >> 6;

                var_v0 = &D_80162420[(((s7 + (s6 & ~0x7F) + 0x600) % s5) * 128) + (s6 & 0x7F)];
                var_v0->unk0 += a2;
                var_v0->unk2 = 0;

                fa0 += 64.0f;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004CC7C.s")
#endif

extern s32 D_800D47C0;

#ifdef NON_MATCHING
void func_8004D018(f32 arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 phase;
    s32 sin_idx;
    f32 amp;
    s32 disp;
    f32 half_rad;
    f32 max_x;
    f32 curr_x, curr_z;
    s32 temp_hi, temp_hi_2;
    s32 a0_val, a1_val, t9_val;
    s32 t8_diff, t6_diff;
    s32 s5 = 384;
    UnkStruct_80162420* var_v1;
    UnkStruct_80162420* var_t1;
    UnkStruct_80162420* var_a2;

    phase = D_800D47C0 + arg4;
    if (phase >= arg3) {
        phase -= arg3;
    }
    D_800D47C0 = phase;

    sin_idx = ((phase << 12) / arg3) & 0xFFF;
    amp = gSinTable[sin_idx] * (f32) arg2;
    disp = (s32) amp << 8;

    half_rad = (f32) (D_80192498 >> 2);
    max_x = arg0 + half_rad;
    curr_x = arg0 - half_rad;
    curr_z = arg1 - half_rad;

    while (curr_x <= max_x) {
        temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * curr_z) % 24576;
        temp_hi = (s32) ((DIRLIGHT_DIRECTION * curr_z) + curr_x);

        a0_val = temp_hi_2 >> 6;
        curr_x += 64.0f;

        temp_hi %= 24576;
        t9_val = a0_val << 6;
        a1_val = a0_val;
        t8_diff = temp_hi_2 - t9_val;

        a0_val = temp_hi >> 6;
        t6_diff = temp_hi - (a0_val << 6);

        if (t8_diff < t6_diff) {
            var_v1 = &D_80162420[(((a0_val + (a1_val & ~0x7F) + 0x601) % s5) * 128) + (a1_val & 0x7F)];
        } else {
            a1_val++;
            var_v1 = &D_80162420[(((a0_val + (a1_val & ~0x7F) + 0x600) % s5) * 128) + (a1_val & 0x7F)];
        }

        var_t1 = &D_80162420[(((a0_val + ((a0_val + 1) & ~0x7F) + 0x601) % s5) * 128) + ((a0_val + 1) & 0x7F)];
        var_a2 = &D_80162420[(((a0_val + (a0_val & ~0x7F) + 0x600) % s5) * 128) + (a0_val & 0x7F)];

        var_t1->unk0 += disp;
        var_a2->unk0 += disp;
        var_v1->unk0 += disp;

        var_t1->unk2 = 0;
        var_a2->unk2 = 0;
        var_v1->unk2 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D018.s")
#endif

#ifdef NON_MATCHING
f32 func_8004D30C(f32 arg0, f32 arg1) {
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_a1;
    s32 temp_a0;
    s32 t5;
    s32 t4;
    s32 a3;
    s32 a2;
    s32 t2;
    s32 v0;
    s32 v1;
    f32 norm;

    temp_hi = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a1 = temp_hi >> 6;
    temp_hi_2 = (s32) ((DIRLIGHT_DIRECTION * arg1) + arg0) % 24576;
    temp_a0 = temp_hi_2 >> 6;

    a3 = temp_a1 + (temp_a0 & ~0x7F);
    t2 = D_80162420[(((a3 + 0x600) % 384) * 128) + (temp_a0 & 0x7F)].unk0 >> 8;

    t5 = (temp_a1 * 64) - temp_hi;
    t4 = (temp_a0 * 64) - temp_hi_2;

    if (t5 < t4) {
        v0 = D_80162420[(((a3 + 0x601) % 384) * 128) + (temp_a0 & 0x7F)].unk0 >> 8;
        a2 = temp_a0 + 1;
        v1 = t2 - v0;
        v0 = v0 - (D_80162420[((((temp_a1 + (a2 & ~0x7F)) + 0x601) % 384) * 128) + (a2 & 0x7F)].unk0 >> 8);
    } else {
        a2 = temp_a0 + 1;
        a3 = temp_a1 + (a2 & ~0x7F);
        v1 = D_80162420[(((a3 + 0x600) % 384) * 128) + (a2 & 0x7F)].unk0 >> 8;
        v0 = t2 - v1;
        v1 = v1 - (D_80162420[(((a3 + 0x601) % 384) * 128) + (a2 & 0x7F)].unk0 >> 8);
    }

    norm = sqrtf((f32) (((v0 * v0) + (v1 * v1) + 0x1000) << 12));
    return (f32) ((v0 * t4) + ((gWaterLevel + t2) << 12) + (v1 * t5)) / norm;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D30C.s")
#endif

#define SQRT_3_OVER_2 (0.8660254f)

#ifdef NON_MATCHING
void func_8004D628(struct UnkStruct_8004B0F8* arg0) {
    struct UnkStruct_8004B0F8_1* var_v0;
    f32 temp_f2;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_v0;
    s32 temp_v1;
    s32 a0;
    s32 a2;
    s32 t0;
    s32 s3;
    s32 s1;
    s32 s2;
    s32 s6 = 384;
    f32 norm;
    f32 inv_norm;
    f32 norm_x, norm_y, norm_z;
    f32 depth;
    f32 depth_force;

    temp_f2 = arg0->unk1C * arg0->unk40 * arg0->unk18;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        temp_hi = (s32) ((DIRLIGHT_DIRECTION * var_v0->unk8) + var_v0->unk0) % 24576;
        temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * var_v0->unk8) % 24576;
        temp_v1 = temp_hi >> 6;
        temp_a3 = temp_hi_2 >> 6;

        t0 = temp_a3 + (temp_v1 & ~0x7F);
        s3 = D_80162420[(((t0 + 0x600) % s6) * 128) + (temp_v1 & 0x7F)].unk0 >> 8;

        a0 = (temp_v1 * 64) - temp_hi;
        a2 = (temp_a3 * 64) - temp_hi_2;

        if (a2 < a0) {
            s1 = D_80162420[(((t0 + 0x601) % s6) * 128) + (temp_v1 & 0x7F)].unk0 >> 8;
            temp_v0 = temp_v1 + 1;
            s2 = s3 - s1;
            s1 = s1 - (D_80162420[((((temp_a3 + (temp_v0 & ~0x7F)) + 0x601) % s6) * 128) + (temp_v0 & 0x7F)].unk0 >> 8);
        } else {
            temp_v0 = temp_v1 + 1;
            t0 = temp_a3 + (temp_v0 & ~0x7F);
            s2 = D_80162420[(((t0 + 0x600) % s6) * 128) + (temp_v0 & 0x7F)].unk0 >> 8;
            s1 = s3 - s2;
            s2 = s2 - (D_80162420[(((t0 + 0x601) % s6) * 128) + (temp_v0 & 0x7F)].unk0 >> 8);
        }

        norm = sqrtf((f32) (((s1 * s1) + (s2 * s2) + 0x1000) << 12));
        inv_norm = 1.0f / norm;
        norm_x = (f32) s1 * inv_norm;
        norm_y = 4096.0f * inv_norm;
        norm_z = (f32) s2 * inv_norm;

        depth = (((gWaterLevel + s3) - var_v0->unk4) * norm_y) + ((f32) a0 * norm_x) + ((f32) a2 * norm_z);

        if (depth >= 0.0f) {
            var_v0->unk1C |= 1;
            var_v0->unkC *= arg0->unk14;
            var_v0->unk10 *= arg0->unk10;
            var_v0->unk14 *= arg0->unk14;

            depth_force = depth * arg0->unk18;
            if (depth_force > temp_f2) {
                depth_force = temp_f2;
            }

            var_v0->unkC += depth_force * (norm_x - (0.5f * norm_z));
            var_v0->unk10 += depth_force * norm_y;
            var_v0->unk14 += depth_force * (norm_z * SQRT_3_OVER_2);
        } else {
            var_v0->unk1C &= ~1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D628.s")
#endif

#define APPLY_FRICTION(pt)                                                      \
    {                                                                           \
        f32 dot = (pt->unkC * dir_x) + (pt->unk14 * dir_z);                     \
        pt->unkC = (dot * dir_x * friction_scale) + (pt->unkC * arg0->unk14);   \
        pt->unk10 *= arg0->unk10;                                               \
        pt->unk14 = (dot * dir_z * friction_scale) + (pt->unk14 * arg0->unk14); \
    }

#ifdef NON_MATCHING
void func_8004DAF0(void* arg0_in) {
    struct UnkStruct_8004B0F8* arg0 = (struct UnkStruct_8004B0F8*) arg0_in;
    f32 dir_x, dir_z;
    f32 speed_sq;
    f32 inv_speed;
    f32 friction_scale;
    struct UnkStruct_8004B0F8_1* pts = arg0->unk30;

    speed_sq = (arg0->unk6C * arg0->unk6C) + (arg0->unk74 * arg0->unk74);
    friction_scale = 1.0f - arg0->unk14;

    if (speed_sq == 0.0f) {
        dir_x = 0.0f;
        dir_z = 0.0f;
    } else {
        inv_speed = 1.0f / sqrtf(speed_sq);
        dir_x = arg0->unk6C * inv_speed;
        dir_z = arg0->unk74 * inv_speed;
    }

    if (pts[1].unk1C & 1) {
        APPLY_FRICTION((&pts[1]));
    }
    if (pts[4].unk1C & 1) {
        APPLY_FRICTION((&pts[4]));
    }
    if (pts[8].unk1C & 1) {
        APPLY_FRICTION((&pts[8]));
    }
    if (pts[11].unk1C & 1) {
        APPLY_FRICTION((&pts[11]));
    }

    if ((pts[3].unk1C | pts[5].unk1C) & 1) {
        APPLY_FRICTION((&pts[6]));
        APPLY_FRICTION((&pts[5]));
    }

    if ((pts[6].unk1C | pts[7].unk1C) & 1) {
        APPLY_FRICTION((&pts[9]));
        APPLY_FRICTION((&pts[7]));
    }

    if ((pts[9].unk1C | pts[10].unk1C) & 1) {
        APPLY_FRICTION((&pts[9]));
        APPLY_FRICTION((&pts[2]));
    }

    if ((pts[2].unk1C | pts[0].unk1C) & 1) {
        pts[0].unk10 *= arg0->unk10;
        pts[2].unk10 *= arg0->unk10;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004DAF0.s")
#endif

#ifdef NON_MATCHING
void func_8004E0A4(struct UnkStruct_8004B0F8* arg0, f32 arg1) {
    struct UnkStruct_8004B0F8_1* var_v0;
    f32 temp_f2;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_v1;
    s32 temp_a3;
    s32 temp_v0;
    s32 a0;
    s32 a2;
    s32 t0;
    s32 s3;
    s32 s1;
    s32 s2;
    s32 s5 = 384;
    f32 norm;
    f32 inv_norm;
    f32 norm_x, norm_y, norm_z;
    f32 depth;
    f32 depth_force;

    temp_f2 = arg0->unk1C * arg0->unk40 * arg0->unk18;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        temp_hi = (s32) ((DIRLIGHT_DIRECTION * var_v0->unk8) + var_v0->unk0) % 24576;
        temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * var_v0->unk8) % 24576;
        temp_v1 = temp_hi >> 6;
        temp_a3 = temp_hi_2 >> 6;

        t0 = temp_a3 + (temp_v1 & ~0x7F);
        s3 = D_80162420[(((t0 + 0x600) % s5) * 128) + (temp_v1 & 0x7F)].unk0 >> 8;

        a0 = (temp_v1 * 64) - temp_hi;
        a2 = (temp_a3 * 64) - temp_hi_2;

        if (a2 < a0) {
            s1 = D_80162420[(((t0 + 0x601) % s5) * 128) + (temp_v1 & 0x7F)].unk0 >> 8;
            temp_v0 = temp_v1 + 1;
            s2 = s3 - s1;
            s1 = s1 - (D_80162420[((((temp_a3 + (temp_v0 & ~0x7F)) + 0x601) % s5) * 128) + (temp_v0 & 0x7F)].unk0 >> 8);
        } else {
            temp_v0 = temp_v1 + 1;
            t0 = temp_a3 + (temp_v0 & ~0x7F);
            s2 = D_80162420[(((t0 + 0x600) % s5) * 128) + (temp_v0 & 0x7F)].unk0 >> 8;
            s1 = s3 - s2;
            s2 = s2 - (D_80162420[(((t0 + 0x601) % s5) * 128) + (temp_v0 & 0x7F)].unk0 >> 8);
        }

        norm = sqrtf((f32) (((s1 * s1) + (s2 * s2) + 0x1000) << 12));
        inv_norm = 1.0f / norm;
        norm_x = (f32) s1 * inv_norm;
        norm_y = 4096.0f * inv_norm;
        norm_z = (f32) s2 * inv_norm;

        depth = (((arg1 + (f32) s3) - var_v0->unk4) * norm_y) + ((f32) a0 * norm_x) + ((f32) a2 * norm_z);

        if (depth >= 0.0f) {
            var_v0->unk1C |= 1;
            depth_force = depth * arg0->unk18;
            if (depth_force > temp_f2) {
                depth_force = temp_f2;
            }

            var_v0->unkC += depth_force * (norm_x - (0.5f * norm_z));
            var_v0->unk10 += depth_force * norm_y;
            var_v0->unk14 += depth_force * (norm_z * SQRT_3_OVER_2);
        } else {
            var_v0->unk1C &= ~1;
        }
    }

    func_8004DAF0(arg0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E0A4.s")
#endif

void func_8004E548(struct UnkStruct_8004B0F8* arg0, f32 arg1) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;
    struct UnkStruct_8004B0F8_1* var_v0;

    temp_f2 = arg0->unk1C * arg0->unk40 * arg0->unk18;

    for (var_v0 = &arg0->unk30[arg0->unk28]; (u32) var_v0 >= (u32) arg0->unk30; var_v0--) {
        var_f0 = (arg1 - var_v0->unk4);
        if (var_f0 >= 0.0f) {
            var_v0->unk1C |= 1;
            var_f0 *= arg0->unk18;
            if (temp_f2 < var_f0) {
                var_f0 = temp_f2;
            }
            var_v0->unk10 += var_f0;
        } else {
            var_v0->unk1C &= 0xFFFE;
        }
    }
    func_8004DAF0(arg0);
}

extern s8 D_80160430[][2];
extern s16 D_80160A98[][4];
extern s32 D_80192494;

#ifdef NON_MATCHING
void func_8004E614(void) {
    s32 s4;
    s32 s1;
    s32 s2;
    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 v1;
    s32 t0;
    s32 t3;
    f32 fv0;
    f32 fval;

    a3 = D_80192494;
    s2 = 0;
    a2 = -a3;

    if (a2 < 0) {
        s4 = a2;
        a1 = a3 * 2;
        a0 = a1 + s4;
        do {
            if (a0 >= 0) {
                s1 = 0;
                v1 = a2;
                do {
                    s1++;
                    D_80160430[s2][0] = v1;
                    v1++;
                    D_80160430[s2][1] = s4;
                    s2++;
                } while (s1 <= a0);
            }
            s4++;
            a0 = a1 + s4;
        } while (s4 < 0);
    }

    if (a3 >= 0) {
        s4 = 0;
        a1 = a3 * 2;
        a0 = a1 - s4;
        do {
            if (a0 >= 0) {
                s1 = 0;
                v1 = a2 + s4;
                do {
                    s1++;
                    D_80160430[s2][0] = v1;
                    v1++;
                    D_80160430[s2][1] = s4;
                    s2++;
                } while (s1 <= a0);
            }
            s4++;
            a0 = a1 - s4;
        } while (s4 <= a3);
    }

    s2 = 0;
    if (a2 <= a3) {
        s4 = a2;
        do {
            t0 = s4 * s4;
            fv0 = sqrtf((f32) t0);
            t3 = (s32) fv0;
            a3 = D_80192494;
            a1 = (a3 * 2) - t3;
            if (a1 >= 0) {
                for (s1 = 0; s1 <= a1; s1++) {
                    D_80160A98[s2][2] = (s1 - (a1 / 2)) << 6;
                    s2++;
                }
            }
            s4++;
        } while (s4 <= a3);
    }

    s2 = 0;
    if (a2 < 0) {
        s4 = a2;
        do {
            t0 = s4 * s4;
            fv0 = sqrtf((f32) t0);
            t3 = (s32) fv0;
            a3 = D_80192494;
            a1 = (a3 * 2) - t3;
            if (a1 >= 0) {
                for (s1 = 0; s1 <= a1; s1++) {
                    fval = (sqrtf(3.0f) * 64.0f / 2.0f) * (f32) s4;
                    D_80160A98[s2][3] = (s16) ((f64) fval - 0.5);
                    s2++;
                }
            }
            s4++;
        } while (s4 < 0);
    }

    if (a3 >= 0) {
        s4 = 0;
        do {
            t0 = s4 * s4;
            fv0 = sqrtf((f32) t0);
            t3 = (s32) fv0;
            a3 = D_80192494;
            a1 = (a3 * 2) - t3;
            if (a1 >= 0) {
                for (s1 = 0; s1 <= a1; s1++) {
                    fval = (sqrtf(3.0f) * 64.0f / 2.0f) * (f32) s4;
                    D_80160A98[s2][3] = (s16) ((f64) fval + 0.5);
                    s2++;
                }
            }
            s4++;
        } while (s4 <= a3);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E614.s")
#endif

extern s32 D_800D4724;
extern s32 D_800D472C;
extern s32 D_800D4730;

#ifdef NON_MATCHING
void func_8004EAA4(void) {
    s32 radius = D_80192494;
    s32 row = -radius;
    u32* v0;
    u32* t1;
    UnkStruct_80162420* a2;
    UnkStruct_80162420* a0;
    s32 t0, t2, t3, t6, t7, t8, t9;
    s32 span;

    if (row < 0) {
        v0 = (u32*) D_80160A98;
        do {
            span = (radius * 2) + row + 2;
            t1 = v0 + (span * 2);
            t6 = *(t1 - 2);
            t9 = *v0;
            a2 = (UnkStruct_80162420*) ((u8*) D_80162420 + t9);
            a0 = (UnkStruct_80162420*) ((u8*) D_80162420 + t6);

            t0 = a2->unk0;
            t2 = a0->unk0;
            t3 = (t0 + t2) >> D_800D4724;
            t6 = (t2 - t0) >> D_800D472C;

            a2->unk2 = (a2->unk2 + t6) - t3;
            a0->unk2 = (a0->unk2 - t6) - t3;

            v0 += 2;
            t1 -= 2;
            while ((uintptr_t) v0 < (uintptr_t) t1) {
                t6 = *(t1);
                a0 = (UnkStruct_80162420*) ((u8*) D_80162420 + t6);
                t2 = a0->unk0;
                t3 = (t0 + t2) >> D_800D4724;
                t0 = (t2 - t0) >> D_800D472C;

                a2->unk2 = (a2->unk2 + t0) - t3;
                a0->unk2 = (a0->unk2 - t0) - t3;
                v0 += 2;
            }
            row++;
        } while (row < 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004EAA4.s")
#endif

#ifdef NON_MATCHING
void func_8004EFB4(f32 arg0, f32 arg1, s32 arg2) {
    UnkStruct_80162420* var_v0;
    UnkStruct_80162420* var_t4;
    UnkStruct_80162420* var_a3;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_val;
    s32 temp_a1_plus_1;
    s32 t0;
    s32 t2;

    temp_hi = (s32) ((DIRLIGHT_DIRECTION * arg1) + arg0) % 24576;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a0 = temp_hi_2 >> 6;
    temp_a1 = temp_hi >> 6;

    if ((temp_hi - (temp_a1 * 64)) < (temp_hi_2 - (temp_a0 * 64))) {
        t2 = temp_a0 + (temp_a1 & ~0x7F);
        var_v0 = D_80162420 + ((((t2 + 0x601) % 384) * 128) + (temp_a1 & 0x7F));
        temp_a1_plus_1 = temp_a1 + 1;
        t0 = temp_a0 + (temp_a1_plus_1 & ~0x7F);
    } else {
        temp_a1_plus_1 = temp_a1 + 1;
        t0 = temp_a0 + (temp_a1_plus_1 & ~0x7F);
        var_v0 = D_80162420 + ((((t0 + 0x600) % 384) * 128) + (temp_a1_plus_1 & 0x7F));
        t2 = temp_a0 + (temp_a1 & ~0x7F);
    }

    var_t4 = D_80162420 + ((((t0 + 0x601) % 384) * 128) + (temp_a1_plus_1 & 0x7F));
    var_a3 = D_80162420 + ((((t2 + 0x600) % 384) * 128) + (temp_a1 & 0x7F));
    temp_val = arg2 * 256;
    var_t4->unk0 = temp_val;
    var_a3->unk0 = temp_val;
    var_v0->unk0 = temp_val;
    var_t4->unk2 = 0;
    var_a3->unk2 = var_t4->unk2;
    var_v0->unk2 = var_t4->unk2;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004EFB4.s")
#endif

extern u32 D_801924E0[];
extern s32 D_800D4680;
extern u32 gFrameCounter;

#ifdef NON_MATCHING
void func_8004F1EC(f32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    UnkStruct_80162420* var_v0;
    UnkStruct_80162420* var_t3;
    UnkStruct_80162420* var_t4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_hi;
    s32 temp_hi_2;
    s32 temp_val;

    temp_hi = (s32) ((DIRLIGHT_DIRECTION * arg1) + arg0) % 24576;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a0 = temp_hi_2 >> 6;
    temp_a1 = temp_hi >> 6;

    if ((temp_hi - (temp_a1 * 64)) < (temp_hi_2 - (temp_a0 * 64))) {
        var_v0 = D_80162420 + ((((((temp_a0 + 1) + (temp_a1 & ~0x7F) + 0x600) % 384)) * 128) + (temp_a1 & 0x7F));
    } else {
        var_v0 = D_80162420 + (((((temp_a0 + ((temp_a1 + 1) & ~0x7F) + 0x600) % 384)) * 128) + ((temp_a1 + 1) & 0x7F));
    }

    if ((u32) (gFrameCounter - D_801924E0[arg3]) < (u32) D_800D4680) {
        return;
    }

    var_t3 = D_80162420 + (((((temp_a0 + ((temp_a1 + 1) & ~0x7F) + 0x601) % 384)) * 128) + ((temp_a1 + 1) & 0x7F));
    var_t4 = D_80162420 + (((((temp_a0 + (temp_a1 & ~0x7F) + 0x600) % 384)) * 128) + (temp_a1 & 0x7F));
    D_801924E0[arg3] = gFrameCounter;
    temp_val = arg2 * 256;
    var_t3->unk0 = temp_val;
    var_t4->unk0 = temp_val;
    var_v0->unk0 = temp_val;
    var_t3->unk2 = 0;
    var_t4->unk2 = var_t3->unk2;
    var_v0->unk2 = var_t3->unk2;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F1EC.s")
#endif

void func_8004F3D4(f32 arg0, f32 arg1, s32 arg2) {
    UnkStruct_80162420* var_v0;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_hi;
    s32 temp_hi_2;

    temp_hi = (s32) ((DIRLIGHT_DIRECTION * arg1) + arg0) % 24576;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg1) % 24576;
    temp_a0 = temp_hi_2 >> 6;
    temp_a1 = temp_hi >> 6;

    if ((temp_hi - (temp_a1 * 64)) < (temp_hi_2 - (temp_a0 * 64))) {
        var_v0 = D_80162420 + ((((((temp_a0 + 1) + (temp_a1 & ~0x7F) + 0x600) % 384)) * 128) + (temp_a1 & 0x7F));
    } else {
        var_v0 = D_80162420 + (((((temp_a0 + ((temp_a1 + 1) & ~0x7F) + 0x600) % 384)) * 128) + ((temp_a1 + 1) & 0x7F));
    }
    if ((arg2 * 256) < var_v0->unk0) {
        var_v0->unk0 += arg2 * 256;
        var_v0->unk2 = 0;
    }
}

#ifdef NON_MATCHING
void func_8004F520(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    s32 val;
    s32 s0 = 384;
    UnkStruct_80162420* var_v1;
    UnkStruct_80162420* var_t1;
    UnkStruct_80162420* var_a2;
    f32 curr_x = arg1;
    f32 curr_z = arg2;
    s32 temp_hi, temp_hi_2;
    s32 a2_val, t1_val, t0_val;
    s32 t9_diff, t7_diff;

    if (arg5 == 0) {
        return;
    }

    val = (s32) arg0 << 8;

    while (arg5 != 0) {
        arg5--;
        temp_hi = (s32) (DIRLIGHT_DIRECTION * curr_z) + (s32) curr_x;
        temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * curr_z);

        curr_x += arg3;

        temp_hi %= 24576;
        temp_hi_2 %= 24576;

        a2_val = temp_hi >> 6;
        t1_val = temp_hi_2 >> 6;

        t9_diff = temp_hi_2 - (t1_val << 6);
        t7_diff = temp_hi - (a2_val << 6);

        if (t9_diff < t7_diff) {
            t0_val = t1_val;
            var_v1 = &D_80162420[(((a2_val + (t1_val & ~0x7F) + 0x601) % s0) * 128) + (t1_val & 0x7F)];
        } else {
            t0_val = t1_val;
            t1_val++;
            var_v1 = &D_80162420[(((a2_val + (t1_val & ~0x7F) + 0x600) % s0) * 128) + (t1_val & 0x7F)];
        }

        var_t1 = &D_80162420[(((a2_val + ((t0_val + 1) & ~0x7F) + 0x601) % s0) * 128) + ((t0_val + 1) & 0x7F)];
        var_a2 = &D_80162420[(((a2_val + (t0_val & ~0x7F) + 0x600) % s0) * 128) + (t0_val & 0x7F)];

        var_t1->unk0 = val;
        var_a2->unk0 = val;
        var_v1->unk0 = val;

        var_t1->unk2 = 0;
        var_a2->unk2 = 0;
        var_v1->unk2 = 0;

        curr_z += arg4;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F520.s")
#endif

#ifdef NON_MATCHING
void func_8004F790(s32 arg0) {
    s32 rand_arr[6];
    f32 scale = (f32) arg0;
    s32 i, j, k;
    s32 sum;
    s32 mask;

    for (i = 5; i >= 0; i--) {
        rand_arr[i] = SysUtils_Rand() & 0x7FFF;
    }

    for (j = 0; j < 0x200; j += 4) {
        for (i = 0; i < 384; i++) {
            sum = 0;
            mask = 1;
            for (k = 5; k >= 0; k--) {
                if (mask & 1) {
                    rand_arr[k] = SysUtils_Rand() & 0x7FFF;
                }
                sum += rand_arr[k];
                mask <<= 1;
            }
            D_80162420[(i * 128) + (j / 4)].unk0 = SysUtils_Round(scale * ((((f32) sum / 6.0f) / 16383.5f) - 1.0f))
                                                   << 8;
            D_80162420[(i * 128) + (j / 4)].unk2 = 0;
        }
    }

    for (i = 5; i >= 0; i--) {
        rand_arr[i] = SysUtils_Rand() & 0x7FFF;
    }

    for (i = 0; i < 384; i++) {
        for (j = 0; j < 0x200; j += 4) {
            sum = 0;
            mask = 1;
            for (k = 5; k >= 0; k--) {
                if (mask & 1) {
                    rand_arr[k] = SysUtils_Rand() & 0x7FFF;
                }
                sum += rand_arr[k];
                mask <<= 1;
            }
            D_80162420[(i * 128) + (j / 4)].unk0 = SysUtils_Round(scale * ((((f32) sum / 6.0f) / 16383.5f) - 1.0f))
                                                   << 8;
            D_80162420[(i * 128) + (j / 4)].unk2 = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F790.s")
#endif

extern s32 D_801CE64C;
extern s32 D_80192420[];
extern f32 D_800D4684[];
extern f32 D_80192460[];
extern s32 D_801924A0;
extern s32 D_801924A4;
extern s32 D_801924A8;
extern s32 D_80192498;
extern s32 D_8019249C;
extern f32 D_801924AC;
extern f32 D_801924B0;
extern f32 D_801924B8;
extern f32 D_801924BC;
extern f32 D_801924B4;
extern f32 D_801924C0;
extern u8 D_801388D0[];

#ifdef NON_MATCHING
void func_8004F9E0(f32 arg0, f32 arg1) {
    s32 s0;
    s32 s7 = 2;
    s32 a2;
    s32 t3;
    f32 fv0;
    u8* t2;

    if (D_801CE64C == 1) {
        D_800D4724 = 10;
        D_800D472C = 4;
        D_800D4730 = 5;
        D_80192494 = 16;
        s0 = 0;
    } else {
        D_800D4724 = 9;
        D_800D472C = 5;
        D_800D4730 = 6;
        if (s7 == D_801CE64C) {
            D_80192494 = 10;
            s0 = 26;
        } else if (s7 == gPlayers) {
            D_80192494 = 10;
            s0 = 26;
        } else {
            D_80192494 = 12;
            s0 = 13;
        }
    }

    D_80192420[8] = 0;
    D_80192420[13] = 0;
    D_80192420[7] = 0;
    D_80192420[1] = 0;
    D_80192420[0] = 0;

    {
        s32 i;
        for (i = 0; i < 13; i++) {
            D_80192460[i] = D_800D4684[s0 + i];
        }
    }

    D_801924A0 = 0x8000;
    D_801924A4 = 0x8000;
    D_801924A8 = 0x800;
    D_80192498 = D_80192494 << 6;
    D_8019249C = ((D_80192494 * 3) * (D_80192494 + 1)) + 1;
    gWaterLevel = arg0;

    func_8004E614();
    func_8004F790(arg1);

    a2 = (s32) ((((f32) ((D_801924A8 * 2) + D_801924A0)) / 49152.0f) + 0.900000000000000022);
    fv0 = sqrtf(3.0f);
    t3 = (s32) ((((f32) (D_801924A4 + (D_801924A8 * 2))) / (fv0 * 2.0f * 8192.0f)) + 0.900000000000000022);

    D_801924AC = (f32) (a2 * 24576) - 0.0;
    D_801924B0 = (f32) (-a2 * 24576);
    D_801924B8 = (fv0 * (f32) t3 * 8192.0f) - 0.0;
    D_801924BC = (fv0 * (f32) -t3 * 8192.0f);
    D_801924B4 = (D_801924AC - D_801924B0) + 0.0;
    D_801924C0 = (D_801924B8 - D_801924BC) + 0.0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F9E0.s")
#endif

#ifdef NON_MATCHING
void func_80050204(s32 arg0, Vtx* vtx) {
    UnkStruct_80192420* fp = &((UnkStruct_80192420*) D_80192420)[arg0];
    s32 v0 = D_80192494;
    Vtx* s3 = vtx;
    s32 i;
    f32 fv0, fv1;

    for (i = 0; i < v0; i++) {
        s3->v.ob[0] = fp->unk0 + D_80160A98[i][2];
        s3->v.ob[1] = (s32) gWaterLevel;
        s3->v.ob[2] = fp->unk4 + D_80160A98[i][3];
        s3++;
    }

    if (fp == &((UnkStruct_80192420*) D_80192420)[0]) {
        fv0 = *(f32*) ((u8*) gCameraPerspective + 0xF0);
        fv1 = *(f32*) ((u8*) gCameraPerspective + 0xF4);
    } else {
        fv0 = *(f32*) ((u8*) gCameraPerspective + 0x1FC);
        fv1 = *(f32*) ((u8*) gCameraPerspective + 0x200);
    }

    fp->unk10 = (f32) (v0 * v0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050204.s")
#endif

typedef struct UnkCameraStruct {
    char pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    char pad58[0xC];
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    char pad7C[0xC];
    f32 unk88;
    char pad8C[0x8];
    f32 unk94;
    f32 unk98;
    f32 unk9C;
    char padA0[0x54];
    f32 unkF4;
} UnkCameraStruct;

extern f32 gSinTable[];
extern s32 D_800D49B0;
s32 SysUtils_Round(f32);

#ifdef NON_MATCHING
void func_80050B78(void* cam_in, f32* out_x, f32* out_y) {
    UnkCameraStruct* cam = (UnkCameraStruct*) cam_in;
    s32 angle_idx;
    f32 sin_val, cos_val;
    f32 f_tan;
    f32 f18, f16, f14;
    f32 f12, f10;
    f32 f4, f6, f8;
    f32 p0, p1, p2;
    f32 min_val;
    f32 v0, v1;
    f32 cam_water_diff;

    angle_idx = SysUtils_Round((cam->unk88 / 180.0f) * 1024.0f);
    sin_val = gSinTable[angle_idx & 0xFFF];
    cos_val = gSinTable[(angle_idx + 0x400) & 0xFFF];

    f_tan = (cam->unk9C * sin_val) / cos_val;

    f18 = (cam->unk74 * cam->unk6C) - (cam->unk78 * cam->unk68);
    f16 = (cam->unk78 * cam->unk64) - (cam->unk70 * cam->unk6C);
    f14 = (cam->unk70 * cam->unk68) - (cam->unk74 * cam->unk64);

    f12 = (f_tan * 320.0f) / 240.0f;
    f10 = cam->unk94 + f12;

    p0 = f10 * f18;
    p1 = f10 * f16;
    p2 = f10 * f14;

    cam_water_diff = (f32) ((s32) gWaterLevel + D_800D49B0) - cam->unk50;
    min_val = (cam->unk9C * (f32) D_801924A8 * 1.732f) / 320.0f;

    v0 = (f12 * f18) + (cam->unk9C * cam->unk68);
    v1 = (f12 * f16) + (cam->unk9C * cam->unk74);

    if (v1 < -5.0f) {
        f4 = cam_water_diff / v1;
        f6 = f4 * v0;
        if (f6 < min_val) {
            min_val = f6;
        }
    }

    *out_x = cam->unk4C + ((min_val - (128.0f - (f32) D_80192498 * 0.866f)) * cam->unk6C);
    *out_y = cam->unk54 + ((min_val - (128.0f - (f32) D_80192498 * 0.866f)) * cam->unkF4);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050B78.s")
#endif

#ifdef NON_MATCHING
void func_80050F8C(s32 arg0, f32 arg1, f32 arg2) {
    s32 temp_hi;
    s32 temp_hi_2;
    s32 t4, t5;
    s32 i;
    f32 f_u, f_v;
    f32 fa1, fa0;
    UnkStruct_80192420* obj = &((UnkStruct_80192420*) D_80192420)[arg0];

    temp_hi = (s32) ((DIRLIGHT_DIRECTION * arg2) + arg1) % 24576;
    t4 = (temp_hi + 0x20) >> 6;
    temp_hi_2 = (s32) (TWO_OVER_SQRT_3 * arg2) % 24576;
    t5 = (temp_hi_2 + 0x20) >> 6;

    f_u = (f32) (t4 << 6);
    f_v = (f32) (t5 << 6);

    fa1 = (f_u - (0.5f * f_v)) - ((f32) temp_hi - (0.5f * (f32) temp_hi_2));
    fa0 = (SQRT_3_OVER_2 * f_v) - (SQRT_3_OVER_2 * (f32) temp_hi_2);

    obj->unk14 = fa1;
    obj->unk0 = (s32) (fa1 + arg1);
    obj->unk18 = fa0;
    obj->unk4 = (s32) (fa0 + arg2);

    for (i = 0; i < D_8019249C; i++) {
        s32 gu = (t4 + D_80160430[i][0]) & 0x7F;
        s32 gv = (((t4 + (t5 & ~0x7F) + D_80160430[i][1]) + 0x600) % 384);
        D_80160A98[i][0] = (gv * 128) + gu;
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050F8C.s")
#endif

extern s32 D_801C1FCC;
extern f32 D_800D46E4;
extern f32 D_801924D8;
extern f32 D_800D46E0;
extern f32 D_801924D4;
extern void* D_80164420[];
extern f32 D_8019245C[];
extern f32 D_80192458[];

void func_80050B78(void*, f32*, f32*);

#ifdef NON_MATCHING
void func_80051238(void) {
    if (gCourseID == 7) {
        if (gRiderGameModes != 0) {
            if (D_801CE638 == 1) {
                if (D_801C1FCC == 1) {
                    if (gWaterLevel >= -99.0f) {
                        gWaterLevel -= 1.0f;
                    }
                } else if (D_801C1FCC == 2) {
                    if (gWaterLevel >= -149.0f) {
                        gWaterLevel -= 1.0f;
                    }
                }
            }
        }
    }

    D_801924D8 += D_800D46E4;
    D_801924D4 += D_800D46E0;

    func_80050B78(D_80164420[0], &D_8019245C[0], &D_80192458[0]);

    if (D_801CE64C == 1) {
        func_80050B78(D_80164420[1], &D_8019245C[1], &D_80192458[1]);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80051238.s")
#endif
