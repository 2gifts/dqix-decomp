#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02067fec(int, void*, int);

// USA: func_020689a4
ARM int TestFlag0x800CombatantWith02067fec_020689a4(GameState* battleStruct, int arg1, int arg2) {
    GameObject* c = battleStruct->GetPartyMemberByIndex(0);
    if (c != 0) {
        return func_02067fec(0, c->baseStats_, arg2) == 0;
    }
    return 0;
}
