#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define Wrapper021e74d0 func_ov025_021e7980
#endif

extern "C" int func_ov025_021ed11c(void*, int);

struct Work021ef988_021e74d0 {
    char pad[kGlobalHolderInnerOffset];
    char* base;
};
extern struct Work021ef988_021e74d0 data_ov025_021ef988;

struct Obj021e74d0 {
    char pad8[8];
    int v;
};

// USA: func_ov025_021e74d0
#if defined(jpn)
extern "C"
#endif
ARM int Wrapper021e74d0(struct Obj021e74d0* obj) {
    func_ov025_021ed11c(data_ov025_021ef988.base + 0x22c, obj->v);
    return 1;
}
