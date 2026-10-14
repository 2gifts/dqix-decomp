#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int CheckState0x10_020cf87c(void);

struct State02111818_020cf1e0 {
    unsigned char pad0[0xc];
    unsigned int busy;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1c;
    unsigned int f20;
    unsigned int f24;
};

extern struct State02111818_020cf1e0 data_02111818;

// USA: func_020cf1e0  (semantic: EnterCombatModeAlt020cf1e0)
extern "C" ARM int func_020cf1e0(int a, int b, int c, int d) {
    unsigned int mask = DisableIRQInterrupts();
    if (data_02111818.busy != 0) {
        SetIRQInterruptState(mask);
        return 1;
    }
    data_02111818.busy = 1;
    SetIRQInterruptState(mask);
    data_02111818.f20 = 2;
    data_02111818.f24 = 0;
    data_02111818.f14 = a;
    data_02111818.f18 = b;
    data_02111818.f10 = c;
    data_02111818.f1c = d;
    return CheckState0x10_020cf87c() ? 0 : 3;
}
