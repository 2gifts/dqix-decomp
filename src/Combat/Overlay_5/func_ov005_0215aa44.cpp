#include <globaldefs.h>

#define GXFIFO_MATRIX_PUSH (*(volatile unsigned int*)0x04000444)
#define GXFIFO_MATRIX_POP (*(volatile unsigned int*)0x04000448)
#define GXFIFO_MATRIX_TRANSLATE (*(volatile unsigned int*)0x04000470)
#define GXFIFO_BEGIN_VTXS (*(volatile unsigned int*)0x04000500)
#define GXFIFO_END_VTXS (*(volatile unsigned int*)0x04000504)

struct MessageSystem;

struct EquipmentMenu
{
    char unk_0[0x3dbc];
    unsigned char kind_;
    signed char page_;
    char unk_3dbe[0x3df4 - 0x3dbe];
    unsigned char pageCounts_[8];
    unsigned char pages_[8];
    char unk_3e04[0x3e0c - 0x3e04];
    unsigned short digits_[20][3];
};

extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02045f3c(MessageSystem* messages, unsigned short* codes, int x, int y, int color, int, int, int, int, int);

// USA: func_ov005_0215aa44
extern "C" ARM void func_ov005_0215aa44(EquipmentMenu* self)
{
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    int page = self->page_ + 1;
    int count = self->pageCounts_[self->kind_];
    GXFIFO_MATRIX_PUSH = 0;
    GXFIFO_BEGIN_VTXS = 1;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = 0;
    GXFIFO_MATRIX_TRANSLATE = -0x3ff000;
    int tens = count / 10;
    if (tens != 0)
    {
        func_02045f3c(messages, self->digits_[tens], 0xc8, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
        func_02045f3c(messages, self->digits_[count % 10], 0xd0, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
    }
    else
    {
        func_02045f3c(messages, self->digits_[count], 0xcc, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
    }
    tens = page / 10;
    if (tens != 0)
    {
        func_02045f3c(messages, self->digits_[tens], 0xa8, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
        func_02045f3c(messages, self->digits_[page % 10], 0xb0, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
    }
    else
    {
        func_02045f3c(messages, self->digits_[page], 0xac, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
    }
    GXFIFO_END_VTXS = 0;
    GXFIFO_MATRIX_POP = 1;
}
