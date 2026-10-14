#include <globaldefs.h>

// USA: func_0204a040
ARM int GetSubstructByte0x6c_0204a040(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x6c] : 0xff;
}
