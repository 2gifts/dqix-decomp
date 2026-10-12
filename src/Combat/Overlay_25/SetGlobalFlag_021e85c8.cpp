#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define SetGlobalFlag_021e85c8 func_ov025_021e8a68
#endif

extern "C" int func_ov025_021eb6fc(void* p, int flag);

struct DataOv025_021ef988_85c8 {
    char pad0xC[kGlobalHolderInnerOffset];
    void* field0xC;
};
extern DataOv025_021ef988_85c8 data_ov025_021ef988;

// USA: func_ov025_021e85c8
#if defined(jpn)
extern "C"
#endif
ARM int SetGlobalFlag_021e85c8(void) {
    func_ov025_021eb6fc(data_ov025_021ef988.field0xC, 1);
    return 1;
}
