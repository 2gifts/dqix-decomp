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
    char unk_0[R(0x56c, 0x634)];
    unsigned short flags_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c, 0x19f4)];
    char cursor_[0x3db8 - 0x19f4];
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
extern "C" int func_0205bf58(void* cursor, int ticks);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* s);
extern "C" void func_ov005_0215742c(EquipmentMenu* self);
extern "C" void func_ov005_0215751c(EquipmentMenu* self);
extern "C" void func_ov005_0215771c(EquipmentMenu* self);

// USA: func_ov005_0215730c
extern "C" ARM void func_ov005_0215730c(EquipmentMenu* self) {
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
        func_ov005_0215792c(self, 1);
        MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
        screen->flags_ |= 0x800;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 0x1b, 0);
        return;
    }
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 4)) {
        if (self->state_ == 2 || self->state_ == 3 || self->state_ == 4) {
            func_ov005_0215792c(self, 7);
            self->flags_ |= 0x80000;
            return;
        }
    }
    int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_0205bf58(self->cursor_, ticks);
    _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_);
    switch (self->state_) {
    case 2:
        func_ov005_0215742c(self);
        return;
    case 3:
        func_ov005_0215751c(self);
        return;
    case 4:
        func_ov005_0215771c(self);
        return;
    }
}
