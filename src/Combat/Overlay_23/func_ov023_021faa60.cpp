#include <globaldefs.h>

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

extern "C" int func_ov011_021849d8(void* p);

char* FindEntryAndGetNext_020467c0(void* a, char* b, unsigned int* outSize);

extern "C" void func_ov023_021fab48(void* obj, void* keyObj, const void* fileData, int fileLength);

struct Obj021faa60 {
    char pad0[0x10];
    char* entryName;
    char pad1c[0x1c - 0x14];
    int state;
};

// USA: func_ov023_021faa60
extern "C" ARM void func_ov023_021faa60(struct Obj021faa60* obj, void* keyObj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int taskId = func_ov011_021849d8(keyObj);
    if (taskId < 0) {
        return;
    }
    if (!loader->GetTaskStatus(taskId)) {
        return;
    }
    if (loader->GetDetailedTaskStatus(taskId) != BackgroundLoader::TaskStatus_Complete) {
        return;
    }

    void* fileData;
    unsigned int fileLength;
    loader->GetLoadedFileByID(taskId, &fileData, &fileLength);

    const void* entry;
    unsigned int entryLength;
    if (GetFileInNarc(fileData, obj->entryName, &entry, &entryLength, 0)) {
        func_ov023_021fab48(obj, keyObj, fileData, fileLength);
        obj->state = 2;
        return;
    }

    entry = FindEntryAndGetNext_020467c0(fileData, obj->entryName, &entryLength);
    if (entry == NULL) {
        return;
    }

    func_ov023_021fab48(obj, keyObj, fileData, fileLength);
    obj->state = 2;
}
