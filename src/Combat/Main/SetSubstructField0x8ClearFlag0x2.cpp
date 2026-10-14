#include <globaldefs.h>

// USA: func_02049bac
ARM void SetSubstructField0x8ClearFlag0x2_02049bac(unsigned char* obj, int* src) {
    if (*(int**)(obj + 0x13c) == 0) return;
    (*(int**)(obj + 0x13c))[2] = src[1];
    (*(int**)(obj + 0x13c))[8] &= ~0x2;
}
