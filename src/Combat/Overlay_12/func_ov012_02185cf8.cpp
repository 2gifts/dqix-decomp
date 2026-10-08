#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" void _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0* window, int state, int text, int a, unsigned char b);

struct ProfileEditor02185cf8
{
    char unk_0[0xac];
    char window_[0x1370 - 0xac];
    unsigned char step_;
    unsigned char state_;
    char unk_1372[2];
    char* text_;
    char unk_1378[0x1398 - 0x1378];
    int unk_1398;
};

struct Frame02185cf8
{
    char unk_0[0x30];
    int unk_30;
};

struct Input02114e54
{
    char unk_0[0x24];
    unsigned short unk_24;
    char unk_26[0x5f - 0x26];
    unsigned char unk_5f;
};

typedef void (ProfileEditor02185cf8::*TextFn02185cf8)(char* text, int hidden);

struct TextTable02185cf8
{
    TextFn02185cf8 functions[16];
};

extern "C" Input02114e54 data_02114e54;
extern "C" const TextTable02185cf8 data_ov012_0218b108;
extern "C" TextFn02185cf8 data_020e6d5c;

static inline Frame02185cf8* GetFrame02185cf8(char* window)
{
    return (Frame02185cf8*)(window + 4);
}

static inline char* GetWindow02185cf8(ProfileEditor02185cf8* editor)
{
    return (char*)editor + 0xac;
}

// USA: func_ov012_02185cf8
extern "C" ARM void func_ov012_02185cf8(ProfileEditor02185cf8* self)
{
    if (self->unk_1398 == 0)
        return;

    int hidden = 0;
    if (self->unk_1398 == 2)
    {
        if (data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0 &&
            GetFrame02185cf8(GetWindow02185cf8(self))->unk_30 < 0)
            return;
        hidden = 1;
    }
    memset(self->text_, 0, 0x960);
    TextTable02185cf8 functions = data_ov012_0218b108;
    TextFn02185cf8 none = data_020e6d5c;
    functions.functions[0] = none;
    functions.functions[15] = none;
    if (functions.functions[self->state_] != 0)
        (self->*functions.functions[self->state_])(self->text_, hidden);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((StructA0205d5d0*)self->window_, self->state_, (int)self->text_, 0, 0);
}
