#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02159904
ARM int IsCombatantFlag2_0x4Set_ov000_02159904(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x18) & 0x4) != 0;
}
