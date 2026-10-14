#include <globaldefs.h>

// USA: func_02048c38
ARM void SetSubstructFlag0x100_02048c38(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] |= 0x100;
    }
}
