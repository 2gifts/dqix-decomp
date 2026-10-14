#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

struct Obj020bdbf0;
extern int InitAllocatorHolder020bdbf0(Obj020bdbf0* obj, HMRFAllocator* allocator);

// USA: func_020bd914
ARM void* CreateAllocatorHolderInRegion_020bd914(void* start, unsigned int size)
{
    unsigned int end = (unsigned int)start + size;
    unsigned int alignedStart = ((unsigned int)start + 3) & ~3;

    if (alignedStart > end)
        return NULL;

    unsigned int avail = end - alignedStart;
    if (avail < 0x10)
        return NULL;

    HMRFAllocator* allocator = HMRFAllocator::CreateAtLocation((void*)(alignedStart + 0x10), avail - 0x10, 0);
    if (allocator == NULL)
        return NULL;

    if (InitAllocatorHolder020bdbf0((Obj020bdbf0*)alignedStart, allocator))
        return (void*)alignedStart;

    allocator->RemoveFromTree();
    return NULL;
}
