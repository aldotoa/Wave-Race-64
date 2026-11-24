#include "global.h"
#include "rider.h"

struct unk_D_801C3C60 {
    struct unk_D_801C3C58* unk0;
    char pad[0x4C];
    int unk5C;
    char pad1[0x94];
};

struct UnkStruct_801C2C70 {
    s32 unk0;
    char pad[0x374];
};

struct UnkStruct_801CB058 {
    char pad[0xC0];
    s32 unkC0;
    s32 unkC4;
    s32 unkC8;
    char padCC[0x3C];
    f32 unk108;
};

void func_800890B4(void);

extern s32 D_800D48DC;
extern s32 D_801C26C0[];
extern struct unk_D_801C3C60 D_801C3C60[];
extern s32 D_801C4100[];
extern s32 D_800D476C;
extern s32 D_800D4770;
extern s8 D_800D9888;
extern s32 D_800D98CC;
extern s32 D_800D98D0;
extern s32 D_800D98D4;
extern u8 D_800E5150[2][4];
extern struct UnkStruct_801C2C70 D_801C2C70[];
extern struct UnkStruct_801CB058 D_801CB058;

void func_80088EA0(void) {
}

/* Returns int (no return statement): the original was evidently defined with
   an int return type. As a void function, func_800890B4's register
   coloring changes even though this function's own code is identical. */
s32 func_80088EA8(void) {
    /* Rider grid shuffle: index riders, reset their slot fields, then give
       each of the first gRiders - 1 riders a random free grid slot that is
       not the player's. The random pick needs several compiler-steering
       constructs (all no-ops): `raw` starts at 0 and is read by an empty
       `if` at the top of each pass, which keeps the raw Rand() value live
       across the loop (retail's dead `move a1,v0`); the empty `if (pick)`
       and keeping the last three statements on one line fix the v0/a0
       copy order (IDO schedules by source line). */
    s32 i;
    s32 slot;
    s32 raw = 0;
    s32 pick;
    s32 idx;

    for (i = 0; i < gRiders; i++) {
        D_801C4100[D_801C26C0[i]] = i;
    }
    for (i = 0; i < gRiders; i++) {
        D_801C3C58->unk60 = 1.0f;
    }
    for (i = 0; i < gRiders; i++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[i];
        D_801C3C58->unk5C = -1;
    }
    for (slot = i = 0; i < (gRiders - 1); slot++, i++) {
        if (raw) {}
        SysUtils_Rand();
        raw = SysUtils_Rand();
        pick = (u32) raw >> 8;
        pick = pick & 3;
        // Must stay on one line: IDO line markers change scheduling here.
        // clang-format off
        D_801C3C58 = (struct unk_D_801C3C60*) &D_801C3C60[pick]; if (pick) {} idx = pick;
        // clang-format on
        while (D_801C3C58->unk5C != -1 || idx == D_800D48DC) {
            idx = (idx % gRiders) + 1;
            D_801C3C58 = (struct unk_D_801C3C60*) &D_801C3C60[idx];
        }
        D_801C3C58->unk5C = slot;
    }
}

extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern s32 D_801C4110;
extern s32 D_801C4118[];

void func_800890B4(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    Vtx* vtxA;
    Vtx* vtxB;

    /* `(i ^ 0)` keeps IDO from rewriting this bound as `bne` against a
       held 4 (retail keeps `slti`); `j` doubling as the switch value and
       the unk80 row counter fixes the v0/v1 coloring of this loop. */
    for (i = 0; (i ^ 0) < 4; i++) {
        D_801C3C50 = (struct UnkStruct_801C3C50*) &D_80192690[i];
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[i];
        D_801C3C58->unk0 = i;
        D_801C3C58->currentRider = D_801C3C50->unkB68;
        D_801C3C58->unk74 = 1;
        D_801C3C58->unk8C = 0;
        D_801C3C58->unkAC = 0;
        D_801C3C58->unkB0 = 0;
        D_801C3C58->unkB4 = 1;
        D_801C3C58->pad58 = 0;
        D_801C3C58->unkA0 = 0;
        D_801C3C58->unkD8 = 0;
        D_801C3C58->unkDC[0] = 0;
        j = D_801C3C50->unkB64;
        switch (j) {
            case 0:
            case 1:
            case 2:
                D_801C3C58->unk64 = 32.0f;
                break;
            case 3:
                D_801C3C58->unk64 = 24.0f;
                break;
        }
    }

    func_80088EA8();

    for (j = 0; j < 4; j++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[j];
        for (k = 0; k < 3; k++) {
            D_801C3C58->unk80[k] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        SysUtils_Rand();
        if (((SysUtils_Rand() >> 8) & 3) == 0) {
            SysUtils_Rand();
            D_801C3C58 = (struct_801C3C58*) &D_801C3C60[(SysUtils_Rand() >> 8) & 3];
            D_801C3C58->unk80[i] = 1;
        }
    }

    for (i = 0; i < 3; i++) {
        D_801C3C58 = (struct_801C3C58*) &D_801C3C60[3];
    }

    for (j = 0; j < 2; j++) {
        vtxA = D_801C43F8[j].unk2A0;
        vtxB = D_801C43F8[j].unk2D0;
        for (i = 0; i < 3; i++) {
            (vtxA + i)->v.cn[0] = 0xFF;
            (vtxA + i)->v.cn[1] = 0;
            (vtxA + i)->v.cn[2] = 0;
            (vtxA + i)->v.cn[3] = 0xFF;
        }
        for (i = 0; i < 4; i++) {
            (vtxB + i)->v.ob[1] = 0;
            (vtxB + i)->v.cn[0] = 0xFF;
            (vtxB + i)->v.cn[1] = 0xFF;
            (vtxB + i)->v.cn[2] = 0xFF;
        }
        D_801C4110 = 0;
        for (i = 0; i < D_801BFA40; i++) {
            if (D_801BC940[i].unk4C == 1) {
                D_801C4118[D_801C4110++] = i;
            }
        }
    }
}

void func_800893A8(void) {
    func_800890B4();
    D_800D476C = D_801CB058.unkC4;
    D_800D4770 = D_801CB058.unkC8;
    if (gCourseID == DRAKE_LAKE) {
        D_800D9888 = 1;
        D_801CB058.unk108 = 0.0f;
    } else {
        D_800D9888 = 0;
    }
    switch (D_800E5150[gDifficulty][D_801C2C70[D_800D48DC].unk0]) {
        case 0x8F:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x90:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x91:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x92:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x2EE;
            D_800D98D4 = 0x44C;
            return;
        case 0x93:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x94:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
            return;
        case 0x95:
            D_800D98CC = 0x952;
            D_800D98D0 = 0x316;
            D_800D98D4 = 0x33E;
        default:
            break;
    }
}
