#include <globaldefs.h>

#include "GameState/GameState.h"

struct SearchStruct;

extern "C" void* func_0202ae18(void);

int TestBitBySignedByteIndex_0202c1c0(struct SearchStruct* obj, int value);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);
void SetField0x17eBitAndHigh_02079710(unsigned char* obj, int bit, int cond);

// USA: func_0207973c
ARM int CheckAndSetAllCombatantFlags0207973c(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    int i;
    for (i = 0; i < 4; i++) {
        if (!TestBitBySignedByteIndex_0202c1c0(search, i) || GetCombatantWithFlag0x1000_0200ff58(battleStruct, i) != 0) {
            SetField0x17eBitAndHigh_02079710(obj, i, 1);
        }
    }
    return (obj[0x17e] & 0xf) == 0xf ? 1 : 0;
}
