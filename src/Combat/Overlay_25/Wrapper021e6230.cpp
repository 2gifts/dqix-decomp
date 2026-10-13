#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

extern "C" int func_ov025_021e2f54(void*, int, int);

struct Work021ef988_021e6230 {
    char pad[kGlobalHolderInnerOffset];
    char* base;
};
extern struct Work021ef988_021e6230 data_ov025_021ef988;

// USA: func_ov025_021e6230
ARM int Wrapper021e6230(void* obj, int b, int c, int d) {
    (void)obj;
    (void)c;
    func_ov025_021e2f54(data_ov025_021ef988.base + 0x540, b, d);
    return 1;
}
