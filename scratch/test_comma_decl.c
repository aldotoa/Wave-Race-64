#include <ultra64.h>
extern u16 D_80B0008[];
Gfx* func_i2_802C86E4(Gfx* gdl, s32 x, s32 y) {
    s32 height, y2, i, tex_offset, cur_y;

    for (tex_offset = 0, i = 0, cur_y = y, y2 = y + 20; i != 105; i += 15, y2 += 15, cur_y += 15, tex_offset += 1950) {
        if (i != 90) {
            height = 15;
        } else {
            height = 2;
        }

        gDPLoadTextureTile(gdl++, (u8*) D_80B0008 + (tex_offset << 1), G_IM_FMT_RGBA, G_IM_SIZ_16b, 130, 0, 0, 0, 130 - 1,
                           height - 1, 0, G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gdl++, (x + 8) << 2, y2 << 2, (x + 138) << 2, (cur_y + height + 20) << 2, G_TX_RENDERTILE,
                            0, 0, 1 << 10, 1 << 10);
    }

    return gdl;
}
