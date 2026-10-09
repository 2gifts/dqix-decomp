#include <globaldefs.h>

struct Container020e0310;

struct EquipmentMenu {
    char unk_0[0xdf8];
    char strings_[0xf84 - 0xdf8];
    short menuWidth_;
    short menuHeight_;
    short menuX_;
    short menuY_;
    char unk_f8c[0x3dbb - 0xf8c];
    signed char slot_;
    char unk_3dbc[0x3ddc - 0x3dbc];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
};

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" int func_020420e8(const char* text, int large);
void AppendNameTag(char* text, int item, const char* itemText);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);

// USA: func_ov005_02159a30
extern "C" ARM void func_ov005_02159a30(EquipmentMenu* self, char* text, int framed) {
    if (text == NULL)
        return;
    int choice = self->menuChoice_;
    if (framed)
        _Z22AppendFrameTag02041c08Pciiiii(text, choice, 8, 5, 5, 5);
    AppendCursorTag(text, choice);
    int count = 4;
    int shifted = 0;
    if (self->slot_ >= 0 && self->slot_ < 8) {
        count--;
        shifted = 1;
    }
    Container020e0310* strings = (Container020e0310*)self->strings_;
    const char* separator = _Z21GetFieldByKey020e0434P17Container020e0310i(strings, 0x64);
    int maxWidth = 0;
    for (int i = 0; i < count; i++) {
        short key = i;
        if (shifted) {
            key++;
            if (i == 0)
                key = 4;
        }
        const char* name = _Z21GetFieldByKey020e0434P17Container020e0310i(strings, key);
        int width = func_020420e8(name, 0);
        if (maxWidth < width)
            maxWidth = width;
        AppendNameTag(text, i, name);
        if (i != count - 1)
            _Z20AppendString02042058PcPKc(text, separator);
    }
    int tiles = ((maxWidth + 0x1b) & ~7) >> 3;
    tiles += tiles & 1;
    self->menuWidth_ = tiles;
    self->menuHeight_ = 7;
    self->menuX_ = (0x20 - tiles) >> 1;
    self->menuY_ = 9;
}
