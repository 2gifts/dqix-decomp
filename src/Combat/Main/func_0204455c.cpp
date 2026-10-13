#include <globaldefs.h>

struct Level0204455c {
    char pad0[0xa8];
    short fa8;
    short faa;
    short fac;
};

// USA: func_0204455c
extern "C" ARM void func_0204455c(void* p, short* out1, short* out2) {
    if (p == 0) return;
    struct Level0204455c* lv = (struct Level0204455c*)p;
    short a = lv->fa8;
    short b = lv->fac;
    short c = lv->faa;
    a <<= 3;
    b <<= 3;
    c <<= 3;
    *out1 = b + (a >> 1);
    *out2 = c - 10;
}
