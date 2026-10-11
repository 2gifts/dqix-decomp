#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct InitStruct02075cdcStruct;
void InitStruct02075cdc(struct InitStruct02075cdcStruct* s);

struct Obj021dbfd0 {
    SafeAllocator allocator0;                  // 0x00
    SafeAllocator allocator1;                  // 0x14
    SafeAllocator allocator2;                  // 0x28
    SafeAllocator* pAlloc0;                    // 0x3c
    SafeAllocator* pAlloc1;                    // 0x40
    SafeAllocator* pAlloc2;                    // 0x44
    unsigned char pad48[0xc4 - 0x48];
    struct InitStruct02075cdcStruct* ptrC4;    // 0xc4
    struct InitStruct02075cdcStruct* ptrC8;    // 0xc8
};

struct Struct02075cdcFields_021dbfd0 {
    unsigned char pad0[0x38];
    int f38;
    int f3c;
    unsigned char pad40[0x5e - 0x40];
    unsigned char f5e;
};

// JPN: func_ov023_021dc8c8
// USA: func_ov023_021dbfd0  (semantic: InitSubAllocatorsAndBuffers_021dbfd0)
extern "C" ARM void func_ov023_021dbfd0(Obj021dbfd0* obj, SafeAllocator* alloc) {
#if defined(jpn)
 enum {regionalOffset0=0x6f8};
#else
 enum {regionalOffset0=0x77c};
#endif
    if (alloc == NULL) return;

    obj->allocator0.CreateTypeA(alloc->Allocate(0xd33), 0xd33);
    obj->allocator1.CreateTypeA(alloc->Allocate(0x4cc), 0x4cc);
    obj->allocator2.CreateTypeA(alloc->Allocate(0x400), 0x400);

    obj->ptrC4 = (struct InitStruct02075cdcStruct*)alloc->Allocate(0x70);
    obj->ptrC8 = (struct InitStruct02075cdcStruct*)alloc->Allocate(0x70);
    obj->pAlloc0 = (SafeAllocator*)alloc->Allocate(0x14);
    obj->pAlloc1 = (SafeAllocator*)alloc->Allocate(0x14);
    obj->pAlloc2 = (SafeAllocator*)alloc->Allocate(0x14);
    obj->pAlloc2->CreateTypeA(alloc->Allocate(0x180), 0x180);

    InitStruct02075cdc(obj->ptrC4);
    InitStruct02075cdc(obj->ptrC8);

    ((Struct02075cdcFields_021dbfd0*)obj->ptrC4)->f5e = *(signed char*)((char*)obj + regionalOffset0);
    ((Struct02075cdcFields_021dbfd0*)obj->ptrC4)->f3c = 0;
    ((Struct02075cdcFields_021dbfd0*)obj->ptrC8)->f5e = *(signed char*)((char*)obj + regionalOffset0);
    ((Struct02075cdcFields_021dbfd0*)obj->ptrC8)->f38 = 0x120;
    ((Struct02075cdcFields_021dbfd0*)obj->ptrC8)->f3c = 1;

    obj->pAlloc0->CreateTypeA(alloc->Allocate(0x280), 0x280);
    obj->pAlloc1->CreateTypeA(alloc->Allocate(0x280), 0x280);
}
