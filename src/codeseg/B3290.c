#include "common.h"

typedef struct B3290Node {
    /* 0x00 */ s16 pos[3];
    /* 0x06 */ s8 fwd[3];
    /* 0x09 */ s8 up[3];
} B3290Node; /* size = 0xC */

typedef struct B3290Model {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ B3290Node* nodes;
    /* 0x08 */ u8 pad8[0x3C];
    /* 0x44 */ s16* idx0;
    /* 0x48 */ s16* idx1;
    /* 0x4C */ s16* idx2;
} B3290Model;

typedef struct B3290Entry {
    /* 0x00 */ Gfx* dl0;
    /* 0x04 */ Gfx* dl1;
    /* 0x08 */ Gfx* dl2;
    /* 0x0C */ u8 padC[0x38];
} B3290Entry; /* size = 0x44 */

extern s32 D_80226C30;
extern s32 D_80228920;
// Same address as D_80228920. The compare and the store must use separate symbols, or IDO
// CSEs the global's address into a register.
extern s32 D_80228920_2;
extern B3290Model* D_802238DC[];
extern B3290Entry D_80227A60[];
extern Gfx* D_801CE9A0[];

void func_801E4C60(Mtx* mtx, f32 x1, f32 y1, f32 z1, f32 x2, f32 y2, f32 z2, f32 tx, f32 ty, f32 tz, f32 scale) {
    s32 e1;
    f32 cx;
    f32 cy;
    f32 cz;
    s32 e0;
    f32 inv;
    f32 s;

    x1 = x1 / 127.0;
    y1 = y1 / 127.0;
    z1 = z1 / 127.0;
    x2 = x2 / 127.0;
    y2 = y2 / 127.0;
    z2 = z2 / 127.0;
    s = scale * 65536.0f;
    e0 = x1 * s;
    e1 = y1 * s;
    mtx->m[1][0] = (e0 & 0xFFFF0000) | ((u32) e1 >> 16);
    mtx->m[1][1] = ((s32) (z1 * s) & 0xFFFF0000);
    mtx->m[3][0] = (e0 << 16) | (e1 & 0xFFFF);
    mtx->m[3][1] = (s32) (z1 * s) << 16;

    cx = y2 * z1 - z2 * y1;
    cy = z2 * x1 - x2 * z1;
    cz = x2 * y1 - y2 * x1;
    inv = cx * cx + cy * cy + cz * cz;
    if (inv != 0.0) {
        inv = s / sqrtf(inv);
        e0 = cx * inv;
        e1 = cy * inv;
        mtx->m[0][0] = (e0 & 0xFFFF0000) | ((u32) e1 >> 16);
        mtx->m[0][1] = ((s32) (cz * inv) & 0xFFFF0000);
        mtx->m[2][0] = (e0 << 16) | (e1 & 0xFFFF);
        mtx->m[2][1] = (s32) (cz * inv) << 16;

        x2 = y1 * cz - z1 * cy;
        y2 = z1 * cx - x1 * cz;
        z2 = x1 * cy - y1 * cx;
        inv = 1.0 / sqrtf(x2 * x2 + y2 * y2 + z2 * z2);
        x2 *= inv;
        y2 *= inv;
        z2 *= inv;
        // Recomputing s here (instead of reusing the value from the top) is what gives
        // IDO the original register allocation for the 0xFFFF0000 mask.
        s = scale * 65536.0f;
        e0 = x2 * s;
        e1 = y2 * s;
        mtx->m[0][2] = (e0 & 0xFFFF0000) | ((u32) e1 >> 16);
        mtx->m[0][3] = ((s32) (z2 * s) & 0xFFFF0000);
        mtx->m[2][2] = (e0 << 16) | (e1 & 0xFFFF);
        mtx->m[2][3] = (s32) (z2 * s) << 16;

        e0 = 65536.0f * tx;
        e1 = 65536.0f * ty;
        mtx->m[1][2] = (e0 & 0xFFFF0000) | ((u32) e1 >> 16);
        mtx->m[1][3] = ((s32) (65536.0f * tz) & 0xFFFF0000) | 1;
        mtx->m[3][2] = (e0 << 16) | (e1 & 0xFFFF);
        mtx->m[3][3] = (s32) (65536.0f * tz) << 16;
    }
}

Gfx* func_801E4FE8(Gfx* gdl, s32 arg1, s32 arg2, s32 arg3, Mtx* mtx) {
    B3290Model* model;
    s16 idx;

    if (arg2 != D_80228920) {
        D_80226C30 = 0;
    }
    D_80228920_2 = arg2;
    model = D_802238DC[arg2];

    idx = model->idx0[D_80226C30];
    func_801E4C60(mtx, model->nodes[idx].fwd[0], model->nodes[idx].fwd[1], model->nodes[idx].fwd[2],
                  model->nodes[idx].up[0], model->nodes[idx].up[1], model->nodes[idx].up[2], model->nodes[idx].pos[0],
                  model->nodes[idx].pos[1], model->nodes[idx].pos[2], 1.0f);
    gSPMatrix(gdl++, VIRTUAL_TO_PHYSICAL(mtx), G_MTX_PUSH);
    if (D_801CE638 == 21) {
        gSPDisplayList(gdl++, D_801CE9A0[arg1]);
    } else {
        gSPDisplayList(gdl++, D_80227A60[arg1].dl2);
    }
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);

    idx = model->idx1[D_80226C30];
    func_801E4C60(mtx + 1, model->nodes[idx].fwd[0], model->nodes[idx].fwd[1], model->nodes[idx].fwd[2],
                  model->nodes[idx].up[0], model->nodes[idx].up[1], model->nodes[idx].up[2], model->nodes[idx].pos[0],
                  model->nodes[idx].pos[1], model->nodes[idx].pos[2], 1.0f);
    gSPMatrix(gdl++, VIRTUAL_TO_PHYSICAL(mtx + 1), G_MTX_PUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].dl1);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);

    idx = model->idx2[D_80226C30];
    func_801E4C60(mtx + 2, model->nodes[idx].fwd[0], model->nodes[idx].fwd[1], model->nodes[idx].fwd[2],
                  model->nodes[idx].up[0], model->nodes[idx].up[1], model->nodes[idx].up[2], model->nodes[idx].pos[0],
                  model->nodes[idx].pos[1], model->nodes[idx].pos[2], 1.0f);
    gSPMatrix(gdl++, VIRTUAL_TO_PHYSICAL(mtx + 2), G_MTX_PUSH);
    gSPDisplayList(gdl++, D_80227A60[arg1].dl0);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}
