#include <globaldefs.h>
#include "World/Object3D.h"

struct State02041244 {
    char pad_00[0xac];
    unsigned short field_ac;
    char pad_ae[2];
    int field_b0;
    char pad_b4[0xc];
    int field_c0;
    unsigned char field_c4;
    char pad_c5[3];
    int field_c8;
    int field_cc;
    int field_d0;
    unsigned char flags_d4;
};

// USA: func_02041244
ARM void ResetState02041244(struct State02041244* obj) {
    ((Object3D*)obj)->Initialize();
    obj->field_ac = 0;
    obj->field_b0 = 0;
    obj->field_c0 = 0;
    obj->field_c4 = 0;
    obj->field_cc = 0;
    obj->field_c8 = 0x7a;
    obj->flags_d4 &= ~1;
    obj->flags_d4 &= ~2;
    obj->field_d0 = 0;
}
