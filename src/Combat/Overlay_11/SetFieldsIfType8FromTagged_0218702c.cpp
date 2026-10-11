#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z40InitTenAllocatorsAndClearFields_021e4e8cPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
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
extern "C" int func_ov023_021f6f10(void* self);
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
#else
extern int ScaleStatsIfType12_021f6f10(void* self);
#endif

struct Obj0218702c {
    char pad0[0x42];
    unsigned short field42;
    char pad1[1];
    unsigned char bit0:1;
    unsigned char field1_6:R(7, 6);
#if !defined(jpn)
    unsigned char bit7:1;
#endif
};

// USA: func_ov011_0218702c  (semantic: SetFieldsIfType8FromTagged_0218702c)
extern "C" ARM int func_ov011_0218702c(struct TaggedNumber02184c30* a) {
    int v0 = GetTaggedValueAsInt_02184c30(a);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)a + 0x10));
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021849c8(ctx);
    struct Obj0218702c* node = (struct Obj0218702c*)func_ov023_021f6880(obj, v0);
    if (!node) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 8) return 0;
    node->field1_6 = v1;
    node->field42 = (unsigned short)v2;
    return 1;
}
