#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Header020e544c;
unsigned int GetField0Low12Times16020e544c(Header020e544c* header);

struct ElementList020e545c;
struct Element020e545c;
typedef void (*ElementCallback020e545c)(ElementList020e545c*, Element020e545c*);
int InvokeCallbackPerElement020e545c(ElementList020e545c* list, ElementCallback020e545c callback);

struct Pair020e5204;
void RemapBothPointerFields(void* a, Pair020e5204* b);

struct List020e5604 {
    unsigned int field0;
    void* field4;
    void* field8;
};

// USA: func_020e5604
extern "C" ARM int func_020e5604(struct List020e5604* self, SafeAllocator* alloc, unsigned char* src, int flag) {
    unsigned int size1;
    unsigned int size2;
    if (!(alloc != 0 && src != 0 && flag != 0)) {
        return 0;
    }
    if (!(alloc != 0 && src != 0)) {
        return 0;
    }
    memcpy(self, src, 4);
    size1 = GetField0Low12Times16020e544c((Header020e544c*)self);
    size2 = (self->field0 << 1) >> 13;
    if (size1)
        self->field4 = alloc->Allocate(size1);
    else
        self->field4 = (void*)0;
    self->field8 = size2 ? alloc->Allocate(size2) : (void*)0;
    if (self->field4) {
        memcpy(self->field4, src + 4, size1);
    }
    if (self->field8) {
        memcpy(self->field8, src + (GetField0Low12Times16020e544c((Header020e544c*)self) + 4), size2);
    }
    if ((void*)RemapBothPointerFields != 0) {
        InvokeCallbackPerElement020e545c((ElementList020e545c*)self,
            (ElementCallback020e545c)RemapBothPointerFields);
    }
    self->field0 = (self->field0 & ~0x80000000) | 0x80000000;
    return 1;
}
