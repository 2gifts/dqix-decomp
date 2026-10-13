#include <globaldefs.h>

struct InputState0222e048 {
    unsigned int reserved;
    unsigned int* flags;
    unsigned char digits[12];
    unsigned char cursor;
    unsigned char status;
};
extern InputState0222e048* data_ov031_02290c98;
extern unsigned char data_ov031_02248f20[];

// USA: func_ov031_0222e048
extern "C" ARM void func_ov031_0222e048() {
    InputState0222e048* input = data_ov031_02290c98;
    int index = input->cursor;
    if (index > 3) index = 3;
    unsigned int* flags = input->flags;
    unsigned int value = data_ov031_02248f20[index * 3 + 2];
    unsigned int word = (*flags & 0xfe00ff00) | 0x28;
    value = (value & 0x1ff) << 16;
    *flags = value | word;
}
