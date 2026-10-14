#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02067fec(int, void*, int);

// USA: func_020689e4
ARM int TestField0x3acCombatantWith02067fec_020689e4(GameState* battleStruct, int arg1, int arg2) {
    GameObject* c = battleStruct->GetProtagonist();
    if (c != 0) {
        return func_02067fec(0, c->baseStats_, arg2) == 0;
    }
    return 0;
}
