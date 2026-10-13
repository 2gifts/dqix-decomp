#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" void func_02048690(GameObject* combatant);

// USA: func_ov000_02160fe4
ARM void ProcessFlaggedombatants02160fe4_02160fe4(void*) {
    GameState* battle = GameState::GetInstance();
    int i;
    for (i = 0; i < 8; i++) {
        GameObject* c = GetCombatantWithFlag0x400(battle, i + 0xc0);
        if (c != 0) func_02048690(c);
    }
}
