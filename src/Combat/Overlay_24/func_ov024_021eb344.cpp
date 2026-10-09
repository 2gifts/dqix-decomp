#include <globaldefs.h>
#include "GameState/GameState.h"

struct DamageRatioThreshold_021eb344 {
    float minRatio;
    unsigned char rank;
};

struct DamageRatioRank_021eb344 {
    unsigned char rank;
    char pad[7];
};

extern DamageRatioThreshold_021eb344 data_ov024_021fe970[9];
extern DamageRatioRank_021eb344 data_ov024_021fe974[9];

static inline unsigned short GetMaxHP(GameObject* obj) {
    return obj->currentStats_->primaryStats.maxHP;
}

// USA: func_ov024_021eb344
extern "C" ARM int func_ov024_021eb344(void* self, int id, int damage) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    if (combatant == 0) return 0;
    if (damage <= 0) return 0;
    unsigned short maxHP = GetMaxHP(combatant);
    float ratio = (float)damage / (float)maxHP;
    for (int i = 0; i < 9; i++) {
        if (ratio >= data_ov024_021fe970[i].minRatio) return data_ov024_021fe974[i].rank;
    }
    return 0;
}
