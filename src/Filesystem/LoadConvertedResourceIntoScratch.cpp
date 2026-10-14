#include <globaldefs.h>
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
extern "C" int func_020e12ec(char* destination, const char* source);
extern "C" int func_020da930(const char* filename, void* buffer,
    unsigned int* outLength, unsigned int capacity, bool flag);

// JPN: func_020e0968
extern "C" ARM void* func_020e0968(const char* filename, unsigned int* outLength) {
    if (filename == 0)
        return 0;
    char path[0x40];
    *outLength = 0;
    func_020e12ec(path, filename);
    BackgroundLoader::FreeAllocationsGlobal();
    func_020da930(path, data_0211e33c, outLength, sizeof(data_0211e33c), false);
    if (*outLength != 0)
        return data_0211e33c;
    return 0;
}
#endif
