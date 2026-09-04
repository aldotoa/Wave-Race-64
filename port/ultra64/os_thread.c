#include <pthread.h>
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ultra64.h>

#define MAX_THREADS 32

typedef struct {
    OSThread *n64_thread;
    OSId id;
    OSPri priority;
    void (*entry)(void *);
    void *arg;
    pthread_t pthread;
    int started;
    int stopped;
} NativeThread;

static NativeThread sNativeThreads[MAX_THREADS];
static pthread_mutex_t sThreadMutex = PTHREAD_MUTEX_INITIALIZER;
static int sThreadCount = 0;

static NativeThread* find_or_alloc_thread(OSThread *thread) {
    int i;
    for (i = 0; i < sThreadCount; i++) {
        if (sNativeThreads[i].n64_thread == thread) {
            return &sNativeThreads[i];
        }
    }
    if (sThreadCount < MAX_THREADS) {
        NativeThread *nt = &sNativeThreads[sThreadCount++];
        memset(nt, 0, sizeof(*nt));
        nt->n64_thread = thread;
        return nt;
    }
    return NULL;
}

static void* thread_runner(void *arg) {
    NativeThread *nt = (NativeThread *)arg;
    if (nt && nt->entry) {
        nt->entry(nt->arg);
    }
    return NULL;
}

void osCreateThread(OSThread *thread, OSId id, void (*entry)(void *),
                    void *arg, void *sp, OSPri pri) {
    pthread_mutex_lock(&sThreadMutex);
    
    NativeThread *nt = find_or_alloc_thread(thread);
    if (nt != NULL) {
        nt->id = id;
        nt->priority = pri;
        nt->entry = entry;
        nt->arg = arg;
        nt->started = 0;
        nt->stopped = 0;
    }

    if (thread != NULL) {
        thread->id = id;
        thread->priority = pri;
        thread->state = OS_STATE_STOPPED;
    }

    pthread_mutex_unlock(&sThreadMutex);
}

void osStartThread(OSThread *thread) {
    pthread_mutex_lock(&sThreadMutex);

    NativeThread *nt = find_or_alloc_thread(thread);
    if (nt != NULL && !nt->started) {
        nt->started = 1;
        if (thread != NULL) {
            thread->state = OS_STATE_RUNNING;
        }
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        /* Set thread priority if permissions allow */
        struct sched_param param;
        int policy = SCHED_OTHER;
        param.sched_priority = 0;
        pthread_attr_setschedparam(&attr, &param);

        pthread_create(&nt->pthread, &attr, thread_runner, nt);
        pthread_attr_destroy(&attr);
    }

    pthread_mutex_unlock(&sThreadMutex);
}

void osDestroyThread(OSThread *thread) {
    pthread_mutex_lock(&sThreadMutex);

    NativeThread *nt = find_or_alloc_thread(thread);
    if (nt != NULL) {
        nt->stopped = 1;
        if (thread != NULL) {
            thread->state = OS_STATE_STOPPED;
        }
    }

    pthread_mutex_unlock(&sThreadMutex);
}

void osStopThread(OSThread *thread) {
    osDestroyThread(thread);
}

OSId osGetThreadId(OSThread *thread) {
    if (thread == NULL) {
        return 0;
    }
    return thread->id;
}

OSPri osGetThreadPri(OSThread *thread) {
    if (thread == NULL) {
        return 0;
    }
    return thread->priority;
}

void osSetThreadPri(OSThread *thread, OSPri pri) {
    pthread_mutex_lock(&sThreadMutex);

    NativeThread *nt = find_or_alloc_thread(thread);
    if (nt != NULL) {
        nt->priority = pri;
    }
    if (thread != NULL) {
        thread->priority = pri;
    }

    pthread_mutex_unlock(&sThreadMutex);
}
