#include <globaldefs.h>
#include "GameState/GameState.h"

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
    char unk_c[0x89c - 0xc];
    void* members_;
    char unk_8a0[0x100c - 0x8a0];
    short mode_;
    short slot_;
    short index_;
    char unk_1012[0x101c - 0x1012];
    int memberIds_[5];
    int kind_;
    char unk_1034[0x103a - 0x1034];
    short key_;
    signed char amount_;
};

// USA: func_ov003_02175df4
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
