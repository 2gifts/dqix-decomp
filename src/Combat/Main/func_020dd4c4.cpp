#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field150Holder02052df8;
int GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
int GetField0x3acValue_020100a8(GameState*);
int TestCombatantCategoryBit020dd200(int, int);
int DispatchByField0x950Byte_020dd154(int, int);
struct Requirements020dd4c4 {
    unsigned int : 7;
    unsigned int category : 4;
    unsigned int : 18;
    unsigned int protagonistOnly : 1;
    unsigned int minimumRevocations : 2;
    unsigned int vocationMask : 12;
    unsigned int : 15;
    unsigned int allowFirst : 1;
    unsigned int allowSecond : 1;
    unsigned int restricted : 1;
    unsigned int : 2;
};
struct Entry020dd4c4 {
    Requirements020dd4c4* requirements;
    int field_4;
    unsigned int kind : 4;
    unsigned int : 28;
    char pad_c[0xc];
    short count;
};
struct PartyRecord020dd4c4 {
    char pad_0[0x186];
    unsigned char revocations[13];
    char pad_193[0x49c - 0x193];
    unsigned char flag : 1;
    unsigned char : 7;
#if defined(jpn)
    char pad_49d[0x8b8 - 0x49d];
#else
    char pad_49d[0x950 - 0x49d];
#endif
    int vocation;
    unsigned short GetRevocationCount(int vocation) const {
        return revocations[vocation];
    }
};
struct Combatant020dd4c4 {
#if defined(jpn)
    char pad_0[0x144];
#else
    char pad_0[0x150];
#endif
    PartyRecord020dd4c4* record;
};
static inline Combatant020dd4c4* GetCombatant020dd4c4(int id) {
    return (Combatant020dd4c4*)GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), id);
}

// USA: func_020dd4c4
extern "C" ARM int func_020dd4c4(int id, Entry020dd4c4* entry) {
    if (!entry) return 0x200;
    if (entry->count <= 0) return 0x200;
    Combatant020dd4c4* combatant = GetCombatant020dd4c4(id);
    if (!combatant) return 0x20;
    if (!combatant->record->vocation) return 0;
    int valid = entry->kind <= 7;
    if (!valid) return 8;
    if (!entry->requirements) return 8;
    int result = 0;
    GameState* state = GameState::GetInstance();
    result |= (entry->requirements->protagonistOnly && id != GetField0x3acValue_020100a8(state)) ? 0x100 : 0;
    int categoryError;
    if (entry->kind != 0 && entry->kind != 1) categoryError = 0;
    else if (TestCombatantCategoryBit020dd200(id & 0xff, entry->requirements->category & 0xff)) categoryError = 0;
    else {
        if (DispatchByField0x950Byte_020dd154(id, entry->requirements->category & 0xff)) categoryError = 0;
        else categoryError = 1;
    }
    result |= categoryError;
    int classError;
    if (entry->kind == 0) classError = 0;
    else if (entry->kind == 1) classError = 0;
    else {
        int vocation = GetCombatant020dd4c4(id)->record->vocation;
        if (vocation == 0) classError = 2;
        else {
            int mask = 1 << (vocation - 1);
            classError = (entry->requirements->vocationMask & mask) ? 0 : 2;
        }
    }
    result |= classError;
    PartyRecord020dd4c4* record = GetCombatant020dd4c4(id)->record;
    int revocations = record->GetRevocationCount(record->vocation);
    result |= entry->requirements->minimumRevocations <= (unsigned short)revocations ? 0 : 0x10;
    combatant = GetCombatant020dd4c4(id);
    Requirements020dd4c4* requirements = entry->requirements;
    unsigned int flag = combatant->record->flag;
    int restrictionError;
    if (GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, 9) == 0x4680 && !requirements->restricted) restrictionError = 0;
    else {
        unsigned int allowed[2] = { requirements->allowFirst, requirements->allowSecond };
        restrictionError = allowed[flag] ? 0 : 0x80;
    }
    result |= restrictionError;
    return result;
}
