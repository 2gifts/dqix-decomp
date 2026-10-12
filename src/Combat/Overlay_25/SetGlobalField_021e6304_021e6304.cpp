#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define SetGlobalField_021e6304_021e6304 func_ov025_021e67b4
#endif

extern void* data_ov025_021ef988;

struct InField8Struct021e6304 {
    char pad0[8];
    int field8;
};

// USA: func_ov025_021e6304
#if defined(jpn)
extern "C"
#endif
ARM int SetGlobalField_021e6304_021e6304(struct InField8Struct021e6304* in) {
    *(int*)((char*)*(void**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset) + 0x558) = in->field8;
    return 1;
}
