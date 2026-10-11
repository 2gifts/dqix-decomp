#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021845f8(void* a, int b);
extern "C" void func_0208b9a0(void*, int);

struct Obj0208b8c4;
void InitAllocatorsAndBuffers0208b8c4(struct Obj0208b8c4* obj, SafeAllocator* allocator);

struct InitObj02167820 {
    char pad0[4];
    unsigned short field_4;
    unsigned short field_6;
    unsigned short field_8;
    char pad1[0x1c - 0xa];
    int field_1c;
    SafeAllocator alloc0x20;
    char pad2[0x106 - 0x34];
    unsigned short field_106;
};

// USA: func_ov004_02167820  (semantic: InitCombatObjAllocators_02167820)
extern "C" ARM int func_ov004_02167820(InitObj02167820* self, void* param1, int param2, int param3) {
    func_ov023_021f6ed8(self);
    self->field_4 = 0x15;
    self->field_6 = param2;
    self->field_8 = param3;
    self->field_1c = 2;

    void* p = func_ov011_021845f8(param1, self->field_8);
    if (!p) {
        return 0;
    }

    self->alloc0x20.ResetAllocatorPointer();
    void* buf = ((SafeAllocator*)((char*)p + 4))->Allocate(0x2800);
    self->alloc0x20.CreateTypeA(buf, 0x2800);

    func_0208b9a0((char*)self + 0x34, 1);
    InitAllocatorsAndBuffers0208b8c4((struct Obj0208b8c4*)((char*)self + 0x34), &self->alloc0x20);

    self->field_106 = 0x270f;
    return 1;
}
