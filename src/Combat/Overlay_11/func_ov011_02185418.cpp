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

struct TaggedInput_02185418 {
    TaggedNumber02184c30 f0;
    TaggedNumber02184c30 f8;
    TaggedNumber02184c30 f10;
    TaggedNumber02184c30 f18;
    TaggedNumber02184c30 f20;
    TaggedNumber02184c30 f28;
    TaggedNumber02184c30 f30;
    TaggedNumber02184c30 f38;
    TaggedNumber02184c30 f40;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* obj, int v);
extern "C" ARM int func_ov023_021f6f10(void* self);
extern "C" ARM void func_ov023_021f7eb8(void* node, void* a, int buf, int mode, int a5, int a6, int a7, int a8, int a9, int a10);

struct Obj_02184ad8 { char pad[0x1c8]; int field1c8; };
ARM void SetField1c8True_02184ad8(struct Obj_02184ad8* obj);

// USA: func_ov011_02185418
extern "C" ARM int func_ov011_02185418(struct TaggedInput_02185418* obj) {
    int val1;
    int val0 = GetTaggedValueAsInt_02184c30(&obj->f0);
    val1 = GetTaggedValueAsInt_02184c30(&obj->f8);
    short val2 = (short)GetTaggedValueAsInt_02184c30(&obj->f10);
    short val3 = (short)GetTaggedValueAsInt_02184c30(&obj->f18);
    short val4 = (short)GetTaggedValueAsInt_02184c30(&obj->f20);
    short val5 = (short)GetTaggedValueAsInt_02184c30(&obj->f28);
    unsigned char val6 = (unsigned char)GetTaggedValueAsInt_02184c30(&obj->f30);
    unsigned char val7 = (unsigned char)GetTaggedValueAsInt_02184c30(&obj->f38);
    int flag = GetTaggedValueAsInt_02184c30(&obj->f40) != 0;

    void* x = func_ov017_021b2164();
    void* list = func_ov011_021849c8(x);
    void* node = func_ov023_021f6880(list, val0);
    if (node == 0) return 0;

    if (func_ov023_021f6f10(node) != 6) return 0;

    func_ov023_021f7eb8(node, x, val1, val2, val3, val4, val5, val6, val7, flag);
    SetField1c8True_02184ad8((struct Obj_02184ad8*)x);
    return 1;
}
