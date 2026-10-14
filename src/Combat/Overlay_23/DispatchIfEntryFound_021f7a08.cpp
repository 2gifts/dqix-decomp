#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov011_021849d8(void* p);

struct List0202fe68;

struct List0202fec8;

char* FindEntryAndGetNext_020467c0(void* a, char* b, unsigned int* outSize);
extern "C" void func_ov023_021f7aac(void* obj, void* arg1, char* entry, unsigned int entryLength);

struct Obj021f7a08 {
    char pad0[0x10];
    char* f10;
};

// USA: func_ov023_021f7a08  (semantic: DispatchIfEntryFound_021f7a08)
extern "C" ARM void func_ov023_021f7a08(struct Obj021f7a08* obj, void* keyObj) {
    void* listPtr = (void*)(int)BackgroundLoader::GetInstance();
    int key = func_ov011_021849d8(keyObj);
    if (key < 0) {
        return;
    }
    if (!((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(key))) {
        return;
    }
    if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(key)) != 2) {
        return;
    }

    int out1, out2;
    ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(key), (void**)(&out1), (unsigned int*)(&out2));
    if (out1 == 0 || out2 == 0) {
        return;
    }

    unsigned int entryLength;
    char* entry = FindEntryAndGetNext_020467c0((void*)out1, obj->f10, &entryLength);
    if (entry == NULL) {
        return;
    }

    func_ov023_021f7aac(obj, keyObj, entry, entryLength);
}
