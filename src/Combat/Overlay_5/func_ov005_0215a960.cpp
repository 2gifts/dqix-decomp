#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0x3e0c];
    unsigned short digits_[20][3];
};

struct MessageSystem {
    char unk_0[0x195b];
    unsigned char unk_195b_0 : 7;
    unsigned char unk_195b_7 : 1;
};

extern "C" char data_ov005_0215ce05[];

extern "C" int sprintf(char* out, const char* format, ...);
extern "C" MessageSystem* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02045d14(MessageSystem* messages, const char* text, unsigned short* codes, int unk);
extern "C" void func_020439b0(MessageSystem* messages, int unk);

// USA: func_ov005_0215a960
extern "C" ARM void func_ov005_0215a960(EquipmentMenu* self) {
    MessageSystem* messages = _Z26GetGlobalField0x1c020421a0v();
    messages->unk_195b_7 = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++)
            self->digits_[i][j] = 0xffff;
        int digit = i % 10;
        char text[2];
        sprintf(text, data_ov005_0215ce05, digit);
        func_02045d14(messages, text, self->digits_[i], 0);
        if (digit == 9) {
            func_020439b0(messages, 0);
            messages->unk_195b_7 = 1;
        }
    }
    messages->unk_195b_7 = 0;
}
