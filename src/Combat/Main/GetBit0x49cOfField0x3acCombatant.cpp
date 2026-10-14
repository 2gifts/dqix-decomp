#include <globaldefs.h>
#include "GameState/GameState.h"

struct Sub0x150_02068580 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068580
ARM int GetBit0x49cOfField0x3acCombatant_02068580(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetProtagonist();
    if (combatant != 0) {
        struct Sub0x150_02068580* sub = *(struct Sub0x150_02068580**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
