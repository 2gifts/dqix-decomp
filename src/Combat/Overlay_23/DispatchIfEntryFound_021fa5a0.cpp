#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021fa5a0 func_ov023_021f99c8
#endif
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov011_021849d8(void* p);

struct List0202fe68;

struct List0202fec8;

char* FindEntryAndGetNext(void* a, char* b, void** outField44);
extern "C" void func_ov023_021fa644(void* obj, void* arg1, char* entry, void* next);

struct Obj021fa5a0 {
    char pad0[0x10];
    char* f10;
};

// USA: func_ov023_021fa5a0  (semantic: DispatchIfEntryFound_021fa5a0)
extern "C" ARM void func_ov023_021fa5a0(struct Obj021fa5a0* obj, void* keyObj) {
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

    void* next;
    char* entry = FindEntryAndGetNext((void*)out1, obj->f10, &next);
    if (entry == NULL) {
        return;
    }

    func_ov023_021fa644(obj, keyObj, entry, next);
}
