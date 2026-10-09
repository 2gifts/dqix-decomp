#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"

struct EntryList_203dce4 {
    char pad[0xc];
    struct Entry_203dce4* entries[0x20];
};

// USA: func_0203dce4
ARM struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4* list, int id) {
    struct Entry_203dce4* entry;
    if ((unsigned int)id >= 0x20) {
        return 0;
    }
    entry = list->entries[id];
    if (entry != 0 && (entry->flags & 0x8000)) {
        entry = 0;
    }
    return entry;
}
