#include <globaldefs.h>
#include "GameState/GameState.h"

struct Foo02057930;
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
void InitStruct02057930(Foo02057930* p);

// USA: func_02057978
ARM void ClearCombatantsAndInitStruct02057978(Foo02057930* p) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 16; i++) {
        ClearCombatantSlot_0200fd48(bs, i + 0xd0);
    }
    InitStruct02057930(p);
}
