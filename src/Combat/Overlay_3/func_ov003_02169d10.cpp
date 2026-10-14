#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define PANEL_SHIFT 4
extern "C" void func_02042428(char*, int);
#define AppendSizeTag func_02042428
#define data_ov003_02180156 data_ov003_0217e8e5
#define data_ov003_02180159 data_ov003_0217e8e8
#else
#define PANEL_SHIFT 0
#endif
struct Container020e0310;

struct DigitPanel02169d10
{
    char unk_0[0x64];
    char texts_[0x4ee - PANEL_SHIFT - 0x64];
    signed char cursor_;
    signed char digits_[7];
    char unk_4f6[0x5a6 - 0x4f6];
    unsigned char upActive_;
    unsigned char downActive_;
};

extern "C" void __clear(void* buf, int size);
void AppendXYTag(char* text, int x, int y);
void AppendPaletteTag(char* text, int palette);
void AppendString02042058(char* text, const char* append);
void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
void AppendUaTag(char* text, int a, int b, int c);
void AppendDbTag(char* text, int a, int b, int c);
void AppendSizeTag(char* text, int size);
void AppendNameTag(char* text, int item, const char* itemText);
void AppendXTag(char* text, int x);
const char* GetFieldByKey020e0434(Container020e0310* c, int key);

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
#if !defined(jpn)
    AppendXYTag(text, cursor * 8 + 0x23, 5);
    if (self->upActive_)
        AppendPaletteTag(text, 0xd);
    else
        AppendPaletteTag(text, 0xf);
    AppendString02042058(text, data_ov003_02180137);
    AppendXYTag(text, cursor * 8 + 0x23, 0x1b);
    if (self->downActive_)
        AppendPaletteTag(text, 0xd);
    else
        AppendPaletteTag(text, 0xf);
    AppendString02042058(text, data_ov003_02180145);
    AppendPaletteTag(text, 0xf);
 #endif
    if (framed)
        AppendFrameTag02041c08(text, cursor, 3, 0xb, 3, 0xa);
    AppendUaTag(text, cursor, self->upActive_, 2);
    AppendDbTag(text, cursor, self->downActive_, 2);
    AppendSizeTag(text, 0xc);
    for (int i = 0; i < 7; i++)
    {
        memset(buf, 0, 2);
        sprintf(buf, data_ov003_02180156, self->digits_[i]);
#if !defined(jpn)
        AppendXYTag(text, i * 8 + 0x24, 0x10);
#endif
        if (i < 4)
            AppendNameTag(text, i, buf);
        else
            AppendString02042058(text, data_ov003_02180159);
    }
#if !defined(jpn)
    AppendXTag(text, 0x5c);
#endif
    AppendString02042058(text, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x66));
}
