#include <globaldefs.h>

struct State0xbb1c {
    char unk0[8];
    int unk8;
    int unkC;
    int unk10;
    short unk14;
    short unk16;
    short unk18;
};

// USA: func_0203bb1c
ARM void ClearFields0x8_0203bb1c(struct State0xbb1c* obj) {
    obj->unk8 = 0;
    obj->unkC = 0;
    obj->unk10 = 0;
    obj->unk14 = 0;
    obj->unk16 = 0;
    obj->unk18 = 0;
}
