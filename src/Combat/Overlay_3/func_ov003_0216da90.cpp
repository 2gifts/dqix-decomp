#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205ba68;
struct Node0205bacc;
struct Container020e0310;
struct Struct0200fb08;

struct PointerTable0216da90
{
    int field0;
    int field4;
    char unk_8[0x40 - 0x8];
};

struct Rect0216da90
{
    short x;
    short y;
    short width;
    short height;

    void SetPosition(short newX, short newY)
    {
        x = newX;
        y = newY;
    }

    void SetSize(short newWidth, short newHeight)
    {
        width = newWidth;
        height = newHeight;
    }
};

struct Window0216da90
{
    int field0;
    PointerTable0216da90 tableA;
    char unk_44[0x54 - 0x44];
    PointerTable0216da90 tableB;
    unsigned char activeA;
    unsigned char activeB;
    char unk_96[0xa0 - 0x96];
    Rect0216da90 frame;
    Rect0216da90 body;
    char unk_b0;
    unsigned char field_b1;
    char unk_b2[3];
    unsigned char field_b5;
};

struct Menu0216da90
{
    char unk_0[0x10];
    int mode;
    char unk_14[0x12c0 - 0x14];
    Window0216da90* window;
    char unk_12c4[0x1324 - 0x12c4];
    char texts_[4];
};

extern "C" void __clear(void* buf, int size);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* obj);
extern "C" unsigned char _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08* obj);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* s);
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char* text, int a, int b, int c, int d, int e);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* c, int key);
extern "C" void _Z20AppendString02042058PcPKc(char* text, const char* append);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" Window0216da90* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* s, int key);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(Node0205bacc* s, int val);

extern short data_ov003_0217f560[];

// USA: func_ov003_0216da90
extern "C" ARM void func_ov003_0216da90(Menu0216da90* self)
{
    _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((Struct0205de24*)self->window, 0, 1);
    self->window->field_b1 = 0;
    self->window->body.SetPosition(0xd, 5);
    self->window->body.SetSize(0xa, 0xc);
    self->window->field_b5 = 1;
    _Z23SetChannelAFlag0205cef8Pv(self->window);

    short x = data_ov003_0217f560[_Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance())];
    self->window->frame.SetPosition(x, 7);
    self->window->frame.SetSize(0x1f - x, 1);

    char text[0x100];
    char sub[0x40];
    __clear(text, 0x100);
    __clear(sub, 0x40);
    if (self->mode == 2)
        _Z22AppendFrameTag02041c08Pciiiii(text, _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window), 8, 5, 5, 5);
    _Z20AppendString02042058PcPKc(text, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->texts_, 0x5c));
    func_0205d304(self->window, text, 0, 0, 0, 1, 0, 0);

    Window0216da90* found = _Z23FindElementByC40205d81cP15Struct_0205d81ci((Struct_0205d81c*)self->window, 0);
    if (found)
        found->body.SetSize(0x1f - found->body.x, found->body.height);

    Window0216da90* window = self->window;
    window->tableA.field4 = 1;
    window->tableB.field4 = 1;
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->tableA, 1, 4, 0);
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((Struct_0205ba68*)&window->tableB, 1, 4, 0);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->tableA, 4);
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((Node0205bacc*)&window->tableB, 4);
    window->activeA = 1;
    window->activeB = 1;
}
