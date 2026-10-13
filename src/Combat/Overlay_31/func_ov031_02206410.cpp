#include <globaldefs.h>
#include "System/Memory.h"

struct Obj0220528c;
struct TransferBuffer02206410 {
    unsigned char padding_0[0xf8];
    int capacity;
    unsigned char* data;
    unsigned short position;
    unsigned char padding_102[0xa];
    Obj0220528c* callback;
};
struct TransferContext02206410 {
    unsigned char padding_0[0xa];
    unsigned short sequence;
    unsigned char padding_c[0x5c];
    TransferBuffer02206410* buffer;
    unsigned char padding_6c[7];
    signed char mode;
    unsigned short pending_sequence;
    unsigned short pending_tag;
    void* pending_data;
};
struct TransferRecord02206410 {
    unsigned char padding_0[0xd];
    unsigned char flags;
    unsigned char padding_e[2];
    void* first_data;
    int first_size;
    void* second_data;
    int second_size;
    unsigned short position;
    unsigned char padding_22[2];
    unsigned short sequence;
    unsigned short tag;
    void* user_data;
};
void* SetLookupFields_02205134(void*, void*, int);
int TailCall0220520cField68_0220528c(Obj0220528c*, void*);
extern "C" unsigned short func_ov031_02203078();
extern "C" void func_ov031_02206584();

// USA: func_ov031_02206410
extern "C" ARM int func_ov031_02206410(TransferContext02206410* self, const unsigned char* source, int length, int offset, unsigned short tag, void* user_data, int flags) {
    TransferBuffer02206410* buffer = self->buffer;
    TransferRecord02206410* record = (TransferRecord02206410*)SetLookupFields_02205134((void*)func_ov031_02206584, buffer->callback, flags);
    if (!record) return -33;
    if ((flags & 1) && self->mode != 1) record->flags = 3;
    else record->flags = 0;
    unsigned char* base = buffer->data;
    int capacity = buffer->capacity;
    int end = offset + length;
    if (end < capacity) {
        record->first_data = base + offset;
        record->first_size = length;
        record->second_data = 0;
        offset = end;
        record->second_size = 0;
    } else {
        record->first_data = base + offset;
        record->first_size = capacity - offset;
        record->second_data = base;
        offset = length - record->first_size;
        record->second_size = offset;
        VectorizedInvertedMemcpy(source + record->first_size, record->second_data, offset);
    }
    VectorizedInvertedMemcpy(source, record->first_data, record->first_size);
    unsigned short old_position = buffer->position;
    record->position = offset;
    buffer->position = record->position;
    if (self->mode == 1) {
        if (self->pending_sequence == 0) {
            self->pending_sequence = func_ov031_02203078();
            self->sequence = self->pending_sequence;
        }
        record->sequence = self->pending_sequence;
        if (self->pending_data == 0 || user_data != 0) {
            record->user_data = user_data;
            record->tag = tag;
        } else {
            record->user_data = self->pending_data;
            record->tag = self->pending_tag;
        }
    } else record->user_data = 0;
    if (TailCall0220520cField68_0220528c(buffer->callback, record)) {
        length = 0;
        buffer->position = old_position;
    }
    return length;
}
