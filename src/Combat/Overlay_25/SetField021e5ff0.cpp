#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define SetField021e5ff0 func_ov025_021e64a0
#endif

struct Holder021e5ff0 {
    char pad0[kGlobalHolderInnerOffset];
    unsigned char* inner;
};

extern struct Holder021e5ff0 data_ov025_021ef988;

struct Param021e5ff0 { char pad[8]; unsigned short field_8; };

// USA: func_ov025_021e5ff0
#if defined(jpn)
extern "C"
#endif
ARM int SetField021e5ff0(struct Param021e5ff0* p) {
    *(unsigned short*)(data_ov025_021ef988.inner + 0x21c) = p->field_8;
    return 1;
}
