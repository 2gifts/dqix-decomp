#include <globaldefs.h>

#if defined(jpn)
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void* func_020e21e8(const char* tablePath, unsigned int* outSize, int variant);
extern "C" int func_020e0028(void* texts, SafeAllocator* allocator, void* data,
    unsigned int size, short* ids, unsigned short count);

// JPN: func_020e1fc4
extern "C" ARM int func_020e1fc4(void* texts, SafeAllocator* allocator,
    const char* tablePath, short* ids, unsigned short count, short variant, bool lock) {
    if (lock)
        BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* data = func_020e21e8(tablePath, &size, variant);
    int result = func_020e0028(texts, allocator, data, size, ids, count);
    if (lock)
        BackgroundLoader::RemoveLockGlobal();
    return result;
}
#endif
