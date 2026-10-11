#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void func_02020720(int);

class AllocatorUnion;
int TailForward02012da4(AllocatorUnion*, void*);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

extern AllocatorUnion data_02114e20;
extern int data_ov017_021d669c[];

// JPN: func_ov017_021a0fbc
// USA: func_ov017_021a050c
ARM void ResetTaskAndDestroyAllocators_021a050c(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0x4c0};
#else
 enum {regionalOffset0=0x6d0};
#endif
    int handle = *(int*)(self + 0x3000 + regionalOffset0);
    func_02020720(handle);

    for (int i = 0; data_ov017_021d669c[i] >= 0; i++) {
        int off = data_ov017_021d669c[i] * 0x14;
        void* p = ((SafeAllocator*)(self + 0x38 + off))->GetSignedAllocator();
        ((SafeAllocator*)(self + 0x38 + off))->Destroy();
        ((SafeAllocator*)(self + 0x38 + off))->ResetAllocatorPointer();
        if (p != NULL) {
            TailForward02012da4(&data_02114e20, p);
        }
    }

    void* buf = AllocateAligned4(&data_02114e20, 0x6f78);
    ((SafeAllocator*)(self + 0x9c))->CreateTypeA(buf, 0x6f78);
}
