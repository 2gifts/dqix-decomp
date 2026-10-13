#include <globaldefs.h>
#include "GameState/GameState.h"

struct Field150Holder02052df8;
int GetHalfwordEntryFromField150(Field150Holder02052df8*, int);
int GetField0x3acValue(GameState*);
extern "C" int _Z32TestCombatantCategoryBit020dd200ii(int, int);
int DispatchByField0x950Byte(int, int);
struct Requirements020dd4c4 {
    unsigned int : 7;
    unsigned int category : 4;
    unsigned int : 18;
    unsigned int protagonistOnly : 1;
    unsigned int rank : 2;
    unsigned int classMask : 12;
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
struct Stats020dd4c4 {
    char pad_0[0x186];
    unsigned char ranks[0x316];
    unsigned char flag : 1;
    unsigned char : 7;
    char pad_49d[0x950 - 0x49d];
    int category;
};
struct Combatant020dd4c4 { char pad_0[0x150]; Stats020dd4c4* stats; };
static inline Combatant020dd4c4* GetCombatant020dd4c4(int id) {
    return (Combatant020dd4c4*)GetCombatantWithFlag0x100(GameState::GetInstance(), id);
}
static inline unsigned short GetRank020dd4c4(Stats020dd4c4* stats) {
    unsigned short value = stats->ranks[stats->category];
    return value;
}

// USA: func_020dd4c4
extern "C" ARM int func_020dd4c4(int id, Entry020dd4c4* entry) {
    if (!entry) return 0x200;
    if (entry->count <= 0) return 0x200;
    Combatant020dd4c4* combatant = GetCombatant020dd4c4(id);
    if (!combatant) return 0x20;
    if (!combatant->stats->category) return 0;
    int valid = entry->kind <= 7;
    if (!valid) return 8;
    if (!entry->requirements) return 8;
    int result = 0;
    GameState* state = GameState::GetInstance();
    result |= (entry->requirements->protagonistOnly && id != GetField0x3acValue(state)) ? 0x100 : 0;
    int categoryError;
    if (entry->kind != 0 && entry->kind != 1) categoryError = 0;
    else if (_Z32TestCombatantCategoryBit020dd200ii(id & 0xff, entry->requirements->category & 0xff)) categoryError = 0;
    else {
        if (DispatchByField0x950Byte(id, entry->requirements->category & 0xff)) categoryError = 0;
        else categoryError = 1;
    }
    result |= categoryError;
    int classError;
    if (entry->kind == 0) classError = 0;
    else if (entry->kind == 1) classError = 0;
    else {
        int category = GetCombatant020dd4c4(id)->stats->category;
        if (category == 0) classError = 2;
        else {
            int mask = 1 << (category - 1);
            classError = (entry->requirements->classMask & mask) ? 0 : 2;
        }
    }
    result |= classError;
    Stats020dd4c4* stats = GetCombatant020dd4c4(id)->stats;
    int rank = GetRank020dd4c4(stats);
    result |= entry->requirements->rank <= (unsigned short)rank ? 0 : 0x10;
    combatant = GetCombatant020dd4c4(id);
    Requirements020dd4c4* requirements = entry->requirements;
    unsigned int flag = combatant->stats->flag;
    int restrictionError;
    if (GetHalfwordEntryFromField150((Field150Holder02052df8*)combatant, 9) == 0x4680 && !requirements->restricted) restrictionError = 0;
    else {
        unsigned int allowed[2] = { requirements->allowFirst, requirements->allowSecond };
        restrictionError = allowed[flag] ? 0 : 0x80;
    }
    result |= restrictionError;
    return result;
}
