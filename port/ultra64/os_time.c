#include <time.h>
#include <ultra64.h>

static OSTime sTimeOffset = 0;

OSTime osGetTime(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    /* Convert nanoseconds to N64 count frequency (~46.875 MHz) */
    OSTime current = ((u64)ts.tv_sec * 46875000ULL) + (((u64)ts.tv_nsec * 46875ULL) / 1000000ULL);
    return current - sTimeOffset;
}

void osSetTime(OSTime time) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    OSTime current = ((u64)ts.tv_sec * 46875000ULL) + (((u64)ts.tv_nsec * 46875ULL) / 1000000ULL);
    sTimeOffset = current - time;
}

u32 osSetTimer(OSTimer *t, OSTime countdown, u64 interval, OSMesgQueue *mq, OSMesg msg) {
    if (t != NULL) {
        t->remaining = countdown;
        t->interval = interval;
        t->mq = mq;
        t->msg = (OSMesg*)msg;
    }
    return 0;
}
