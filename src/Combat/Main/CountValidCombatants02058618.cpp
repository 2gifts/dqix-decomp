#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_02058618
ARM int CountValidCombatants02058618(void*) {
    GameState* bs = GameState::GetInstance();
    int count = 0;
    int i;
    for (i = 0; i < 0x10; i++) {
        if (bs->GetGameObjectByIndex(i + 0xd0)) {
            count++;
        }
    }
    return count;
}
