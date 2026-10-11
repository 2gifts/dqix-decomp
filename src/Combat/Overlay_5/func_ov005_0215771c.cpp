#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Obj0205eaa0;
struct Struct_0205bb84;

struct MemberScreen {
    char unk_0[R(0x4f8, 0x4fc)];
    int member_;
    char unk_500[R(0x56c - 0x4fc, 0x634 - 0x500)];
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
    char unk_0[R(0x196c, 0x19f4)];
    char cursor_[0x2d90 - 0x19f4];
    EquipmentSlot slots_[24];
    char unk_3030[0x3db8 - 0x3030];
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
};

extern unsigned short data_02114e30;
extern int data_02108760;

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" int _Z25CheckFlag30Or401_02157190v(EquipmentMenu* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* s);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" int func_ov005_021585fc(EquipmentMenu* self, int direction);

// USA: func_ov005_0215771c
extern "C" ARM void func_ov005_0215771c(EquipmentMenu* self) {
    signed char slot;
    int index = self->slot_ - 8;
    int cursor;
    if (index < 4 && TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40)) {
        func_ov005_0215792c(self, 3);
        self->slot_ = self->kind_;
        func_ov005_021579ec(self, self->state_, _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_));
        return;
    }
    int column = index % 4;
    int changed = 0;
    if (column == 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x20)) {
            changed = func_ov005_021585fc(self, -1);
            self->flags_ |= 0x20000;
        }
    } else if (column == 3 && TestFlag0SetAndFlag1Clear(&data_02114e30, 0x10)) {
        changed = func_ov005_021585fc(self, 1);
        self->flags_ |= 0x40000;
    }
    if (changed != 0)
        func_ov005_021555c0(self);
    else {
        self->flags_ &= ~0x20000;
        self->flags_ &= ~0x40000;
    }
    cursor = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_) + 8;
    slot = self->slot_;
    if (cursor != slot) {
        self->slot_ = cursor;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 2, 0);
        func_ov005_021579ec(self, self->state_, self->slot_);
        return;
    }
    if (cursor != slot)
        return;
    GameState::GetInstance();
    MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    if (!func_ov005_02157ae8(self, screen->member_))
        return;
    if (!_Z25CheckFlag30Or401_02157190v(self))
        return;
    if (self->slots_[self->slot_].item_ < 0)
        return;
    func_ov005_0215792c(self, 5);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
    screen->flags_ &= ~1;
    screen->flags_ &= ~0x80;
}
