#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);

// USA: func_02010038
ARM int CollectCombatantsWithFlag0x1000_02010038(GameState* battleStruct, unsigned char* out) {
    int i;
    int count;
    if (out == NULL) {
        return 0;
    }
    i = 0;
    out[0] = 0;
    count = 1;
    for (; i < 4; i++) {
        if (GetCombatantWithFlag0x1000_0200ff58(battleStruct, i) != NULL) {
            out[count] = i;
            count++;
        }
    }
    return count;
}
