#include <globaldefs.h>
#include "System/IPC.h"

void FillBufferAndStoreResult_020d12e4(void);
void InitializeInterProcessorCommunication(void);
bool IsIPCCommandHandlerRegistered(int command, IPCSide side);
void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);
extern "C" void func_020d16b0(void);
void InitSubsystemContextOnce020d1954(void* obj);
void SetModeFlagAndUpdatePermission020d15b4(int flag);
void HandleMsg1SetFlag_020d18a4(int a, int msg);
void DispatchType0x11ShutdownOnce_020d18d0(int context, int code);
void ClearField4At02112160_020d1940(void);

struct Guard020d15fc {
    char pad0[8];
    int flag8;
    int fc;
    char pad10[8];
    int f18;
};
extern struct Guard020d15fc data_02112160;
extern int data_02112240;

// USA: func_020d15fc  (semantic: InitIPCAndSubsystems_020d15fc)
extern "C" ARM void func_020d15fc(void) {
    if (data_02112160.flag8 != 0) return;
    data_02112160.flag8 = 1;
    FillBufferAndStoreResult_020d12e4();
    data_02112160.fc = 0;
    InitializeInterProcessorCommunication();
    do {
    } while (!IsIPCCommandHandlerRegistered(0xd, IPCSide_Arm7));
    SetArm9IPCCommandHandler(0xd, (IPCCommandHandler)HandleMsg1SetFlag_020d18a4);
    func_020d16b0();
    SetArm9IPCCommandHandler(0xd, 0);
    SetArm9IPCCommandHandler(0xd, (IPCCommandHandler)DispatchType0x11ShutdownOnce_020d18d0);
    data_02112160.f18 = 0;
    InitSubsystemContextOnce020d1954(&data_02112240);
    SetArm9IPCCommandHandler(0x11, (IPCCommandHandler)ClearField4At02112160_020d1940);
    SetModeFlagAndUpdatePermission020d15b4(0);
}
