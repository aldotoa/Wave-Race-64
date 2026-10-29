#include "common.h"

typedef struct UnkStruct_801DB024 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} UnkStruct_801DB024;

typedef struct UnkStruct_801DB0E4_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC[3];
    f32 unk14[3];
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} UnkStruct_801DB0E4_arg0;

typedef struct UnkStruct_801DB0E4_arg1 {
    f32 unk0[3];
    f32 unk4[3];
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
} UnkStruct_801DB0E4_arg1;

typedef struct UnkStruct_801DBF68_s0 {
    s32 unk0;
    s32 unk4;
    struct UnkStruct_801DB0E4_arg1* unk8;
    s8 pad[0x1C];
} UnkStruct_801DBF68_s0;

typedef struct UnkStruct_801DBF68 {
    UnkStruct_801DBF68_s0 unk0[4];
} UnkStruct_801DBF68;

extern struct UnkStruct_801DBF68 D_80225CF4;

void func_800AB92C(void);
void func_800AB95C(s32, s32);

#define ANG_NORMALIZE_1(x) (x < 0.0f ? 360.0f : 0.0f)
#define ANG_NORMALIZE_2(x) (x > 360.0f ? -360.0f : 0.0f)

#define SIGNF(x) (x >= 0 ? 1.0f : -1.0f)

extern s32 D_80228110;
extern struct UnkStruct_801DB0E4_arg0 D_80228190;
extern s32 D_802287A8;
extern s32 D_802287AC;

// TODO: Improve these matches
void func_801DAFA0(void** arg0, s32 arg1) {
    *(f32*) (((u8*) (*arg0)) + 0x50) = 3.0f;
}

void func_801DAFB8(void* arg0) {
    u32 randVal;
    u32 result;
    void* savedArg0 = arg0;

    randVal = SysUtils_Rand();
    if ((randVal & 7) != 0) {
        result = SysUtils_Rand();
        *(u32*) ((u8*) savedArg0 + 8) = result % 15;
        return;
    }

    result = SysUtils_Rand();
    *(u32*) ((u8*) savedArg0 + 8) = (result % 19) + 0x19;
}

void func_801DB024(struct UnkStruct_801DB0E4_arg0* arg0) {
    if ((arg0->unk8 >= 0) && (((arg0->unk8 < 0x10)))) {
        arg0->unk8 += 2;
        if (arg0->unk8 >= 0x10) {
            if (SysUtils_Rand() & 7) {
                arg0->unk8 = 0;
            } else {
                arg0->unk8 = 0x10;
            }
        }
    } else {
        if ((arg0->unk8 >= 0x19) && (((arg0->unk8 < 0x2D)))) {
            arg0->unk8++;
            if (arg0->unk8 >= 0x2D) {
                if (SysUtils_Rand() & 0xF) {
                    arg0->unk8 = 0x2D;
                    return;
                }
                arg0->unk8 = 0x19;
            }
        } else {
            arg0->unk8++;
            if (arg0->unk8 >= 0x37) {
                arg0->unk8 = 0;
            }
        }
    }
}

void func_801DB0E4(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    f32 vec[3];
    f32 magnitud;
    s32 i;

    arg0->unk0 = 3;
    arg0->unk4 = 0;

    func_801DAFB8(arg0);

    for (i = 0; i < 3; i++) {
        arg0->unkC[i] = arg1->unk0[i];
        vec[i] = arg1->unk4[i] - arg1->unk0[i];
    }

    magnitud = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

    for (i = 0; i < 3; i++) {
        arg0->unk14[i] = vec[i] / magnitud;
    }

    arg0->unk24 = 0.0f;
    arg0->unk28 = 1.0f;
    arg0->unk2C = 0.0f;
    arg0->unk30 = 0.1f;

    *arg2 = arg1->unk1C;
}

void func_801DB1DC(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, s32* arg2) {
    s32 i;

    func_801DB024(arg0);

    if (*arg2 > 0) {
        for (i = 0; i < 3; i++) {
            arg0->unkC[i] += arg0->unk14[i] * arg1->unk18;
        }
        return;
    }

    arg0->unk0 = 0;
}

void func_801DB284(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    s32 var_s1;
    s32 var_s6;

    for (var_s6 = 0; var_s6 < arg3; var_s6++, arg0++) {
        arg0->unk0 = 3;
        arg0->unk4 = 0;

        func_801DAFB8(arg0);

        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            arg0->unkC[var_s1] = ((arg1->unk0[var_s1] + arg1->unk4[var_s1]) - (arg1->unk4[var_s1 + 3] * 0.5f)) +
                                 (((f32) (SysUtils_Rand() % 256) / 256) * arg1->unk4[var_s1 + 3]);
        }

        arg0->unk30 = 0.1f;
        arg2[var_s6][0] = SysUtils_Rand() % 360;
        arg2[var_s6][1] = SysUtils_Rand() % 360;
    }
}

void func_801DB430(struct UnkStruct_801DB0E4_arg0* arg0, struct UnkStruct_801DB0E4_arg1* arg1, f32 arg2[1][2],
                   s32 arg3) {
    f32 magnitude; // f20
    s32 i;
    f32 vec[3];
    s32 j;

    for (i = 0; i < arg3; i++, arg0++) {
        func_801DB024(arg0);
        vec[0] = COS((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[2] = SIN((s32) ((arg2[i][0] * 4096.0f) / 360.0f));
        vec[1] =
            (SIN((s32) ((arg2[i][1] * 4096.0f) / 360.0f)) * arg1->unk30) * (1.0f - ((SysUtils_Rand() & 3) / 20.0f));

        if (vec[1] * ((arg1->unk0[1] - arg0->unkC[1])) > 0) {
            vec[1] *= 1.2f;
        }

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        for (j = 0; j < 3; j++) {
            arg0->unk14[j] = vec[j] / magnitude;
            arg0->unkC[j] += arg0->unk14[j] * (arg1->unk24 + (f32) (SysUtils_Rand() & 1));
        }

        vec[0] = arg1->unk0[0] - arg0->unkC[0];

        vec[2] = arg1->unk0[2] - arg0->unkC[2];

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[2]));

        if (magnitude > 0.0f) {
            magnitude = 1 / magnitude;
        }

        vec[0] *= magnitude * 3.0f;
        vec[2] *= magnitude * 3.0f;
        vec[1] = arg1->unk24 / arg1->unk28;

        magnitude = sqrtf(SQ(vec[0]) + SQ(vec[1]) + SQ(vec[2]));

        arg0->unk24 = vec[0] / magnitude;
        arg0->unk28 = vec[1] / magnitude;
        arg0->unk2C = vec[2] / magnitude;

        magnitude = (arg0->unk14[0] * vec[2]) - (arg0->unk14[2] * vec[0]);

        arg2[i][0] += (SIGNF(magnitude) * (arg1->unk28 + (SysUtils_Rand() % 31U * 0.125f)));
        arg2[i][0] += ANG_NORMALIZE_2(arg2[i][0]) + ANG_NORMALIZE_1(arg2[i][0]);
        arg2[i][1] += ((arg1->unk2C * (0.9f + ((f32) (SysUtils_Rand() & 3) / 20.0f))));
        arg2[i][1] += ANG_NORMALIZE_2(arg2[i][1]);
    }
}

#ifdef NON_MATCHING
void func_801DB8F0(void* arg0) {
    /* 3D particle fireworks and water splash simulator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DB8F0.s")
#endif

void func_801DBF68(struct UnkStruct_801DB0E4_arg0* arg0) {
    s32 var_s2;
    UnkStruct_801DBF68 sp4C = D_80225CF4;
    s32 i;

    if (arg0->unk8 == 0) {
        func_800AB92C();
    }

    for (var_s2 = 0; var_s2 < D_802287AC; var_s2++) {
        if ((arg0->unk8 >= sp4C.unk0[var_s2].unk0) && (arg0->unk8 < sp4C.unk0[var_s2].unk4)) {
            D_802287A8 = 1;

            if (arg0->unk8 == sp4C.unk0[var_s2].unk0) {
                func_801DB0E4(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
            }
            func_801DB1DC(&D_80228190, (UnkStruct_801DB0E4_arg1*) &sp4C.unk0[var_s2].unk8, &D_80228110);
        }
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 unk8[0x20];
} DC0AC_Entry;

typedef struct {
    DC0AC_Entry e[3];
} DC0AC_Tbl78;

extern DC0AC_Tbl78 D_80225D94;
extern DC0AC_Entry D_80225E0C;
extern struct UnkStruct_801DB0E4_arg0 D_802281C4;
extern s32 D_80228114;

void func_801DC0AC(struct UnkStruct_801DB0E4_arg0* arg0) {
    s32 i;
    DC0AC_Tbl78 t78 = D_80225D94;
    DC0AC_Entry e28 = D_80225E0C;

    if (arg0->unk8 == 0) {
        func_800AB92C();
    }

    for (i = 0; i < 3; i++) {
        if ((arg0->unk8 >= t78.e[i].unk0) && (arg0->unk8 < t78.e[i].unk4)) {
            D_802287A8 += 1;
            if (arg0->unk8 == t78.e[i].unk0) {
                func_801DB0E4(&D_80228190, (UnkStruct_801DB0E4_arg1*) &t78.e[i].unk8, &D_80228110);
            }
            func_801DB1DC(&D_80228190, (UnkStruct_801DB0E4_arg1*) &t78.e[i].unk8, &D_80228110);
        }
    }

    if ((arg0->unk8 >= e28.unk0) && (arg0->unk8 < e28.unk4)) {
        D_802287A8 += 1;
        if (arg0->unk8 == e28.unk0) {
            func_801DB0E4(&D_802281C4, (UnkStruct_801DB0E4_arg1*) &e28.unk8, &D_80228114);
        }
        func_801DB1DC(&D_802281C4, (UnkStruct_801DB0E4_arg1*) &e28.unk8, &D_80228114);
    }
}

#ifdef NON_MATCHING
void func_801DC274(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC274.s")
#endif

typedef struct {
    s32 unk0;
    void* unk4;
    void* unk8;
} UnkStruct_80223F7C;

extern UnkStruct_80223F7C D_80223F7C[];
extern UnkStruct_80223F7C D_80224B14[];
extern UnkStruct_801DB0E4_arg1 D_80225E34;
extern f32 D_80228120[][2];

typedef struct {
    s32 unk0;
    UnkStruct_80223F7C* unk4;
    s32 unk8;
} UnkStruct_801DC5A8;

void func_801DC404(UnkStruct_801DC5A8* arg0) {
    f32 temp;
    s32 val;
    UnkStruct_801DB0E4_arg1 sp54 = D_80225E34;
    UnkStruct_801DB0E4_arg1 sp20 = sp54;

    val = arg0->unk4 - D_80224B14;
    if (val != 2) {
        return;
    }

    D_802287A8 = 8;
    if (arg0->unk8 == 1) {
        func_800AB92C();
        func_801DB284(&D_80228190, &sp20, D_80228120, 8);
    }
    temp = (f32) (arg0->unk8 / arg0->unk4->unk0);
    sp20.unk0[0] += 300.0f * temp;
    sp20.unk0[1] += -200.0f * temp;
    sp20.unk0[2] += -200.0f * temp;
    func_801DB430(&D_80228190, &sp20, D_80228120, 8);
}

void func_801DC5A8(UnkStruct_801DC5A8* arg0) {
    s32 val;

    if ((val = arg0->unk4 - D_80223F7C) == 2) {
        if (arg0->unk8 == 1) {
            func_800AB92C();
            func_800AB95C(1, 0);
        }
    }
}

#ifdef NON_MATCHING
void func_801DC60C(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DC60C.s")
#endif

#ifdef NON_MATCHING
void func_801DCD34(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DCD34.s")
#endif

#ifdef NON_MATCHING
void func_801DD2D0(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD2D0.s")
#endif

#ifdef NON_MATCHING
void func_801DD6B4(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DD6B4.s")
#endif

typedef struct {
    u8 pad[0xE0];
} Struct_80227E98;

typedef struct {
    u8 pad[0x38];
} Struct_80228058;

typedef struct {
    u8 pad[0x20];
} Struct_802280C8;

extern Struct_80227E98 D_80227E98[];
extern Struct_80228058 D_80228058[];
extern Struct_802280C8 D_802280C8[];
extern s32 D_80228108;

void func_801DFD8C();
void func_801DFDA0();
void func_801DFDA8();

void func_801DD85C(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        gCameraPerspective[i].unkE8 = i;
        gCameraPerspective[i].unkEC = 1;
        gCameraPerspective[i].unkF8 = 0;
        gCameraPerspective[i].camViewY = 0.0f;
        func_801DFD8C(&D_80228058[i], &D_80227E98[i]);
        func_801DFDA0(&D_80228058[i], &D_802280C8[i]);
        func_801DFDA8(&D_80228058[i], &gCameraPerspective[i].unk4, &gCameraPerspective[i].unk8,
                      &gCameraPerspective[i].unkC, &gCameraPerspective[i].unk1C, &gCameraPerspective[i].unk20,
                      &gCameraPerspective[i].unk24, &gCameraPerspective[i].unk10, &gCameraPerspective[i].unk14,
                      &gCameraPerspective[i].unk18, &D_80228108);
    }
}

void func_801DDA24(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDAB8(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

#ifdef NON_MATCHING
void func_801DDAB8(void* arg0, void* arg1, void* arg2) {
    /* Camera perspective_RGB/scale initializer (3-arg form) */
    ((void) arg0);
    ((void) arg1);
    ((void) arg2);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDAB8.s")
#endif

void func_801DDEDC();

void func_801DDE48(void) {
    s32 i;

    for (i = 0; i < gPlayers; i++) {
        func_801DDEDC(&gCameraPerspective[i], &D_80227E98[i], &D_80228058[i]);
    }
}

#ifdef NON_MATCHING
void func_801DDEDC(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DDEDC.s")
#endif

#ifdef NON_MATCHING
void func_801DE3CC(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE3CC.s")
#endif

#ifdef NON_MATCHING
void func_801DE690(void) {
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DE690.s")
#endif

typedef struct {
    s32 unk0;
    s32 unk4;
} UnkStruct_801DEA94;

void func_801DEA94(UnkStruct_801DEA94* arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < arg1; i++) {
        arg0[i].unk4 = 0;
        arg0[i].unk0 = 0;
    }
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32* unk8;
} UnkCurve_801DEB08;

f32 func_801DE690(f32, s32, s32, s32);

void func_801DEB08(f32* out, UnkStruct_801DEA94* s1, UnkCurve_801DEB08* s2) {
    s32 var_v0;

    while ((var_v0 = s2->unk8[s1->unk4]) == 0) {
        s1->unk4++;
    }
    *out = func_801DE690((f32) s1->unk0 / (f32) var_v0, s1->unk4, s2->unk4, s2->unk0);
    if (++s1->unk0 < s2->unk8[s1->unk4]) {
        return;
    }
    s1->unk0 = 0;
    s1->unk4++;
    if (s1->unk4 < s2->unk0 - 3) {
        return;
    }
    s1->unk4 = -1;
}

typedef struct {
    s32 unk0;
    s32 unk4[3];
    s32* unk10;
} UnkCurve_801DEC00;

void func_801DEC00(f32* arg0, UnkStruct_801DEA94* arg1, UnkCurve_801DEC00* arg2) {
    s32 i;

    while (arg2->unk10[arg1->unk4] == 0) {
        arg1->unk4++;
    }
    for (i = 0; i < 3; i++) {
        arg0[i] = func_801DE690((f32) arg1->unk0 / (f32) arg2->unk10[arg1->unk4], arg1->unk4, arg2->unk4[i], arg2->unk0);
    }
    if (++arg1->unk0 < arg2->unk10[arg1->unk4]) {
        return;
    }
    arg1->unk0 = 0;
    arg1->unk4++;
    if (arg1->unk4 < arg2->unk0 - 3) {
        return;
    }
    arg1->unk4 = -1;
}


void func_801DED44(u8* arg0, u8* arg1, u8* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00(arg0 + 0xC, arg1 + 0x8, arg2 + 0x14);
}

void func_801DED88(u8* arg0, u8* arg1, u8* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00(arg0 + 0xC, arg1 + 0x8, arg2 + 0x14);
    func_801DEC00(arg0 + 0x18, arg1 + 0x10, arg2 + 0x28);
}

void func_801DEDE8(u8* arg0, u8* arg1, u8* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00(arg0 + 0xC, arg1 + 0x8, arg2 + 0x14);
    func_801DEB08(arg0 + 0x18, arg1 + 0x10, arg2 + 0x28);
}

void func_801DEE48(u8* arg0, u8* arg1, u8* arg2) {
    func_801DEC00(arg0, arg1, arg2);
    func_801DEC00(arg0 + 0xC, arg1 + 0x8, arg2 + 0x14);
    func_801DEC00(arg0 + 0x18, arg1 + 0x10, arg2 + 0x28);
    func_801DEB08(arg0 + 0x24, arg1 + 0x18, arg2 + 0x3C);
}

typedef struct {
    char pad0[0x18];
    f32 unk18[3];
    f32 unk24[3];
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40[2];
    f32 unk48[2];
    f32 unk50[2];
} Struct_801DEEC4_A;

void func_801DEEC4(u8* arg0) {
    Struct_801DEEC4_A* a = (Struct_801DEEC4_A*) (arg0 + 4);
    s32 i;

    for (i = 0; i < 3; i++) {
        a->unk18[i] += (a->unk24[i] - a->unk18[i]) * a->unk30;
    }

    a->unk34 += (a->unk38 - a->unk34) * a->unk3C;

    for (i = 0; i < 2; i++) {
        a->unk40[i] += (a->unk48[i] - a->unk40[i]) * a->unk50[i];
    }
}

typedef struct {
    s32 data[22];
} UnkPartA_801DF278;

typedef struct {
    s32 data[8];
} UnkPartD_801DEF84;

typedef struct {
    UnkPartA_801DF278 a;
    UnkPartD_801DEF84 d;
} UnkSrc_801DF008;

typedef struct {
    s32 type;
    UnkPartA_801DF278 a;
    UnkPartD_801DEF84 d;
} UnkStruct_801DEF84;

void func_801DEF84(void* dst, void* srcA, void* srcD) {
    UnkStruct_801DEF84* d = (UnkStruct_801DEF84*) dst;
    d->type = 1;
    d->a = *(UnkPartA_801DF278*) srcA;
    d->d = *(UnkPartD_801DEF84*) srcD;
}

void func_801DF008(void* dst, void* src) {
    UnkStruct_801DEF84* d = (UnkStruct_801DEF84*) dst;
    UnkSrc_801DF008* s = (UnkSrc_801DF008*) src;
    d->type = 1;
    d->a = s->a;
    d->d = s->d;
}

typedef struct {
    char pad0[0x24];
    f32 unk24[3];
} Struct_A_801DF08C;

typedef struct {
    f32 unk0[3];
    char padC[4];
    f32 unk10[3];
} Struct_B_801DF08C;

void func_801DF08C(u8* dst, f32* src1, f32* src2, f32* src3, f32* src4) {
    s32 i;
    Struct_B_801DF08C* b;
    Struct_A_801DF08C* a;

    if (src1 != NULL) {
        b = (Struct_B_801DF08C*) (dst + 0x5C);
        for (i = 0; i < 3; i++) {
            b->unk0[i] = src1[i];
        }
    }
    if (src2 != NULL) {
        b = (Struct_B_801DF08C*) (dst + 0x5C);
        for (i = 0; i < 3; i++) {
            b->unk10[i] = src2[i];
        }
    }
    if (src3 != NULL) {
        a = (Struct_A_801DF08C*) (dst + 4);
        for (i = 0; i < 3; i++) {
            a->unk24[i] = src3[i];
        }
    }
    if (src4 != NULL) {
        *(f32*) (dst + 0x3C) = *src4;
    }
}

typedef struct {
    f32 vec1[3];
    f32 vec2[3];
} Struct_A_801DF128;

typedef struct {
    f32 target1[3];
    f32 step1;
    f32 target2[3];
    f32 step2;
} Struct_B_801DF128;

void func_801DF128(u8* arg0) {
    Struct_A_801DF128* a = (Struct_A_801DF128*) (arg0 + 4);
    Struct_B_801DF128* b = (Struct_B_801DF128*) (arg0 + 0x5C);
    s32 i;

    for (i = 0; i < 3; i++) {
        a->vec1[i] += (b->target1[i] - a->vec1[i]) * b->step1;
        a->vec2[i] += (b->target2[i] - a->vec2[i]) * b->step2;
    }

    func_801DEEC4(arg0);
}

typedef struct {
    s32 data[14];
} UnkPartB_801DF278;

typedef struct {
    UnkPartA_801DF278 a;
    UnkPartB_801DF278 b;
} UnkSrc_801DF278;

typedef struct {
    s32 type;
    UnkPartA_801DF278 a;
    UnkPartB_801DF278 b;
} UnkStruct_801DF278;

void func_801DF1F8(void* dst, s32 type, void* srcA, void* srcB) {
    UnkStruct_801DF278* d = (UnkStruct_801DF278*) dst;
    d->type = type;
    d->a = *(UnkPartA_801DF278*) srcA;
    d->b = *(UnkPartB_801DF278*) srcB;
}

void func_801DF278(void* dst, s32 type, void* src) {
    UnkStruct_801DF278* d = (UnkStruct_801DF278*) dst;
    UnkSrc_801DF278* s = (UnkSrc_801DF278*) src;
    d->type = type;
    d->a = s->a;
    d->b = s->b;
}

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    Vec3f group[3];
} Struct_B_801DF2F8;

void func_801DF2F8(u8* dst, f32* src1, f32* src2, f32* src3, f32* src4) {
    s32 i;
    Struct_B_801DF2F8* b = (Struct_B_801DF2F8*) (dst + 0x5C);
    Struct_A_801DF08C* a;

    if (src1 != NULL) {
        for (i = 0; i < 3; i++) {
            b->unk0[i] = src1[i];
        }
    }
    if (src2 != NULL) {
        b->group[0].y = src2[0];
        b->group[1].y = src2[1];
        b->group[2].y = src2[2];
    }
    if (src3 != NULL) {
        a = (Struct_A_801DF08C*) (dst + 4);
        for (i = 0; i < 3; i++) {
            a->unk24[i] = src3[i];
        }
    }
    if (src4 != NULL) {
        *(f32*) (dst + 0x3C) = *src4;
    }
}

typedef struct {
    f32 vec1[3];
    f32 vec2[3];
} Struct_A_801DF38C;

typedef struct {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
} Struct_B_801DF38C;

void func_801DF38C(void* arg0) {
    Struct_A_801DF38C* a = (Struct_A_801DF38C*) ((u8*) arg0 + 4);
    Struct_B_801DF38C* b = (Struct_B_801DF38C*) ((u8*) arg0 + 0x5C);
    f32 yaw;
    f32 pitch;
    f32 vec[3];
    s32 i;

    b->unk14 += (b->unk18 - b->unk14) * b->unk1C;
    b->unk20 += (b->unk24 - b->unk20) * b->unk28;
    b->unk2C += (b->unk30 - b->unk2C) * b->unk34;
    yaw = b->unkC + b->unk20;
    pitch = b->unk10 + b->unk2C;
    vec[0] = (b->unk14 * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f));
    vec[1] = b->unk14 * SIN((s32) ((pitch * 4096.0f) / 360.0f));
    vec[2] = (b->unk14 * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f));
    switch (*(s32*) arg0) {
        case 2:
            for (i = 0; i < 3; i++) {
                a->vec1[i] = b->unk0[i];
                a->vec2[i] = b->unk0[i] + vec[i];
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                a->vec2[i] = b->unk0[i];
                a->vec1[i] = b->unk0[i] + vec[i];
            }
            break;
    }
    func_801DEEC4((u8*) arg0);
}

typedef struct {
    s32 data[33];
} UnkPartC_801DF578;

typedef struct {
    UnkPartA_801DF278 a;
    UnkPartC_801DF578 c;
} UnkSrc_801DF5F0;

typedef struct {
    s32 type;
    UnkPartA_801DF278 a;
    UnkPartC_801DF578 c;
} UnkStruct_801DF5F0;

void func_801DF578(void* dst, void* srcA, void* srcC) {
    UnkStruct_801DF5F0* d = (UnkStruct_801DF5F0*) dst;
    d->type = 5;
    d->a = *(UnkPartA_801DF278*) srcA;
    d->c = *(UnkPartC_801DF578*) srcC;
}

void func_801DF5F0(void* dst, void* src) {
    UnkStruct_801DF5F0* d = (UnkStruct_801DF5F0*) dst;
    UnkSrc_801DF5F0* s = (UnkSrc_801DF5F0*) src;
    d->type = 5;
    d->a = s->a;
    d->c = s->c;
}

typedef struct {
    f32 unk0[3];
    f32 padC[6];
    f32 unk24[2];
    f32 pad2C[8];
    f32 unk4C;
    f32 pad50[2];
    f32 unk58;
    f32 pad5C[2];
    f32 unk64;
    f32 pad68[3];
    s32 unk74;
    s32 unk78;
} UnkPart_801DF668;

void func_801DF668(void* workBuf, f32* copySrc, f32* lookupSrcDst, f32* singleA, f32* offsetTriplet, f32* streamSrc,
                   f32* singleB) {
    UnkPart_801DF668* part = (UnkPart_801DF668*) ((u8*) workBuf + 0x5C);
    s32 loopCountA;
    s32 loopCountB;

    loopCountA = 0;
    if (copySrc != NULL) {
        f32* copySrcPos = copySrc;
        do {
            part->unk0[loopCountA] = *copySrcPos;
            copySrcPos += 1;
            loopCountA += 1;
        } while (loopCountA != 3);
    }
    if (lookupSrcDst != NULL) {
        part->unk24[0] = lookupSrcDst[part->unk74];
        part->unk24[1] = lookupSrcDst[part->unk78];
    }
    lookupSrcDst = (f32*) ((u8*) workBuf + 4);
    if (singleA != NULL) {
        *(f32*) ((u8*) workBuf + 0x90) = *singleA;
    }
    if (offsetTriplet != NULL) {
        part->unk4C = offsetTriplet[0];
        part->unk58 = offsetTriplet[1];
        part->unk64 = offsetTriplet[2];
    }
    loopCountB = 0;
    if (streamSrc != NULL) {
        f32* streamPos = streamSrc;
        do {
            lookupSrcDst[9] = *streamPos;
            loopCountB += 1;
            streamPos += 1;
            lookupSrcDst += 1;
        } while (loopCountB != 3);
    }
    if (singleB != NULL) {
        *(f32*) ((u8*) workBuf + 0x3C) = *singleB;
    }
}

#ifdef NON_MATCHING
void func_801DF744(void* arg0) {
    ((void) arg0);
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/A95D0/func_801DF744.s")
#endif

void func_801DF38C(void*);
void func_801DF744(void*);

void func_801DFC48(s32* arg0) {
    switch (arg0[0]) {
        case 1:
            func_801DF128(arg0);
            break;
        case 2:
        case 3:
            func_801DF38C(arg0);
            break;
        case 5:
            func_801DF744(arg0);
            break;
    }
}

typedef struct UnkStruct_801DFCB8_cmd {
    s32 unk0;
    void (*func)(void*, s32);
    s32 unk8;
} UnkStruct_801DFCB8_cmd;

typedef struct UnkStruct_801DFCB8 {
    s32 unk0;
    UnkStruct_801DFCB8_cmd* cmd;
    s32 timer;
} UnkStruct_801DFCB8;

void func_801DFCB8(UnkStruct_801DFCB8* arg0) {
    register UnkStruct_801DFCB8* a0 = arg0;
    register UnkStruct_801DFCB8_cmd* cmd;

    while (1) {
        if ((cmd = a0->cmd) == NULL) {
            return;
        }
        if (cmd->func != NULL) {
            cmd->func(a0, cmd->unk8);
        }
        switch (cmd->unk0) {
            case 0:
                a0->cmd++;
                continue;
            case -1:
                cmd = NULL;
                a0->timer = 0;
                break;
            case -2:
                a0->timer++;
                break;
            default:
                if (++a0->timer >= cmd->unk0) {
                    cmd++;
                    a0->timer = 0;
                }
                break;
        }
        break;
    }

    a0->cmd = cmd;
}

void func_801DFD8C(s32* arg0, s32 arg1) {
    *arg0 = arg1;
}

void func_801DFD94(s32* arg0, s32 arg1) {
    arg0[1] = arg1;
    arg0[2] = 0;
}

void func_801DFDA0(s32* arg0, s32 arg1) {
    arg0[3] = arg1;
}

void func_801DFDA8(s32* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9,
                   s32 arg10) {
    arg0[4] = arg1;
    arg0[5] = arg2;
    arg0[6] = arg3;
    arg0[7] = arg4;
    arg0[8] = arg5;
    arg0[9] = arg6;
    arg0[10] = arg7;
    arg0[11] = arg8;
    arg0[12] = arg9;
    arg0[13] = arg10;
}

void func_801DFDF0(s32* arg0, s32 arg1) {
    func_801DEA94((UnkStruct_801DEA94*) arg0[3], arg1);
}

void func_801DFE10(s32* arg0, s32 arg1) {
    func_801DF008((void*) arg0[0], (void*) arg1);
}

void func_801DFE30(s32* arg0, s32 arg1) {
    func_801DF278(arg0[0], 2, arg1);
}

void func_801DFE58(s32* arg0, s32 arg1) {
    func_801DF278(arg0[0], 3, arg1);
}

typedef struct SubStruct_801DFE80 {
    f32 unk0[3];
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18[2];
    f32 unk20;
    f32 unk24;
    f32 unk28;
    char pad2C[0x8];
    f32 unk34;
    char pad38[0x3C];
    s32 unk74[2];
} SubStruct_801DFE80;

typedef struct UnkCmd_801DFE80_Obj {
    char pad0[0x5C];
    SubStruct_801DFE80 sub;
} UnkCmd_801DFE80_Obj;

typedef struct UnkCmd_801DFE80 {
    UnkCmd_801DFE80_Obj* obj;
    char pad4[8];
    void* unkC;
    f32* unk10[3];
    f32* unk1C[3];
    f32* unk28[3];
    f32* unk34;
} UnkCmd_801DFE80;

void func_801DFE80(UnkCmd_801DFE80* arg0, void* arg1) {
    s32 i;
    SubStruct_801DFE80* sub;

    func_801DF5F0(arg0->obj, arg1);
    sub = &arg0->obj->sub;
    for (i = 0; i < 3; i++) {
        sub->unk0[i] = *arg0->unk10[i];
    }
    for (i = 0; i < 2; i++) {
        s32 idx = sub->unk74[i];
        sub->unk18[i] = *arg0->unk10[idx] - (*arg0->unk1C[idx] * 100.0f);
    }
}

void func_801DFF5C(s32* arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp20[3];

    func_801DED44((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF08C(arg0[0], sp20, sp2C, NULL, NULL);
}

void func_801DFFA8(s32* arg0, s32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_801DED88((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF08C(arg0[0], sp24, sp30, sp3C, NULL);
}

void func_801DFFF4(s32* arg0, s32 arg1) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_801DEDE8((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF08C(arg0[0], sp24, sp30, NULL, &sp3C);
}

void func_801E0044(s32* arg0, s32 arg1) {
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_801DEE48((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF08C(arg0[0], sp20, sp2C, sp38, &sp44);
}

void func_801E0094(s32* arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp20[3];

    func_801DED44((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp20, sp2C, NULL, NULL);
}

void func_801E00E0(s32* arg0, s32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_801DED88((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp24, sp30, sp3C, NULL);
}

void func_801E012C(s32* arg0, s32 arg1) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_801DEDE8((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp24, sp30, NULL, &sp3C);
}

void func_801E017C(s32* arg0, s32 arg1) {
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_801DEE48((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp20, sp2C, sp38, &sp44);
}

void func_801E01CC(s32* arg0, s32 arg1) {
    f32 sp2C[3];
    f32 sp20[3];

    func_801DED44((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp2C, sp20, NULL, NULL);
}

void func_801E0218(s32* arg0, s32 arg1) {
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];

    func_801DED88((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp30, sp24, sp3C, NULL);
}

void func_801E0264(s32* arg0, s32 arg1) {
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_801DEDE8((u8*) sp24, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp30, sp24, NULL, &sp3C);
}

void func_801E02B4(s32* arg0, s32 arg1) {
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_801DEE48((u8*) sp20, (u8*) arg0[3], (u8*) arg1);
    func_801DF2F8(arg0[0], sp2C, sp20, sp38, &sp44);
}

f32 func_801ED154(f32, f32);

void func_801E0304(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DED44((u8*) sp50, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    sub->unkC = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]);
    yaw = sp50[1] + sub->unkC;
    sub->unk10 = 0.0f;
    pitch = sp50[2];
    sp44[0] = *arg0->unk10[0] + ((sp50[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp44[1] = *arg0->unk10[1] + (sp50[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp44[2] = *arg0->unk10[2] + ((sp50[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));
    func_801DF2F8(arg0->obj, sp44, sp5C, NULL, NULL);
}

void func_801E0454(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DED88((u8*) sp4C, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    sub->unkC = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]);
    yaw = sp4C[1] + sub->unkC;
    sub->unk10 = 0.0f;
    pitch = sp4C[2];
    sp40[0] = *arg0->unk10[0] + ((sp4C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp40[1] = *arg0->unk10[1] + (sp4C[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp40[2] = *arg0->unk10[2] + ((sp4C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));
    func_801DF2F8(arg0->obj, sp40, sp58, sp64, NULL);
}

void func_801E05A4(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp64;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DEDE8((u8*) sp4C, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    sub->unkC = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]);
    yaw = sp4C[1] + sub->unkC;
    sub->unk10 = 0.0f;
    pitch = sp4C[2];
    sp40[0] = *arg0->unk10[0] + ((sp4C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp40[1] = *arg0->unk10[1] + (sp4C[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp40[2] = *arg0->unk10[2] + ((sp4C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));
    func_801DF2F8(arg0->obj, sp40, sp58, NULL, &sp64);
}

void func_801E06F8(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp74;
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DEE48((u8*) sp50, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    sub->unkC = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]);
    yaw = sp50[1] + sub->unkC;
    sub->unk10 = 0.0f;
    pitch = sp50[2];
    sp44[0] = *arg0->unk10[0] + ((sp50[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp44[1] = *arg0->unk10[1] + (sp50[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp44[2] = *arg0->unk10[2] + ((sp50[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));
    func_801DF2F8(arg0->obj, sp44, sp5C, sp68, &sp74);
}

void func_801E084C(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DED44((u8*) sp58, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    yaw = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]) + sp58[1];
    pitch = sp58[2];
    sp4C[0] = *arg0->unk10[0] + ((sp58[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp4C[1] = *arg0->unk10[1] + (sp58[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp4C[2] = *arg0->unk10[2] + ((sp58[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));

    sub->unkC = *arg0->unk34;
    sub->unk24 = *arg0->unk1C[sub->unk74[0]];
    sub->unk28 = *arg0->unk1C[sub->unk74[1]];
    sub->unk34 = sqrtf(SQ(*arg0->unk28[sub->unk74[0]]) + SQ(*arg0->unk28[sub->unk74[1]]));

    func_801DF668(arg0->obj, sp4C, NULL, NULL, sp64, NULL, NULL);
}

void func_801E0A18(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp74[3];
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DED88((u8*) sp5C, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    yaw = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]) + sp5C[1];
    pitch = sp5C[2];
    sp50[0] = *arg0->unk10[0] + ((sp5C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp50[1] = *arg0->unk10[1] + (sp5C[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp50[2] = *arg0->unk10[2] + ((sp5C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));

    sub->unkC = *arg0->unk34;
    sub->unk24 = *arg0->unk1C[sub->unk74[0]];
    sub->unk28 = *arg0->unk1C[sub->unk74[1]];
    sub->unk34 = sqrtf(SQ(*arg0->unk28[sub->unk74[0]]) + SQ(*arg0->unk28[sub->unk74[1]]));

    func_801DF668(arg0->obj, sp50, NULL, NULL, sp68, sp74, NULL);
}

void func_801E0BE8(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp74;
    f32 sp68[3];
    f32 sp5C[3];
    f32 sp50[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DEDE8((u8*) sp5C, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    yaw = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]) + sp5C[1];
    pitch = sp5C[2];
    sp50[0] = *arg0->unk10[0] + ((sp5C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp50[1] = *arg0->unk10[1] + (sp5C[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp50[2] = *arg0->unk10[2] + ((sp5C[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));

    sub->unkC = *arg0->unk34;
    sub->unk24 = *arg0->unk1C[sub->unk74[0]];
    sub->unk28 = *arg0->unk1C[sub->unk74[1]];
    sub->unk34 = sqrtf(SQ(*arg0->unk28[sub->unk74[0]]) + SQ(*arg0->unk28[sub->unk74[1]]));

    func_801DF668(arg0->obj, sp50, NULL, NULL, sp68, NULL, &sp74);
}

void func_801E0DB8(UnkCmd_801DFE80* arg0, void* arg1) {
    f32 sp7C;
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 yaw;
    f32 pitch;
    SubStruct_801DFE80* sub;

    func_801DEE48((u8*) sp58, (u8*) arg0->unkC, (u8*) arg1);
    sub = &arg0->obj->sub;
    yaw = func_801ED154(*arg0->unk1C[2], *arg0->unk1C[0]) + sp58[1];
    pitch = sp58[2];
    sp4C[0] = *arg0->unk10[0] + ((sp58[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * COS((s32) ((yaw * 4096.0f) / 360.0f)));
    sp4C[1] = *arg0->unk10[1] + (sp58[0] * SIN((s32) ((pitch * 4096.0f) / 360.0f)));
    sp4C[2] = *arg0->unk10[2] + ((sp58[0] * COS((s32) ((pitch * 4096.0f) / 360.0f))) * SIN((s32) ((yaw * 4096.0f) / 360.0f)));

    sub->unkC = *arg0->unk34;
    sub->unk24 = *arg0->unk1C[sub->unk74[0]];
    sub->unk28 = *arg0->unk1C[sub->unk74[1]];
    sub->unk34 = sqrtf(SQ(*arg0->unk28[sub->unk74[0]]) + SQ(*arg0->unk28[sub->unk74[1]]));

    func_801DF668(arg0->obj, sp4C, NULL, NULL, sp64, sp70, &sp7C);
}

typedef struct UnkDst_801E0F8C {
    char pad0[0x4C];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    char pad58[0xC];
    f32 unk64;
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    f32 unk7C;
    f32 unk80;
    f32 unk84;
    f32 unk88;
    f32 unk8C;
    f32 unk90;
    f32 unk94;
    f32 unk98;
    f32 unk9C;
    f32 unkA0;
    MtxF unkA4;
    u16 unkE4;
    char padE6[2];
    s32 unkE8;
    char padEC[4];
    f32 unkF0;
    f32 unkF4;
} UnkDst_801E0F8C;

typedef struct {
    char pad0[4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    char pad28[0x10];
    f32 unk38;
    char pad3C[8];
    f32 unk44;
    f32 unk48;
} UnkSrc_801E0F8C;

void func_801E0F8C(UnkDst_801E0F8C* dst, UnkSrc_801E0F8C* src) {
    dst->unk4C = src->unk10;
    dst->unk50 = src->unk14;
    dst->unk54 = src->unk18;
    dst->unk7C = src->unk4;
    dst->unk80 = src->unk8;
    dst->unk84 = src->unkC;
    dst->unk70 = src->unk1C;
    dst->unk74 = src->unk20;
    dst->unk78 = src->unk24;
    dst->unk88 = src->unk38;
    dst->unk94 = src->unk44;
    dst->unk98 = src->unk48;
}

void func_801E0FF0(UnkDst_801E0F8C* arg0) {
    f32 temp;
    f32 temp2;

    arg0->unk64 = arg0->unk7C - arg0->unk4C;
    arg0->unk68 = arg0->unk80 - arg0->unk50;
    arg0->unk6C = arg0->unk84 - arg0->unk54;

    temp = sqrtf(SQ(arg0->unk64) + SQ(arg0->unk68) + SQ(arg0->unk6C));
    arg0->unk64 /= temp;
    arg0->unk68 /= temp;
    arg0->unk6C /= temp;

    temp = sqrtf(SQ(arg0->unk64) + SQ(arg0->unk6C));

    arg0->unkF0 = arg0->unk64 / temp;
    arg0->unkF4 = arg0->unk6C / temp;

    temp2 = (SQ(arg0->unk64) + SQ(arg0->unk68)) + SQ(arg0->unk6C);
    temp2 = -(((arg0->unk64 * arg0->unk70) + (arg0->unk68 * arg0->unk74)) + (arg0->unk6C * arg0->unk78)) / temp2;

    arg0->unk70 += arg0->unk64 * temp2;
    arg0->unk74 += arg0->unk68 * temp2;
    arg0->unk78 += arg0->unk6C * temp2;

    temp = sqrtf(SQ(arg0->unk70) + SQ(arg0->unk74) + SQ(arg0->unk78));
    arg0->unk70 /= temp;
    arg0->unk74 /= temp;
    arg0->unk78 /= temp;

    arg0->unk8C = sqrtf(SQ(arg0->unk4C - arg0->unk7C) + SQ(arg0->unk54 - arg0->unk84));
    arg0->unk90 = arg0->unk50 - arg0->unk80;
}

void func_801E11B4(u8* arg0, UnkDst_801E0F8C* arg1) {
    func_800481E0((Mtx*) (arg0 + 0xE008 + (arg1->unkE8 << 6)), &arg1->unkE4, arg1->unk88, 4.0f / 3.0f, arg1->unk9C,
                  arg1->unkA0, arg1->unk94, arg1->unk98);
    func_800484C8((Mtx*) (arg0 + 0xE088 + (arg1->unkE8 << 6)), &arg1->unkA4, arg1->unk4C, arg1->unk50, arg1->unk54,
                  arg1->unk7C, arg1->unk80, arg1->unk84, arg1->unk70, arg1->unk74, arg1->unk78);
}
