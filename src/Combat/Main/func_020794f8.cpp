#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj020794f8 {
    Object3D obj3D_;
    char pad_ac[0xae - 0xac];
    short field_ae;
};

extern "C" void func_ov017_021c95ec(int id, int lowNibble, int unused, int kind, int highNibble,
                                    Vector3fix v, int field8, int flag6, int flag7);

// USA: func_020794f8
extern "C" ARM void func_020794f8(struct Obj020794f8* self, int flag6, int flag7) {
    int id = self->obj3D_.GetField06();
    int v4 = *(volatile short *)&self->obj3D_.unknown_4_;
    int v2 = self->obj3D_.unknown_2_;
    Vector3fix v = self->obj3D_.position_;
    short field8 = self->field_ae;
    int rem = (v4 - 0x70) % 12;
    if (rem < 0 || rem >= 12) {
        return;
    }
    func_ov017_021c95ec(id, rem, v2, 1, -1, v, field8, flag6, flag7);
}
