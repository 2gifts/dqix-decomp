#include <globaldefs.h>

// USA: func_0208979c
ARM void ClearBits0x1And0x4_0208979c(unsigned char* obj) {
    obj[0x3b] &= ~1;
    obj[0x3b] &= ~4;
}
