#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* obj, int key);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
extern int ScaleStatsIfType12_021f6f10(void* self);
#endif

struct Obj021fb25c;
extern "C" void _Z18SetShorts_021fb25cP11Obj021fb25cttti(struct Obj021fb25c* obj, unsigned int a1, unsigned int a2, unsigned int a3, int a4);

// USA: func_ov011_02187570  (semantic: SetShortsIfType1FromTagged_02187570)
extern "C" ARM int func_ov011_02187570(struct TaggedNumber02184c30* a) {
    int v0 = GetTaggedValueAsInt_02184c30(a);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x18));
    int v4 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x20));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct Obj021fb25c* node = (struct Obj021fb25c*)func_ov023_021f6880(obj, v0);
    if (!node) return 1;
    if (ScaleStatsIfType12_021f6f10(node) != 1) return 1;
    _Z18SetShorts_021fb25cP11Obj021fb25cttti(node, v1, v2, v3, v4);
    return 1;
}
