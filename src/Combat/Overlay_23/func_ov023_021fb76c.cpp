#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void* ctx);

struct List0202fe68;

struct List0202fec8;

extern "C" {
    int func_ov023_021f6bb8(void* obj);
    void func_ov023_021f6bb0(void* obj, int v);
    void func_ov023_021fb9c4(void* obj, void* ctx, int p2, int p3);
}

struct Obj021fb76c {
    char pad[0x1c];
    int field1c;
};

// USA: func_ov023_021fb76c  (semantic: DispatchOrReturnField1c_021fb76c)
extern "C" ARM int func_ov023_021fb76c(struct Obj021fb76c* obj, void* ctx) {
    void* node = func_ov011_021849c8(ctx);
    int listPtr = (int)BackgroundLoader::GetInstance();
    int key = func_ov023_021f6bb8(node);
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(key))) {
        if (((BackgroundLoader*)((struct List0202fe68*)listPtr))->GetDetailedTaskStatus((int)(key)) == 2) {
            int v1, v2;
            ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(key), (void**)(&v1), (unsigned int*)(&v2));
            func_ov023_021fb9c4(obj, ctx, v1, v2);
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(key));
        func_ov023_021f6bb0(node, -1);
        return 2;
    }
    return obj->field1c;
}
