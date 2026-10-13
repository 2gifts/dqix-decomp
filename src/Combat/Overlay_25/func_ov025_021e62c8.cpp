#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif

void* GetActiveCombatWork(void);
int CheckCombatantStatusOrTable_02162954(void* self);
int IsByteFieldZero_021ed0fc(void* obj);
extern int data_ov025_021ef988;

// USA: func_ov025_021e62c8  (semantic: CheckByteFieldAndStatus_021e62c8)
extern "C" ARM int func_ov025_021e62c8(void) {
    void* p = *(void**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset);
    if (!IsByteFieldZero_021ed0fc((char*)p + 0x22c)) return 0;
    void* w = GetActiveCombatWork();
    int v = CheckCombatantStatusOrTable_02162954(w);
    return v == 0;
}
