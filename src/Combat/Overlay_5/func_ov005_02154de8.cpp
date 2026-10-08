#include <globaldefs.h>
#include <GameState/GameState.h>

struct EquipmentMenu {
    char unk_0[0x1244];
    char infoWindow_[0x1a34 - 0x1244];
    char frame_[0x3db8 - 0x1a34];
    unsigned char state_;
    char unk_3db9[0x3dd1 - 0x3db9];
    unsigned char unk_3dd1;
    char unk_3dd2[0x3de4 - 0x3dd2];
    int ticks_;
    char unk_3de8[0x3e06 - 0x3de8];
    signed char tapTimer_;
    signed char tappedSlot_;
};

typedef void (EquipmentMenu::*EquipmentState)();

extern "C" EquipmentState data_ov005_0215cd74[8];

extern "C" void func_ov005_02153728(void* frame, int a);
extern "C" void func_ov023_021dc488(void* window);
extern "C" int func_ov005_0215cb4c(EquipmentMenu* self);
extern "C" void func_ov005_021556e4(EquipmentMenu* self);
extern "C" void func_ov005_02158878(EquipmentMenu* self, int ticks);

// USA: func_ov005_02154de8
extern "C" ARM void func_ov005_02154de8(EquipmentMenu* self) {
    int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    self->ticks_ = ticks;
    func_ov005_02153728(self->frame_, 1);
    func_ov023_021dc488(self->infoWindow_);
    if (func_ov005_0215cb4c(self)) {
        func_ov005_021556e4(self);
        return;
    }
    if (self->unk_3dd1 != 0 && self->unk_3dd1 != 8 && self->unk_3dd1 != 9) {
        func_ov005_02158878(self, ticks);
        func_ov005_021556e4(self);
        return;
    }
    if (self->tapTimer_ > 0) {
        self->tapTimer_ -= ticks;
        if (self->tapTimer_ <= 0) {
            self->tapTimer_ = 0;
            self->tappedSlot_ = -2;
        }
    }
    if (data_ov005_0215cd74[self->state_] == NULL)
        return;
    (self->*data_ov005_0215cd74[self->state_])();
    func_ov005_021556e4(self);
}
