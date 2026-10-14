#include <globaldefs.h>
#include "World/Object3D.h"

struct IntField0x64_020377c4;
struct IntField0x68_020377b4;
struct Shorts5c_374e0;

struct AcTarget020484f8 {
    char unk0[0x8];
    short at8;
    short unkA;
    short atc;
    short ate;
};

struct Input020484f8 {
    struct AcTarget020484f8* ac;
    unsigned int val4;
    unsigned int val8;
};

// USA: func_020484f8
ARM void InitObjectFields020484f8(unsigned char* self, struct Input020484f8* in) {
    *(unsigned int*)(self + 0xb0) = in->val4;
    *(struct AcTarget020484f8**)(self + 0xac) = in->ac;
    *(unsigned int*)(self + 0xb4) = in->val8;
    ((Object3D*)((struct Shorts5c_374e0*)self))->SetScale(0x10a, 0x10a, 0x10a);
    ((Object3D*)((struct IntField0x64_020377c4*)self))->SetRadius((*(struct AcTarget020484f8**)(self + 0xac))->atc << 2);
    ((Object3D*)((struct IntField0x68_020377b4*)self))->SetHeight((*(struct AcTarget020484f8**)(self + 0xac))->ate);
    if ((*(struct AcTarget020484f8**)(self + 0xac))->at8 == 0x140) {
        ((Object3D*)self)->EnableFlag(0x20000000);
    }
    if (((Object3D*)self)->GetFlags() & 0x20000000) return;
    ((Object3D*)self)->UseRenderConfigDiffuseColor();
}
