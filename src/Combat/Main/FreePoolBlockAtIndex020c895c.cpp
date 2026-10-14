#include <globaldefs.h>
#include "System/Interrupts.h"

struct RemoveNodeEntry;
RemoveNodeEntry* RemoveNode_020c8784(RemoveNodeEntry* head, RemoveNodeEntry* node);

struct FreeBlock020c87ac;
FreeBlock020c87ac* InsertFreeBlock020c87ac(FreeBlock020c87ac* head, FreeBlock020c87ac* blk);

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

// USA: func_020c895c  (semantic: FreePoolBlockAtIndex020c895c)
extern "C" ARM void func_020c895c(int tableIdx, int count, char* addr) {
    struct PoolTable020c895c* table;
    struct SubEntry020c895c* entry;
    char* blk;
    int state = DisableIRQInterrupts();
    table = data_02111564[tableIdx];
    if (count < 0) {
        count = table->defaultCount;
    }
    entry = &table->entries[count];
    blk = addr - 0x20;
    entry->usedList = RemoveNode_020c8784(entry->usedList, (struct RemoveNodeEntry*)blk);
    entry->freeList = InsertFreeBlock020c87ac(entry->freeList, (struct FreeBlock020c87ac*)blk);
    SetIRQInterruptState(state);
}
