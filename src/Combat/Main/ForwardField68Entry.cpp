#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_020143d8
ARM int Zone3D::ProcessBPOSFile(const void* source, unsigned int sourceLength) {
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    Zone3D_StructPtr_8* map = pUnknownStruct_8_;
    ZoneFeatures* features = reinterpret_cast<ZoneFeatures*>(substruct_6c_);
    features->LoadFromScript(allocator, script, size);
    pUnknownStruct_8_ = map;
    return 1;
}
