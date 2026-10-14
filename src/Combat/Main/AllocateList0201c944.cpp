#include <globaldefs.h>
#include "World/ZoneFeatures.h"

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e480;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct GlobalList020fdc20_c944 {
    int pad0;
    SafeAllocator* alloc;
    struct Foo0201e480* array;
};
extern struct GlobalList020fdc20_c944 data_020fdc20;

// USA: func_0201c944
extern "C" ARM int _Z20WarpScript_Opcode_66PN6Script9ParameterEi(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    ((ZoneFeatures*)data_020fdc20.array)->AllocateOpcode66Entries(n, data_020fdc20.alloc);
    return 1;
}
