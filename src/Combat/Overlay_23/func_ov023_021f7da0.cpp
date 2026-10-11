#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void func_0204c684(void* obj);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);

struct Obj_021844ec;
int GetField9c_021844ec(struct Obj_021844ec* obj);

void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);

struct Obj0204c7a8;
void AllocateBuffer0204c7a8(struct Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len);

struct Obj021f7da0 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fa;
    char pad_c[4];
    unsigned int f10;
    char pad_14[8];
    unsigned int f1c;
    void* f20;
    void* f24;
    char pad_28[0x104 - 0x28];
    unsigned short f104;
    unsigned short f106;
    unsigned char f108;
    char pad_109[1];
    unsigned char f10a;
    char pad_10b[1];
    unsigned short f10c;
    unsigned short f10e;
};

// USA: func_ov023_021f7da0  (semantic: InitObjKind6AndLinkNodes_021f7da0)
extern "C" ARM int func_ov023_021f7da0(struct Obj021f7da0* obj, void* ctx, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 6;
    obj->f6 = arg3;
    obj->f8 = arg4;
    obj->f10 = obj->fa = 0;
    obj->f1c = 2;
    obj->f106 = 0;
    obj->f104 = 0;
    obj->f10a = 0xf;
    obj->f10c = 0;
    obj->f10e = 1;
    func_0204c684(&obj->f20);

    void* p = func_ov011_021845f8(ctx, obj->f8);
    if (p == NULL) {
        return 0;
    }

    int f9c = GetField9c_021844ec((struct Obj_021844ec*)ctx);
    if (f9c == 0) {
        return 0;
    }

    unsigned int len = (unsigned int)(arg6 * arg7) * 2;
    SafeAllocator* alloc = (SafeAllocator*)((char*)p + 4);
    if (alloc->GetMaxPossibleAllocation() < len) {
        return 0;
    }

    AllocateBuffer0204c7a8((struct Obj0204c7a8*)&obj->f20, alloc, f9c, len);

    void* list = func_ov011_021849c8(ctx);
    void* node = func_ov023_021f6880(list, arg5);
    if (node == NULL) {
        return 0;
    }
    obj->f24 = GetFieldPtrAt_021f79e4_021f79e4(node);

    obj->f108 = (unsigned char)arg8;
    void* node2 = func_ov023_021f6880(list, arg9);
    if (node2 != NULL) {
        obj->f20 = (char*)node2 + 0x20;
    }
    return 1;
}
