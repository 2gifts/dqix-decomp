#include <globaldefs.h>

struct UnkStruct0205c508;
struct TableA68;

struct Cursor02189af4
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct ProfileEditor02189af4
{
    char unk_0[0xac];
    char window_[0x133c - 0xac];
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unk_137c[0x13d8 - 0x137c];
    int selections_[6];
};

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
const char* FindEntryByKey(TableA68* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXTag(char* text, int x);
extern "C" void func_ov012_021842a0(ProfileEditor02189af4* self, int canvas, int color, int shadow);

static inline Cursor02189af4* GetCursor02189af4(char* window)
{
    return (Cursor02189af4*)(window + 0x54);
}

// USA: func_ov012_02189af4
extern "C" ARM void func_ov012_02189af4(ProfileEditor02189af4* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[1] & 0xf;
    if (hidden)
        _Z22AppendFrameTag02041c08Pciiiii(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    _Z26GetGlobalField0x1c020421a0v();
    Cursor02189af4* cursor = GetCursor02189af4(self->window_);
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((UnkStruct0205c508*)cursor, &first, &last);
    int end = first + (last + 1 - first) / 2;
    for (int i = first; i < end; i++)
    {
        if (i != first)
            _Z20AppendString02042058PcPKc(text, self->unk_1378);
        AppendNameTag(text, i & 0xf, FindEntryByKey((TableA68*)self->strings_, (short)(i + 0x2846)));
        int right = i + (last + 1 - first) / 2;
        if (right < 0xc0)
        {
            AppendXTag(text, 0x56);
            AppendNameTag(text, right & 0xf, FindEntryByKey((TableA68*)self->strings_, (short)(right + 0x2846)));
        }
    }
    func_ov012_021842a0(self, 3, shadow, color);
}
