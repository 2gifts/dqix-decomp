#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct PartySlots { char pad0[0xf78]; signed char ids[4]; unsigned char count; };
struct BattleContext { int field0; void* controller; };
extern BattleContext data_ov017_021d82e0;
void CopyByteField0x253To0x252_02039830(void*);
unsigned char GetByteField0x252_02039820(void*);
unsigned char GetField0x397cValue_020100b0(GameState*);
void TryClearFlags0x130_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
void SetByteField0x253_020397c0(void*);
struct Obj020397cc;
void CancelPendingAction020397cc(Obj020397cc*, int);

// USA: func_ov017_0218d2f0
extern "C" ARM void func_ov017_0218d2f0(unsigned char revive, unsigned char cure, int amount, unsigned char all) {
    GameState* game = GameState::GetInstance();
    PartySlots* party = (PartySlots*)GetPtrField0x2a04_02010828(game);
    int active = 1;
    unsigned char count = party->count;
    GameObject* leader = game->GetUnknownGameObject();
    if (leader) {
        CopyByteField0x253To0x252_02039830(leader);
        active = GetByteField0x252_02039820(leader) != 0;
    }
    for (unsigned char i = 0; i < count; ++i) {
        short index = party->ids[i];
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, index);
        if (!combatant || (!all && index != GetField0x397cValue_020100b0(game))) continue;
        if (revive) {
            if (combatant->combatFields_.savedState_130_->flags & 1) {
                ClearFieldBit02053fe4(combatant, 1, 1);
                TryClearFlags0x130_02048418((unsigned char*)combatant, 1);
            }
        }
        if (cure && !(combatant->combatFields_.savedState_130_->flags & 1)) {
            if (combatant->combatFields_.savedState_130_->flags) combatant->combatFields_.savedState_130_->flags &= 4;
        }
        if (amount && !(combatant->combatFields_.savedState_130_->flags & 1)) {
            int hp = combatant->combatFields_.savedState_130_->hp + amount;
            if (combatant->baseStats_->primaryStats.maxHP < hp) hp = combatant->baseStats_->primaryStats.maxHP;
            combatant->combatFields_.savedState_130_->hp = hp;
            hp = combatant->combatFields_.savedState_130_->mp + amount;
            if (combatant->baseStats_->primaryStats.maxMP < hp) hp = combatant->baseStats_->primaryStats.maxMP;
            combatant->combatFields_.savedState_130_->mp = hp;
        }
        func_ov017_021c9e00(index, 1, 0, 1);
        func_ov017_02191108(data_ov017_021d82e0.controller, 1, 1, 1, 1);
    }
    leader = game->GetUnknownGameObject();
    if (leader) {
        if (active) SetByteField0x253_020397c0(leader);
        else CancelPendingAction020397cc((Obj020397cc*)leader, 1);
    }
}
