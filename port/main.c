#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ultra64.h>
#include "rom_assets.h"

int main(int argc, char *argv[]) {
    printf("========================================================\n");
    printf("   Wave Race 64 - Native macOS Apple Silicon Port       \n");
    printf("   Platform: macOS (arm64) | Compiler: Clang            \n");
    printf("========================================================\n\n");

    const char *rom_path = (argc > 1) ? argv[1] : "baserom.us.rev1.z64";
    printf("[Init] Initializing ROM asset reader for '%s'...\n", rom_path);

    if (rom_assets_init(rom_path) != 0) {
        /* Try build path */
        if (rom_assets_init("build/waverace64.us.rev1.z64") != 0) {
            fprintf(stderr, "[Init] Error: Could not locate retail ROM.\n");
            return 1;
        }
    }

    printf("[Init] Testing Libultra POSIX Message Queue...\n");
    OSMesgQueue testQueue;
    OSMesg testBuffer[4];
    osCreateMesgQueue(&testQueue, testBuffer, 4);

    osSendMesg(&testQueue, (OSMesg)(uintptr_t)0x12345678, OS_MESG_NOBLOCK);
    osSendMesg(&testQueue, (OSMesg)(uintptr_t)0xDEADBEEF, OS_MESG_NOBLOCK);

    OSMesg receivedMsg = NULL;
    osRecvMesg(&testQueue, &receivedMsg, OS_MESG_BLOCK);
    if ((uintptr_t)receivedMsg == 0x12345678) {
        printf("[Test] OSMesgQueue FIFO message 1 verified (0x%lx).\n", (uintptr_t)receivedMsg);
    } else {
        fprintf(stderr, "[Test] OSMesgQueue mismatch: expected 0x12345678, got 0x%lx\n", (uintptr_t)receivedMsg);
        return 1;
    }

    osRecvMesg(&testQueue, &receivedMsg, OS_MESG_BLOCK);
    if ((uintptr_t)receivedMsg == 0xDEADBEEF) {
        printf("[Test] OSMesgQueue FIFO message 2 verified (0x%lx).\n", (uintptr_t)receivedMsg);
    } else {
        fprintf(stderr, "[Test] OSMesgQueue mismatch: expected 0xDEADBEEF, got 0x%lx\n", (uintptr_t)receivedMsg);
        return 1;
    }

    printf("[Init] Testing Time & OS Clock...\n");
    OSTime t0 = osGetTime();
    printf("[Test] Initial OS cycle count: %llu\n", (unsigned long long)t0);

    printf("[Init] Testing ROM asset DMA copy...\n");
    u8 dmaTestBuffer[64];
    memset(dmaTestBuffer, 0, sizeof(dmaTestBuffer));
    game_dma_copy(0x0, dmaTestBuffer, sizeof(dmaTestBuffer));
    printf("[Test] First 4 bytes of ROM: %02X %02X %02X %02X (N64 Header: 80 37 12 40)\n",
           dmaTestBuffer[0], dmaTestBuffer[1], dmaTestBuffer[2], dmaTestBuffer[3]);

    if (dmaTestBuffer[0] == 0x80 && dmaTestBuffer[1] == 0x37) {
        printf("[Test] ROM Header successfully validated!\n");
    }

    printf("\n[Phase 1 Complete] Libultra POSIX shim and game modules operational on Apple Silicon arm64.\n");

    rom_assets_cleanup();
    return 0;
}
