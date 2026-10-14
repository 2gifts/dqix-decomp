#include <globaldefs.h>

// USA: func_020c9a4c
ARM unsigned int CountLeadingZeros_020c9a4c(unsigned int value) {
    asm {
        clz value, value
    }
    return value;
}
