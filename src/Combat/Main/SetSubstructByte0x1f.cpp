#include <globaldefs.h>

// USA: func_02049400
ARM void SetSubstructByte0x1f_02049400(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x1f] = value;
    }
}
