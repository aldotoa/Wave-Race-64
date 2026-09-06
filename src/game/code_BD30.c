#include "global.h"

extern u8 D_1005748[];
extern Gfx D_1006748[];

s32 D_800D47E0[2] = { 1, 2 };
s16 gColorRed = 255;
s16 gColorGreen = 255;
s16 gColorBlue = 255;
s16 gColorAlpha = 33;
s16 D_800D47F8 = 255;

/* Splash screen overlay: draws the scrolling title splash image on top of
 * the frame (texture D_1005748 via display list D_1006748). D_800D47E0[0]
 * selects the behavior: 0 skips drawing, 1 uses the translucent logo
 * render mode, anything else uses the opaque cloudy-surface mode. */
void Splash_Init(void) {
}

Gfx* Splash_Draw(Gfx* gdl) {
    static u32 sTexScroll = { 0 };

    if (D_800D47E0[0] == 0) {
        return gdl;
    }

    gSPDisplayList(gdl++, D_1006748);
    gDPLoadTextureBlock(gdl++, D_1005748, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetEnvColor(gdl++, gColorRed, gColorGreen, gColorBlue, gColorAlpha);

    if (D_800D47E0[0] == 1) {
        gDPSetRenderMode(gdl++,
                         AA_EN | IM_RD | CVG_DST_WRAP | ZMODE_OPA | CVG_X_ALPHA |
                             GBL_c1(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA),
                         AA_EN | IM_RD | CVG_DST_WRAP | ZMODE_OPA | CVG_X_ALPHA |
                             GBL_c2(G_BL_CLR_MEM, G_BL_0, G_BL_CLR_MEM, G_BL_1MA));
    } else {
        gDPSetRenderMode(gdl++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    }

    /* Scroll the splash texture upward one step per frame, wrapping every 128 frames. */
    sTexScroll = (sTexScroll - 1) % 0x80;

    gSPTextureRectangle(gdl++, 36, 84, 1240, 872, G_TX_RENDERTILE, sTexScroll * 32, 0, 1024, 1024);

    return gdl;
}
