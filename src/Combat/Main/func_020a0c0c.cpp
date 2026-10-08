#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"

struct Struct02012dd0;
extern "C" unsigned int _Z19GetMaxAlloc02012dd0P14Struct02012dd0(struct Struct02012dd0* self);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
unsigned int LoadROMFilesystemFileTables(void* where, unsigned int capacity);
void CacheMainFileAccessors();

extern AllocatorUnion data_02114e20;
extern void* data_02109d90;

// USA: func_020a0c0c
extern "C" ARM void func_020a0c0c() {
    unsigned int max;
    void* tmp;
    BackgroundLoader* loader;
    unsigned int size;

    if (data_02109d90 != NULL)
        return;

    size = LoadROMFilesystemFileTables(NULL, 0);
    max = _Z19GetMaxAlloc02012dd0P14Struct02012dd0((Struct02012dd0*)&data_02114e20);
    if (size + 0x10 > max)
        return;

    loader = BackgroundLoader::GetInstance();
    if (loader != NULL)
        loader->AddLock();

    tmp = AllocateAligned4(&data_02114e20, max - (size + 0x10));
    data_02109d90 = AllocateAligned4(&data_02114e20, size);
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, tmp);

    if (data_02109d90 != NULL)
        LoadROMFilesystemFileTables(data_02109d90, size);

    if (loader != NULL)
        loader->RemoveLock();

    CacheMainFileAccessors();
}