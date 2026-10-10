#include <globaldefs.h>

struct Level1_020e23c0;

struct Pair0204459c {
    short b;
    short a;
};

struct Pose0204459c {
    char pad0[0x14];
    short f14;
    short f16;
    short f18;
    short f1a;
};

struct Obj0204459c {
    char pad0[0x34];
    void* field34;
    struct Level1_020e23c0* field38;
    char pad3c[0x900 - 0x3c];
    struct Pose0204459c pose;
    char pad91c[0x9a0 - 0x91c];
    int mode;
    char pad9a4[0x19ae - 0x9a4];
    signed char s19ae;
    unsigned char u19af;
    char pad19b0[0x19ca - 0x19b0];
    unsigned char u19ca;
};

extern "C" void func_0204455c(void* obj, short* a, short* b);
extern "C" void func_0204f914(void* obj, int mode, short a, short b, short c, short d);
extern "C" void _Z15Forward020e23c0P15Level1_020e23c0iiiss(struct Level1_020e23c0*, int, int, int, short, short);

// USA: func_0204459c
extern "C" ARM void func_0204459c(struct Obj0204459c* obj, int flag) {
    if (obj->mode == 1 || obj->mode == 3 || obj->mode == 2) {
        if (obj->u19ca == 0) return;
        if (flag != 0) {
            struct Pair0204459c pr;
            func_0204455c(obj->field34, &pr.a, &pr.b);
            int b = pr.b;
            int a = pr.a;
            func_0204f914(obj->field34, 0, a - 3, b, a + 4, b + 4);
        }
    }
    if (obj->u19af != 1) return;
    if (flag != 0) {
        short p;
        short q;
        func_0204455c(obj->field34, &p, &q);
        if (obj->s19ae <= 15) return;
        for (short i = 0; i < 4; i++) {
            func_0204f914(obj->field34, 15, p - (3 - i), q + i, p + (4 - i), q + i + 1);
        }
        return;
    }
    short x = obj->pose.f1a;
    short y = obj->pose.f16;
    short z = obj->pose.f18;
    short w = obj->pose.f14;
    int zs = w + (z >> 1);
    int ws = y + x - 3;
    if (obj->field38 != 0) {
        if (obj->s19ae <= 15) return;
        int base = x - 8;
        for (short i = 0; i < 4; i++) {
            _Z15Forward020e23c0P15Level1_020e23c0iiiss(obj->field38, 15, (short)((z >> 1) - (3 - i)), (short)(base + i), (4 - i) + (z >> 1), base + i + 1);
        }
        return;
    }
    unsigned int v = 0xf000f000;
    volatile unsigned int* gx = (volatile unsigned int*)0x04000444;
    gx[0] = 0;
    gx[0x3c / 4] = 0x7fff;
    gx[0x64 / 4] = 0x900000;
    gx[0x60 / 4] = 0x3e1f00c0;
    gx[0] = 0;
    gx[0x2c / 4] = zs << 12;
    gx[0x2c / 4] = ws << 12;
    gx[0x2c / 4] = 0x400000;
    gx[0x28 / 4] = 0x6000;
    gx[0x28 / 4] = 0x6000;
    gx[0x28 / 4] = 0x1000;
    gx[0xbc / 4] = 0;
    gx[0x48 / 4] = 0;
    gx[0x48 / 4] = 0;
    gx[0x48 / 4] = v;
    gx[0x48 / 4] = 0;
    gx[0x48 / 4] = v - 0xe000;
    gx[0x48 / 4] = 0;
    gx[0xc0 / 4] = 0;
    gx[4 / 4] = 1;
    gx[4 / 4] = 1;
}
