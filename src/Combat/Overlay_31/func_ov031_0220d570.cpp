#include <globaldefs.h>
#include "System/Interrupts.h"
extern char* data_ov031_0224e53c;

// USA: func_ov031_0220d570
extern "C" ARM int func_ov031_0220d570(int flags) {
    int irq = DisableIRQInterrupts();
    char* context = data_ov031_0224e53c;
    unsigned int mask = 0;
    int previous = *(int*)(context + 0x2000 + 0x264);
    if (context == NULL) {
        SetIRQInterruptState(irq);
        return 0;
    }
    if (flags & 0x8000) {
        mask |= 0x3ffe;
        if (!(flags & 0x3ffe)) flags |= 0xa082;
    }
    if (flags & 0x20000) mask |= 0x10000;
    if (flags & 0x80000) mask |= 0x40000;
    if (flags & 0x200000) mask |= 0x100000;
    if (flags & 0x800000) mask |= 0x400000;
    *(int*)(context + 0x2000 + 0x264) = flags | (previous & ~mask);
    SetIRQInterruptState(irq);
    return previous;
}
