#include <globaldefs.h>
#include "std_library_functions.h"

struct Container020e0310;

struct DigitPanel02169d10
{
    char unk_0[0x64];
    char texts_[0x4ee - 0x64];
    signed char cursor_;
    signed char digits_[7];
    char unk_4f6[0x5a6 - 0x4f6];
    unsigned char upActive_;
    unsigned char downActive_;
};

extern "C" void __clear(void* buf, int size);
void AppendXYTag(char* text, int x, int y);
void AppendPaletteTag(char* text, int palette);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
void AppendUaTag(char* text, int a, int b, int c);
void AppendDbTag(char* text, int a, int b, int c);
void AppendSizeTag(char* text, int size);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXTag(char* text, int x);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* c, int key);

extern "C" const char data_ov003_02180137[];
extern "C" const char data_ov003_02180145[];
extern "C" const char data_ov003_02180156[];
extern "C" const char data_ov003_02180159[];

// USA: func_ov003_02169d10
extern "C" ARM void func_ov003_02169d10(DigitPanel02169d10* self, char* text, int framed)
{
    if (text == 0)
        return;

    char buf[2];
    __clear(buf, 2);
    int cursor = self->cursor_;
    AppendXYTag(text, cursor * 8 + 0x23, 5);
    if (self->upActive_)
        AppendPaletteTag(text, 0xd);
    else
        AppendPaletteTag(text, 0xf);
    _Z20AppendString02042058PcPKc(text, data_ov003_02180137);
    AppendXYTag(text, cursor * 8 + 0x23, 0x1b);
    if (self->downActive_)
        AppendPaletteTag(text, 0xd);
    else
        AppendPaletteTag(text, 0xf);
    _Z20AppendString02042058PcPKc(text, data_ov003_02180145);
    AppendPaletteTag(text, 0xf);
    if (framed)
        _Z22AppendFrameTag02041c08Pciiiii(text, cursor, 3, 0xb, 3, 0xa);
    AppendUaTag(text, cursor, self->upActive_, 2);
    AppendDbTag(text, cursor, self->downActive_, 2);
    AppendSizeTag(text, 0xc);
    for (int i = 0; i < 7; i++)
    {
        memset(buf, 0, 2);
        sprintf(buf, data_ov003_02180156, self->digits_[i]);
        AppendXYTag(text, i * 8 + 0x24, 0x10);
        if (i < 4)
            AppendNameTag(text, i, buf);
        else
            _Z20AppendString02042058PcPKc(text, data_ov003_02180159);
    }
    AppendXTag(text, 0x5c);
    _Z20AppendString02042058PcPKc(text, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x66));
}
