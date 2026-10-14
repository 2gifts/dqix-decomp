#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"
#include "Resource/Script.h"

struct List0201e634;
struct Variant02030b0c;

struct Container0201d01c {
    int f0;
    SafeAllocator* alloc;
    List0201e634* list;
};
extern Container0201d01c data_020fdc20;

// USA: func_0201d01c
ARM int WarpScript_Opcode_6a(Script::Parameter* arg0, int) {
    Variant02030b0c* p = (Variant02030b0c*)arg0;
    ((ZoneFeatures*)data_020fdc20.list)->AllocateOpcode6aEntries(((Script::Parameter*)p)->ToInt(), data_020fdc20.alloc);
    return 1;
}
