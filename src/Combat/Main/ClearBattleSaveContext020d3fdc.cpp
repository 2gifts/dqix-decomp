#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int GetBattleStateCode_020d41e8(void);
extern "C" int func_020d424c(int a, int b);
#include "System/IPC.h"

void ClearBit0At027FFF96_020d468c(void);
void SetArm9IPCCommandHandler(int command, IPCCommandHandler handler);

struct BattleState021142e0_020d3fdc {
    unsigned short state;
    unsigned char pad[2];
    unsigned int f4;
};

extern struct BattleState021142e0_020d3fdc data_021142e0;

// USA: func_020d3fdc
ARM int ClearBattleSaveContext020d3fdc(void) {
    unsigned int mask = DisableIRQInterrupts();
    if (GetBattleStateCode_020d41e8() != 0) {
        SetIRQInterruptState(mask);
        return 3;
    }
    int r = func_020d424c(1, 0);
    if (r != 0) {
        return r;
    }
    ClearBit0At027FFF96_020d468c();
    SetArm9IPCCommandHandler(0xa, 0);
    data_021142e0.f4 = 0;
    data_021142e0.state = 0;
    SetIRQInterruptState(mask);
    return 0;
}
