#include <globaldefs.h>

// USA: func_02068b94
ARM int CheckField0x8b4NotZeroOrOne_02068b94(int a, unsigned char* obj) {
    int v = *(int*)(obj + 0x8b4);
    return v != 0 && v != 1;
}
