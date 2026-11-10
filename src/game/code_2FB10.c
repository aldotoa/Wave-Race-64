#include "common.h"

extern s32 D_800D48E0;

extern UnkStruct_801AEE20 D_801AEE20[];
extern s32 D_801BB120;
extern RiderStruct D_801C2938[];

static const char devstr1[] = "dolphin condition full at goal\n";
static const char devstr2[] = "dolphin condition full\n";
static const char devstr3[] = "rank value adjust\n";
static const char devstr4[] = "simultaneously goal !!\n";

#ifdef NON_MATCHING
void func_80075310(void) {
    /* Rider lean angle calculation relative to velocity vector and turning radius */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80075310.s")
#endif

s32 func_80076240(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;

    func_80074368(arg0, arg1, &sp24, &sp20);
    func_80074368(arg2, arg3, &sp1C, &sp18);
    if ((sp24 != -1) && ((sp24 == sp1C) || (sp24 == sp18))) {
        return 1;
    }
    if ((sp20 != -1) && ((sp20 == sp1C) || (sp20 == sp18))) {
        return 1;
    }
    return 0;
}

void func_800762D0(struct_800762D0* arg0) {
    if (D_801CE638 == 1) {
        if ((gGameModes == GMODE_STUNT) && (arg0->unk2C4 <= 0)) {
            arg0->unk2EC = 2;
        } else if (arg0->unk19C >= 599999) {
            arg0->unk2EC = 2;
        } else {
            arg0->unk2EC = 1;
        }
        if ((gGameModes != GMODE_2P_VS) || (arg0->unk2EC != 2)) {
            arg0->unk32C = D_801C39B4;
            D_801C39B4 += 10000.0f;
        }
    }
}

#ifdef NON_MATCHING
void func_80076378(s32 arg0) {
    /* Jet ski throttle response and water drag velocity damping */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80076378.s")
#endif

#ifdef NON_MATCHING
void func_8007687C(s32 arg0) {
    /* Race position evaluation and checkpoint milestone update */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_8007687C.s")
#endif

#ifdef NON_MATCHING
/* draft: probe score 128 (2026-11-09) */
extern s32 D_801C1FD4;
extern s32 D_801C26C0[];

void func_80077F5C(void) {
    RiderStruct *a0;
    RiderStruct *a3;
    UnkStruct_801AEE20 *v0;
    UnkStruct_801AEE20 *seg;
    UnkStruct_80192690 *t0;
    s32 i;
    s32 j;
    s32 a2;
    s32 a3n;
    s32 tmp;
    s32 tmp2;
    s32 *dst;
    s32 *end;
    f32 fv0;
    f32 fv1;
    s32 *lim;

    if (D_801C1FD4 == 0) {
        D_801C1FD4 = 1;
        i = 0;
        lim = D_801CE728;
        a0 = D_801C2938;
        if (lim == 0) {}
        if (gRiders > 0) {
            do {
                if ((a0->unk2F4 == 0) && (a0->unk2EC == 0)) {
                    v0 = &D_801AEE20[a0->unkC];
                    seg = &D_801AEE20[v0->unkA8];
                    t0 = &D_80192690[i];
                    fv0 = (seg->unk74 * (t0->unk44.z - seg->unk8)) + ((t0->unk44.x - seg->unk0) * seg->unk70);
                    if (fv0 < 0.0f) {
                        fv0 = 0.0f;
                    }
                    fv0 = 1.0f - (fv0 / seg->unk88);
                    if (fv0 < 0.0f) {
                        fv0 = 0.0f;
                    }
                    fv0 = fv0 * 20.0f;
                    fv1 = 80.0f - ((f32) a0->racePosition * 5.0f);
                    a3n = v0->unk98;
                    a2 = a0->lapCount;
                    if ((a3n != 3) || (a2 < *lim)) {
                        do {
                            if (a3n == 3) {
                                a2 += 1;
                            }
                            fv0 += v0->unk88;
                            v0 = &D_801AEE20[v0->unkA0];
                            a3n = v0->unk98;
                        } while ((a3n != 3) || (a2 < *lim));
                    }
                    a0->unk19C = (s32) ((f32) a0->unk19C + ((fv0 / (fv1 / 1.8f)) * 50.0f));
                }
                i += 1;
                a0 += 1;
            } while (i < gRiders);
            i = 0;
        }
        if (gRiders > 0) {
            a0 = D_801C2938;
            do {
                if (a0->unk19C >= 0x927C0) {
                    a0->unk19C = 0x927BF;
                }
                if ((a0->unk2F4 == 0) && (a0->unk2EC == 0)) {
                    j = 0;
                    if (gRiders > 0) {
                        a3 = D_801C2938;
                        do {
                            if ((a3->unk2F4 == 0) && (a3->unk2EC == 0) && (j != i)) {
                                tmp = a0->racePosition;
                                tmp2 = a3->racePosition;
                                if ((tmp < tmp2) && (a3->unk19C < a0->unk19C)) {
                                    a0->racePosition = tmp2;
                                    a3->racePosition = tmp;
                                }
                            }
                            j += 1;
                            a3 += 1;
                        } while (j < gRiders);
                    }
                }
                i += 1;
                a0 += 1;
            } while (i < gRiders);
            i = 0;
        }
        if ((gCourseID != DOLPHIN_PARK) && (gRiders > 0)) {
            dst = D_801C26C0;
            a0 = D_801C2938;
            end = D_801C26C0 + gRiders;
            do {
                tmp = a0->racePosition;
                dst += 1;
                a0 += 1;
                dst[-1] = tmp;
            } while (dst < end);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80077F5C.s")
#endif

void func_80078264(void) {
    RiderStruct* temp_a0;
    RiderStruct* temp_v1;
    s32 var_v0;
    f32 var_fv0;
    s32 lapCount;
    s32 lapCount2;
    s32 var_a3;
    s32 var_t0;

    var_v0 = D_801BB120;
    var_fv0 = 0.0f;
    temp_v1 = &D_801C2938[D_800D48DC];
    temp_a0 = &D_801C2938[D_800D48E0];
    lapCount = temp_v1->lapCount;
    lapCount2 = temp_a0->lapCount;
    var_a3 = temp_v1->unkC;
    var_t0 = temp_a0->unkC;

    if (temp_a0->racePosition >= temp_v1->racePosition) {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_t0].unk88;
                if (D_801AEE20[var_t0].unk98 == 3) {
                    lapCount2++;
                }
                var_t0 = D_801AEE20[var_t0].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }
        temp_v1->unk330 = -var_fv0;
        temp_a0->unk330 = var_fv0;
    } else {
        if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
            while (var_v0-- > 0) {
                var_fv0 += D_801AEE20[var_a3].unk88;
                if (D_801AEE20[var_a3].unk98 == 3) {
                    lapCount++;
                }
                var_a3 = D_801AEE20[var_a3].unkA0;
                if ((lapCount != lapCount2) || (var_a3 != var_t0)) {
                    continue;
                } else {
                    break;
                }
            }
        }

        temp_v1->unk330 = var_fv0;
        temp_a0->unk330 = -var_fv0;
    }
}

#ifdef NON_MATCHING
void func_800783AC(s32 arg0) {
    /* Real-time rider position gap distance and rubberband AI speed scaling */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_800783AC.s")
#endif

#ifdef NON_MATCHING
void func_80079528(void) {
    /* Rider animation state transition and posture stabilizer */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_2FB10/func_80079528.s")
#endif
