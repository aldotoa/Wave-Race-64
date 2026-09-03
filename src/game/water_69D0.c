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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004D628.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004DAF0.s")

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

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/water_69D0/func_8004E614.s")

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
