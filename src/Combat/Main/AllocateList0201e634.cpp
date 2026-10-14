#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "World/ZoneFeatures.h"

struct List0201e634 {
    char pad[0x24];
    void* buf;
    int count;
    int capacity;
};

// USA: func_0201e634
ARM void ZoneFeatures::AllocateOpcode6aEntries(int capacity, SafeAllocator* alloc) {
    struct List0201e634* self = (struct List0201e634*)this;
    self->buf = alloc->Allocate(capacity * 0x74);
    self->count = 0;
    self->capacity = capacity;
}
