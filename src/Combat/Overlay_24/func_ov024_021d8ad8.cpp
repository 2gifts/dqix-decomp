#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

float CalculatePhysicalDamage(int attack, int defense, struct Random* random);

struct DamageCtx_021d8ad8 {
    struct Random* random;

    struct Random* GetRandom() { return random; }
};

static inline unsigned short GetAttack(GameObject* obj) {
    return obj->currentStats_->primaryStats.attack;
}

static inline unsigned short GetDefense(GameObject* obj) {
    return obj->currentStats_->primaryStats.defense;
}

// USA: func_ov024_021d8ad8
extern "C" ARM int func_ov024_021d8ad8(struct DamageCtx_021d8ad8* ctx, int attackerIdx, int defenderIdx, int c, int d, int fallback) {
    GameState* gameState = GameState::GetInstance();
    GameObject* attacker = gameState->GetCombatantByIndex(attackerIdx);
    GameObject* defender = gameState->GetCombatantByIndex(defenderIdx);
    if (attacker == NULL || defender == NULL) {
        return fallback;
    }
    struct Random* random = ctx->GetRandom();
    unsigned short defense = GetDefense(defender);
    unsigned short attack = GetAttack(attacker);
    return (int)CalculatePhysicalDamage((int)(attack * 0.75f), (int)(float)defense, random);
}
