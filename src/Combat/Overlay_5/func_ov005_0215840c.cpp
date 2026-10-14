#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

struct PartModelInfo {
    unsigned int unk_0;
    unsigned int unk_4_0 : 27;
    unsigned int maleCompatible : 1;
    unsigned int femaleCompatible : 1;
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
    char unk_0[LOW_REGION(0x144, 0x150)];
    PartyMemberData* data_;
};

struct Container020dedd0;

struct EquipmentMenu {
    char unk_0[0xdf4];
    Container020dedd0* items_;
};

extern "C" const unsigned char data_ov005_0215cc0c[];

int GetHalfwordEntryFromField150(Field150Holder02052df8* member, int part);
PartEntry* FindElementByKey020dedd0(Container020dedd0* items, int id);
PartyMemberData* GetFieldAt0x150_02053c6c(unsigned char* member);
extern "C" void func_02052d7c(Field150Holder02052df8* member, int part, short item);
extern "C" void func_0208358c(PartyMemberData* data, PartEntry* item, int unk);
extern "C" void func_02083738(PartyMemberData* data, int category);
extern "C" int func_0207c378(void* lists, int item, int count, int list);

// USA: func_ov005_0215840c
extern "C" ARM int func_ov005_0215840c(EquipmentMenu* self, int member) {
    GameState* gameState = GameState::GetInstance();
    Field150Holder02052df8* partyMember = (Field150Holder02052df8*)GetCombatantWithFlag0x100_0200ff1c(gameState, member);
    if (partyMember == NULL)
        return 0;
    int removed = 0;
    unsigned int female = partyMember->data_->female_;
    for (int i = 0; i < 7; i++) {
        unsigned char part = data_ov005_0215cc0c[i];
        int current = GetHalfwordEntryFromField150(partyMember, part);
        PartEntry* entry = FindElementByKey020dedd0(self->items_, current);
        if (entry == NULL)
            continue;
        unsigned int wearable[2];
        wearable[0] = entry->model_->maleCompatible;
        wearable[1] = entry->model_->femaleCompatible;
        if (wearable[female] != 0)
            continue;
        short replacement = -1;
        int unk = -1;
        if (part == 0) {
            unk = 0;
            replacement = 1000;
        }
        func_02052d7c(partyMember, part, -1);
        PartyMemberData* data = GetFieldAt0x150_02053c6c((unsigned char*)partyMember);
        PartEntry* replacementEntry = FindElementByKey020dedd0(self->items_, replacement);
        if (replacementEntry != NULL)
            func_0208358c(data, replacementEntry, unk);
        else
            func_02083738(data, entry->category_);
        func_0207c378((char*)GetPtrField0x2a04_02010828(gameState) + 0x1d4, current, 1, entry->category_);
        removed = 1;
    }
    return removed;
}
