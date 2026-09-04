#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ultra64.h>

static pthread_mutex_t sMsgQueueMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t sMsgQueueCond = PTHREAD_COND_INITIALIZER;

typedef struct {
    OSMesgQueue *queue;
    OSMesg msg;
} EventRegistration;

static EventRegistration sEventTable[OS_NUM_EVENTS];

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {
    if (mq == NULL) {
        return;
    }
    pthread_mutex_lock(&sMsgQueueMutex);

    mq->mtqueue = NULL;
    mq->fullqueue = NULL;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;

    pthread_mutex_unlock(&sMsgQueueMutex);
}

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    if (mq == NULL || mq->msg == NULL || mq->msgCount <= 0) {
        return -1;
    }

    pthread_mutex_lock(&sMsgQueueMutex);

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            pthread_cond_wait(&sMsgQueueCond, &sMsgQueueMutex);
        } else {
            pthread_mutex_unlock(&sMsgQueueMutex);
            return -1;
        }
    }

    s32 last = (mq->first + mq->validCount) % mq->msgCount;
    mq->msg[last] = msg;
    mq->validCount++;

    pthread_cond_broadcast(&sMsgQueueCond);
    pthread_mutex_unlock(&sMsgQueueMutex);

    return 0;
}

s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) {
    if (mq == NULL || mq->msg == NULL || mq->msgCount <= 0) {
        return -1;
    }

    pthread_mutex_lock(&sMsgQueueMutex);

    while (mq->validCount >= mq->msgCount) {
        if (flag == OS_MESG_BLOCK) {
            pthread_cond_wait(&sMsgQueueCond, &sMsgQueueMutex);
        } else {
            pthread_mutex_unlock(&sMsgQueueMutex);
            return -1;
        }
    }

    mq->first = (mq->first - 1 + mq->msgCount) % mq->msgCount;
    mq->msg[mq->first] = msg;
    mq->validCount++;

    pthread_cond_broadcast(&sMsgQueueCond);
    pthread_mutex_unlock(&sMsgQueueMutex);

    return 0;
}

s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag) {
    if (mq == NULL || mq->msg == NULL || mq->msgCount <= 0) {
        return -1;
    }

    pthread_mutex_lock(&sMsgQueueMutex);

    while (mq->validCount == 0) {
        if (flag == OS_MESG_BLOCK) {
            pthread_cond_wait(&sMsgQueueCond, &sMsgQueueMutex);
        } else {
            pthread_mutex_unlock(&sMsgQueueMutex);
            return -1;
        }
    }

    if (msg != NULL) {
        *msg = mq->msg[mq->first];
    }
    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    pthread_cond_broadcast(&sMsgQueueCond);
    pthread_mutex_unlock(&sMsgQueueMutex);

    return 0;
}

void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg) {
    pthread_mutex_lock(&sMsgQueueMutex);

    if (event < OS_NUM_EVENTS) {
        sEventTable[event].queue = mq;
        sEventTable[event].msg = msg;
    }

    pthread_mutex_unlock(&sMsgQueueMutex);
}

void __osSendEvent(OSEvent event) {
    pthread_mutex_lock(&sMsgQueueMutex);

    if (event < OS_NUM_EVENTS && sEventTable[event].queue != NULL) {
        OSMesgQueue *mq = sEventTable[event].queue;
        OSMesg msg = sEventTable[event].msg;

        if (mq->validCount < mq->msgCount) {
            s32 last = (mq->first + mq->validCount) % mq->msgCount;
            mq->msg[last] = msg;
            mq->validCount++;
            pthread_cond_broadcast(&sMsgQueueCond);
        }
    }

    pthread_mutex_unlock(&sMsgQueueMutex);
}
