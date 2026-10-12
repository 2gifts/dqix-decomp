#include <globaldefs.h>

#if defined(jpn)
#define _ZN6Zone3D15ProcessBATSFileEPKvj func_020141e0
enum { AllocatorOffset = 0x88, SubobjectOffset = 0x12c };
#else
enum { AllocatorOffset = 0x68, SubobjectOffset = 0x10c };
#endif
#include "Graphics/LightingInfo.h"
#include "Memory/SafeAllocator.h"

void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& alloc, const void* src, unsigned int& outSize);

// USA: func_02014414
extern "C" ARM int _ZN6Zone3D15ProcessBATSFileEPKvj(char* obj, const void* src) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + AllocatorOffset);
    unsigned int size;
    void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, size);
    ((LightingInfo*)(obj + SubobjectOffset))->Initialize();
    ((LightingInfo*)((int)(obj + SubobjectOffset)))->LoadFromScript((const void*)((int)data), (unsigned int)((int)size), (SafeAllocator*)((int)alloc));
    return 1;
}
