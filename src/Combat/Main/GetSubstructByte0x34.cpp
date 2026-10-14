#include <globaldefs.h>

// USA: func_02049444
ARM int GetSubstructByte0x34_02049444(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    return p != 0 ? p[0x34] : 0;
}
