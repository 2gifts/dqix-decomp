#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02088e80 {
    char pad0[0x14];
    int f14;
    int f18;
    char pad1c[0x21 - 0x1c];
    unsigned char b21;
    unsigned short h22;
    unsigned char b24;
    char pad25[0x32 - 0x25];
    short h32;
    short h34;
    char pad36[0x3b - 0x36];
    unsigned char b3b;
    char pad3c[0x58 - 0x3c];
    unsigned char f58[4];
    unsigned char f5c[0x23];
    unsigned char f7f[0x23];
};

// USA: func_02088e80
ARM void InitObj02088e80(Obj02088e80* obj, int) {
    int hadBit2 = 0;
    if (obj->f14 & 0x4) hadBit2 = 1;
    obj->f14 = 1;
    obj->f18 = 0;
    obj->b21 = 0;
    obj->h22 &= ~0x3;
    obj->h22 &= ~0x3c;
    obj->h22 &= ~0x1c0;
    obj->h22 &= ~0xe00;
    obj->h22 &= ~0x3000;
    obj->b24 = 0;
    obj->h22 &= ~0x4000;
    obj->b3b &= ~0x8;
    obj->b3b &= ~0xf0;
    obj->b3b &= ~0x4;
    obj->h32 = -1;
    obj->h34 = -1;
    if (hadBit2) {
        obj->f14 |= 0x4;
    }
    memset(obj->f58, 0, 4);
    memset(obj->f5c, 0, 0x23);
    memset(obj->f7f, 0, 0x23);
}
