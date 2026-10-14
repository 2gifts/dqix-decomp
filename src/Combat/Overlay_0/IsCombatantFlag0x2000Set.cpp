#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02159964
ARM int IsCombatantFlag0x2000Set_ov000_02159964(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x2000) != 0;
}
