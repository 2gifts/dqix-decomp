#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
void TailCallOffset20_021fbdcc(void*, int);

// USA: func_ov004_021556dc  (semantic: DispatchAdjustmentIfType16_021556dc)
extern "C" ARM int func_ov004_021556dc(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x2e);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 0x10) return 0;
    TailCallOffset20_021fbdcc(node, -1);
    return 0;
}
