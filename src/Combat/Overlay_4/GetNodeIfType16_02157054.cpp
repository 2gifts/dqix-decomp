#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif

// USA: func_ov004_02157054  (semantic: GetNodeIfType16_02157054)
extern "C" ARM void* func_ov004_02157054(void* a, int key) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), key);
    if (!node) goto ret0;
    if (ScaleStatsIfType12_021f6f10(node) == 0x10) return node;
ret0:
    return 0;
}
