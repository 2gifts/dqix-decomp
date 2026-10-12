#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02168b08 func_ov004_02169040
#endif

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov023_021fa598(void*);

// USA: func_ov004_02168b08  (semantic: DispatchIfType4_02168b08)
extern "C" ARM int func_ov004_02168b08(void* a, int key) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) goto ret0;
#if defined(jpn)
    if (func_ov023_021f6f10(node) != 0x4) goto ret0;
#else
    if (ScaleStatsIfType12_021f6f10(node) != 0x4) goto ret0;
#endif
    return func_ov023_021fa598(node);
ret0:
    return 0;
}
