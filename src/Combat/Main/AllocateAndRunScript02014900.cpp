#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void InitStruct02013454(char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
void* DecompressLZ77FileIntoScratchSpace(SafeAllocator& alloc, const void* src, unsigned int& outSize);
struct StreamHeader;
void RegisterAndRunBufferedScript0201f040(void* p0, void* p1, struct StreamHeader* headerIn, unsigned int countIn);

#if defined(jpn)
#define _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE func_020146cc
enum { kAllocatorOffset = 0x88, kListOffset = 0x43c };
#else
enum { kAllocatorOffset = 0x68, kListOffset = 0x41c };
#endif

// USA: func_02014900  (semantic: AllocateAndRunScript02014900)
extern "C" ARM int _ZN6Zone3D15ProcessBMDJFileEPKvjPN12ZoneFeatures13Opcode64EntryE(char* obj, const void* src, void* unused, int* pack) {
    SafeAllocator* alloc = *(SafeAllocator**)(obj + kAllocatorOffset);
    char* newObj = (char*)alloc->Allocate(0x58);
    if (!newObj) return 0;
    InitStruct02013454(newObj);
    *(int*)(newObj + 0x0) = pack[0];
    _ZN8Vector3iaSERKS_((int*)(newObj + 0x48), pack + 1);
    unsigned int count;
    void* data = DecompressLZ77FileIntoScratchSpace(*alloc, src, count);
    if (!data) return 0;
    RegisterAndRunBufferedScript0201f040(newObj + 4, alloc, (struct StreamHeader*)data, count);
    *(int*)(newObj + 0x54) = *(int*)(obj + kListOffset);
    *(int*)(obj + kListOffset) = (int)newObj;
    return 1;
}
