#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov000_0215991c
ARM int IsCombatantFlag0x400Set_ov000_0215991c(GameObject* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats_ + 0x14) & 0x400) != 0;
}
