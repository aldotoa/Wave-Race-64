#ifndef ROM_ASSETS_H
#define ROM_ASSETS_H

#include <ultra64.h>

#ifdef __cplusplus
extern "C" {
#endif

extern u8 *gRomBuffer;
extern size_t gRomSize;

int rom_assets_init(const char *rom_path);
void rom_assets_cleanup(void);
void game_dma_copy(uintptr_t devAddr, void *vAddr, u32 nbytes);

#ifdef __cplusplus
}
#endif

#endif /* ROM_ASSETS_H */
