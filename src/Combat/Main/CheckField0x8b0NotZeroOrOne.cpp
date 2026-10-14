#include <globaldefs.h>

// USA: func_02068b7c
ARM int CheckField0x8b0NotZeroOrOne_02068b7c(int a, unsigned char* obj) {
    int v = *(int*)(obj + 0x8b0);
    return v != 0 && v != 1;
}
