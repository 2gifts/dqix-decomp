#include <globaldefs.h>

extern "C" void func_0205ac40(void* dst, void* src);

struct DigitSprite02181164 {
    char pad0[0x14];
    int x;
    int y;
    char pad1[0x22 - 0x1c];
    unsigned char frame;
    char pad2[0x26 - 0x23];
    signed char palette;
    char pad3[0x28 - 0x27];
};

// USA: func_ov000_02181164
extern "C" ARM void func_ov000_02181164(void* obj, int value, struct DigitSprite02181164* sprites, int x, int y,
    int palette, int frame, int spacing) {
    if (value < 0) return;
    if (sprites == NULL) return;
    do {
        struct DigitSprite02181164* e = &sprites[value % 10];
        e->x = x << 12;
        e->y = y << 12;
        e->frame = frame;
        e->palette = palette & 3;
        func_0205ac40((char*)obj + 0x11c, e);
        frame++;
        x -= spacing;
        value /= 10;
    } while (value != 0);
}
