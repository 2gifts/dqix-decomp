#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

extern void* data_ov025_021ef988;

struct InField8Struct021e6270 {
    char pad0[8];
    int field8;
};

// USA: func_ov025_021e6270
ARM int SetGlobalField_021e6270_021e6270(struct InField8Struct021e6270* in) {
    *(int*)((char*)*(void**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset) + 0x548) = in->field8;
    return 1;
}
