#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x144
#define REGION_OFFSET_1 0x8b8
#else
#define REGION_OFFSET_0 0x150
#define REGION_OFFSET_1 0x950
#endif

#include "GameState/GameState.h"

extern short data_ov000_02182d54;
extern short data_ov000_02182d56[];

// USA: func_ov000_02159cb4  (semantic: Lookup_02159cb4)
extern "C" ARM int func_ov000_02159cb4(void* unusedThis, int combatantId) {
    GameState* battle = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x100(battle, combatantId);
    if (!c) return 0;

    int i = 0;
    while (*(short*)((char*)&data_ov000_02182d54 + i * 4) != -1) {
        void* sub = *(void**)((char*)c + REGION_OFFSET_0);
        short key = *(short*)((char*)&data_ov000_02182d54 + i * 4);
        if (key == *(int*)((char*)sub + REGION_OFFSET_1)) {
            return data_ov000_02182d56[i * 2];
        }
        i++;
    }
    return 0;
}
