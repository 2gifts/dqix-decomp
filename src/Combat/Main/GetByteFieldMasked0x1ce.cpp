#include <globaldefs.h>

// USA: func_02039790
ARM int GetByteFieldMasked0x1ce_02039790(void* obj, int mask) {
#if defined(jpn)
    return *(unsigned char*)((char*)obj + 0x1c2) & mask;
#else
    return *(unsigned char*)((char*)obj + 0x1ce) & mask;
#endif
}
