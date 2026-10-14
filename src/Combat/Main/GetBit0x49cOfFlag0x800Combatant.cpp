#include <globaldefs.h>
#include "GameState/GameState.h"

struct Sub0x150_02068558 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068558
ARM int GetBit0x49cOfFlag0x800Combatant_02068558(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(0);
    if (combatant != 0) {
        struct Sub0x150_02068558* sub = *(struct Sub0x150_02068558**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
