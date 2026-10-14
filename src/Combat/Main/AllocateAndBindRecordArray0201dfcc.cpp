#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"
#include "World/ZoneWarpScript.h"

struct Variant02030b0c;

// USA: func_0201dfcc
ARM int WarpScript_Opcode_7b_0201dfcc(Script::Parameter* arg0, int) {
    struct Variant02030b0c* variant = (struct Variant02030b0c*)arg0;
    unsigned int count = ((Script::Parameter*)variant)->ToInt();
    ZoneFeatures::Opcode7bEntry* p = (ZoneFeatures::Opcode7bEntry*)data_020fdc20.allocator->Allocate(count * sizeof(ZoneFeatures::Opcode7bEntry));
    if (p == NULL) return 0;
    data_020fdc20.warp->SetOpcode7bAllocation_0201e878(p, count);
    return 1;
}
