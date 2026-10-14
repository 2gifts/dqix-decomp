#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
void SetElementFields0202756c(void* obj, int p1, int p2, int idx,
        unsigned char p5, unsigned char p6, unsigned short p7, unsigned char p8, int p9, int p10);

// USA: func_0202720c  (semantic: ConfigureSubEngineAndElement0202720c)
extern "C" ARM void func_0202720c(void* obj) {
    int band = 5;
    *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1300;
    if (CheckField0NonZero_0202b7d8(func_0202ae18()) != 0) band += 0x10;
    SetElementFields0202756c(obj, band << 12, 0x5000, 0x17, 0x40, 1, 0xff, 0xff, 0x1000, 0x1000);
}
