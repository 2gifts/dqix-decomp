#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov017_0218b5b0(void);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
extern int data_02114e20;

// USA: func_ov017_021a9714  (semantic: ClearAllocatorAndFields_021a9714)
extern "C" ARM void func_ov017_021a9714(char* self) {
    SafeAllocator* allocator = (SafeAllocator*)(self + 0xc);
    void* p = allocator->GetSignedAllocator();
    if (p != NULL) {
        allocator->Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }
    allocator->ResetAllocatorPointer();
    self[8] = 0;
    *(int*)(self + 0x20) = 0;
    void* h = func_ov017_0218b5b0();
    ClearBitsInField4_0203b4e8((unsigned int*)h, 0xc0);
}
