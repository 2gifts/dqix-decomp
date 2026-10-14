#include <globaldefs.h>

// USA: func_020c8a2c
ARM void SetProtectionRegion1_020c8a2c(unsigned int value) {
    asm {
        mcr p15, 0, value, c6, c1, 0
    }
}
