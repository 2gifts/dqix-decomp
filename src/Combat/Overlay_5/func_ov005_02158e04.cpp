#include <globaldefs.h>

struct MenuElement {
    char unk_0[0xc5];
    unsigned char flags_;
};

struct EquipmentMenu {
    char unk_0[0xee4];
    char window_[0x3dbb - 0xee4];
    signed char slot_;
    char unk_3dbc[0x3ddc - 0x3dbc];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;

    char* GetWindow() { return window_; }
};

extern "C" MenuElement* _Z21FindElementForFieldB0P15Struct_0205d81c(void* window);
extern "C" int _Z17IsField0x9cEqual3Ph(MenuElement* elem);
extern "C" void _Z14SetFieldAt0x30Pvi(void* p, int value);
extern "C" unsigned char func_0205d0e0(void* window, int arg);
extern "C" void func_ov005_02158f80(EquipmentMenu* self);
extern "C" void func_ov005_0215916c(EquipmentMenu* self);
extern "C" void func_ov005_02159208(EquipmentMenu* self);
extern "C" void func_ov005_02159274(EquipmentMenu* self);
extern "C" void func_ov005_02159850(EquipmentMenu* self);
extern "C" void func_ov005_02158ed0(EquipmentMenu* self);

// USA: func_ov005_02158e04
extern "C" ARM void func_ov005_02158e04(EquipmentMenu* self, int arg) {
    MenuElement* elem = _Z21FindElementForFieldB0P15Struct_0205d81c(self->window_);
    if (elem != NULL && _Z17IsField0x9cEqual3Ph(elem) && !(elem->flags_ & 2))
        _Z14SetFieldAt0x30Pvi(self->GetWindow() + 4, -1);
    self->menuResult_ = func_0205d0e0(self->window_, arg);
    switch (self->menuState_) {
    case 0:
        func_ov005_02158f80(self);
        break;
    case 1:
        func_ov005_0215916c(self);
        break;
    case 2:
        func_ov005_02159208(self);
        break;
    case 3:
        func_ov005_02159274(self);
        break;
    case 4:
        func_ov005_02159850(self);
        break;
    }
    func_ov005_02158ed0(self);
}
