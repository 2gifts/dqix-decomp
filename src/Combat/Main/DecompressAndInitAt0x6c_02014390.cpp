#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_02014390
extern "C" ARM int _ZN6Zone3D15ProcessBMBLFileEPKvj(Zone3D* zone, const void* source) {
    SafeAllocator* allocator = zone->pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    Zone3D_StructPtr_8* map = zone->pUnknownStruct_8_;
    ZoneFeatures* features = reinterpret_cast<ZoneFeatures*>(zone->substruct_6c_);
    features->Reset();
    features->LoadFromScript(allocator, script, size);
    zone->pUnknownStruct_8_ = map;
    return 1;
}
