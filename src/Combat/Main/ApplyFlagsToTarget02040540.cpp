#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_203cec4;
void SetField0x5cFlag0x4_0203ceb4(unsigned char* obj);
void SetOrClearFlag0x8_0203cec4(struct Struct_203cec4* obj, int enable);

struct ClampTarget_0203fc84;
void ClampValueAndStoreAt0x2c(struct ClampTarget_0203fc84* obj, int value);

struct S02037418;

struct BFieldAt50_02040540 {
    char pad[0x50];
    unsigned int val50;
};

struct CFieldAt0xac_02040540 {
    char pad[0xac];
    unsigned short valac;
};

struct ChildFlags_02040540 {
    char pad[0xc];
    unsigned int val;
};

struct Obj02040540 {
    unsigned int flags;
    unsigned int unk4;
    unsigned int unk8;
    struct ChildFlags_02040540* child;
    unsigned int unk10;
    struct Struct_203cec4* b;
    struct S02037418* c;
};

// USA: func_02040540
ARM void ApplyFlagsToTarget02040540(struct Obj02040540* obj) {
    if (obj->child == NULL) return;
    obj->flags |= obj->child->val;

    if (obj->b != NULL) {
        if (obj->flags & 0x4) SetField0x5cFlag0x4_0203ceb4((unsigned char*)obj->b);
        if (obj->flags & 0x10) SetOrClearFlag0x8_0203cec4(obj->b, 1);
        if (obj->flags & 0x20) ClampValueAndStoreAt0x2c((struct ClampTarget_0203fc84*)obj->b, 0x10);
        if (obj->flags & 0x100) ((struct BFieldAt50_02040540*)obj->b)->val50 |= 2;
        if (obj->flags & 0x400) ((struct BFieldAt50_02040540*)obj->b)->val50 |= 4;
        if (obj->flags & 0x800) ((struct BFieldAt50_02040540*)obj->b)->val50 |= 8;
    } else if (obj->c != NULL) {
        if (obj->flags & 0x4) ((struct CFieldAt0xac_02040540*)obj->c)->valac |= 4;
        if (obj->flags & 0x20) ((Object3D*)obj->c)->SetInheritedAlpha(0x10);
    }

    if (obj->flags & 0x8) obj->unk4 = 0;
}
