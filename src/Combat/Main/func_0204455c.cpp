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
    volatile struct Level0204455c* vl = lv;
    short a = vl->fa8;
    short b = vl->fac;
    short c = vl->faa;
    *out1 = (short)(b << 3) + ((short)(a << 3) >> 1);
    *out2 = (short)(c << 3) - 10;
}