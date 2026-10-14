#include <globaldefs.h>
#include "World/Zone3D.h"
#include "World/ZoneFeatures.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_02014390
ARM int Zone3D::ProcessBMBLFile_02014390(const void* source, unsigned int sourceLength) {
    SafeAllocator* allocator = pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    Zone3D_StructPtr_8* map = pUnknownStruct_8_;
    substruct_6c_.Reset();
    substruct_6c_.LoadFromScript_0201e2b4(allocator, script, size);
    pUnknownStruct_8_ = map;
    return 1;
}
