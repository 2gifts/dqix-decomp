#include <globaldefs.h>
#include "std_library_functions.h"

struct Packed10_891cc {
    unsigned int fa : 10;
    unsigned int fb : 10;
    unsigned int fc : 8;
    unsigned int fd : 2;
    unsigned int fe : 2;
};

struct Packed3b_891cc {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 4;
};

struct Packed3c_891cc {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 2;
};

struct Obj020891cc {
    unsigned short w00;
    unsigned short w02;
    unsigned short w04;
    unsigned short w06;
    unsigned short w08;
    unsigned short w0a;
    unsigned short w0c;
    struct Packed10_891cc p10;
    unsigned int w14;
    unsigned int w18;
    unsigned int w1c;
    unsigned char b20;
    unsigned char b21;
    unsigned short w22;
    unsigned char b24;
    unsigned char b25;
    unsigned char b26;
    unsigned char b27;
    short w28;
    short w2a;
    short w2c;
    short w2e;
    unsigned short w30;
    short w32;
    short w34;
    unsigned short w36;
    unsigned char b38;
    unsigned char b39;
    unsigned char b3a;
    struct Packed3b_891cc p3b;
    struct Packed3c_891cc p3c;
    unsigned char b3d;
    unsigned char blk3e[0x16];
    unsigned char pad54[4];
    unsigned int w58;
    unsigned char blk5c[0x23];
    unsigned char blk7f[0x23];
};

// USA: func_020891cc
extern "C" ARM void func_020891cc(struct Obj020891cc* obj) {
    obj->w00 = 0;
    obj->w02 = 0;
    obj->w04 = 0;
    obj->w06 = 0;
    obj->w0c = 0;
    obj->w08 = 0;
    obj->w0a = 0;
    obj->p10.fa = 0;
    *(unsigned int*)&obj->p10 &= 0xfff003ff;
    *(unsigned int*)&obj->p10 &= 0xc00fffff;
    memset(&obj->blk3e, 0x64, sizeof(obj->blk3e));
    obj->w14 = 0;
    obj->w18 = 0;
    obj->w1c = 0;
    obj->b20 = 0;
    obj->b21 = 0;
    obj->w22 &= ~3;
    obj->w22 &= ~0xe00;
    obj->w22 &= ~0x3c;
    obj->w22 &= ~0x1c0;
    obj->w22 &= ~0x3000;
    obj->b24 = 0;
    obj->w22 &= ~0x4000;
    obj->b25 = 0;
    obj->b26 = 0;
    obj->w28 = -1;
    obj->w2a = -1;
    obj->w2c = -1;
    obj->w2e = -1;
    obj->w30 = 0;
    obj->w32 = -1;
    obj->w34 = -1;
    obj->w36 = 0;
    obj->b38 = 0;
    obj->b39 = 0;
    obj->b3a = 0;
    obj->p3b.b0 = 0;
    obj->p3b.b1 = 0;
    obj->p3b.b2 = 0;
    obj->p3b.b3 = 0;
    obj->p3b.b4 = 0;
    obj->p3c.b0 = 0;
    obj->p3c.b1 = 0;
    obj->p3c.b2 = 0;
    obj->p3c.b3 = 0;
    obj->p3c.b4 = 0;
    obj->p3c.b5 = 0;
    obj->b3d = 0;
    memset(&obj->w58, 0, sizeof(obj->w58));
    memset(&obj->blk5c, 0, sizeof(obj->blk5c));
    memset(&obj->blk7f, 0, sizeof(obj->blk7f));
}