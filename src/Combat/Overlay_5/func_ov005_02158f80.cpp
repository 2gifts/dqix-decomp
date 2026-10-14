#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[LOW_REGION(0xee0, 0xee4)];
    char window_[LOW_REGION(0x3d33, 0x3dbb) - LOW_REGION(0xee0, 0xee4)];
    signed char slot_;
    char unk_3dbc[LOW_REGION(0x3d54, 0x3ddc) - LOW_REGION(0x3d34, 0x3dbc)];
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
void SetChannelAFlag0205cef8(void* window);
void SetChannelBFlag0205cf04(void* window);
int GetActiveScaledSum0205d794(Struct_0205c570* window);
int CheckFlag30Or401_02157190(void* self);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int unk);
void ClearChannelAFlag0205cf10(void* window);
void ClearFlagByte0205cf1c(Struct0205cf1c* window);
void ResetEntryList0205d6a0(Entry_0205d6a0* window, int unk);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* pad, int buttons);

// USA: func_ov005_02158f80
extern "C" ARM void func_ov005_02158f80(EquipmentMenu* self) {
    if (self->menuStep_ == 0) {
        func_ov005_02159904(self);
        SetChannelAFlag0205cef8(self->window_);
        SetChannelBFlag0205cf04(self->window_);
        self->menuStep_++;
    } else if (self->menuStep_ == 1) {
        self->menuChoice_ = GetActiveScaledSum0205d794((Struct_0205c570*)self->window_);
        if (CheckFlag30Or401_02157190(self) | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)self->window_, 0x14)) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            ClearChannelAFlag0205cf10(self->window_);
            ClearFlagByte0205cf1c((Struct0205cf1c*)self->window_);
            ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 0);
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
        if (!TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2))
            return;
        ClearChannelAFlag0205cf10(self->window_);
        ClearFlagByte0205cf1c((Struct0205cf1c*)self->window_);
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->window_, 0);
        self->menuState_ = 4;
        self->menuStep_ = 0;
    }
}
