#include <globaldefs.h>

struct List0207f0ac;
struct List0207f6ac;

struct SubList02080608 {
    short* keys;
    char pad[0x13 - 0x4];
    unsigned char count;
};

extern struct SubList02080608* FindEntryByShortId0207f0ac(struct List0207f0ac* list, int id);
extern void SetEntryFlagBits0207f7ac(struct List0207f6ac* list, int id, int mask);

// USA: func_02080608
ARM void SetSublistEntriesFlag2(void* obj, int id) {
    struct SubList02080608* sub;
    unsigned char i;
    sub = FindEntryByShortId0207f0ac((struct List0207f0ac*)((char*)obj + 0xc), id);
    if (sub == NULL) return;
    for (i = 0; i < sub->count; i++) {
        SetEntryFlagBits0207f7ac((struct List0207f6ac*)((char*)obj + 4), sub->keys[i], 2);
    }
}

// JPN: 0x02081130
