#include <ultra64.h>
#include "variables.h"
#include "structs.h"
#include "functions.h"
#include "macros.h"

extern struct UnkStruct_80088B00 D_801C4000;
extern struct UnkStruct_80088B00 D_801C4020;
extern struct UnkStruct_80088B00 D_801C4040;
extern struct UnkStruct_80088B00 D_801C4060;
extern struct UnkStruct_80088B00 D_801C4080;
extern struct UnkStruct_80088B00 D_801C40A0;
extern struct UnkStruct_80088B00 D_801C40C0;
extern struct UnkStruct_80088B00 D_801C40E0;
extern f32 D_801C4058;
extern f32 D_801C4058;

f32 func_801ED090(f32);
f32 func_800C7010(f32);
f32 Math_PointLineDistance(f32 pointX, f32 pointY, f32 lineX0, f32 lineY0, f32 lineX1, f32 lineY1);
void Seg2D_Normalize(struct UnkStruct_80088B00* seg);

/* Course guide segments: builds the 2D guide-segment set (D_801C4020..E0)
 * from the course markers and the rider position, then derives the
 * rider/marker distances and the upcoming-turn intersection test in
 * D_801C3C58. Segment endpoints use the marker positions extended along
 * the marker headings; UnkStruct_80088B00 field names are shared with
 * game/code_3AC00.c and stay as-is. */
void Guide_BuildSegments(void) {
    f32 markX;
    f32 markZ;
    f32 workX;
    f32 workZ;

    /* Lead-in segment between the two upcoming markers. */
    D_801C4020.unk0 = D_801C3C54[D_801C3C58->unk18].unk0;
    D_801C4020.unk4 = D_801C3C54[D_801C3C58->unk18].unk8;
    D_801C4020.unk8 = D_801C3C54[D_801C3C58->unk10].unk0;
    D_801C4020.unkC = D_801C3C54[D_801C3C58->unk10].unk8;

    Seg2D_Normalize(&D_801C4020);
    /* Rider-to-next-marker segment. */
    D_801C4040.unk0 = D_801C3C50->unk44;
    D_801C4040.unk4 = D_801C3C50->unk4C;
    D_801C4040.unk8 = D_801C3C54[D_801C3C58->unk10].unk0;
    D_801C4040.unkC = D_801C3C54[D_801C3C58->unk10].unk8;

    Seg2D_Normalize(&D_801C4040);
    D_801C4060.unk0 = D_801C3C50->unk44;
    D_801C4060.unk4 = D_801C3C50->unk4C;
    D_801C4060.unk8 = D_801C3C54[D_801C3C58->unk14].unk0;
    D_801C4060.unkC = D_801C3C54[D_801C3C58->unk14].unk8;

    Seg2D_Normalize(&D_801C4060);
    D_801C4080.unk0 = D_801C3C50->unk44;
    D_801C4080.unk4 = D_801C3C50->unk4C;

    D_801C4080.unk8 = D_801C3C54[D_801C3C58->unk14].unkC - (D_801C3C54[D_801C3C58->unk14].unk78 * 50.0f);

    D_801C4080.unkC = D_801C3C54[D_801C3C58->unk14].unk14 - (D_801C3C54[D_801C3C58->unk14].unk7C * 50.0f);

    Seg2D_Normalize(&D_801C4080);
    D_801C40A0.unk0 = D_801C3C50->unk44;
    D_801C40A0.unk4 = D_801C3C50->unk4C;

    D_801C40A0.unk8 = D_801C3C54[D_801C3C58->unk14].unk18 + (D_801C3C54[D_801C3C58->unk14].unk78 * 50.f);

    D_801C40A0.unkC = D_801C3C54[D_801C3C58->unk14].unk20 + (D_801C3C54[D_801C3C58->unk14].unk7C * 50.f);

    Seg2D_Normalize(&D_801C40A0);

    D_801C40C0.unk0 = D_801C3C54[D_801C3C58->unk10].unk0 + (D_801C3C54[D_801C3C58->unk10].unk80 * 50);

    D_801C40C0.unk4 = D_801C3C54[D_801C3C58->unk10].unk8 + (D_801C3C54[D_801C3C58->unk10].unk84 * 50);

    D_801C40C0.unk8 = D_801C3C54[D_801C3C58->unk14].unk0 + (D_801C3C54[D_801C3C58->unk14].unk80 * 50);

    D_801C40C0.unkC = D_801C3C54[D_801C3C58->unk14].unk8 + (D_801C3C54[D_801C3C58->unk14].unk84 * 50);

    Seg2D_Normalize(&D_801C40C0);
    D_801C40E0.unk0 = D_801C3C50->unk44;
    D_801C40E0.unk4 = D_801C3C50->unk4C;
    D_801C40E0.unk8 = D_801C3C54[D_801C3C58->unk8].unk0;
    D_801C40E0.unkC = D_801C3C54[D_801C3C58->unk8].unk8;
    Seg2D_Normalize(&D_801C40E0);

    /* Lateral distance from the rider to the previous marker's heading ray. */
    markX = D_801C3C54[D_801C3C58->unk8].unk0;
    markZ = D_801C3C54[D_801C3C58->unk8].unk8;

    D_801C3C58->unk2C = (s32) Math_PointLineDistance(D_801C3C50->unk44, D_801C3C50->unk4C, markX, markZ,
                                            (D_801C3C54[D_801C3C58->unk8].unk78 * 256.0f) + markX,
                                            (D_801C3C54[D_801C3C58->unk8].unk7C * 256.0f) + markZ);

    workX = D_801C3C54[D_801C3C58->unk10].unk0;
    workZ = D_801C3C54[D_801C3C58->unk10].unk8;

    D_801C3C58->unk30 = (s32) Math_PointLineDistance(D_801C3C50->unk44, D_801C3C50->unk4C, workX, workZ,
                                            (D_801C3C54[D_801C3C58->unk10].unk78 * 256.0f) + workX,
                                            (D_801C3C54[D_801C3C58->unk10].unk7C * 256.0f) + workZ);

    /* Straight-line distances between the upcoming markers ... */
    workX = D_801C3C54[D_801C3C58->unk10].unk0 - D_801C3C54[D_801C3C58->unk18].unk0;
    workZ = D_801C3C54[D_801C3C58->unk10].unk8 - D_801C3C54[D_801C3C58->unk18].unk8;
    D_801C3C58->unk34 = (s32) sqrtf(SQ(workX) + SQ(workZ));

    /* ... and from the rider to the previous marker. */
    workX = D_801C3C54[D_801C3C58->unk8].unk0 - D_801C3C50->unk44;
    workZ = D_801C3C54[D_801C3C58->unk8].unk8 - D_801C3C50->unk4C;
    D_801C3C58->unk38 = (s32) sqrtf(SQ(workX) + SQ(workZ));

    /* Upcoming-turn intersection test. */
    D_801C3C58->unk3C = Math_TwoLineSegmentsIntersect(
        workX = D_801C3C54[D_801C3C58->unk10].unk0, workZ = D_801C3C54[D_801C3C58->unk10].unk8,
        (D_801C3C54[D_801C3C58->unk10].unk70 * 256.0f) + workX,
        (D_801C3C54[D_801C3C58->unk10].unk74 * 256.0f) + workZ, D_801C3C50->unk44, D_801C3C50->unk4C);
}

/* Refreshes the off-course flag from the lateral distance, then rebuilds
 * the primary guide segment. */
void Guide_Update(void) {
    if ((D_801C3C58->unk30 < 0x258) || (D_801C4058 < 600.0f)) {
        D_801C3C58->unk6C = 1;
    } else {
        D_801C3C58->unk6C = 0;
    }
    Guide_BuildPrimarySegment(D_801C3C58->unk6C);
}

void Guide_BuildPrimarySegment(s32 arg0) {
    f32 sideOff;
    f32 fwdOff;
    f32 frameKeep; /* unused; preserves the original stack frame */
    if (arg0 != 0) {
        sideOff = 120.0f;
        fwdOff = 120.0f;
    } else {
        sideOff = -50.0f;
        fwdOff = 250.0f;
    }
    D_801C4000.unk0 = D_801C3C50->unk44;
    D_801C4000.unk4 = D_801C3C50->unk4C;
    D_801C4000.unk8 = D_801C3C54[D_801C3C58->unk10].unk0;
    D_801C4000.unkC = D_801C3C54[D_801C3C58->unk10].unk8;

    switch (D_801C3C58->unk1C) {
        case 4:
            break;
        case 0:
            if (D_801C3C54[D_801C3C58->unk10].unkBC != 0) {
                D_801C4000.unk8 += (120.0f * D_801C4040.unk10) - (200.0f * D_801C4040.unk14);
                D_801C4000.unkC += (120.0f * D_801C4040.unk14) + (200.0f * D_801C4040.unk10);
            } else {
                D_801C4000.unk8 +=
                    ((sideOff * D_801C4040.unk10) - (fwdOff * D_801C4040.unk14)) - (0 * D_801C40C0.unk10);
                D_801C4000.unkC +=
                    ((sideOff * D_801C4040.unk14) + (fwdOff * D_801C4040.unk10)) - (0 * D_801C40C0.unk14);
            }
            break;
        case 1:
            if (D_801C3C54[D_801C3C58->unk10].unkBC != 0) {
                D_801C4000.unk8 += (120.0f * D_801C4040.unk10) + (200.0f * D_801C4040.unk14);
                D_801C4000.unkC += (120.0f * D_801C4040.unk14) - (200.0f * D_801C4040.unk10);
            } else {
                D_801C4000.unk8 +=
                    ((sideOff * D_801C4040.unk10) + (fwdOff * D_801C4040.unk14)) - (0 * D_801C40C0.unk10);

                D_801C4000.unkC +=
                    (((sideOff * D_801C4040.unk14) - (fwdOff * D_801C4040.unk10)) - (0 * D_801C40C0.unk14));
            }
            break;
        case 2:
        case 3:
            frameKeep = 120.0f;
            if (Math_TwoLineSegmentsIntersect(
                    D_801C3C50->unk44, D_801C3C50->unk4C,
                    D_801C3C54[D_801C3C58->unk10].unk18 + (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f),

                    D_801C3C54[D_801C3C58->unk10].unk20 + (D_801C3C54[D_801C3C58->unk10].unk7C * 120.0f),
                    D_801C3C54[D_801C3C58->unk14].unk0, D_801C3C54[D_801C3C58->unk14].unk8) == -1) {

                D_801C4000.unk8 = D_801C3C54[D_801C3C58->unk10].unk18 + (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);
                D_801C4000.unkC = D_801C3C54[D_801C3C58->unk10].unk20 + (D_801C3C54[D_801C3C58->unk10].unk7C * 120.0f);
            } else {

                if (Math_TwoLineSegmentsIntersect(
                        D_801C3C50->unk44, D_801C3C50->unk4C,
                        D_801C3C54[D_801C3C58->unk10].unkC - (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f),
                        D_801C3C54[D_801C3C58->unk10].unk14 - (D_801C3C54[D_801C3C58->unk10].unk7C * 120.0f),
                        D_801C3C54[D_801C3C58->unk14].unk0, D_801C3C54[D_801C3C58->unk14].unk8) == 1) {

                    D_801C4000.unk8 =
                        D_801C3C54[D_801C3C58->unk10].unkC - (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);

                    D_801C4000.unkC =
                        D_801C3C54[D_801C3C58->unk10].unk14 - (D_801C3C54[D_801C3C58->unk10].unk7C * 120.0f);
                } else {
                    if (D_801C3C58->unk8 != D_801C3C58->unk10) {
                        if (D_801C3C58->unk24 == 0) {

                            if (Math_TwoLineSegmentsIntersect(
                                    D_801C3C50->unk44, D_801C3C50->unk4C,
                                    D_801C3C54[D_801C3C58->unk18].unk0 - (50.0f * D_801C4040.unk14),
                                    D_801C3C54[D_801C3C58->unk18].unk8 + (50.0f * D_801C4040.unk10),
                                    D_801C3C54[D_801C3C58->unk10].unk0, D_801C3C54[D_801C3C58->unk10].unk8) == 1) {

                                D_801C4000.unk8 = D_801C3C54[D_801C3C58->unk10].unk18 +
                                                  (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);
                                D_801C4000.unkC = D_801C3C54[D_801C3C58->unk10].unk20 +
                                                  (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);
                                break;
                            }
                        }
                        if (D_801C3C58->unk24 == 1) {
                            if (Math_TwoLineSegmentsIntersect(
                                    D_801C3C50->unk44, D_801C3C50->unk4C,
                                    D_801C3C54[D_801C3C58->unk18].unk0 + (50.0f * D_801C4040.unk14),
                                    D_801C3C54[D_801C3C58->unk18].unk8 - (50.0f * D_801C4040.unk10),
                                    D_801C3C54[D_801C3C58->unk10].unk0, D_801C3C54[D_801C3C58->unk10].unk8) == -1) {

                                D_801C4000.unk8 =
                                    D_801C3C54[D_801C3C58->unk10].unkC - (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);
                                D_801C4000.unkC = D_801C3C54[D_801C3C58->unk10].unk14 -
                                                  (D_801C3C54[D_801C3C58->unk10].unk78 * 120.0f);
                            }
                        }
                    }
                }
            }
            break;
    }
    Seg2D_Normalize(&D_801C4000);
}

/* Normalizes a 2D segment in place: sets the unit direction (unk10/unk14)
 * and length (unk18) from the endpoints (unk0/unk4 -> unk8/unkC). */
void Seg2D_Normalize(struct UnkStruct_80088B00* seg) {
    f32 segLenSq;

    seg->unk10 = seg->unk8 - seg->unk0;
    seg->unk14 = seg->unkC - seg->unk4;

    segLenSq = SQ(seg->unk10) + SQ(seg->unk14);
    seg->unk18 = segLenSq;
    if (segLenSq != 0.0f) {
        seg->unk18 = sqrtf(seg->unk18);
        seg->unk10 = (f32) (seg->unk10 / seg->unk18);
        seg->unk14 = (f32) (seg->unk14 / seg->unk18);
    }
}

void Math_Normalize_VectorComponents(f32* componentX, f32* componentY) {
    f32 result_square;
    f32 reciprocal;

    result_square = SQ(*componentX) + SQ(*componentY);
    if (result_square != 0.0f) {
        reciprocal = 1.0f / sqrtf(result_square);
        *componentX *= reciprocal;
        *componentY *= reciprocal;
    }
}

/* Computes the upcoming-turn angle (unk28) from the sine between the
 * rider-to-marker direction and the marker-to-marker direction. */
void Guide_ComputeTurnAngle(void) {
    f32 toMarkX;
    f32 toMarkZ;
    f32 markDirX;
    f32 markDirZ;
    f32 turnSin;
    f32 align;

    toMarkX = D_801C3C54[D_801C3C58->unk10].unk0 - D_801C3C50->unk44;
    toMarkZ = D_801C3C54[D_801C3C58->unk10].unk8 - D_801C3C50->unk4C;
    markDirX = D_801C3C54[D_801C3C58->unk14].unk0 - D_801C3C54[D_801C3C58->unk10].unk0;
    markDirZ = D_801C3C54[D_801C3C58->unk14].unk8 - D_801C3C54[D_801C3C58->unk10].unk8;
    Math_Normalize_VectorComponents(&toMarkX, &toMarkZ);
    Math_Normalize_VectorComponents(&markDirX, &markDirZ);

    turnSin = (toMarkX * markDirZ) - (markDirX * toMarkZ);
    if (D_801C3C58->unk1C == 0) {
        turnSin = turnSin * -1.0f;
    }
    if (turnSin < 0.0f) {
        turnSin = 0.0f;
    }

    align = 1.0f - SQ(turnSin);
    if (SQ(turnSin) > 1.0f) {
        align = 0.0f;
    }
    D_801C3C58->unk28 = (s32) func_801ED090(sqrtf(align));
}

/* Absolute distance from a point to the infinite line through two points. */
f32 Math_PointLineDistance(f32 pointX, f32 pointY, f32 lineX0, f32 lineY0, f32 lineX1, f32 lineY1) {
    f32 slope;
    f32 numer;
    f32 lineLen;
    f32 negOne;
    f32 frameKeep; /* unused; preserves the original stack frame */

    if (lineX0 == lineX1) {
        return (lineX0 <= pointX) ? pointX - lineX0 : -(pointX - lineX0);
    }

    slope = (lineY1 - lineY0) / (lineX1 - lineX0);
    negOne = -SQ(1);
    lineLen = sqrtf(SQ(slope) + SQ(negOne));
    numer = (slope * pointX) + (-1 * pointY) + (lineY0 - (slope * lineX0));

    return FABS(numer) / lineLen;
}
