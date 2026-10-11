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
struct Obj021f9bb0;
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);

// USA: func_ov004_021634dc
ARM int GetScaledStat_021634dc_021634dc(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0xa);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;
    short s = *(short*)((char*)node + 0x5c);
    return GetShort28_021f9bb0((struct Obj021f9bb0*)node) + (s << 3);
}
