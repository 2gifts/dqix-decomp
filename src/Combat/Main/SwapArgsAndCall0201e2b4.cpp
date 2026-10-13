#include <globaldefs.h>
#include "World/ZoneWarpScript.h"


// USA: func_0201e2b4
ARM void ZoneFeatures::LoadFromScript(SafeAllocator* allocator, const void* script, unsigned int length) {
    ExecuteZoneWarpScript(script, length, this, allocator);
}
