#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov002_02154b94
ARM int HasPositiveField256Short178_02154b94(void* unused, int combatantId) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (!combatant) {
        return 0;
    }
    int v = *(unsigned short*)((char*)combatant + 0x100
#if defined(jpn)
        + 0xa6);
#else
        + 0xb2);
#endif
    if (v != 0) {
        return 1;
    }
    return 0;
}
