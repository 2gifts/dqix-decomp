#include <globaldefs.h>
#if defined(jpn)
enum { kMinimumSize = 0x129e00 };
#else
enum { kMinimumSize = 0x12d0f4 };
#endif

#include "Memory/AllocatorUnion.h"
#include "Memory/HPXEAllocator.h"

int GetSharedWordDa0(int index);
int GetSharedWordDc4(int index);

extern "C" {
    void* func_020c86fc(int, unsigned int, int);
    void func_020c9be0(void);
}

// USA: func_02012d18
ARM void InitMainAllocator02012d18(AllocatorUnion* obj) {
    int begin = GetSharedWordDa0(0);
    int end = GetSharedWordDc4(0);
    unsigned int alignedBegin = (begin + 0xf) & ~0xf;
    unsigned int alignedEnd = end & ~0xf;
    unsigned int size = alignedEnd - alignedBegin;

    void* where = func_020c86fc(0, size, 0x10);
    HPXEAllocator* alloc = HPXEAllocator::CreateAtLocation(where, size, 0);
    obj->InitializeTypeB(alloc, 4);

    if (size < kMinimumSize) {
        func_020c9be0();
    }
}
