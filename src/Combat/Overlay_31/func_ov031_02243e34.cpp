#include <globaldefs.h>
#include "GameState/GameState.h"

struct Identifier02243e34 {
    unsigned int number : 12;
    unsigned int category : 4;
    unsigned int field_16 : 5;
    unsigned int field_21 : 5;
    unsigned int field_26 : 6;
};

struct Struct_02245528 {
    unsigned char padding_0[0x34];
    unsigned char state;
    unsigned char phase;
    unsigned char field_36;
    unsigned char field_37;
    unsigned char padding_38[0xc];
    unsigned char flags;
    unsigned char padding_45[0x32f];
    unsigned char options;
    unsigned char padding_375[3];
    Identifier02243e34 identifier;
    unsigned char padding_37c[8];
    int timer;
    unsigned char padding_388[0x48];
    unsigned char field_3d0;
};

struct Settings02243e34 {
    unsigned char padding_0[0x104];
    Identifier02243e34 identifier;
};

struct StateView02243e34 {
    unsigned char padding_0[0x5e6c];
    Settings02243e34 settings;
};

extern "C" void func_ov031_022125c8();
extern "C" int func_ov031_0221268c();
extern "C" void func_ov031_022120f8();
void SetField34AndClear35_37_02245528(Struct_02245528*, int);
extern "C" int func_ov031_0221244c(int*, int*);
extern "C" int func_ov017_021b2090(Identifier02243e34, Identifier02243e34);
void CallStub022169a0_02212784();
extern "C" void func_ov031_02245478(Struct_02245528*);

static inline Settings02243e34* GetSettings02243e34(GameState* state) {
    return &reinterpret_cast<StateView02243e34*>(state)->settings;
}

static inline int IsNonzero02243e34(int value) {
    return value != 0;
}

// USA: func_ov031_02243e34
extern "C" ARM void func_ov031_02243e34(Struct_02245528* object) {
    switch (object->phase) {
    case 0:
        object->phase = 4;
        break;
    case 4:
        func_ov031_022125c8();
        object->phase = 5;
        break;
    case 5: {
        int result = func_ov031_0221268c();
        if (result == 3) object->phase = 6;
        else if (result == 4) object->phase = 8;
        else if (result == 5 || result == 0) {
            func_ov031_022120f8();
            SetField34AndClear35_37_02245528(object, 0);
        }
        if (object->timer < 0x46000) object->timer += 0x333;
        break;
    }
    case 6: {
        int first[4];
        int second[3];
        if (func_ov031_0221244c(first, second)) {
            first[0] += 2000;
            object->identifier.number = first[0];
            object->identifier.category = first[1];
            object->identifier.field_16 = first[2];
            object->identifier.field_21 = second[0];
            object->identifier.field_26 = second[1];
            object->flags |= 4;
            if ((object->options & 0x10) && !IsNonzero02243e34(func_ov017_021b2090(GetSettings02243e34(GameState::GetInstance())->identifier, object->identifier))) {
                object->flags |= 0x80;
                object->options &= ~1;
            }
        } else object->options &= ~1;
        if (object->options & 0x80) object->phase = 7;
        else if (object->options & 2) {
            object->field_3d0 = 1;
            SetField34AndClear35_37_02245528(object, 5);
        } else if (!(object->options & 1)) object->phase = 7;
        else SetField34AndClear35_37_02245528(object, 4);
        break;
    }
    case 7:
        CallStub022169a0_02212784();
        object->phase = 5;
        break;
    case 8:
        func_ov031_02245478(object);
        func_ov031_022120f8();
        break;
    }
}
