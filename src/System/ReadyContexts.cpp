#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

// USA: func_020c7950
ARM void MarkContextReadyAndSwitch(ProcessorContext *context) {
    int priorState      = DisableIRQInterrupts();
    context->blockState = CONTEXT_STATE_READY;
    SwitchContext();
    SetIRQInterruptState(priorState);
}

// USA: func_020c7978
ARM ProcessorContext *GetFirstReadyContext() {
    ProcessorContext *context;
    for (context = data_021112e0.substruct_24.firstContext; context != NULL && context->blockState != CONTEXT_STATE_READY;
         context = context->pNext)
    {
    }
    return context;
}
