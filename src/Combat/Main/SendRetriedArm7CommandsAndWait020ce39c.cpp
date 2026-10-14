#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);
int TryAcquireLock_020ce128(void);
void RetryHelperUntilZero_020ce870(int cmd);
extern "C" void func_020c976c(int);
extern "C" void func_020ce234(int value, int* ptr);

extern char data_021117ec;

// USA: func_020ce39c  (semantic: SendRetriedArm7CommandsAndWait020ce39c)
#pragma optimize_for_size off
extern "C" ARM void func_020ce39c(int* arr, int count) {
    int pumpArg = 0xa3a47;
    volatile int local;
    int i;
    for (;;) {
        unsigned irq = DisableIRQInterrupts();
        if (!TryAcquireLock_020ce128()) {
            SetIRQInterruptState(irq);
            continue;
        }
        local = -0x10000;
        *(int*)(&data_021117ec + 0x20) = (int)func_020ce234;
        *(int*)(&data_021117ec + 0x24) = (int)&local;
        i = 0;
        if (count > 0) {
            do {
                RetryHelperUntilZero_020ce870(arr[i]);
                i++;
            } while (i < count);
        }
        SetIRQInterruptState(irq);
        if (local == -0x10000) {
            do {
                func_020c976c(pumpArg);
            } while (local == -0x10000);
        }
        if (local == 0) {
            return;
        }
        func_020c976c(pumpArg);
    }
}
