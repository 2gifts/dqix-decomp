#include <globaldefs.h>
#include "World/ZoneFeatures.h"
#include "Resource/Script.h"

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e25c;

struct GlobalList020fdc20_c79c {
    int pad0;
    SafeAllocator* alloc;
    struct Foo0201e25c* array;
};
extern struct GlobalList020fdc20_c79c data_020fdc20;

// USA: func_0201c79c
ARM int WarpScript_Opcode_64(Script::Parameter* arg0, int) {
    struct Variant02030b0c* v = (struct Variant02030b0c*)arg0;
    int n = ((Script::Parameter*)v)->ToInt();
    ((ZoneFeatures*)data_020fdc20.array)->AllocateOpcode64Entries(n, data_020fdc20.alloc);
    return 1;
}
