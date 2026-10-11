#include <globaldefs.h>

#if defined(jpn)
#define func_020c9a88 func_020cb554
#endif

#pragma optimize_for_size off
unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int state);
unsigned int CountLeadingZeros(unsigned int value);

extern int data_0211166c;
extern unsigned short data_02111670[9];

// USA: func_020c9a88  (semantic: ClearMatchingBitsInMaskTable020c9a88)
extern "C" ARM void func_020c9a88(int flags, int id) {
    unsigned int mask;
    unsigned int state = DisableIRQInterrupts();
    mask = flags & data_0211166c & 0x1ff;
    for (;;) {
        int pos = 0x1f - CountLeadingZeros(mask);
        if (pos < 0) break;
        unsigned int bit = 1 << pos;
        unsigned short entry = data_02111670[pos];
        mask &= ~bit;
        if (id != entry) continue;
        data_02111670[pos] = 0;
        data_0211166c &= ~bit;
    }
    SetIRQInterruptState(state);
}
