#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

// USA: func_020c7be8
ARM void SleepCompletionProc(ProcessorContext **ppContext) {
    ProcessorContext *context = *ppContext;
    *ppContext                = NULL;
    context->sleepAlarm       = NULL;
    MarkContextReadyAndSwitch(context);
}

// USA: func_020c7c08
ARM PFNSwitchContextProc SetSwitchContextProcB(PFNSwitchContextProc proc) {
    int priorState                                = DisableIRQInterrupts();
    PFNSwitchContextProc priorProc                = data_021112e0.substruct_24.switchContextProcB;
    data_021112e0.substruct_24.switchContextProcB = proc;
    SetIRQInterruptState(priorState);
    return priorProc;
}

extern "C" void func_020c9bf0(void);

// USA: func_020c7c30
ARM void InterruptWaitLoopFunction(void *) {
    EnableIRQInterrupts();
    for (;;) {
        func_020c9bf0();
    }
}

// USA: func_020c7c40
ARM unsigned int AddContextSwitchLock() {
    unsigned int previousCount;
    int previousIRQState = DisableIRQInterrupts();
    if (data_021112e0.contextSwitchLock < ~0u) {
        previousCount = data_021112e0.contextSwitchLock++;
    }
    SetIRQInterruptState(previousIRQState);
    return previousCount;
}

// USA: func_020c7c74
ARM unsigned int RemoveContextSwitchLock() {
    int previousIRQState       = DisableIRQInterrupts();
    unsigned int previousCount = 0;
    if (data_021112e0.contextSwitchLock > 0) {
        previousCount = data_021112e0.contextSwitchLock--;
    }
    SetIRQInterruptState(previousIRQState);
    return previousCount;
}
