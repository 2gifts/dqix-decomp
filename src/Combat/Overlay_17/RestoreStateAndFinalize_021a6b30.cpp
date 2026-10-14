#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* obj, int index);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
void RestorePairTableFromBuffer_020bb740(int* out);
void WriteGlobalPair020bb92c(int* src);
extern "C" void func_020a0c0c(void);

extern int data_02114e20;

struct Obj021a6b30 {
    char pad[0x10];
    SafeAllocator allocator;
};

// USA: func_ov017_021a6b30  (semantic: RestoreStateAndFinalize_021a6b30)
extern "C" ARM void func_ov017_021a6b30(struct Obj021a6b30* self) {
    func_02057f00(func_02057924(self), 0xc);

    void* p = self->allocator.GetSignedAllocator();
    if (p != NULL) {
        self->allocator.Destroy();
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
    }

    RestorePairTableFromBuffer_020bb740((int*)((char*)self + 0x24));
    WriteGlobalPair020bb92c((int*)((char*)self + 0x4c));
    func_020a0c0c();
}
