#if defined(jpn)
#define R(j,u) (j)
#define func_ov012_021845f8 func_ov011_021845f8
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" int func_ov012_021845f8(void* key, int val1);

struct Obj021844f4;
extern int AllocateAndStoreSize_021844f4(struct Obj021844f4* obj, int unused, unsigned int size);

// USA: func_ov011_021878dc  (semantic: AllocateSizedBufferFromTagged_021878dc)
extern "C" ARM int func_ov011_021878dc(struct TaggedNumber02184c30* a) {
    int val1 = GetTaggedValueAsInt_02184c30(a);
    int val2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    void* key = func_ov017_021b2164();
    if (func_ov012_021845f8(key, val1) == 0) return 0;
    AllocateAndStoreSize_021844f4((struct Obj021844f4*)key, val1, (unsigned int)val2);
    return 1;
}
