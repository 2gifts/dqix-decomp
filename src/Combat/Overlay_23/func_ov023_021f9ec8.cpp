#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
struct Obj021f9eb4;
void ClearFields0To3_021f9eb4(struct Obj021f9eb4* o);

struct Obj021f9ec8 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fa;
    char pad10[4];
    unsigned int f10;
    char pad1c[8];
    unsigned int f1c;
    unsigned short f20;
    char pad22[2];
    void* f24;
};

// USA: func_ov023_021f9ec8  (semantic: InitObjAndAllocateEntries_021f9ec8)
extern "C" ARM int func_ov023_021f9ec8(struct Obj021f9ec8* obj, void* ctx, int arg3, int arg4, int arg5) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 9;
    obj->f6 = arg3;
    obj->f8 = arg4;
    obj->fa = 0;
    obj->f10 = 0;
    obj->f1c = 2;
    obj->f20 = arg5;

    void* p = func_ov011_021845f8(ctx, obj->f8);
    if (p == NULL) {
        return 0;
    }

    SafeAllocator* alloc = (SafeAllocator*)((char*)p + 4);
    obj->f24 = alloc->Allocate(obj->f20 * 0x28);
    if (obj->f24 == NULL) {
        return 0;
    }

    int i;
    for (i = 0; i < obj->f20; i++) {
        ClearFields0To3_021f9eb4((struct Obj021f9eb4*)((char*)obj->f24 + i * 0x28));
    }
    return 1;
}
