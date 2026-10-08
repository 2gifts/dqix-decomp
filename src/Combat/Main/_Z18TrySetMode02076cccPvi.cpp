#include <globaldefs.h>

struct Entry02076ccc {
    int field0;
    int field4;
};

extern "C" struct Entry02076ccc data_020e8994[];

struct Actor02076ccc {
    char pad[0x130];
    int field_130;
    int field_134;
    char pad134[0x14];
    unsigned int field_14c;
};

// KEEP-NAME
// USA: func_02076ccc
extern "C" ARM bool _Z18TrySetMode02076cccPvi(struct Actor02076ccc* obj, int mode) {
    if (obj->field_130 == mode) {
        return true;
    }
    struct Entry02076ccc* e = &data_020e8994[mode];
    void* base = (char*)obj + (e->field4 >> 1);
    void* callback;
    if (e->field4 & 1) {
        void** vtable = (void**)*(void**)base;
        callback = *(void**)((char*)vtable + e->field0);
    } else {
        callback = (void*)e->field0;
    }
    if (((int (*)(void*))callback)(base) == 0) {
        return false;
    }
    obj->field_134 = obj->field_130;
    obj->field_130 = mode;
    obj->field_14c = 0;
    return true;
}
