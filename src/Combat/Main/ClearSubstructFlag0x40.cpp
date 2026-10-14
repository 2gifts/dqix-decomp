#include <globaldefs.h>

// USA: func_0204950c
ARM void ClearSubstructFlag0x40_0204950c(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    p[8] &= ~0x40;
}
