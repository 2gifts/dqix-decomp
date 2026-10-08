#include <globaldefs.h>
#include "std_library_functions.h"

struct Ctx0209e6ac {
    char pad0[4];
    void* tablePtr;
    char pad1[0x98 - 8];
    int count0x98;
    char arr0x9c[0x400];
    int count0x49c;
    char arr0x4a0[0x400];
};

// USA: func_0209e6ac
extern "C" ARM void func_0209e6ac(struct Ctx0209e6ac* obj, int mode, int mask) {
    int elemSize = 0x40;
    if (mode == 0) {
        int count;
        int i;
        obj->count0x98 = 0;
        count = *(unsigned char*)((char*)obj->tablePtr + 0x8e07);
        for (i = 0; i < count; i++) {
            char* elem = (char*)obj->tablePtr + 0xc60 + 0x5000 + i * elemSize;
            if (elem != 0 && (*(int*)(elem + 4) & mask)) {
                int idx = obj->count0x98++;
                memcpy(obj->arr0x9c + idx * elemSize, elem, elemSize);
            }
        }
        return;
    }
    obj->count0x49c = 0;
    memset(obj->arr0x4a0, 0, 0x400);
    {
    int i;
    for (i = 0; i < obj->count0x98; i++) {
        char* elem = obj->arr0x9c + i * elemSize;
        if (*(int*)(elem + 4) & mask) {
            int idx = obj->count0x49c++;
            memcpy(obj->arr0x4a0 + idx * elemSize, elem, elemSize);
        }
    }
    }
    obj->count0x98 = obj->count0x49c;
    memcpy(obj->arr0x9c, obj->arr0x4a0, 0x400);
}