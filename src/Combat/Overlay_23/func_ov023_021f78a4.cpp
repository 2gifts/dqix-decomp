#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f6bb8(void* obj);
extern "C" void func_ov023_021f6bb0(void* obj, int v);

struct List0202fe68;

struct List0202fec8;

extern "C" void func_ov023_021f7b98(void* obj, void* ctx, int flag, int v1, int v2);
extern "C" void func_0204b088(void* p, int flag);

struct Obj021f78a4 {
    char pad0[0xc];
    unsigned char flags0xc;
    char pad0d[0x1c - 0xd];
    int field1c;
    void* field20;
};

// JPN: func_ov023_021f6d9c
// USA: func_ov023_021f78a4
extern "C" ARM void func_ov023_021f78a4(struct Obj021f78a4* obj) {
#if defined(jpn)
 enum {regionalOffset=0x24};
#else
 enum {regionalOffset=0x28};
#endif
    if (obj->flags0xc & 0x2) {
        void* ctx = obj->field20;
        void* node = func_ov011_021849c8(ctx);
        int listPtr = (int)BackgroundLoader::GetInstance();
        int key = func_ov023_021f6bb8(node);
        if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(key))) {
            if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(key)) == 2) {
                int v1, v2;
                ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
                if (v1 != 0 && v2 != 0) {
                    func_ov023_021f7b98(obj, ctx, 0, v1, v2);
                }
            }
            ((BackgroundLoader*)(listPtr))->RemoveTask((int)(key));
            func_ov023_021f6bb0(node, -1);
            obj->field1c = 2;
        }
    }

    if (!(obj->flags0xc & 0x1)) {
        func_0204b088((char*)obj + regionalOffset, 0);
    }
}
