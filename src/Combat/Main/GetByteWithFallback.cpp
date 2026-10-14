#include <globaldefs.h>

// USA: func_020494a0
ARM int GetByteWithFallback_020494a0(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    unsigned char val;
    if (p == 0) {
        return 0xff;
    }
    val = p[0x4c];
    if (val == 0xff) {
        val = p[0x4d];
    }
    return val;
}
