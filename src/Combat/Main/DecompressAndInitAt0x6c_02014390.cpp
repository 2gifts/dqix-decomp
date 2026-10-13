#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_02014390
ARM int Zone3D::ProcessBMBLFile(const void* source, unsigned int sourceLength) {
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    Zone3D_StructPtr_8* map = pUnknownStruct_8_;
    ZoneFeatures* features = reinterpret_cast<ZoneFeatures*>(substruct_6c_);
    features->Reset();
    features->LoadFromScript(allocator, script, size);
    pUnknownStruct_8_ = map;
    return 1;
}
