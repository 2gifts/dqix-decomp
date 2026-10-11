#include <globaldefs.h>

struct ActorEntry {
    char unk[0x368];
};

struct ActorListManager {
#if defined(jpn)
    char unk[0x496];
#else
    char unk[0x476];
#endif
    unsigned char count;
    char unk477[0x1];
    struct ActorEntry* entries;
};

// USA: func_0201777c
ARM struct ActorEntry* GetActorEntryByIndex(struct ActorListManager* manager, int index) {
    struct ActorEntry* entry;
    if (index < 0 || manager->count <= index) {
        entry = 0;
    } else {
        entry = &manager->entries[index];
    }
    return entry;
}
