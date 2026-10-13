#include <globaldefs.h>

struct TableA68;
struct TextItem020806d8 {
    unsigned int unknown0;
    short id;
    short horizontalOffset;
    char unknown8[6];
    short textId;
    char unknown10[2];
    unsigned char kind;
    unsigned char fontSize : 4;
    unsigned char unknown13 : 4;
};
struct Entry0207f0ac020806d8 {
    char unknown0[0xe];
    short tileWidth;
};
struct List0207f6ac {
    TextItem020806d8* entries;
    short count;
};
struct List0207f0ac {
    Entry0207f0ac020806d8* entries;
    short count;
};
struct ObjSublist020806d8 {
    TableA68* textTable;
    List0207f6ac items;
    List0207f0ac groups;
};

void* FindEntryByShortId0207f6ac(List0207f6ac*, int);
Entry0207f0ac020806d8* FindEntryByShortId0207f0ac(List0207f0ac*, int);
void* FindEntryByKey(TableA68*, int);
#if defined(jpn)
int StringLength(const char*);
#else
int IsValueEqual12(int);
extern "C" int func_020420e8(char* text, int fontIndex);
#endif

// USA: func_020806d8  (semantic: UpdateSublistEntryField6020806d8)
extern "C" ARM void func_020806d8(ObjSublist020806d8* menu, int groupId, int itemId, int alignRight, short marginPixels) {
    TextItem020806d8* item = (TextItem020806d8*)FindEntryByShortId0207f6ac(&menu->items, itemId);
    if (item == NULL) return;
    if (!alignRight) {
        item->horizontalOffset = marginPixels;
        return;
    }
    if (item->kind != 0) return;
    char* text = (char*)FindEntryByKey(menu->textTable, item->textId);
    if (text == NULL) return;
#if defined(jpn)
    int glyphCount = StringLength(text) >> 1;
    int textWidth = glyphCount * item->fontSize;
#else
    int fontIndex = IsValueEqual12(item->fontSize);
    int textWidth = func_020420e8(text, fontIndex);
#endif
    Entry0207f0ac020806d8* group = FindEntryByShortId0207f0ac(&menu->groups, groupId);
    if (group == NULL) return;
    short groupWidthPixels = group->tileWidth << 3;
    item->horizontalOffset = groupWidthPixels - textWidth - marginPixels;
}
