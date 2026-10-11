// JPN: func_ov031_02239340
#include <globaldefs.h>

extern unsigned short* data_ov031_02290d14;
void SetGlobal02290d14_02239108(unsigned short v);
unsigned int DisableIRQInterrupts();
unsigned int SetIRQInterruptState(int mask);
extern "C" void func_ov031_02238a88(int);
#if defined(jpn)
extern "C" void func_ov027_021dcd5c(void* obj);
#else
void ResetBlockFields_021dcd5c(void* obj);
#endif

// USA: func_ov031_02238b60
extern "C" ARM void func_ov031_02238b60(void) {
    SetGlobal02290d14_02239108(3);
    unsigned short i = 1;
    do {
        if (!(data_ov031_02290d14[1] & (1 << i))) goto next;
        if (data_ov031_02290d14[2] & (1 << i)) goto next;
        if (!(data_ov031_02290d14[3] & (1 << i))) {
            unsigned short mask = (unsigned short)~(1 << i);
            unsigned int state = DisableIRQInterrupts();
            data_ov031_02290d14[1] &= mask;
            data_ov031_02290d14[2] &= mask;
            data_ov031_02290d14[3] &= mask;
            data_ov031_02290d14[4] &= mask;
            data_ov031_02290d14[5] &= mask;
            data_ov031_02290d14[6] &= mask;
            SetIRQInterruptState(state);
#if defined(jpn)
            func_ov027_021dcd5c((void*)(int)i);
#else
            ResetBlockFields_021dcd5c((void*)(int)i);
#endif
        } else {
            func_ov031_02238a88(i);
        }
    next:
        i++;
    } while (i < 0x10);
}
