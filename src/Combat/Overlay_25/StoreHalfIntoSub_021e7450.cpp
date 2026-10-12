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

struct Base021e7450;

struct Holder021e7450 {
    char pad[kGlobalHolderInnerOffset];
    struct Base021e7450* base;
};
extern struct Holder021e7450 data_ov025_021ef988;

inline struct Sub021e7450* GetSub021e7450(struct Base021e7450* b) {
    return (struct Sub021e7450*)((char*)b + 0x540);
}

// USA: func_ov025_021e7450  (semantic: StoreHalfIntoSub_021e7450)
extern "C" ARM int func_ov025_021e7450(void* obj) {
    GetSub021e7450(data_ov025_021ef988.base)->f26 = *(unsigned short*)((char*)obj + 8);
    return 1;
}
