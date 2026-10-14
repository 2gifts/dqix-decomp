#include <globaldefs.h>

// USA: func_02049f3c
ARM void ClearSubstructByte0x56_02049f3c(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x56] = 0;
    }
}
