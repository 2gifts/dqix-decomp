#include <globaldefs.h>
#include "System/Matrix.h"

struct Inner02048c90 {
    char pad00[0x10];
    Vector3i vec10;
    char pad1c[0x4];
    unsigned int flags20;
    char pad24[0x10];
    unsigned char b34;
    char pad35[0x3];
    int i38;
    unsigned short h3c;
    char pad3e[0x2];
    Vector3i vec40;
};

struct Obj02048c90 {
    char pad00[0x13c];
    struct Inner02048c90* ptr;
};

// USA: func_02048c90
ARM void ResetInnerState02048c90(struct Obj02048c90* obj) {
    if (obj->ptr == NULL) return;
    obj->ptr->b34 = 0;
    obj->ptr->i38 = 0;
    obj->ptr->h3c = 0;
    obj->ptr->vec40 = obj->ptr->vec10;
    obj->ptr->flags20 &= ~0x10;
    obj->ptr->flags20 &= ~0x40;
}
