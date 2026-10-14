#include <globaldefs.h>

// USA: func_02048bd0
ARM int CheckSubstructFlag0x80_02048bd0(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return (p[8] & 0x80) != 0;
    }
    return 0;
}
