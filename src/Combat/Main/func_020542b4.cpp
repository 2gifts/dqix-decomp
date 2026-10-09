#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"

extern "C" ARM void _Z23InitSlotEntries020543ecPcS_(char* obj, char* p);

extern unsigned int data_020e7c40[];

struct Obj020542b4 {
    unsigned char pad0[4];
    SafeAllocator entries[10];
};

// USA: func_020542b4
extern "C" ARM void func_020542b4(struct Obj020542b4* self, SafeAllocator* alloc, char* arg2) {
    int i;
    void* buf;
    unsigned int size;

    alloc->Reset();

    for (i = 0; i < 10; i++) {
        size = data_020e7c40[i];
        buf = alloc->Allocate(size);
        VectorizedMemset(buf, 0, size);
        self->entries[i].CreateTypeA(buf, size);
    }

    _Z23InitSlotEntries020543ecPcS_((char*)self, arg2);

    buf = alloc->Allocate(0x2000);
    VectorizedMemset(buf, 0, 0x2000);
    ((SafeAllocator*)((char*)self + 0x52c))->CreateTypeA(buf, 0x2000);

    buf = alloc->Allocate(0x5400);
    VectorizedMemset(buf, 0, 0x5400);
    ((SafeAllocator*)((char*)self + 0x540))->CreateTypeA(buf, 0x5400);

    buf = alloc->Allocate(0x1000);
    VectorizedMemset(buf, 0, 0x1000);
    ((SafeAllocator*)((char*)self + 0x554))->CreateTypeA(buf, 0x1000);

    buf = alloc->Allocate(0xc00);
    VectorizedMemset(buf, 0, 0xc00);
    ((SafeAllocator*)((char*)self + 0x5d8))->CreateTypeA(buf, 0xc00);
}