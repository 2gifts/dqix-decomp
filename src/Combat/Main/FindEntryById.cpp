#include <globaldefs.h>

struct Entry_1e690 {
    unsigned short id;
    char unk[0x72];
};

struct EntryList_1e690 {
    char unk[0x24];
    struct Entry_1e690* entries;
    int count;
};

// USA: func_0201e690
ARM struct Entry_1e690* FindEntryById_0201e690(struct EntryList_1e690* list, int id) {
    struct Entry_1e690* entry;
    int i;
    if (id < 0) {
        return 0;
    }
    entry = list->entries;
    for (i = 0; i < list->count; i++, entry++) {
        if (entry->id == id) {
            return entry;
        }
    }
    return 0;
}
