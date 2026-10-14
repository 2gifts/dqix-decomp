#include <globaldefs.h>

// USA: func_020c8a34
ARM void SetProtectionRegion2_020c8a34(unsigned int value) {
    asm {
        mcr p15, 0, value, c6, c2, 0
    }
}
