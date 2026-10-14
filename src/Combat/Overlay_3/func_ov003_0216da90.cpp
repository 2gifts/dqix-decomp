#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_0216da90 func_ov003_0216d478
#endif
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
#if defined(jpn)
    char unk_14[0x1150 - 0x14];
#else
    char unk_14[0x12c0 - 0x14];
#endif
    Window0216da90* window;
    char unk_12c4[0x1324 - 0x12c4];
    char texts_[4];
};

extern "C" void __clear(void* buf, int size);
void FindAndLinkMatchingEntry0205de24(Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);
void SetChannelAFlag0205cef8(void* obj);
unsigned char NormalizeField5_0200fb08(Struct0200fb08* obj);
int GetActiveScaledSum0205d794(Struct_0205c570* s);
void AppendFrameTag02041c08(char* text, int a, int b, int c, int d, int e);
const char* GetFieldByKey020e0434(Container020e0310* c, int key);
void AppendString02042058(char* text, const char* append);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
Window0216da90* FindElementByC40205d81c(Struct_0205d81c* s, int key);
void SetupPointerTable0205ba68(Struct_0205ba68* s, int a, int b, int mode);
void SetField0AndPropagate0205bacc(Node0205bacc* s, int val);

extern short data_ov003_0217f560[];

// USA: func_ov003_0216da90
extern "C" ARM void func_ov003_0216da90(Menu0216da90* self)
{
    FindAndLinkMatchingEntry0205de24((Struct0205de24*)self->window, 0, 1);
    self->window->field_b1 = 0;
#if defined(jpn)
    self->window->frame.SetPosition(0xc, 7);
    self->window->frame.SetSize(0x11, 1);
#endif
    self->window->body.SetPosition(0xd, 5);
    self->window->body.SetSize(0xa, 0xc);
    self->window->field_b5 = 1;
    SetChannelAFlag0205cef8(self->window);

#if !defined(jpn)
    short x = data_ov003_0217f560[NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance())];
    self->window->frame.SetPosition(x, 7);
    self->window->frame.SetSize(0x1f - x, 1);
#endif

    char text[0x100];
    char sub[0x40];
    __clear(text, 0x100);
    __clear(sub, 0x40);
    if (self->mode == 2)
        AppendFrameTag02041c08(text, GetActiveScaledSum0205d794((Struct_0205c570*)self->window), 8, 5, 5, 5);
    AppendString02042058(text, GetFieldByKey020e0434((Container020e0310*)self->texts_, 0x5c));
#if defined(jpn)
    func_0205d304(self->window, text, 0, 0, 0, 1, 0);
#else
    func_0205d304(self->window, text, 0, 0, 0, 1, 0, 0);
#endif

#if !defined(jpn)
    Window0216da90* found = FindElementByC40205d81c((Struct_0205d81c*)self->window, 0);
    if (found)
        found->body.SetSize(0x1f - found->body.x, found->body.height);
#endif

    Window0216da90* window = self->window;
    window->tableA.field4 = 1;
    window->tableB.field4 = 1;
    SetupPointerTable0205ba68((Struct_0205ba68*)&window->tableA, 1, 4, 0);
    SetupPointerTable0205ba68((Struct_0205ba68*)&window->tableB, 1, 4, 0);
    SetField0AndPropagate0205bacc((Node0205bacc*)&window->tableA, 4);
    SetField0AndPropagate0205bacc((Node0205bacc*)&window->tableB, 4);
    window->activeA = 1;
    window->activeB = 1;
}
