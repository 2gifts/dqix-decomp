#include "Combat/TryApplyElemFields.h"
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_02158878 func_ov005_02159e70
#endif
#include <std_library_functions.h>

struct StructA0205d5d0;
struct Struct_0205d81c;
struct Entry_0205d6a0;
struct MenuElement;
struct Obj0205eaa0;

struct MenuWindow {
    int unk_0;
    char list_[0x38 - 4];
    char unk_38[0xb0 - 0x38];
    unsigned char style_;
};

struct EquipmentMenu {
    char unk_0[0xe10];
    unsigned short* text_;
    char unk_e14[LOW_REGION(0xee0, 0xee4) - 0xe14];
    MenuWindow window_;
    char unk_f98[LOW_REGION(0x3d44, 0x3dcc) - LOW_REGION(0xf94, 0xf98)];
    unsigned int flags_;
    unsigned char step_;
    unsigned char kind_;
    unsigned char pending_;
    char unk_3dd3[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d4b, 0x3dd3)];
};

extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30;
extern "C" unsigned char data_02114e54[];

extern "C" void func_0205d0e0(void* window);
extern "C" void func_ov005_021589f4(EquipmentMenu* self);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
extern "C" MenuElement* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* s, int key);
extern "C" int _Z17IsField0x9cEqual3Ph(MenuElement* elem);
int CheckFlag30Or401_02157190(void* self);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(unsigned short* obj, int mask);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int unk);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int unk);
// USA: func_ov005_02158878
extern "C" ARM void func_ov005_02158878(EquipmentMenu* self) {
    func_0205d0e0(&self->window_);
    if (self->step_ == 0) {
        func_ov005_021589f4(self);
        self->step_++;
        return;
    }
    if (self->step_ == 1) {
        if (_Z17IsField0x9cEqual3Ph(_Z23FindElementByC40205d81cP15Struct_0205d81ci((Struct_0205d81c*)&self->window_, 0))) {
            if (self->kind_ == 0xc || self->kind_ == 0xd)
                self->flags_ |= 0x10000;
        }
        self->step_++;
        return;
    }
    if (self->step_ != 2)
        return;
    int clear;
    unsigned char touch;
    touch = data_02114e54[0x55];
    clear = 0;
    int flag = CheckFlag30Or401_02157190(self);
    if (flag | touch) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, clear);
        if (self->pending_ != 0) {
            self->kind_ = self->pending_;
            self->pending_ = 0;
            memset(self->text_, clear, LOW_REGION(0x800, 0x960));
            func_ov005_02158b3c(self, self->text_);
#if defined(jpn)
            TryApplyElemFields0205d5d0((StructA0205d5d0*)&self->window_, clear, (int)self->text_, 1);
#else
            TryApplyElemFields0205d5d0((StructA0205d5d0*)&self->window_, clear, (int)self->text_, 1, clear);
#endif
            return;
        }
        clear = 1;
    } else if (_Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 2)) {
        clear = 1;
    }
    if (clear) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)&self->window_, 0);
        self->step_ = 0;
        self->kind_ = 0;
    }
}
