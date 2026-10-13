#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

struct Holder021e6010 {
    char pad0[kGlobalHolderInnerOffset];
    unsigned char* inner;
};

extern struct Holder021e6010 data_ov025_021ef988;

struct Param021e6010 { char pad[8]; unsigned short field_8; };

// USA: func_ov025_021e6010
ARM int SetField021e6010(struct Param021e6010* p) {
    *(unsigned short*)(data_ov025_021ef988.inner + 0x21c) = p->field_8;
    return 1;
}
