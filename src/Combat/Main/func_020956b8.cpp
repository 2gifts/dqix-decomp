#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"
#include "Resource/QuestScript.h"

extern short data_020f13d8;
extern const char data_020f1474[] __attribute__((aligned(4)));
extern Script::OpcodeLookupEntry data_020f141c[];

// USA: func_020956b8
extern "C" ARM void func_020956b8(struct Header020956b8* header, SafeAllocator* allocator) {
    unsigned int fileSize;

    if (allocator == 0) {
        return;
    }

    BackgroundLoader::AddLockGlobal();
    void* file = LoadFileIntoMemory(data_020f1474, data_0211e33c, &fileSize);
    if (file != 0) {
        data_02109404.f8 = 0;
        data_02109404.f3 = 0;
        data_02109404.f4 = 0;
        data_02109404.allocator = allocator;
        data_02109404.selected = 0;
        *(short*)0x020f13d8 = -1;
        header->listHead = 0;
        data_02109404.f0 = 0;
        Script runner;
        runner.Initialize();
        runner.SetOpcodeLookup(data_020f141c);
        runner.Load(file, fileSize);
        runner.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
