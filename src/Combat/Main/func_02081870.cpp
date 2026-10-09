#include <globaldefs.h>
#include <std_library_functions.h>

struct TableA68;
struct Obj02046574;
struct TextRenderer {
    TableA68* strings;
    char pad_4[0x14];
    char* buffer;
};
struct TextWindow {
    char pad_0[0xa8];
    short width;
    char pad_aa[0xa];
    short firstFont;
    short lastFont;
};
struct TextItem {
    char* name;
    short id;
    short x;
    short y;
    short width;
    short height;
    short stringId;
    short nameIndex;
    unsigned char field_12;
    unsigned char font : 4;
    unsigned char color : 4;
    unsigned char alignment : 2;
    unsigned char field_14 : 6;
    char pad_15[0x13];
    short xOffset;
    unsigned char flags;
};
int IsValueEqual12(int);
void* FindEntryByKey(TableA68*, int);
extern "C" int func_020420e8(char*, int);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(Obj02046574*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" void func_02046608(Obj02046574*, int, void*, char*, int, int, int);
extern "C" void func_0204f41c(TextWindow*, short, int, char*, int, int, short*, short*, int);

// USA: func_02081870
extern "C" ARM void func_02081870(TextRenderer* renderer, TextWindow* window, TextItem* item) {
    int color = item->color;
    if (item->flags & 4) color = 5;
    int font = IsValueEqual12(item->font);
    if (item->flags & 8) {
        char* text = (char*)FindEntryByKey(renderer->strings, item->stringId);
        if (text) {
            short width = window->width * 8;
            item->x = (short)(width - func_020420e8(text, font)) >> 1;
        }
    }
    Obj02046574* formatter = (Obj02046574*)_Z26GetGlobalField0x1c020421a0v();
    memset(renderer->buffer, 0, 0x960);
    func_02046380(formatter);
    _Z22SetIndexedName02046574P11Obj02046574iPc(formatter, item->nameIndex, item->name);
    void* text = FindEntryByKey(renderer->strings, item->stringId);
    func_02046608(formatter, item->font, text, renderer->buffer, 0x100, 0, 0);
    int firstFont = item->font;
    window->firstFont = firstFont;
    window->lastFont = firstFont + 1;
    if (item->flags & 0x10) {
        int selectedFont = item->font;
        if (selectedFont == 12) {
            window->firstFont = selectedFont;
            window->lastFont = 20;
        }
    }
    int offset = 0;
    if (item->alignment) offset = func_020420e8(renderer->buffer, 0);
    func_0204f41c(window, (short)(item->x + item->xOffset - offset), item->y,
        renderer->buffer, item->font, color, &item->width, &item->height, 0);
}
