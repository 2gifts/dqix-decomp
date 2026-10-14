#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int TryAcquireLock_020ce128(void);
void RetryHelperUntilZero_020ce870(int cmd);

struct DataBlock020ce4e8 {
    char pad[0x20];
    int f20;
    int f24;
    int f28;
};
extern struct DataBlock020ce4e8 data_021117ec;

// USA: func_020ce4e8  (semantic: SendLockedArm7Command020ce4e8)
extern "C" ARM int func_020ce4e8(int a0, int a1, int a2, int a3, int a4) {
    int irq = DisableIRQInterrupts();
    if (TryAcquireLock_020ce128() == 0) {
        SetIRQInterruptState(irq);
        return 1;
    }
    int cmd = (a0 & 0xff) | 0x2006100;
    data_021117ec.f20 = a3;
    data_021117ec.f24 = a4;
    data_021117ec.f28 = a2;
    RetryHelperUntilZero_020ce870(cmd);
    RetryHelperUntilZero_020ce870(0x1010000 | (a1 & 0xffff));
    SetIRQInterruptState(irq);
    return 0;
}
