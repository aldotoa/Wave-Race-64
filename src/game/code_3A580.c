#include "common.h"

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 z;
    /* 0x8 */ s32 angle;
} SprayEmitter; // size = 0xC

struct UnkStruct_80192420 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
};

extern SprayEmitter D_801C3B90[16];
extern s16 D_800D9640[32];
extern struct UnkStruct_80192420 D_80192420;
extern Gfx D_E010F28[];
extern Mtx D_2000A40;
extern u8 D_3000000[];

f32 func_8004D30C(f32, f32);

/* Seeds the 16 spray emitters and fills both gfx pools' spray quads with
   texture coordinates (3x3 grid minus the center, 8 vertices each). The
   `i << 1` indexing is load-bearing: `D_800D9640[i][0]` lets IDO strength-
   reduce the table pointer and drop i, recoloring the whole function. */
void func_8007FD80(void) {
    s32 i;
    s32 k;
    Vtx* vtx;

    for (i = 0; i < 16; i++) {
        D_801C3B90[i].x = D_800D9640[i << 1];
        D_801C3B90[i].z = D_800D9640[(i << 1) + 1];
        D_801C3B90[i].angle = SysUtils_Rand() & 0xFFF;
    }

    for (k = 1; k >= 0; k--) {
        vtx = D_8011F8E8[k].sprayVtx;
        for (i = 0; i < 16; i++, vtx += 8) {
            vtx[0].v.tc[0] = vtx[3].v.tc[0] = vtx[5].v.tc[0] = vtx[0].v.tc[1] = vtx[1].v.tc[1] = vtx[2].v.tc[1] = 0;
            vtx[1].v.tc[0] = vtx[6].v.tc[0] = 0x7E0;
            vtx[2].v.tc[0] = vtx[4].v.tc[0] = vtx[7].v.tc[0] = 0xFC0;
            vtx[3].v.tc[1] = vtx[4].v.tc[1] = 0x3E0;
            vtx[5].v.tc[1] = vtx[6].v.tc[1] = vtx[7].v.tc[1] = 0x7C0;
        }
    }
}

/* Port Blue spray: builds an 8-vertex quad grid around each nearby emitter.
   Load-bearing: reusing dx/dz for cos/sin and the corner temps (keeps cx/cz
   from being sunk past the calls), the block-scoped locals and their order
   (stack slots 0x74/0x78, 0x98 frame), and `i = 0` after the gSPMatrix. */
Gfx* func_8007FFA8(Gfx* gfx) {
    SprayEmitter* p;
    s32 i;
    Vtx* segVtx;
    f32 dx;
    f32 dz;

    if (gCourseID != 5) {
        return gfx;
    }

    gSPDisplayList(gfx++, D_E010F28);
    gSPMatrix(gfx++, &D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    i = 0;

    for (p = D_801C3B90; p < &D_801C3B90[16]; p++, i += 8) {
        f32 ax;
        f32 az;
        f32 x;
        f32 z;
        f32 cx;
        f32 cz;
        Vtx* vtx;

        dx = p->x - D_80192420.unk8;
        dz = p->z - D_80192420.unkC;
        if (D_80192420.unk10 <= (dx * dx) + (dz * dz)) {
            continue;
        }
        dx = COS(p->angle);
        dz = SIN(p->angle);
        ax = 26.24f * dx;
        az = 26.24f * dz;
        cx = -17.28f * dz;
        cz = 17.28f * dx;
        vtx = &gGfxPool->sprayVtx[i];
        segVtx = &((GfxPool*) D_3000000)->sprayVtx[i];

        x = p->x - ax;
        vtx[3].v.ob[0] = x;
        z = p->z - az;
        vtx[3].v.ob[2] = z;
        vtx[3].v.ob[1] = func_8004D30C(x, z);

        dx = x - cx;
        dz = z - cz;
        vtx[0].v.ob[0] = dx;
        vtx[0].v.ob[2] = dz;
        vtx[0].v.ob[1] = func_8004D30C(dx, dz);

        dx = x + cx;
        dz = z + cz;
        vtx[5].v.ob[0] = dx;
        vtx[5].v.ob[2] = dz;
        vtx[5].v.ob[1] = func_8004D30C(dx, dz);

        dx = p->x - cx;
        vtx[1].v.ob[0] = dx;
        dz = p->z - cz;
        vtx[1].v.ob[2] = dz;
        vtx[1].v.ob[1] = func_8004D30C(dx, dz);

        dx = p->x + cx;
        vtx[6].v.ob[0] = dx;
        dz = p->z + cz;
        vtx[6].v.ob[2] = dz;
        vtx[6].v.ob[1] = func_8004D30C(dx, dz);

        x = p->x + ax;
        vtx[4].v.ob[0] = x;
        z = p->z + az;
        vtx[4].v.ob[2] = z;
        vtx[4].v.ob[1] = func_8004D30C(x, z);

        dx = x - cx;
        dz = z - cz;
        vtx[2].v.ob[0] = dx;
        vtx[2].v.ob[2] = dz;
        vtx[2].v.ob[1] = func_8004D30C(dx, dz);

        dx = x + cx;
        dz = z + cz;
        vtx[7].v.ob[0] = dx;
        vtx[7].v.ob[2] = dz;
        vtx[7].v.ob[1] = func_8004D30C(dx, dz);

        gSPVertex(gfx++, segVtx, 8, 0);
        gSP1Triangle(gfx++, 0, 3, 1, 0);
        gSP1Triangle(gfx++, 1, 3, 6, 0);
        gSP1Triangle(gfx++, 6, 3, 5, 0);
        gSP1Triangle(gfx++, 6, 7, 4, 0);
        gSP1Triangle(gfx++, 6, 4, 1, 0);
        gSP1Triangle(gfx++, 1, 4, 2, 0);
    }
    return gfx;
}
