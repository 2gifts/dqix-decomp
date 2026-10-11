#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void*);
struct ObjE2_021f8944;
extern "C" struct ObjE2_021f8944* func_ov023_021f6880(void*, int);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
void SetFieldE2AndMaybeCall_021f8944(struct ObjE2_021f8944* obj, int a1, int a2, int a3);

// USA: func_ov011_0218735c  (semantic: AllocateNodeAndSetFieldE2_0218735c)
extern "C" ARM int func_ov011_0218735c(struct TaggedNumber02184c30* p) {
    int v = GetTaggedValueAsInt_02184c30(p);
    int b = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)p + 8)) & 0xff;
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct ObjE2_021f8944* node = func_ov023_021f6880(obj, v);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 6) return 0;
    SetFieldE2AndMaybeCall_021f8944(node, (int)(long)ctx, b, 1);
    return 1;
}
