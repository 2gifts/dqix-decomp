#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Filesystem/FileIO.h"

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void ZeroInit020de848(void* obj);

extern "C" void* func_020de9a4(void* a, void* b, void* c, unsigned int d, int e, unsigned int f);

#if defined(jpn)
extern "C" void func_020e0484(void*, SafeAllocator*, char*, int, unsigned int, int);
#endif
extern AllocatorUnion data_02114e20;
extern char* data_020f2a38;
extern char* data_020f2a30;

// USA: func_0207d6dc
ARM void* InitAllocatorAndLoadGp2File0207d6dc(SafeAllocator* self, int param1, int param2) {
    unsigned int allocSize = (unsigned int)param2 << 8;
    void* mem = AllocateAligned4_02012d88(&data_02114e20, allocSize);
    self->CreateTypeA(mem, allocSize);
    self->Reset();
    ZeroInit020de848((char*)self + 0x14);
#if defined(jpn)
    func_020e0484((char*)self + 0x14, self, data_020f2a38, param1, (unsigned int)param2 & 0xffff, 1);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int fileSize = 0;
    void* fileData = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &fileSize);
    if (fileData != NULL) {
        func_020de9a4((char*)self + 0x14, self, fileData, fileSize, param1, (unsigned int)param2 & 0xffff);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    *(void**)((char*)self + 0x2c) = (char*)self + 0x14;
    return (char*)self + 0x14;
}
