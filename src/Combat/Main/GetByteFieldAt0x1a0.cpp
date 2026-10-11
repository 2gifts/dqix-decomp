#include <globaldefs.h>

// USA: func_02053eb4
ARM unsigned char GetByteFieldAt0x1a0(void* obj, int extra) {
#if defined(jpn)
    return *((unsigned char*)obj + extra + 0x194);
#else
    return *((unsigned char*)obj + extra + 0x1a0);
#endif
}
