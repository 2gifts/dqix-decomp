#include <globaldefs.h>
#include "World/ZoneFeatures.h"

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e25c;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);

struct GlobalList020fdc20_c79c {
    int pad0;
    SafeAllocator* alloc;
    struct Foo0201e25c* array;
};
extern struct GlobalList020fdc20_c79c data_020fdc20;

// USA: func_0201c79c
extern "C" ARM int _Z20WarpScript_Opcode_64PN6Script9ParameterEi(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    ((ZoneFeatures*)data_020fdc20.array)->AllocateOpcode64Entries(n, data_020fdc20.alloc);
    return 1;
}
