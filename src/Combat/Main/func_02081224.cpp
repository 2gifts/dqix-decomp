#include <globaldefs.h>

struct Entry0207f0ac {
    short* entries;
    char pad_4[0xc];
    short width;
    unsigned char field_12;
    unsigned char count;
    char pad_14[4];
};
struct Entry0207f6ac {
    char pad_0[8];
    short x;
    short y;
    short width;
    char pad_e[0x22];
};
struct List0207f0ac { Entry0207f0ac* entries; short count; };
struct List0207f6ac { Entry0207f6ac* entries; short count; };
struct Obj2081 {
    void* table;
    List0207f6ac items;
    List0207f0ac groups;
};
Entry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac*, int);
Entry0207f6ac* FindEntryByShortId0207f6ac(List0207f6ac*, int);
extern "C" int func_020813ec(void*, int);
void CallFunc0204c804OnMatchingKey(Obj2081*, int);

// USA: func_02081224
extern "C" ARM void func_02081224(Obj2081* object, int id) {
    int ids[8];
    int positions[8];
    int widths[8];
    Entry0207f0ac* group = FindEntryByShortId0207f0ac(&object->groups, id);
    if (!group) return;
    func_020813ec(object, id);
    int count = 0;
    int total = group->count;
    int i = 0;
    for (; i < total; i++) {
        int entryId = group->entries[i];
        Entry0207f6ac* entry = FindEntryByShortId0207f6ac(&object->items, entryId);
        if (entry) {
            ids[count] = entryId;
            positions[count] = entry->x;
            widths[count] = entry->width;
            count++;
        }
    }
    if (count <= 1) return;
    for (int first = 0; first < count - 1; first++) {
        for (int second = first + 1; second < count; second++) {
            if (positions[second] < positions[first]) {
                int position = positions[first];
                positions[first] = positions[second];
                int entryId = ids[first];
                int width = widths[first];
                ids[first] = ids[second];
                ids[second] = entryId;
                positions[second] = position;
                widths[first] = widths[second];
                widths[second] = width;
            }
        }
    }
    int usedWidth = 0;
    for (int index = 0; index < count; index++) usedWidth += widths[index];
    int availableWidth = group->width * 8;
    if (availableWidth <= usedWidth) return;
    int extraWidth = availableWidth - usedWidth;
    int spacing = extraWidth / (count - 1);
    int remainder = extraWidth % (count - 1);
    while (remainder < 12) {
        remainder += count - 1;
        spacing--;
    }
    int position = remainder >> 1;
    for (int index = 0; index < count; index++) {
        Entry0207f6ac* entry = FindEntryByShortId0207f6ac(&object->items, (short)ids[index]);
        if (entry) {
            entry->x = position;
            position += spacing + entry->width;
        }
    }
    CallFunc0204c804OnMatchingKey(object, id);
}
