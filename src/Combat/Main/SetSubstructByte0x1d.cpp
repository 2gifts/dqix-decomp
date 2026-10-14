#include <globaldefs.h>

// USA: func_020493b8
ARM void SetSubstructByte0x1d_020493b8(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x1d] = value;
    }
}
