#include "System/Interrupts.h"
#include "System/Mutex.h"
#include "System/ProcessorContext.h"
#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void *destination, unsigned int length);
extern "C" void func_020c9be0(void);

// USA: func_020c75b4
ARM void PopulateContext(ProcessorContext *context, unsigned int startAddress, unsigned int userdata, unsigned int stackBottom,
                         unsigned int stackSize, unsigned int priority) {
    int prior           = DisableIRQInterrupts();
    int id              = GenerateUniqueContextID();
    context->priority   = priority;
    context->uniqueID   = id;
    context->blockState = CONTEXT_STATE_BLOCKED;
    context->unknown_74 = 0;
    InsertContextIntoGlobalList(context);
    context->stackBottom                          = stackBottom;
    context->stackTop                             = stackBottom - stackSize;
    context->stackUnknownTopSubspaceSize          = 0;
    *(unsigned int *) (context->stackBottom - 4)  = STACK_BOTTOM_MAGIC;
    *(unsigned int *) context->stackTop           = STACK_TOP_MAGIC;
    context->contextsAwaitingThisCompletion.first = context->contextsAwaitingThisCompletion.last = NULL;
    InitializeContextRegisters(context, startAddress, stackBottom - 4);
    context->userModeRegisters[0]  = userdata;
    context->userModeRegisters[14] = (unsigned int) ContextExecutionReturnProc;
    func_020ca3ec(0, (void *) (stackBottom - stackSize + 4), stackSize - 8);
    context->blockingMutex        = NULL;
    context->lockedMutexes.pFirst = NULL;
    context->lockedMutexes.pLast  = NULL;
    SetContextEndProc(context, NULL);
    context->containerBlockedQueue = NULL;
    context->pNextBlocked          = NULL;
    context->pPrevBlocked          = NULL;
    func_020ca3ec(0, &context->unknown_A4, 0xc);
    context->sleepAlarm = NULL;
    SetIRQInterruptState(prior);
}

// USA: func_020c76b0
ARM void ContextExecutionReturnProc() {
    DisableIRQInterrupts();
    ExitContext(data_021112e0.substruct_24.activeContext, 0);
}

// USA: func_020c76d0
ARM void ExitContext(ProcessorContext *context, int exitCode) {
    unsigned int exitStack = data_021112e0.unknown_1C;
    if (exitStack != 0) {
        InitializeContextRegisters(context, (unsigned int) ExitCurrentContext, exitStack);
        context->userModeRegisters[0] = exitCode;
        context->programStatusRegister |= 0x80;
        context->blockState = CONTEXT_STATE_READY;
        RestoreContext(context);
    } else {
        ExitCurrentContext(exitCode);
    }
}

// USA: func_020c772c
ARM void ExitCurrentContext(int code) {
    ProcessorContext::ExitRoutine exitRoutine = (*data_021112e0.ppActiveContext)->exitProc;
    if (exitRoutine != NULL) {
        (*data_021112e0.ppActiveContext)->exitProc = NULL;
        exitRoutine(code);
        DisableIRQInterrupts();
    }
    ShutdownCurrentContext();
}

// USA: func_020c7764
ARM void ShutdownCurrentContext() {
    ProcessorContext *context = *data_021112e0.ppActiveContext;
    AddContextSwitchLock();
    UnlockAllMutexesLockedByContext(context);
    if (context->containerBlockedQueue != NULL) {
        context->containerBlockedQueue->Remove(context);
    }
    RemoveContextFromGlobalList(context);
    context->blockState = CONTEXT_STATE_INVALID;
    UnblockContexts(&context->contextsAwaitingThisCompletion);
    RemoveContextSwitchLock();
    SwitchContextUninterrupted();
    func_020c9be0();
}

// USA: func_020c77c0
ARM void ShutdownContext(ProcessorContext *context) {
    int priorIRQState = DisableIRQInterrupts();
    if (data_021112e0.substruct_24.activeContext == context) {
        ShutdownCurrentContext();
    }

    AddContextSwitchLock();
    UnlockAllMutexesLockedByContext(context);
    CancelContextSleepAlarm(context);
    if (context->containerBlockedQueue != NULL) {
        context->containerBlockedQueue->Remove(context);
    }
    RemoveContextFromGlobalList(context);
    context->blockState = CONTEXT_STATE_INVALID;
    UnblockContexts(&context->contextsAwaitingThisCompletion);
    RemoveContextSwitchLock();
    SetIRQInterruptState(priorIRQState);
    SwitchContextUninterrupted();
}

// USA: func_020c783c
ARM void CancelContextSleepAlarm(ProcessorContext *context) {
    Alarm *alarm = context->sleepAlarm;
    if (alarm != NULL) CancelAlarm(alarm);
}

// USA: func_020c7854
ARM void AwaitContextCompletion(ProcessorContext *context) {
    int priorState = DisableIRQInterrupts();
    if (context->blockState != CONTEXT_STATE_INVALID) {
        BlockCurrentContext(&context->contextsAwaitingThisCompletion);
    }
    SetIRQInterruptState(priorState);
}
