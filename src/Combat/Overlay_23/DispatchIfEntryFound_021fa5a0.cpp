#include <globaldefs.h>

#if defined(jpn)
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov011_021849d8(void* p);

char* FindEntryAndGetNext(void* a, char* b, unsigned int* outSize);
extern "C" void func_ov023_021fa644(void* obj, void* arg1, char* entry, int entryLength);

struct Obj021fa5a0 {
    char pad0[0x10];
    char* f10;
};

// USA: func_ov023_021fa5a0  (semantic: DispatchIfEntryFound_021fa5a0)
extern "C" ARM void func_ov023_021fa5a0(struct Obj021fa5a0* obj, void* keyObj) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int key = func_ov011_021849d8(keyObj);
    if (key < 0) {
        return;
    }
    if (!loader->GetTaskStatus(key)) {
        return;
    }
    if (loader->GetDetailedTaskStatus(key) != BackgroundLoader::TaskStatus_Complete) {
        return;
    }

    void* fileData;
    unsigned int fileLength;
    loader->GetLoadedFileByID(key, &fileData, &fileLength);
    if (fileData == NULL || fileLength == 0) {
        return;
    }

    unsigned int entryLength;
    char* entry = FindEntryAndGetNext(fileData, obj->f10, &entryLength);
    if (entry == NULL) {
        return;
    }

    func_ov023_021fa644(obj, keyObj, entry, entryLength);
}
