#include <globaldefs.h>
#include "Combat/BufferedScriptResult.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

#if defined(jpn)
#define data_020f0d40 data_020f0e38
#endif

extern char data_020f0d40[];
extern unsigned char data_0211e33c[];

// KEEP-NAME
// USA: func_02074114
ARM int TryDecodeGlobalBitstreamEntry_02074114(BufferedScriptResult* result, int key) {
    unsigned int length;
    BackgroundLoader::AddLockGlobal();
    void* bytecode = LoadFileIntoMemory(data_020f0d40, data_0211e33c, &length);
    if (bytecode != 0) {
        RunBufferedStream0207416c(result, key, bytecode, length);
        BackgroundLoader::RemoveLockGlobal();
        return 1;
    }
    BackgroundLoader::RemoveLockGlobal();
    return 0;
}
