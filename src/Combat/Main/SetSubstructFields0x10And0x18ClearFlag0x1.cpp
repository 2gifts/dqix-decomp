#include <globaldefs.h>

// USA: func_02049bd4
ARM void SetSubstructFields0x10And0x18ClearFlag0x1_02049bd4(unsigned char* obj, int* src) {
    if (*(int**)(obj + 0x13c) == 0) return;
    (*(int**)(obj + 0x13c))[4] = src[0];
    (*(int**)(obj + 0x13c))[6] = src[2];
    (*(int**)(obj + 0x13c))[8] &= ~0x1;
}
