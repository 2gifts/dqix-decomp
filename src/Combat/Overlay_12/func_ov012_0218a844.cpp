#include <globaldefs.h>

struct UnkStruct0205c508;
struct Container020e0310;

struct Cursor0218a844
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct ProfileEditor0218a844
{
    char unk_0[0xac];
    char window_[0x1344 - 0xac];
    char texts_[0x1378 - 0x1344];
    const char* unk_1378;
    char unk_137c[0x13c8 - 0x137c];
    short* unk_13c8;
    char unk_13cc[0x13f0 - 0x13cc];
    int unk_13f0;
};

extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendCursorTag(char* text, int a);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
void AppendXTag(char* text, int x);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXYTag(char* text, int x, int y);
extern "C" void func_ov012_021842a0(ProfileEditor0218a844* self, int canvas, int color, int shadow);

extern "C" const char data_ov012_0218b310[];

static inline Cursor0218a844* GetCursor0218a844(char* window)
{
    return (Cursor0218a844*)(window + 0x54);
}

// USA: func_ov012_0218a844
extern "C" ARM void func_ov012_0218a844(ProfileEditor0218a844* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->unk_13f0 & 0xf;
    if (hidden)
        _Z22AppendFrameTag02041c08Pciiiii(text, selection, 8, 5, 5, 5);
    AppendCursorTag(text, selection);
    _Z26GetGlobalField0x1c020421a0v();
    int i;
    Cursor0218a844* cursor = GetCursor0218a844(self->window_);
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((UnkStruct0205c508*)cursor, &first, &last);
    for (i = first; i < last; i++)
    {
        if (i % 2 == 0)
        {
            if (i != first)
                _Z20AppendString02042058PcPKc(text, self->unk_1378);
        }
        else
        {
            AppendXTag(text, 0x88);
        }
        AppendNameTag(text, i & 0xf, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, self->unk_13c8[i]));
    }
    if (color > 1)
    {
        func_ov012_021842a0(self, 12, shadow, color);
        AppendXYTag(text, 0x56, 0x94);
        _Z20AppendString02042058PcPKc(text, data_ov012_0218b310);
    }
}
