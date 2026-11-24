#include "common.h"

typedef struct BuoyPathHeader {
    /* 0x00 */ s16 count;
    /* 0x04 */ u32 points;   /* segmented -> BuoyPoint[] */
    /* 0x08 */ u32 paths[8]; /* segmented -> s16[] point indices */
} BuoyPathHeader;

typedef struct BuoyPoint {
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 z;
    /* 0x6 */ s8 unk6[6];
} BuoyPoint; /* size = 0xC */

extern s32 D_i5_802C7AA0;
extern s32 D_i5_802C7AC8;
extern s32 D_i5_802C7ACC;
extern s32 D_i5_802C7AD0;
extern f32 D_802C7B10[8];
extern s32 D_802C7B30;
extern s32 D_802C7B34;
extern BuoyPathHeader* D_802C7B38[2];
extern s16* D_802C7B40[2][8];
extern BuoyPoint* D_802C7B80[2];
extern s32 D_802C7B88;
extern s32 D_802C7B8C;
extern s32 D_802C7B90;
extern s32 D_801CB334;
extern s32 D_801CB340[];
extern const s16 D_800EABBC[][8];
extern s16 D_800EAC14[][8];
extern s32 D_801C2660[];
extern s32 D_801C2690[];
extern u8 D_80B0E28[];
extern u8 D_80B1550[];

void func_801EC830(void);
void func_8004EFB4(f32, f32, s32);
void func_801E4C60(Mtx*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);

/* Loads the two buoy path sets (8 paths each) once per race, then places the
 * 8 buoys of the active set at the current path step and calls func_8004EFB4
 * the first time each one surfaces.
 * Load-bearing for the match: the chained clear `D_802C7B8C = D_802C7B90 = 0`
 * (its extra temp rotates ugen's FIFO register queue), the 2D D_800EAC14 index,
 * the outer loop on `j` with the inner loop reusing `i`, `path += j` with `j`
 * reused for D_i5_802C7AA0, `!D_802C7B10[i]` (fresh zero), the switch for
 * `sel`, the while-form clear loop, and the unused hdr/paths/fp locals (frame). */
void func_i5_802C7090(void) {
    f32 z;
    s32 i;
    BuoyPoint* pt;
    BuoyPathHeader** hdr;
    s32 j;
    f32 x;
    s16** paths;
    f32* fp;
    f32 y;
    s32 sel;
    s16 idx;
    s32 k;
    s16* path;
    if (D_801CE63C != 0 && gGameState == GAME_STATE_5A) {
        D_802C7B30 = D_801CB340[D_800D48DC];
        D_802C7B34 = D_800EABBC[gDifficulty][D_801CB334];
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                D_802C7B38[j] = (BuoyPathHeader*) SegmentedToVirtual((u32) D_80B0E28);
            } else {
                D_802C7B38[j] = (BuoyPathHeader*) SegmentedToVirtual((u32) D_80B1550);
            }
            for (i = 0; i < 8; i++) {
                D_802C7B40[j][i] = (s16*) SegmentedToVirtual(D_802C7B38[j]->paths[i]);
            }
            D_802C7B80[j] = (BuoyPoint*) SegmentedToVirtual(D_802C7B38[j]->points);
        }
        D_802C7B8C = D_802C7B90 = 0;
        for (i = 0; i < D_801CB334 + 1; i++) {
            k = D_800EAC14[gDifficulty][i];
            if (D_801C2660[k]) {
                D_802C7B8C = 1;
            }
            if (D_801C2690[k]) {
                D_802C7B90 = 1;
            }
        }
        i = 0;
        while (i < 8) {
            D_802C7B10[i] = 0.0f;
            i++;
        }
    }

    switch (D_i5_802C7AC8) {
        case 2:
        case 3:
            sel = 0;
            break;
        default:
            sel = 1;
            break;
    }
    for (i = 0; i < 8; i++) {
        j = D_i5_802C7AA0;
        path = D_802C7B40[sel][i];
        pt = D_802C7B80[sel];
        path += j;
        idx = *path;
        pt += idx;
        x = pt->x / 10.0f;
        y = pt->y / 10.0f;
        z = pt->z / 10.0f;
        if (y >= 0.0f && !D_802C7B10[i] && D_i5_802C7AA0 > 0) {
            D_802C7B10[i] = 1.0f;
            func_8004EFB4(x, z, 0x32);
        }
        func_801E4C60(&D_801CE5F8->unk1380[i], pt->unk6[0], pt->unk6[1], pt->unk6[2], pt->unk6[3], pt->unk6[4],
                      pt->unk6[5], x, y, z, 0.05f);
    }
}

Gfx* func_i5_802C7594(Gfx*);
Gfx* func_i5_802C7698(Gfx*);
void func_i5_802C781C(void);
Gfx* Gfx_DrawCoursePanel(Gfx*, s32);
Gfx* func_801EB00C(Gfx*, s32, s32, s32, s32);
extern Mtx D_8011F820;

Gfx* func_i5_802C7484(Gfx* glistp) {
    /* Port Blue race frame: clears the buffer, fills the course color, draws
     * buoys when the tide state calls for them, then appends the course
     * panel, water effects, and results panels before the attract tail. */
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }

    glistp = Gfx_ClearCurrentBuffer(glistp);

    D_800DAB2C = 0;

    glistp = Gfx_FillCourseColor(glistp, gCourseID);
    glistp = func_8008FB74(glistp);

    if (D_i5_802C7AC8 == 2 || D_i5_802C7AC8 == 3 || D_i5_802C7AC8 == 4) {
        glistp = func_i5_802C7594(glistp);
    }

    gSPMatrix(glistp++, &D_8011F820, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    glistp = Gfx_DrawCoursePanel(glistp, gCourseID);
    glistp = Draw_WaterEffects(glistp);
    glistp = func_i5_802C7698(glistp);

    if (gGameState == GAME_STATE_5A) {
        func_i5_802C781C();
    } else if (D_80228A16 == 1) {
        func_801EB180();
    }

    return glistp;
}

extern u32 D_106F6C0;
extern u32 D_i5_802C7AA8[];
extern u32 D_7001380;
extern u32 D_70013C0;
extern u32 D_7001400;
extern u32 D_7001440;
extern u32 D_7001640;

Gfx* func_i5_802C7594(Gfx* arg0) {
    Gfx* v0;
    Gfx* v1;
    u32 var_a1;
    u32* src;
    u32 var_a3;
    u32 var_t0;
    u8* var_t1;
    u8* var_t4;

    /* clang-format off */
    v0 = arg0++; v0->words.w0 = 0x06000000; v0->words.w1 = (u32)&D_106F6C0; v1 = 0;
    var_a1 = (u32) &D_7001380; src = D_i5_802C7AA8; var_a3 = (u32) &D_70013C0; var_t0 = (u32) &D_7001400; var_t1 = (u8*) &D_7001440; var_t4 = (u8*) &D_7001640; loop:
    /* clang-format on */
    v0 = arg0++;
    v0->words.w0 = 0x01020040;
    v0->words.w1 = var_a1;
    v1 = arg0++;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[0];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = var_a3;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[1];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = var_t0;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[2];

    v0 = arg0++;
    v1 = arg0++;
    v0->words.w1 = (u32) var_t1;
    v0->words.w0 = 0x01020040;
    v1->words.w0 = 0x06000000;
    v1->words.w1 = src[3];

    var_t1 += 0x100;
    var_t0 += 0x100;
    var_a3 += 0x100;
    var_a1 += 0x100;
    src += 4;
    if (var_t1 != var_t4) {
        goto loop;
    }
    return arg0;
}

Gfx* func_i5_802C7698(Gfx* glistp) {
    /* Draws the two Port Blue leaderboard panels: frames, full-bright text
     * rows, position numbers, and the two course-record lines. */
    gSPDisplayList(glistp++, D_106F628);
    glistp = Menu_DrawFrame(glistp, 0, D_i5_802C7ACC, 0x91, 0xD0, 0xF);
    glistp = Menu_DrawFrame(glistp, 0, D_i5_802C7AD0, 0xA6, 0xD0, 0xF);
    glistp = func_801E946C(glistp, 0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    glistp = func_801E3EE0(glistp, 1, 6, D_i5_802C7ACC + 10, 0x93, 0);
    glistp = func_801E3EE0(glistp, 1, 7, D_i5_802C7AD0 + 10, 0xA8, 0);
    glistp = func_801EB00C(glistp, 2, D_802C7B34, D_i5_802C7ACC + 0xBA, 0x93);
    return func_801EB00C(glistp, 2, D_802C7B30, D_i5_802C7AD0 + 0xBA, 0xA8);
}

void func_i5_802C781C(void) {
    s32 var_a0;

    switch (D_i5_802C7AC8) {
        case 0:
            D_i5_802C7ACC -= 0x1E;
            if (D_i5_802C7ACC < 0x38) {
                D_i5_802C7AC8 = 1;
                D_i5_802C7ACC = 0x38;
            }
            break;
        case 1:
            D_i5_802C7AC8 = 2;
            break;
        case 2:
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == D_802C7B38[0]->count) {
                D_i5_802C7AA0--;
                D_i5_802C7AC8 = 3;
            }
            break;
        case 3:
            if (D_801CE65A[0].unk0 & 0xB000) {
                D_i5_802C7AC8 = 4;
                D_i5_802C7AA0 = 0;
                D_802C7B88 = 0;
            }
            break;
        case 4:
            var_a0 = 0;
            D_i5_802C7ACC -= 0x1E;
            if (D_i5_802C7ACC < -0xD0) {
                var_a0 = 1;
                D_i5_802C7ACC = -0xD0;
            }
            D_i5_802C7AA0++;
            if (D_i5_802C7AA0 == D_802C7B38[1]->count) {
                var_a0++;
                D_i5_802C7AA0--;
            }
            if (var_a0 == 2) {
                D_802C7B88++;
            }
            if (D_802C7B88 >= 4) {
                if (D_802C7B8C != 0 || D_802C7B90 != 0) {
                    func_801EC9C8();
                } else {
                    func_801EC830();
                }
            }
            break;
    }
    D_i5_802C7AD0 = 0x70 - D_i5_802C7ACC;
}

void func_i5_802C79F4(void) {
}

#ifdef NON_MATCHING
s32 D_i5_802C7AA0 = 0;
s32 D_i5_802C7AA4 = 0;
u32 D_i5_802C7AA8[8] = {
    0x0808EB68, 0x08091C40, 0x080924E0, 0x0808F878, 0x08092D80, 0x080940A0, 0x0808FE58, 0x08091C40
};
s32 D_i5_802C7AC8 = 0;
s32 D_i5_802C7ACC = 0;
s32 D_i5_802C7AD0 = 0;
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA0.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AA8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AC8.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7ACC.s")

#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i5/ovl_1C17E0/D_i5_802C7AD0.s")
#endif
