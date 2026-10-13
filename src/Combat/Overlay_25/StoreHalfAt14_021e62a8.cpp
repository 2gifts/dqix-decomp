#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e62a8 func_ov025_021e6758
#endif

struct Sub021e62a8 {
    char pad[0x14];
    unsigned short f14;
};

struct Base021e62a8 {
    char pad[0x540];
    struct Sub021e62a8 sub;

    struct Sub021e62a8* GetSub() { return &sub; }
};

struct Holder021e62a8 {
    char pad[kGlobalHolderInnerOffset];
    struct Base021e62a8* base;
};
extern struct Holder021e62a8 data_ov025_021ef988;

// USA: func_ov025_021e62a8  (semantic: StoreHalfAt14_021e62a8)
extern "C" ARM int func_ov025_021e62a8(void* obj) {
    data_ov025_021ef988.base->GetSub()->f14 = *(unsigned short*)((char*)obj + 8);
    return 1;
}
