#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

extern void* data_ov025_021ef988;

struct InField8Struct021e628c {
    char pad0[8];
    int field8;
};

// USA: func_ov025_021e628c
ARM int SetGlobalField_021e628c_021e628c(struct InField8Struct021e628c* in) {
    *(int*)((char*)*(void**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset) + 0x54c) = in->field8;
    return 1;
}
