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
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" int func_ov005_02157ae8(EquipmentMenu* self, int member);
extern "C" void func_0205bb04(void* cursor, int index);

// USA: func_ov005_0215751c
extern "C" ARM void func_ov005_0215751c(EquipmentMenu* self) {
    int up = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x40))
        up = 1;
    if (up) {
        func_ov005_0215792c(self, 2);
        func_ov005_021579ec(self, self->state_, _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_));
        return;
    }
    int down = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80))
        down = 1;
    if (!up) {
        GameState::GetInstance();
        MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
        if (!func_ov005_02157ae8(self, screen->member_))
            return;
        if (_Z25CheckFlag30Or401_02157190v(self)) {
            if (self->slots_[self->kind_].item_ < 0) {
                down = 1;
            } else {
                func_ov005_0215792c(self, 5);
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
                screen->flags_ &= ~1;
                screen->flags_ &= ~0x80;
            }
        }
    }
    if (down) {
        func_ov005_0215792c(self, 4);
        self->slot_ = 8;
        func_0205bb04(self->cursor_, self->slot_ - 8);
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80))
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 2, 0);
        else if (_Z25CheckFlag30Or401_02157190v(self))
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov005_021579ec(self, self->state_, self->slot_);
        return;
    }
    if (!func_ov005_02158560(self, _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_), 0))
        return;
    self->slot_ = self->kind_;
    self->flags_ |= 0x100;
    func_ov005_021555c0(self);
}
