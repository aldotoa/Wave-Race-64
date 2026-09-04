#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "rom_assets.h"

u8 *gRomBuffer = NULL;
size_t gRomSize = 0;
static int sRomFd = -1;

int rom_assets_init(const char *rom_path) {
    if (gRomBuffer != NULL) {
        return 0; /* Already loaded */
    }

    const char *paths[] = {
        rom_path,
        "baserom.us.rev1.z64",
        "build/waverace64.us.rev1.z64",
        "Wave Race 64 - Kawasaki Jet Ski (USA) (Rev 1).z64",
        NULL
    };

    int fd = -1;
    const char *loaded_path = NULL;
    int i;

    for (i = 0; paths[i] != NULL; i++) {
        if (paths[i][0] == '\0') continue;
        fd = open(paths[i], O_RDONLY);
        if (fd >= 0) {
            loaded_path = paths[i];
            break;
        }
    }

    if (fd < 0) {
        fprintf(stderr, "[ROM Assets] Error: Could not open ROM file.\n");
        return -1;
    }

    struct stat st;
    if (fstat(fd, &st) < 0) {
        close(fd);
        return -1;
    }

    gRomSize = st.st_size;
    gRomBuffer = (u8 *)mmap(NULL, gRomSize, PROT_READ, MAP_SHARED, fd, 0);
    if (gRomBuffer == MAP_FAILED) {
        /* Fallback to heap allocation */
        gRomBuffer = (u8 *)malloc(gRomSize);
        if (!gRomBuffer) {
            close(fd);
            return -1;
        }
        if (read(fd, gRomBuffer, gRomSize) != (ssize_t)gRomSize) {
            free(gRomBuffer);
            gRomBuffer = NULL;
            close(fd);
            return -1;
        }
        sRomFd = -1;
        close(fd);
    } else {
        sRomFd = fd;
    }

    printf("[ROM Assets] Successfully loaded %zu bytes from '%s'\n", gRomSize, loaded_path);
    return 0;
}

void rom_assets_cleanup(void) {
    if (gRomBuffer != NULL) {
        if (sRomFd >= 0) {
            munmap(gRomBuffer, gRomSize);
            close(sRomFd);
            sRomFd = -1;
        } else {
            free(gRomBuffer);
        }
        gRomBuffer = NULL;
        gRomSize = 0;
    }
}

void game_dma_copy(uintptr_t devAddr, void *vAddr, u32 nbytes) {
    if (gRomBuffer == NULL) {
        rom_assets_init(NULL);
    }

    if (gRomBuffer != NULL && vAddr != NULL) {
        if (devAddr + nbytes <= gRomSize) {
            memcpy(vAddr, gRomBuffer + devAddr, nbytes);
        } else {
            fprintf(stderr, "[ROM Assets] DMA out of bounds: devAddr=0x%lx, nbytes=%u, romSize=%zu\n",
                    (unsigned long)devAddr, nbytes, gRomSize);
        }
    }
}
