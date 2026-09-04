#include "common.h"

extern double D_80226C40;
extern s32 D_80228920;
extern s32 D_80226C30;
extern uintptr_t D_802238DC[];

#ifdef NON_MATCHING
void func_801E4C60(Vtx* vtx, f32 x, f32 y, f32 z, f32 u, f32 v, f32 w, f32 scale) {
    f64 d = 127.0;
    f32 fx = (f32) (x / d);
    f32 fy = (f32) (y / d);
    f32 fz = (f32) (z / d);
    f32 fu = (f32) (u / d);
    f32 fv = (f32) (v / d);
    f32 fw = (f32) (w / d);
    f32 len = sqrtf(fx * fx + fy * fy + fz * fz);

    if (len != 0.0f) {
        vtx[0].v.ob[0] = (s16) (fx * scale);
        vtx[0].v.ob[1] = (s16) (fy * scale);
        vtx[0].v.ob[2] = (s16) (fz * scale);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4C60.s")
#endif

#ifdef NON_MATCHING
void func_801E4FE8(Vtx* vtx, s32 a1, s32 a2, s32 a3, s32 a4) {
    u8* ptr;
    s16 idx;
    s16* indices;
    u8* node;

    if (a2 != D_80228920) {
        D_80226C30 = 0;
    }
    D_80228920 = a2;

    ptr = (u8*) D_802238DC[a2];
    if (ptr != NULL) {
        indices = *(s16**) (ptr + 0x44);
        idx = indices[D_80226C30];
        node = *(u8**) (ptr + 0x4) + idx * 12;
        func_801E4C60(vtx, (f32) (signed char) node[6], (f32) (signed char) node[7], (f32) (signed char) node[8],
                      (f32) (signed char) node[9], (f32) (signed char) node[10], (f32) (signed char) node[11], 1.0f);
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B3290/func_801E4FE8.s")
#endif
