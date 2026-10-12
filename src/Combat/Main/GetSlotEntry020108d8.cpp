#include <globaldefs.h>

#if defined(jpn)
enum { kSlotStride = 0x8cc };
#else
enum { kSlotStride = 0x964 };
#endif


#if defined(jpn)
#define GetSlotEntry020108d8 func_02010734
extern "C" ARM void* func_02010734(char* base, int index);
#endif

// USA: func_020108d8
ARM void* GetSlotEntry020108d8(char* base, int index) {
    return base + 0x474 + index * kSlotStride;
}
