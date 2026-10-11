#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


struct List0202fec8;

extern "C" {
    void func_020df850(void* a, void* b, int out1, int out2, int fifth);
}

struct Obj021e0b9c {
    char pad28[0x28];
    int field28;
    char pad4c[0x4c - 0x2c];
    void* field4c;
    char pad7c[0x7c - 0x50];
    int field7c;
#if defined(jpn)
    char pad74c[0x6c8 - 0x80];
#else
    char pad74c[0x74c - 0x80];
#endif

    int handle;
};

// JPN: func_ov023_021e10f0
// USA: func_ov023_021e0b9c  (semantic: ApplyAndClearListEntry_021e0b9c)
extern "C" ARM int func_ov023_021e0b9c(struct Obj021e0b9c* obj) {
    if (obj->handle == -1) {
        return -1;
    }

    int listPtr = (int)BackgroundLoader::GetInstance();
    if (((BackgroundLoader*)(listPtr))->GetTaskStatus((int)(obj->handle))) {
        int out1, out2;
        ((BackgroundLoader*)((struct List0202fec8*)listPtr))->GetLoadedFileByID((int)(obj->handle), (void**)(&out1), (unsigned int*)(&out2));
#if defined(jpn)
        {
#else
        if (out1 != 0 && out2 != 0) {
#endif

            int v = *(short*)((char*)obj->field4c + 0x18);
            func_020df850(&obj->field7c, &obj->field28, out1, out2, v);
        }

        ((BackgroundLoader*)(listPtr))->RemoveTask((int)(obj->handle));
        obj->handle = -1;
        return 0xf;
    }

    return 0xd;
}
