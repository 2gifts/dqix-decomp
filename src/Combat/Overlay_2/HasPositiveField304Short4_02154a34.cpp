#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov002_02154a34
ARM int HasPositiveField304Short4_02154a34(void* unused, int combatantId) {
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), combatantId);
    if (!combatant) {
        return 0;
    }
    int* field = *(int**)((char*)combatant + 0x130);
    int v = *(unsigned short*)((char*)field + 0x4);
    int result = 0;
    if (v > 0) {
        result = 1;
    }
    return result;
}
