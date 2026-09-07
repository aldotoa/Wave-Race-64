#include "libultra_internal.h"

#ifdef AVOID_UB
/* AVOID_UB reroutes the thread-tail through this unified struct (see the
   header); it has no definition anywhere, so provide it. queue/tlnext
   point at itself exactly like the original __osRunQueue/__osActiveQueue
   point at &__osThreadTail (priority -1 keeps new threads preempting).
   Matching builds never see this. */
OSThread_ListHead __osThreadTail_fix = {
    NULL,
    -1,
    (OSThread*) &__osThreadTail_fix,
    (OSThread*) &__osThreadTail_fix,
    NULL,
    0,
};
#endif

void osSetThreadPri(OSThread* thread, OSPri pri) {
    register u32 int_disabled = __osDisableInt();
    if (thread == NULL) {
        thread = __osRunningThread;
    }

    if (thread->priority != pri) {
        thread->priority = pri;
        if (thread != __osRunningThread) {
            if (thread->state != OS_STATE_STOPPED) {
                __osDequeueThread(thread->queue, thread);
                __osEnqueueThread(thread->queue, thread);
            }
        }
        if (__osRunningThread->priority < __osRunQueue->priority) {
            __osRunningThread->state = OS_STATE_RUNNABLE;
            __osEnqueueAndYield(&__osRunQueue);
        }
    }

    __osRestoreInt(int_disabled);
}
