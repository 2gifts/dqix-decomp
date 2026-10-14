#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int state);
int IssueBattleCommandSlot6_020d4f3c(int fn);
extern "C" void func_ov031_0220da1c(int a);
extern "C" void func_ov031_0220dc40(void);
extern int data_ov031_0224e53c;

// USA: func_ov031_0220cce4
extern "C" ARM int func_ov031_0220cce4(void) {
    unsigned int state = DisableIRQInterrupts();
    if (data_ov031_0224e53c == 0) {
        SetIRQInterruptState(state);
        return 1;
    }
    int v = *(int*)((char*)data_ov031_0224e53c + 0x2260);
    if (v == 1) goto L_ret0;
    if (v == 3) goto L_slot;
    if (v != 4) goto L_default;
    SetIRQInterruptState(state);
    return 2;

L_ret0:
    SetIRQInterruptState(state);
    return 0;

L_default:
    SetIRQInterruptState(state);
    return 1;

L_slot: {
    int r = IssueBattleCommandSlot6_020d4f3c((int)func_ov031_0220dc40);
    switch (r) {
    case 2:
        func_ov031_0220da1c(4);
        *(unsigned short*)((char*)data_ov031_0224e53c + 0x2280) = 2;
        break;
    case 8:
        SetIRQInterruptState(state);
        return 4;
    case 3:
    default:
        func_ov031_0220da1c(0xb);
        SetIRQInterruptState(state);
        return 7;
    }
    SetIRQInterruptState(state);
    return 3;
}
}
