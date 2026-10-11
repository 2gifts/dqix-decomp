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
extern "C" void* func_ov023_021f6880(void** list, int value);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
extern int ScaleStatsIfType12_021f6f10(void* self);
#endif

struct Fields021849e0 { char pad[0x1b0]; unsigned short field1b0; char pad2[0x1c8-0x1b2]; int field1c8; };
extern void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);

// USA: func_ov011_021858f4  (semantic: SetFieldFromTaggedIfNodeType7_021858f4)
extern "C" ARM int func_ov011_021858f4(struct TaggedNumber02184c30* a) {
    int val = GetTaggedValueAsInt_02184c30(a);
    void* key = func_ov017_021b2164();
    void** list = (void**)func_ov011_021849c8(key);
    void* node = func_ov023_021f6880(list, val);
    if (node == 0) return 0;
    if (ScaleStatsIfType12_021f6f10(node) != 7) return 0;
    SetFieldConditional_021849e0((struct Fields021849e0*)key, (unsigned short)val);
    return 1;
}
