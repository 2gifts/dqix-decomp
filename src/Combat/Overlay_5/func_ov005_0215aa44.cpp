#if defined(jpn)
#define func_02045f3c func_02046c78
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215aa44 func_ov005_0215bf64
#endif

#define GXFIFO_MATRIX_PUSH (*(volatile unsigned int*)0x04000444)
#define GXFIFO_MATRIX_POP (*(volatile unsigned int*)0x04000448)
#define GXFIFO_MATRIX_TRANSLATE (*(volatile unsigned int*)0x04000470)
#define GXFIFO_BEGIN_VTXS (*(volatile unsigned int*)0x04000500)
#define GXFIFO_END_VTXS (*(volatile unsigned int*)0x04000504)

struct MessageSystem;

struct EquipmentMenu
{
    char unk_0[LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char kind_;
    signed char page_;
    char unk_3dbe[LOW_REGION(0x3d6c, 0x3df4) - LOW_REGION(0x3d36, 0x3dbe)];
    unsigned char pageCounts_[8];
    unsigned char pages_[8];
    char unk_3e04[LOW_REGION(0x3d84, 0x3e0c) - LOW_REGION(0x3d7c, 0x3e04)];
    unsigned short digits_[20][3];
};

MessageSystem* GetGlobalField0x1c020421a0();
#if defined(jpn)
extern "C" void func_02045f3c(MessageSystem* messages, unsigned short* codes, int x, int y, int color, int, int, int);
#else
extern "C" void func_02045f3c(MessageSystem* messages, unsigned short* codes, int x, int y, int color, int, int, int, int, int);
#endif

// USA: func_ov005_0215aa44
extern "C" ARM void func_ov005_0215aa44(EquipmentMenu* self)
{
    MessageSystem* messages = GetGlobalField0x1c020421a0();
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
#if defined(jpn)
        func_02045f3c(messages, self->digits_[tens], 0xc8, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[tens], 0xc8, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
#if defined(jpn)
        func_02045f3c(messages, self->digits_[count % 10], 0xd0, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[count % 10], 0xd0, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
    }
    else
    {
#if defined(jpn)
        func_02045f3c(messages, self->digits_[count], 0xcc, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[count], 0xcc, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
    }
    tens = page / 10;
    if (tens != 0)
    {
#if defined(jpn)
        func_02045f3c(messages, self->digits_[tens], 0xa8, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[tens], 0xa8, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
#if defined(jpn)
        func_02045f3c(messages, self->digits_[page % 10], 0xb0, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[page % 10], 0xb0, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
    }
    else
    {
#if defined(jpn)
        func_02045f3c(messages, self->digits_[page], 0xac, 0xa1, 0x7fff, 8, 0, 0);
#else
        func_02045f3c(messages, self->digits_[page], 0xac, 0x9e, 0x7fff, 8, 0, 0, 0, 0x11);
#endif
    }
    GXFIFO_END_VTXS = 0;
    GXFIFO_MATRIX_POP = 1;
}
