#include <globaldefs.h>
#include "World/ZoneWarpScript.h"

// USA: func_0201e2b4
ARM void ZoneFeatures::LoadFromScript_0201e2b4(SafeAllocator* allocator, const void* script, unsigned int length) {
    ExecuteZoneWarpScript_0201e1d0(script, length, this, allocator);
}
