#include <globaldefs.h>

// USA: func_0204948c
ARM int GetSubstructByte0x4d_0204948c(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x4d] : 0xff;
}
