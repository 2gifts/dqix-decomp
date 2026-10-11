#if defined(jpn)
#define R(j,u) (j)
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
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void* obj);

struct Obj021f79ec;
void SetFieldAndFlags3_021f79ec(struct Obj021f79ec* obj, void* v);

// USA: func_ov011_02186f08  (semantic: SetField10AndFlags3IfType2_02186f08)
extern "C" ARM int func_ov011_02186f08(struct TaggedNumber02184c30* a) {
    int key = GetTaggedValueAsInt_02184c30(a);
    struct TaggedNumber02184c30* b = (struct TaggedNumber02184c30*)((char*)a + 8);
    void* val = (b->type == 2) ? (void*)b->value.i : 0;
    if (!val) return 0;
    void* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 2) return 0;
    SetFieldAndFlags3_021f79ec((struct Obj021f79ec*)node, val);
    return 1;
}
