#include <globaldefs.h>

extern unsigned char data_021117b0;

// USA: func_020cdddc
ARM unsigned short GetHalfword021117b0At0x10_020cdddc() {
    return *(unsigned short*)(&data_021117b0 + 0x10);
}
