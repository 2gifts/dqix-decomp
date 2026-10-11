#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02158560 func_ov005_02159b58
#define func_ov005_021585fc func_ov005_02159bf4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct EquipmentMenu {
    char unk_0[R(0x3d30, 0x3db8)];
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
    char unk_3dd0[0x3df0 - 0x3dd0];
    signed char blinks_;
    signed char blinkTimer_;
    signed char blinkTimer2_;
};

extern "C" void func_ov005_021571d0(EquipmentMenu* self);

// USA: func_ov005_0215792c
extern "C" ARM void func_ov005_0215792c(EquipmentMenu* self, unsigned char state) {
    self->lastState_ = self->state_;
    self->state_ = state;
    self->step_ = 0;
    if (self->state_ == 0) {
        self->unk_3dbe = self->kind_;
        self->flags_ |= 0x400;
    } else {
        self->flags_ &= ~0x400;
    }
    if (self->state_ == 0 && self->lastState_ == 1) {
        self->blinks_ = 3;
        self->blinkTimer_ = 30;
        self->blinkTimer2_ = 30;
        self->flags_ &= ~0x1000;
        self->flags_ &= ~0x2000;
    } else if (self->lastState_ == 3) {
        self->blinks_ = 0;
        self->flags_ &= ~0x1000;
    }
    if (self->state_ != 5 && self->state_ != 1 && self->state_ != 7)
        func_ov005_021571d0(self);
}
