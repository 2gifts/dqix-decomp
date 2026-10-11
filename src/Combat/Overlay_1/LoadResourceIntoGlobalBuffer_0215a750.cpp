#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_0211e33c[];

// USA: func_ov001_0215a750
ARM unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr) {
    BackgroundLoader::AddLockGlobal();
    unsigned int size = 0;
    void* result = LoadFileIntoMemory(path, data_0211e33c, &size);
    if (result == NULL) return 0;
    BackgroundLoader::RemoveLockGlobal();
    *outPtr = data_0211e33c;
    return size;
}
