#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dca88 func_ov023_021dd398
#endif

void ResetIfNonNeg_021db2e4(volatile int* p);

// USA: func_ov023_021dca88  (semantic: ResetPendingSlotsIfActive_021dca88)
extern "C" ARM void func_ov023_021dca88(void* obj) {
    if (*((unsigned char*)obj + 0x776) == 2) return;
    ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x734));
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x738 + i * 4));
    }
    *((unsigned char*)obj + 0x776) = 2;
    *((unsigned char*)obj + 0x777) = 0;
}
