#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Obj020bc084;
extern void ClearFieldAndNullSlot020bc084(struct Obj020bc084** slot);

struct Obj020bc6fc;
extern void DispatchType2Command020bc6fc(struct Obj020bc6fc* obj);

extern void InsertAllocatorSortedByByte3d_020bc658(SignedAllocatorList* list, SignedAllocatorHeader* what);
extern SignedAllocatorHeader* AcquireOrEvictEntryByByte3d020bc734(int priority);

struct SlotObj020bc454 {
    void* field0;
};

struct EntryContainer020bc454 {
    SignedAllocatorList list;
    char pad0c[0x18 - 0xc];
    unsigned int capacity;
    char pad1c[0x24 - 0x1c];
};
extern struct EntryContainer020bc454 data_0210f824[];

// USA: func_020bc454
ARM void* AcquireOrEvictSlotAndLink020bc454(struct SlotObj020bc454* obj, int index, int priority) {
    struct EntryContainer020bc454* c = &data_0210f824[index];

    if (obj->field0 != NULL) {
        ClearFieldAndNullSlot020bc084((struct Obj020bc084**)obj);
    }

    if (c->list.numElements >= c->capacity) {
        SignedAllocatorHeader* first = c->list.ElementAfter(NULL);
        if (first == NULL) {
            return NULL;
        }
        if (priority < *((unsigned char*)first + 0x3d)) {
            return NULL;
        }
        DispatchType2Command020bc6fc((struct Obj020bc6fc*)first);
    }

    {
        SignedAllocatorHeader* e = AcquireOrEvictEntryByByte3d020bc734(priority);
        if (e == NULL) {
            return NULL;
        }
        InsertAllocatorSortedByByte3d_020bc658(&c->list, e);
        *(void**)e = obj;
        obj->field0 = e;
        return e;
    }
}
