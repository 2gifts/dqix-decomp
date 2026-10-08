#include <globaldefs.h>

struct UnkStruct0205c508;
struct TableA68;

struct Cursor02189dfc
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct ProfileEditor02189dfc
{
    char unk_0[0xac];
    char window_[0x133c - 0xac];
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unk_137c[0x13c0 - 0x137c];
    signed char* unk_13c0;
    unsigned short unk_13c4_0 : 5;
    unsigned short unk_13c4_5 : 11;
    char unk_13c6[0x13d8 - 0x13c6];
    int selections_[6];
};

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXYTag(char* text, int x, int y);
extern "C" void func_ov012_021842a0(ProfileEditor02189dfc* self, int canvas, int color, int shadow);

extern "C" const char data_ov012_0218b310[];

static inline Cursor02189dfc* GetCursor02189dfc(char* window)
{
    return (Cursor02189dfc*)(window + 0x54);
}

// USA: func_ov012_02189dfc
extern "C" ARM void func_ov012_02189dfc(ProfileEditor02189dfc* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[3] % 9;
    if (hidden)
        _Z22AppendFrameTag02041c08Pciiiii(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    _Z26GetGlobalField0x1c020421a0v();
    int i;
    Cursor02189dfc* cursor = GetCursor02189dfc(self->window_);
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((UnkStruct0205c508*)cursor, &first, &last);
    for (i = first; i < last; i++)
    {
        if (i != first)
            _Z20AppendString02042058PcPKc(text, self->unk_1378);
        AppendNameTag(text, i % 9, FindEntryByKey((TableA68*)self->strings_, (short)(self->unk_13c0[i] + 10000)));
    }
    if (self->unk_13c4_0 > 9)
    {
        func_ov012_021842a0(self, 5, shadow, color);
        AppendXYTag(text, 0x2a, 0x94);
        _Z20AppendString02042058PcPKc(text, data_ov012_0218b310);
    }
}
