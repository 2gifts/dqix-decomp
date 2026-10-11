#if defined(jpn)
#define R(j,u) (j)
#define _Z25TailCallOffset20_021fbddcPviii func_ov023_021fb158
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
#if defined(jpn)
#define TailCallOffset20_021fbddc func_ov023_021fb158
extern "C" int TailCallOffset20_021fbddc(void*, int, int, int);
#else
int TailCallOffset20_021fbddc(void*, int, int, int);
#endif

// USA: func_ov004_0216863c  (semantic: DispatchTailIfType16_0216863c)
extern "C" ARM int func_ov004_0216863c(void* a) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(a), 0x7);
    if (node) {
        if (ScaleStatsIfType12_021f6f10(node) == 0x10) {
            typedef void (*TailFn1)(void*);
            ((TailFn1)&TailCallOffset20_021fbddc)(node);
        }
    }
    return 0;
}
