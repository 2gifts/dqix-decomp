#include <globaldefs.h>
#include "GameState/GameState.h"

struct Sub0x150_020685cc {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_020685cc
ARM int GetBit0x49cOfField0x397cCombatant_020685cc(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetUnknownGameObject();
    if (combatant != 0) {
        struct Sub0x150_020685cc* sub = *(struct Sub0x150_020685cc**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
