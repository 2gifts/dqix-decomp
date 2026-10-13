#include <globaldefs.h>

#include "World/ZoneWarpScript.h"

extern Script::OpcodeLookupEntry data_020ef388[];

// USA: func_0201e1d0
ARM void ExecuteZoneWarpScript(const void* data, unsigned int length, ZoneFeatures* features, SafeAllocator* allocator) {
    if (length == 0) return;
    data_020fdc20.warp = features;
    data_020fdc20.allocator = allocator;
    data_020fdc20.currentEntry = 0;
    Script script;
    script.Initialize();
    script.SetOpcodeLookup(data_020ef388);
    script.Load(data, length);
    script.Execute();
    data_020fdc20.warp = 0;
    data_020fdc20.allocator = 0;
    data_020fdc20.currentEntry = 0;
}
