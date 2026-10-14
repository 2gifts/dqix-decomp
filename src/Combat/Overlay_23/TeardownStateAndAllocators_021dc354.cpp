#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void ResetIfNonNeg_021db2e4(volatile int* p);
int GetGlobal02109400_02094a00(void);
extern "C" void func_02094ab0(void* obj);
struct InitStruct02075cdcStruct;
void InitStruct02075d58(struct InitStruct02075cdcStruct* s);
extern "C" void func_ov023_021dcd18(void* obj);
extern "C" void func_ov023_021dc134(void* a, int key, int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern AllocatorUnion data_02114e20;

#if defined(jpn)
struct DataStruct_021dc354 { unsigned int pad0[5]; void* field4; };
#else
struct DataStruct_021dc354 { unsigned int pad0; void* field4; };
#endif

extern struct DataStruct_021dc354 data_ov023_021ff9e0;

struct Obj021dc354 {
    SafeAllocator allocator0;
    SafeAllocator allocator1;
    SafeAllocator allocator2;
    SafeAllocator* pAlloc0;
    SafeAllocator* pAlloc1;
    SafeAllocator* pAlloc2;
    unsigned char pad48[0xc4 - 0x48];
    struct InitStruct02075cdcStruct* ptrC4;
    struct InitStruct02075cdcStruct* ptrC8;
#if defined(jpn)
    unsigned char padCC[0x6b0 - 0xcc];
#else
    unsigned char padCC[0x734 - 0xcc];
#endif

    int field734;
    int arr738[7];
    unsigned char pad754[0x774 - 0x754];
    unsigned short flags774;
    unsigned char pad776[0x77b - 0x776];
    signed char field77b;
    unsigned char pad77c[0x77e - 0x77c];
    signed char field77e;
    unsigned char pad77f[0x780 - 0x77f];
    int field780;
    unsigned char pad784[0x79b - 0x784];
    unsigned char flag79b : 1;
};

// USA: func_ov023_021dc354  (semantic: TeardownStateAndAllocators_021dc354)
extern "C" ARM void func_ov023_021dc354(struct Obj021dc354* obj) {
    ResetIfNonNeg_021db2e4((volatile int*)&obj->field780);
    obj->field77e = -1;

    if (!(obj->flags774 & 0x10)) {
        func_02094ab0((void*)GetGlobal02109400_02094a00());
    }

    ResetIfNonNeg_021db2e4((volatile int*)&obj->field734);
    for (int i = 0; i < 7; i++) {
        ResetIfNonNeg_021db2e4((volatile int*)&obj->arr738[i]);
    }

    if (obj->ptrC8) {
        InitStruct02075d58(obj->ptrC8);
    }
    if (obj->ptrC4) {
        InitStruct02075d58(obj->ptrC4);
    }

    if (obj->field77b != 1) {
        func_ov023_021dcd18(obj);
    }

    if (obj->pAlloc2) {
        obj->pAlloc2->Destroy();
    }
    if (obj->pAlloc1) {
        obj->pAlloc1->Destroy();
    }
    if (obj->pAlloc0) {
        obj->pAlloc0->Destroy();
    }
    obj->allocator2.Destroy();
    obj->allocator1.Destroy();
    obj->allocator0.Destroy();

    if (data_ov023_021ff9e0.field4) {
        if (!obj->flag79b) {
            TailForward02012da4(&data_02114e20, data_ov023_021ff9e0.field4);
        }
        data_ov023_021ff9e0.field4 = 0;
    }

    func_ov023_021dc134(obj, -1, obj->field77b);
}
