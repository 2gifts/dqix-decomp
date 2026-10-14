#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" int func_ov017_021d60f4(void*);
struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(struct Struct02012dd0*);

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

extern SafeAllocator* data_ov001_021658b8[8];
extern AllocatorUnion data_02114e20;

// USA: func_ov001_0215e9b0
ARM int AllocateAndCreateAllocator_0215e9b0(void* self) {
    int idx = func_ov017_021d60f4(self);
    if (idx < 0 || idx >= 8) {
        return 0;
    }
    unsigned int maxAlloc = GetMaxAlloc02012dd0((struct Struct02012dd0*)&data_02114e20);
    if (data_ov001_021658b8[0] != NULL) {
        if (data_ov001_021658b8[0]->GetMaxPossibleAllocation() <= 0x14) {
            return 0;
        }
    }
    SafeAllocator* buf = (SafeAllocator*)data_ov001_021658b8[0]->Allocate(0x14);
    buf->ResetAllocatorPointer();
    void* p = AllocateAligned4(&data_02114e20, maxAlloc);
    buf->CreateTypeA(p, maxAlloc);
    return 1;
}
