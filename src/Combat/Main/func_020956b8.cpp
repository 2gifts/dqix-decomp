#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"
#include "Resource/QuestScript.h"

struct DataStruct02109404_956b8 {
    unsigned char f0;
    unsigned char skip;
    unsigned char selected;
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5;
    unsigned short index;
    unsigned short f8;
    unsigned char padA[2];
    SafeAllocator* allocator;
    unsigned char* table;
};
extern struct DataStruct02109404_956b8 data_02109404;

extern short data_020f13d8;
extern const char data_020f1474[] __attribute__((aligned(4)));
extern Script::OpcodeLookupEntry data_020f141c[];

struct Node020958fc;
struct Header020956b8 {
    char pad[0xa0];
    Node020958fc* listHead;
};

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
