#include <globaldefs.h>

// USA: func_0204a00c
ARM void SetSubstructWord0x68_0204a00c(unsigned char* obj, int value) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[0x1a] = value;
    }
}
