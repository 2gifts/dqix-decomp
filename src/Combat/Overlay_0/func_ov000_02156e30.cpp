#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Combatant02156e30 {
    char pad0[0x150];
    unsigned char* status;
};

struct Battler02156e30 {
    char pad0[0x2cc];
    short hp;
};

struct Action02156e30 {
    char pad0[4];
    unsigned int id : 12;
    unsigned int rest : 20;
    char pad1[0x10 - 8];
    unsigned int flags;
};

Battler02156e30* GetFieldAt0x150(unsigned char* obj);
int TestBit5At0x2f4(unsigned char* obj);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" int func_ov000_02155f9c(struct Random* rand, int combatantId, int checkSubFlag);
extern "C" float func_ov000_02156118(struct Random* rand, int combatantId);

static inline unsigned char* GetStatus(GameObject* c) {
    return ((Combatant02156e30*)c)->status;
}

static inline int IsPartyIndex(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov000_02156e30
extern "C" ARM int func_ov000_02156e30(struct Random* rand, int attackerId, int targetId, Action02156e30* action) {
    GameState* bs = GameState::GetInstance();
    if (!(action->flags & 0x40)) {
        return 0;
    }
    if (func_ov000_02155f9c(rand, targetId, 0) != 0) {
        return 0;
    }
    if (IsPartyIndex(attackerId)) {
        GameObject* attacker = GetCombatantWithFlag0x100(bs, attackerId);
        if (attacker != NULL && (action->flags & 0x80000)) {
            if (TestBit5At0x2f4(GetStatus(attacker))) {
                return 0;
            }
        }
    }
    if (GameState::GetInstance()->GetCombatantByIndex(targetId) == NULL) {
        return 0;
    }
    float chance = func_ov000_02156118(rand, targetId);
    if (IsPartyIndex(targetId) && (action->id == 0xf4 || action->id == 0xf5)) {
        GameObject* target = GetCombatantWithFlag0x100(GameState::GetInstance(), targetId);
        Battler02156e30* battler = GetFieldAt0x150((unsigned char*)target);
        if (target != NULL && battler != NULL && battler->hp > 0) {
            if (TestBitInArray0x8ec(GetStatus(target), 0x28)) {
                chance = 100.0f;
            }
        }
    }
    return NextRandomMax(rand, 100) < chance;
}
