#include <globaldefs.h>
#include "System/Interrupts.h"

struct RemoveNodeEntry;
RemoveNodeEntry* RemoveNode_020c8784(RemoveNodeEntry* head, RemoveNodeEntry* node);

struct DListNode;
DListNode* InsertNodeAtHead_020c8768(DListNode* oldHead, DListNode* newNode);

struct FreeBlock020c87ac {
    struct FreeBlock020c87ac* prev;
    struct FreeBlock020c87ac* next;
    unsigned int size;
};

struct SubEntry020c895c {
    int unk0;
    struct FreeBlock020c87ac* freeList;
    struct RemoveNodeEntry* usedList;
};

struct PoolTable020c895c {
    int defaultCount;
    char pad4[0xc];
    struct SubEntry020c895c* entries;
};

extern struct PoolTable020c895c* data_02111564[];

// USA: func_020c8854  (semantic: AllocPoolBlockAtIndex_020c8854)
extern "C" ARM void* func_020c8854(int tableIdx, int count, int size) {
    struct PoolTable020c895c* table;
    struct SubEntry020c895c* entry;
    struct FreeBlock020c87ac* cursor;
    int state;
    state = DisableIRQInterrupts();
    table = data_02111564[tableIdx];
    if (table == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    if (count < 0) {
        count = table->defaultCount;
    }
    entry = &table->entries[count];
    cursor = entry->freeList;
    size = (size + 0x3f) & ~0x1f;
    if (cursor != 0) {
        do {
            if (size <= (int)cursor->size) break;
            cursor = cursor->next;
        } while (cursor != 0);
    }
    if (cursor == 0) {
        SetIRQInterruptState(state);
        return 0;
    }
    unsigned int remaining = cursor->size - size;
    if (remaining < 0x40) {
        entry->freeList = (struct FreeBlock020c87ac*)RemoveNode_020c8784((struct RemoveNodeEntry*)entry->freeList, (struct RemoveNodeEntry*)cursor);
    } else {
        cursor->size = size;
        struct FreeBlock020c87ac* newBlock = (struct FreeBlock020c87ac*)((char*)cursor + size);
        newBlock->size = remaining;
        newBlock->prev = cursor->prev;
        newBlock->next = cursor->next;
        if (newBlock->next != 0) {
            newBlock->next->prev = newBlock;
        }
        if (newBlock->prev != 0) {
            newBlock->prev->next = newBlock;
        } else {
            entry->freeList = newBlock;
        }
    }
    entry->usedList = (struct RemoveNodeEntry*)InsertNodeAtHead_020c8768((struct DListNode*)entry->usedList, (struct DListNode*)cursor);
    SetIRQInterruptState(state);
    return (char*)cursor + 0x20;
}
