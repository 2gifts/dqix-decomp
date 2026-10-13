#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

extern unsigned int data_020e7b98[][4];

struct Obj0204b04c {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    char pad1c[3];
    unsigned char byte1f;
};

static inline unsigned int GetSize(unsigned int type, unsigned int index) {
    return data_020e7b98[type][index];
}

// USA: func_0204b04c
extern "C" ARM void func_0204b04c(Obj0204b04c* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    CleanInvalidateCacheRange(p, GetSize(obj->byte1f, obj->field18));
}