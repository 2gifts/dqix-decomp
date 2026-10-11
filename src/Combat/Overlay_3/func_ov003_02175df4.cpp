#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue89C_818 = 0x818 };
enum { kRegionValue100C_F88 = 0xf88 };
enum { kRegionValue8A0_81C = 0x81c };
enum { kRegionValue101C_F98 = 0xf98 };
enum { kRegionValue1012_F8E = 0xf8e };
enum { kRegionValue103A_FB6 = 0xfb6 };
enum { kRegionValue1034_FB0 = 0xfb0 };
#else
enum { kRegionValue89C_818 = 0x89c };
enum { kRegionValue100C_F88 = 0x100c };
enum { kRegionValue8A0_81C = 0x8a0 };
enum { kRegionValue101C_F98 = 0x101c };
enum { kRegionValue1012_F8E = 0x1012 };
enum { kRegionValue103A_FB6 = 0x103a };
enum { kRegionValue1034_FB0 = 0x1034 };
#endif


struct KeyedList0207c484;
struct KeyMap020a0a08;
struct Slots0208386c;

int DecrementKeyedStackAmount0207c484(struct KeyedList0207c484* obj, int value, int amount, int key);
short FindMappedMemberId02080468(void* obj, int id);
struct Slots0208386c* GetFieldAt0x150(unsigned char* obj);
void RemoveSlotShiftDown0208386c(struct Slots0208386c* s, int idx);
int DecrementKeyValue020a0a08(struct KeyMap020a0a08* map, int key, int amount);

struct Owner02175df4 {
    char unk_0[0x8];
    unsigned int category_ : 4;
};

struct Ctx02175df4 {
    char unk_0[0x8];
    Owner02175df4* owner_;
    char unk_c[kRegionValue89C_818 - 0xc];
    void* members_;
    char unk_8a0[kRegionValue100C_F88 - kRegionValue8A0_81C];
    short mode_;
    short slot_;
    short index_;
    char unk_1012[kRegionValue101C_F98 - kRegionValue1012_F8E];
    int memberIds_[5];
    int kind_;
    char unk_1034[kRegionValue103A_FB6 - kRegionValue1034_FB0];
    short key_;
    signed char amount_;
};

// USA: func_ov003_02175df4
// JPN: func_ov003_02174e10
extern "C" ARM int func_ov003_02175df4(Ctx02175df4* self) {
    GameState* bs = GameState::GetInstance();
    char* bag = (char*)GetPtrField0x2a04(bs);
    if (self->mode_ == 0x77) {
        return DecrementKeyedStackAmount0207c484((struct KeyedList0207c484*)(bag + 0x1d4), self->key_, self->amount_, self->owner_->category_);
    }
    int id;
    switch (self->kind_) {
    case 1:
        id = 0x11;
        break;
    case 2:
        id = 0x12;
        break;
    case 3:
        id = 0x13;
        break;
    case 4:
        id = 0x14;
        break;
    }
    short idx = self->index_ - FindMappedMemberId02080468(self->members_, id);
    if (self->kind_ > idx) {
        GameObject* member = bs->GetPartyMemberByIndex(self->memberIds_[idx]);
        if (member == NULL) {
            return 0;
        }
        short slot = self->slot_ - FindMappedMemberId02080468(self->members_, 0x15);
        RemoveSlotShiftDown0208386c(GetFieldAt0x150((unsigned char*)member), (signed char)slot);
        return 1;
    }
    DecrementKeyValue020a0a08((struct KeyMap020a0a08*)bag, self->key_, self->amount_);
    return 1;
}
