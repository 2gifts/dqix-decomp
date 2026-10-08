#include <globaldefs.h>

extern "C" void Mat4x3_WriteIdentity(void* mtx);

struct Obj02056b48 {
    unsigned char pad_00[0x04];
    int f04;
    int f08;
    unsigned char pad_0c[0x04];
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    unsigned char pad_28[0x10];
    unsigned char f38;
    unsigned char pad_39[0x03];
    unsigned short f3c;
    unsigned char pad_3e[0x0e];
    int f4c;
    int f50;
    int f54;
    int f58;
    unsigned short f5c;
    unsigned short f5e;
    unsigned short f60;
    unsigned short f62;
    int f64[3];
    int f70[3];
    int f7c[3];
    unsigned short f88[3];
    unsigned short f8e[3];
    unsigned short f94[3];
    int f9c;
    unsigned short fa0;
    unsigned char pad_a2[0x02];
    int fa4[3];
    int fb0[3];
    unsigned short fbc[3];
    unsigned short fc2;
    unsigned char pad_c4[0x24];
    unsigned int mtx[12];
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128[3];
    int f134[3];
    int f140[3];
    unsigned char pad_14c[0x04];
    int f150;
    unsigned char pad_154[0x04];
    int f158[3];
    int f164[3];
};

// USA: func_02056b48
extern "C" ARM void func_02056b48(struct Obj02056b48* p) {
    p->f38 = 0;
    p->f04 = 0;
    p->f08 = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f3c = 0;
    p->f4c = 0;
    p->f50 = 0;
    p->f54 = 0;
    p->f58 = 0;
    p->f118 = 0;
    p->f11c = 0;
    p->f120 = 0;
    p->f124 = 0;
    p->f5c = 0;
    p->f5e = 0;
    p->f60 = 0;
    p->f62 = 0;
    p->f9c = 0;
    p->fa0 = 0;
    p->f150 = 0;

    for (int i = 0; i < 3; i++) {
        p->f128[i] = 0;
        p->f134[i] = 0;
        p->f140[i] = 0;
        p->f64[i] = 0;
        p->f70[i] = 0;
        p->f7c[i] = 0;
        p->f88[i] = 0;
        p->f8e[i] = 0;
        p->f94[i] = 0;
    }

    for (int i = 0; i < 3; i++) {
        p->f158[i] = 0;
        p->f164[i] = 0;
        p->fa4[i] = 0;
        p->fb0[i] = 0;
        p->fbc[i] = 0;
    }

    p->fc2 = 0;
    Mat4x3_WriteIdentity(&p->mtx);
}