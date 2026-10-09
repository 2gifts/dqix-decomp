#include <globaldefs.h>

struct Outer020e28dc;
struct Ctx020e263c;
struct Obj0207fc6c;

struct Menu021745fc {
    char unk_0[0x36];
    short cursor_;
};

class BattleMenu021745fc {
public:
    Outer020e28dc* ctrl_;
    char unk_4[0x88c - 0x4];
    char repeat_[0xc];
    unsigned short repeatButtons_;
    unsigned char unk_89a;
    char unk_89b;
    Menu021745fc* menu_;
    char unk_8a0[0xfe0 - 0x8a0];
    int ticks_;
    int menuEvents_;
    char unk_fe8[0xff8 - 0xfe8];
    short* cursor_;
    short unk_ffc;
    short group_;
    short prevCursor_;
    char unk_1002[0x1036 - 0x1002];
    short pending_;
    char unk_1038[0x103e - 0x1038];
    unsigned char state_;
    char unk_103f[0x1046 - 0x103f];
    unsigned short flags_;
};

typedef void (BattleMenu021745fc::*StateFn021745fc)();

extern "C" {
bool func_ov017_021959b4();
void func_ov003_02174550(BattleMenu021745fc* self);
void func_ov003_021749f0(BattleMenu021745fc* self);
void func_ov003_021760cc(BattleMenu021745fc* self);
void func_02081f20(void* repeat, int ticks);
int func_020800fc(Menu021745fc* menu, short* cursor, short prevCursor, unsigned short buttons, unsigned char, bool);
void func_020813ec(Menu021745fc* menu, short group);
}

void ClearFlag80AtOffset1000_02174988(char* self);
void SetElementFlagIfValid_0217451c(char* self);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
void CallFunc0204c87cOverEntries0207fc6c(Obj0207fc6c* obj, int ticks);
void ClearSublistEntriesFlag4(void* menu, int group);
int GetInnerFlagBit0020e28dc(Outer020e28dc* o);
void UpdateEntryStateAndPosition(Ctx020e263c* ctx, int ticks);

extern unsigned int data_ov003_02180cc8;
extern StateFn021745fc data_020e6d5c;
extern StateFn021745fc data_ov003_02180aa4[10];

// USA: func_ov003_021745fc
extern "C" ARM bool func_ov003_021745fc(BattleMenu021745fc* self, int ticks) {
    self->ticks_ = ticks;
    if (func_ov017_021959b4())
        func_ov003_02174550(self);
    func_ov003_021749f0(self);
    ClearFlag80AtOffset1000_02174988((char*)self);
    SetElementFlagIfValid_0217451c((char*)self);

    if (self->state_ != 0) {
        if (self->pending_ >= 0) {
            func_ov003_021760cc(self);
            return false;
        }
        ((unsigned char*)GetGlobalField0x1c020421a0())[0x19ae] = 0;
        Menu021745fc* menu = self->menu_;
        if (menu != NULL)
            CallFunc0204c87cOverEntries0207fc6c((Obj0207fc6c*)menu, ticks);
        if (self->cursor_ != NULL) {
            func_02081f20(self->repeat_, ticks);
            self->prevCursor_ = *self->cursor_;
            self->menuEvents_ = func_020800fc(menu, self->cursor_, self->prevCursor_, self->repeatButtons_, self->unk_89a, (self->flags_ & 0x400) != 0);
            menu->cursor_ = *self->cursor_;
            if (self->menuEvents_ != 0)
                ClearSublistEntriesFlag4(menu, self->group_);
            if (self->prevCursor_ != *self->cursor_)
                func_020813ec(menu, self->group_);
        }
    }

    if (self->ctrl_ != NULL && GetInnerFlagBit0020e28dc(self->ctrl_))
        UpdateEntryStateAndPosition((Ctx020e263c*)self->ctrl_, self->ticks_);

    if (!(data_ov003_02180cc8 & 1)) {
        data_ov003_02180aa4[9] = data_020e6d5c;
        data_ov003_02180cc8 |= 1;
    }
    if (data_ov003_02180aa4[self->state_] == NULL) {
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());
        return !(self->flags_ & 0x80);
    }
    (self->*data_ov003_02180aa4[self->state_])();
    return false;
}
