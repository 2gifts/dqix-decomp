#include <globaldefs.h>

struct FindEntryByKindEntry020d3d90 {
#if defined(jpn)
    unsigned char pad[0xb];
#else
    unsigned char pad[0x10];
#endif
    unsigned char kind : 3;
    unsigned char : 5;
#if defined(jpn)
    unsigned char pad2[0x14];
#else
    unsigned char pad2[0x13];
#endif
};

struct FindEntryByKindContainer020d3d90 {
    struct FindEntryByKindEntry020d3d90 entries[5];
    int count;
};

// USA: func_020d3d90
ARM struct FindEntryByKindEntry020d3d90* FindEntryByKind(struct FindEntryByKindContainer020d3d90* c, int kind) {
    struct FindEntryByKindEntry020d3d90* e = c->entries;
    int i;
    for (i = 0; i < c->count; i++) {
        if (e->kind == kind) return e;
        e++;
    }
    return NULL;
}
