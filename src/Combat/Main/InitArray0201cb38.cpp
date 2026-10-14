#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"
#include "Resource/Script.h"

struct Foo0201e518;
struct Variant02030b0c;

struct Container0201cb38 {
    int f0;
    SafeAllocator* alloc;
    Foo0201e518* array;
};
extern Container0201cb38 data_020fdc20;

// USA: func_0201cb38
ARM int WarpScript_Opcode_68(Script::Parameter* arg0, int) {
    Variant02030b0c* p = (Variant02030b0c*)arg0;
    ((ZoneFeatures*)data_020fdc20.array)->AllocateOpcode68Entries(((Script::Parameter*)p)->ToInt(), data_020fdc20.alloc);
    return 1;
}
