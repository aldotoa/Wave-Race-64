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

/*
 * Draws a menu text banner from one of five texture tables. Types 0 and 4 load the
 * whole IA8 strip as a block; types 1-3 split it into `num_tiles` horizontal strips
 * loaded with LoadTextureTile.
 *
 * Load-bearing quirks (no codegen of their own):
 *  - `(u32)` casts on width/height in the load macros make the dxt/lrs math unsigned
 *    and stop LICM from hoisting the shared `(height - 1) << 2` out of the loop.
 *  - the empty `if (arg5) {}` / `if (entry) {}` only shift IDO's register priorities
 *    (entry/arg5 into t1/a1/a3, is_block/num_tiles into v0/v1).
 */
Gfx* func_801E3EE0(Gfx* glistp, s32 type, s32 idx, s32 x, s32 y, s32 arg5) {
    s32 i;
    s32 height;
    s32 is_block = 1;
    s32 num_tiles = 1;
    MenuBannerEntry* entry;

    switch (type) {
        case 0:
            height = 8;
            entry = &D_802263C0[idx];
            break;
        case 4:
            height = 10;
            entry = &D_802264F8[idx];
            if (arg5) {}
            break;
        case 1:
            entry = &D_80226568[idx];
            height = arg5 + 10;
            is_block = 0;
            if (entry) {}
            break;
        case 2:
            entry = &D_80226A48[idx];
            height = 18;
            is_block = 0;
            if (entry->width >= 228) {
                num_tiles = 2;
                height = 9;
            }
            break;
        case 3:
            entry = &D_80226890[idx];
            is_block = 0;
            height = arg5 + 14;
            if (arg5 == 6) {
                num_tiles = 5;
                height = 4;
            } else if (entry->width >= 291) {
                num_tiles = 2;
                height = 7;
            }
            break;
    }

    for (i = 0; i < num_tiles; i++) {
        if (is_block) {
            gDPLoadTextureBlock(glistp++, entry->img, G_IM_FMT_IA, G_IM_SIZ_8b, (u32) entry->width, height, 0,
                                G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        } else {
            gDPLoadTextureTile(glistp++, entry->img + (u32) entry->width * height * i, G_IM_FMT_IA, G_IM_SIZ_8b,
                               (u32) entry->width, height, 0, 0, (u32) entry->width - 1, (u32) height - 1, 0,
                               G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        }
        gSPScisTextureRectangle(glistp++, x << 2, (y + height * i) << 2, (x + entry->width) << 2,
                                (y + height * i + height) << 2, G_TX_RENDERTILE, 0, 0, 1 << 10, 1 << 10);
    }

    return glistp;
}
