#include <globaldefs.h>
#include "Memory/AllocatorLifecycle.h"

struct AllocatorUnion;
void FreeIfFlag(struct AllocatorUnion* alloc, void* ptr, int flag);

#if defined(jpn)
enum { BufferAllocationSize = 0x33f8 };
#else
enum { BufferAllocationSize = 0x36c0 };
#endif

// USA: func_ov030_021d92f0  (semantic: ReleaseBuffers_021d92f0)
extern "C" ARM void func_ov030_021d92f0(void* ptr, struct AllocatorUnion* alloc, void** slot) {
    if (ptr != NULL) {
        FreeIfFlag(alloc, ptr, 1);
    }
    if (*slot != NULL) {
        FreeIfFlag(alloc, *slot, BufferAllocationSize);
        *slot = NULL;
    }
    EmptyStub02012de4(alloc);
}
