#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>
#include "Resource/CharacterCreationUI.h"

struct EquipmentMenu {
    char unk_0[0xdf8];
    Container020e0310 messages;
    char unknownAfterMessages[LOW_REGION(0xf80, 0xf84) - 0xdf8 - sizeof(Container020e0310)];
    short menuWidth_;
    short menuHeight_;
    short menuX_;
    short menuY_;
    char unk_f8c[LOW_REGION(0x3d33 - 0xf88, 0x3dbb - 0xf8c)];
    signed char slot_;
    char unk_3dbc[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
};

void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag_02041ea4(char* text, int a);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
extern "C" int func_020420e8(const char* text, int large);
void AppendNameTag_02041b70(char* text, int item, const char* itemText);
void AppendString02042058(char* text, const char* append);

// USA: func_ov005_02159a30
extern "C" ARM void func_ov005_02159a30(EquipmentMenu* self, char* text, int framed) {
    if (text == NULL)
        return;
    int choice = self->menuChoice_;
    if (framed)
        AppendFrameTag02041c08(text, choice, 8, 5, 5, 5);
    AppendCursorTag_02041ea4(text, choice);
    int count = 4;
    int shifted = 0;
    if (self->slot_ >= 0 && self->slot_ < 8) {
        count--;
        shifted = 1;
    }
#if defined(jpn)
    for (int i = 0; i < count; i++) {
        if (shifted) {
            if (i == 0)
                AppendNameTag_02041b70(text, i, GetFieldByKey020e0434(&self->messages, 4));
            else
                AppendNameTag_02041b70(text, i, GetFieldByKey020e0434(&self->messages, (short)(i + 1)));
        } else {
            AppendNameTag_02041b70(text, i, GetFieldByKey020e0434(&self->messages, (short)i));
        }
        if (i != count - 1)
            AppendString02042058(text, GetFieldByKey020e0434(&self->messages, 0x64));
    }
#else
    Container020e0310* strings = &self->messages;
    const char* separator = GetFieldByKey020e0434(strings, 0x64);
    int maxWidth = 0;
    for (int i = 0; i < count; i++) {
        short key = i;
        if (shifted) {
            key++;
            if (i == 0)
                key = 4;
        }
        const char* name = GetFieldByKey020e0434(strings, key);
        int width = func_020420e8(name, 0);
        if (maxWidth < width)
            maxWidth = width;
        AppendNameTag_02041b70(text, i, name);
        if (i != count - 1)
            AppendString02042058(text, separator);
    }
    int tiles = ((maxWidth + 0x1b) & ~7) >> 3;
    tiles += tiles & 1;
    self->menuWidth_ = tiles;
    self->menuHeight_ = 7;
    self->menuX_ = (0x20 - tiles) >> 1;
    self->menuY_ = 9;
#endif
}
