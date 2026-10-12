#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define func_ov025_021e8064 func_ov025_021e8504
#endif

struct Sub021e8064 {
    char pad[0x1e];
    unsigned short f1e;
};

struct Base021e8064;

struct Holder021e8064 {
    char pad[kGlobalHolderInnerOffset];
    struct Base021e8064* base;
};
extern struct Holder021e8064 data_ov025_021ef988;

inline struct Sub021e8064* GetSub021e8064(struct Base021e8064* b) {
    return (struct Sub021e8064*)((char*)b + 0x540);
}

// USA: func_ov025_021e8064  (semantic: StoreHalfAt1e_021e8064)
extern "C" ARM int func_ov025_021e8064(void* obj) {
    GetSub021e8064(data_ov025_021ef988.base)->f1e = *(unsigned short*)((char*)obj + 8);
    return 1;
}
