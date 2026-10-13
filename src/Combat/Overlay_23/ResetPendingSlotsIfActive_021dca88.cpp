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

struct PendingWindowLoads {
    unsigned char unknown0[PendingSlotOffset];
    int primaryTaskId;
    int taskIds[7];
    unsigned char unknownAfterTasks[PendingStateOffset - PendingArrayOffset - 7 * sizeof(int)];
    unsigned char state;
    unsigned char flag;
};

// USA: func_ov023_021dca88  (semantic: ResetPendingSlotsIfActive_021dca88)
extern "C" ARM void func_ov023_021dca88(void* obj) {
    PendingWindowLoads* loads = (PendingWindowLoads*)obj;
    if (loads->state == 2) return;
    ResetIfNonNeg_021db2e4(&loads->primaryTaskId);
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4(&loads->taskIds[i]);
    }
    loads->state = 2;
    loads->flag = 0;
}
