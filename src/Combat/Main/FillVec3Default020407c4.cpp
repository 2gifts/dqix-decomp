#include <globaldefs.h>
#include "Combat/EntryGetterTypes.h"

extern "C" void __clear(void* out, int size);

int GetField0x60(struct StructF0x60_0203cdd0* obj);

struct Vec3_020407c4 { unsigned int v[3]; };

struct Self020407c4 {
    unsigned char pad0[0x14];
    void* field14;
    unsigned char* field18;
    unsigned char* field1c;
};

// USA: func_020407c4
ARM void FillVec3Default020407c4(struct Vec3_020407c4* out, struct Self020407c4* self) {
    Vec3_020407c4 tmp;
    if (self->field14 != NULL) {
        __clear(&tmp, 0xc);
        tmp.v[1] = GetField0x60((struct StructF0x60_0203cdd0*)self->field14);
        *out = tmp;
        return;
    }
    if (self->field18 != NULL) {
        *out = *(struct Vec3_020407c4*)(self->field18 + 0x50);
        return;
    }
    if (self->field1c != NULL) {
        *out = *(struct Vec3_020407c4*)(self->field1c + 0x50);
        return;
    }
    {
        Vec3_020407c4 zero;
        zero.v[0] = 0;
        zero.v[1] = 0;
        zero.v[2] = 0;
        *out = zero;
    }
}
