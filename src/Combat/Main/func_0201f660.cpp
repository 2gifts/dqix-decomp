#include <globaldefs.h>

#if defined(jpn)
enum { kAllocatorOffset = 0x4, kOwnerOffset = 0xc, kListOffset = 0x6a8 };
#else
enum { kAllocatorOffset = 0x8, kOwnerOffset = 0x10, kListOffset = 0x754 };
#endif

#include "Memory/SafeAllocator.h"

struct Variant02030b0c { int tag; union { int i; float f; } u; };
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern int data_020fdc4c;

struct Node0201f660 {
    unsigned char type;
    unsigned char id;
    unsigned char count;
    unsigned char pad3;
    short* data;
    int padx;
    int pady;
    struct Node0201f660* next;
};

// USA: func_0201f660
extern "C" ARM int func_0201f660(struct Variant02030b0c* arr, int count) {
    struct Node0201f660* node = (struct Node0201f660*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(0x14);
    if (node == 0) return 0;
    node->type = 0;
    node->count = count;
    node->data = (short*)
        ((SafeAllocator*)*(char**)((char*)&data_020fdc4c + kAllocatorOffset))->Allocate(node->count * 2);
    if (node->data == 0) return 0;
    for (int i = 0; i < node->count; i++) {
        node->data[i] = (short)_ZNK6Script9Parameter5ToIntEv(arr);
        arr++;
    }
    struct Node0201f660* head = *(struct Node0201f660**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset);
    node->id = head ? head->id + 1 : 1;
    node->next = *(struct Node0201f660**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset);
    *(struct Node0201f660**)((char*)(*(void**)((char*)&data_020fdc4c + kOwnerOffset)) + kListOffset) = node;
    return 1;
}
