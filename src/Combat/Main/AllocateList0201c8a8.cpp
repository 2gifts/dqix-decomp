#include <globaldefs.h>
#include "World/ZoneFeatures.h"

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e288;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct GlobalList020fdc20_c8a8 {
    int pad0;
    SafeAllocator* alloc;
    struct Foo0201e288* array;
};
extern struct GlobalList020fdc20_c8a8 data_020fdc20;

// USA: func_0201c8a8
extern "C" ARM int _Z20WarpScript_Opcode_7dPN6Script9ParameterEi(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    ((ZoneFeatures*)data_020fdc20.array)->AllocateGrottoTileFeaturePlacementEntries(n, data_020fdc20.alloc);
    return 1;
}
