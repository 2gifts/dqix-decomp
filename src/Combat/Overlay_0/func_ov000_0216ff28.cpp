#include <globaldefs.h>
#include "std_library_functions.h"

struct State0xc0cc {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    short unk14;
};

void InitFields0x0(struct State0xc0cc* obj);

struct CombatantStatus {
    char unk0[0x1c];
    unsigned char active : 1;
    unsigned char unk1c_1 : 7;
    char unk1d[0x28 - 0x1d];
};

extern "C" void func_ov000_0216fe9c(struct CombatantStatus* status);

struct Combatant {
    int unk0;
    int unk4;
    struct CombatantStatus status;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    struct State0xc0cc unk50;
    struct State0xc0cc unk68;
    short unk80;
    short unk82;
    char unk84[2];
    unsigned char unk86;
    unsigned char unk87;
    unsigned char unk88[0x13];
    int unk9c[0x42];
    int unk1a4[0x93];
    int unk3f0[0x10];
    short unk430;
    short unk432;
    int unk434;
    int unk438;
    unsigned char unk43c;
    signed char unk43d;
    unsigned char unk43e;
    unsigned char unk43f;
    unsigned char unk440;
    unsigned char unk441;
    signed char unk442;
    unsigned char unk443;
    unsigned char unk444;
    unsigned char unk445;
};

// USA: func_ov000_0216ff28
extern "C" ARM void func_ov000_0216ff28(struct Combatant* obj) {
    int i;
    obj->unk0 = 0;
    obj->unk4 = 0;
    func_ov000_0216fe9c(&obj->status);
    obj->unk87 = 0;
    obj->unk30 = 0;
    obj->unk38 = 0;
    obj->unk3c = 0;
    obj->unk40 = 0;
    obj->unk48 = 0;
    obj->unk44 = 0;
    obj->unk4c = -1;
    obj->unk82 = 0;
    obj->unk86 = 0;
    obj->unk80 = 0x7fff;
    obj->unk438 = 0;
    obj->unk43c = 0;
    obj->unk430 = 0x7fff;
    obj->unk432 = 0x7fff;
    obj->unk434 = 0;
    obj->unk43d = -1;
    obj->unk43e = 0;
    obj->unk440 = 0;
    obj->unk43f = 0;
    obj->unk441 = 0;
    obj->unk442 = -1;
    obj->unk443 = 5;
    obj->unk444 = 0;
    obj->unk445 = 1;
    InitFields0x0(&obj->unk68);
    InitFields0x0(&obj->unk50);
    memset(obj->unk88, 0, sizeof(obj->unk88));
    for (i = 0; i < 0x42; i++) {
        obj->unk9c[i] = 0;
    }
    for (i = 0; i < 0x93; i++) {
        obj->unk1a4[i] = 0;
    }
    for (i = 0; i < 0x10; i++) {
        obj->unk3f0[i] = 0;
    }
    obj->status.active = 0;
}
