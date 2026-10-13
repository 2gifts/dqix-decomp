#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

#if defined(jpn)
#define data_020f14b0 data_020f15fc
#endif

extern char data_020f14b0[] __attribute__((aligned(4)));
extern Script::OpcodeLookupEntry data_020f1444[];

struct Manager02109404 {
    char pad[0x10];
    char* f10;
};
extern struct Manager02109404 data_02109404;

// USA: func_02096524
extern "C" ARM void func_02096524(char* ctx) {
    unsigned int count;
    Script script;

    BackgroundLoader::AddLockGlobal();
    void* header = LoadFileIntoMemory(data_020f14b0, data_0211e33c, &count);
    if (header != 0) {
        char* slot = ctx + 0xac;
        struct Manager02109404* manager = &data_02109404;
        manager->f10 = slot;
        unsigned int len = count;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1444);
        script.Load(header, len);
        script.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
