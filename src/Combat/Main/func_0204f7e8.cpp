#include <globaldefs.h>

#pragma opt_common_subs off

extern "C" void* __clear(void* dst, int count);
extern "C" int sprintf(char* dst, const char* fmt, ...);
int IsValueEqual12_02042190(int x);
extern "C" int func_020420e8(char* str, int id);
extern "C" void func_0204f41c(int a, short b, short c, char* buf, int d, int e, void* f, void* g, int h);
extern char data_020f02f5;
extern char data_020f02fc;
extern char data_020f0300;

// USA: func_0204f7e8  (semantic: FormatNumberAndDispatch0204f7e8)
extern "C" ARM void func_0204f7e8(int target, short width, short height, int value,
                                  unsigned char style, unsigned char color, void* palette, void* font,
                                  unsigned char measure, unsigned char digits,
                                  unsigned char showSign, unsigned char zeroPad) {
    int v = value;
    do {
        v = v / 10;
    } while (v != 0);

    char buf[0x40];
    __clear(buf, 0x40);
    if (zeroPad) {
        char fmt[8];
        __clear(fmt, 8);
        sprintf(fmt, &data_020f02f5, digits);
        sprintf(buf, fmt, value);
    } else if (showSign && value > 0) {
        sprintf(buf, &data_020f02fc, value);
    } else {
        sprintf(buf, &data_020f0300, value);
    }

    int index = IsValueEqual12_02042190(style);
    if (measure) {
        width = width - func_020420e8(buf, index);
    }
    func_0204f41c(target, width, height, buf, style, color, palette, font, index);
}
