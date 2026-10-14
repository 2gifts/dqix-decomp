#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_0215ec1c  (semantic: FindActiveCombatantsInRangeC0_0215ec1c)
extern "C" ARM int func_ov000_0215ec1c(void* unused, short* out, int max) {
    int found = 0;
    int i;
    for (i = 0; i < 8; i++) {
        short id = (short)(i + 0xc0);
        GameState* bs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, id);
        if (c != NULL) {
            out[found++] = id;
            if (found == max) return found;
        }
    }
    return found;
}
