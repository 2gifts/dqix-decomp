#include <globaldefs.h>

#include "System/IPC.h"

void InitializeInterProcessorCommunication(void);
void SetArm9IPCCommandHandler(int, IPCCommandHandler);
void DispatchType0x11InitOnce_020d1144(unsigned int, unsigned int, unsigned int);

struct InitGuard020d1118 { int done; void* callback; };
extern InitGuard020d1118 data_02112140;

// USA: _Z32RegisterType0x11Handler_020d1118v
ARM void RegisterType0x11Handler_020d1118(void) {
    InitializeInterProcessorCommunication();
    SetArm9IPCCommandHandler(0xe, (IPCCommandHandler)DispatchType0x11InitOnce_020d1144);
    data_02112140.callback = NULL;
}
