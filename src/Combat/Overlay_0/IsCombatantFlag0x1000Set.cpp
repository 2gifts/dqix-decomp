#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215994c
ARM int IsCombatantFlag0x1000Set_ov000_0215994c(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x1000) != 0;
}
