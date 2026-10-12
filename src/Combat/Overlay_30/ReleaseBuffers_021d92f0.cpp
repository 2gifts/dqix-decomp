#include <globaldefs.h>

struct AllocatorUnion;
extern "C" void _Z10FreeIfFlagP14AllocatorUnionPvi(struct AllocatorUnion* alloc, void* ptr, int flag);
extern "C" void _Z17EmptyStub02012de4v(struct AllocatorUnion* alloc);

#if defined(jpn)
enum { BufferAllocationSize = 0x33f8 };
#else
enum { BufferAllocationSize = 0x36c0 };
#endif

// USA: func_ov030_021d92f0  (semantic: ReleaseBuffers_021d92f0)
extern "C" ARM void func_ov030_021d92f0(void* ptr, struct AllocatorUnion* alloc, void** slot) {
    if (ptr != NULL) {
        _Z10FreeIfFlagP14AllocatorUnionPvi(alloc, ptr, 1);
    }
    if (*slot != NULL) {
        _Z10FreeIfFlagP14AllocatorUnionPvi(alloc, *slot, BufferAllocationSize);
        *slot = NULL;
    }
    _Z17EmptyStub02012de4v(alloc);
}
