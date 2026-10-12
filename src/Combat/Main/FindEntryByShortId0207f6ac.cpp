#include <globaldefs.h>

struct Entry0207f6ac {
    char pad[4];
    short id;
    char pad2[0x30 - 0x6];
};

struct List0207f6ac {
    struct Entry0207f6ac* entries;
    short count;
};

static inline struct Entry0207f6ac* GetEntry0207f6ac(struct List0207f6ac* list, unsigned int index) {
    return &list->entries[index];
}

// USA: func_0207f6ac
ARM struct Entry0207f6ac* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id) {
    short i;
    struct Entry0207f6ac* e;
    if (id < 0) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        e = GetEntry0207f6ac(list, i);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
