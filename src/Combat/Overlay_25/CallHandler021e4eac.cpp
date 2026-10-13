#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

struct Holder021e4eac {
    char pad0[kGlobalHolderInnerOffset];
    void* inner;
};

extern struct Holder021e4eac data_ov025_021ef988;
extern "C" void func_ov025_021e8a74(void* obj);

// USA: func_ov025_021e4eac
ARM int CallHandler021e4eac(void) {
    func_ov025_021e8a74(data_ov025_021ef988.inner);
    return 1;
}
