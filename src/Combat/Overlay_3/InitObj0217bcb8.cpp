#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct List0204af64;
void ResetList0204af64(List0204af64* obj);

struct Obj0217bcb8 {
    int field0;
    class SafeAllocator alloc4;
    class SafeAllocator alloc18;
    class SafeAllocator alloc2c;
    unsigned char list40[0x20];
    unsigned char list60[0x20];
    unsigned char sub80[0xac];
    unsigned char b12c;
    signed char b12d;
    int w130;
    int w134;
    int w138;
    int w13c;
    unsigned char b140;
    unsigned char b141;
    unsigned char b142;
    unsigned char b143;
    unsigned char pad144[0x160 - 0x144];
    int w160;
};

// USA: func_ov003_0217bcb8
ARM void InitObj0217bcb8(Obj0217bcb8* self) {
    self->field0 = 0;
    self->alloc4.ResetAllocatorPointer();
    self->alloc18.ResetAllocatorPointer();
    self->alloc2c.ResetAllocatorPointer();
    ResetList0204af64((List0204af64*)self->list40);
    ResetList0204af64((List0204af64*)self->list60);
    ((Object3D*)self->sub80)->Initialize();
    self->b12c = 0;
    int negOne = self->b12c - 1;
    self->b12d = negOne;
    self->w130 = negOne;
    self->w134 = negOne;
    self->w138 = negOne;
    self->w13c = negOne;
    self->b140 = 0;
    self->b141 = 0;
    self->b143 = 0;
    self->b142 = 0;
    self->w160 = 0;
    *(short*)((char*)self + 0x15c) = 0;
}
