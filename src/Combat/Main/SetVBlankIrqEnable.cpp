#include <globaldefs.h>

// USA: func_020c3864
#pragma optimize_for_size off
ARM int SetVBlankIrqEnable_020c3864(int enable) {
    volatile unsigned short* dispstat = (volatile unsigned short*)0x4000004;
    int prev = *dispstat & 8;
    if (enable != 0) {
        *dispstat |= 8;
    } else {
        *dispstat &= ~8;
    }
    return prev;
}
