#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj020938f0 {
    char pad0[0x340];
    int handle340;
    int field344;
    char pad1[0x3c8 - 0x348];
    unsigned char rest3c8 : 7;
    unsigned char flag3c8 : 1;
    unsigned char flag3c9 : 1;
    unsigned char field3ca;
    unsigned char field3cb;
    unsigned char field3cc;
    unsigned char field3cd;
};

extern "C" void _Z19ClearRegion02093980Pc(char* obj);

// USA: func_020938f0
extern "C" ARM void func_020938f0(char* obj) {
    int i;
    for (i = 0; i < 8; i++) {
        _Z19ClearRegion02093980Pc(obj + i * 0x34);
        _Z19ClearRegion02093980Pc(obj + 0x1a0 + i * 0x34);
    }
    struct Obj020938f0* p = (struct Obj020938f0*)obj;
    p->handle340 = -1;
    p->field344 = 0;
    memset(obj + 0x348, 0, 0x80);
    p->rest3c8 = 0;
    ((unsigned char*)obj)[0x3c8] |= 0x80;
    p->flag3c9 = 0;
    p->field3cb = p->field3ca = 0;
    p->field3cc = 0;
    p->field3cd = p->field3cc | 8;
}