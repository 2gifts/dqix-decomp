#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0202a6c4 {
    int type;
    char text[0x30];
    Entry0202a6c4* next;
    char padding_38[8];
    int value;
    char padding_44[8];
    unsigned short flags;
};

struct Menu0202a6c4 {
    int type;
    char text[0x40];
    Entry0202a6c4* entries;
    char padding_48[8];
    short top;
    short field_52;
    short width;
    short height;
    short field_58;
    unsigned short count;
    short firstSelection;
    short lastSelection;
    short field_60;
    unsigned short visibleCount;
    short visibleFirst;
    short visibleLast;
};

struct Metrics0202a6c4 {
    int field_0;
    int rowHeight;
    int columnWidth;
    int font;
};

extern Metrics0202a6c4 data_020ef74c;
extern char data_020ef772[];
extern char data_020ef775[];
extern "C" int func_020420e8(const char*, int);
#if defined(jpn)
extern "C" void func_02028ce4(const char*, int*, int*);
#endif

static inline int VisibleSelectionRemainder(int last, int first, unsigned int count, unsigned int visible) {
    return visible - (count - (last - first));
}

// USA: func_0202a6c4
extern "C" ARM void func_0202a6c4(Menu0202a6c4* menu) {
    char number[16];
    int width = strlen(menu->text);
    if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
        int measured;
        #if defined(jpn)
        int height;
        func_02028ce4(menu->text, &measured, &height);
#else
        if (menu->text != NULL) measured = func_020420e8(menu->text, 1);
#endif
        measured /= data_020ef74c.columnWidth;
        width = measured;
    }
    Entry0202a6c4* entry = menu->entries;
    int index = 0;
    while (entry != NULL) {
        int length;
        if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
            int measured;
            #if defined(jpn)
            int height;
            func_02028ce4(entry->text, &measured, &height);
#else
            if (entry->text != NULL) measured = func_020420e8(entry->text, 1);
#endif
            measured /= data_020ef74c.columnWidth;
            length = measured;
            if (menu->firstSelection >= 0 && menu->firstSelection <= menu->lastSelection &&
                menu->firstSelection <= index && index <= menu->lastSelection)
                length += 2;
            if (entry->type == 2) length += 6;
            if (entry->type == 3) {
                length += 4;
                if (entry->flags & 0x80)
                    sprintf(number, data_020ef772, entry->value + 0x40);
                else
                    sprintf(number, data_020ef775, entry->value);
                length += strlen(number) * 2;
            }
        } else {
            length = strlen(entry->text);
            if (menu->firstSelection >= 0 && menu->firstSelection <= menu->lastSelection &&
                menu->firstSelection <= index && index <= menu->lastSelection)
                length++;
            if (entry->type == 2) length += 3;
        }
        if (width < length) width = length;
        entry = entry->next;
        ++index;
    }
    menu->width = (width + 3) * data_020ef74c.columnWidth;
    menu->height = (menu->count + 3) * data_020ef74c.rowHeight;
    if (menu->top + menu->height > 192)
        menu->height = 192 - menu->top - data_020ef74c.rowHeight;
    menu->visibleCount = menu->height / data_020ef74c.rowHeight - 2;
    short first = menu->firstSelection;
    int remaining = VisibleSelectionRemainder(menu->lastSelection, first, menu->count, menu->visibleCount);
    menu->visibleFirst = first;
    menu->visibleLast = first + remaining;
}
