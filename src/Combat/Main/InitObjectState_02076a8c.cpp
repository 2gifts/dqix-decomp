#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

// USA: func_02076a8c  (semantic: InitObjectState_02076a8c)
extern "C" ARM void func_02076a8c(unsigned char* p) {
    func_02032e58(p);

    *(unsigned short*)(p + 0x0) |= 0x20;
    *(unsigned short*)(p + 0xb4) = 0x1c2;
    *(int*)(p + 0x130) = 1;
    *(int*)(p + 0x134) = 1;
    *(unsigned char*)(p + 0x138) = 1;
    *(unsigned char*)(p + 0x139) = 2;
    *(unsigned char*)(p + 0x13a) = 1;
    *(unsigned char*)(p + 0x13b) = 3;
    *(unsigned char*)(p + 0x13c) = 1;
    *(int*)(p + 0x140) = 0x1e;
    *(int*)(p + 0x144) = 5;
    *(int*)(p + 0x148) = 0x1000;
    *(int*)(p + 0x14c) = 0;
    *(int*)(p + 0x150) = 0;
    *(int*)(p + 0x154) = 0;
    *(unsigned short*)(p + 0x164) = 0;
    *(unsigned short*)(p + 0x166) = 0;
    *(unsigned short*)(p + 0x168) = 0;
    *(unsigned char*)(p + 0x17d) = 0;
    *(int*)(p + 0x170) = 0;
    *(unsigned short*)(p + 0x174) = 0;
    *(unsigned short*)(p + 0x176) = 0;
    *(unsigned char*)(p + 0x17a) = 0;
    *(unsigned char*)(p + 0x17b) = 0;
    *(unsigned char*)(p + 0x17c) = 0;
    *(int*)(p + 0x180) = 0;
    *(int*)(p + 0x184) = 0;
    *(unsigned short*)(p + 0x16a) = 0;
    *(unsigned char*)(p + 0x17e) = 0;
    *(int*)(p + 0x158) = 0;
    *(int*)(p + 0x15c) = 0;
    *(int*)(p + 0x160) = 0;

    _ZN8Object3D11DisableFlagEi(p, 0x80);
}
