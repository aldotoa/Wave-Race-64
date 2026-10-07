#include "common.h"

void func_801EC830(s32*);

extern u32 D_802288F0;
extern s32 D_802288F4;
extern s32 D_802288F8;
extern s32 D_802288FC;
extern f32 D_80226334;
extern Vp D_80226340;
extern u16 D_80228900;
extern UnkStruct_801CE5F8* D_801CE5F8;

f32 func_801E31A0(void) {
    int temp;
    f32 var_f2;
    s32 var_v0;
    var_v0 = gControllerOne[D_80154330[0]].unk_8;

    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    temp = 0x3A;
    if (var_v0 >= 0x47) {
        var_v0 = 0x46;
    } else if (var_v0 < 0xC) {
        var_v0 = 0xC;
    }

    var_v0 -= 0xC;
    var_f2 = (2.0f * var_v0) / temp;
    if (var_f2 > 2.0f) {
        var_f2 = 2.0f;
    }
    if (var_f2 < D_80226334) {
        var_f2 = D_80226334;
    }
    return var_f2;
}

void func_801E3250(void) {
    s32 i;
    s32 var_s0;
    MtxF sp170;
    MtxF sp130;
    MtxF spF0;
    Mtx spB0;
    Mtx sp70;

    if (D_801CE63C != 0) {
        D_802288F4 = 0;
        D_802288F0 = 0;
        D_802288F8 = 0x140;
        D_802288FC = -0x108;
    }
    func_800481E0(D_801CE5F8->unkA40, &D_80228900, 33.0f, 1.0f, 16.0f, 4096.0f, 0.0f, 0.0f);
    func_80048A88(&spB0, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.025f);
    func_800484C8(&sp70, &sp130, 500.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    SysUtils_MtxToMtxF(&spB0, &sp170);
    SysUtils_MatrixAffineMultiply(&sp130, &sp170, &spF0);

    for (i = 0; i < 3; i++) {
        if (i & 1) {
            var_s0 = D_802288FC;
        } else {
            var_s0 = D_802288F8;
        }
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_80226340;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = ((var_s0 + 0x38) << 2);
        D_801CE5F8->unk1280[i].vp.vtrans[1] = ((i + 7) * 0x12 - 4) << 2;
    }

    if (D_801C2928 == 0) {
        SysUtils_MtxFToMtx(&spF0, &D_801CE5F8->unkA80[i]);
        D_801CE5F8->unk1280[i] = D_80226340;
        D_801CE5F8->unk1280[i].vp.vtrans[0] = ((D_802288FC + 0x38) << 2);
        D_801CE5F8->unk1280[i].vp.vtrans[1] = 0x338;
    }
}

Gfx* func_801E34F8(Gfx* gdl) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    gdl = func_801E3698(Draw_WaterEffects(Gfx_FillCourseColor(func_8008FB74(gdl), gCourseID)));
    func_801E355C();
    return gdl;
}

void func_801E355C(void) {
    s32 var_a1;

    var_a1 = false;
    switch (D_802288F0) {
        case 0:
            var_a1 = true;
            D_802288F0 = 1;
            break;
        case 1:
            D_802288F8 = D_802288F8 - 0x14;
            if (D_802288F8 < 0x14) {
                D_802288F0 = 2;
                D_802288F8 = 0x14;
            }
            break;
        case 2:
            if (D_801CE65A->unk0 & 0xB000) {
                D_802288F0 = 3;
                var_a1 = true;
            }
            break;
        case 3:
            D_802288F8 = D_802288F8 - 0x14;
            if (D_802288F8 < -0x108) {
                D_802288F8 = -0x108;
                D_802288F0 = 4;
                D_802288F4 = 0;
            }
            break;
        case 4:
            D_802288F4 = D_802288F4 + 1;
            if (D_802288F4 >= 3) {
                func_801EC830(&D_802288F4);
                var_a1 = false;
            }
            break;
    }
    if (var_a1) {
        AudioGeneral_PlaySound(0x31, 0);
    }
    D_802288FC = 0x28 - D_802288F8;
}

typedef struct {
    /* 0x0 */ s32 time;
    /* 0x4 */ s32 unk4;
    /* 0x8 */ s32 unk8;
    /* 0xC */ char name[4];
} RecordEntry_801C26E8; // size = 0x10

extern s32 D_801C2928;
extern Mtx D_7000A40[];
extern Mtx D_7000A80[];
extern Vp D_7001280[];
extern Gfx D_106F488[];
extern RecordEntry_801C26E8 D_801C26E8[][3];
extern s8 D_80226E44[];
extern s32 D_80226350[];

Gfx* Menu_DrawFrame(Gfx* glistp, s32 arg1, s32 x, s32 y, s32 w, s32 h);
Gfx* func_801E7E74(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);
Gfx* func_801E7FD8(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);
Gfx* func_801E4FE8(Gfx* glistp, s32 a1, s32 a2, s32 a3, Vtx* vtx);
Gfx* func_801E9858(Gfx*, s32, char*, s32, s32);

Gfx* func_801E3698(Gfx* glistp) {
    /* Course records screen: frames, per-row viewport renders, then the three
       record rows. Load-bearing: entry assigned first in the viewport loop
       (puts it in s2 and fixes glistp in s3); char buf[4] placed after
       color gives the 0xB8 frame. */
    s32 i;
    s32 y;
    s32 x;
    s32 color;
    char buf[4];
    RecordEntry_801C26E8* entry;

    gSPDisplayList(glistp++, D_106F628);

    glistp = Menu_DrawFrame(glistp, 0, D_802288F8 + 8, 0x1E, 0x108, 0x18);
    glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 0x58, 0x108, 0x10);

    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        glistp = Menu_DrawFrame(glistp, 0, x + 8, i * 0x12 + 0x6E, 0x108, 0x10);
    }

    if (D_801C2928 == 0) {
        glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 0xB7, 0x108, 0xA);
        glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 0xC2, 0x108, 0x10);
    }

    glistp = func_801E7E74(glistp, 0, 0, 0, 0xFF);

    for (i = 0; i < 3; i++) {
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        glistp = func_801E7FD8(glistp, x + 0x28, i * 0x12 + 0x70, x + 0x42, i * 0x12 + 0x7C);
    }

    if (D_801C2928 == 0) {
        glistp = func_801E7FD8(glistp, D_802288FC + 0x28, 0xC4, D_802288FC + 0x42, 0xD0);
    }

    gDPPipeSync(glistp++);
    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 8, 20, 310, 218);
    gSPPerspNormalize(glistp++, D_80228900);
    gSPMatrix(glistp++, D_7000A40, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    gSPDisplayList(glistp++, D_106F488);

    for (i = 0; i < 3; i++) {
        entry = &D_801C26E8[gCourseID][i];
        gSPViewport(glistp++, &D_7001280[i]);
        gSPMatrix(glistp++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        glistp = func_801E4FE8(glistp, entry->unk4, 0, 0, D_801CE5F8->unkC80[i]);
    }

    if (D_801C2928 == 0) {
        gSPViewport(glistp++, &D_7001280[i]);
        gSPMatrix(glistp++, &D_7000A80[i], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        glistp = func_801E4FE8(glistp, D_800DA9B0[D_800D48DC], 0, 0, D_801CE5F8->unkC80[i]);
    }

    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 2, D_800DAA34[gCourseID], D_80226350[gCourseID] + D_802288F8 + 0x38, 0x21, 0);
    glistp = func_801E3EE0(glistp, 1, 0x1F, D_802288FC + 0x17, 0x5B, 0);
    glistp = func_801E3EE0(glistp, 1, 0x20, D_802288FC + 0x77, 0x5B, 0);
    glistp = func_801E3EE0(glistp, 1, 0x3E, D_802288FC + 0xDA, 0x5B, 0);
    if (D_801C2928 == 0) {
        glistp = func_801E3EE0(glistp, 0, 0x1A, D_802288FC + 0x12, 0xB8, 0);
    }

    for (i = 0; i < 3; i++) {
        if (D_801C2928 != 0) {
            if (D_801C2928 == 1) {
                if (i + 1 == D_801C2928) {
                    color = 4;
                } else {
                    color = 0;
                }
            } else if (i + 1 == D_801C2928) {
                color = 6;
            } else {
                color = 0;
            }
        } else {
            color = 0;
        }
        glistp = func_801E946C(glistp, color, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        entry = &D_801C26E8[gCourseID][i];
        if (i & 1) {
            x = D_802288FC;
        } else {
            x = D_802288F8;
        }
        y = i * 0x12 + 0x70;
        sprintf(buf, "%1d", i + 1);
        glistp = func_801E9858(glistp, 2, buf, D_80226E44[i + 1] + x + 0x11, y);
        if (entry->unk8 == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        glistp = func_801E9858(glistp, 1, buf, x + 0x3B, y);
        glistp = func_801E9858(glistp, 2, entry->name, x + 0x77, y);
        glistp = Font_DrawDecimal(glistp, 2, entry->time, x + 0xD0, y);
    }

    if (D_801C2928 == 0) {
        glistp = func_801E946C(glistp, 6, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        if (D_801CB32C == 0) {
            sprintf(buf, "%s", "N");
        } else {
            sprintf(buf, "%s", "C");
        }
        glistp = func_801E9858(glistp, 1, buf, D_802288FC + 0x3B, 0xC4);
        glistp = Font_DrawDecimal(glistp, 2, D_801C26D0, D_802288FC + 0xD0, 0xC4);
    }
    return glistp;
}
