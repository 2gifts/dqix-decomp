#include <globaldefs.h>

unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
void InvokeCallbackIfCurrent_020d29b0(int packed);

// USA: func_020d27fc
ARM void InvokeCallbackWithInterruptsDisabled020d27fc(int channel, int packed) {
    unsigned int mask = DisableIRQInterrupts();
    InvokeCallbackIfCurrent_020d29b0(packed);
    SetIRQInterruptState(mask);
}
