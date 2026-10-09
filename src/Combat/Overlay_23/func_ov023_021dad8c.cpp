#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

struct SlotData {
    unsigned int kind_ : 7; unsigned int group_ : 4; unsigned int unusedB_ : 18;
    unsigned int enabled_ : 1; unsigned int mode_ : 2;
    unsigned int mask_ : 12; unsigned int unusedC_ : 15;
    unsigned int flag27_ : 1; unsigned int flag28_ : 1; unsigned int flag29_ : 1;
    unsigned int unused1E_ : 2;
};
struct Slot {
    SlotData* data_; void* field4_;
    unsigned int type_ : 4; unsigned int unused8_ : 28;
    char padC[12]; short key_; char pad1A[6];
};
struct SlotHeader {
    unsigned short count_; unsigned short extraCount_ : 15; unsigned short extended_ : 1;
    int field4_; unsigned int unused8_ : 31; unsigned int mapped_ : 1;
};
struct Container020de5b0 { SlotHeader header_; Slot* slots_; void* data_; };
struct PackedSlot {
    short key_; unsigned short type_ : 4; unsigned short unused2_ : 12;
    unsigned int kind_ : 7; unsigned int group_ : 4; unsigned int mask_ : 12;
    unsigned int enabled_ : 1; unsigned int mode_ : 2;
    unsigned int flag27_ : 1; unsigned int flag28_ : 1; unsigned int flag29_ : 1;
    unsigned int unused1D_ : 3;
};
struct SlotCollection { PackedSlot* entries_; unsigned short count_; unsigned short used_; };
extern "C" int func_020de574(Container020de5b0*, Slot*);
extern "C" int _Z34RemapSlotIndicesToPointers020de5b0P17Container020de5b0(Container020de5b0*);

// USA: func_ov023_021dad8c
extern "C" ARM void func_ov023_021dad8c(SlotCollection* self, SafeAllocator* allocator, SlotHeader* source, void* context) {
    if (!allocator || !source || !context) return;
    self->count_ = 0;
    self->used_ = 0;
    Container020de5b0 container;
    memset(&container, 0, sizeof(container));
    int mapped = 0;
    if (source) {
        memcpy(&container, source, sizeof(SlotHeader));
        container.slots_ = (Slot*)(source + 1);
        unsigned short extra = container.header_.extraCount_;
        unsigned short count = container.header_.count_;
        int extension = container.header_.extended_ ? 88 : 0;
        int size = extension + extra * 32 + count * 32;
        container.data_ = (char*)source + (size + 12);
        if (container.header_.mapped_) mapped = 1;
        else {
            Slot* slot = container.slots_;
            int i;
            unsigned short count;
            if (slot && (count = container.header_.count_) && (unsigned int)func_020de574) {
                for (i = 0; i < count; ++i, ++slot) func_020de574(&container, slot);
            }
            container.header_.mapped_ = 1;
            source->mapped_ = 1;
        }
    }
    if (!mapped) _Z34RemapSlotIndicesToPointers020de5b0P17Container020de5b0(&container);
    int count = container.header_.count_;
    {
        Slot* slot = container.slots_;
        for (int i = 0; i < count; ++i, ++slot) {
            int valid = slot->type_ <= 7 ? 1 : 0;
            if (valid) ++self->count_;
        }
    }
    PackedSlot* output = (PackedSlot*)allocator->Allocate(self->count_ * sizeof(PackedSlot));
    self->entries_ = output;
    if (!output) return;
    Slot* slot = container.slots_;
    for (int i = 0; i < count; ++i, ++slot) {
        int valid = slot->type_ <= 7 ? 1 : 0;
        SlotData* data;
        if (valid && (data = slot->data_) != 0) {
            ++self->used_;
            output->key_ = slot->key_;
            output->type_ = (unsigned short)slot->type_;
            output->kind_ = data->kind_;
            output->group_ = data->group_;
            output->mask_ = data->mask_;
            output->enabled_ = data->enabled_;
            output->mode_ = data->mode_;
            output->flag27_ = data->flag27_;
            output->flag28_ = data->flag28_;
            output->flag29_ = data->flag29_;
            ++output;
        }
    }
}
