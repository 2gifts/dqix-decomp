#include <globaldefs.h>

// USA: func_02048c68
ARM int CheckSubstructFlag0x100_02048c68(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return (p[8] & 0x100) != 0;
    }
    return 0;
}
