#include <globaldefs.h>

struct ColorHolder {
    char unk0[4];
    unsigned short color;
};

// USA: func_0204be3c
ARM unsigned short ConvertColorToDecimal_0204be3c(struct ColorHolder* obj) {
    unsigned short color = obj->color;
    unsigned short red = color & 0x1f;
    unsigned short green = (color & 0x3e0) >> 5;
    unsigned short blue = (color & 0x7c00) >> 10;
    return red * 100 + green * 10 + blue;
}
