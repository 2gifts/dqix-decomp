#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"



extern "C" void func_ov003_0216d77c(void* arg);
void PopStack0AndTrigger(int flag);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
struct Struct02074bd0;
void ClearFlag0x10IfSet(struct Struct02074bd0* obj);
extern "C" int GetMainBGAssignedVRAMSize(void);
extern "C" void func_020ca458(int a, int b, int c);
extern "C" void func_020a0c0c(void);
extern AllocatorUnion data_02114e20;

// USA: func_ov003_0217f118  (semantic: FinalizeAndCleanup_0217f118)
// JPN: func_ov003_0217de1c
extern "C" ARM void func_ov003_0217f118(char* self) {
    if (*(void**)(self + 0xc) != 0) {
        func_ov003_0216d77c(*(void**)(self + 0xc));
        *(void**)(self + 0xc) = 0;
        PopStack0AndTrigger(1);
    }
    SafeAllocator* alloc14 = (SafeAllocator*)(self + 0x14);
    void* p = alloc14->GetSignedAllocator();
    if (p != 0) {
        alloc14->Destroy();
        TailForward02012da4(&data_02114e20, p);
    }
    ClearFlag0x10IfSet((struct Struct02074bd0*)(self + 0x2a));
    int size = GetMainBGAssignedVRAMSize();
    func_020ca458(0, 0x6000000, size);
    func_020a0c0c();
    self[1] = 1;
}
