#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cd48 data_ov005_0215e128
#define func_ov005_02157b74 func_ov005_0215916c
#define func_ov013_02185990 func_ov013_02186b88
#define func_ov013_02186c64 func_ov013_02187f78
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <GameState/GameState.h>

struct Dst02157174;
struct Src02157174;

struct MemberScreen {
    char unk_0[R(0x4f8,0x4fc)];
    int member_;
    char unk_500[R(0x56c - 0x4fc,0x634 - 0x500)];
    unsigned short flags_;
};

struct MenuModel {
    char unk_0[0x1c];
    Vector3fix position_;
    char unk_28[0x80 - 0x28];
    short alpha_;
    short unk_82;
    char unk_84[4];
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct EquipmentMenu {
    char unk_0[R(0x196c,0x19f4)];
    char cursor_[0x2d90 - 0x19f4];
    EquipmentSlot slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
    short dragged_;
    char unk_3d7a[0x3daa - 0x3d7a];
    unsigned char pageStep_;
    char unk_3dab[0x3db8 - 0x3dab];
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
    char unk_3dd0[0x3de0 - 0x3dd0];
    short swapped_;
};

extern unsigned char data_ov005_0215cd48[8];

extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" void _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174(Dst02157174* dst, Src02157174* src);
extern "C" void func_ov005_02157b74(EquipmentMenu* self, int item, int keep);
extern "C" int func_ov005_02155670(EquipmentMenu* self, int x, int y);
void* GetPtrField0x2a04(GameState* gs);
short* GetPointerFromArray0xbd0(unsigned char* obj, unsigned int index);
signed char* GetPointerAt0xbf0(void* obj, unsigned int index);
extern "C" void func_ov005_021555c0(EquipmentMenu* self);
extern "C" void func_ov005_021579ec(EquipmentMenu* self, unsigned int state, unsigned char slot);
extern "C" void func_0205bb04(void* cursor, int index);

// USA: func_ov005_02156ecc
extern "C" ARM void func_ov005_02156ecc(EquipmentMenu* self, int x, int y) {
    if (self->dragged_ < 0)
        return;
    GameState::GetInstance();
    MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    Vector3fix position = self->dragModel_.position_;
    MenuModel* model = self->slots_[self->dragged_].model_;
    position.z = 0;
    _Z23CopyThreeFields02157174P11Dst02157174P11Src02157174((Dst02157174*)model, (Src02157174*)&position);
    model->unk_82 = 0;
    if (self->dragged_ >= 0 && self->dragged_ < 8)
        model->unk_82 = 0x1f;
    if (x < 0x80) {
        if (self->unk_3dc0 == 0)
            func_ov005_02157b74(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x15 && y < 0x2e) {
        if (x > 0x83 && self->unk_3dc0 == 0)
            func_ov005_02157b74(self, self->slots_[self->dragged_].item_, 0);
    } else if (y > 0x30 && self->unk_3dc0 == 1) {
        func_ov005_02157b74(self, 0xffff, 0);
    }
    if (self->unk_3dc0 == 0) {
        int slot = func_ov005_02155670(self, x, y);
        if (slot >= 8 && slot < 24 && self->slot_ != slot) {
            short index = (slot - 8) + self->page_ * 16;
            char* party = (char*)GetPtrField0x2a04(GameState::GetInstance());
            short* items = GetPointerFromArray0xbd0((unsigned char*)party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            signed char* counts = GetPointerAt0xbf0(party + 0x1d4, data_ov005_0215cd48[self->kind_]);
            short swapped = self->swapped_;
            short item = items[swapped];
            signed char count = counts[swapped];
            items[swapped] = items[index];
            counts[self->swapped_] = counts[index];
            items[index] = item;
            counts[index] = count;
            func_ov005_021555c0(self);
            self->flags_ |= 0x40;
            self->pageStep_ = 0;
            self->swapped_ = -1;
            self->slot_ = slot;
        }
    }
    func_ov005_021579ec(self, self->state_, self->slot_);
    func_0205bb04(self->cursor_, self->slot_ - 8);
    screen->flags_ |= 0x1 | 0x80;
    self->flags_ |= 0x4 | 0x8;
}
