#include <globaldefs.h>

#if defined(jpn)
enum { adjustedByteOffset = 0x1fa3 };
#else
enum { adjustedByteOffset = 0x1d6b };
#endif

// USA: func_ov000_021815c8
ARM int GetAdjustedByteField0x1d6b_ov000_021815c8(void* obj) {
    signed char val = *((signed char*)obj + adjustedByteOffset);
    if (val < 0) return -1;
    return *((signed char*)obj + val + 0x70);
}
