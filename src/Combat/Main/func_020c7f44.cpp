#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"

struct MessageQueue
{
    BlockedContextList sendQueue;
    BlockedContextList receiveQueue;
    void** messages;
    int capacity;
    int first;
    int count;
};

// USA: func_020c7f44
extern "C" ARM int func_020c7f44(MessageQueue* queue, void* message, int flags)
{
    int priorState = DisableIRQInterrupts();

    int capacity;
    if ((capacity = queue->capacity) <= queue->count)
    {
        do
        {
            if (!(flags & 1))
            {
                SetIRQInterruptState(priorState);
                return false;
            }
            BlockCurrentContext(&queue->sendQueue);
        } while ((capacity = queue->capacity) <= queue->count);
    }

    queue->first = (queue->first + capacity - 1) % capacity;
    queue->messages[queue->first] = message;
    queue->count++;

    UnblockContexts(&queue->receiveQueue);

    SetIRQInterruptState(priorState);
    return true;
}
