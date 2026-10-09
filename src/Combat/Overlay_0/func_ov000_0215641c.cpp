#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantExtra0215641c {
    char unk_0[0xc];
    unsigned int charmBonus : 10;
};

struct Combatant0215641c {
    char unk_0[0x134];
    BaseCombatStats* baseStats;
    ModifiableCombatStats* currentStats;
    char unk_13c[0x150 - 0x13c];
    CombatantExtra0215641c* extra;

    unsigned short GetCurrentCharm() {
        unsigned short charm = currentStats->primaryStats.charm;
        return charm;
    }
    unsigned short GetBaseCharm() {
        unsigned short charm = baseStats->primaryStats.charm;
        return charm;
    }
};

// USA: func_ov000_0215641c
extern "C" ARM float func_ov000_0215641c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    float result = 0.0f;
    int valid = (id >= 0 && id <= 3);
    if (valid) {
        Combatant0215641c* c = (Combatant0215641c*)GetCombatantWithFlag0x100(gs, id);
        if (c == NULL) {
            return 0.0f;
        }
        int charm = c->GetCurrentCharm() - c->GetBaseCharm();
        charm += (unsigned short)c->extra->charmBonus;
        result = (charm - 100) * 0.02f;
    }
    return result;
}
