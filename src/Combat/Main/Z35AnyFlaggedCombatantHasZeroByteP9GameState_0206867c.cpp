#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0206867c
extern "C" ARM int _Z35AnyFlaggedCombatantHasZeroByte0x2d0P9GameState(GameState* battleStruct) {
    signed char count = 0;
    int i;
    for (i = 1; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x1000(battleStruct, i);
        if (c != 0) {
            if (GetSignedByte0x2d0(c) == 0) {
                count = count + 1;
            }
        }
    }
    return (signed char)(count + 1) != 1;
}