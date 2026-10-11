#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
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
    char unk_0[R(0x2d08, 0x2d90)];
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
