#include <globaldefs.h>
#if defined(jpn)

#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov005_0215a720 func_ov005_0215bc6c
#endif

struct EquipmentMenu {
    char unk_0[LOW_REGION(0xea0, 0xea4)];
    char background1_[LOW_REGION(0x3d34, 0x3dbc) - LOW_REGION(0xea0, 0xea4)];
    unsigned char kind_;
    char unk_3dbd[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0x3d35, 0x3dbd)];
    unsigned int flags_;
};

struct Obj0204b010;
struct Obj0204b8d0;

void ClearBuffer0204b010(Obj0204b010* background, void* unk);
void DispatchEntry0204b8d0(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g, unsigned short h);
extern "C" void func_0204b04c(void* background, int unk);

// USA: func_ov005_0215a720
extern "C" ARM void func_ov005_0215a720(EquipmentMenu* self) {
    if (!(self->flags_ & 0x100))
        return;
    ClearBuffer0204b010((Obj0204b010*)self->background1_, 0);
    DispatchEntry0204b8d0((Obj0204b8d0*)self->background1_, 0, 0, 0, 0x10, 0, 0x10, 0x16, 0xffff);
    DispatchEntry0204b8d0((Obj0204b8d0*)self->background1_, (unsigned char)(self->kind_ + 1), 0, 0, (short)(self->kind_ * 2 + 0xf), 0, 4, 3, 0xffff);
    func_0204b04c(self->background1_, 0);
}
