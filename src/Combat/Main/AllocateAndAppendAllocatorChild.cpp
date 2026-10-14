#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

void InitAllocatorListZero_020bdbe0(SignedAllocatorList* list);

struct Obj020bdc24 {
    HMRFAllocator* allocator;
    SignedAllocatorList list;
};

// USA: func_020bdc24
extern "C" ARM int func_020bdc24(void* objPtr) {
    struct Obj020bdc24* obj = (struct Obj020bdc24*)objPtr;
    void* p = obj->allocator->Allocate(0x14, 4);
    if (p == NULL) return 0;
    InitAllocatorListZero_020bdbe0((SignedAllocatorList*)p);
    obj->list.InsertAtEnd((SignedAllocatorHeader*)p);
    return 1;
}
