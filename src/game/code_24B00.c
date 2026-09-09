#include "common.h"
#include "rider.h"
#include "camera.h"

typedef struct UnkStruct_801BB138_s {
    /* 0x00 */ f32 unk0; /* inferred for func_8006E674 */
    /* 0x04 */ f32 unk4; /* inferred */
    /* 0x08 */ f32 unk8; /* inferred for func_8006E674 */
    /* 0x0C */ char padC[4];
    /* 0x10 */ s32 unk10; /* inferred */
    /* 0x14 */ char pad14[4];
} UnkStruct_801BB138; /* size = 0x18 */

typedef struct UnkStruct_801BFA48_s {
    /* 0x00 */ f32 unk0;  /* inferred */
    /* 0x04 */ f32 unk4;  /* inferred */
    /* 0x08 */ f32 unk8;  /* inferred */
    /* 0x0C */ f32 unkC;  /* inferred */
    /* 0x10 */ f32 unk10; /* inferred */
    /* 0x14 */ s32 unk14; /* inferred */
    /* 0x18 */ s32 unk18; /* inferred */
    /* 0x1C */ s32 unk1C; /* inferred */
    /* 0x20 */ char pad20[4];
} UnkStruct_801BFA48; /* size = 0x24 */

typedef struct UnkStruct_801BFB70_s {
    /* 0x00 */ s32 unk0;        /* inferred */
    /* 0x04 */ char pad4[0x3C]; /* maybe part of unk0[0x10]? */
} UnkStruct_801BFB70;           /* size = 0x40 */

typedef struct UnkStruct_801C0C80_s {
    char pad[0x48];
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    char pad58[0x20];
    s32 unk78;
    s32 unk7C;
    char pad80[0x20];
    s32 unkA0; /* inferred for func_8006E674 */
    s32 unkA4; /* inferred for func_8006E674 */
    char padA8[4];
    f32 unkAC;
    f32 unkB0;
    f32 unkB4;
} UnkStruct_801C0C80;

typedef struct UnkStruct_800D5330_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} UnkStruct_800D5330;

typedef struct UnkStruct_801C0580_s {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} UnkStruct_801C0580;

// TODO: Find another type for D_10445C8
typedef struct UnkStruct_10445C8_s {
    char pad[0xC0];
} UnkStruct_10445C8;

// .data
extern s32 D_800D4B00;
extern u16 D_800D4B18[4][256];
extern u8 D_800D5318[4][3];
extern UnkStruct_800D5330 D_800D5330[];
extern s32 D_800D543C;
extern s32 D_800D5454;
extern s32 D_800D92B0;
extern s32 D_800D92B4;

// .bss
extern UnkStruct_80198368 D_80198368[2];
extern s32 D_801AE950;
extern s32 D_801BB120;
extern UnkStruct_801BB138 D_801BB138[];
extern s32 D_801BC938;
extern UnkStruct_801BC940 D_801BC940[];
extern s32 D_801BFA40;
extern UnkStruct_801BFA48 D_801BFA48[];
extern s32 D_801BFB68;
extern UnkStruct_801BFB70 D_801BFB70[];
extern s32 D_801BFD70;
extern s32 D_801C058C;
extern s32 D_801C059C;
extern s32 D_801C05AC;
extern s32 D_801C05BC;
extern UnkStruct_801C0580 D_801C0580[];
extern s16 D_801C0840[];
extern s16 D_801C0AC0[];
extern UnkStruct_801C0C80* D_801C0C80;
extern f32 D_801C0C84;
extern f32 D_801C0C88;
extern f32 D_801C0C8C;
extern s32 D_801C0C90[2][4];
extern s32 D_801C0CB0;
extern s32 D_801C0CB4;
extern s32 D_801C0CB8;
extern s32 D_801C0CBC;
extern s32 D_801C0CC0;
extern s32 D_801C0CC4;
extern s32 D_801C1FD0;
extern s32 D_801C292C;
extern RiderStruct D_801C2938[];
extern UnkStruct_801BC940_unk60 D_801BFD78[];
extern s32 D_801C1FC8;
extern s32 D_801BB12C;
extern s32 D_800D5438;
extern RiderStruct D_801C2C70[];
extern UnkStruct_801AEE20 D_801B2F20;
extern Vec3f D_800D5408[];
extern s32 D_801C26C0[];

extern s32 D_10149A0;
extern s32 D_800D48E0;
extern s32 D_80223934;
extern s32 D_80228AAC;
extern s32 D_80228AB0;
extern s32 D_80228AB4;

// segmented addresses
extern Gfx D_10145F0[];
extern u16 D_101ED68[];
extern u16 D_101F170[];
extern UNK_TYPE D_1029978[];
extern Gfx D_102BF48[];
extern Gfx D_102BFD8[];
extern Gfx D_102C798[];
extern Gfx D_102C828[];
extern s32 D_1014A18[];
extern s32 D_1015220[];
extern s32 D_1015A28[];
extern s32 D_1016230[];
extern Gfx D_102CE78[];
extern LookAt D_500B2C0[];
extern LookAt D_500B2D0[];
extern s32 D_802E1F0[];
extern s32 D_802E9F8[];
extern u8 D_E0098D0[];
extern UnkStruct_10445C8 D_10445C8[];

// Externs for func_8006E674 draft (imported external scratch, see floor note)
typedef struct chkcrs_entry_s {
    s32 ibnext; /* @+0: sole use verified against stub (888-byte stride, see note) */
    char pad[0x374];
} chkcrs_entry_t;
extern s32 D_801C2944; /* bss base of the logical chkcrs array */
#define chkcrs ((chkcrs_entry_t*) &D_801C2944)
extern UnkStruct_801C0C80 D_801CB058[]; /* NOTE: stub indexes with 0x110 stride, bss labels 0xAC: unresolved */
extern s32 D_800D4B04;
extern s32 D_800D5440;
extern s32 D_800D5444;
extern s32 D_800D5448;
extern s32 D_800D5450;
extern s16 D_801C05C0[];
extern s16 D_801C0640[];
extern s16 D_801C08C0[];
extern u8 D_801C0B40[]; /* u8 per stub sb/lbu + bss sizes; matches collaborator ctx */
extern u8 D_801C0B80[]; /* u8 per stub sb/lbu + bss sizes; matches collaborator ctx */
extern Mtx D_801C0CD0[];
extern Gfx* D_801C1CD0;
extern Gfx* D_801C1CD4;
extern Gfx* D_801C1CD8;
extern Gfx* D_801C1CDC;
extern Gfx* D_801C1CE0;
extern Gfx* D_801C1CE4;
extern Gfx D_1014438[];
extern u8 D_1016A38[];
extern u8 D_1017A38[];
extern Gfx D_1018AA8[];
extern Gfx D_1018D58[];
extern u8 D_101F978[];
extern Gfx D_1029BE0[];
extern Gfx D_1029C88[];
extern Gfx D_102AD90[];
extern Gfx D_102AE38[];
extern Gfx D_102CB78[];
extern Gfx D_102CC58[];
extern Gfx D_102CC70[];
extern UnkStruct_801BC940 D_102CD78[];
extern Gfx D_102CD90[];
extern Gfx D_102CD00[];
extern Gfx D_102CCE8[];
extern UnkStruct_801BC940 D_102CE08[];
extern Gfx D_102CE20[];
extern Gfx D_102CF10[];
extern Gfx D_102CF28[];
extern Mtx D_2000A40[];
extern Gfx D_8029FA70[];
extern Gfx D_8029FAD0[];
extern Gfx D_8029FCD8[];
extern Gfx D_8029FDC8[];
extern Gfx D_8029FC50[];
extern Gfx D_8029FF58[];
extern Gfx D_D02B640[];
extern u16 D_D4B18[];
extern u16 D_D4D18[];
extern u16 D_D4F18[];
extern u16 D_D5118[];
extern UNK_TYPE D_E00F478[];
extern UNK_TYPE D_E011480[];
extern UNK_TYPE D_E013488[];
extern Gfx D_E010DF0[];
extern Gfx D_E010ED0[];

// codeseg
extern s32 D_80223934;

// TODO: Move this to the proper header
extern void guLookAtHilite(Mtx* m, LookAt* l, Hilite* h, float xEye, float yEye, float zEye, float xAt, float yAt,
                           float zAt, float xUp, float yUp, float zUp, float xl1, float yl1,
                           float zl1,                       /* light 1 direction */
                           float xl2, float yl2, float zl2, /* light 2 direction */
                           int twidth, int theight);

void func_800C3628(s32);
void func_801FB488(s32, s32, s32);
void func_8006A300(void);
void Spray_Reset(void);
void func_801EDFFC(s32, s32, f32, s32);
void func_8004CC7C(UnkStruct_801BFB70*); /* extern */
void func_8004F520(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
void func_801EE6F4(s32*, s32, s32, f32, f32, f32, f32); /* extern */
void func_80079528(void);                               /* extern */
void func_8007DBC0(void);                               /* extern */
void Spray_Update(void);
void Spray_Draw(Gfx**); /* == func_800B4ABC per retail map; scratch used the numeric name */
f32 func_801ED090(f32); /* extern; defined in codeseg/B97B0.c */
void func_8006E0F4(void);
f32 func_801ED338(f32);

void func_8006A300(void) {
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_s6;
    s32 temp_t0;
    s32 temp_t1;
    u16* var_ra;
    s32 i;
    s32 j;
    s32 r;
    s32 g;
    s32 b;

    var_ra = SegmentedToVirtual(D_1029978);
    for (i = 0; i < 4; i++) {
        s16 temp_s1 = D_800D5318[i][0];
        s16 temp_s2 = D_800D5318[i][1];
        s16 temp_s3 = D_800D5318[i][2];
        for (j = 0; j < 256; j++) {
            temp_a0 = (var_ra[j] >> 6) & 0x1F;
            temp_t0 = (var_ra[j] >> 1) & 0x1F;
            temp_lo = (var_ra[j] >> 0xB);
            temp_t1 = (var_ra[j] & 1);
            // FAKE
            r = (((((0, temp_lo) * temp_s1) / 255) + ((temp_a0 * (0xFF - temp_s1)) / 255)));
            g = ((((0, temp_lo) * temp_s2) / 255) + ((temp_a0 * (0xFF - temp_s2)) / 255));
            b = ((((0, temp_lo) * temp_s3) / 255) + ((temp_t0 * (0xFF - temp_s3)) / 255));
            D_800D4B18[i][j] = ((r << 0xB) + (g << 6) + (b << 1) + temp_t1);
        }
    }
}

// Updates stunt mode ring score
void func_8006A748(void) {
    UnkStruct_80192690* temp_a0;
    UnkStruct_801BC940* var_v0;
    RiderStruct* temp_v1;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f16;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f30;
    f32 var_f0;
    s32 temp_v0;
    s32 i;
    s32* temp;

    temp_a0 = &D_80192690[D_800D48DC];
    temp_v1 = &D_801C2938[D_800D48DC];
    if ((temp_v1->unk2F4 == 0) && (temp_v1->unk2EC == 0)) {
        temp_f26 = temp_a0->unk44.x;
        temp_f28 = temp_a0->unk44.y + 8.0f;
        temp_f30 = temp_a0->unk44.z;

        for (i = 0; i < D_801BFA40; i++) {
            if (D_801BC940[i].unk4C != 8) {
                continue;
            }
            if (D_801BC940[i].unkBC != 0) {
                if (D_801BC940[i].unk6C < 0xFF) {
                    D_801BC940[i].unk6C++;
                }
            } else {
                temp_f2 = temp_f26 - D_801BC940[i].unk0;
                temp_f14 = temp_f28 - D_801BC940[i].unk4;
                temp_f16 = temp_f30 - D_801BC940[i].unk8;
                temp_f0 = (temp_f16 * D_801BC940[i].unk34) + (D_801BC940[i].unk30 * temp_f2);
                if (temp_f0 >= 0.0f) {
                    temp_f0 = temp_f0;
                } else {
                    temp_f0 = -temp_f0;
                }
                if (temp_f0 > 32.0f) {
                    continue;
                }
                temp = &D_801BC940[i].unkC0;
                temp_f0 = (temp_f16 * D_801BC940[i].unk3C) + (D_801BC940[i].unk38 * temp_f2);
                if (sqrtf(SQ(temp_f0) + SQ(temp_f14)) < 112.0f) {
                    D_801BC940[i].unkBC = 1;
                    if (D_801C0CB0 == *temp) {
                        D_801C0CB0++;
                        D_801C0CB4++;
                    } else {
                        D_801C0CB0 = *temp + 1;
                        D_801C0CB4 = 1;
                    }
                    D_801C292C++;
                    func_801FB488(3, D_800D92B0 + ((D_801C0CB4 - 1) * D_800D92B4), 0);
                    func_800C3628(D_801C0CB4);
                }
            }
        }
    }
}

void func_8006AA58(void) {
    camera_unk_1* camera;

    D_801C058C = 0;
    D_801C059C = 0;
    D_801C05AC = 0;
    D_801C05BC = 0;
    camera = &gCameraPerspective[D_80223930];
    D_801C0C84 = camera->unk4C;
    D_801C0C88 = camera->unk54;
    D_801C0C8C = 700.0f;
}

void func_8006AACC(s32 arg0) {
    s32 i;
    s32 k;
    s32 j;
    Vtx* vtx;
    s32 temp;
    if (D_800D543C != 0) {
        D_800D543C = 0;
        func_8006A300();
    }
    func_80075274();

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            vtx = D_80198368[i].unk5140[j];
            for (k = 0; k < 4; k++) {
                vtx->v.flag = 0;
                temp = k % 4;
                if ((temp == 0) || (temp == 3)) {
                    vtx->v.cn[0] = 0xC0;
                    vtx->v.cn[1] = 0xC0;
                    vtx->v.cn[2] = 0x20;
                } else {
                    vtx->v.cn[0] = 0x20;
                    vtx->v.cn[1] = 0xC0;
                    vtx->v.cn[2] = 0x20;
                }
                vtx->v.cn[3] = 0xFF;
                vtx++;
            }
        }
    }
    func_8006AA58();
    Spray_Reset();
    D_801C0CB0 = D_801C0CB4 = 0;

    for (k = 0; k < 2; k++) {
        for (i = 0; i < gRiders; i++) {
            D_801C0C90[k][i] = 0xFF;
        }
    }

    D_801C0CB8 = D_801C0CBC = D_801C0CC0 = D_801C0CC4 = 0;
    if (gCourseID == 2) {
        D_800D5454 = 0;
    } else if (gCourseID == 4) {
        D_800D5454 = 2;
    } else {
        D_800D5454 = 1;
    }
}

void func_8006AC84(s32 arg0, Mtx* arg1) {
    UnkStruct_801AEE20* temp_v0;
    UnkStruct_801AEE20* var_v1_3;
    f32 temp_fv0;
    f32 temp_fv1;
    f32 temp_fa0;
    f32 var_ft5;
    f32 var_fa1;
    s32 temp_t0;
    s32 var_a1;
    f32 var_fv0;
    f32 sp8C;
    MtxF sp4C;
    s32 i;

    if (D_801CE638 == 8) {
        if (gCourseID == SUNNY_BEACH) {
            temp_t0 = (gRiders - arg0) - 1;
            var_ft5 = (64.0f - ((temp_t0 & 1) * 128.0f)) + 52.0f;

            if (temp_t0 >= 2) {
                var_ft5 -= 32.0f;
            }
            sp8C = (((gRiders - temp_t0) - 1) * 80.0f) + -512.0f;

            temp_fv0 = (D_801AEE20[D_801BB12C].unk0 + (var_ft5 * D_801AEE20[D_801BB12C].unk78)) +
                       (D_801AEE20[D_801BB12C].unk70 * sp8C);
            temp_fa0 = (D_801AEE20[D_801BB12C].unk8 + (var_ft5 * D_801AEE20[D_801BB12C].unk7C)) +
                       (D_801AEE20[D_801BB12C].unk74 * sp8C);
            SysUtils_MatrixLookAt(arg1, &sp4C, D_801AEE20[D_801BB12C].unk70, 0.0f, D_801AEE20[D_801BB12C].unk74, 0.0f,
                                  1.0f, 0.0f, temp_fv0, 0.0f, temp_fa0);
            return;
        }
        var_a1 = -1;
        temp_t0 = (arg0 + D_800D5438) & 3;
        if (temp_t0 == 0) {
            var_a1 = 0xB;
        } else if (temp_t0 == 1) {
            var_a1 = 0xC;
        } else if (temp_t0 == 2) {
            var_a1 = 0xD;
        } else if (temp_t0 == 3) {
            var_a1 = 0xE;
        }
        for (i = 0; i < D_801BB120; i++) {
            if (var_a1 == D_801AEE20[i].unk98) {
                break;
            }
        }

        if (i >= D_801BB120) {
            i = temp_t0;
        }
        SysUtils_MatrixLookAt(arg1, &sp4C, D_801AEE20[i].unk70, 0.0f, D_801AEE20[i].unk74, 0.0f, 1.0f, 0.0f,
                              D_801AEE20[i].unk0, 0.0f, D_801AEE20[i].unk8);
        return;
    }
    if (D_801CE638 == 0x15) {
        temp_t0 = D_801C2C70[arg0].lapCount;
        if (temp_t0 < 3) {
            var_fa1 = 1.00f;
            var_ft5 = 0.0f;
            i = 0;
        } else {
            var_fa1 = 1.000f;
            var_ft5 = -1.0f;
            i = 3;
        }
        temp_fv0 = D_800D5408[i].x - 8.0f;
        temp_fv1 = D_800D5408[i].y;
        temp_fa0 = D_800D5408[i].z;
        SysUtils_MatrixLookAt(arg1, &sp4C, var_fa1, 0.0f, var_ft5, 0.0f, 1.0f, 0.0f, temp_fv0, temp_fv1, temp_fa0);
        return;
    }
    if (gRiders == 1) {
        sp8C = -512.0f;
        var_ft5 = 0.0f;
        if ((gGameModes != GMODE_STUNT) && (gCourseID == DOLPHIN_PARK)) {
            sp8C -= 512.0f;
        }
    } else {
        if (gRiders == 2) {
            if (arg0 == D_800D48DC) {
                var_ft5 = 48.0f;
                sp8C = -512.0f;
            } else {
                var_ft5 = -48.0f;
                sp8C = -512.0f;
            }
            var_ft5 += 52.0f;
            if (gCourseID == DOLPHIN_PARK) {
                sp8C -= 512.0f + ((f32) arg0 * 96.0f);
            }
        } else if (D_801CE638 == 0) {
            var_ft5 = (64.0f - ((f32) (arg0 & 1) * 128.0f)) + 52.0f;
            sp8C = ((f32) (gRiders - arg0) * 80.0f) + -512.0f;
        } else if (gGameModes == GMODE_CHAMPIONSHIP) {
            temp_t0 = D_801C26C0[arg0];
            if (D_801C1F90 == 0) {
                var_ft5 = (64.0f - ((f32) (temp_t0 & 1) * 128.0f)) + 52.0f;
                if (temp_t0 >= 2) {
                    var_ft5 -= 32.0f;
                }
            } else {
                var_ft5 = (((f32) (temp_t0 & 1) * 128.0f) + -64.0f) - 52.0f;
                if (temp_t0 >= 2) {
                    var_ft5 += 32.0f;
                }
            }
            sp8C = ((f32) ((gRiders - temp_t0) - 1) * 80.0f) + -512.0f;
        } else {
            var_ft5 = (64.0f - ((f32) (arg0 & 1) * 128.0f)) + 52.0f;
            sp8C = ((f32) arg0 * 80.0f) + -512.0f;
        }
    }
    if ((gCourseID == RIDER_SELECTION) && (arg0 == D_800D48E0)) {
        var_v1_3 = &D_801B2F20;
    } else {
        var_v1_3 = D_801AEE20;
    }
    temp_fv0 =
        (var_v1_3[D_801BB12C].unk0 + (var_ft5 * var_v1_3[D_801BB12C].unk78)) + (var_v1_3[D_801BB12C].unk70 * sp8C);
    temp_fa0 =
        (var_v1_3[D_801BB12C].unk8 + (var_ft5 * var_v1_3[D_801BB12C].unk7C)) + (var_v1_3[D_801BB12C].unk74 * sp8C);
    SysUtils_MatrixLookAt(arg1, &sp4C, var_v1_3[D_801BB12C].unk70, 0.0f, var_v1_3[D_801BB12C].unk74, 0.0f, 1.0f, 0.0f,
                          temp_fv0, 0.0f, temp_fa0);
}

void func_8006B334(Gfx** gdl) {
    f32 var_fv0;
    f32 temp_f18;
    f32 temp_f8;
    f32 temp_fa0;
    s32 var_t5;
    f32 var_fv1;
    s32 var_t2;
    s32* var_t4;
    s32* var_ra_2;
    s32 var_v0_2;
    f32 var_fa0;
    f32 temp_ft5;
    f32 temp_fv1;
    f32 sp160;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_ft4;
    f32 temp_fv0_2;
    s32 var_ra;
    s32 var_v1;
    camera_unk_1* sp144;
    RiderStruct* var_v0;
    s32 pad;
    Gfx* gdlh;
    MtxF spF8;

    gdlh = *gdl;
    if (D_800DAB2C == 0) {
        sp144 = &gCameraPerspective[D_80223930];
        var_v0 = &D_801C2938[D_800D48DC];
    } else {
        sp144 = &gCameraPerspective[D_80223934];
        var_v0 = &D_801C2938[D_800D48E0];
    }
    if (var_v0->unk2F4 != 0) {
        return;
    }
    if ((var_v0->unk320 != var_v0->lapCount)) {
        return;
    }
    if ((var_v0->unkC == D_801BB12C) && (var_v0->unk20 == 0)) {
        return;
    }
    var_t5 = 0;
    var_ra = 0;
    var_v1 = var_v0->unkC;
    if ((var_v0->lapCount >= D_801CE728[0]) && (var_v0->unkC == (0, D_801BB12C))) {
        var_ra = 1;
    }
    var_v0_2 = D_801BB120;
    while (((D_801AEE20[var_v1].unk9C != 0) || (D_801AEE20[var_v1].unkC8 == 0)) && (--var_v0_2 > 0)) {

        if ((var_v0->lapCount >= D_801CE728[0]) && (var_v1 == D_801BB12C)) {
            var_t5 = 1;
            var_ra = 1;
        }
        var_v1 = D_801AEE20[var_v1].unkA0;
    }
    var_t2 = D_801AEE20[var_v1].unkA0;
    if ((var_v0->lapCount >= D_801CE728[0]) && (var_t2 == D_801BB12C)) {
        var_t5 = 1;
    }
    var_v0_2 = D_801BB120;
    while (((D_801AEE20[var_t2].unk9C != 0) || (D_801AEE20[var_t2].unkC8 == 0)) && (--var_v0_2 > 0)) {
        if ((var_v0->lapCount >= D_801CE728[0]) && (var_t2 == D_801BB12C)) {
            var_t5 = 1;
        }
        var_t2 = D_801AEE20[var_t2].unkA0;
    }
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE | 0x0100000);
    gDPSetCombineLERP(gdlh++, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0, ENVIRONMENT,
                      COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED);
    gDPSetRenderMode(gdlh++, G_RM_PASS, G_RM_AA_ZB_TEX_EDGE2);

    if ((D_801CE638 == 1) && (D_801AEE20[var_v1].unk9C == 0) && (D_801AEE20[var_v1].unkC8 != 0) && (var_ra == 0)) {
        switch (D_801AEE20[var_v1].unk98) {
            case 0:
                var_t4 = D_1015A28;
                var_ra_2 = D_1016230;
                break;
            case 1:
                var_t4 = D_1014A18;
                var_ra_2 = D_1015220;
                break;
            default:
                var_t4 = D_1015A28;
                var_ra_2 = D_1016230;
                break;
        }

        temp_ft5 = D_801AEE20[var_v1].unk0;
        temp_fv1 = D_801AEE20[var_v1].unk4 + 128.0f;
        sp160 = D_801AEE20[var_v1].unk8;
        temp_fa1 = sp144->unk4C - temp_ft5;
        temp_fv0 = sp144->unk50 - temp_fv1;
        temp_ft4 = sp144->unk54 - sp160;
        temp_fv0_2 = sqrtf(SQ(temp_fa1) + SQ(temp_fv0) + SQ(temp_ft4));
        if (temp_fv0_2 > 3000.0f) {
            var_fa0 = temp_fv0_2 / 3000.0f;
        } else {
            var_fa0 = 1.0f;
        }
        if ((temp_fa1 != 0.0f) || (temp_ft4 != 0.0f)) {
            var_fv0 = 1.0f;
            var_fv1 = 0.0f;
        } else {
            var_fv0 = 0.0f;
            var_fv1 = 1.0f;
        }

        SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spF8, temp_fa1, temp_fv0, temp_ft4, 0.0f, var_fv0,
                              var_fv1, temp_ft5, temp_fv1, sp160);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_801EE97C(&D_801AE948->unk4140[D_801AE950], var_fa0, var_fa0, var_fa0);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPPipeSync(gdlh++);
        gDPLoadTextureBlock(gdlh++, var_t4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

        gDPLoadMultiBlock(gdlh++, var_ra_2, 0x100, 1, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0,
                          G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                          G_TX_NOLOD);
        var_v0_2 = D_800D4B00 & 3;
        if (var_v0_2 == 3) {
            var_v0_2 = 1;
        }

        var_v0_2 *= 127;
        gDPSetPrimColor(gdlh++, 0, 0, var_v0_2, var_v0_2, var_v0_2, var_v0_2);
        gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, 0);
        gSPDisplayList(gdlh++, D_102CE78);
    }
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gdlh++, ENVIRONMENT, TEXEL0, ENV_ALPHA, TEXEL0, 0, 0, 0, TEXEL0, ENVIRONMENT, TEXEL0, ENV_ALPHA,
                      TEXEL0, 0, 0, 0, TEXEL0);
    gDPSetRenderMode(gdlh++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE2);
    if ((D_801CE638 == 1) && (D_801AEE20[var_t2].unk9C == 0) && (D_801C0840[var_t2] >= 0) && (var_t5 == 0)) {
        if (D_801C0840[var_t2]) {}
        switch (D_801AEE20[var_t2].unk98) {
            case 0:
                var_t4 = D_1015A28;
                break;
            case 1:
                var_t4 = D_1014A18;
                break;
            default:
                var_t4 = D_1015A28;
                break;
        }

        temp_ft5 = D_801AEE20[var_t2].unk0;
        temp_fv1 = D_801AEE20[var_t2].unk4 + 128.0f;
        sp160 = D_801AEE20[var_t2].unk8;
        temp_fa1 = sp144->unk4C - temp_ft5;
        temp_fv0 = sp144->unk50 - temp_fv1;
        temp_ft4 = sp144->unk54 - sp160;
        if ((temp_fa1 != 0.0f) || (temp_ft4 != 0.0f)) {
            var_fv0 = 1.0f;
            var_fv1 = 0.0f;
        } else {
            var_fv1 = 1.0f;
            var_fv0 = 0.0f;
        }
        SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spF8, temp_fa1, temp_fv0, temp_ft4, 0, var_fv0,
                              var_fv1, temp_ft5, temp_fv1, sp160);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gdlh++);
        gDPLoadTextureBlock(gdlh++, var_t4, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_CLAMP,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, 0);
        gSPDisplayList(gdlh++, D_102CE78);
    }
    *gdl = gdlh;
}

void func_8006BE74(Gfx** gdl) {
    Gfx* gdlh;
    camera_unk_1* var_s5;
    s32 sp17C;
    s32 sp16C[4];
    f32 temp_f0;
    f32 temp_f0_3;
    f32 temp_f14;
    f32 temp_f26;
    f32 temp_f2;
    f32 var_f20;
    f32 var_f22;
    s32 temp_a1;
    f32 sp148;
    f32 sp144;
    f32 sp140;
    s32 temp_t0;
    f32 sp138;
    f32 sp134;
    s32 temp_v1;
    s32 var_s3;
    s32 var_s4;
    MtxF spE8;

    gdlh = *gdl;
    if (D_800DAB2C == 0) {
        var_s5 = &gCameraPerspective[D_80223930];
        sp17C = D_800D48DC;
    } else {
        var_s5 = &gCameraPerspective[D_80223934];
        sp17C = D_800D48E0;
    }
    sp148 = -var_s5->unk64;
    var_s3 = 0;
    sp144 = -var_s5->unk68;
    sp140 = -var_s5->unk6C;
    if ((sp148 != 0.0f) || (sp140 != 0.0f)) {
        sp134 = 0.0f;
        sp138 = 1.0f;
    } else {
        sp134 = 1.0f;
        sp138 = 0.0f;
    }
    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        sp16C[var_s4] = 0;
        if ((D_800DAB2C == 0) && (var_s4 == D_800D48DC)) {
            continue;
        }
        var_f20 = D_80192690[var_s4].unk44.x - var_s5->unk4C;
        var_f22 = D_80192690[var_s4].unk44.z - var_s5->unk54;
        temp_f0_3 = sqrtf(SQ(var_f20) + SQ(var_f22));
        if (temp_f0_3 > 0.0f) {
            var_f20 /= temp_f0_3;
            var_f22 /= temp_f0_3;
        }
        if ((temp_f0_3 < 4096.0f) && (((var_s5->unkF0 * var_f20) + (var_f22 * var_s5->unkF4)) > 0.7f)) {
            sp16C[var_s4] = 1;
        }
        if (sp16C[var_s4] != 0) {
            if ((D_801C0C90[D_800DAB2C][var_s4] < 0xFF) && GAME_NOT_PAUSED) {
                D_801C0C90[D_800DAB2C][var_s4]++;
            }
        } else {
            D_801C0C90[D_800DAB2C][var_s4] = 0;
        }
    }
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gdlh++, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0, 0, ENVIRONMENT, 0, TEXEL0,
                      0, ENVIRONMENT, 0);
    gDPSetRenderMode(gdlh++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    for (var_s4 = 0; var_s4 < gRiders; var_s4++) {
        if ((var_s4 == sp17C) || (D_801C0C90[D_800DAB2C][var_s4] >= 0x1E) || (sp16C[var_s4] == 0)) {
            continue;
        }
        if ((D_801C2938[sp17C].racePosition < D_801C2938[var_s4].racePosition) || (D_801C2938[var_s4].unk2F4 != 0)) {
            continue;
        }

        var_f20 = D_80192690[var_s4].unk44.x;
        temp_f26 = D_80192690[var_s4].unk44.y;
        var_f22 = D_80192690[var_s4].unk44.z;
        temp_f0 = var_s5->unk4C - var_f20;
        temp_f2 = var_s5->unk50 - temp_f26;
        temp_f14 = var_s5->unk54 - var_f22;
        temp_f0_3 = sqrtf(SQ(temp_f0) + SQ(temp_f2) + SQ(temp_f14));
        if (temp_f0_3 < 1024.0f) {
            D_801C0C90[D_800DAB2C][var_s4] = 0xFF;
            continue;
        }

        SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spE8, sp148, sp144, sp140, 0.0f, sp138, sp134, var_f20,
                              temp_f26 + 56.0f + (temp_f0_3 * 0.03125f), var_f22);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_801EE97C(&D_801AE948->unk4140[D_801AE950], temp_f0_3 * 0.0078125f, temp_f0_3 * 0.0078125f,
                      temp_f0_3 * 0.0078125f);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gDPLoadTextureBlock(gdlh++, &D_10445C8[D_801C2938[var_s4].racePosition], G_IM_FMT_IA, G_IM_SIZ_8b, 16, 12, 0,
                            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK,
                            G_TX_NOLOD, G_TX_NOLOD);
        gDPSetEnvColor(gdlh++, D_80228AAC, D_80228AB0, D_80228AB4, 0xFF);
        gSPDisplayList(gdlh++, &D_10149A0);
    }
    *gdl = gdlh;
}

void func_8006C5D8(Gfx** gdl) {
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fs0;
    f32 temp_fs1;
    f32 temp_fv1;
    f32 temp_f4;
    f32 temp_f6;
    f32 var_f0;
    s32 pad[1];
    f32 sp150;
    s32 pad14C;
    f32 var_f24;
    f32 sp144;
    f32 sp140;
    f32 var_f26;
    s32 var_s1;
    s32 i;
    f32 sp130;
    s32 j;
    camera_unk_1* temp_s3;
    UnkStruct_800D5330* var_v0;
    MtxF spE4;
    Gfx* gdlh;

    gdlh = *gdl;
    temp_s3 = &gCameraPerspective[D_80223930];
    var_f26 = temp_s3->unk64;
    var_f24 = temp_s3->unk6C;
    temp_fv0 = sqrtf(SQ(var_f26) + SQ(var_f24));
    if (temp_fv0 > 0.0f) {
        var_f26 /= temp_fv0;
        var_f24 /= temp_fv0;
    }
    sp130 = -var_f26;
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
    gDPSetCombineLERP(gdlh++, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, 0, SHADE, 0);
    gDPSetRenderMode(gdlh++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);
    gDPLoadTextureBlock(gdlh++, &D_E0098D0[(D_800D4B00 & 0x1F) << 5], G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0,
                        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    sp150 = 0.0f;
    if ((var_f26 != 0.0f) || (var_f24 != 0.0f)) {
        sp140 = 0.0f;
        sp144 = 1.0f;
    } else {
        sp144 = 0.0f;
        sp140 = 1.0f;
        sp150 = 1.0f;
    }
    for (i = 0; i < 4; i++) {
        if (D_801C0580[i].unkC == 0) {
            if (D_801C1FD0 != 0) {
                continue;
            }

            temp_fs0 = D_801C0C84 - temp_s3->unk4C;
            temp_fs1 = D_801C0C88 - temp_s3->unk54;
            temp_fv0 = sqrtf(SQ(temp_fs0) + SQ(temp_fs1));
            if (!(D_801C0C8C < temp_fv0)) {
                continue;
            }

            D_801C0C84 = temp_s3->unk4C;
            D_801C0C88 = temp_s3->unk54;
            D_801C0C8C = func_801ED338(500.0f) + 500.0f;
            D_801C0580[i].unkC = 1;
            temp_fv1 = func_801ED338(1024.0f) - 512.0f;
            temp_f4 = temp_fv1 * var_f24;
            D_801C0580[i].unk0 = (temp_s3->unk4C + (var_f26 * 2024.0f) + temp_f4);
            D_801C0580[i].unk4 = -64.0f;
            D_801C0580[i].unk8 = (temp_s3->unk54 + (var_f24 * 2024.0f) + (temp_fv1 * sp130));
            var_s1 = false;
            for (j = 0; D_800D5330[j].unk0 != D_800D5330[j].unk4; j++) {
                temp_fv0 = D_800D5330[j].unk0;
                if ((D_800D5330[j].unk0 <= D_801C0580[i].unk0) && (D_801C0580[i].unk0 <= D_800D5330[j].unk4) &&
                    ((D_800D5330[j].unk8 <= D_801C0580[i].unk8)) && (D_801C0580[i].unk8 <= D_800D5330[j].unkC)) {
                    var_s1 = true;
                    break;
                }
            }

            if (var_s1) {
                D_801C0580[i].unkC = 0;
                continue;
            }
        } else {
            temp_fs0 = D_801C0580[i].unk0 - temp_s3->unk4C;
            temp_fs1 = D_801C0580[i].unk8 - temp_s3->unk54;
            temp_fv0 = sqrtf(SQ(temp_fs0) + SQ(temp_fs1));
            if (temp_fv0 > 0.0f) {
                temp_fs0 /= temp_fv0;
                temp_fs1 /= temp_fv0;
            }
            if (((temp_fs0 * var_f26) + (temp_fs1 * var_f24)) < -0.3f) {
                D_801C0580[i].unkC = 0;
                continue;
            }
        }
        SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spE4, var_f26, sp150, var_f24, 0.0f, sp144, sp140,
                              D_801C0580[i].unk0, D_801C0580[i].unk4, D_801C0580[i].unk8);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gdlh++, D_10145F0);
    }

    *gdl = gdlh;
}

void func_8006CB98(Gfx** gdl) {
    s32 var_s3;
    Gfx* gdlh;

    gdlh = *gdl;
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(gdlh++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
    gDPSetCombineMode(gdlh++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gdlh++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);

    for (var_s3 = 0; var_s3 < D_801BB120; var_s3++) {
        if (D_801C0840[var_s3] < 0) {
            continue;
        }

        if ((D_801AEE20[var_s3].unk9C != 0) || (D_801AEE20[var_s3].unkC8 == 0)) {
            continue;
        }

        func_801EDFFC(&D_801AE948->unk4140[D_801AE950], D_801AEE20[var_s3].unk24, 0.0f, D_801AEE20[var_s3].unk28);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (D_801AEE20[var_s3].unk98 == 0) {
            gSPDisplayList(gdlh++, D_102C828);
        } else {
            gSPDisplayList(gdlh++, D_102BFD8);
        }
    }
    *gdl = gdlh;
}

void func_8006CDE8(Gfx** gdl) {
    s32 var_s3;
    Gfx* gdlh;

    gdlh = *gdl;
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH);
    gSPTexture(gdlh++, 0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
    gDPSetCombineMode(gdlh++, G_CC_MODULATEIDECALA, G_CC_MODULATEIDECALA);
    gDPSetRenderMode(gdlh++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    for (var_s3 = 0; var_s3 < D_801BB120; var_s3++) {
        if (D_801C0840[var_s3] < 0) {
            continue;
        }

        if ((D_801AEE20[var_s3].unk9C != 0) || (D_801AEE20[var_s3].unkC8 == 0)) {
            continue;
        }

        func_801EDFFC(&D_801AE948->unk4140[D_801AE950], D_801AEE20[var_s3].unk24, 0, D_801AEE20[var_s3].unk28);
        gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        if (D_801AEE20[var_s3].unk98 == 0) {
            gSPDisplayList(gdlh++, D_102C798);
        } else {
            gSPDisplayList(gdlh++, D_102BF48);
        }
    }
    *gdl = gdlh;
}

void func_8006D034(Gfx** gdl) {
    UnkStruct_801BC940* temp_s1;
    camera_unk_1* var_s5;
    f32 temp_f12;
    f32 temp_f18;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f2;
    s32 var_s2;
    MtxF spD8;
    Gfx* gdlh;
    f32 other;

    gdlh = *gdl;
    if (D_800DAB2C == 0) {
        var_s5 = &gCameraPerspective[D_80223930];
    } else {
        var_s5 = &gCameraPerspective[D_80223934];
    }
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH);
    gSPFogFactor(gdlh++, 0x1F400 / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78),
                 (((0x1F4 - (s32) D_801C0C80->unk78) * 256) / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78)))
        gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_2CYCLE);
    gDPSetFogColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0C80->unk54);

    for (var_s2 = 0; var_s2 < D_801BFA40; var_s2++) {
        if (D_801C0AC0[var_s2] < 0) {
            continue;
        }

        if (D_801BC940[var_s2].unk54 == 2) {
            temp_f12 = var_s5->unk4C - D_801BC940[var_s2].unk0;
            other = var_s5->unk50 - D_801BC940[var_s2].unk4;
            temp_f18 = var_s5->unk54 - D_801BC940[var_s2].unk8;
            if ((temp_f12 != 0.0f) || (temp_f18 != 0.0f)) {
                var_f0 = 1.0f;
                var_f2 = 0.0f;
            } else {
                var_f0 = 0.0f;
                var_f2 = 1.0f;
            }
            SysUtils_MatrixLookAt(&D_801AE948->unk4140[D_801AE950], &spD8, temp_f12, other, temp_f18, 0.0f, var_f0,
                                  var_f2, D_801BC940[var_s2].unk0, D_801BC940[var_s2].unk4, D_801BC940[var_s2].unk8);
            gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPSetGeometryMode(gdlh++, G_CULL_BACK);

            if (D_801BC940[var_s2].unkB4 != NULL) {
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
                gSPDisplayList(gdlh++, D_801BC940[var_s2].unkB4);
            }
            gSPClearGeometryMode(gdlh++, G_CULL_BACK);
            if (D_801BC940[var_s2].unkB8 != NULL) {
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2);

                gSPDisplayList(gdlh++, D_801BC940[var_s2].unkB8);
            }
        }
    }
    *gdl = gdlh;
}

// clang-format off
void func_8006D494(Gfx** gdl) {
    camera_unk_1* cam;
    f32 var_f0;
    s32 i;
    Gfx* gdlh;
    UnkStruct_801BC940 *ptr;

    gdlh = *gdl;
    cam = &gCameraPerspective[D_80223930];
    if (D_800D5454 == 0) {
        guLookAtHilite(D_801AE948->unk4100, D_801AE948->unkB2C0, D_801AE948->unkB2E0, cam->unk4C, cam->unk50,
                       cam->unk54, cam->unk7C, cam->unk80, cam->unk84, cam->unk70, cam->unk74,
                       cam->unk78, D_801C0C80->unkAC, D_801C0C80->unkB0, D_801C0C80->unkB4, 1.0f, 0.0f, 0.0f, 0x20,
                       0x20);
    } else {
        guLookAtReflect(D_801AE948->unk4100, D_801AE948->unkB2C0, cam->unk4C, cam->unk50, cam->unk54,
                        cam->unk7C, cam->unk80, cam->unk84, cam->unk70, cam->unk74, cam->unk78);
    }
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH);
    gSPSetLights0(gdlh++, D_6000000->unk35D8[D_800DAB2C]);
    gSPLookAt(gdlh++, D_500B2C0);
    gSPTexture(gdlh++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCycleType(gdlh++, G_CYC_2CYCLE);

    if (D_800D5454 == 0) {
        gSPTexture(gdlh++, 0x07C0, 0x07C0, 0, G_TX_RENDERTILE, G_ON);
        gDPSetEnvColor(gdlh++, 255, 255, 200, 255);

        // Custom version of gDPLoadTextureBlock?
        gDPSetTextureImage(gdlh++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, D_101ED68);gDPSetTile(gdlh++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPLoadSync(gdlh++);gDPLoadBlock(gdlh++, G_TX_LOADTILE, 0, 0, 511, 512);gDPPipeSync(gdlh++);gDPSetTile(gdlh++, G_IM_FMT_IA, G_IM_SIZ_8b, 4, 0, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPSetTileSize(gdlh++, 1, 0, 0, (32 - 1) << 2, (32 - 1) << 2);

        gDPSetHilite1Tile(gdlh++, 1, D_801AE948->unkB2E0, 32, 32);

        gDPSetCombineLERP(gdlh++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, SHADE, ENVIRONMENT, COMBINED, TEXEL0_ALPHA, COMBINED,
                          0, 0, 0, SHADE);
    } else if (D_800D5454 == 1) {
        gSPTexture(gdlh++, 0x0F80, 0x0F80, 0, G_TX_RENDERTILE, G_ON);
        gDPSetEnvColor(gdlh++, 255, 255, 255, 96); 
        gDPSetTextureImage(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_802E1F0); gDPSetTile(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPLoadSync(gdlh++);gDPLoadBlock(gdlh++, G_TX_LOADTILE, 0, 0, 1023, 256);gDPPipeSync(gdlh++);gDPSetTile(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPSetTileSize(gdlh++, 1, 0, 0, 0x007C, 0x007C);
        gDPSetCombineLERP(gdlh++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, COMBINED, ENV_ALPHA, COMBINED, 0, 0,
                          0, SHADE);
    } else {
        gSPTexture(gdlh++, 0x0F80, 0x0F80, 0, G_TX_RENDERTILE, G_ON);
        gDPSetEnvColor(gdlh++, 255, 255, 255, 96);
        gDPSetTextureImage(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, D_802E9F8);gDPSetTile(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, 5,
                   G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPLoadSync(gdlh++);gDPLoadBlock(gdlh++, G_TX_LOADTILE, 0, 0, 1023, 256);gDPPipeSync(gdlh++);gDPSetTile(gdlh++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD,
                   G_TX_NOMIRROR | G_TX_WRAP, 5, G_TX_NOLOD);gDPSetTileSize(gdlh++, 1, 0, 0, 0x007C, 0x007C);
        gDPSetCombineLERP(gdlh++, PRIMITIVE, 0, SHADE, 0, 0, 0, 0, SHADE, TEXEL0, COMBINED, ENV_ALPHA, COMBINED, 0, 0,
                          0, SHADE);
    }
    gSPFogFactor(gdlh++, 0x1F400 / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78),
                 (((0x1F4 - (s32) D_801C0C80->unk78) * 256) / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78)))
        gDPSetFogColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0C80->unk54);

    for (i = 0; i < D_801BFA40; i++) {
        ptr = &D_801BC940[i];
        if (D_801C0AC0[i] < 0) {
            continue;
        }
            
        if (ptr->unk54 == 3) {
            if (ptr->unk6C > 15) {
                continue;
            }
            _MtxF_to_Mtx(&ptr->unk74, &D_801AE948->unk4140[D_801AE950]);
            gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            
            if (ptr->unkBC != 0) {
                if (ptr->unk6C >= 8) {
                    var_f0 = 1.0f - ((ptr->unk6C - 8) * 0.125f);
                } else {
                    var_f0 = 1.0f;
                }
                func_801EE97C(&D_801AE948->unk4140[D_801AE950], var_f0, var_f0, var_f0);
                gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
            }

            gSPSetGeometryMode(gdlh++, G_CULL_BACK);
            if (ptr->unkB4 != NULL) {
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2);
                gSPDisplayList(gdlh++, ptr->unkB4);
            }
        }
    }
    *gdl = gdlh;
}
// clang-format on
void func_8006DE24(Gfx** gdl) {
    Gfx* gdlh;
    camera_unk_1* temp_v1;

    gdlh = *gdl;
    temp_v1 = &gCameraPerspective[D_80223930];

    guLookAtReflect(D_801AE948->unk4100, D_801AE948->unkB2C0, temp_v1->unk4C, temp_v1->unk50, temp_v1->unk54,
                    temp_v1->unk7C, temp_v1->unk80, temp_v1->unk84, -1.0f, 0.0f, 0.0f);
    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_TEXTURE_GEN | G_SHADING_SMOOTH);
    gDPPipeSync(gdlh++);
    /* clang-format off */
    gSPLookAtX(gdlh++, D_500B2C0); gSPLookAtY(gdlh++, D_500B2D0); // This needs to be in a single line to match
    /* clang-format on */
    gSPTexture(gdlh++, 0x0F80, 0x26C0, 0, G_TX_RENDERTILE, G_ON);
    gDPLoadTextureBlock(gdlh++, D_101F170, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetCombineMode(gdlh++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    *gdl = gdlh;
}

void func_8006E01C(s32 arg0) {
}

void configSignalRectangle(Gfx** gdl) {

    s32 pad1[0xF];
    Gfx* gdlh = *gdl;
    s32 pad2[2];

    gDPPipeSync(gdlh++);
    gDPSetTextureLUT(gdlh++, G_TT_NONE);

    if ((gPlayers == 1) && (gCourseID == 4)) {
        func_8006C5D8(&gdlh);
    }
    if ((D_801CE638 == 1) && ((gGameModes == 4) || (gGameModes == 1))) {
        func_8006BE74(&gdlh);
    }
    func_8006B334(&gdlh);

    *gdl = gdlh;
}

void func_8006E0F4(void) {
    UnkStruct_801BC940_unk60* var_s8 = D_801BFD78;
    s32 i;

    for (i = 0; i < D_801BFA40; i++) {
        UnkStruct_801BC940* ptr = &D_801BC940[i];
        f32* temp_s4;

        if ((ptr->unk4C == 0xA) && (ptr->unkBC != 0)) {
            ptr->unk54 = 0;
            if (ptr->unk6C < 0xFF) {
                ptr->unk6C++;
            }
        }

        if (ptr->unk58 == 0) {
            continue;
        }

        if (ptr->unk4C != 1) {
            if (ptr->unk4C == 2) {
                if (D_801C1FC8 != 0) {
                    if (ptr->unk4 < 128.0f) {
                        ptr->unk4 += 6.0f;
                    }
                }
            } else if (ptr->unk4C == 8) {
                if (ptr->unkC0 & 1) {
                    ptr->unk14 += 4.0f;
                    if (ptr->unk14 >= 360.0f) {
                        ptr->unk14 -= 360.0f;
                    }
                } else {
                    ptr->unk14 -= 4.0f;
                    if (ptr->unk14 < 0.0f) {
                        ptr->unk14 += 360.0f;
                    }
                }
            }
        }

        func_801EE6F4((s32*) &ptr->unk74, ptr->unkC, ptr->unk10, ptr->unk14, ptr->unk0, ptr->unk4, ptr->unk8);

        // FAKE
        if (D_801BFD78) {}
        if (ptr->unk68 == 1) {}
        if (ptr->unk68 == 10) {}
        if (ptr->unk68 > 0) {
            UnkStruct_801BC940_unk60* var_s0 = &D_801BFD78[ptr->unk64];
            UnkStruct_801BC940_unk60* var_s1 = ptr->unk60;
            s32 var_s2;

            for (var_s2 = 0; var_s2 < ptr->unk68; var_s2++) {
                func_801EDC60((s32*) &ptr->unk74, var_s1->unk0, var_s1->unk4, var_s1->unk8, &var_s0->unk0,
                              &var_s0->unk4, &var_s0->unk8);
                var_s0++;
                var_s1++;
            }
        }
    }
}

void func_8006E3A8(void) {
    f32 var_fv0;
    s32 temp_v0;
    s32 i;
    s32 var_v0;
    func_80079528();
    if (gCurrentPauseMenuOption == (-1)) {
        if (gGameModes == GMODE_STUNT) {
            func_8006A748();
        }
        func_8007DBC0();
        if (gCourseID == GLACIER_COAST) {
            for (i = 0; i < D_801BC938; i++) {
                if (D_801BB138[i].unk10 != 5) {
                    D_801BB138[i].unk4 = gWaterLevel;
                }
            }
        }
        func_8006E0F4();
        Spray_Update();
        for (i = 0; i < D_801BFB68; i++) {
            if (D_801BFA48[i].unk18 != 0) {
                var_fv0 = ((f32) (D_800D4B00 % D_801BFA48[i].unk14)) / D_801BFA48[i].unk14 * 360.0f;
                var_fv0 = gSinTable[((s32) (((var_fv0) / 360.0f) * 4096.0f)) & 0xFFF];
            } else {
                var_fv0 = 1.0f;
            }
            func_8004F520(D_801BFA48[i].unk10 * var_fv0, D_801BFA48[i].unk0, D_801BFA48[i].unk4, D_801BFA48[i].unk8,
                          D_801BFA48[i].unkC, D_801BFA48[i].unk1C);
        }

        for (i = 0; i < D_801BFD70; i++) {
            func_8004CC7C(&D_801BFB70[i]);
        }

        if (gCourseID == TWILIGHT_CITY) {
            D_801C0CBC += 4;
            if (D_801C0CBC >= 0x40) {
                D_801C0CBC = 0;
            }
            D_801C0CC4++;
            if (D_801C0CC4 >= 0x13) {
                D_801C0CC4 = 0;
            }
            if (D_801C0CC4 < 0xA) {
                D_801C0CC0 = 0;
            } else if (D_801C0CC4 < 0xC) {
                D_801C0CC0 = 1;
            } else if (D_801C0CC4 < 0x12) {
                D_801C0CC0 = 2;
            } else {
                D_801C0CC0 = 1;
            }
        }
    }
}

#ifdef NON_MATCHING
/* Floor note (2026-09-09): body imported from an external scratch pasted by the
 * collaborator (unscored remote m2c-shaped output, NOT a verified 0).
 * Import adaptations: param keeps repo TU name `gdl`; the scratch's
 * `func_800B4ABC(&gdlh)` is `Spray_Draw` (retail map: Spray_Draw == 0x800B4ABC),
 * so the stub's `jal Spray_Draw` and the draft's call set agree 1:1
 * (sqrtf×6, MatrixLookAt×4, SegmentedToVirtual×3, 801ED090, 6E01C, 6D494,
 * 6D034, 6CDE8, 6CB98, _MtxF_to_Mtx, Spray_Draw).
 * Verified-against-stub structural risks (see diff score below):
 *  - `chkcrs` is the scratch's name for a logical 888-byte-entry array based at
 *    bss D_801C2944 (stub: i = *(D_801C2944 + idx*888), ibnext @+0). Imported
 *    via #define; the linker symbol wants a proper rename + size later.
 *  - D_801CB058 is indexed with 0x110 stride (idx*17*16) but the bss label
 *    claims 0xAC total: unresolved, the natural decl below will mis-stride.
 *  - hov branch asymmetry: D_800D48DC path scales ~7960 (0x1F18) vs D_800D48E0
 *    path 5912 (0x1718 = sizeof UnkStruct_80192690): one branch cannot be
 *    `&D_80192690[idx]` as written.
 *  - Dozens of empty `if (!*(s32*) &X) {}` phantoms are m2c skeleton branches;
 *    each needs placement against the stub during real matching work.
 * Diff floor 410 (TU-object `-o` form vs matching object, no `-s`; was 3345
 * with s32 D_801C0B40/D_801C0B80, u8 per stub sb/lbu + collaborator ctx fixed
 * ~2900 rows. Prologue and both hov/camera index blocks match row-for-row,
 * first divergence is the D_801CB058 store: stub `sll,addu,sll` = idx*0x110
 * vs draft idx*0xB8). */
void func_8006E674(Gfx** gdl) {
    UnkStruct_801BC940* obj;
    s32 padR597;
    s32 imtx;
    s32 padR983;
    f32 dy;
    s32 alpha;
    f32 px;
    f32 lim;
    u8* tex2;
    s32 nearDist;
    s32 padA[2];
    s32 padR594;
    s32 inext2;
    UnkStruct_80192690* hov;
    f32 ang2;
    f32 ux;
    s32 padB[4];
    f32 ang;
    Mtx* mtxp;
    s32 padR404;
    s32 padR444;
    s32 farDist;
    s32 padB2;
    s32 pad17;
    s32 inext;
    s32 idx;
    camera_unk_1* camera;
    s32 padR2;
    s32 i;
    f32 viewX;
    f32 viewZ;
    f32 dx;
    s32 padR406;
    s32 padR373;
    f32 dz;
    Gfx* gdlh;
    Gfx* dlOpa;
    Gfx* dlXlu;
    s32 pad9;
    Gfx* dlRingXlu;
    s32 padC[2];
    MtxF mtx;
    UnkStruct_801AEE20* bwalk;
    s32 padD[4];

    gdlh = *gdl;
    if (D_800DAB2C == 0) {
        camera = &gCameraPerspective[D_80223930];
        hov = &D_80192690[D_800D48DC];
        if (!*(s32*) &gCourseID) {}
        i = chkcrs[D_800D48DC].ibnext;
    } else {
        if (!*(s32*) &D_801AE948) {}
        camera = &gCameraPerspective[D_80223934];
        hov = &D_80192690[D_800D48E0];
        i = chkcrs[D_800D48E0].ibnext;
    }
    D_801C0C80 = &D_801CB058[D_800DAB2C];
    sqrtf(SQ(hov->unk6C) + SQ(hov->unk74));
    if (camera->unk4C == 0.0f) {}
    viewX = camera->unk64;
    viewZ = camera->unk6C;
    ang = sqrtf(SQ(viewX) + SQ(viewZ));
    if (ang > 0.0f) {
        viewX /= ang;
        viewZ /= ang;
    }
    imtx = D_801BB120;
    while (((D_801AEE20[i].unk9C != 0) || (D_801AEE20[i].unkC8 == 0)) && (--imtx > 0)) {
        i = D_801AEE20[i].unkA0;
        if (!*(s32*) &gCourseID) {}
    }
    if (!*(s32*) &D_1017A38) {}
    inext = D_801AEE20[i].unkA0;
    if (!D_801C0B80[0]) {}
    imtx = D_801BB120;
    while (((D_801AEE20[inext].unk9C != 0) || (D_801AEE20[inext].unkC8 == 0)) && (--imtx > 0)) {
        inext = D_801AEE20[inext].unkA0;
    }
    inext2 = D_801AEE20[i].unkA8;
    imtx = D_801BB120;
    while (((D_801AEE20[inext2].unk9C != 0) || (D_801AEE20[inext2].unkC8 == 0)) && (--imtx > 0)) {
        inext2 = D_801AEE20[inext2].unkA8;
    }

    if (!*(s32*) &D_801BFA40) {}
    nearDist = D_801C0C80->unkA0;
    farDist = D_801C0C80->unkA4;
    for (i = 0; i < D_801BB120; i++) {
        if (D_801AEE20[i].unkC0 >= 2) {
            if ((D_800D4B04 & 1) || (D_800D5444 == 0)) {
                D_801C0840[i] = -1;
                continue;
            }
        } else if ((D_801AEE20[i].unkC8 == 0) && (D_800D5448 == 0)) {
            D_801C0840[i] = -1;
            continue;
        }
        dx = D_801AEE20[i].unk0 - camera->unk4C;
        dz = D_801AEE20[i].unk8 - camera->unk54;
        ang = sqrtf(SQ(dx) + SQ(dz));
        if (!D_801AEE20[0].unk98) {}
        if (D_801AEE20[i].unk9C == 1) {
            lim = 2.0f * (f32) farDist;
        } else {
            if (!*(s32*) &D_801BC938) {}
            if (!D_801AEE20[0].unk98) {}
            lim = (f32) farDist;
        }
        if (ang < lim) {
            if (ang > 0.0f) {
                dx /= ang;
                dz /= ang;
            }
            if ((((dx * viewX) + (dz * viewZ)) > 0.5f) || (D_801AEE20[i].unk9C == 1) || (D_801AEE20[i].unk98 == 8) ||
                (D_801AEE20[i].unk98 == 9)) {
                if (ang <= (f32) nearDist) {
                    D_801C0840[i] = 0;
                } else {
                    D_801C0840[i] = (s32) (((ang - (f32) nearDist) * 255.0f) / (f32) (farDist - nearDist));
                    if (!D_801AEE20[0].unk98) {}
                }
                if (D_801C0840[i] >= 0x100) {
                    D_801C0840[i] = 0xFF;
                }
            } else {
                D_801C0840[i] = -1;
            }
        } else {
            D_801C0840[i] = -1;
        }
    }
    if (!*(s32*) &D_800DAB2C) {}
    padR373 = (u32) D_102CF10;

    for (i = 0, imtx = 0; i < D_801BC938; i++, imtx++) {
        padR406 = i;
        dx = D_801BB138[i].unk0 - camera->unk4C;
        dz = D_801BB138[i].unk8 - camera->unk54;
        if ((D_801BB138[i].unk10 == 4) || (D_801BB138[i].unk10 == 5)) {
            D_801C08C0[padR406] = -1;
        } else if ((ang = sqrtf(SQ(dx) + SQ(dz))) < (f32) farDist) {
            if (ang > 0.0f) {
                dx /= ang;
                dz /= ang;
            }
            if (((dx * viewX) + (dz * viewZ)) > 0.5f) {
                if (ang <= (f32) nearDist) {
                    D_801C08C0[padR406] = 0;
                } else {
                    D_801C08C0[padR406] = (s32) (((ang - (f32) nearDist) * 255.0f) / (f32) (farDist - nearDist));
                }
            } else {
                D_801C08C0[padR406] = -1;
            }
        } else {
            D_801C08C0[padR406] = -1;
        }
        if (!*(s32*) &D_801BC938) {}
    }

    for (i = 0, imtx = 0; i < D_801BFA40; i++, imtx++) {
        dx = D_801BC940[i].unk0 - camera->unk4C;
        dz = D_801BC940[i].unk8 - camera->unk54;
        ang = sqrtf(SQ(dx) + SQ(dz));
        if (ang < (f32) farDist) {
            if (ang > 0.0f) {
                dx /= ang;
                dz /= ang;
            }
            if ((((dx * viewX) + (dz * viewZ)) > 0.0f) || (D_801BC940[i].unk4C == 1U) || (D_801BC940[i].unk4C == 2U)) {
                if (ang <= (f32) nearDist) {
                    D_801C0AC0[i] = 0;
                } else {
                    D_801C0AC0[i] = (s32) (((ang - (f32) nearDist) * 255.0f) / (f32) (farDist - nearDist));
                }
            } else {
                D_801C0AC0[i] = -1;
            }
        } else {
            D_801C0AC0[i] = -1;
        }
        if (!*(s32*) &D_801BC938) {}
    }

    if (!*(s32*) &D_801BC938) {}
    gSPDisplayList(gdlh++, D_1014438);
    gSPDisplayList(gdlh++, D_102CB78);
    gDPPipeSync(gdlh++);
    if (!*(s32*) &D_2000A40) {
        if (!*(s32*) &D_101F978) {}
    }
    gDPSetTextureLUT(gdlh++, G_TT_RGBA16);

    if (!*(s32*) &D_801BC938) {}
    imtx = 0;
    for (i = 0; i < D_801BC938; i++) {
        if (D_801C08C0[i] < 0) {
            continue;
        }
        dx = camera->unk4C - D_801BB138[i].unk0;
        if (!camera) {}
        dy = camera->unk50 - D_801BB138[i].unk4;
        dz = camera->unk54 - D_801BB138[i].unk8;
        if ((dx != 0.0f) || (dz != 0.0f)) {
            ux = 1.0f;
            lim = 0.0f;
        } else {
            ux = 0.0f;
            lim = 1.0f;
        }
        SysUtils_MatrixLookAt(&D_801AE948->unkA1C0[D_800DAB2C][imtx], &mtx, dx, dy, dz, 0.0f, ux, lim,
                              D_801BB138[i].unk0, D_801BB138[i].unk4, D_801BB138[i].unk8);
        D_801C0B80[i] = imtx;
        imtx++;
        if (imtx >= 0x20) {
            break;
        }
    }

    dx = -D_801C0C80->unkAC;
    dz = -D_801C0C80->unkB4;
    ang = sqrtf(SQ(dx) + SQ(dz));
    if (ang > 0.0f) {
        dx /= ang;
        dz /= ang;
    }
    ang2 = ang = func_801ED090((viewX * dx) + (viewZ * dz));
    if (((viewX * dz) + (-(viewZ * dx))) > 0.0f) {
        ang2 = 360.0f - ang;
    }
    idx = (s32) ((ang2 / 360.0f) * 18.0f);
    if (idx < 0) {
        idx = 0;
    }
    if (idx >= 18) {
        idx = 17;
    }
    if (idx < 10) {
        dlOpa = D_102CC58;
        dlXlu = D_102CC70;
        obj = D_102CD78;
        dlRingXlu = D_102CD90;
    } else {
        idx = 18 - idx;
        dlOpa = D_102CCE8;
        dlXlu = D_102CD00;
        obj = D_102CE08;
        dlRingXlu = D_102CE20;
    }

    mtxp = &D_5000000->unkA1C0[D_800DAB2C][0];
    inext = (s32) &D_101F978[idx * 0x1000];
    gDPLoadTLUT_pal256(gdlh++, D_D4F18);
    gDPLoadTextureBlock(gdlh++, inext, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    if (!*(s32*) &D_801CB058) {}
    for (i = 0; i < D_801BC938; i++) {
        D_801C0640[i] = -1;
        if (D_801BB138[i].unk10 == 0) {
            alpha = D_801C08C0[i];
            if (alpha >= 0) {
                D_801C0640[i] = alpha;
                gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gdlh++);
                gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                gSPDisplayList(gdlh++, obj);
            }
        }
        if (!*(s32*) &D_800D5440) {}
    }

    tex2 = (u8*) (inext + 0x800);
    gDPLoadTextureBlock(gdlh++, tex2, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BC938; i++) {
        if (D_801C0640[i] < 0) {
            continue;
        }
        gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gDPPipeSync(gdlh++);
        gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0640[i]);
        gSPDisplayList(gdlh++, dlRingXlu);
        if (!*(s32*) &D_102CC70) {}
    }

    gDPLoadTLUT_pal256(gdlh++, D_D5118);
    gDPLoadTextureBlock(gdlh++, inext, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BC938; i++) {
        D_801C0640[i] = -1;
        if (D_801BB138[i].unk10 == 1) {
            alpha = D_801C08C0[i];
            if (alpha >= 0) {
                D_801C0640[i] = alpha;
                gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gdlh++);
                gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                gSPDisplayList(gdlh++, obj);
            }
        }
    }

    gDPLoadTextureBlock(gdlh++, tex2, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BC938; i++) {
        if (D_801C0640[i] >= 0) {
            gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gdlh++);
            gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0640[i]);
            if (!*(s32*) &D_801C0CD0) {}
            gSPDisplayList(gdlh++, dlRingXlu);
        }
    }

    gDPPipeSync(gdlh++);
    gDPSetTextureLUT(gdlh++, G_TT_NONE);
    gDPLoadTextureBlock(gdlh++, D_1016A38, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BC938; i++) {
        D_801C0640[i] = -1;
        if ((D_801BB138[i].unk10 == 2) || (D_801BB138[i].unk10 == 3)) {
            alpha = D_801C08C0[i];
            if (alpha >= 0) {
                D_801C0640[i] = alpha;
                gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gdlh++);
                gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                gSPDisplayList(gdlh++, D_102CF10);
            }
        }
    }

    gDPLoadTextureBlock(gdlh++, D_1017A38, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BC938; i++) {
        if (D_801C0640[i] >= 0) {
            gSPMatrix(gdlh++, &mtxp[D_801C0B80[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gdlh++);
            gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0640[i]);
            gSPDisplayList(gdlh++, D_102CF28);
        }
    }

    gDPPipeSync(gdlh++);
    gDPSetTextureLUT(gdlh++, G_TT_RGBA16);

    bwalk = D_801AEE20;
    imtx = 0;
    for (i = 0; i < D_801BB120; i++, bwalk++) {
        if (D_801C0840[i] < 0) {
            continue;
        }
        if (D_801AEE20[i].unk9C == 0) {
            dx = camera->unk4C - bwalk->unk0;
            dy = camera->unk50 - bwalk->unk4;
            dz = camera->unk54 - bwalk->unk8;
            if ((dx != 0.0f) || (dz != 0.0f)) {
                ux = 1.0f;
                lim = 0.0f;
            } else {
                ux = 0.0f;
                lim = 1.0f;
                if (!D_801AEE20[0].unkC8) {}
            }
            SysUtils_MatrixLookAt(&D_801AE948->unk95C0[D_800DAB2C][imtx], &mtx, dx, dy, dz, 0.0f, ux, lim, bwalk->unk0,
                                  bwalk->unk4, bwalk->unk8);
            dx = bwalk->unk60 - bwalk->unk0;
            dy = (bwalk->unk64 + (f32) gWaterLevel) - bwalk->unk4;
            dz = bwalk->unk68 - bwalk->unk8;
            if ((dx != 0.0f) || (dz != 0.0f)) {
                ux = 1.0f;
                lim = 0.0f;
            } else {
                ux = 0.0f;
                lim = 1.0f;
            }
            if (!D_801C0AC0[0]) {}
            if (!D_801C0AC0[0]) {}
            SysUtils_MatrixLookAt(&D_801AE948->unk9BC0[D_800DAB2C][imtx], &mtx, dx, dy, dz, 0.0f, ux, lim, bwalk->unk0,
                                  bwalk->unk4, bwalk->unk8);
        } else {
            bwalk->unk0 = 0.5f * (bwalk->unkC + bwalk->unk18);
            if (gCourseID != GLACIER_COAST) {
                bwalk->unk4 = 0.5f * (bwalk->unk10 + bwalk->unk1C);
            } else {
                bwalk->unk4 = 0.0f;
            }
            ang = (bwalk->unk14 + bwalk->unk20) * 0.5f;
            bwalk->unk8 = ang;
            SysUtils_MatrixLookAt(&D_801AE948->unk95C0[D_800DAB2C][imtx], &mtx, -bwalk->unk70, 0.0f, -bwalk->unk74,
                                  0.0f, 1.0f, 0.0f, bwalk->unk0, bwalk->unk4, ang);
        }
        D_801C0B40[i] = imtx;
        imtx++;
        if (imtx >= 0xC) {
            break;
        }
    }

    mtxp = &D_5000000->unk95C0[D_800DAB2C][0];
    gDPLoadTLUT_pal256(gdlh++, D_1029978);
    gDPLoadTextureBlock(gdlh++, inext, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BB120; i++) {
        D_801C05C0[i] = -1;
        alpha = D_801C0840[i];
        if (alpha >= 0) {
            if (D_801AEE20[i].unk98 == 0) {
                if ((D_801AEE20[i].unkC8 != 0) || (D_800D5448 != 0)) {
                    D_801C05C0[i] = alpha;
                    gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gDPPipeSync(gdlh++);
                    gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                    gSPDisplayList(gdlh++, dlOpa);
                }
            }
        }
        if (!D_801C08C0[0]) {}
    }

    gDPLoadTextureBlock(gdlh++, tex2, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BB120; i++) {
        if (D_801C05C0[i] >= 0) {
            gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gdlh++);
            gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C05C0[i]);
            gSPDisplayList(gdlh++, dlXlu);
        }
    }

    gDPLoadTLUT_pal256(gdlh++, D_D4B18);
    gDPLoadTextureBlock(gdlh++, inext, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    for (i = 0; i < D_801BB120; i++) {
        alpha = D_801C0840[i];
        D_801C05C0[i] = -1;
        if (!*(s32*) &gGameModes) {}
        if (alpha >= 0) {
            if (D_801AEE20[i].unk98 == 1) {
                if ((D_801AEE20[i].unkC8 != 0) || (D_800D5448 != 0)) {
                    D_801C05C0[i] = alpha;
                    gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gDPPipeSync(gdlh++);
                    gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                    gSPDisplayList(gdlh++, dlOpa);
                }
            }
        }
    }

    gDPLoadTextureBlock(gdlh++, tex2, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
    if (!*(s32*) &D_801C0CD0) {}
    for (i = 0; i < D_801BB120; i++) {
        if (D_801C05C0[i] >= 0) {
            gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPPipeSync(gdlh++);
            gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C05C0[i]);
            if (!D_801C0AC0[0]) {
                if (!*(s32*) &D_801C0AC0) {}
            }
            gSPDisplayList(gdlh++, dlXlu);
        }
    }

    if (D_800D5448 != 0) {
        if (!D_800D48DC) {}
        gDPLoadTLUT_pal256(gdlh++, D_D4D18);
        gDPLoadTextureBlock(gdlh++, inext, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
        for (i = 0; i < D_801BB120; i++) {
            alpha = D_801C0840[i];
            D_801C05C0[i] = -1;
            if ((alpha >= 0) &&
                ((D_801AEE20[i].unk98 == 4) || (D_801AEE20[i].unk98 == 6) || (D_801AEE20[i].unk98 == 0xA))) {
                D_801C05C0[i] = alpha;
                gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gdlh++);
                gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, alpha);
                gSPDisplayList(gdlh++, dlOpa);
            }
        }

        gDPLoadTextureBlock(gdlh++, tex2, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_CLAMP, G_TX_CLAMP, 0, 0, 0, 0);
        for (i = 0; i < D_801BB120; i++) {
            if (D_801C05C0[i] >= 0) {
                gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                gDPPipeSync(gdlh++);
                gDPSetEnvColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C05C0[i]);
                gSPDisplayList(gdlh++, dlXlu);
            }
        }
    }

    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_FOG | G_LIGHTING);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gSPSetLights0(gdlh++, D_6000000->unk35D8[D_800DAB2C]);
    gSPFogFactor(gdlh++, 0x1F400 / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78),
                 (((0x1F4 - (s32) D_801C0C80->unk78) * 256) / ((s32) D_801C0C80->unk7C - (s32) D_801C0C80->unk78)));
    gDPPipeSync(gdlh++);
    gDPSetTextureLUT(gdlh++, G_TT_NONE);
    gDPSetCycleType(gdlh++, G_CYC_2CYCLE);
    gDPSetTexturePersp(gdlh++, G_TP_PERSP);
    gDPSetTextureFilter(gdlh++, G_TF_BILERP);
    gDPSetCombine(gdlh++, 0x127FFF, 0xFFFFF238);
    gDPSetRenderMode(gdlh++, 0, 0xC8112078);
    gDPSetFogColor(gdlh++, D_801C0C80->unk48, D_801C0C80->unk4C, D_801C0C80->unk50, D_801C0C80->unk54);
    gDPSetAlphaCompare(gdlh++, G_AC_NONE);

    if (gCourseID != RIDER_SELECTION) {
        mtxp = &D_5000000->unk95C0[D_800DAB2C][0];
        for (i = 0; i < D_801BB120; i++) {
            alpha = D_801C0840[i];
            if (alpha < 0) {
                continue;
            }
            if (D_801AEE20[i].unk9C == 1) {
                gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                if ((D_801AEE20[i].unk98 == 3) || (D_801AEE20[i].unk98 == 5)) {
                    if ((gCourseID == DOLPHIN_PARK) && (gGameModes != GMODE_STUNT)) {
                        gSPDisplayList(gdlh++, D_D02B640);
                    } else if (gCourseID == SUNSET_BAY) {
                        gSPDisplayList(gdlh++, D_8029FDC8);
                        gDPPipeSync(gdlh++);
                        gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                        gSPDisplayList(gdlh++, D_8029FAD0);
                    } else if (gCourseID == GLACIER_COAST) {
                        gSPDisplayList(gdlh++, D_8029FF58);
                        gDPPipeSync(gdlh++);
                        gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                        gSPDisplayList(gdlh++, D_8029FC50);
                    } else {
                        gSPDisplayList(gdlh++, D_8029FCD8);
                        gDPPipeSync(gdlh++);
                        gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                        gSPDisplayList(gdlh++, D_8029FA70);
                    }
                } else {
                    gSPDisplayList(gdlh++, D_1018D58);
                    gDPPipeSync(gdlh++);
                    gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                    gSPDisplayList(gdlh++, D_1018AA8);
                }
                if (!D_801BB120) {}
            }
        }
    }

    if (gPlayers == ONE_PLAYER) {
        mtxp = &D_5000000->unk9BC0[D_800DAB2C][0];
        gSPSetGeometryMode(gdlh++, G_CULL_BACK);
        gDPPipeSync(gdlh++);
        gDPSetCombine(gdlh++, 0x127FFF, 0xFFFFF238);
        if (!D_801C0B40[0]) {
            if (!*(s32*) &gWaterLevel) {}
        }
        for (i = 0; i < D_801BB120; i++) {
            if (D_801C0840[i] < 0) {
                continue;
            }
            if (D_801AEE20[i].unk9C == 0) {
                if (D_801AEE20[i].unkC8 != 0) {
                    gDPPipeSync(gdlh++);
                    gDPSetRenderMode(gdlh++, 0, 0xC8112078);
                    gSPMatrix(gdlh++, &mtxp[D_801C0B40[i]], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    if (D_801AEE20[i].unk98 == 0) {
                        gSPDisplayList(gdlh++, D_102AE38);
                        gDPPipeSync(gdlh++);
                        gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                        gSPDisplayList(gdlh++, D_102AD90);
                    } else {
                        gSPDisplayList(gdlh++, D_1029C88);
                        gDPPipeSync(gdlh++);
                        gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                        gSPDisplayList(gdlh++, D_1029BE0);
                        if (!*(s32*) &D_800DAB2C) {}
                    };
                }
                if (!*(s32*) &D_8029FF58) {}
            }
        }
    }
    if (!mtxp) {}

    gDPPipeSync(gdlh++);
    gDPSetCombine(gdlh++, 0x127FFF, 0xFFFFF238);
    if (!*(s32*) &D_1014438) {}
    for (i = 0; i < D_801BFA40; i++) {
        if (D_801C0AC0[i] < 0) {
            continue;
        }
        obj = &D_801BC940[i];
        if (obj->unk54 == 1) {
            if (obj->unk58 != 0) {
                _MtxF_to_Mtx(&obj->unk74, &D_801AE948->unk4140[D_801AE950]);
                gSPMatrix(gdlh++, &D_5000000->unk4140[D_801AE950++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            } else {
                gSPMatrix(gdlh++, &D_801C0CD0[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            }
            gSPSetGeometryMode(gdlh++, G_CULL_BACK);
            if (obj->unkB4 != 0) {
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, 0, 0xC8112078);
                gSPDisplayList(gdlh++, obj->unkB4);
            }
            gSPClearGeometryMode(gdlh++, G_CULL_BACK);
            if (obj->unkB8 != 0) {
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                gSPDisplayList(gdlh++, obj->unkB8);
            }
        }
    }

    if (gCourseID == TWILIGHT_CITY) {
        padR404 = SegmentedToVirtual((u32) D_E00F478) + (D_801C0CBC << 6);
        gSPSegment(gdlh++, 9, padR404);
        padR404 = SegmentedToVirtual((u32) D_E011480) + (D_801C0CBC << 6);
        gSPSegment(gdlh++, 10, padR404);
        padR404 = SegmentedToVirtual((u32) D_E013488) + (D_801C0CC0 << 12);
        gSPSegment(gdlh++, 11, padR404);
    }

    gSPClearGeometryMode(gdlh++, G_ZBUFFER | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR);
    gSPSetGeometryMode(gdlh++, G_ZBUFFER | G_SHADE | G_SHADING_SMOOTH | G_CULL_BACK | G_FOG | G_LIGHTING);
    gSPTexture(gdlh++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPPipeSync(gdlh++);
    gDPSetCombine(gdlh++, 0x127FFF, 0xFFFFF238);
    gDPSetRenderMode(gdlh++, 0, 0xC8112078);
    gSPMatrix(gdlh++, D_2000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    if (D_800D5440 != 0) {
        if (D_801CE638 == 0x15) {
            gDPSetRenderMode(gdlh++, 0, 0x0C192078);
            gSPDisplayList(gdlh++, D_801C1CD0);
            gSPClearGeometryMode(gdlh++, G_CULL_BACK);
            gDPPipeSync(gdlh++);
            gDPSetRenderMode(gdlh++, 0, 0x0C193078);
            gSPDisplayList(gdlh++, D_801C1CD4);
        } else {
            if (D_801C1CD0 != NULL) {
                gSPDisplayList(gdlh++, D_801C1CD0);
            }
            if (gCourseID == PORT_BLUE) {
                if ((gGameModes == GMODE_STUNT) || (gDifficulty == DIFFICULTY_NORMAL)) {
                    gSPDisplayList(gdlh++, D_E010ED0);
                } else if (gDifficulty == DIFFICULTY_EXPERT) {
                    gSPDisplayList(gdlh++, D_E010DF0);
                }
            }
            if (D_801C1CD4 != NULL) {
                gSPClearGeometryMode(gdlh++, G_CULL_BACK);
                gDPPipeSync(gdlh++);
                gDPSetRenderMode(gdlh++, 0, 0xC8113078);
                gSPDisplayList(gdlh++, D_801C1CD4);
            }
        }
        if (gCourseID != PORT_BLUE) {
            gSPSetGeometryMode(gdlh++, G_CULL_BACK);
            if (!*(s32*) &D_E010DF0) {}
        }
        gSPClearGeometryMode(gdlh++, G_LIGHTING);
        if (D_801C1CD8 != NULL) {
            gDPPipeSync(gdlh++);
            gDPSetRenderMode(gdlh++, 0, 0xC8112078);
            gSPDisplayList(gdlh++, D_801C1CD8);
        }
        if (D_801C1CDC != NULL) {
            gSPClearGeometryMode(gdlh++, G_CULL_BACK);
            gDPPipeSync(gdlh++);
            gDPSetRenderMode(gdlh++, 0, 0xC8113078);
            gSPDisplayList(gdlh++, D_801C1CDC);
        }
        gSPSetGeometryMode(gdlh++, G_CULL_BACK);
        gSPClearGeometryMode(gdlh++, G_FOG);
        gDPPipeSync(gdlh++);
        gDPSetCycleType(gdlh++, G_CYC_1CYCLE);
        if (D_801C1CE0 != NULL) {
            gDPSetRenderMode(gdlh++, 0, 0x00442078);
            gSPDisplayList(gdlh++, D_801C1CE0);
            if (!*(s32*) &D_E00F478) {}
        }
        if (D_801C1CE4 != NULL) {
            gSPClearGeometryMode(gdlh++, G_CULL_BACK);
            gDPPipeSync(gdlh++);
            gDPSetRenderMode(gdlh++, 0, 0x004049D8);
            gSPDisplayList(gdlh++, D_801C1CE4);
        }
        if (!D_801C0AC0[0]) {}
    }

    if ((gPlayers == ONE_PLAYER) && (gCourseID == TWILIGHT_CITY)) {
        func_8006CB98(&gdlh);
        func_8006CDE8(&gdlh);
    }
    func_8006D034(&gdlh);
    if (!*(s32*) &D_801C0CBC) {}
    Spray_Draw(&gdlh);
    if (gGameModes == GMODE_STUNT) {
        func_8006D494(&gdlh);
    }
    if (D_800D5450 != 0) {
        func_8006E01C((s32) &gdlh);
    }
    *gdl = gdlh;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_24B00/func_8006E674.s")
#endif
