#include <globaldefs.h>
#include "Combat/LootPickupEvent.h"

struct ByteHeader0204693c;
extern void ResetByteHeader(ByteHeader0204693c* p);


// USA: func_ov017_021ae800
ARM void ResetHeaderAndAllocator_021ae800(Obj021ae800* self) {
    ResetByteHeader((ByteHeader0204693c*)self);
    self->type = 0x23;
    self->stage = 0;
    self->timer = 0;
    self->itemId = 0;
    self->allocator.ResetAllocatorPointer();
    {
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        unsigned int extracted = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((extracted | 0x10) << 8);
    }
    self->mode = 0;
}
