#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/MonsterDefinition.h"

extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

#if defined(jpn)
#include "Filesystem/FileIO.h"
extern char data_020f0bc0;
#endif

extern char data_020f0a64;
extern char data_020f0a7a;

// USA: func_0206efd8
// KEEP-NAME
extern "C" ARM void _Z28LockedLookupDispatch0206efd8PvS_(void* a, void* b) {
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
#if defined(jpn)
    LoadFileIntoMemory(&data_020f0bc0, data_0211e33c, &size);
    void* data = data_0211e33c;
#else
    void* data = ExtractFileFromGP2(&data_020f0a64, &data_020f0a7a, &size);
#endif
    func_0206f01c(static_cast<List0206f170*>(a), static_cast<SafeAllocator*>(b),
                   static_cast<Src0206f170*>(data), size);
    BackgroundLoader::RemoveLockGlobal();
}
