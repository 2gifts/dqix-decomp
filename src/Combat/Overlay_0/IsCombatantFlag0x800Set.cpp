#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_02159934
ARM int IsCombatantFlag0x800Set_ov000_02159934(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x800) != 0;
}
