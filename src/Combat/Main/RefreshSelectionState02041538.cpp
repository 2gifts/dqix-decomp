#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct02041538 {
    char pad0[0x14];
    void* field14;
    char pad18[0x18 - 0x14 - 4];
    signed char field18;
    char pad_ac[0xac - 0x18 - 1];
    unsigned short field_ac;
    char pad_c4[0xc4 - 0xac - 2];
    unsigned char field_c4;
    char pad_cc[0xcc - 0xc4 - 1];
    void* field_cc;
    int field_d0;
    unsigned char field_d4_b0 : 1;
};

// USA: func_02041538
ARM void RefreshSelectionState02041538(struct Struct02041538* self) {
    if (self->field_d4_b0) return;
    self->field_ac &= ~1;
    if (self->field_cc != NULL) {
        if (self->field14 == self->field_cc) return;
        ((Object3D*)self)->MaybeSetRegularAnimation((char const*)self->field_cc, self->field_d0);
    } else {
        if (self->field_c4 == self->field18) return;
        ((Object3D*)self)->MaybeSetBCFGAnimation(self->field_c4, self->field_d0);
    }
}
