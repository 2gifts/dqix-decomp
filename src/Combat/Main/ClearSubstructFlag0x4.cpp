#include <globaldefs.h>

// USA: func_02049ae4
ARM void ClearSubstructFlag0x4_02049ae4(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] &= ~0x4;
    }
}
