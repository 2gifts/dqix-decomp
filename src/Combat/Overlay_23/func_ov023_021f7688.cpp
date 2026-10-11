#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj021f7ca0;
extern "C" void func_ov023_021f7ca0(struct Obj021f7ca0* obj, void* keyObj);

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

struct List0202fe68;

struct List0202fec8;


struct Obj021f7aac;
struct Rec020467f0;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct Rec020467f0* entry, void* next);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct Rec020467f0* entry, void* next);

struct Obj021f7688 {
    char pad0[0xc];
    unsigned char fieldC;
    char pad0d[0x10 - 0xd];
    int field10;
    char pad14[0x1c - 0x14];
    int field1c;
};

// USA: func_ov023_021f7688
extern "C" ARM int func_ov023_021f7688(struct Obj021f7688* obj, void* keyObj) {
    if (obj->field10 == 0) {
        func_ov023_021f7ca0((struct Obj021f7ca0*)obj, keyObj);
        return 2;
    }

    void* node = func_ov011_021849c8(keyObj);
    int listPtr = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    int result;
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            if (v1 != 0 && v2 != 0) {
                if (obj->fieldC & 0x2) {
                    func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, (struct Rec020467f0*)v1, (void*)v2);
                } else {
                    func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, (struct Rec020467f0*)v1, (void*)v2);
                }
            }
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        result = 2;
    } else {
        result = obj->field1c;
    }
    return result;
}
