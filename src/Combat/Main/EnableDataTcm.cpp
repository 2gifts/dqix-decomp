#include <globaldefs.h>

// USA: func_020c89d4
ARM void EnableDataTcm_020c89d4(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c1, c0, 0
        orr v, v, #0x10000
        mcr p15, 0, v, c1, c0, 0
    }
}
