#include <globaldefs.h>
#include "Resource/Script.h"
#include "World/GrottoTileGraph.h"

struct Variant02030b0c;
struct BoundedHalfwordPairList;
void AppendHalfwordPairCapped_02028378(struct BoundedHalfwordPairList* list, struct HalfwordPair* src);

struct Global020fdd30_800c {
    struct BoundedHalfwordPairList* list;
};
extern struct Global020fdd30_800c data_020fdd30;

// USA: func_0202800c
ARM int AppendVariantHalfwordPair_0202800c(struct Variant02030b0c* v) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(v);
    struct HalfwordPair pair;
    int a = parameters[0].ToInt();
    int b = parameters[1].ToInt();
    pair.first = a;
    pair.second = b;
    AppendHalfwordPairCapped_02028378(data_020fdd30.list, &pair);
    return 1;
}
