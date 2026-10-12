#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e6cd4 func_ov025_021e7184
#endif

struct Sub021e6cd4 {
    char pad[0x24];
    unsigned short f24;
};

struct Base021e6cd4;

struct Holder021e6cd4 {
    char pad[kGlobalHolderInnerOffset];
    struct Base021e6cd4* base;
};
extern struct Holder021e6cd4 data_ov025_021ef988;

inline struct Sub021e6cd4* GetSub021e6cd4(struct Base021e6cd4* b) {
    return (struct Sub021e6cd4*)((char*)b + 0x540);
}

// USA: func_ov025_021e6cd4  (semantic: StoreFieldIntoSub_021e6cd4)
extern "C" ARM int func_ov025_021e6cd4(void* obj) {
    GetSub021e6cd4(data_ov025_021ef988.base)->f24 = (unsigned short)*(unsigned int*)((char*)obj + 8);
    return 1;
}
