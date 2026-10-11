#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov023_021fa598(void*);

// USA: func_ov004_02157018
ARM int DispatchAdjustmentIfType4_02157018(void* a, int key) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) goto ret0;
    if (ScaleStatsIfType12_021f6f10(node) != 0x4) goto ret0;
    return func_ov023_021fa598(node);
ret0:
    return 0;
}
