#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

extern "C" void __clear(void* buf, int count);
extern "C" int func_02001aec(const void* a, const void* b, unsigned int length);

extern char data_020f12b8[];
extern char data_020f12bf[];
extern char data_020f12d3[];
extern char data_020f12e1[];
extern char data_020f12fb[];
extern Script::OpcodeLookupEntry data_020f1278[];
extern Script::OpcodeLookupEntry data_020f1290[];

struct Obj0208e4f8 {
    char field0[4];
    int field4;
    short field8;
    unsigned char fielda;
};

void ResetAllocatorAndClearState(struct Obj0208e4f8*);

// USA: func_0208e520
extern "C" ARM void func_0208e520(struct Obj0208e4f8* p, char* name) {
    char path[0x40];
    unsigned int len;
    char tag[4];
    unsigned int fileLen;
    const void* fileData;

    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
        return;
    }
    BackgroundLoader::AddLockGlobal();
    len = 0;
    if (func_02001aec(name, data_020f12b8, 6) == 0 && func_02001aec(name, p->field0, 3) != 0 &&
        LoadFileIntoMemory(data_020f12bf, data_0211e33c, &len)) {
        ResetAllocatorAndClearState(p);
        Script scriptC;
        scriptC.Initialize();
        scriptC.SetOpcodeLookup(data_020f1278);
        scriptC.Load(data_0211e33c, len);
        scriptC.Execute();
        strncpy(p->field0, name, 3);
    }
    if (name[0] != 'F') {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    if (func_02001aec(name, p->field0, 3) == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }
    __clear(tag, 4);
    strncpy(tag, name, 3);
    __clear(path, 0x40);
    sprintf(path, data_020f12d3, tag);
    if (LoadFileIntoMemory(data_020f12e1, data_0211e33c, &len)) {
        if (p->fielda == 0 && GetFileInNarc(data_0211e33c, data_020f12fb, &fileData, &fileLen, 0)) {
            Script scriptB;
            scriptB.Initialize();
            scriptB.SetOpcodeLookup(data_020f1290);
            scriptB.Load(fileData, fileLen);
            scriptB.Execute();
            p->fielda = 1;
        }
        ResetAllocatorAndClearState(p);
        if (GetFileInNarc(data_0211e33c, path, &fileData, &fileLen, 0)) {
            Script scriptA;
            scriptA.Initialize();
            scriptA.SetOpcodeLookup(data_020f1290);
            scriptA.Load(fileData, fileLen);
            scriptA.Execute();
        }
        strcpy(p->field0, tag);
    }
    BackgroundLoader::RemoveLockGlobal();
}
