#include <globaldefs.h>

struct UpdateStateStruct {
    char unk0[0x10];
    unsigned short field10;
    char unk12[2];
    unsigned char field14;
    char unk15;
    unsigned char field16;
    char unk17;
    unsigned char field18;
};

// USA: func_02015a98
ARM void UpdateActivationState_02015a98(UpdateStateStruct* p, int value, int clearFlag, int force) {
    if (p->field16 == 1) {
        p->field16 = 2;
        p->field14 = value;
        p->field10 = 0;
    } else if (force) {
        p->field16 = 2;
        p->field14 = value;
        p->field10 = 0;
    }
    if (clearFlag) {
        p->field18 = 0;
    }
}
