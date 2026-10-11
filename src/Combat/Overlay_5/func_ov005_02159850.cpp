#if defined(jpn)
#define R(j,u) (j)
#define func_ov023_021dd4cc func_ov023_021ddcbc
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[R(0xee0, 0xee4)];
    char window_[R(0x3d33 - 0xee0, 0x3dbb - 0xee4)];
    signed char slot_;
    char unk_3dbc[0x3dcc - 0x3dbc];
    unsigned int flags_;
    char unk_3dd0[0x3ddc - 0x3dd0];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
};

struct MemberScreen {
    char unk_0[R(0x56c, 0x634)];
    unsigned short flags_;
};

struct MenuContext {
    char unk_0[R(0x34f8, 0x3708)];
    int* unknown_ptr_3708;
};

struct Entry_0205d6a0;

extern "C" MenuContext* func_ov017_0218b5b0();
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int unk);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);

// USA: func_ov005_02159850
extern "C" ARM void func_ov005_02159850(EquipmentMenu* self) {
    if (self->menuStep_ != 0)
        return;
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
    if (self->slot_ >= 0 && self->slot_ < 8)
        func_ov005_0215792c(self, 3);
    else if (self->slot_ >= 8 && self->slot_ < 24)
        func_ov005_0215792c(self, 4);
    self->menuStep_ = 0;
    self->menuChoice_ = 0;
    self->menuState_ = 0;
    MemberScreen* screen = _Z19GetField1c_021a193cPi(func_ov017_0218b5b0()->unknown_ptr_3708);
    screen->flags_ |= 0x81;
    self->flags_ |= 0xc;
}
