#if defined(jpn)
#define R(j,u) (j)
#define func_ov005_02155d6c func_ov005_0215735c
#define func_ov005_02159c88 func_ov005_0215b1d4
#define func_ov005_0215a2c8 func_ov005_0215b81c
#define func_ov005_0215a37c func_ov005_0215b8d0
#define func_ov005_0215a3bc func_ov005_0215b910
#define func_ov005_0215a418 func_ov005_0215b96c
#define func_ov005_0215a620 func_ov005_0215bb74
#define func_ov005_0215a720 func_ov005_0215bc6c
#define func_ov005_0215aa44 func_ov005_0215bf64
#define func_ov005_0215ae7c func_ov005_0215c33c
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct Outer020e28dc;
struct Struct020e2794;

struct EquipmentMenu {
    char unk_0[R(0xe60, 0xe64)];
    void* unk_e64;
    int unk_e68;
    char unk_e6c[0xee4 - 0xe6c];
    char window_[R(0x19ac - 0xee0, 0x1a34 - 0xee4)];
    char frame_[0x3db8 - 0x1a34];
    unsigned char state_;
    char unk_3db9[0x3dcc - 0x3db9];
    unsigned int flags_;
    char unk_3dd0[0x3df0 - 0x3dd0];
    signed char blinks_;
    signed char blinkTimer_;
    signed char blinkTimer2_;
    unsigned char fadeStep_;
    char unk_3df4[0x3e04 - 0x3df4];
    signed char unk_3e04;
};

extern "C" void func_ov005_021537bc(void* frame, int a, int color);
extern "C" void func_ov005_0215a37c(EquipmentMenu* self);
extern "C" void func_ov005_0215a720(EquipmentMenu* self);
extern "C" void func_ov005_0215a2c8(EquipmentMenu* self);
extern "C" void func_ov005_0215a3bc(EquipmentMenu* self);
extern "C" void func_ov005_0215aa44(EquipmentMenu* self);
extern "C" void func_ov005_0215acc0(EquipmentMenu* self);
void ClearBuffers0204b010OverList0x98(Cont0205d1e0* window);
void CallFunc0204c8f0OverList0x9c(Cont0205d228* window);
void CallFunc0204b04cOverList0x98(Cont0205d274* window);
extern "C" void func_ov005_02159c88(EquipmentMenu* self);
int GetInnerFlagBit0020e28dc(Outer020e28dc* p);
void UpdateEntryIfActive020e2794(Struct020e2794* p, void* a);
extern "C" void func_ov005_0215a7ec(EquipmentMenu* self);
extern "C" void func_ov005_0215a418(EquipmentMenu* self);
extern "C" void func_ov005_0215b0a0(EquipmentMenu* self);

// USA: func_ov005_02154ef0
extern "C" ARM void func_ov005_02154ef0(EquipmentMenu* self) {
    if (self->state_ == 1)
        return;
    if (self->state_ != 0) {
        if (self->state_ == 3) {
            int ticks = GameState::GetInstance()->GetTickCount();
            if (ticks == 0)
                ticks = 1;
            if (self->blinks_ > 0) {
                self->blinkTimer_ -= ticks;
                if (self->blinkTimer_ <= 0) {
                    if (!(self->flags_ & 0x1000)) {
                        self->flags_ |= 0x1000;
                        self->blinkTimer_ += 30;
                    } else {
                        self->flags_ &= ~0x1000;
                        self->blinkTimer_ += 30;
                        self->blinks_--;
                    }
                }
            }
            self->blinkTimer2_ -= ticks;
            if (self->blinkTimer2_ <= 0) {
                if (!(self->flags_ & 0x2000)) {
                    self->flags_ |= 0x2000;
                    self->blinkTimer2_ += 30;
                } else {
                    self->flags_ &= ~0x2000;
                    self->blinkTimer2_ += 30;
                }
            }
        }
        if (!(self->flags_ & 0x1000))
            func_ov005_021537bc(self->frame_, 0, 0x7fff);
        if (!(self->flags_ & 0x2000))
            func_ov005_0215a37c(self);
        func_ov005_0215a720(self);
        func_ov005_0215a2c8(self);
        func_ov005_0215a3bc(self);
        func_ov005_0215aa44(self);
        func_ov005_0215acc0(self);
        ClearBuffers0204b010OverList0x98((Cont0205d1e0*)self->window_);
        CallFunc0204c8f0OverList0x9c((Cont0205d228*)self->window_);
        CallFunc0204b04cOverList0x98((Cont0205d274*)self->window_);
    }
    func_ov005_02159c88(self);
    if (self->unk_e64 != NULL && GetInnerFlagBit0020e28dc((Outer020e28dc*)self->unk_e64))
        UpdateEntryIfActive020e2794((Struct020e2794*)self->unk_e64, (void*)self->unk_e68);
    func_ov005_0215a7ec(self);
    func_ov005_0215a418(self);
    if (!(self->flags_ & 0x200) && self->unk_3e04 <= 0) {
        func_ov005_0215b0a0(self);
        return;
    }
    self->unk_3e04--;
}
