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
extern "C" void* func_ov023_021f9bc8(void*);

// USA: func_ov004_02156e2c
ARM int DispatchNodeIfType7_02156e2c(void* a, int key) {
    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, key);
    if (!node) return -1;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return -1;
    return (int)func_ov023_021f9bc8(node);
}
