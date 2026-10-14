#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct EquipmentMenu {
    #if defined(jpn)
    char unk_0[0x3d84];
#else
    char unk_0[0x3e0c];
#endif
    unsigned short digits_[20][3];
};

extern "C" char data_ov005_0215ce05[];

extern "C" int sprintf(char* out, const char* format, ...);
int GetGlobalField0x1c020421a0();
#if defined(jpn)
extern "C" unsigned short func_020469b0(MessageSystem* messages, const char* text, unsigned short* codes, int);
#endif
extern "C" unsigned short func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int unk);
extern "C" void func_020439b0(MessageSystem* messages, int unk);

// USA: func_ov005_0215a960
extern "C" ARM void func_ov005_0215a960(EquipmentMenu* self) {
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
#if !defined(jpn)
    messages->b195b &= ~0x80;
#endif
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++)
            self->digits_[i][j] = 0xffff;
#if defined(jpn)
        char text[3];
        text[2] = 0;
        if (i < 10) {
            text[0] = '\x82';
            text[1] = '\x4f';
        } else {
            text[0] = '\xea';
            text[1] = '\x40';
        }
        int digit = i % 10;
        text[1] += digit;
        func_020469b0(messages, text, self->digits_[i], 8);
#else
        int digit = i % 10;
        char text[2];
        sprintf(text, data_ov005_0215ce05, digit);
        func_02045d14(messages, text, self->digits_[i], 0);
#endif
        if (digit == 9) {
            func_020439b0(messages, 0);
#if !defined(jpn)
            messages->b195b |= 0x80;
#endif
        }
    }
#if !defined(jpn)
    messages->b195b &= ~0x80;
#endif
}
