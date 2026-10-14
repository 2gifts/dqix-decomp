#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_02163c0c
#pragma optimize_for_size off
ARM int IsCombatantStateSpecial02163c0c(void* unused, int id) {
    GameState* battle = GameState::GetInstance();
    int valid = (id >= 0xc0 && id <= 0xc7);
    GameObject* c;
    int x;
    short state;
    if (!valid) goto fail;
    c = GetCombatantWithFlag0x400_0200fea4(battle, id);
    if (!c) goto fail;
    x = 0x1fd;
    state = *(short*)((char*)c + 2);
    if (state == x || state == x + 1 || (unsigned int)(state - 0x308) <= 3) return 1;
fail:
    return 0;
}
