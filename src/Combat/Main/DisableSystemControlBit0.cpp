#include <globaldefs.h>

// USA: func_020c8a08
ARM void DisableSystemControlBit0_020c8a08(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c1, c0, 0
        bic v, v, #0x1
        mcr p15, 0, v, c1, c0, 0
    }
}
