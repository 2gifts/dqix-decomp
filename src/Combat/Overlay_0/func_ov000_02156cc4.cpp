#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Combatant02156cc4 {
    char pad0[0x150];
    unsigned char* status;
};

struct Battler02156cc4 {
    char pad0[4];
    unsigned int deftness : 10;
    unsigned int rest : 22;
};

struct Param2085ab8 {
    char pad0[8];
    unsigned int lo8 : 29;
    unsigned int alwaysCrit : 1;
    unsigned int hi8 : 2;
    char pad1[0x14 - 0xc];
    unsigned int lo14 : 21;
    unsigned int critChance : 7;
    unsigned int hi14 : 4;
};

unsigned char* GetFieldAt0x150(unsigned char* obj);
int TestBitInArray0x8ec(unsigned char* obj, int index);
extern "C" float _Z32AccumulateMagicalMending02084e78Pv(void* param0);
extern "C" int _Z34AccumulateCategorySlotBits02085ab8PhP12Param2085ab8(unsigned char* actor, Param2085ab8* action);
float CalculateCritRate(int deftness, float accessoryBonus, float bookBonus, float skillBonus, unsigned char hitCount);
extern "C" float _Z28ComputeWeightedRatio020748f8fj(float a, unsigned int b);
extern "C" float func_ov000_02155a04(GameObject* obj);

static inline unsigned char* GetStatus(GameObject* c) {
    return ((Combatant02156cc4*)c)->status;
}

static inline int IsPartyIndex(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov000_02156cc4
extern "C" ARM int func_ov000_02156cc4(struct Random* rand, int attackerId, Param2085ab8* action, int hitCount) {
    if (action->alwaysCrit) {
        return 1;
    }
    GameState* bs = GameState::GetInstance();
    float rate;
    if (IsPartyIndex(attackerId)) {
        GameObject* attacker = GetCombatantWithFlag0x100(bs, attackerId);
        unsigned char* battler = GetFieldAt0x150((unsigned char*)attacker);
        int deftness = ((Battler02156cc4*)battler)->deftness;
        float mending = _Z32AccumulateMagicalMending02084e78Pv(battler);
        float bonus = _Z34AccumulateCategorySlotBits02085ab8PhP12Param2085ab8(battler, action);
        rate = CalculateCritRate(deftness, mending, bonus, action->critChance / 100.0f, (unsigned char)hitCount);
        if (TestBitInArray0x8ec(GetStatus(attacker), 0x11d)) {
            if (func_ov000_02155a04(attacker) < 0.25f) {
                rate *= 2.0f;
            }
        }
    } else {
        rate = _Z28ComputeWeightedRatio020748f8fj(action->critChance / 100.0f, (unsigned char)hitCount);
    }
    rate = 100.0f * rate;
    return NextRandomMax(rand, 10000) < (int)rate;
}
