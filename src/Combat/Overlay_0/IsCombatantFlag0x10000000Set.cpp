#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215988c
ARM int IsCombatantFlag0x10000000Set_ov000_0215988c(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x10000000) != 0;
}
