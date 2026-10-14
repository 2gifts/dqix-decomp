#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

struct Struct02070a30;
void InitListBuffers02070a30(Struct02070a30*, SafeAllocator*, void*, unsigned int);

extern char data_020f0b64;

// USA: func_020709ec
// KEEP-NAME
ARM void LockedLookupDispatch020709ec(void* destination, void* allocator) {
    unsigned int size;
    BackgroundLoader::AddLockGlobal();
    void* buf = LoadFileIntoMemory(&data_020f0b64, data_0211e33c, &size);
    InitListBuffers02070a30(static_cast<Struct02070a30*>(destination),
                           static_cast<SafeAllocator*>(allocator), buf, size);
    BackgroundLoader::RemoveLockGlobal();
}
