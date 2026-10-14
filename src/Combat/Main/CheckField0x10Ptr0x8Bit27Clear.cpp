#include <globaldefs.h>

// USA: func_02068954
ARM int CheckField0x10Ptr0x8Bit27Clear_02068954(int a, unsigned char* obj) {
    unsigned int* p = *(unsigned int**)(obj + 0x10);
    if (p != NULL) {
        return (p[2] << 4 >> 31) == 0;
    }
    return 0;
}
