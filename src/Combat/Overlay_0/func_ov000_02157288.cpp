#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* stats);
float SelectOneOrHalf_02074968(int x);
int IsFlag0x14Bit0x20Set_ov000_021543f4(GameObject* combatant);
float SelectHalfOrQuarter_02074978(int x);
void ClearBattleFlag0x14Bit4_02088390(void* obj);
void ClearFlag0x20AndBytes_020883fc(void* obj);

struct Action_02157288 {
    char pad0[0x10];
    unsigned int flags;
};

struct CombatStats_02157288 {
    char pad0[0x3b];
    unsigned char flag3b_0 : 1;
};

static inline bool IsPartyIndex(int idx) {
    return (idx >= 0 && idx <= 3) ? 1 : 0;
}

// USA: func_ov000_02157288
extern "C" ARM int func_ov000_02157288(struct Random* rng, int combatantId, struct Action_02157288* action) {
    float rate;
    signed char isParty;
    int roll;
    int result;
    GameObject* c;

    if (!(action->flags & 0x800)) {
        return 0;
    }

    rate = 0;
    c = GameState::GetInstance()->GetCombatantByIndex(combatantId);
    if (c == NULL) {
        return 0;
    }

    isParty = IsPartyIndex(combatantId);
    if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)c->currentStats_)) {
        rate = SelectOneOrHalf_02074968(isParty);
    } else if (IsFlag0x14Bit0x20Set_ov000_021543f4(c)) {
        rate = SelectHalfOrQuarter_02074978(isParty);
    }

    rate *= 100.0f;
    roll = NextRandomMax(rng, 100);
    if (roll < (int)rate) {
        result = 0x40;
        if (IsFlag0x14Bit0x20Set_ov000_021543f4(c)) {
            result = 0x173;
        }
        ClearBattleFlag0x14Bit4_02088390(c->currentStats_);
        ClearFlag0x20AndBytes_020883fc(c->currentStats_);
        ((struct CombatStats_02157288*)c->currentStats_)->flag3b_0 = 1;
        return result;
    }
    return 0;
}
