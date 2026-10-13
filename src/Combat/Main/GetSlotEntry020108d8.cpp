#include <globaldefs.h>

#if defined(jpn)
enum { kSlotStride = 0x8cc };
#else
enum { kSlotStride = 0x964 };
#endif

// USA: func_020108d8
ARM void* GetSlotEntry020108d8(char* base, int index) {
    return base + 0x474 + index * kSlotStride;
}
