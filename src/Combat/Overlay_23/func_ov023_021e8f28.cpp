#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3acValue_020100a8(GameState* battleStruct);
unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst);
extern "C" void* __clear(void* dst, int count);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);

// USA: func_ov023_021e8f28
extern "C" ARM GameObject* func_ov023_021e8f28(int index) {
    GameState* battle = GameState::GetInstance();
    GameObject* result = 0;
    if (index >= 0) {
        int inRange = (index >= 0) && (index <= 3);
        if (inRange) {
            result = GetCombatantWithFlag0x100_0200ff1c(battle, index);
        }
    } else {
        if (index == -1) {
            int key = GetField0x3acValue_020100a8(battle);
            result = GetCombatantWithFlag0x100_0200ff1c(battle, key);
        } else {
            unsigned char local[4];
            __clear(local, 4);
            unsigned char count = CopyOutRegion0x5718_02011494((char*)battle, local);
            int i = -1 - index;
            if (i < count) {
                result = GetCombatantWithFlag0x100_0200ff1c(battle, local[i]);
            }
        }
    }
    return result;
}
