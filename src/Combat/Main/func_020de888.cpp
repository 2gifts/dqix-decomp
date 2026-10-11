#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Coords020de7a4;
int ComputeOffsetFromFields(Coords020de7a4* obj);

struct Container020de7d0;
struct Element020de7d0;
typedef void (*Callback020de7d0)(Container020de7d0*, Element020de7d0*);
int IterateEntries020de7d0(Container020de7d0* c, Callback020de7d0 cb);

struct Container020de5b0;
int RemapSlotIndicesToPointers020de5b0(Container020de5b0* c);

extern "C" ARM int func_020de574(void* table, void* cursor);

struct Bits020de888 {
    unsigned int count : 31;
    unsigned int flag : 1;
};

struct List020de888 {
    char pad0[8];
    union {
        unsigned int raw;
        struct Bits020de888 bits;
    } f8;
    void* field_c;
    void* field_10;
};

// USA: func_020de888
extern "C" ARM int func_020de888(List020de888* self, SafeAllocator* allocator, void* file, void* arg3) {
    int offset;
    unsigned int count;
    Callback020de7d0 cb;

    if (allocator == 0 || file == 0 || arg3 == 0) {
        return 0;
    }
    if (allocator != 0 && file != 0) {
        memcpy(self, file, 0xc);
        offset = ComputeOffsetFromFields((Coords020de7a4*)self);
        count = self->f8.bits.count;
        if (offset != 0)
            self->field_c = allocator->Allocate(offset);
        else
            self->field_c = 0;
        self->field_10 = (count != 0) ? allocator->Allocate(count) : 0;
        if (self->field_c != 0) {
            memcpy(self->field_c, (char*)file + 0xc, offset);
        }
        if (self->field_10 != 0) {
            memcpy(self->field_10, (char*)file + (ComputeOffsetFromFields((Coords020de7a4*)self) + 0xc), count);
        }
        cb = (Callback020de7d0)func_020de574;
        if (cb != 0) {
            IterateEntries020de7d0((Container020de7d0*)self, cb);
        }
        self->f8.raw = (self->f8.raw & ~0x80000000u) | 0x80000000u;
    }
    return RemapSlotIndicesToPointers020de5b0((Container020de5b0*)self);
}
