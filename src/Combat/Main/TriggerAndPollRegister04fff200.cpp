#include <globaldefs.h>

extern "C" int func_020c7dc4(void);
unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

// USA: func_020d28f0
ARM int TriggerAndPollRegister04fff200(void) {
    if (func_020c7dc4() == 0) {
        return 1;
    }
    unsigned int mask = DisableIRQInterrupts();
    *(volatile int*)0x4fff200 = 0x10;
    int status = *(volatile int*)0x4fff200;
    SetIRQInterruptState(mask);
    return status != 0;
}
