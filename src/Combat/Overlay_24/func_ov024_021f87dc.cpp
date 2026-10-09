#include <globaldefs.h>
#include "GameState/GameState.h"

struct SkillRecord_021f87dc {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest4 : 20;
    unsigned int cost : 8;
    unsigned int rest8 : 24;
    char padC[0x18 - 0xc];
    unsigned int gap18 : 12;
    unsigned int costType : 4;
    unsigned int rest18 : 16;
};

extern "C" int _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(GameObject* combatant);
unsigned int AdjustValueByFieldFlag(void* obj, unsigned int val);

// USA: func_ov024_021f87dc
extern "C" ARM int func_ov024_021f87dc(GameObject* combatant, SkillRecord_021f87dc* skill, int* cost) {
    *cost = skill->cost;
    if (skill->costType == 2) {
        if (combatant != 0 && _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(combatant)) {
            *cost = 0;
        } else if (skill->id == 0x28) {
            *cost = 0x14;
            if (combatant->currentStats_->primaryStats.currMP > *cost) {
                *cost = combatant->currentStats_->primaryStats.currMP;
            }
        } else {
            *cost = AdjustValueByFieldFlag(combatant, *cost);
        }
    }
    return *cost;
}
