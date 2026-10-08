#include <globaldefs.h>

extern "C" void* memset(void* dst, int value, unsigned int length);

struct StructA0205d5d0;
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct TouchState_021da1dc {
    char pad0[0x24];
    unsigned short unk_24;
    char pad26[0x5f - 0x26];
    unsigned char unk_5f;
};

extern "C" TouchState_021da1dc data_02114e54;

struct WindowFrame_021da1dc {
    char pad0[0x30];
    int unk_30;
};

struct CharacterCreation_021da1dc {
    char pad0[0xf8];
    void* unk_f8;
    char padfc[0x2b4 - 0xfc];
    char window1[0xd85 - 0x2b4];
    unsigned char unk_d85;
};

extern "C" void func_ov023_021da100(CharacterCreation_021da1dc* self, char* text, int highlighted);

static inline WindowFrame_021da1dc* GetFrame(void* window)
{
    return (WindowFrame_021da1dc*)((char*)window + 4);
}

// USA: func_ov023_021da1dc
extern "C" ARM void func_ov023_021da1dc(CharacterCreation_021da1dc* self)
{
    unsigned char unk = self->unk_d85;
    if (unk != 0)
    {
        int highlighted = 0;
        if (unk == 2 && data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0)
        {
            WindowFrame_021da1dc* frame = GetFrame(self->window1);
            if (frame->unk_30 < 0)
                return;
            highlighted = 1;
        }
        char* text = (char*)self->unk_f8;
        memset(text, 0, 0x960);
        func_ov023_021da100(self, text, highlighted);
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((StructA0205d5d0*)self->window1, 1, (int)text, 0, 1);
    }
}
