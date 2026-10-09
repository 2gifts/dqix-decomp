#include <globaldefs.h>
#include <std_library_functions.h>

struct Struct_0205d81c;
struct MessageSystem;

struct ProfileCard_021e7d8c {
    char pad0[0x78];
    char window_[0x5d8 - 0x78];
    char* text_;
};

typedef void (ProfileCard_021e7d8c::*PageFunction)();

struct PageTable_021e7d8c {
    PageFunction functions[3];
};

struct Shorts3_021e7d8c {
    short v[3];
};

struct Rodata_021fd75c {
    char pad0[0x32];
    Shorts3_021e7d8c y;
    char pad38[0x6c - 0x38];
};

extern PageTable_021e7d8c data_ov023_021fd7cc;
extern Rodata_021fd75c data_ov023_021fd75c;

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
void SetElementFieldC2(Struct_0205d81c* window, int index, int value);

extern "C" {
void func_02046380(MessageSystem* messages);
void func_ov023_021e7cec(ProfileCard_021e7d8c* self, int id, short x, short y);
void func_0205d304(void* window, char* text, int a, int b, int c, int d, int e, int f);
}

// USA: func_ov023_021e7d8c
extern "C" ARM void func_ov023_021e7d8c(ProfileCard_021e7d8c* self)
{
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    PageFunction functions[3];
    *(PageTable_021e7d8c*)functions = data_ov023_021fd7cc;
    short y[3];
    *(Shorts3_021e7d8c*)y = data_ov023_021fd75c.y;
    for (unsigned char i = 0; i < 3; i++)
    {
        func_02046380(messages);
        func_ov023_021e7cec(self, i, 2, y[i]);
        memset(self->text_, 0, 0x960);
        (self->*functions[i])();
        func_0205d304(self->window_, self->text_, 0, 0, 0, 1, 0, 0);
    }
    for (int i = 0; i < 3; i++)
        SetElementFieldC2((Struct_0205d81c*)self->window_, (unsigned char)i, 0);
}
