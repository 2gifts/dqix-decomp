#include <globaldefs.h>

// USA: func_020c8a18
ARM void UpdateDataAccessPermission_020c8a18(unsigned int clearMask, unsigned int setMask) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c5, c0, 2
        bic v, v, clearMask
        orr v, v, setMask
        mcr p15, 0, v, c5, c0, 2
    }
}
