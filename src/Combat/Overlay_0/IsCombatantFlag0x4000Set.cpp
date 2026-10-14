#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215997c
ARM int IsCombatantFlag0x4000Set_ov000_0215997c(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x4000) != 0;
}
