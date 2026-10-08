#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[0xee4];
    char window_[0x3dbb - 0xee4];
    signed char slot_;
    char unk_3dbc[0x3ddc - 0x3dbc];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
};

struct Obj0205eaa0;
struct Struct_0205c570;
struct Struct0205cf1c;
struct Entry_0205d6a0;

extern "C" char data_02108760[];
extern "C" unsigned short data_02114e30;

extern "C" void func_ov005_02159904(EquipmentMenu* self);
extern "C" void _Z23SetChannelAFlag0205cef8Pv(void* window);
extern "C" void _Z23SetChannelBFlag0205cf04Pv(void* window);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(Struct_0205c570* window);
extern "C" int _Z25CheckFlag30Or401_02157190v(EquipmentMenu* self);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* window, int unk);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* sound, int effect, int unk);
extern "C" void _Z25ClearChannelAFlag0205cf10Pv(void* window);
extern "C" void _Z21ClearFlagByte0205cf1cP14Struct0205cf1c(Struct0205cf1c* window);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int unk);
int TestFlag0SetAndFlag1Clear(unsigned short* pad, int buttons);

// USA: func_ov005_02158f80
extern "C" ARM void func_ov005_02158f80(EquipmentMenu* self) {
    if (self->menuStep_ == 0) {
        func_ov005_02159904(self);
        _Z23SetChannelAFlag0205cef8Pv(self->window_);
        _Z23SetChannelBFlag0205cf04Pv(self->window_);
        self->menuStep_++;
    } else if (self->menuStep_ == 1) {
        self->menuChoice_ = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((Struct_0205c570*)self->window_);
        if (_Z25CheckFlag30Or401_02157190v(self) | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self->window_, 0x14)) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)data_02108760, 1, 0);
            _Z25ClearChannelAFlag0205cf10Pv(self->window_);
            _Z21ClearFlagByte0205cf1cP14Struct0205cf1c((Struct0205cf1c*)self->window_);
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 0);
            if (self->slot_ >= 0 && self->slot_ < 8) {
                switch (self->menuChoice_) {
                case 0:
                    self->menuState_ = 1;
                    break;
                case 1:
                    self->menuState_ = 3;
                    break;
                case 2:
                    self->menuState_ = 4;
                    break;
                }
            } else {
                switch (self->menuChoice_) {
                case 0:
                    self->menuState_ = 1;
                    break;
                case 1:
                    self->menuState_ = 2;
                    break;
                case 2:
                    self->menuState_ = 3;
                    break;
                case 3:
                    self->menuState_ = 4;
                    break;
                }
            }
            self->menuStep_ = 0;
            return;
        }
        if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 2))
            return;
        _Z25ClearChannelAFlag0205cf10Pv(self->window_);
        _Z21ClearFlagByte0205cf1cP14Struct0205cf1c((Struct0205cf1c*)self->window_);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 0);
        self->menuState_ = 4;
        self->menuStep_ = 0;
    }
}
