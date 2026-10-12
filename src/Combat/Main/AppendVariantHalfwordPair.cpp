#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};
struct HalfwordPair {
    unsigned short a;
    unsigned short b;
};
struct BoundedHalfwordPairList;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
void AppendHalfwordPairCapped(struct BoundedHalfwordPairList* list, struct HalfwordPair* src);

struct Global020fdd30_800c {
    struct BoundedHalfwordPairList* list;
};
extern struct Global020fdd30_800c data_020fdd30;

#if defined(jpn)
#define AppendVariantHalfwordPair func_02027878
extern "C" ARM int AppendVariantHalfwordPair(struct Variant02030b0c* v);
#endif

// USA: func_0202800c
ARM int AppendVariantHalfwordPair(struct Variant02030b0c* v) {
    struct HalfwordPair pair;
    int a = _ZNK6Script9Parameter5ToIntEv(v);
    int b = _ZNK6Script9Parameter5ToIntEv(v + 1);
    pair.a = a;
    pair.b = b;
    AppendHalfwordPairCapped(data_020fdd30.list, &pair);
    return 1;
}
