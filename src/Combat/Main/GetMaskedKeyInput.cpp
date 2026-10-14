#include <globaldefs.h>

// USA: func_02012354
ARM unsigned short GetMaskedKeyInput_02012354(void) {
    int v = *(unsigned short*)0x4000130 | *(unsigned short*)0x27fffa8;
    return (v ^ 0x2fff) & 0x2fff;
}
