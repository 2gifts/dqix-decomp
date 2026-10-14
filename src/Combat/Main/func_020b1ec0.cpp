#include <globaldefs.h>

static inline int Clz(int x) {
    int r = x;
    __asm("clz %0, %0" : "+r"(r));
    return r;
}

extern const unsigned char data_020e91e0[32];
extern int data_020e91d4;

struct Fields020b1d48;
void InitFields020b1d48(Fields020b1d48*, int, int, int, int, int, int);

// USA: func_020b1ec0
extern "C" ARM void func_020b1ec0(void* s, int a, int b, int c, int d) {
    int col = (b >= 8) ? 3 : (0x1f - Clz(b));
    int row = (c >= 8) ? 3 : (0x1f - Clz(c));

    const unsigned char* t = data_020e91e0 + row * 8;

    volatile int v;
    int w = (v & ~0xff) | t[col * 2];
    int x = (w & ~0xff00) | ((unsigned)(*(t + col * 2 + 1)) << 24 >> 16);
    v = x;

    InitFields020b1d48((Fields020b1d48*)s, a, b, c, d, (int)&data_020e91d4, x);
}
