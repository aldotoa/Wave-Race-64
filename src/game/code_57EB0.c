#include "global.h"
#include "macros.h"
#include "camera.h"

/* Second half of the HUD overlay code. Retail .rodata has a 4-byte alignment pad at
 * 0x800EB54C in front of func_8009D6B0's jump table and func_8009D6B0 itself is 16-aligned,
 * so this is an original file boundary (split from code_52CD0.c). */

typedef struct UnkStruct_801CEBE0 {
    /* 0x00 */ Vec3f unk0;
    /* 0x0C */ Vec3f unkC;
    /* 0x18 */ s32 pad18;
    /* 0x1C */ u8 unk1C;
    s32 pad;
    /* 0x24 */ Vec3f unk24;
    /* 0x30 */ Vec3f unk30;
    /* 0x3C */ Vec3f unk3C;
} UnkStruct_801CEBE0;

typedef struct UnkStruct_800AC098_src {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
} UnkStruct_800AC098_src;

typedef struct UnkStruct_801CE780_unk4_unk4_s {
    /* 0x0 */ s16 unk0; /* inferred */
    /* 0x2 */ s16 unk2; /* inferred */
    /* 0x4 */ s16 unk4; /* inferred */
    /* 0x6 */ s8 unk6;  /* inferred */
    /* 0x7 */ s8 unk7;  /* inferred */
    /* 0x8 */ s8 unk8;  /* inferred */
    /* 0x9 */ s8 unk9;  /* inferred */
    /* 0xA */ s8 unkA;  /* inferred */
    /* 0xB */ s8 unkB;  /* inferred */
} UnkStruct_801CE780_unk4_unk4;

typedef struct UnkStruct_801CE780_unk4_s {
    /* 0x00 */ s16 unk0; /* inferred */
    /* 0x02 */ char pad2[2];
    /* 0x04 */ UnkStruct_801CE780_unk4_unk4* unk4; /* inferred */
    /* 0x08 */ s16* unk8;                          /* inferred */
    /* 0x0C */ s16* unkC;                          /* inferred */
    /* 0x10 */ s16* unk10;                         /* inferred */
    /* 0x14 */ s16* unk14;                         /* inferred */
    /* 0x18 */ s16* unk18;                         /* inferred */
    /* 0x1C */ s16* unk1C;                         /* inferred */
    /* 0x20 */ s16* unk20;                         /* inferred */
} UnkStruct_801CE780_unk4;

typedef struct UnkStruct_801CE780_s {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ UnkStruct_801CE780_unk4** unk4; /* inferred */
    /* 0x08 */ u32 unk8;                       /* inferred */
    /* 0x0C */ u32 unkC;                       /* inferred */
    /* 0x10 */ u32 unk10;                      /* inferred */
    /* 0x14 */ u32 unk14;                      /* inferred */
    /* 0x18 */ u32 unk18;                      /* inferred */
    /* 0x1C */ u32 unk1C;                      /* inferred */
    /* 0x20 */ u32 unk20;                      /* inferred */
    /* 0x24 */ u32 unk24;                      /* inferred */
    /* 0x28 */ u32 unk28;                      /* inferred */
} UnkStruct_801CE780;

typedef struct UnkStruct_801CF0D8_s {
    /* 0x00 */ s32 unk0;        /* inferred */
    /* 0x04 */ char pad4[0xB8]; /* maybe part of unk0[0x2F]? */
} UnkStruct_801CF0D8;

extern s32 D_801D06B8;
extern f32 D_801D075C;
extern f32 D_801D0760;
extern f32 D_801D0764;
extern s16 D_801CE776;
extern s16 D_801CE770;
extern s16 D_801CE76C;
extern UnkStruct_801CE780 D_801CE780[];
extern UnkStruct_801CF0D8 D_801CF0D8[];
extern Gfx D_800E6CA0[];
extern Gfx D_800E6CF8[];
extern s16 D_801CE774;
extern s16 D_801CE76E;
extern s32 D_801D0738;
extern s32 D_800E62C8;
extern s32 D_800E62CC;
extern s16 D_801CE768[];

Gfx* func_800916B4(Gfx*);
Gfx* func_8009DB90(Gfx*, s32);
Gfx* func_8009DC10(Gfx*, s32);
Gfx* func_8009E794(Gfx*, s32);
Gfx* func_8009E814(Gfx*, s32);
Gfx* func_8009F398(Gfx*, s32);
Gfx* func_8009FCB0(Gfx*, s32);
Gfx* func_800A063C(Gfx*, s32);
Gfx* func_800A10E4(Gfx*, s32);
Gfx* func_800A16F0(Gfx*, s32);
Gfx* func_800A1CFC(Gfx*, s32);
Gfx* func_800A2308(Gfx*, s32);
Gfx* func_800A28F4(Gfx*, s32);
s32 func_800ADC8C(s32);
void func_800ADD14(void);
void func_800A2B24(s32);
void func_801E4C60(Mtx*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
s32 func_8009A460(void (*arg0)(UnkStruct_801CF060*), UnkStruct_801CF060* arg1, s16 arg2, s16 arg3);
void func_8009C2CC(UnkStruct_801CEBE0* arg0);
f32 func_8009D3AC(f32 arg0, f32 arg1);
f32 func_8009D4A8(f32 arg0, f32 arg1);
f32 func_8009D4DC(f32 arg0, f32 arg1);
f32 Math_Normalize_Angle(f32 x);
f32 func_8009D564(f32 arg0);
void func_8009D5C0(void);

/* Returns the vertex-table entry for a HUD buoy piece: arg0 selects the model group and
 * which per-piece index list to use. Original falls off the end for unhandled arg0 values
 * (v0 still holds the copy of arg0 used as the second switch selector). */
UnkStruct_801CE780_unk4_unk4* func_8009D6B0(s32 arg0, s32 arg1, s32 arg2) {
    s32 sw;
    s32 v1;
    UnkStruct_801CE780_unk4** tbl;
    UnkStruct_801CE780_unk4* p;
    s32 idx;
    s32 sp8;

    sw = arg0;
    switch (sw) {
        case 6:
            sp8 = 0;
            break;
        case 5:
            sp8 = 1;
            break;
        case 7:
        case 8:
        case 9:
            sp8 = 2;
            break;
        case 3:
        case 4:
            sp8 = 3;
            break;
        case 10:
            sp8 = 4;
            break;
        case 1:
        case 2:
            sp8 = 6;
            break;
        case 12:
            sp8 = 7;
            break;
    }
    v1 = D_801CE768[sp8];
    switch (arg0) {
        case 6:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unk8[arg2];
            return p->unk4 + idx;
        case 5:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unk10[arg2];
            return p->unk4 + idx;
        case 7:
        case 8:
        case 9:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unkC[arg2];
            return p->unk4 + idx;
        case 3:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unk8[arg2];
            return p->unk4 + idx;
        case 10:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unkC[arg2];
            return p->unk4 + idx;
        case 1:
            tbl = D_801CE780[v1].unk4;
            p = tbl[arg1];
            idx = p->unk8[arg2];
            return p->unk4 + idx;
    }
}

#ifdef NON_MATCHING
Gfx* func_8009D96C(Gfx* arg0, s32 arg1, f32 arg2) {
    /* Buoy power meter level bar display list builder */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_8009D96C.s")
#endif

Gfx* func_8009D96C(Gfx*, s32, f32);

typedef struct UnkStruct_801CE798 {
    s32 unk0;
    char pad[0x28];
} UnkStruct_801CE798;
extern UnkStruct_801CE798 D_801CE798[];

Gfx* func_8009DB90(Gfx* dl, s32 arg1) {
    UNUSED s32 pad;
    s32 sp18;

    sp18 = D_801CE774;
    gSPDisplayList(dl++, D_800E6CA0);
    dl = func_8009D96C(dl++, arg1, 0.1f);
    gSPDisplayList(dl++, D_801CE798[sp18].unk0);
    return dl;
}

#ifdef NON_MATCHING
Gfx* func_8009DC10(Gfx* arg0, s32 arg1) {
    /* Speedometer dial needle renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_8009DC10.s")
#endif

Gfx* func_8009E794(Gfx* dl, s32 arg1) {
    UNUSED s32 pad;
    s32 sp18;

    sp18 = D_801CE76E;
    gSPDisplayList(dl++, D_800E6CA0);
    dl = func_8009D96C(dl++, arg1, 0.2f);
    gSPDisplayList(dl++, D_801CE798[sp18].unk0);
    return dl;
}

Gfx* func_8009E814(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 index;
    s32 sp68;
    s32 var_s3;

    index = D_801CE76E;

    v1 = D_801CE780[index].unk4;

    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }

    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CA0);

    gdl = func_8009D96C(gdl, arg1, 0.2f);

    var_s3 = temp_s4->unk14[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk20[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk1C[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk18[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

#ifdef NON_MATCHING
Gfx* func_8009F398(Gfx* arg0, s32 arg1) {
    /* Tachometer RPM indicator display list generator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_8009F398.s")
#endif

#ifdef NON_MATCHING
Gfx* func_8009FCB0(Gfx* arg0, s32 arg1) {
    /* Lap counter digit sprite renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_8009FCB0.s")
#endif

#ifdef NON_MATCHING
Gfx* func_800A063C(Gfx* arg0, s32 arg1) {
    /* Race timer millisecond split renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A063C.s")
#endif

Gfx* func_800A10E4(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 var_s3;
    s32 sp68;
    s32 pad[4];
    s32 index;

    index = D_801CE76C;
    v1 = D_801CE780[index].unk4;
    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }
    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A16F0(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 var_s3;
    s32 sp68;
    s32 pad[4];
    s32 index;

    index = D_801CE76C;
    v1 = D_801CE780[index].unk4;
    temp_s4 = v1[1];
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }
    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk14);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk1C);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk18);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A1CFC(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 var_s3;
    s32 sp68;
    s32 pad[4];
    s32 index;

    index = D_801CE76C;
    v1 = D_801CE780[index].unk4;
    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }
    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    if (arg1 < 12) {
        gdl = func_8009D96C(gdl, arg1, 0.3f);
    } else {
        gdl = func_8009D96C(gdl, arg1, 0.2f);
    }
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk20);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk28);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk24);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A2308(Gfx* gdl, s32 arg1) {
    UnkStruct_801CE780_unk4* temp_s4;
    UnkStruct_801CE780_unk4** v1;
    s32 var_s3;
    s32 sp68;
    s32 pad[4];
    s32 index;

    index = D_801CE770;
    v1 = D_801CE780[index].unk4;
    temp_s4 = *v1;
    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (D_801CF060[arg1].unk78 + 1) % temp_s4->unk0;
    }
    sp68 = D_801CF0D8[arg1].unk0 % temp_s4->unk0;
    gSPDisplayList(gdl++, D_800E6CF8);
    gdl = func_8009D96C(gdl, arg1, 0.1f);
    var_s3 = temp_s4->unkC[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk8);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk8[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unk10);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    var_s3 = temp_s4->unk10[sp68];
    func_801E4C60(&D_801C43F8[D_8011F8E0].unk5D0[D_801D06B8], temp_s4->unk4[var_s3].unk6, temp_s4->unk4[var_s3].unk7,
                  temp_s4->unk4[var_s3].unk8, temp_s4->unk4[var_s3].unk9, temp_s4->unk4[var_s3].unkA,
                  temp_s4->unk4[var_s3].unkB, temp_s4->unk4[var_s3].unk0, temp_s4->unk4[var_s3].unk2,
                  temp_s4->unk4[var_s3].unk4, 1.0f);
    gSPMatrix(gdl++, &D_6000000->unk5D0[D_801D06B8++], G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(gdl++, D_801CE780[index].unkC);
    gSPPopMatrix(gdl++, G_MTX_MODELVIEW);
    return gdl;
}

Gfx* func_800A28F4(Gfx* gdl, s32 arg1) {
    StructVarS0* temp_t0;
    s32 sp68;
    StructVarS0* temp_t0_2;
    UnkStruct_801CE780* temp_a2;
    s32 pad;

    if (gCurrentPauseMenuOption == -1) {
        D_801CF060[arg1].unk78 = (s32) (D_801CF060[arg1].unk78 + 1) % 2;
    }
    sp68 = D_801CE776;
    gSPDisplayList(gdl++, D_800E6CA0);
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_OPA_SURF2);
    gdl = func_8009D96C(gdl, arg1, 0.4f);
    gSPDisplayList(gdl++, D_801CE780[sp68].unk8);
    gSPClearGeometryMode(gdl++, G_ZBUFFER | G_TEXTURE_ENABLE | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                                    G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | 0xFFE0CDF8);
    gSPSetGeometryMode(gdl++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gdl++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdl++);
    gDPSetCombineMode(gdl++, G_CC_DECALRGBA, G_CC_PASS2);
    gDPSetRenderMode(gdl++, G_RM_PASS, G_RM_AA_ZB_XLU_SURF2);

    if (D_801CF060[arg1].unk78 == 0) {
        gSPDisplayList(gdl++, D_801CE780[sp68].unkC);
    } else {
        gSPDisplayList(gdl++, D_801CE780[sp68].unk10);
    }
    return gdl;
}

#ifdef NON_MATCHING
void func_800A2B24(s32 arg0) {
    /* Course mini-map track contour display list builder */
    (void) arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A2B24.s")
#endif

#ifdef NON_MATCHING
void func_800A52D8(s32 arg0, f32 arg1) {
    /* Stunt score numerical counter display list builder */
    (void) arg0;
    (void) arg1;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A52D8.s")
#endif

void func_800C1E0C(f32);

void func_800A5C74(void) {
    camera_unk_1* temp_s1;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f20;
    s32 i;

    var_f20 = 1600000.0f;
    temp_s1 = &gCameraPerspective[D_80223930];
    for (i = 0; i < 30; i++) {
        if (D_801CF060[i].unk0 == 1) {
            temp_f0 = func_8009D4A8(temp_s1->unk4C - D_801CF060[i].unkC, temp_s1->unk54 - D_801CF060[i].unk14);
            if (temp_f0 < var_f20) {
                var_f20 = temp_f0;
            }
        }
    }
    var_f20 = var_f20 / 40.0f;
    if (var_f20 > 50.0f) {
        func_800C1DEC();
    }
    func_800C1E0C(var_f20);
}

extern s32 D_800D4720;
extern f32 D_80192420[];
extern f32 D_801D06D4;

// TODO: Migrate rodata

void func_800A5D70(s32 arg0) {
    camera_unk_1* cam;
    s32 idx; // Index for D_801CF060
    s32 angle;
    u32 rand_num;

    cam = &gCameraPerspective[D_80223930];
    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 11) {
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk8C + 90.0f);
            angle = (s32) ((D_801CF060[arg0].unk8C / 360.0f) * 4096.0f);
            D_801CF060[arg0].unkC = D_801CF060[arg0].unk80 + (D_801CF060[arg0].unk70 * COS(angle));
            D_801CF060[arg0].unk14 = D_801CF060[arg0].unk88 + (D_801CF060[arg0].unk70 * SIN(angle));
            D_801CF060[arg0].unk8C += 0.5f;
        } else if ((D_801CF060[arg0].unk8 == 5) || (D_801CF060[arg0].unk8 == 10)) {
            D_801CF060[arg0].unk74 = 0;
            D_801D0760 = func_8009D564(-func_8009D3AC(cam->unkF0, cam->unkF4));
            idx = D_801CF060[arg0].unk7C;
            if (idx == 0xFF) {
                if ((D_801CF060[arg0].unk8 == 5) || (D_801CF060[arg0].unk8 == 10)) {
                    D_801D0754 =
                        (COS(ANGLE_TO_CUSTOM_UNITS(D_801D0760)) * ((300.0f + (D_801D06D4 * 10.0f)))) + D_801D06BC;
                    D_801D075C =
                        (SIN(ANGLE_TO_CUSTOM_UNITS(D_801D0760)) * ((300.0f + (D_801D06D4 * 10.0f)))) + D_801D06C4;
                }
            } else {
                D_801D0754 = D_801CF060[idx].unkC;
                D_801D075C = D_801CF060[idx].unk14;
            }
            if (D_801CF060[arg0].unk8 == 5) {
                D_801D0760 = Math_Normalize_Angle(
                    func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                    D_801CF060[arg0].unk18);
            }
            if (D_801CF060[arg0].unk8 == 10) {
                D_801D0760 = Math_Normalize_Angle(
                    (func_8009D3AC(D_801D06BC - D_801CF060[arg0].unkC, -(D_801D06C4 - D_801CF060[arg0].unk14)) -
                     D_801CF060[arg0].unk18) +
                    180.0f);
            }
            if (D_801CF060[arg0].unk0 == 7) {
                D_801D0764 = 0.5f;
            }
            if (D_801CF060[arg0].unk0 == 8) {
                D_801D0764 = 0.7f;
            }
            if (D_801CF060[arg0].unk0 == 9) {
                D_801D0764 = 1.0f;
            }
            if (D_801CF060[arg0].unk0 == 10) {
                D_801D0764 = 0.7f;
            }
            if (D_801CF060[arg0].unk8 == 5) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + D_801D0764);
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 2));
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - D_801D0764);
                    if (D_801D0760 < -45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 2));
                    }
                }

                D_801D0764 = ((180.0f - FABS(D_801D0760)) / 180.0f) * 10.0f;
            }
            if (D_801CF060[arg0].unk8 == 10) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 3.0f));
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 + (D_801D0764 * 6.0f));
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 3.0f));
                    if (D_801D0760 < -45.0f) {
                        D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18 - (D_801D0764 * 6.0f));
                    }
                }

                D_801D0764 = ((180.0f - FABS(D_801D0760)) / 180.0f) * 25.0f;
            }

            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = (D_801D0760 + ((D_801D0764 - D_801D0760) * 0.1));
            ;
            angle = (s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f);
            D_801CF060[arg0].unkC += (D_801CF060[arg0].unk24 = COS(angle) * D_801D0764);
            D_801CF060[arg0].unk14 += (D_801CF060[arg0].unk2C = SIN(angle) * D_801D0764);
            if (D_801CF060[arg0].unk8 == 5) {
                if (func_8009D4DC(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) <
                    SQ((D_801D06D4 * 500.0f))) {
                    D_801CF060[arg0].unk8 = 10;
                }
            }
            if ((D_801CF060[arg0].unk8 == 10) &&
                (1000000.0f < func_8009D4DC(D_801D06BC - D_801CF060[arg0].unkC, D_801D06C4 - D_801CF060[arg0].unk14))) {
                D_801CF060[arg0].unk8 = 5;
            }
            D_801D0754 = D_80192420[2] - D_801CF060[arg0].unkC;
            D_801D0758 = D_80192420[3] - D_801CF060[arg0].unk14;
            if (((f64) D_80192420[4] * 0.9 * 0.9) < func_8009D4DC(D_801D0754, D_801D0758)) {
                rand_num = SysUtils_Rand() % 4095U;
                D_801CF060[arg0].unkC = (D_80192420[2] + (SIN(rand_num) * (D_800D4720 * 0.8)));
                D_801CF060[arg0].unk14 = (D_80192420[3] + (COS(rand_num) * (D_800D4720 * 0.8)));
                D_801CF060[arg0].unk18 = (s32) (SysUtils_Rand() & 255);
            }
        }
    }
}

f32 func_800A6628(s32 arg0, f32 arg1, f32 arg2) {
    return func_8009D4A8(D_801CF060[arg0].unkC - arg1, D_801CF060[arg0].unk14 - arg2);
}

s32 func_800A6684(s32 arg0) {
    s32 var_v0;

    if (func_800A6628(arg0, 112.0f, 5108.0f) < 1100.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 3252.0f, 3922.0f) < 1200.0f) {
        return 1;
    }
    if (func_800A6628(arg0, -3520.0f, -85.0f) < 1770.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 179.0f, -2485.0f) < 1400.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 3063.0f, -1319.0f) < 2200.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 1425.0f, 3603.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 1159.0f, 4182.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 2441.0f, -5018.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, 32.0f, -4958.0f) < 1000.0f) {
        return 1;
    }
    if (func_800A6628(arg0, -2511.0f, -4971.0f) < 1000.0f) {
        return 1;
    }
    return 0;
}

#ifdef NON_MATCHING
s32 func_800A68A4(void) {
    /* Wrong way warning banner animator */
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A68A4.s")
#endif

// TODO: Migrate rodata

void func_800A9130(s32 arg0) {
    char pad[0x8];

    if ((gGameModeState == 3) && (gCurrentPauseMenuOption == -1)) {
        if (D_801CF060[arg0].unk8 == 1) {
            func_800A52D8(arg0, 200.0f);
            if ((D_801D0738 + 1) == D_801CE728[0]) {
                if (arg0 == 0) {
                    D_801CF060->unkC = 6000.0f;
                    D_801CF060->unk18 = 90.0f;
                    D_801CF060->unk4C = 25.0f;
                    D_801CF060->unk9C = 0;
                    D_801CF060->unk8 = 0xB;
                    D_801CF060->unk0 = 6;
                    D_801CF060->unk14 = 4000.0f;
                }
                if (arg0 == 1) {
                    D_801CF060[1].unk8 = 0xC;
                    D_801CF060[1].unk0 = 6;
                    D_801CF060[1].unk7C = 0;
                }
                if (arg0 == 2) {
                    D_801CF060[2].unk7C = 0;
                    D_801CF060[2].unk14 = 4000.0f;
                    D_801CF060[2].unkC = 4800.0f;
                    D_801CF060[2].unk18 = 180.0f;
                    D_801CF060[2].unk0 = 6, D_801CF060[2].unk8 = 2;
                }
            }
        } else {
            if (D_801CF060[arg0].unk8 == 0xB) {
                func_800A52D8(arg0, 100.0f);
            } else if (D_801CF060[arg0].unk8 == 0xC) {
                D_801CF060[arg0].unkC = D_801CF060[D_801CF060[arg0].unk7C].unkC + 50.0f;
                D_801CF060[arg0].unk10 = D_801CF060[D_801CF060[arg0].unk7C].unk10;
                D_801CF060[arg0].unk14 = 4000.0f - (D_801CF060[D_801CF060[arg0].unk7C].unk14 - 4000.0f);
                D_801CF060[arg0].unk18 = -D_801CF060[D_801CF060[arg0].unk7C].unk18;
                D_801CF060[arg0].unk1C = D_801CF060[D_801CF060[arg0].unk7C].unk1C;
                D_801CF060[arg0].unk20 = D_801CF060[D_801CF060[arg0].unk7C].unk20;
            } else if (D_801CF060[arg0].unk8 == 2) {
                if (((D_801CF060[D_801CF060[arg0].unk7C].unk9C == 0) ||
                     (D_801CF060[D_801CF060[arg0].unk7C].unk9C == 5)) &&
                    (D_801CF060[D_801CF060[arg0].unk7C].unk54 == 1)) {
                    D_801CF060[arg0].unk50 = 0xE;
                    D_801CF060[arg0].unk54 = 0;
                    D_801CF060[arg0].unk74 = D_801CF060[arg0].unk78 = 0;
                }
                if ((D_801CF060[D_801CF060[arg0].unk7C].unk9C == 1) ||
                    (D_801CF060[D_801CF060[arg0].unk7C].unk9C == 6)) {
                    D_801CF060[arg0].unk50 = 0;
                    D_801CF060[arg0].unk54 = 0;
                    D_801CF060[arg0].unk74 = 6;
                    D_801CF060[arg0].unk78 = 0xA;
                }
                func_800A2B24(arg0);
            } else if (D_801CF060[arg0].unk8 == 5) {
                func_800A52D8(arg0, 200.0f);
            }
        }
    }
}

void func_800A93C8(s32 arg0) {
    D_801D0754 = func_8009D4A8(D_801CF060[arg0].unkC - D_801D06BC, D_801CF060[arg0].unk14 - D_801D06C4) / 40.0f;
    D_801D0758 = 0.0f;

    func_800C1BD8(D_801D0754, D_801D0758);

    if ((gCurrentPauseMenuOption == -1) && (D_801CF060[arg0].unk8 == 1)) {
        func_800A52D8(arg0, 400.0f);
    }
}

void func_800A9494(s32 arg0) {
    if (gCurrentPauseMenuOption == -1) {
        if (D_801CF060[arg0].unk8 == 1) {
            D_801CF060[arg0].unk74 = 0;
            switch (gCourseID) {
                case SUNNY_BEACH:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 3000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 1100.0f;
                    } else {
                        D_801D0754 = (-3500.0f);
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = (-1100.0f);
                    }
                    break;

                case GLACIER_COAST:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 4000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = (-2600.0f);
                    } else {
                        D_801D0754 = -290.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 4800.0f;
                    }
                    break;
                default:
                    break;
            }

            D_801D0760 = Math_Normalize_Angle(
                func_8009D3AC(D_801D0754 - D_801CF060[arg0].unkC, -(D_801D075C - D_801CF060[arg0].unk14)) -
                D_801CF060[arg0].unk18);
            if (FABS(D_801D0760) > 170) {
                if (arg0 % 2 == 0) {
                    D_801D0760 = 170.0f;
                } else {
                    D_801D0760 = -170.0f;
                }
            }
            if (arg0 % 2 == 0) {
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 += 2.0f;
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 += 3.0f;
                    }
                }
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 -= 2.0f;
                    if (D_801D0760 < (-45.0f)) {
                        D_801CF060[arg0].unk18 -= 3.0f;
                    }
                }
            } else {
                if (D_801D0760 < 0.0f) {
                    D_801CF060[arg0].unk18 -= 2.0f;
                    if (D_801D0760 < (-45.0f)) {
                        D_801CF060[arg0].unk18 -= 3.0f;
                    }
                }
                if (D_801D0760 > 0.0f) {
                    D_801CF060[arg0].unk18 += 2.0f;
                    if (D_801D0760 > 45.0f) {
                        D_801CF060[arg0].unk18 += 3.0f;
                    }
                }
            }
            D_801CF060[arg0].unk18 = func_8009D564(D_801CF060[arg0].unk18);
            D_801CF060[arg0].unk10 += 0.05 * (D_801D0758 - D_801CF060[arg0].unk10);
            D_801D0764 = (((180 - FABS(D_801D0760))) / 180.0f) * 30.0f;
            D_801CF060[arg0].unk1C = Math_Normalize_Angle(
                ((f64) D_801CF060[arg0].unk1C) + (Math_Normalize_Angle(D_801D0760 - D_801CF060[arg0].unk1C) * 0.1));
            if (D_801CF060[arg0].unk1C > 45.0f) {
                D_801CF060[arg0].unk1C = 45.0f;
            }
            if (D_801CF060[arg0].unk1C < -45.0f) {
                D_801CF060[arg0].unk1C = -45.0f;
            }
            D_801CF060[arg0].unk1C = func_8009D564(D_801CF060[arg0].unk1C);
            D_801D0760 = func_8009D4A8(D_801CF060[arg0].unk24, D_801CF060[arg0].unk2C);
            D_801D0764 = D_801D0760 + ((D_801D0764 - D_801D0760) * 0.1);
            D_801CF060[arg0].unkC +=
                (D_801CF060[arg0].unk24 = COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            D_801CF060[arg0].unk14 +=
                (D_801CF060[arg0].unk2C = SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * D_801D0764);
            if (func_8009D4A8(D_801D0754 - D_801CF060[arg0].unkC, D_801D075C - D_801CF060[arg0].unk14) <
                D_801CF060[arg0].unk70) {
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unkA8 = (SysUtils_Rand() & 15) + 10;
                D_801CF060[arg0].unk70 = ((SysUtils_Rand() & 15) * 10.0f) + 200.0f;
            }
            if (func_8009D4A8(D_801D06BC - D_801D0754, D_801D06C4 - D_801D075C) < 1000.0f) {
                D_801CF060[arg0].unk9C = (D_801CF060[arg0].unk9C + 1) % 2;
                D_801CF060[arg0].unk8 = 7;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unkA8 = (SysUtils_Rand() & 15) + 10;
            }
            if (D_801CF060[arg0].unk78 == 15) {
                D_801CF060[arg0].unk78 = 0;
            }
        } else if (D_801CF060[arg0].unk8 == 7) {
            switch (gCourseID) {
                case SUNNY_BEACH:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 3000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 1100.0f;
                    } else {
                        D_801D0754 = (-3500.0f);
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = (-1100.0f);
                    }
                    break;

                case GLACIER_COAST:
                    if (D_801CF060[arg0].unk9C == 0) {
                        D_801D0754 = 4000.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = (-2600.0f);
                    } else {
                        D_801D0754 = -290.0f;
                        D_801D0758 = D_801CF060[arg0].unk10;
                        D_801D075C = 4800.0f;
                    }
                    break;
                default:
                    break;
            }

            if (func_8009D4DC(D_801CF060[arg0].unk2C, D_801CF060[arg0].unk2C) < 1600.0f) {
                D_801CF060[arg0].unk24 =
                    D_801CF060[arg0].unk24 + (COS((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 2);
                D_801CF060[arg0].unk2C =
                    D_801CF060[arg0].unk2C + (SIN((s32) ((D_801CF060[arg0].unk18 * 4096.0f) / 360.0f)) * 2);
            }
            D_801CF060[arg0].unkC += D_801CF060[arg0].unk24;
            D_801CF060[arg0].unk10 += D_801CF060[arg0].unk28;
            D_801CF060[arg0].unk14 += D_801CF060[arg0].unk2C;
            D_801CF060[arg0].unkA4++;
            if (D_801CF060[arg0].unkA4 >= D_801CF060[arg0].unkA8) {
                D_801CF060[arg0].unkAC = 0;
                D_801CF060[arg0].unkA8 = 0;
                D_801CF060[arg0].unkA4 = 0;
                D_801CF060[arg0].unk8 = 1;
            }
            if (func_8009D4DC(D_801D06BC - D_801D0754, D_801D06C4 - D_801D075C) < 1000000.0f) {
                D_801CF060[arg0].unk9C = (D_801CF060[arg0].unk9C + 1) % 2;
            }
        }
    }
}

#ifdef NON_MATCHING
Gfx* func_800A9D48(Gfx* arg0, s32 arg1) {
    /* Finish line final lap banner renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800A9D48.s")
#endif

#ifdef NON_MATCHING
Gfx* func_800AAAC8(Gfx* arg0, s32 arg1) {
    /* Disqualification notice overlay renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800AAAC8.s")
#endif

#ifdef NON_MATCHING
Gfx* func_800AB25C(Gfx* arg0, s32 arg1) {
    /* Retired / out of fuel banner renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800AB25C.s")
#endif

void func_800AB890(s32 arg0) {
    s32 temp_v1;
    StructAB90* temp_v0;

    if ((gGameModeState == 3) && (gCurrentPauseMenuOption == -1)) {
        temp_v0 = (StructAB90*) ((arg0 * 0xBC) + (u32) &D_801CF060);

        if (temp_v0->unk8 == 2) {
            temp_v0->unk78 = (s32) (temp_v0->unk78 + 1);
        } else if (temp_v0->unk8 == 1) {
            temp_v0->unk74 = 1;
            temp_v0->unk78 = (s32) (temp_v0->unk78 + 1);
            func_800A52D8(arg0, 200.0f);
        }
    }
}

void func_800AB92C(void) {
    D_800E62C8 = D_800E62CC = 0;
    func_8009D5C0();
}

#ifdef NON_MATCHING
Gfx* func_800AB95C(Gfx* arg0, s32 arg1) {
    /* Time up game over banner renderer */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800AB95C.s")
#endif

void func_800AC098(UnkStruct_800AC098_src* src, s32 n) {
    /* Record lap flash alert queue append: copies n source entries into
       D_801CF060 starting at slot D_800E62CC, capped at 30 slots (an
       overflow returns without updating the count). Load-bearing for
       register coloring: the count = end copy, i reused for the
       constant 1, and the for (inits;;) header keeping the loop setup
       on one line (IDO schedules li v0,1 by line). */
    s32 i;
    s32 j;
    s32 count;
    StructVarS0* dst;
    UnkStruct_800AC098_src* s;
    s32 loop;
    s32 end;

    i = D_800E62CC;
    if (i < 30) {
        end = i + n;
        j = i;
        count = end;
        if (j < count) {
            for (dst = &D_801CF060[i], s = src, loop = i, i = 1;;) {
                dst->unk0 = s->unk0;
                dst->unkB8 = i;
                loop++;
                dst->unk74 = s->unk4;
                j++;
                dst->unk78 = s->unk8;
                dst->unkC = s->unkC;
                dst->unk10 = s->unk10;
                dst->unk14 = s->unk14;
                dst->unk30 = s->unk18;
                dst->unk34 = s->unk1C;
                dst->unk38 = s->unk20;
                dst->unk3C = s->unk24;
                dst->unk40 = s->unk28;
                dst->unk44 = s->unk2C;
                dst->unk48 = s->unk30;
                s++;
                if (loop >= 30) {
                    return;
                }
                dst++;
                if (j >= count) {
                    break;
                }
            }
        }
        D_800E62CC = count;
    }
}

#ifdef NON_MATCHING
Gfx* func_800AC184(Gfx* arg0, s32 arg1) {
    /* New record congratulatory fanfare banner */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800AC184.s")
#endif

void func_800AD3C4(void) {
    switch (gCourseID) {
        case DRAKE_LAKE:
            func_800C1DEC();
            break;
        case PORT_BLUE:
            func_800C1B98();
            break;
        default:
            break;
    }
}

#ifdef NON_MATCHING
void func_800AD418(void) {
    /* 2-Player split-screen HUD divider and layout setup */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_57EB0/func_800AD418.s")
#endif

/* `ret += 1` (not `ret++`) in cases 2/4 stops IDO cross-jumping them into the case 12 tail. */

s32 func_800ADC8C(s32 arg0) {
    s32 ret;

    ret = D_801D06B8;
    switch (arg0) {
        case 1:
            ret += 8;
            break;
        case 2:
            ret += 1;
            break;
        case 3:
            ret += 8;
            break;
        case 4:
            ret += 1;
            break;
        case 5:
            ret += 6;
            break;
        case 6:
            ret += 6;
            break;
        case 7:
            ret += 4;
            break;
        case 8:
            ret += 4;
            break;
        case 9:
            ret += 4;
            break;
        case 10:
            ret += 4;
            break;
        case 12:
            ret += 1;
    }
    return ret;
}

// TO CHECK
void func_800ADD14(void) {
    s32 i;

    for (i = 0; i < 30; i++) {
        if ((D_801CF060[i].unkB8 == 0) && (D_801CF060[i].unk0 != 0)) {
            if (D_801CF060[i].unkC > 8000) {
                D_801CF060[i].unkC = 8000.0f;
            }
            if (D_801CF060[i].unkC < -8000.0f) {
                D_801CF060[i].unkC = -8000.0f;
            }
            if (D_801CF060[i].unk14 > 8000) {
                D_801CF060[i].unk14 = 8000.0f;
            }
            if (D_801CF060[i].unk14 < -8000.0f) {
                D_801CF060[i].unk14 = -8000.0f;
            }
            if (D_801CF060[i].unk10 > 4000) {
                D_801CF060[i].unk14 = 4000.0f;
            }
            if (D_801CF060[i].unk10 < -4000.0f) {
                D_801CF060[i].unk14 = -4000.0f;
            }
        }
    }
}

s32 func_800ADE14(s32 arg0) {
    camera_unk_1* temp_v0;
    f32 angle;

    if (D_801CF060[arg0].unkB8 != 0) {
        return 1;
    }
    if (D_801CF060[arg0].unk0 != 0) {
        temp_v0 = &gCameraPerspective[D_80223930];
        D_801D0754 = func_8009D564(-func_8009D3AC(temp_v0->unkF0, temp_v0->unkF4));

        D_801D0758 = func_8009D564(
            func_8009D3AC(D_801CF060[arg0].unkC - temp_v0->unk4C, -(D_801CF060[arg0].unk14 - temp_v0->unk54)));

        if (D_801CF060[arg0].unk0 == 6) {
            return 1;
        }

        angle = FABS(Math_Normalize_Angle(D_801D0758 - D_801D0754));

        if (angle < 100.0f) {
            return 1;
        }
    }
    return 0;
}

extern s32 D_800E62C0;
extern s32 D_801D06B8;

Gfx* func_800ADF90(Gfx* arg0) {
    Gfx* var_v0;
    s32 var_s1;

    if (D_800E62C0 == 1) {
        D_800E62C0 = 0;
    } else {
        D_800E62C0 = 1;
    }
    arg0 = func_800916B4(arg0);
    func_800ADD14();
    D_801D06B8 = 0;

    for (var_s1 = 0; var_s1 < 30; var_s1++) {
        if ((func_800ADC8C(D_801CF060[var_s1].unk0 + D_801CF060[var_s1].unk4)) > 0xBF) {
            break;
        }

        if (func_800ADE14(var_s1) == 1) {
            switch (D_801CF060[var_s1].unk0 + D_801CF060[var_s1].unk4) {
                case 1:
                    var_v0 = func_8009DC10(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 2:
                    var_v0 = func_8009DB90(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 3:
                    var_v0 = func_8009E814(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 4:
                    var_v0 = func_8009E794(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 5:
                    var_v0 = func_8009F398(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 6:
                    var_v0 = func_8009FCB0(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 7:
                    var_v0 = func_800A10E4(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 8:
                    var_v0 = func_800A16F0(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 9:
                    var_v0 = func_800A1CFC(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 10:
                    var_v0 = func_800A2308(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 12:
                    var_v0 = func_800A28F4(arg0, var_s1);
                    arg0 = var_v0;
                    break;
                case 13:
                    var_v0 = func_800A063C(arg0, var_s1);
                    arg0 = var_v0;
                    break;
            }
        }
    }
    D_800E62CC = D_800E62C8;

    for (var_s1 = D_800E62C8; var_s1 < 30; var_s1++) {
        D_801CF060[var_s1].unk0 = 0;
    }

    return arg0;
}
