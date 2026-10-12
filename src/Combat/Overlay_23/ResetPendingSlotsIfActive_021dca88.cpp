#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dca88 func_ov023_021dd398
#endif

void ResetIfNonNeg_021db2e4(volatile int* p);

#if defined(jpn)
enum { PendingSlotOffset = 0x6b0, PendingArrayOffset = 0x6b4, PendingStateOffset = 0x6f2, PendingFlagOffset = 0x6f3 };
#else
enum { PendingSlotOffset = 0x734, PendingArrayOffset = 0x738, PendingStateOffset = 0x776, PendingFlagOffset = 0x777 };
#endif

// USA: func_ov023_021dca88  (semantic: ResetPendingSlotsIfActive_021dca88)
extern "C" ARM void func_ov023_021dca88(void* obj) {
    if (*((unsigned char*)obj + PendingStateOffset) == 2) return;
    ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + PendingSlotOffset));
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + PendingArrayOffset + i * 4));
    }
    *((unsigned char*)obj + PendingStateOffset) = 2;
    *((unsigned char*)obj + PendingFlagOffset) = 0;
}
