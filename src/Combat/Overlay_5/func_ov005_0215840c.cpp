#include <globaldefs.h>

struct PartModelInfo {
    unsigned int unk_0;
    unsigned int unk_4_0 : 27;
    unsigned int unk_4_27 : 1;
    unsigned int unk_4_28 : 1;
    unsigned int unk_4_29 : 3;
};

struct PartEntry {
    PartModelInfo* model_;
    int unk_4;
    unsigned int category_ : 4;
    unsigned int unk_8_4 : 28;
};

struct PartyMemberData {
    char unk_0[0x49c];
    unsigned char female_ : 1;
    unsigned char unk_49c_1 : 7;
};

struct Field150Holder02052df8 {
    char unk_0[0x150];
    PartyMemberData* data_;
};

struct Container020dedd0;

struct EquipmentMenu {
    char unk_0[0xdf4];
    Container020dedd0* items_;
};

class GameState {
public:
    static GameState* GetInstance();
};

extern "C" const unsigned char data_ov005_0215cc0c[];

Field150Holder02052df8* GetCombatantWithFlag0x100(GameState* gs, int idx);
short GetHalfwordEntryFromField150(Field150Holder02052df8* member, int part);
extern "C" PartEntry* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* items, int id);
PartyMemberData* GetFieldAt0x150(unsigned char* member);
char* GetPtrField0x2a04(GameState* gs);
extern "C" void func_02052d7c(Field150Holder02052df8* member, int part, short item);
extern "C" void func_0208358c(PartyMemberData* data, PartEntry* item, int unk);
extern "C" void func_02083738(PartyMemberData* data, int category);
extern "C" void func_0207c378(void* lists, short item, int count, int list);

// USA: func_ov005_0215840c
extern "C" ARM int func_ov005_0215840c(EquipmentMenu* self, int member) {
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052df8* partyMember = GetCombatantWithFlag0x100(gameState, member);
    if (partyMember == NULL)
        return 0;
    int removed = 0;
    unsigned int female = partyMember->data_->female_;
    for (int i = 0; i < 7; i++) {
        unsigned char part = data_ov005_0215cc0c[i];
        short current = GetHalfwordEntryFromField150(partyMember, part);
        PartEntry* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, current);
        if (entry == NULL)
            continue;
        unsigned int wearable[2];
        wearable[0] = entry->model_->unk_4_27;
        wearable[1] = entry->model_->unk_4_28;
        if (wearable[female] != 0)
            continue;
        short replacement = -1;
        int unk = -1;
        if (part == 0) {
            unk = 0;
            replacement = 1000;
        }
        func_02052d7c(partyMember, part, -1);
        PartyMemberData* data = GetFieldAt0x150((unsigned char*)partyMember);
        PartEntry* replacementEntry = _Z24FindElementByKey020dedd0P17Container020dedd0i(self->items_, replacement);
        if (replacementEntry != NULL)
            func_0208358c(data, replacementEntry, unk);
        else
            func_02083738(data, entry->category_);
        func_0207c378(GetPtrField0x2a04(gameState) + 0x1d4, current, 1, entry->category_);
        removed = 1;
    }
    return removed;
}
