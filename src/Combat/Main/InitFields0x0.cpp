#include <globaldefs.h>
#if defined(jpn)
#include "std_library_functions.h"
#endif

struct State0xc0cc {
#if defined(jpn)
    char entries[0x14];
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned int low16 : 16;
    unsigned int next8 : 8;
    unsigned int high8 : 8;
    int unk34;
#else
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    short unk14;
#endif
};

// USA: func_0203c0cc
ARM void InitFields0x0_0203c0cc(struct State0xc0cc* obj) {
#if defined(jpn)
    memset(obj->entries, -1, sizeof(obj->entries));
    obj->unk18 = 0;
    obj->unk14 = 0;
    obj->unk1c = 16;
    obj->unk20 = 12;
    obj->unk24 = 0;
    obj->unk2c = 0;
    obj->low16 = 0;
    obj->next8 = 0;
    obj->unk34 = 0;
    obj->unk28 = 0;
#else
    obj->unk4 = 0;
    obj->unk0 = 0;
    obj->unk8 = 0;
    obj->unk10 = 0;
    obj->unkC = 0;
    obj->unk14 = -1;
#endif
}
