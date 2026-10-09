#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include <GameState/GameState.h>

struct Obj0205eaa0;
struct Foo02048004;

struct TouchState {
    char unk_0[0x24];
    unsigned short unk_24;
    char unk_26[0x54 - 0x26];
    unsigned char unk_54;
    unsigned char touching_;
    char unk_56[0x5f - 0x56];
    unsigned char unk_5f;
};

struct MemberScreen {
    char unk_0[0x4fc];
    int member_;
    char unk_500[0x634 - 0x500];
    unsigned short flags_;
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    void* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    char unk_0[0x2d90];
    EquipmentSlot slots_[24];
    char slotModels_[0x3cf0 - 0x3030];
    char dragModel_[0x88];
    short dragged_;
    char unk_3d7a[0x3db8 - 0x3d7a];
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
    char unk_3dd0[0x3e05 - 0x3dd0];
    signed char touchTime_;
    signed char tapTimer_;
    signed char tappedSlot_;
    short touchX_;
    short touchY_;
};

extern TouchState data_02114e54;
extern int data_02108760;

void SelectCoordsByFlag0x24(unsigned char* state, int* x, int* y);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov005_0215792c(EquipmentMenu* self, unsigned char state);
extern "C" void func_ov005_02156658(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_021567ac(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_0215690c(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
void MaybeInvoke0204719c(Foo02048004* model);
extern "C" void func_ov005_02156e1c(EquipmentMenu* self, int x, int y);
extern "C" void func_ov005_02156ecc(EquipmentMenu* self, int x, int y);

// USA: func_ov005_021562b8
extern "C" ARM void func_ov005_021562b8(EquipmentMenu* self) {
    int x;
    int y;
    SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
    int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    if (data_02114e54.touching_) {
        if (x == 0 || y == 0)
            return;
        MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
        if (!(self->flags_ & 0x400) && (screen->flags_ & 0x800)) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x1b, 0);
            func_ov005_0215792c(self, 1);
            return;
        }
        func_ov005_02156658(self, x, y);
        if (!(self->flags_ & 0x400) && x >= 0x80 && y >= 0xb0) {
            func_ov005_0215792c(self, 7);
            self->flags_ |= 0x80000;
            return;
        }
        if (self->unk_3dc0 != -1)
            return;
        func_ov005_021567ac(self, x, y);
        func_ov005_0215690c(self, x, y);
        if (x > 0x83 && y > 0x15 && y < 0x2e) {
            func_ov005_0215792c(self, 3);
            self->slot_ = self->kind_;
            func_ov005_021579ec(self, self->state_, 0);
        }
        if (self->dragged_ < 0)
            return;
        if (self->tappedSlot_ == self->dragged_) {
            if (self->tapTimer_ > 0) {
                if (self->slots_[self->slot_].item_ >= 0) {
                    func_ov005_0215792c(self, 5);
                    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
                    screen->flags_ &= ~1;
                    screen->flags_ &= ~0x80;
                }
                MaybeInvoke0204719c((Foo02048004*)self->dragModel_);
                self->dragged_ = -1;
                self->unk_3dc0 = -1;
                self->touchTime_ = 0;
                self->tappedSlot_ = -2;
                self->tapTimer_ = 0;
                return;
            }
            self->tappedSlot_ = -2;
            self->tapTimer_ = 0;
        }
        self->touchTime_ = 0;
        self->touchX_ = x;
        self->touchY_ = y;
    } else if (data_02114e54.unk_5f != 0 && data_02114e54.unk_24 != 0) {
        func_ov005_02156e1c(self, x, y);
        if (self->dragged_ >= 0)
            self->touchTime_ += ticks;
    } else if (data_02114e54.unk_54 != 0) {
        if (self->dragged_ >= 0) {
            int dx = self->touchX_ - (short)x;
            int dy = self->touchY_ - (short)y;
            int moved = 0;
            if (dx * dx + dy * dy >= 25)
                moved = 1;
            if (self->touchTime_ <= 20 && moved == 0) {
                self->tapTimer_ = 20;
                self->tappedSlot_ = self->dragged_;
            } else {
                self->touchTime_ = 0;
                self->tappedSlot_ = -2;
                self->tapTimer_ = 0;
            }
            self->touchX_ = -1;
            self->touchY_ = -1;
        }
        func_ov005_02156ecc(self, x, y);
        MaybeInvoke0204719c((Foo02048004*)self->dragModel_);
        self->dragged_ = -1;
        self->unk_3dc0 = -1;
    }
}
