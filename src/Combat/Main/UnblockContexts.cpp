#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c78e8
ARM void UnblockContexts(BlockedContextList* blockQueue)
{
    int priorIRQState = DisableIRQInterrupts();
    if (blockQueue->first != NULL)
    {
        if (blockQueue->first != NULL)
        {
            do
            {
                ProcessorContext* context = blockQueue->PopFront();
                context->blockState = CONTEXT_STATE_READY;
                context->containerBlockedQueue = NULL;
                context->pNextBlocked = NULL;
                context->pPrevBlocked = NULL;
            } while (blockQueue->first != NULL);
        }
        blockQueue->last = NULL;
        blockQueue->first = NULL;
        SwitchContext();
    }
    SetIRQInterruptState(priorIRQState);
}
