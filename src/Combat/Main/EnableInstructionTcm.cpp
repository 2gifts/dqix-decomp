#include <globaldefs.h>

// USA: func_020c89c4
ARM void EnableInstructionTcm_020c89c4(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c1, c0, 0
        orr v, v, #0x40000
        mcr p15, 0, v, c1, c0, 0
    }
}
