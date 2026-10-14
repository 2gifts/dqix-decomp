#include <globaldefs.h>

// USA: func_020889e4
ARM void SetByte0x63AndFlag0x10000000_020889e4(unsigned char* obj) {
    obj[0x63] = 4;
    obj[0x86] = 0;
    ((int*)obj)[5] |= 0x10000000;
}
