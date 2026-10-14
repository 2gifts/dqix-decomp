#include <globaldefs.h>
#include <GameState/GameState.h>

struct StatusTimers { char pad[0x5c]; unsigned char remaining[35]; unsigned char expired[35]; };
struct ExpirationRule { int index; int value; };
struct Combatant_2088660;
int IsFlag0x14Bit0x8Set_ov000_02156038(GameObject*);
int CheckFlag0x14Bit0x10Set_020882f8(unsigned char*);
int IsFlag0x14Bit0x20Set_ov000_021543f4(GameObject*);
int IsFlag0x18Bit0x400Set_ov000_02156404(GameObject*);
int IsFlag0x18Bit0x200Set_ov000_02153a8c(GameObject*);
int IsFlag0x14Bit0x40Set_ov000_02156b20(GameObject*);
int IsCombatantFlag0x100Set_ov000_0215985c(GameObject*);
int IsCombatantFlag0x200Set_ov000_02159874(GameObject*);
int IsFlag0x14Bit0x8000000Set_ov000_0215516c(GameObject*);
int IsCombatantFlag0x10000000Set_ov000_0215988c(GameObject*);
int IsCombatantFlag0x20000000Set_ov000_021598a4(GameObject*);
int IsCombatantFlag0x4000000Set_ov000_021598bc(GameObject*);
int IsCombatantFlag0x400000Set_ov000_021598d4(GameObject*);
int IsFlag0x18Bit0x8Set_ov000_02156c94(GameObject*);
int IsField0x18Flag0x80Set_02088660(Combatant_2088660*);
int IsFlag0x18Bit0x10Set_ov000_02156cac(GameObject*);
int IsCombatantFlag2_0x2Set_ov000_021598ec(GameObject*);
int IsCombatantFlag2_0x4Set_ov000_02159904(GameObject*);
int IsCombatantFlag0x400Set_ov000_0215991c(GameObject*);
int IsCombatantFlag0x800Set_ov000_02159934(GameObject*);
int IsCombatantFlag0x1000Set_ov000_0215994c(GameObject*);
int IsCombatantFlag0x2000Set_ov000_02159964(GameObject*);
int IsCombatantFlag0x4000Set_ov000_0215997c(GameObject*);
int IsCombatantFlag0x8000Set_ov000_02159994(GameObject*);
int IsCombatantModStatsFlag0x10000Set_ov000_021599ac(GameObject*);
int IsCombatantModStatsFlag0x20000Set_ov000_021599c4(GameObject*);
int IsFlag0x18Bit0x1Set_ov000_02156258(GameObject*);
int IsFlag0x14Bit0x2000000Set_ov000_021563ec(GameObject*);
int IsCombatantModStatsFlag0x100Set_ov000_021599dc(GameObject*);
extern int data_ov000_02182a94[3];
extern ExpirationRule data_ov000_02182efc[26];

// USA: func_ov000_021599f4
extern "C" ARM void func_ov000_021599f4(void*, int id) {
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(id);
    if (!combatant) return;
    unsigned char* remaining = ((StatusTimers*)combatant->currentStats_)->remaining;
    unsigned char* expired = ((StatusTimers*)combatant->currentStats_)->expired;
    unsigned char exclusive[3];
    exclusive[0] = IsFlag0x14Bit0x8Set_ov000_02156038(combatant);
    exclusive[1] = CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->currentStats_);
    exclusive[2] = IsFlag0x14Bit0x20Set_ov000_021543f4(combatant);
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
    active[0] = IsFlag0x18Bit0x400Set_ov000_02156404(combatant);
    active[1] = IsFlag0x18Bit0x200Set_ov000_02153a8c(combatant);
    active[2] = IsFlag0x14Bit0x40Set_ov000_02156b20(combatant);
    active[3] = IsCombatantFlag0x100Set_ov000_0215985c(combatant);
    active[4] = IsCombatantFlag0x200Set_ov000_02159874(combatant);
    active[5] = IsFlag0x14Bit0x8000000Set_ov000_0215516c(combatant);
    active[6] = IsCombatantFlag0x10000000Set_ov000_0215988c(combatant);
    active[7] = IsCombatantFlag0x20000000Set_ov000_021598a4(combatant);
    active[8] = IsCombatantFlag0x4000000Set_ov000_021598bc(combatant);
    active[9] = IsCombatantFlag0x400000Set_ov000_021598d4(combatant);
    active[10] = IsFlag0x18Bit0x8Set_ov000_02156c94(combatant);
    active[11] = IsField0x18Flag0x80Set_02088660((Combatant_2088660*)combatant->currentStats_);
    active[12] = IsFlag0x18Bit0x10Set_ov000_02156cac(combatant);
    active[13] = IsCombatantFlag2_0x2Set_ov000_021598ec(combatant);
    active[14] = IsCombatantFlag2_0x4Set_ov000_02159904(combatant);
    active[15] = IsCombatantFlag0x400Set_ov000_0215991c(combatant);
    active[16] = IsCombatantFlag0x800Set_ov000_02159934(combatant);
    active[17] = IsCombatantFlag0x1000Set_ov000_0215994c(combatant);
    active[18] = IsCombatantFlag0x2000Set_ov000_02159964(combatant);
    active[19] = IsCombatantFlag0x4000Set_ov000_0215997c(combatant);
    active[20] = IsCombatantFlag0x8000Set_ov000_02159994(combatant);
    active[21] = IsCombatantModStatsFlag0x10000Set_ov000_021599ac(combatant);
    active[22] = IsCombatantModStatsFlag0x20000Set_ov000_021599c4(combatant);
    active[23] = IsFlag0x18Bit0x1Set_ov000_02156258(combatant);
    active[24] = IsFlag0x14Bit0x2000000Set_ov000_021563ec(combatant);
    active[25] = IsCombatantModStatsFlag0x100Set_ov000_021599dc(combatant);
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
