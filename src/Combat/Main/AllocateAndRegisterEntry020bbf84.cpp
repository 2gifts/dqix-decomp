#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Obj020bda58;
extern void* AllocateAndLinkEntry020bda58(struct Obj020bda58* obj, unsigned int size, int a2, int a3, int a4);

extern void* CreateAllocatorHolderInRegion(void* start, unsigned int size);

struct Obj020bc820;
#if defined(jpn)
extern "C" void func_020be2ec(struct Obj020bc820* obj);
#define ReleaseActorAndUnlink020bc820 func_020be2ec
#else
extern void ReleaseActorAndUnlink020bc820(struct Obj020bc820* obj);
#endif

struct Block020bbf84 {
    char pad0[8];
    void* alloc;      /* 0x8 */
    void* child;      /* 0xc */
    int index;        /* 0x10 */
    char region[4];   /* 0x14 */
};

struct ListEntry020bbf84 {
    char pad0[0xc];
    SignedAllocatorList list; /* 0xc */
    char pad2[0xc];
};
extern struct ListEntry020bbf84 data_0210f824[];

// JPN: func_020bda50
// USA: func_020bbf84
#pragma optimize_for_size off
ARM int AllocateAndRegisterEntry020bbf84(int index, struct Obj020bda58* obj, unsigned int size) {
    Block020bbf84* block = (Block020bbf84*)AllocateAndLinkEntry020bda58(obj, size + 0x14, (int)&ReleaseActorAndUnlink020bc820, 0, 0);
    if (block == NULL) {
        return 0;
    }
    block->child = NULL;
    block->index = index;
    block->alloc = NULL;
    void* allocator = CreateAllocatorHolderInRegion(&block->region[0], size);
    if (allocator == NULL) {
        return 0;
    }
    block->alloc = allocator;
    data_0210f824[index].list.InsertAtEnd((SignedAllocatorHeader*)block);
    return 1;
}
