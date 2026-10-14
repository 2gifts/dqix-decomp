#include <globaldefs.h>

// USA: func_02083ca0
ARM void SetBit0x954StoreIndex0x950_02083ca0(unsigned char* obj, int bit) {
#if defined(jpn)
    *(unsigned short*)(obj + 0x8bc) |= 1 << bit;
#else
    *(unsigned short*)(obj + 0x954) |= 1 << bit;
#endif
#if defined(jpn)
    *(int*)(obj + 0x8b8) = bit;
#else
    *(int*)(obj + 0x950) = bit;
#endif
}
