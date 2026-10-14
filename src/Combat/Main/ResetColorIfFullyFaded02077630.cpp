#include <globaldefs.h>
#include "World/Object3D.h"

struct Bits40_37464 {
    char unk0[0x40];
    unsigned char lo3 : 3;
    unsigned char hi5 : 5;
};

extern "C" void _ZN8Vector3iaSERKS_(int* a, int* b);

struct Struct020372b8 {
    char pad[0x40];
    unsigned char lo3 : 3;
    unsigned char field5 : 5;
    char pad2[0x2f];
    unsigned short f70;
};

void TrySetMode02076ccc(void*, int);

// USA: func_02077630
ARM void ResetColorIfFullyFaded02077630(void* obj) {
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0 && ((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0x1f) {
        return;
    }
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() == 0) {
        _ZN8Vector3iaSERKS_((int*)((char*)obj + 0x44), (int*)((char*)obj + 0x158));
        ((Object3D*)((struct Struct020372b8*)obj))->TransitionInheritedAlpha(0x1f, 0xfa);
    }
    if (((Object3D*)((struct Bits40_37464*)obj))->GetInheritedAlpha() != 0x1f) {
        return;
    }
    TrySetMode02076ccc(obj, 1);
}
