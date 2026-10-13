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

struct Entry0207f6ac {
    char pad_0[4];
    short id;
    short x;
    short y;
    short width;
    short height;
    char pad_e[4];
    unsigned char kind;
    char pad_13[5];
    Entry0207f6ac* down;
    Entry0207f6ac* up;
    Entry0207f6ac* right;
    Entry0207f6ac* left;
    short xOffset;
    unsigned char flags;
    char pad_2b[5];
};

struct List0207f0ac { Entry0207f0ac* entries; short count; };
struct List0207f6ac { Entry0207f6ac* entries; short count; };
struct Obj2081 {
    void* table;
    List0207f6ac items;
    List0207f0ac groups;
};

int IsPointInsideElement02080d54(Obj2081*, int, int, int);
Entry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac*, int);
Entry0207f6ac* FindEntryByShortId0207f6ac(List0207f6ac*, int);

// USA: func_02080e40

extern "C" ARM int func_02080e40(Obj2081* menu, int groupId, int pointX, int pointY) {
    if (!IsPointInsideElement02080d54(menu, groupId, pointX, pointY)) return -1;
    Entry0207f0ac* group = FindEntryByShortId0207f0ac(&menu->groups, groupId);
    if (!group) return -1;
    short groupX = group->tileX * 8;
    short groupY = group->tileY * 8;
    for (unsigned char i = 0; i < group->count; i++) {
        int id = group->entries[i];
        Entry0207f6ac* entry = FindEntryByShortId0207f6ac(&menu->items, id);
        if (!entry || entry->kind == 1) continue;
        if (entry->flags & 1) continue;
        if (!entry->down && !entry->up && !entry->right && !entry->left) continue;
        short left = entry->x + entry->xOffset;
        short top = entry->y;
        short right = left + entry->width;
        short bottom = top + entry->height;
        left += groupX;
        top += groupY;
        right += groupX;
        bottom += groupY;
        if (pointY < top) continue;
        if (bottom <= pointY) continue;
        if (pointX < left) continue;
        if (right > pointX) return id;
    }
    return -1;
}
