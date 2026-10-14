#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

void InsertAllocatorSortedByByte3d_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* what);
void InsertSortedByByte3dGlobal020bc6a8(SignedAllocatorHeader* what);

extern SignedAllocatorList data_0210f3d8;

// USA: func_020bc870
ARM void RelinkAllocatorAndSetByte3d020bc870(SignedAllocatorHeader* header, unsigned char b) {
    SignedAllocatorList* list = (SignedAllocatorList*)header->pPrevAllocator;
    if (list != NULL) {
        list->Remove(header);
        header->pPrevAllocator = NULL;
    }
    data_0210f3d8.Remove(header);
    *((unsigned char*)header + 0x3d) = b;
    if (list != NULL) {
        InsertAllocatorSortedByByte3d_020bc658(list, header);
    }
    InsertSortedByByte3dGlobal020bc6a8(header);
}
