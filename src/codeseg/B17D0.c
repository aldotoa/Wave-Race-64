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

extern s32 D_801C2928;
extern Gfx D_7000A40[];
extern Gfx D_7000A80[];

Gfx* Menu_DrawFrame(Gfx* glistp, s32 arg1, s32 x, s32 y, s32 w, s32 h);
Gfx* func_801E7E74(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);
Gfx* func_801E7FD8(Gfx* glistp, s32 a1, s32 a2, s32 a3, s32 a4);

#ifdef NON_MATCHING
Gfx* func_801E3698(Gfx* glistp) {
    s32 i;
    s32 y;
    s32 s0;

    gSPDisplayList(glistp++, D_106F628);

    glistp = Menu_DrawFrame(glistp, 0, D_802288F8 + 8, 30, 264, 24);
    glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 88, 264, 16);

    y = 0x6E;
    for (i = 0; i < 3; i++, y += 0x12) {
        if (i & 1) {
            s0 = D_802288FC;
        } else {
            s0 = D_802288F8;
        }
        glistp = Menu_DrawFrame(glistp, 0, s0 + 8, y, 264, 16);
    }

    if (D_801C2928 == 0) {
        glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 0xB7, 264, 10);
        glistp = Menu_DrawFrame(glistp, 0, D_802288FC + 8, 0xC2, 264, 16);
    }

    glistp = func_801E7E74(glistp, 0, 0, 0, 255);

    y = 0x7C;
    s0 = 0x70;
    for (i = 0; i < 3; i++, s0 += 0x12, y += 0x12) {
        s32 base = (i & 1) ? D_802288FC : D_802288F8;
        glistp = func_801E7FD8(glistp, base + 0x28, s0, base + 0x42, y);
    }

    if (D_801C2928 != 0) {
        glistp = func_801E7FD8(glistp, D_802288FC + 0x28, 0xC4, D_802288FC + 0x42, 0xD0);
    }

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_2CYCLE);
    gDPSetPrimColor(glistp++, 0, 0, (D_80228900 >> 11) & 0x1F, (D_80228900 >> 6) & 0x1F, (D_80228900 >> 1) & 0x1F, 255);
    gSPDisplayList(glistp++, D_7000A40);
    gSPDisplayList(glistp++, D_7000A80);

    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B17D0/func_801E3698.s")
#endif
