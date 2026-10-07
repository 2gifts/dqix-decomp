#include <globaldefs.h>

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);

// The six-byte records at context+0x3e0c appear to describe decimal glyphs.
// Draw a nonzero tens quotient and the units remainder; the narrow offsets for
// digit 1 are observed positioning adjustments. The caller supplies table IDs.
// GX port writes are ordered, including the repeated write to 0x04000470.
// USA: func_ov005_02155258
extern "C" ARM void func_ov005_02155258(void* context, int value, short x, short y, unsigned short color) {
    int drawContext = _Z26GetGlobalField0x1c020421a0v();
    volatile unsigned int* ports = (volatile unsigned int*)0x04000444;
    ports[0] = 0;
    ports[0x2f] = 1;
    ports[0xb] = 0;
    ports[0xb] = 0;
    ports[0xb] = 0xffc01000;
    int tens = value / 10;
    int units = value % 10;
    short position = x;
    if (tens != 0) {
        if (units == 1) position++;
        if (tens == 1) position++;
        func_02045f3c((void*)drawContext, (char*)context + 0x3e0c + tens * 6,
                     position, y, color, 8, 0, 0, 0, 0x11);
    }
    position = x + 5;
    if (units == 1) position++;
    func_02045f3c((void*)drawContext, (char*)context + 0x3e0c + units * 6,
                 position, y, color, 8, 0, 0, 0, 0x11);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
