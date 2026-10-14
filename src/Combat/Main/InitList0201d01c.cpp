#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct List0201e634;
struct Variant02030b0c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Container0201d01c {
    int f0;
    SafeAllocator* alloc;
    List0201e634* list;
};
extern Container0201d01c data_020fdc20;

// USA: func_0201d01c
extern "C" ARM int _Z20WarpScript_Opcode_6aPN6Script9ParameterEi(Variant02030b0c* p) {
    ((ZoneFeatures*)data_020fdc20.list)->AllocateOpcode6aEntries(_ZNK6Script9Parameter5ToIntEv(p), data_020fdc20.alloc);
    return 1;
}
