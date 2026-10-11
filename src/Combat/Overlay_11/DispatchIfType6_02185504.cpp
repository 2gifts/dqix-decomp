#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" int func_ov023_021f6f10(void* obj);
extern "C" void func_ov023_021f8120(void* obj);

// USA: func_ov011_02185504
ARM int DispatchIfType6_02185504(struct TaggedNumber02184c30* p) {
    int v = GetTaggedValueAsInt_02184c30(p);
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov023_021f6880(func_ov011_021849c8(ctx), v);
    if (obj == 0) return 0;
    if (func_ov023_021f6f10(obj) != 6) return 0;
    func_ov023_021f8120(obj);
    return 1;
}
