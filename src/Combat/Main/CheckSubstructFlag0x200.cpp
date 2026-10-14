#include <globaldefs.h>

// USA: func_02048c10
ARM int CheckSubstructFlag0x200_02048c10(unsigned char* obj) {
    int* p = *(int**)(obj + 0x13c);
    if (p != 0) {
        return (p[8] & 0x200) != 0;
    }
    return 0;
}
