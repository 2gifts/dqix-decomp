#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215fffe data_ov006_02161350
#define data_ov006_02160010 data_ov006_02161364
#define func_ov006_0215f4dc func_ov006_021608fc
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

class GameState {
public:
    static GameState* GetInstance();
};

struct PartyMemberData {
    char unk_0[0x454];
    unsigned short unk_454[8];
};

struct GameObject {
    char unk_0[R(0x144, 0x150)];
    PartyMemberData* partyData_;
};

struct Party {
    char unk_0[0xf78];
    unsigned char members_[4];
    unsigned char count_;
};

struct AlchemyMenu {
    char unk_0[R(0x40, 0x48)];
    short** items_;
    unsigned char** counts_;
    unsigned short* sizes_;
    char unk_54[0x20];
    char ingredients_[R(0xd4, 0xd8)];
    char table_[0xc];
};

Party* GetPtrField0x2a04(GameState* gameState);
void* GetCombatantWithFlag0x100(GameState* gameState, int member);
short GetShortFromArray0xc10(unsigned char* lists, unsigned int list);
short* GetPointerFromArray0xbd0(unsigned char* lists, unsigned int list);
unsigned char* GetPointerAt0xbf0(void* lists, unsigned int list);
extern "C" void func_ov006_02158fd8(AlchemyMenu* self, unsigned int category, short item, unsigned char count);
extern "C" void func_ov006_0215373c(void* ingredients, void* table);
extern "C" void func_ov006_021537c8(void* ingredients, short** items, unsigned char** counts, unsigned short* sizes);

extern "C" const unsigned short data_ov006_0215fffe[9];
extern "C" const int data_ov006_02160010[8];

// USA: func_ov006_02158de0
extern "C" ARM void func_ov006_02158de0(AlchemyMenu* self) {
    unsigned short sizes[9];
    memcpy(sizes, data_ov006_0215fffe, sizeof(sizes));

    for (unsigned char i = 0; i < 9; i++) {
        unsigned short size = sizes[i];
        memset(self->items_[i], -1, size * 2);
        memset(self->counts_[i], 0, size);
        self->sizes_[i] = 0;
    }
    GameState* gameState = GameState::GetInstance();
    Party* party = GetPtrField0x2a04(gameState);
    for (unsigned short j = 0; j < 0x98; j++)
        func_ov006_02158fd8(self, 8, *(short*)((char*)party + 0xc + j * 2), *((char*)party + 0x13c + j));
    for (unsigned char k = 0; k < party->count_; k++) {
        GameObject* member = (GameObject*)GetCombatantWithFlag0x100(gameState, party->members_[k]);
        if (member != 0) {
            unsigned short* items = member->partyData_->unk_454;
            for (unsigned char l = 0; l < 8; l++)
                func_ov006_02158fd8(self, 8, items[l], 1);
        }
    }
    for (unsigned char m = 0; m < 8; m++) {
        int list = data_ov006_02160010[m];
        short count = GetShortFromArray0xc10((unsigned char*)party + 0x1d4, list);
        short* listItems = GetPointerFromArray0xbd0((unsigned char*)party + 0x1d4, list);
        unsigned char* listCounts = GetPointerAt0xbf0((char*)party + 0x1d4, list);
        for (short n = 0; n < count; n++)
            func_ov006_02158fd8(self, m, listItems[n], listCounts[n]);
    }
    func_ov006_0215373c(self->ingredients_, self->table_);
    func_ov006_021537c8(self->ingredients_, self->items_, self->counts_, self->sizes_);
}
