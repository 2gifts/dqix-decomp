#include <globaldefs.h>

int StringLength(const char*);

struct TableA68;
struct List0207f6ac {
    void* entries;
    short count;
    short capacity;
};

struct MenuEntryContainer {
    TableA68* textTable;
    List0207f6ac entries;
};

extern void* FindEntryByShortId0207f6ac(struct List0207f6ac* list, int entryId);
extern void* FindEntryByKey(struct TableA68* table, int key);
extern int IsValueEqual12(int x);
extern "C" int func_020420e8(void* value, int flag);

struct Entry020808c8 {
    const char* literalText;
    char pad1[0xa - 4];
    short width;
    short height;
    short textId;
    char pad2[0x12 - 0x10];
    unsigned char kind;
    unsigned char fontSize : 4;
    unsigned char unknown13 : 4;
};

// USA: func_020808c8

ARM void GetEntryOutputs020808c8(void* container, int entryId, short* width, short* height) {
    MenuEntryContainer* menu = static_cast<MenuEntryContainer*>(container);
    struct Entry020808c8* entry = (struct Entry020808c8*)FindEntryByShortId0207f6ac(&menu->entries, entryId);
    if (entry == NULL) {
        return;
    }

#if !defined(jpn)
    int isTwelve = IsValueEqual12(entry->fontSize);
#endif
    int kind = entry->kind;

    switch (kind) {
    case 0: {
        void* found = FindEntryByKey(menu->textTable, entry->textId);
        if (found == NULL) {
            return;
        }
#if defined(jpn)
        int glyphUnits = StringLength((const char*)found) >> 1;
        int glyphPixels = entry->fontSize;
        *width = (short)(glyphUnits * glyphPixels);
#else
        *width = (short)func_020420e8(found, isTwelve);
#endif
        *height = entry->fontSize;
        break;
    }
    case 1:
        *width = entry->width;
        *height = entry->height;
        break;
    case 4: {
        if (entry->literalText == NULL) {
            return;
        }
#if defined(jpn)
        int glyphUnits = StringLength(entry->literalText) >> 1;
        int glyphPixels = entry->fontSize;
        *width = (short)(glyphUnits * glyphPixels);
#else
        *width = (short)func_020420e8(const_cast<char*>(entry->literalText), isTwelve);
#endif
        *height = entry->fontSize;
        break;
    }
    default:
        *height = 0;
        *width = 0;
        break;
    }
}
