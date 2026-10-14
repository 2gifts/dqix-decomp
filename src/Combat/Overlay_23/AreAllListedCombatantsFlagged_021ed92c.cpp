#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
struct S_10088;
int IsFlag10088Set_02010088(struct S_10088* obj);

// USA: func_ov023_021ed92c
ARM int AreAllListedCombatantsFlagged_021ed92c(void) {
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GetPtrField0x2a04_02010828(bs);
    for (int i = 0; i < base[0xf7c]; i++) {
        unsigned char* p = base + i;
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(bs, p[0xf78]);
        if (combatant) {
            if (!IsFlag10088Set_02010088((struct S_10088*)combatant)) return 0;
        }
    }
    return 1;
}
