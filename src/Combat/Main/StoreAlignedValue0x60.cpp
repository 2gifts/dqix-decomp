#include <globaldefs.h>

struct State0xcda8 {
    char unk0[0x60];
    int unk60;
    int unk64;
};

// USA: func_0203cda8
ARM void StoreAlignedValue0x60_0203cda8(struct State0xcda8* obj, int value) {
    obj->unk60 = value;
    if ((unsigned int)(value & 0xff) >= (unsigned int)-128) {
        obj->unk60 = (value & ~0xff) + 0x100;
    } else {
        obj->unk60 = value & ~0xff;
    }
    obj->unk64 = obj->unk60;
}
