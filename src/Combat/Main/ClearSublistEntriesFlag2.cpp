#include <globaldefs.h>

struct Entry0207f0ac {
    short* entries;
    char pad_4[4];
    short id;
    short tileX;
    short tileY;
    char pad_e[5];
    unsigned char count;
    char pad_14[4];
};
struct Entry0207f6ac;
struct List0207f0ac { Entry0207f0ac* entries; short count; };
struct List0207f6ac { Entry0207f6ac* entries; short count; };
struct MenuState0208065c {
    void* table;
    List0207f6ac items;
    List0207f0ac groups;
};

extern Entry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac* list, int id);
extern void ClearEntryFlagBits0207f7cc(struct List0207f6ac* list, int id, int mask);

// USA: func_0208065c
ARM void ClearSublistEntriesFlag2_0208065c(void* obj, int id) {
    MenuState0208065c* menu = (MenuState0208065c*)obj;
    Entry0207f0ac* group = FindEntryByShortId0207f0ac(&menu->groups, id);
    if (group == NULL) return;
    for (unsigned char i = 0; i < group->count; i++) {
        ClearEntryFlagBits0207f7cc(&menu->items, group->entries[i], 2);
    }
}
