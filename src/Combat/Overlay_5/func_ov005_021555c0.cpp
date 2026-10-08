#include <globaldefs.h>
#include <GameState/GameState.h>

void* GetPtrField0x2a04(GameState* gameState);
short* GetPointerFromArray0xbd0(unsigned char* p, unsigned int list);
signed char* GetPointerAt0xbf0(void* p, unsigned int list);

extern "C" unsigned char data_ov005_0215cd60[8];

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
    char unk_3030[0x3dbc - 0x3030];
    unsigned char kind_;
    signed char page_;
};

// USA: func_ov005_021555c0
extern "C" ARM void func_ov005_021555c0(EquipmentMenu* self) {
    char* party = (char*)GetPtrField0x2a04(GameState::GetInstance());
    short* items = GetPointerFromArray0xbd0((unsigned char*)(party + 0x1d4), data_ov005_0215cd60[self->kind_]);
    signed char* counts = GetPointerAt0xbf0(party + 0x1d4, data_ov005_0215cd60[self->kind_]);
    signed char page = self->page_;
    for (int i = 0; i < 16; i++) {
        EquipmentSlot* slot = &self->slots_[i + 8];
        int index = i + page * 16;
        short item = items[index];
        signed char count = counts[index];
        if (item == slot->loadedItem_)
            slot->equipped_ = 1;
        else
            slot->equipped_ = 0;
        slot->item_ = item;
        slot->count_ = count;
    }
}
