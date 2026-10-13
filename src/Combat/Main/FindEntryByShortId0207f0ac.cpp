#include <globaldefs.h>

struct Entry0207f0ac {
    char pad[8];
    short id;
    char pad2[0x18 - 0xa];
};

struct List0207f0ac {
    struct Entry0207f0ac* entries;
    short count;
};

static inline struct Entry0207f0ac* GetEntry0207f0ac(struct List0207f0ac* list, unsigned int index) {
    return &list->entries[index];
}

// USA: func_0207f0ac
ARM struct Entry0207f0ac* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id) {
    short i;
    struct Entry0207f0ac* e;
    if (id < 0) {
        return NULL;
    }
    for (i = 0; i < list->count; i++) {
        e = GetEntry0207f0ac(list, i);
        if (id == e->id) {
            return e;
        }
    }
    return NULL;
}
