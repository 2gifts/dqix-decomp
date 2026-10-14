#include <globaldefs.h>

struct Entry_1f170 {
    signed short id;
    char unk[0xa];
};

struct EntryList_1f170 {
    struct Entry_1f170* entries;
    int count;
};

// USA: func_0201f170
ARM struct Entry_1f170* FindEntryBySignedId_0201f170(struct EntryList_1f170* list, int id) {
    int i;
    for (i = 0; i < list->count; i++) {
        if (id == list->entries[i].id) {
            return &list->entries[i];
        }
    }
    return 0;
}
