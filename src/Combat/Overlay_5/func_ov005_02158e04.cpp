#include <globaldefs.h>
#if defined(jpn)
#define func_ov005_0215916c func_ov005_0215a688
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov005_02158e04 func_ov005_0215a36c
#endif

struct MenuElement {
    char unk_0[0xc5];
    unsigned char flags_;
};

struct EquipmentMenu {
    char unk_0[LOW_REGION(0xee0, 0xee4)];
    char window_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char slot_;
    char unk_3dbc[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;

    char* GetWindow() { return window_; }
};

struct Struct_0205d81c;
MenuElement* FindElementForFieldB0_0205d8c4(Struct_0205d81c*);
int IsField0x9cEqual3_0204c7cc(unsigned char*);
void SetFieldAt0x30_0205bc24(void* p, int value);
extern "C" unsigned char func_0205d0e0(void* window, int arg);
extern "C" void func_ov005_02158f80(EquipmentMenu* self);
extern "C" void func_ov005_0215916c(EquipmentMenu* self);
extern "C" void func_ov005_02159208(EquipmentMenu* self);
extern "C" void func_ov005_02159274(EquipmentMenu* self);
extern "C" void func_ov005_02159850(EquipmentMenu* self);
extern "C" void func_ov005_02158ed0(EquipmentMenu* self);

// USA: func_ov005_02158e04
extern "C" ARM void func_ov005_02158e04(EquipmentMenu* self, int arg) {
    MenuElement* elem = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)self->window_);
    if (elem != NULL && IsField0x9cEqual3_0204c7cc((unsigned char*)elem) && !(elem->flags_ & 2))
        SetFieldAt0x30_0205bc24(self->GetWindow() + 4, -1);
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
