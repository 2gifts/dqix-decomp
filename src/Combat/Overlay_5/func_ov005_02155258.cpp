#include <globaldefs.h>

#if defined(jpn)
#define func_02045f3c func_02046c78
#endif

int GetGlobalField0x1c020421a0();
#if defined(jpn)
extern "C" void func_02046c78(void*, void*, int, int, int, int, int, int);
#define DRAW_DIGIT(ctx, rec, x, y, color) func_02046c78(ctx, rec, x, y, color, 8, 0, 0)
#define DIGIT_BASE 0x3d84
#define DIGIT_STEP 8
#else
extern "C" void func_02045f3c(void*, void*, int, int, int, int, int, int, int, int);
#define DRAW_DIGIT(ctx, rec, x, y, color) func_02045f3c(ctx, rec, x, y, color, 8, 0, 0, 0, 0x11)
#define DIGIT_BASE 0x3e0c
#define DIGIT_STEP 5
#endif

// USA: func_ov005_02155258
extern "C" ARM void func_ov005_02155258(void* context, int value,
#if defined(jpn)
    int x, int y
#else
    short x, short y
#endif
    , unsigned short color) {
    int drawContext = GetGlobalField0x1c020421a0();
    volatile unsigned int* ports = (volatile unsigned int*)0x04000444;
    ports[0] = 0;
    ports[0x2f] = 1;
    ports[0xb] = 0;
    ports[0xb] = 0;
    ports[0xb] = 0xffc01000;
    int tens = value / 10;
    int units = value % 10;
    #if defined(jpn)
    int position = x;
#else
    short position = x;
#endif
    if (tens != 0) {
#if !defined(jpn)
        if (units == 1) position++;
        if (tens == 1) position++;
#endif
        DRAW_DIGIT((void*)drawContext, (char*)context + DIGIT_BASE + tens * 6, position, y, color);
    }
    position = x + DIGIT_STEP;
#if !defined(jpn)
    if (units == 1) position++;
#endif
    DRAW_DIGIT((void*)drawContext, (char*)context + DIGIT_BASE + units * 6, position, y, color);
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
}
