#if defined(jpn)
#define func_ov005_02157b74 func_ov005_0215916c
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct EquipmentSlot {
    short item_;
    char unk_2[0x1c - 2];
};

struct EquipmentMenu {
    char unk_0[LOW_REGION(0x2d08, 0x2d90)];
    EquipmentSlot slots_[24];
    char unk_3030[LOW_REGION(0x3d33 - 0x2fa8, 0x3dbb - 0x3030)];
    signed char slot_;
    char unk_3dbc[LOW_REGION(0x3d54 - 0x3d34, 0x3ddc - 0x3dbc)];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
};

extern "C" void func_ov005_02157b74(EquipmentMenu* self, int item, int keep);

// USA: func_ov005_0215916c
extern "C" ARM void
#if defined(jpn)
func_ov005_0215a688
#else
func_ov005_0215916c
#endif
(EquipmentMenu* self) {
    if (self->menuStep_ == 0) {
        if (self->slot_ >= 0 && self->slot_ < 8)
            func_ov005_02157b74(self, 0xffff, 0);
        else if (self->slot_ >= 8 && self->slot_ < 24)
            func_ov005_02157b74(self, self->slots_[self->slot_].item_, 0);
        self->menuStep_++;
    } else if (self->menuStep_ == 1) {
        self->menuState_ = 4;
        self->menuStep_ = 0;
    }
}
