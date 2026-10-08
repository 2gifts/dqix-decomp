#include <globaldefs.h>
#include <GameState/GameState.h>

struct Obj0205eaa0;

struct MemberScreen {
    char unk_0[0x4fc];
    int member_;
    char unk_500[0x634 - 0x500];
    unsigned short flags_;
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    char unk_0[0x19f4];
    char cursor_[0x2d90 - 0x19f4];
    EquipmentSlot slots_[24];
    char slotModels_[0x3d78 - 0x3030];
    short dragged_;
    char unk_3d7a[0x3db8 - 0x3d7a];
    unsigned char state_;
    unsigned char lastState_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unk_3dbe;
    signed char lastPage_;
    signed char unk_3dc0;
    char unk_3dc1[0x3dcc - 0x3dc1];
    unsigned int flags_;
    char unk_3dd0[0x3de0 - 0x3dd0];
    short swapped_;
};

extern int data_02108760;

extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void func_0205bb04(void* cursor, int index);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);

// USA: func_ov005_021567ac
extern "C" ARM void func_ov005_021567ac(EquipmentMenu* self, int x, int y) {
    GameState::GetInstance();
    MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    if (!func_ov005_02157ae8(self, screen->member_))
        return;
    self->dragged_ = func_ov005_02155670(self, x, y);
    if (self->dragged_ >= 8 && self->dragged_ < 24) {
        if (self->slots_[self->dragged_].item_ == -1) {
            self->dragged_ = -1;
            self->unk_3dc0 = -1;
            return;
        }
        func_ov005_0215792c(self, 4);
        self->slot_ = self->dragged_;
        func_ov005_021579ec(self, self->state_, self->slot_);
        func_0205bb04(self->cursor_, self->slot_ - 8);
        self->swapped_ = (self->slot_ - 8) + self->page_ * 16;
        self->unk_3dc0 = 0;
        self->flags_ |= 0x80;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 2, 0);
        screen->flags_ &= ~1;
        screen->flags_ &= ~0x80;
        self->flags_ &= ~4;
        self->flags_ &= ~8;
        return;
    }
    self->dragged_ = -1;
    self->unk_3dc0 = -1;
}
