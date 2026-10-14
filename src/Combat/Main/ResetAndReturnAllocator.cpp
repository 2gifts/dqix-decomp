#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

// USA: func_020466d0
ARM SafeAllocator* ResetAndReturnAllocator_020466d0(SafeAllocator* alloc) {
    alloc->ResetAllocatorPointer();
    return alloc;
}
