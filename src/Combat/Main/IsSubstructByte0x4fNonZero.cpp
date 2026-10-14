#include <globaldefs.h>

// USA: func_02049afc
ARM int IsSubstructByte0x4fNonZero_02049afc(unsigned char* obj) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p == 0) {
        return 0;
    }
    return p[0x4f] != 0;
}
