#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int CheckState0x12_020cf89c(void);

struct State02111818_020cf134 {
    unsigned char pad0[0xc];
    unsigned int busy;
    unsigned int f10;
    unsigned int f14;
    unsigned char gap1[4];
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
};

extern struct State02111818_020cf134 data_02111818;

// USA: func_020cf134  (semantic: SetQueueEntryAndArm020cf134)
extern "C" ARM int func_020cf134(int a, int b, int c) {
    unsigned int mask = DisableIRQInterrupts();
    if (data_02111818.busy != 0) {
        SetIRQInterruptState(mask);
        return 1;
    }
    data_02111818.busy = 1;
    SetIRQInterruptState(mask);
    data_02111818.f20 = 1;
    data_02111818.f24 = 0;
    data_02111818.f14 = a;
    data_02111818.f10 = b;
    data_02111818.f1c = c;
    return CheckState0x12_020cf89c() ? 0 : 3;
}
