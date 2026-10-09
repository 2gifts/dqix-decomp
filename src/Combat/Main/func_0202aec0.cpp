#include <globaldefs.h>
#include "Resource/TextEncoding.h"

extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" void func_020c99c8(void* out);

struct SubState_0202aec0 {
    int f0;
    int f4;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    unsigned char f10;
    unsigned char f11;
    unsigned char pad12[2];
    unsigned char f14[0x14];
    unsigned char f28;
    unsigned char f29;
    unsigned char pad2a[10];
    int f34;
    unsigned char f38[0x10];
    unsigned char f48[0x10];
};

struct Obj_0202aec0 {
    int f0;
    short f4;
    short pad6;
    int f8;
    int fc;
    unsigned char f10[0x780];
    unsigned char f790[0x28];
    unsigned char pad7b8[8];
    unsigned char f7c0[0x400];
    unsigned char fbc0[0x400];
    int ffc0;
    unsigned char ffc4[0x3c];
    SubState_0202aec0 sub;
};

struct Info_0202aec0 {
    int f0;
    unsigned short name[11];
    unsigned short f1a;
    unsigned char pad1c[0x38];
};

extern int data_020fefcc;

// USA: func_0202aec0
extern "C" ARM void func_0202aec0(Obj_0202aec0* obj) {
    Info_0202aec0 info;

    obj->f0 = 0;
    obj->f4 = 0;
    obj->f8 = 0;
    obj->fc = 0;
    obj->ffc0 = 0;
    obj->sub.f4 = 0;
    obj->sub.f8 = -1;
    memset(obj->sub.f14, 0, 0x24);
    memset(obj->f10, 0, 0x780);
    memset(obj->f790, 0, 0x28);
    memset(obj->f7c0, 0, 0x400);
    memset(obj->fbc0, 0, 0x400);
    memset(obj->ffc4, 0, 0x40);

    func_020c99c8(&info);
    obj->sub.f28 = info.f1a;
    func_020328bc(obj->sub.f14, info.name, obj->sub.f28);

    obj->sub.f29 = obj->sub.f29 & ~8;
    obj->sub.f34 = 0;
    obj->sub.fc = 1;
    obj->sub.fd = 1;
    obj->sub.fe = 0;
    obj->sub.ff = 0;
    obj->sub.f10 = 0;
    (&data_020fefcc)[1] = 0;
    memset(obj->sub.f38, 0, 0x10);
    memset(obj->sub.f48, 0, 0x10);
    obj->sub.f11 = 1;
}
