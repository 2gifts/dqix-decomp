#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

// USA: func_020bc658
ARM void InsertAllocatorSortedByByte3d_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* what) {
    SignedAllocatorHeader* e = list->ElementAfter(NULL);
    if (e != NULL) {
        do {
            if (*((unsigned char*)what + 0x3d) < *((unsigned char*)e + 0x3d)) break;
            e = list->ElementAfter(e);
        } while (e != NULL);
    }
    list->InsertBefore(e, what);
    what->pPrevAllocator = (SignedAllocatorHeader*)list;
}
