#include <globaldefs.h>

#include "System/IPC.h"

void InitializeInterProcessorCommunication(void);
void SetArm9IPCCommandHandler(int, IPCCommandHandler);
extern "C" void _Z24DispatchType0x11InitOnceii(unsigned int, unsigned int, unsigned int);

struct InitGuard020d1118 { int done; void* callback; };
extern InitGuard020d1118 data_02112140;

// USA: _Z23RegisterType0x11Handlerv
// JPN: func_020d2be4
ARM void RegisterType0x11Handler(void) {
    InitializeInterProcessorCommunication();
    SetArm9IPCCommandHandler(0xe, _Z24DispatchType0x11InitOnceii);
    data_02112140.callback = NULL;
}
