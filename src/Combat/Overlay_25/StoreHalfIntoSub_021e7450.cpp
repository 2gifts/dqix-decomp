#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e7450 func_ov025_021e7900
#endif

struct Sub021e7450 {
    char pad[0x26];
    unsigned short f26;
};

struct Base021e7450 {
    char pad[0x540];
    struct Sub021e7450 sub;

    struct Sub021e7450* GetSub() { return &sub; }
};

struct Holder021e7450 {
    char pad[kGlobalHolderInnerOffset];
    struct Base021e7450* base;
};
extern struct Holder021e7450 data_ov025_021ef988;

// USA: func_ov025_021e7450  (semantic: StoreHalfIntoSub_021e7450)
extern "C" ARM int func_ov025_021e7450(void* obj) {
    data_ov025_021ef988.base->GetSub()->f26 = *(unsigned short*)((char*)obj + 8);
    return 1;
}
