#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

// USA: func_020c7898
ARM void BlockCurrentContext(BlockedContextList *blockQueue) {
    int priorIRQState         = DisableIRQInterrupts();
    ProcessorContext *context = *data_021112e0.ppActiveContext;
    if (blockQueue != NULL) {
        context->containerBlockedQueue = blockQueue;
        blockQueue->Insert(context);
    }
    context->blockState = CONTEXT_STATE_BLOCKED;
    SwitchContext();
    SetIRQInterruptState(priorIRQState);
}
