#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Zeroable02169a40;
extern "C" void _Z18ZeroStruct02169a40P16Zeroable02169a40(struct Zeroable02169a40* s);

struct Node0216a438 {
    unsigned short* data;
    unsigned short count;
    unsigned int reserved8;
    struct Node0216a438* next;
};

struct Struct02184264_0216a438 {
    struct Node0216a438* head;
    struct Node0216a438* tail;
    SafeAllocator* alloc;
};
extern struct Struct02184264_0216a438 data_ov000_02184264;

// USA: func_ov000_0216a438
extern "C" ARM int func_ov000_0216a438(void) {
    struct Node0216a438* node = (struct Node0216a438*)data_ov000_02184264.alloc->Allocate(0x10);
    _Z18ZeroStruct02169a40P16Zeroable02169a40((struct Zeroable02169a40*)node);
    node->count = 3;
    node->data = (unsigned short*)data_ov000_02184264.alloc->Allocate(node->count * 2);
    node->data[0] = 1;
    node->data[1] = 2;
    node->data[2] = 0xdb;
    struct Node0216a438* tail = data_ov000_02184264.tail;
    if (tail == 0) {
        data_ov000_02184264.tail = node;
    } else {
        tail->next = node;
        data_ov000_02184264.tail = node;
    }
    if (!data_ov000_02184264.head) {
        data_ov000_02184264.head = node;
    }
    return 1;
}
