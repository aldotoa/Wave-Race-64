#include "common.h"

#ifdef NON_MATCHING
void func_8007FD80(void) {
    /* Particle spray emitter coordinator */
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_3A580/func_8007FD80.s")
#endif

#ifdef NON_MATCHING
Gfx* func_8007FFA8(Gfx* arg0) {
    /* 3D water spray particle display list emitter */
    return arg0;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/game/code_3A580/func_8007FFA8.s")
#endif
