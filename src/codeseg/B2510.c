#include "common.h"

typedef struct {
    uintptr_t img;
    s32 width;
} MenuBannerEntry;

extern MenuBannerEntry D_802263C0[];
extern MenuBannerEntry D_802264F8[];
extern MenuBannerEntry D_80226568[];
extern MenuBannerEntry D_80226890[];
extern MenuBannerEntry D_80226A48[];

#ifdef NON_MATCHING
Gfx* func_801E3EE0(Gfx* glistp, s32 type, s32 idx, s32 x, s32 y) {
    MenuBannerEntry* entry;
    s32 num_tiles = 1;
    s32 width_param;
    s32 is_type0 = 1;
    s32 i;

    switch (type) {
        case 0:
            entry = &D_802263C0[idx];
            width_param = 8;
            break;
        case 4:
            entry = &D_802264F8[idx];
            width_param = 10;
            break;
        case 1:
            entry = &D_80226568[idx];
            width_param = y + 10;
            is_type0 = 0;
            break;
        case 2:
            entry = &D_80226890[idx];
            is_type0 = 0;
            if (y == 6) {
                width_param = y + 14;
                num_tiles = 5;
            } else if (entry->width < 291) {
                width_param = 4;
            } else {
                num_tiles = 2;
                width_param = 7;
            }
            break;
        case 3:
            entry = &D_80226A48[idx];
            width_param = 18;
            is_type0 = 0;
            if (entry->width >= 228) {
                num_tiles = 2;
                width_param = 9;
            }
            break;
    }

    for (i = 0; i < num_tiles; i++) {
        gDPPipeSync(glistp++);
        gDPSetTextureImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, entry->img);
        gDPTileSync(glistp++);
        gDPSetTile(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPLoadSync(glistp++);
        gDPLoadBlock(glistp++, G_TX_LOADTILE, 0, 0, 0, 0);
        gDPPipeSync(glistp++);
        gDPSetTile(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_RENDERTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPSetTileSize(glistp++, G_TX_RENDERTILE, 0, 0, 0, 0);
        gSPTextureRectangle(glistp++, x << 2, y << 2, (x + width_param) << 2, (y + 16) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    return glistp;
}
#else
#pragma GLOBAL_ASM("asm/us/rev1/nonmatchings/codeseg/B2510/func_801E3EE0.s")
#endif
