#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0xea4];
    char background1_[0x3dbc - 0xea4];
    unsigned char kind_;
    char unk_3dbd[0x3dcc - 0x3dbd];
    unsigned int flags_;
};

struct Obj0204b010;
struct Obj0204b8d0;

extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(Obj0204b010* background, void* unk);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g, unsigned short h);
extern "C" void func_0204b04c(void* background, int unk);

// USA: func_ov005_0215a720
extern "C" ARM void func_ov005_0215a720(EquipmentMenu* self) {
    if (!(self->flags_ & 0x100))
        return;
    _Z19ClearBuffer0204b010P11Obj0204b010Pv((Obj0204b010*)self->background1_, 0);
    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((Obj0204b8d0*)self->background1_, 0, 0, 0, 0x10, 0, 0x10, 0x16, 0xffff);
    _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((Obj0204b8d0*)self->background1_, (unsigned char)(self->kind_ + 1), 0, 0, (short)(self->kind_ * 2 + 0xf), 0, 4, 3, 0xffff);
    func_0204b04c(self->background1_, 0);
}
