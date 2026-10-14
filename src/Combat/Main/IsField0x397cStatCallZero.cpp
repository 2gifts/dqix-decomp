#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02067f9c(int a, void* b, int c);

// USA: func_02068c30
ARM int IsField0x397cStatCallZero_02068c30(GameState* battleStruct, int unused, int arg2) {
    GameObject* combatant = battleStruct->GetUnknownGameObject();
    if (combatant != NULL) {
        return func_02067f9c(0, combatant->baseStats_, arg2) == 0;
    }
    return 0;
}
