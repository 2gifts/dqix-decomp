#include <globaldefs.h>

#if defined(jpn)
enum { kHolderFlagsOffset = 0xc };
#else
enum { kHolderFlagsOffset = 0x1c };
#endif


#if defined(jpn)
#define SetFlagBit_021e4a90_021e4a90 func_ov025_021e4f80
#endif

struct Holder021e4a90 {
    char pad0[kHolderFlagsOffset];
    unsigned int flags;
};

extern struct Holder021e4a90 data_ov025_021ef988;

// USA: func_ov025_021e4a90
#if defined(jpn)
extern "C"
#endif
ARM int SetFlagBit_021e4a90_021e4a90(void) {
    data_ov025_021ef988.flags |= 0x100;
    return 1;
}
