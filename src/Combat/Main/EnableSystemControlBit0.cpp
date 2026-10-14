#include <globaldefs.h>

// USA: func_020c89f8
ARM void EnableSystemControlBit0_020c89f8(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c1, c0, 0
        orr v, v, #0x1
        mcr p15, 0, v, c1, c0, 0
    }
}
