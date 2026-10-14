#include <globaldefs.h>

// USA: func_0204a030
ARM void SetSubstructByte0x6c(unsigned char* obj, int value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x6c] = value;
    }
}
