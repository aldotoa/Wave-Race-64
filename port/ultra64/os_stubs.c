#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ultra64.h>
#include "rom_assets.h"

/* Global OS variables */
u32 osTvType = 1;      /* OS_TV_NTSC */
s32 osRomType = 0;
s32 osVersion = 0;
u32 osResetType = 0;
u32 osMemSize = 0x800000; /* 8MB expansion */

/* Static state */
static void *sCurrentFramebuffer = NULL;
static OSMesgQueue *sViEventMq = NULL;
static OSMesg sViEventMsg = NULL;
static OSContPad sCurrentContPad[4];

/* Address Translation */
uintptr_t osVirtualToPhysical(void *vaddr) {
    return (uintptr_t)vaddr;
}

void *osPhysicalToVirtual(uintptr_t paddr) {
    return (void *)paddr;
}

/* Cache Operations */
void osInvalDCache(void *vaddr, size_t nbytes) {
    (void)vaddr;
    (void)nbytes;
}

void osInvalICache(void *vaddr, size_t nbytes) {
    (void)vaddr;
    (void)nbytes;
}

void osWritebackDCache(void *vaddr, size_t nbytes) {
    (void)vaddr;
    (void)nbytes;
}

void osWritebackDCacheAll(void) {
}

/* Video Interface (VI) */
void osCreateViManager(OSPri pri) {
    (void)pri;
}

void osViSetMode(OSViMode *mode) {
    (void)mode;
}

void osViBlack(u8 active) {
    (void)active;
}

void osViSwapBuffer(void *vaddr) {
    sCurrentFramebuffer = vaddr;
}

void *osViGetCurrentFramebuffer(void) {
    return sCurrentFramebuffer;
}

void osViSetSpecialFeatures(u32 func) {
    (void)func;
}

void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retraceCount) {
    sViEventMq = mq;
    sViEventMsg = msg;
    (void)retraceCount;
}

u32 osGetMemSize(void) {
    return osMemSize;
}

/* Peripheral Interface (PI) */
void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQueue, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    (void)pri;
    (void)cmdQueue;
    (void)cmdBuf;
    (void)cmdMsgCnt;
}

s32 osPiStartDma(OSIoMesg *mb, s32 priority, s32 direction, uintptr_t devAddr,
                 void *dramAddr, size_t size, OSMesgQueue *mq) {
    (void)mb;
    (void)priority;
    (void)direction;

    game_dma_copy(devAddr, dramAddr, (u32)size);

    if (mq != NULL) {
        osSendMesg(mq, (OSMesg)0, OS_MESG_NOBLOCK);
    }
    return 0;
}

s32 osPiRawStartDma(s32 direction, u32 devAddr, void *dramAddr, size_t size) {
    (void)direction;
    game_dma_copy(devAddr, dramAddr, (u32)size);
    return 0;
}

s32 osPiWriteIo(uintptr_t devAddr, u32 data) {
    (void)devAddr;
    (void)data;
    return 0;
}

s32 osPiReadIo(uintptr_t devAddr, u32 *data) {
    (void)devAddr;
    if (data != NULL) {
        *data = 0;
    }
    return 0;
}

/* Display Processor (DP) & Signal Processor (SP) */
u32 osDpGetStatus(void) {
    return 0; /* Not busy */
}

void osDpSetStatus(u32 status) {
    (void)status;
}

void osSpTaskLoad(OSTask *task) {
    (void)task;
}

void osSpTaskStartGo(OSTask *task) {
    (void)task;
}

void osSpTaskYield(void) {
}

OSYieldResult osSpTaskYielded(OSTask *task) {
    (void)task;
    return 0;
}

/* Controller (SI) */
s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *status) {
    (void)mq;
    if (bitpattern != NULL) {
        *bitpattern = 0x01; /* Port 1 connected */
    }
    if (status != NULL) {
        memset(status, 0, sizeof(OSContStatus) * 4);
        status[0].type = CONT_ABSOLUTE;
        status[0].status = 0;
        status[0].errno = 0;
    }
    return 0;
}

s32 osContStartReadData(OSMesgQueue *mq) {
    if (mq != NULL) {
        osSendMesg(mq, (OSMesg)0, OS_MESG_NOBLOCK);
    }
    return 0;
}

void osContGetReadData(OSContPad *pad) {
    if (pad != NULL) {
        memcpy(pad, sCurrentContPad, sizeof(OSContPad) * 4);
    }
}

/* Save / EEPROM */
static u8 sEepromMemory[2048];

s32 osEepromProbe(OSMesgQueue *mq) {
    (void)mq;
    return 1; /* EEPROM present */
}

s32 osEepromLongRead(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    (void)mq;
    u32 offset = (u32)address * 8;
    if (offset + nbytes <= sizeof(sEepromMemory)) {
        memcpy(buffer, &sEepromMemory[offset], nbytes);
    }
    return 0;
}

s32 osEepromLongWrite(OSMesgQueue *mq, u8 address, u8 *buffer, int nbytes) {
    (void)mq;
    u32 offset = (u32)address * 8;
    if (offset + nbytes <= sizeof(sEepromMemory)) {
        memcpy(&sEepromMemory[offset], buffer, nbytes);
    }
    return 0;
}

/* Audio Interface (AI) */
u32 osAiGetLength(void) {
    return 0;
}

s32 osAiSetFrequency(u32 freq) {
    (void)freq;
    return 32000;
}

s32 osAiSetNextBuffer(void *buf, u32 size) {
    (void)buf;
    (void)size;
    return 0;
}

/* System Initialization */
void osInitialize(void) {
    printf("[Wave Race 64 Native] osInitialize called.\n");
}
