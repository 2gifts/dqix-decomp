#include <globaldefs.h>

// USA: func_020493a4
ARM int GetSubstructByte0x1c_020493a4(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x1c] : 0xff;
}
