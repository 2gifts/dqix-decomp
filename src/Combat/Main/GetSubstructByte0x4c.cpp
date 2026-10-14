#include <globaldefs.h>

// USA: func_02049468
ARM int GetSubstructByte0x4c_02049468(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x4c] : 0xff;
}
