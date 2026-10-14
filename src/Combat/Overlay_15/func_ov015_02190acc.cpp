#include <globaldefs.h>

struct ViewObject
{
    char unk_0[0x3a];
    unsigned char playing_;
    char unk_3b[0x44 - 0x3b];
    int loop_;
    int battle_;
};

struct S02190c2c
{
    char unk_0[0x30];
    ViewObject* current_;
    char unk_34[0x194 - 0x34];
    int menu_;
    char unk_198[0x1a1 - 0x198];
    unsigned char field_;
    char unk_1a2[2];
    int page_;
};

void FormatAndDispatch020290e8(int x, int y, const char* text, ...);
int IsFieldValueInRange_02190c2c(S02190c2c* self);

extern char data_ov015_021942a2[];
extern char data_ov015_021942ae[];
extern char data_ov015_021942ba[];
extern char data_ov015_021942c8[];
extern char data_ov015_021942d4[];
extern char data_ov015_021942e0[];
extern char data_ov015_021942ec[];
extern char data_ov015_021942f6[];
extern char data_ov015_02194302[];
extern char data_ov015_0219430e[];
extern char data_ov015_0219431a[];
extern char data_ov015_02194324[];

// USA: func_ov015_02190acc
extern "C" ARM void func_ov015_02190acc(S02190c2c* self)
{
    FormatAndDispatch020290e8(0x87, 0xa, data_ov015_021942a2);
    FormatAndDispatch020290e8(0x91, 0x18, data_ov015_021942ae);
    if (self->menu_ == 1)
    {
        FormatAndDispatch020290e8(0x91, 0x26, data_ov015_021942ba);
        if (self->current_->loop_ == 0)
            FormatAndDispatch020290e8(0x91, 0x34, data_ov015_021942c8);
        else
            FormatAndDispatch020290e8(0x91, 0x34, data_ov015_021942d4);
        if (self->current_->playing_)
        {
            FormatAndDispatch020290e8(0x91, 0x42, data_ov015_021942e0);
            FormatAndDispatch020290e8(0x91, 0x50, data_ov015_021942ec);
            return;
        }
        FormatAndDispatch020290e8(0x91, 0x42, data_ov015_021942f6);
        return;
    }
    if (self->page_ == 0x22 || IsFieldValueInRange_02190c2c(self))
    {
        if (self->current_->battle_ == 0)
            FormatAndDispatch020290e8(0x91, 0x26, data_ov015_02194302);
        else
            FormatAndDispatch020290e8(0x91, 0x26, data_ov015_0219430e);
    }
    if (self->page_ != 6)
        return;
    if (self->field_)
    {
        FormatAndDispatch020290e8(0x91, 0x26, data_ov015_0219431a);
        return;
    }
    FormatAndDispatch020290e8(0x91, 0x26, data_ov015_02194324);
}
