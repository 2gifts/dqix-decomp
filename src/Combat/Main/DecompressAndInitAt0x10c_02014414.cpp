#include <globaldefs.h>
#include "World/Zone3D.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& allocator, const void* source, unsigned int& size);

// USA: func_02014414
extern "C" ARM int _ZN6Zone3D15ProcessBATSFileEPKvj(Zone3D* zone, const void* source) {
    SafeAllocator* allocator = zone->pAllocator_68_;
    unsigned int size;
    void* script = DecompressLZ77FileIntoScratchSpace(*allocator, source, size);
    zone->lighting_.Initialize();
    zone->lighting_.LoadFromScript(script, size, allocator);
    return 1;
}
