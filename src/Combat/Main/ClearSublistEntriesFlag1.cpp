#include <globaldefs.h>

struct List0207f0ac;
struct List0207f6ac;

struct SubList02080bac {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

extern struct SubList02080bac* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
extern void ClearEntryFlagBits0207f7cc(struct List0207f6ac* list, int id, int mask);

// USA: func_02080bac
ARM void ClearSublistEntriesFlag1_02080bac(void* obj, int id) {
    struct SubList02080bac* sub;
    short i;
    sub = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        ClearEntryFlagBits0207f7cc((struct List0207f6ac*)((char*)obj + 4), sub->keys[i], 1);
    }
}
