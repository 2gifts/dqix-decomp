#include <globaldefs.h>

// USA: func_02048bf8
ARM void SetSubstructFlag0x200_02048bf8(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        p[8] |= 0x200;
    }
}
