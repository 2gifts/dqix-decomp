#include <globaldefs.h>

#if defined(jpn)
enum { kHolderBaseOffset = 0x4 };
#else
enum { kHolderBaseOffset = 0xc };
#endif

struct Src021e6ef8 {
    char pad[8];
    unsigned short h8;
    short ha;
};

struct Sub021e6ef8 {
    char pad[0x3e];
    unsigned short f3e;
    short f40;
};

struct Base021e6ef8 {
    char pad[0x540];
    struct Sub021e6ef8 sub;
};

struct Holder021e6ef8 {
    char pad[kHolderBaseOffset];
    struct Base021e6ef8* base;
};
extern struct Holder021e6ef8 data_ov025_021ef988;

// USA: func_ov025_021e6ef8
ARM int CopyFields_021e6ef8_021e6ef8(struct Src021e6ef8* src) {
    short va = src->ha;
    unsigned short v8 = src->h8;
    struct Base021e6ef8* base = data_ov025_021ef988.base;
    base->sub.f3e = v8;
    base->sub.f40 = va;
    return 1;
}
