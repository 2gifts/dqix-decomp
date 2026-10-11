#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* list, int value);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
extern int ScaleStatsIfType12_021f6f10(void* self);
#endif

class VNode02187154 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22();
    virtual void Method5c(int a);
};

// USA: func_ov011_02187154
extern "C" ARM int func_ov011_02187154(struct TaggedNumber02184c30* a) {
    int val = GetTaggedValueAsInt_02184c30(a);
    int val2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    VNode02187154* node = (VNode02187154*)func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), val);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;
    node->Method5c(val2);
    return 1;
}
