#include <globaldefs.h>
#include <GameState/GameState.h>

struct StatusTimers { char pad[0x5c]; unsigned char remaining[35]; unsigned char expired[35]; };
struct ExpirationRule { int index; int value; };
struct Combatant_2088660;
int IsFlag0x14Bit0x8Set(GameObject*);
int CheckFlag0x14Bit0x10Set(unsigned char*);
int IsFlag0x14Bit0x20Set(GameObject*);
int IsFlag0x18Bit0x400Set(GameObject*);
int IsFlag0x18Bit0x200Set(GameObject*);
int IsFlag0x14Bit0x40Set(GameObject*);
int IsCombatantFlag0x100Set(GameObject*);
int IsCombatantFlag0x200Set(GameObject*);
int IsFlag0x14Bit0x8000000Set(GameObject*);
int IsCombatantFlag0x10000000Set(GameObject*);
int IsCombatantFlag0x20000000Set(GameObject*);
int IsCombatantFlag0x4000000Set(GameObject*);
int IsCombatantFlag0x400000Set(GameObject*);
int IsFlag0x18Bit0x8Set(GameObject*);
int IsField0x18Flag0x80Set(Combatant_2088660*);
int IsFlag0x18Bit0x10Set(GameObject*);
int IsCombatantFlag2_0x2Set(GameObject*);
int IsCombatantFlag2_0x4Set(GameObject*);
int IsCombatantFlag0x400Set(GameObject*);
int IsCombatantFlag0x800Set(GameObject*);
int IsCombatantFlag0x1000Set(GameObject*);
int IsCombatantFlag0x2000Set(GameObject*);
int IsCombatantFlag0x4000Set(GameObject*);
int IsCombatantFlag0x8000Set(GameObject*);
int IsCombatantModStatsFlag0x10000Set(GameObject*);
int IsCombatantModStatsFlag0x20000Set(GameObject*);
int IsFlag0x18Bit0x1Set(GameObject*);
int IsFlag0x14Bit0x2000000Set(GameObject*);
int IsCombatantModStatsFlag0x100Set(GameObject*);
extern int data_ov000_02182a94[3];
extern ExpirationRule data_ov000_02182efc[26];

// USA: func_ov000_021599f4
extern "C" ARM void func_ov000_021599f4(void*, int id) {
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(id);
    if (!combatant) return;
    unsigned char* remaining = ((StatusTimers*)combatant->currentStats_)->remaining;
    unsigned char* expired = ((StatusTimers*)combatant->currentStats_)->expired;
    unsigned char exclusive[3];
    exclusive[0] = IsFlag0x14Bit0x8Set(combatant);
    exclusive[1] = CheckFlag0x14Bit0x10Set((unsigned char*)combatant->currentStats_);
    exclusive[2] = IsFlag0x14Bit0x20Set(combatant);
    unsigned char* flag = exclusive;
    int* index = data_ov000_02182a94;
    for (int i = 0; i < 3; i++, flag++, index++) {
        if (*flag) {
            if (remaining[*index]) {
                remaining[*index]--;
                if (!remaining[*index]) {
                    remaining[*index] = 0;
                    expired[*index] = 4;
                }
            }
            break;
        }
    }
    unsigned char active[26];
    active[0] = IsFlag0x18Bit0x400Set(combatant);
    active[1] = IsFlag0x18Bit0x200Set(combatant);
    active[2] = IsFlag0x14Bit0x40Set(combatant);
    active[3] = IsCombatantFlag0x100Set(combatant);
    active[4] = IsCombatantFlag0x200Set(combatant);
    active[5] = IsFlag0x14Bit0x8000000Set(combatant);
    active[6] = IsCombatantFlag0x10000000Set(combatant);
    active[7] = IsCombatantFlag0x20000000Set(combatant);
    active[8] = IsCombatantFlag0x4000000Set(combatant);
    active[9] = IsCombatantFlag0x400000Set(combatant);
    active[10] = IsFlag0x18Bit0x8Set(combatant);
    active[11] = IsField0x18Flag0x80Set((Combatant_2088660*)combatant->currentStats_);
    active[12] = IsFlag0x18Bit0x10Set(combatant);
    active[13] = IsCombatantFlag2_0x2Set(combatant);
    active[14] = IsCombatantFlag2_0x4Set(combatant);
    active[15] = IsCombatantFlag0x400Set(combatant);
    active[16] = IsCombatantFlag0x800Set(combatant);
    active[17] = IsCombatantFlag0x1000Set(combatant);
    active[18] = IsCombatantFlag0x2000Set(combatant);
    active[19] = IsCombatantFlag0x4000Set(combatant);
    active[20] = IsCombatantFlag0x8000Set(combatant);
    active[21] = IsCombatantModStatsFlag0x10000Set(combatant);
    active[22] = IsCombatantModStatsFlag0x20000Set(combatant);
    active[23] = IsFlag0x18Bit0x1Set(combatant);
    active[24] = IsFlag0x14Bit0x2000000Set(combatant);
    active[25] = IsCombatantModStatsFlag0x100Set(combatant);
    unsigned char* activeFlag = active;
    ExpirationRule* rule = data_ov000_02182efc;
    for (int i = 0; i < 26; i++, activeFlag++, rule++) {
        if (*activeFlag && remaining[rule->index]) {
            remaining[rule->index]--;
            if (!remaining[rule->index]) {
                remaining[rule->index] = 0;
                expired[rule->index] = rule->value;
            }
        }
    }
}
