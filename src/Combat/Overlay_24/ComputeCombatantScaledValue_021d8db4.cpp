#include <globaldefs.h>
#include "GameState/GameState.h"

int CheckFlag0x14Bit0x10Set_020882f8(unsigned char* obj);

// USA: func_ov024_021d8db4
ARM int ComputeCombatantScaledValue_021d8db4(int a, int b, int id, int c, int d, int fallback) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetCombatantByIndex(id);
    if (combatant == NULL) {
        return fallback;
    }
    if (CheckFlag0x14Bit0x10Set_020882f8((unsigned char*)combatant->currentStats_) ||
        (*(int*)((char*)combatant->currentStats_ + 0x14) & 0x20) != 0) {
        return (int)(fallback * 2.0f);
    }
    return fallback;
}
