#include <globaldefs.h>
#include "GameState/GameState.h"

struct ComboBattleState {
    unsigned char pad_00[0x8e50];
    short target;
    short skill;
    unsigned char pad_8e54[4];
    int action;
    unsigned char pad_8e5c[0x26];
    signed char side;
    signed char count;
};
struct ComboAction {
    unsigned char pad_00[4];
    int action;
    unsigned char pad_08[8];
    ComboBattleState* battle;
    unsigned char pad_14[4];
    int state;
    unsigned char pad_1c[0x5c];
    unsigned char restricted;
};
struct ComboParameters {
    unsigned int field_00;
    unsigned int skill : 12;
    unsigned int field_04 : 20;
    unsigned char pad_08[8];
    unsigned int flags;
    unsigned char pad_14[8];
    unsigned int field_1c : 14;
    unsigned int restriction : 5;
    unsigned int field_1c_rest : 13;
    unsigned char pad_20[0xc];
    unsigned int field_2c : 27;
    unsigned int combo : 1;
    unsigned int field_2c_rest : 4;
};
struct ComboCombatant : GameObject {
#if defined(jpn)
    unsigned char pad_13c[8];
#else
    unsigned char pad_13c[0x14];
#endif
    unsigned char* traits;
};
int TestBit2At0x2f4(unsigned char*);
void ZeroFieldsAt0xe58And0xe82And0x8e52(void*);
static inline int IsPartyMember(int id) { return id >= 0 && id <= 3; }

// JPN: func_ov024_021ead50
// USA: func_ov024_021ea584
extern "C" ARM void func_ov024_021ea584(ComboAction* action, int actor, int target, ComboParameters* parameters) {
    if (parameters->skill == 0x61 && action->state > 0) return;
    if (parameters->restriction && action->state > 0) return;
    if (action->restricted && action->state > 0) return;
    if (IsPartyMember(actor)) {
        ComboCombatant* combatant = (ComboCombatant*)GetCombatantWithFlag0x100(GameState::GetInstance(), actor);
        if (combatant && (parameters->flags & 0x100000) && TestBit2At0x2f4(combatant->traits) && action->state > 0) return;
    }
    if (parameters->combo) {
        if (IsPartyMember(actor)) {
            if (action->battle->side != 1) action->battle->count = 0;
            else if (action->battle->action != action->action) action->battle->count++;
            action->battle->side = 1;
        } else {
            if (action->battle->side != 2) action->battle->count = 0;
            else if (action->battle->action != action->action) action->battle->count++;
            action->battle->side = 2;
        }
        if (parameters->skill != action->battle->skill) action->battle->count = 0;
        action->battle->skill = parameters->skill;
        if (target != action->battle->target) action->battle->count = 0;
        action->battle->target = target;
        action->battle->action = action->action;
    } else ZeroFieldsAt0xe58And0xe82And0x8e52(action->battle);
}
