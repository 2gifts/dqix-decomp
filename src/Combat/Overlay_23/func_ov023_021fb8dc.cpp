#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"

extern "C" int func_ov011_021849d8(void* p);

struct List0202fe68;

struct List0202fec8;

char* FindEntryAndGetNext(void* a, char* b, void** outField44);

extern "C" void func_ov023_021fb9c4(void* obj, void* keyObj, int out1, int out2);

struct Obj021fb8dc {
    char pad0[0x10];
    char* f10;
    char pad1c[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021fb8dc
extern "C" ARM void func_ov023_021fb8dc(struct Obj021fb8dc* obj, void* keyObj) {
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

    void* p;
    unsigned int n;
    if (GetFileInNarc((void*)out1, obj->f10, (const void**)&p, &n, 0)) {
        func_ov023_021fb9c4(obj, keyObj, out1, out2);
        obj->field1c = 2;
        return;
    }

    p = FindEntryAndGetNext((void*)out1, obj->f10, (void**)&n);
    if (p == NULL) {
        return;
    }

    func_ov023_021fb9c4(obj, keyObj, out1, out2);
    obj->field1c = 2;
}
