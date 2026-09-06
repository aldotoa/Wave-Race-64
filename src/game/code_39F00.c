#include "common.h"

/* Collision box: an oriented box volume. Points are transformed into the
 * (axisU, axisV, axisW) frame and tested against the half extents.
 * Layout roles inferred from use in Box_CollideRider/Box_QueryPoint. */
typedef struct CollideBox {
    /* 0x00 */ f32 centerX;
    /* 0x04 */ f32 centerY;
    /* 0x08 */ f32 centerZ;
    /* 0x0C */ f32 axisUX;
    /* 0x10 */ f32 axisUY;
    /* 0x14 */ f32 axisUZ;
    /* 0x18 */ f32 axisVX;
    /* 0x1C */ f32 axisVY;
    /* 0x20 */ f32 axisVZ;
    /* 0x24 */ f32 axisWX;
    /* 0x28 */ f32 axisWY;
    /* 0x2C */ f32 axisWZ;
    /* 0x30 */ f32 halfU;
    /* 0x34 */ f32 halfV;
    /* 0x38 */ f32 halfW;
    /* 0x3C */ s32 soft; /* inferred: nonzero softens the impact (x0.4 pushout) */
} CollideBox; /* size = 0x40 */
extern CollideBox D_801BFD78[];
extern s32 D_801C0578;

void Box_CollideRider(UnkStruct_80192690* rider);

void Box_CollideRider(UnkStruct_80192690* rider) {
    CollideBox* box;
    f32 dz;
    f32 vCoord; /* reused as the far-face remainder in the W-axis test below */
    f32 wCoord;
    f32 dy;
    f32 minPen;
    f32 dx;
    UnkStruct_8004B0F8_1* cursor;
    s32 hullIdx;
    UnkStruct_8004B0F8_1* hullPt;

    /* Test every box from last to first, and every hull point in turn. */
    for (box = &D_801BFD78[D_801C0578 - 1]; (u32) box >= (u32) D_801BFD78; box--) {
        hullIdx = rider->unk28;
        for (hullPt = &rider->unk90[hullIdx]; (u32) hullPt >= (u32) &rider->unk90; hullPt--, hullIdx--) {
            /* Transform the hull point into the box frame. */
            dx = box->centerX - hullPt->unk0;
            dy = box->centerY - hullPt->unk4;
            dz = box->centerZ - hullPt->unk8;
            minPen = (box->axisUX * dx) + (dy * box->axisUY) + (dz * box->axisUZ);
            if ((minPen < 0.0f) || (box->halfU <= minPen)) {
                continue;
            }
            vCoord = (box->axisVX * dx) + (dy * box->axisVY) + (dz * box->axisVZ);
            if ((vCoord < 0.0f) || (box->halfV <= vCoord)) {
                continue;
            }
            wCoord = (box->axisWX * dx) + (dy * box->axisWY) + (dz * box->axisWZ);
            if ((wCoord < 0.0f) || (box->halfW <= wCoord)) {
                continue;
            }

            /* Snap the penetration to the nearest face, tracking its normal. */
            if (minPen > box->halfU - minPen) {
                minPen = box->halfU - minPen;
                dx = -box->axisUX;
                dy = -box->axisUY;
                dz = -box->axisUZ;
            } else {
                dx = box->axisUX;
                dy = box->axisUY;
                dz = box->axisUZ;
            }

            if (vCoord < minPen) {
                minPen = vCoord;
                dx = box->axisVX;
                dy = box->axisVY;
                dz = box->axisVZ;
            }
            if (minPen > box->halfV - vCoord) {
                minPen = box->halfV - vCoord;
                dx = -box->axisVX;
                dy = -box->axisVY;
                dz = -box->axisVZ;
            }
            if (wCoord < minPen) {
                minPen = wCoord;
                dx = box->axisWX;
                dy = box->axisWY;
                dz = box->axisWZ;
            }
            vCoord = box->halfW - wCoord;
            if (vCoord < minPen) {
                minPen = vCoord;
                dx = -box->axisWX;
                dy = -box->axisWY;
                dz = -box->axisWZ;
            }
            /* Downward faces never collide with hull points 1, 8 and 11. */
            if ((dy <= 0.0f) && ((hullIdx == 1) || (hullIdx == 8) || (hullIdx == 11))) {
                continue;
            }

            /* Push the hull point out along the face normal ... */
            vCoord = ((-dx * hullPt->unkC) - (dy * hullPt->unk10)) - (dz * hullPt->unk14);
            if (box->soft != 0) {
                rider->unk15DE = 1;
                wCoord = 0.4f * vCoord;
            } else {
                wCoord = vCoord;
            }
            /* ... and remember the strongest hit on the rider. */
            if (rider->unkC48 < wCoord) {
                rider->unkC48 = wCoord;
                rider->unk15B4 = dx;
                rider->unk15B8 = dy;
                rider->unk15BC = dz;
            }
            hullPt->unkC += (vCoord * dx);
            hullPt->unk10 += (vCoord * dy);
            hullPt->unk14 += (vCoord * dz);

            /* Shove the whole hull along the penetration normal. */
            dx *= minPen;
            dy *= minPen;
            dz *= minPen;
            for (cursor = &rider->unk90[0]; (u32) cursor < (u32) &rider->unk90[12]; cursor++) {
                cursor->unk0 += dx;
                cursor->unk4 += dy;
                cursor->unk8 += dz;
            }
        }
    }
}

/* Tests one (x, y, z) point against every collision box without moving
 * it. On a hit, writes the nearest face normal to
 * (normalX, normalY, normalZ) and returns the penetration depth;
 * otherwise returns 0.0f. */
f32 Box_QueryPoint(f32 x, f32 y, f32 z, f32* normalX, f32* normalY, f32* normalZ) {
    CollideBox* box;
    f32 vCoord;
    f32 wCoord;
    f32 dy;
    f32 dz;
    f32 minPen;
    f32 dx;

    for (box = &D_801BFD78[D_801C0578 - 1]; (uintptr_t) box >= (uintptr_t) D_801BFD78; box--) {
        dx = box->centerX - x;
        dy = box->centerY - y;
        dz = box->centerZ - z;
        minPen = (dx * box->axisUX) + (dy * box->axisUY) + (dz * box->axisUZ);
        if (minPen < 0 || box->halfU <= minPen) {
            continue;
        }
        vCoord = (dx * box->axisVX) + (dy * box->axisVY) + (dz * box->axisVZ);
        if (vCoord < 0 || box->halfV <= vCoord) {
            continue;
        }
        wCoord = (dx * box->axisWX) + (dy * box->axisWY) + (dz * box->axisWZ);
        if (wCoord < 0 || box->halfW <= wCoord) {
            continue;
        }

        /* Snap the penetration to the nearest face, tracking its normal. */
        if (minPen > box->halfU - minPen) {
            minPen = box->halfU - minPen;
            dx = -box->axisUX;
            dy = -box->axisUY;
            dz = -box->axisUZ;
        } else {
            dx = box->axisUX;
            dy = box->axisUY;
            dz = box->axisUZ;
        }
        if (minPen > vCoord) {
            minPen = vCoord;
            dx = box->axisVX;
            dy = box->axisVY;
            dz = box->axisVZ;
        }

        if (minPen > box->halfV - vCoord) {
            minPen = box->halfV - vCoord;
            dx = -box->axisVX;
            dy = -box->axisVY;
            dz = -box->axisVZ;
        }

        if (wCoord < minPen) {
            minPen = wCoord;
            dx = box->axisWX;
            dy = box->axisWY;
            dz = box->axisWZ;
        }

        if (minPen > box->halfW - wCoord) {
            minPen = box->halfW - wCoord;
            dx = -box->axisWX;
            dy = -box->axisWY;
            dz = -box->axisWZ;
        }
        *normalX = dx;
        *normalY = dy;
        *normalZ = dz;
        return minPen;
    }
    return 0.0f;
}
