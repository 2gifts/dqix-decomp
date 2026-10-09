#include <globaldefs.h>

struct Obj0205eaa0;

struct EquipmentMenu {
    char unk_0[0x3daa];
    unsigned char pageStep_;
    char unk_3dab[0x3dbc - 0x3dab];
    unsigned char kind_;
    signed char page_;
    unsigned char lastKind_;
    signed char lastPage_;
    char unk_3dc0[0x3dcc - 0x3dc0];
    unsigned int flags_;
    char unk_3dd0[0x3dfc - 0x3dd0];
    unsigned char pages_[8];
};

extern int data_02108760;

extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);

// USA: func_ov005_02158560
extern "C" ARM int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent) {
    if (kind == self->kind_)
        return 0;
    if (silent == 0)
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
    self->lastKind_ = self->kind_;
    self->lastPage_ = self->page_;
    self->pages_[self->kind_] = self->page_;
    self->kind_ = kind;
    self->page_ = self->pages_[self->kind_];
    self->flags_ |= 0x800 | 0x40;
    self->pageStep_ = 0;
    return 1;
}
