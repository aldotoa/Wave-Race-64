#include "global.h"

#define TWO_OVER_SQRT_3 1.1547005f
#define DIRLIGHT_DIRECTION (0.57735026f)

typedef struct UnkStruct_80162420_s {
    s16 unk0;
    s16 unk2;
} UnkStruct_80162420;

extern UnkStruct_80162420 D_80162420[];

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C1D0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004C998.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004CC7C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D018.s")

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

#define APPLY_FRICTION(pt) { \
    f32 dot = (pt->unkC * dir_x) + (pt->unk14 * dir_z); \
    pt->unkC = (dot * dir_x * friction_scale) + (pt->unkC * arg0->unk14); \
    pt->unk10 *= arg0->unk10; \
    pt->unk14 = (dot * dir_z * friction_scale) + (pt->unk14 * arg0->unk14); \
}

#ifdef NON_MATCHING
void func_8004DAF0(struct UnkStruct_8004B0F8* arg0) {
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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E0A4.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004EAA4.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F520.s")

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
            D_80162420[(i * 128) + (j / 4)].unk0 = SysUtils_Round(scale * ((((f32) sum / 6.0f) / 16383.5f) - 1.0f)) << 8;
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
            D_80162420[(i * 128) + (j / 4)].unk0 = SysUtils_Round(scale * ((((f32) sum / 6.0f) / 16383.5f) - 1.0f)) << 8;
            D_80162420[(i * 128) + (j / 4)].unk2 = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F790.s")
#endif

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004F9E0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050204.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050B78.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80050F8C.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_80051238.s")
