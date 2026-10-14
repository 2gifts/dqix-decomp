#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct Foo0201e518;
struct Variant02030b0c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Container0201cb38 {
    int f0;
    SafeAllocator* alloc;
    Foo0201e518* array;
};
extern Container0201cb38 data_020fdc20;

// USA: func_0201cb38
extern "C" ARM int _Z20WarpScript_Opcode_68PN6Script9ParameterEi(Variant02030b0c* p) {
    ((ZoneFeatures*)data_020fdc20.array)->AllocateOpcode68Entries(_ZNK6Script9Parameter5ToIntEv(p), data_020fdc20.alloc);
    return 1;
}
