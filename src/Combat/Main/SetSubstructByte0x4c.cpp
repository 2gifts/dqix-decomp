#include <globaldefs.h>

// USA: func_02049458
ARM void SetSubstructByte0x4c_02049458(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x4c] = value;
    }
}
