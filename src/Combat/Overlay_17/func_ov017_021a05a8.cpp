#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

extern AllocatorUnion data_02114e20;

struct IndexEntry021d6874 { int index; int pad4; };
struct SizeEntry021d6878 { int size; int pad4; };
extern IndexEntry021d6874 data_ov017_021d6874[];
extern SizeEntry021d6878 data_ov017_021d6878[];

struct Obj021a05a8 {
    char pad0[0x9c];
    SafeAllocator allocator;
};

// USA: func_ov017_021a05a8
extern "C" ARM void func_ov017_021a05a8(char* self) {
    SafeAllocator* topAlloc = (SafeAllocator*)(self + 0x9c);
    void* p = topAlloc->GetSignedAllocator();
    if (p) {
        topAlloc->Destroy();
        TailForward02012da4(&data_02114e20, p);
    }

    self = self + 0x38;
    int i = 0;
    for (; data_ov017_021d6878[i].size != 0; i++) {
        int size = data_ov017_021d6878[i].size;
        void* buf = AllocateAligned4_02012d88(&data_02114e20, size);
        int idx = data_ov017_021d6874[i].index;
        SafeAllocator* alloc = (SafeAllocator*)(self + idx * 0x14);
        alloc->CreateTypeA(buf, size);
    }
}
