#include <globaldefs.h>

struct List0207f6ac {
    void* entries;
    short count;
};

struct Entry0207f72c;

union Ref0207f72c {
    short id;
    struct Entry0207f72c* ptr;
};

struct Entry0207f72c {
    char pad[0x18];
    union Ref0207f72c refs[4];
};

extern void* GetElementStride0x30_0207f700(unsigned char* obj, short index);
extern struct Entry0207f72c* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int id);

// USA: func_0207f72c
ARM void ResolveEntryRefs0207f72c(struct List0207f6ac* list) {
    short count = list->count;
    short i;
    for (i = 0; i < count; i++) {
        struct Entry0207f72c* e = (struct Entry0207f72c*)GetElementStride0x30_0207f700((unsigned char*)list, i);
        if (e != NULL) {
            e->refs[0].ptr = FindEntryByShortId0207f6ac(list, e->refs[0].id);
            e->refs[1].ptr = FindEntryByShortId0207f6ac(list, e->refs[1].id);
            e->refs[2].ptr = FindEntryByShortId0207f6ac(list, e->refs[2].id);
            e->refs[3].ptr = FindEntryByShortId0207f6ac(list, e->refs[3].id);
        }
    }
}
