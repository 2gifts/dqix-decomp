#include <globaldefs.h>
#if defined(jpn)
enum { kAllocatorOffset = 4, kOwnerOffset = 0xc, kListOffset = 0x6a8 };
#else
enum { kAllocatorOffset = 8, kOwnerOffset = 0x10, kListOffset = 0x754 };
#endif
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Variant02030b0c { int tag; union { int i; float f; } u; };

extern int data_020fdc4c;

struct Args0201f728 {
    struct TaggedValue02030b44 x;
    struct TaggedValue02030b44 y;
};

struct Node0201f728 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int x;
    int y;
    struct Node0201f728* next;
};

// USA: func_0201f728  (semantic: AllocateAndEnqueuePointVariantNode0201f728)
extern "C" ARM int func_0201f728(struct Args0201f728* arg0, int n) {
    if (n < 3) return 0;
    struct Node0201f728* node = (struct Node0201f728*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(0x14);
    if (node == 0) return 0;
    node->type = 1;
    node->count = n - 2;
    node->data = (short*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(node->count * 2);
    if (node->data == 0) return 0;
    node->x = (int)(((Script::Parameter*)&arg0->x)->ToFloat() * 4096.0f);
    struct Variant02030b0c* p = (struct Variant02030b0c*)((char*)arg0 + 0x10);
    node->y = (int)(((Script::Parameter*)&arg0->y)->ToFloat() * 4096.0f);
    for (int i = 0; i < node->count; i++) {
        node->data[i] = (short)((Script::Parameter*)p)->ToInt();
        p++;
    }
    struct Node0201f728* head = *(struct Node0201f728**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset);
    node->id = head ? head->id + 1 : 1;
    node->next = *(struct Node0201f728**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset);
    *(struct Node0201f728**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset) = node;
    return 1;
}
