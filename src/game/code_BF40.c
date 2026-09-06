#include "global.h"

extern s32 D_801924F0;
extern s32 D_801924F4;
extern s32 D_801924FC;
extern s32 D_80192500;
extern s32 D_80192508;
extern s32 D_80192510;
extern s32 D_80192518;
extern s32 D_80192520;
extern s32 D_80192528;
extern s16* D_80192530;
extern u8* D_80192534;
extern struct UnkStruct_8004B0F8_1* D_80192538;

/* 2D course-wall collision on a spatial-hash grid.
 * D_801924F4/D_80192500 hold the grid origin (x/z), D_801924FC/D_80192508
 * the grid extents; D_801924F0 swaps the cell-index orientation.
 * D_80192530 is the cell table, D_80192534 the per-cell segment-index
 * lists (zero-terminated), D_80192538 the wall segment array.
 * Shared struct field names (UnkStruct_8004B0F8*) are left as-is: they are
 * also used by game/code_39F00.c and need a coordinated rename pass.
 * The `(0, D_80192538)` comma expressions below are load-bearing for
 * byte-match; do not simplify them. */
void Wall_CollideRider(struct UnkStruct_801C3C50* rider, struct UnkStruct_8004B0F8* walls);
void Wall_CollideRider(struct UnkStruct_801C3C50* rider, struct UnkStruct_8004B0F8* walls) {
    f32 penDepth;
    f32 edgeDist;
    s16* cellSeg;
    s32 relX;
    s32 relZ;
    struct UnkStruct_8004B0F8_1* cursor;
    struct UnkStruct_8004B0F8_1* hullPt;
    u8* cellByte;
    struct UnkStruct_8004B0F8_1* hullBase = walls->unk30;
    struct UnkStruct_8004B0F8_1* wallSeg;

    /* Test every hull point from last to first. */
    for (hullPt = &walls->unk30[walls->unk28]; hullPt >= hullBase; hullPt--) {

        relX = (s32) hullPt->unk0 - D_801924F4;
        if ((relX >= 0) && (relX < D_801924FC)) {
            relZ = (s32) hullPt->unk8 - D_80192500;
            if ((relZ >= 0) && (relZ < D_80192508)) {
                if (D_801924F0 != 0) {
                    cellSeg = &(0, D_80192530)[((relZ >> D_80192528) | ((relX >> D_80192520) << D_80192518))];
                } else {
                    cellSeg = &(0, D_80192530)[((relX >> D_80192520) | ((relZ >> D_80192528) << D_80192510))];
                }
                cellByte = &D_80192534[*cellSeg];

                while (*cellByte != 0) {
                    wallSeg = (*cellByte) + (0, D_80192538); // FAKE

                    edgeDist =
                        ((wallSeg->unk0 - hullPt->unk0) * wallSeg->unk8) + ((wallSeg->unk4 - hullPt->unk8) * wallSeg->unkC);

                    if ((edgeDist > 0.0f) && (edgeDist < 16.0f)) {

                        penDepth = ((hullPt->unk0 - wallSeg->unk0) * wallSeg->unk10) +
                                  ((hullPt->unk8 - wallSeg->unk4) * wallSeg->unk14);

                        if ((penDepth > 0.0f) && (penDepth < wallSeg->unk18)) {
                            penDepth = (-hullPt->unkC * wallSeg->unk8) - (hullPt->unk14 * wallSeg->unkC);
                            if (penDepth > 0.0f) {
                                /* Strongest hit so far: record depth + wall normal. */
                                if (rider->unkC44 < penDepth) {
                                    rider->unkC44 = penDepth;
                                    rider->unk15B4 = wallSeg->unk8;
                                    rider->unk15B8 = 0;
                                    rider->unk15BC = wallSeg->unkC;
                                }

                                hullPt->unkC = (f32) (hullPt->unkC + (penDepth * wallSeg->unk8));

                                hullPt->unk14 = (f32) (hullPt->unk14 + (penDepth * wallSeg->unkC));

                                penDepth = (wallSeg->unk8 * edgeDist);
                                edgeDist = (wallSeg->unkC * edgeDist);

                                /* Shove the whole hull along the wall tangent. */
                                for (cursor = walls->unk30; cursor < &walls->unk30[12]; cursor++) {

                                    cursor->unk0 += penDepth;
                                    cursor->unk8 += edgeDist;
                                }
                            }
                        }
                    }

                    cellByte++;
                }
                hullBase = walls->unk30;
            }
        }
    }
}

/* Tests one (x, z) point against the wall grid, pushing it out of any
 * wall it penetrates. Returns 1 if a wall was hit, 0 otherwise. */
s32 Wall_CollidePoint(f32* x, f32* z) {
    f32 edgeDist;
    f32 penDepth;
    f32 alongWall;
    s16* cellSeg;
    s32 relX;
    s32 relZ;
    s32 hit;
    u8* cellByte;
    struct UnkStruct_8004B0F8_1* wallSeg;

    relX = (s32) *x - D_801924F4;
    if ((relX < 0) || (relX >= D_801924FC)) {
        return 0;
    }
    relZ = (s32) *z - D_80192500;
    if ((relZ < 0) || (relZ >= D_80192508)) {
        return 0;
    }

    if (D_801924F0 != 0) {
        cellSeg = &(0, D_80192530)[((relZ >> D_80192528) | ((relX >> D_80192520) << D_80192518))];
    } else {
        cellSeg = &(0, D_80192530)[((relX >> D_80192520) | ((relZ >> D_80192528) << D_80192510))];
    }

    hit = 0;
    cellByte = D_80192534 + *cellSeg;
    while (*cellByte != 0) {
        wallSeg = (*cellByte + (0, D_80192538)); // FAKE
        edgeDist = ((wallSeg->unk0 - *x) * wallSeg->unk8) + ((wallSeg->unk4 - *z) * wallSeg->unkC);
        if ((edgeDist > 0.0f) && (edgeDist < 32.0f)) {
            alongWall = ((*x - wallSeg->unk0) * wallSeg->unk10) + ((*z - wallSeg->unk4) * wallSeg->unk14);
            if ((alongWall > 0.0f) && (alongWall < wallSeg->unk18)) {
                hit = 1;
                *x += edgeDist * wallSeg->unk8;
                *z += (edgeDist * wallSeg->unkC);
            }
        }
        cellByte++;
    }
    return hit;
}

/* Tests one (x, z) point against the wall grid without moving it.
 * On a hit, writes the wall normal to (normalX, normalZ) and returns the
 * edge distance; otherwise returns 0.0f. */
f32 Wall_QueryPoint(f32 x, f32 z, f32* normalX, f32* normalZ) {
    UnkStruct_8004B0F8_1* wallSeg;
    f32 edgeDist;
    f32 alongWall;
    s16* cellSeg;
    s32 relX;
    s32 relZ;
    u8* cellByte;

    relX = (s32) x - D_801924F4;
    if ((relX < 0) || (relX >= D_801924FC)) {
        return 0.0f;
    }
    relZ = (s32) z - D_80192500;
    if ((relZ < 0) || (relZ >= D_80192508)) {
        return 0.0f;
    }
    if (D_801924F0 != 0) {
        cellSeg = &(0, D_80192530)[((relZ >> D_80192528) | ((relX >> D_80192520) << D_80192518))];
    } else {
        cellSeg = &(0, D_80192530)[((relX >> D_80192520) | ((relZ >> D_80192528) << D_80192510))];
    }
    cellByte = &D_80192534[*cellSeg];
    while (*cellByte != 0) {
        wallSeg = (*cellByte + (0, D_80192538)); // FAKE
        edgeDist = ((wallSeg->unk0 - x) * wallSeg->unk8) + ((wallSeg->unk4 - z) * wallSeg->unkC);
        if ((edgeDist > 0.0f) && (edgeDist < 32.0f)) {
            alongWall = ((x - wallSeg->unk0) * wallSeg->unk10) + ((z - wallSeg->unk4) * wallSeg->unk14);
            if ((alongWall > 0.0f) && (alongWall < wallSeg->unk18)) {
                *normalX = wallSeg->unk8;
                *normalZ = wallSeg->unkC;
                return edgeDist;
            }
        }
        cellByte++;
    }
    return 0.0f;
}
