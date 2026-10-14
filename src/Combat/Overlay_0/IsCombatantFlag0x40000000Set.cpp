#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215830c
ARM int IsCombatantFlag0x40000000Set_ov000_0215830c(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x40000000) != 0;
}
