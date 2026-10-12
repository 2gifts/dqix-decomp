#include <globaldefs.h>

struct Entry0207f0ac {
    short* entries;
    char pad_4[4];
    short id;
    short x;
    short y;
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
    unsigned char disabled;
    char pad_13[5];
    void* graphics0;
    void* graphics1;
    void* graphics2;
    void* graphics3;
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
// JPN: func_02081940
extern "C" ARM int func_02080e40(Obj2081* object, int key, int px, int py) {
    if (!IsPointInsideElement02080d54(object, key, px, py)) return -1;
    Entry0207f0ac* group = FindEntryByShortId0207f0ac(&object->groups, key);
    if (!group) return -1;
    short groupX = group->x * 8;
    short groupY = group->y * 8;
    for (unsigned char i = 0; i < group->count; i++) {
        int id = group->entries[i];
        Entry0207f6ac* entry = FindEntryByShortId0207f6ac(&object->items, id);
        if (!entry || entry->disabled == 1) continue;
        if (entry->flags & 1) continue;
        if (!entry->graphics0 && !entry->graphics1 && !entry->graphics2 && !entry->graphics3) continue;
        short left = entry->x + entry->xOffset;
        short top = entry->y;
        short right = left + entry->width;
        short bottom = top + entry->height;
        left += groupX;
        top += groupY;
        right += groupX;
        bottom += groupY;
        if (py < top) continue;
        if (bottom <= py) continue;
        if (px < left) continue;
        if (right > px) return id;
    }
    return -1;
}
