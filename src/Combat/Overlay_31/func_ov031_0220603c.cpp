#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/ProcessorContext.h"
#include "System/Memory.h"

struct Packet0220603c {
    Packet0220603c* next;
    unsigned short length, type;
    unsigned int metadata;
    unsigned char payload[1];
};
struct PacketQueue0220603c {
    char pad_0[0x100];
    union { Packet0220603c* last; signed int lastAddress; };
    Packet0220603c* first;
    unsigned short used, capacity;
    BlockedContextList blocked;
};
struct PacketContext0220603c {
    char pad_0[0xa]; unsigned short initialPending;
    char pad_c[0xc]; unsigned short type, resetType;
    unsigned int metadata, resetMetadata;
    char pad_24[0x40]; PacketQueue0220603c* queue;
    char pad_68[0xc]; unsigned short pending;
};
struct PacketAllocator0220603c {
    char pad_0[0x18]; void* (*allocate)(int);
};
struct PacketErrors0220603c { unsigned int allocation, capacity; };
extern PacketAllocator0220603c* data_ov031_022496a4;
extern PacketErrors0220603c data_ov031_0224e224;

// USA: func_ov031_0220603c
extern "C" ARM int func_ov031_0220603c(const void* source, unsigned int length, PacketContext0220603c* context) {
    PacketQueue0220603c* queue = context->queue;
    Packet0220603c* packet;
    int interruptState = DisableIRQInterrupts();
    if (queue->capacity >= queue->used + length) {
        packet = (Packet0220603c*)data_ov031_022496a4->allocate(length + 0xc);
        if (packet) {
            queue->used += length;
            packet->next = 0;
            packet->length = length;
            packet->type = context->type;
            packet->metadata = context->metadata;
            VectorizedInvertedMemcpy(source, packet->payload, length);
            if (queue->lastAddress) queue->last->next = packet;
            queue->last = packet;
            if (!queue->first) queue->first = packet;
        } else data_ov031_0224e224.allocation++;
    } else {
        data_ov031_0224e224.capacity++;
    }
    if (!context->pending) context->pending = context->initialPending;
    context->type = context->resetType;
    context->metadata = context->resetMetadata;
    UnblockContexts(&queue->blocked);
    SetIRQInterruptState(interruptState);
    return 1;
}
