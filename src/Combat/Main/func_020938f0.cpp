#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif

#include "std_library_functions.h"

struct Obj020938f0 {
    char pad0[IS_JPN ? 0x100 : 0x340];
    int handle340;
    int field344;
    char pad1[IS_JPN ? 0x30 : 0x80];
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
        _Z19ClearRegion02093980Pc(obj + i * (IS_JPN ? 0x10 : 0x34));
        _Z19ClearRegion02093980Pc(obj + (IS_JPN ? 0x80 : 0x1a0) + i * (IS_JPN ? 0x10 : 0x34));
    }
    struct Obj020938f0* p = (struct Obj020938f0*)obj;
    p->handle340 = -1;
    p->field344 = 0;
    memset(obj + (IS_JPN ? 0x108 : 0x348), 0, (IS_JPN ? 0x30 : 0x80));
    p->rest3c8 = 0;
    ((unsigned char*)obj)[(IS_JPN ? 0x138 : 0x3c8)] |= 0x80;
    p->flag3c9 = 0;
    p->field3cb = p->field3ca = 0;
    p->field3cc = 0;
    p->field3cd = p->field3cc | 8;
}
