#include "global.h"

extern s32 D_800D461C;
extern s32 D_800DAB1C;
extern s32 D_801CE630;
extern s32 gPrevGameState;
extern s32 D_801CE638;
extern s32 D_801CE63C;
extern s32 D_801CE640;
extern s32 D_801CE644;

extern Gfx D_8011F820[];

Gfx* Gfx_ClearCurrentBuffer(Gfx* glistp);
Gfx* func_8008FB74(Gfx* glistp);
Gfx* Gfx_DrawCoursePanel(Gfx* glistp, s32 course);
Gfx* Draw_WaterEffects(Gfx* glistp);
void func_801E2530(void);
Gfx* func_801E2058(Gfx* glistp);
Gfx* func_801E229C(Gfx* glistp);

#ifdef NON_MATCHING
void func_801E1290(void) {
    /* Machine tuning interaction and controller input loop */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1290.s")
#endif

#ifdef NON_MATCHING
void func_801E1BA8(void) {
    /* Machine tuning state initialization */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1BA8.s")
#endif

#ifdef NON_MATCHING
Gfx* func_801E1E8C(Gfx* glistp) {
    if (D_801CE63C != 0) {
        D_801CE63C = 0;
    }
    D_800DAB2C = 0;
    glistp = Gfx_ClearCurrentBuffer(glistp);
    glistp = func_8008FB74(glistp);
    glistp = func_801E2058(glistp);
    gSPDisplayList(glistp++, D_8011F820);
    glistp = Gfx_DrawCoursePanel(glistp, gCourseID);
    glistp = Draw_WaterEffects(glistp);
    glistp = func_801E229C(glistp);
    if (gGameState == 0x64) {
        func_801E2530();
    }
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E1E8C.s")
#endif

#ifdef NON_MATCHING
Gfx* func_801E2058(Gfx* glistp) {
    /* Slider cursor movement & audio feedback */
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2058.s")
#endif

#ifdef NON_MATCHING
Gfx* func_801E229C(Gfx* glistp) {
    /* Jet ski color customization palette selector */
    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E229C.s")
#endif

#ifdef NON_MATCHING
const char D_80226210[] = "A";
const char D_80226214[] = "B";
const char D_80226218[] = "C";
const char D_8022621C[] = "D";
const char D_80226220[] = "E";
const char D_80226224[] = "F";
const char D_80226228[] = "G";
const char D_8022622C[] = "H";
const char D_80226230[] = "I";
const char D_80226234[] = "J";
const char D_80226238[] = "K";
const char D_8022623C[] = "L";
const char D_80226240[] = "M";
const char D_80226244[] = "N";
const char D_80226248[] = "O";
const char D_8022624C[] = "P";
const char D_80226250[] = "Q";
const char D_80226254[] = "R";
const char D_80226258[] = "S";
const char D_8022625C[] = "T";
const char D_80226260[] = "U";
const char D_80226264[] = "V";
const char D_80226268[] = "W";
const char D_8022626C[] = "X";
const char D_80226270[] = "Y";
const char D_80226274[] = "Z";
const char D_80226278[] = "-";
const char D_8022627C[] = ".";
const char D_80226280[] = " ";
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226210.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226214.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226218.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022621C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226220.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226224.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226228.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022622C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226230.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226234.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226238.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022623C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226240.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226244.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226248.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022624C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226250.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226254.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226258.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022625C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226260.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226264.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226268.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022626C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226270.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226274.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226278.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_8022627C.s")
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/D_80226280.s")
#endif

#ifdef NON_MATCHING
void func_801E2530(void) {
    /* Character select and machine tuning cursor display list renderer */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2530.s")
#endif

void func_801E2B8C(s32 arg0) {
    gPrevGameState = gGameState;
    D_801CE630 = arg0;
    gGameState = GAME_STATE_65;
    D_801CE638 = 6;
    D_801CE63C = 1;
    D_801CE640 = 0;
    D_801CE644 = 0;
    D_800DAB1C = 0;
    D_800D461C = 2;
    FadeTransition_SetProps(1, 0xE, 0x14);
}

#ifdef NON_MATCHING
void func_801E2C14(void) {
    /* Machine tuning exit and active rider stat commit */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/AF8C0/func_801E2C14.s")
#endif
