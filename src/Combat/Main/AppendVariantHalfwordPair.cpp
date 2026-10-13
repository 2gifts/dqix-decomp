#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct HalfwordPair {
    unsigned short a;
    unsigned short b;
};
struct BoundedHalfwordPairList;
void AppendHalfwordPairCapped(struct BoundedHalfwordPairList* list, struct HalfwordPair* src);

struct Global020fdd30_800c {
    struct BoundedHalfwordPairList* list;
};
extern struct Global020fdd30_800c data_020fdd30;

// USA: func_0202800c
ARM int AppendVariantHalfwordPair(struct Variant02030b0c* v) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(v);
    struct HalfwordPair pair;
    int a = parameters[0].ToInt();
    int b = parameters[1].ToInt();
    pair.a = a;
    pair.b = b;
    AppendHalfwordPairCapped(data_020fdd30.list, &pair);
    return 1;
}
