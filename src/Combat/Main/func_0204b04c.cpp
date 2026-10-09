#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

extern volatile unsigned int data_020e7b98[][4];

struct Obj0204b04c {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    char pad1c[3];
    unsigned char byte1f;
};

// USA: func_0204b04c
extern "C" ARM void func_0204b04c(Obj0204b04c* obj, void* p) {
    if (p == NULL) p = obj->field14;
    if (p == NULL) return;
    unsigned int size = data_020e7b98[obj->byte1f][obj->field18];
    CleanInvalidateCacheRange(p, size);
}