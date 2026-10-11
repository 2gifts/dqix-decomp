#include <globaldefs.h>
#if defined(jpn)
enum { kPrefix = 0x20 };
#else
enum { kPrefix = 0x2c };
#endif

extern "C" void func_0204c87c(void* entry, int arg);

struct Obj0207fc6c {
    char pad0[kPrefix];
    void* field_2c;
    char* entries;
    char pad34[5];
    unsigned char count;
};

// USA: func_0207fc6c
ARM void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg) {
    unsigned char count;
    char* e;
    unsigned char i;
    if (obj->field_2c != NULL && obj->entries != NULL) {
        e = obj->entries;
        count = obj->count;
        for (i = 0; i < count; i++) {
            func_0204c87c(e, arg);
            e += 0xe0;
        }
    }
}
