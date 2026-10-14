#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02159994
ARM int IsCombatantFlag0x8000Set_ov000_02159994(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x8000) != 0;
}
