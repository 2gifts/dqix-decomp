#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue34_30 = 0x30 };
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue3C_38 = 0x38 };
#else
enum { kRegionValue34_30 = 0x34 };
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue3C_38 = 0x3c };
#endif


struct InitTarget0205cfd4;
ARM void InitStruct0205cfd4(struct InitTarget0205cfd4* s);
struct List0204af64;
ARM void ResetList0204af64(struct List0204af64* obj);
extern "C" void func_0204c684(void* obj);
struct Struct0205a198;
void Init0205a198(struct Struct0205a198*);
struct ClearTarget0205a234;
void ClearField0And40205a234(struct ClearTarget0205a234* target);

struct Obj0217cd24 {
    char pad0[kRegionValue34_30];
    void* p34;
    void* p38;
    char pad1[kRegionValue90_8C - kRegionValue3C_38];
    void* p90;
    void* p94;
    void* p98;
    char pad2[4];
    SafeAllocator* alloc;
    SafeAllocator allocA4;
    SafeAllocator allocB8;
};

// USA: func_ov003_0217cd24
// JPN: func_ov003_0217ba4c
extern "C" ARM void func_ov003_0217cd24(void* objRaw, SafeAllocator* allocator) {
    if (allocator == 0) return;
    struct Obj0217cd24* obj = (struct Obj0217cd24*)objRaw;

    obj->alloc = allocator;
    obj->p90 = obj->alloc->Allocate(0xbc);
    obj->p94 = obj->alloc->Allocate(0x40);
    obj->p98 = obj->alloc->Allocate(0xe0);
    InitStruct0205cfd4((struct InitTarget0205cfd4*)obj->p90);

    for (int i = 0; i < 2; i++) {
        ResetList0204af64((struct List0204af64*)((char*)obj->p94 + i * 0x20));
    }
    for (int i = 0; i < 1; i++) {
        func_0204c684((char*)obj->p98 + i * 0xe0);
    }

    obj->p34 = obj->alloc->Allocate(0x118);
    obj->p38 = obj->alloc->Allocate(8);

    for (int i = 0; i < 7; i++) {
        Init0205a198((struct Struct0205a198*)((char*)obj->p34 + i * 0x28));
    }
    ClearField0And40205a234((struct ClearTarget0205a234*)obj->p38);

    void* buf1 = obj->alloc->Allocate(0x800);
    obj->allocA4.CreateTypeA(buf1, 0x800);

    void* buf2 = obj->alloc->Allocate(0x400);
    obj->allocB8.CreateTypeA(buf2, 0x400);
}
