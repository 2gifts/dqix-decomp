#include <globaldefs.h>

struct Obj0205eaa0;
struct Struct_0205bb84;

struct EquipmentMenu {
    char unk_0[0x19f4];
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
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" int _Z25CheckFlag30Or401_02157190v(EquipmentMenu* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* s);
extern "C" int func_ov005_02158560(EquipmentMenu* self, unsigned char kind, int silent);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);

// USA: func_ov005_0215742c
extern "C" ARM void func_ov005_0215742c(EquipmentMenu* self) {
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80)) {
        func_ov005_0215792c(self, 3);
        self->slot_ = self->kind_;
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x80))
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 2, 0);
        else if (_Z25CheckFlag30Or401_02157190v(self))
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov005_021579ec(self, self->state_, self->slot_);
        return;
    }
    if (!func_ov005_02158560(self, _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)self->cursor_), 0))
        return;
    self->flags_ |= 0x100;
    func_ov005_021579ec(self, self->state_, self->kind_);
    func_ov005_021555c0(self);
}
