#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Filesystem/NarcHandle.h"

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
void LoadEightEntriesFromTable(char*, void*, void*);

extern AllocatorUnion data_02114e20;
extern char data_020ef7ac[];
extern char data_0211e33c[];
extern char data_020ef7c0[];

struct EntryTable0202f24c {
    char pad0[0x444];
    class SafeAllocator* alloc;
};

// USA: func_0202f24c  (semantic: InitIconArchiveAndLoadEntries_0202f24c)
extern "C" ARM void func_0202f24c(struct EntryTable0202f24c* obj) {
    if (obj->alloc == 0) {
        obj->alloc = (class SafeAllocator*)AllocateAligned4(&data_02114e20, 0x14);
        obj->alloc->ResetAllocatorPointer();
        void* buf = AllocateAligned4(&data_02114e20, 0xf08);
        obj->alloc->CreateTypeA(buf, 0xf08);
        obj->alloc->Reset();
    } else {
        obj->alloc->Reset();
    }
    BackgroundLoader::AddLockGlobal();

    unsigned int size;
    void* fileData = LoadFileIntoMemory(data_020ef7ac, data_0211e33c, &size);
    if (fileData != 0) {
        NarcHandle handle;
        if (handle.Initialize(data_020ef7c0, (const unsigned char*)fileData)) {
            LoadEightEntriesFromTable((char*)obj, obj->alloc, fileData);
            handle.Destroy();
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
