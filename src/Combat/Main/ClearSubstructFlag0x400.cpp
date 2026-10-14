#include <globaldefs.h>

// USA: func_0204a0e0
ARM void ClearSubstructFlag0x400_0204a0e0(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] &= ~0x400;
    }
}
