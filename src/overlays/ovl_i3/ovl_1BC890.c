#include "global.h"

#ifdef NON_MATCHING
Gfx* func_i3_802C5800(Gfx* arg0) {
    /* Marine Fortress master overlay display list and water gate coordinator */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5800.s")
#endif

void func_i3_802C5AE8(void) {
}

void func_i3_802C5AF0(void) {
    func_80069798(D_801CE5F8->unkA80, D_801CE5F8->unk1780, D_801CE5F8->unkA40, &D_802C7024, &D_80198310, &D_80198350);
}

#ifdef NON_MATCHING
/* Marine Fortress breakwater surge heightfield updater (133 instructions).
 * Floor score: 223 / 683 (compiler allocates -0x20 stack frame vs -0x18 when mixing
 * Gfx_ClearFrameBuffers early return or spills).
 * Load-bearing structures:
 * - early clear check: if (D_801CE63C != 0) { D_801CE63C = 0; if (gGameState == 30) ... }
 * - race scene: D_800DAB2C = 0; Game_BuildRaceScene(arg0)
 * - switch on D_802C7028 guarded by if (D_80223938 != 0)
 * - gSPDisplayList(var_v0, D_106F168)
 * - course completion check: if (D_80228A16 == 1) { gCourseID = D_801CB330; Game_EnterGameplay(); }
 */
extern s32 D_80223938;
extern s32 D_802C7028;
extern s32 D_i3_802C6F88;
extern s32 D_i3_802C6F84;
extern s32 D_802C702C;
extern enum Course D_801CB330;

void func_801EB91C(void);
Gfx* func_i3_802C5D54(Gfx*);
Gfx* func_i3_802C6344(Gfx*);
void func_i3_802C6E9C(void);

Gfx* func_i3_802C5B40(Gfx* arg0) {
    register Gfx* var_v0;

    if (D_801CE63C != 0) {
        D_801CE63C = 0;
        if (gGameState == 30) {
            arg0 = Gfx_ClearFrameBuffers(arg0);
            goto end;
        }
    }

    D_800DAB2C = 0;
    var_v0 = Game_BuildRaceScene(arg0);

    if (D_80223938 != 0) {
        switch (D_802C7028) {
            case 0:
                var_v0 = func_i3_802C5D54(var_v0);
                break;
            case 1:
                var_v0 = func_i3_802C6344(var_v0);
                break;
        }
    }

    arg0 = var_v0 + 1;
    gSPDisplayList(var_v0, D_106F168);

    if (gGameState == 30) {
        if (D_i3_802C6F88 != 0) {
            D_i3_802C6F88 = 0;
            func_801EB91C();
        } else {
            if (D_801CE692->unk0 & 0xB000) {
                if (D_i3_802C6F84 != 0) {
                    func_i3_802C6E9C();
                }
            } else if ((D_80223938 != 0) && (D_801CE644 >= D_802C702C)) {
                func_i3_802C6E9C();
            }
            SysUtils_Rand();
        }
    } else {
        if (D_801CE644 >= 0) {
            D_801CE644--;
        }
        if (D_801CE644 == 0) {
            func_800C1F60(7);
        }
        if (D_80228A16 == 1) {
            gCourseID = D_801CB330;
            Game_EnterGameplay();
        }
    }

    if (D_801CE638 != 8) {
        func_800AD3C4();
    }

    if (gGameState == 30) {
        D_801CE644++;
    }

end:
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5B40.s")
#endif

#ifdef NON_MATCHING
void func_i3_802C5D54(void) {
    /* Storm lock gate opening/closing kinematic animator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C5D54.s")
#endif

#ifdef NON_MATCHING
void func_i3_802C6344(void) {
    /* Breakwater splash particle emitter and collision response */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/overlays/ovl_i3/ovl_1BC890/func_i3_802C6344.s")
#endif

void func_i3_802C6E9C(void) {
    gPrevGameState = gGameState;
    D_801CE630 = 0;
    gGameState = 31;
    D_801CE638 = 8;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 20;
    D_800DAB1C = 0;
    D_800D461C = 3;

    D_i3_802C6FE0 = 1;

    FadeTransition_SetProps(5, 0, 20);
    func_801E6A4C(0, 0);
    AudioGeneral_PlaySound(58, 0);
}
