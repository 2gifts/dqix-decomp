#include <globaldefs.h>
#include "System/IPC.h"

void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
int TriggerAndPollRegister04fff200_020d28f0(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
void InvokeCallbackWithInterruptsDisabled020d27fc(int channel, int packed);
extern "C" void func_020c976c(int);

// USA: func_020d2820
ARM void WaitForSharedFlagBit7020d2820(void) {
    SetArm9IPCCommandHandler(7, (IPCCommandHandler)InvokeCallbackWithInterruptsDisabled020d27fc);
    if (TriggerAndPollRegister04fff200_020d28f0() == 0) return;
    if (IsIPCCommandHandlerRegistered(7, IPCSide_Arm7) != 0) return;
    do {
        func_020c976c(100);
    } while (IsIPCCommandHandlerRegistered(7, IPCSide_Arm7) == 0);
}
