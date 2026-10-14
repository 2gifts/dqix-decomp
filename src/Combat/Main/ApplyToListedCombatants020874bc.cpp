#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
struct S02037418;

struct Party020874bc {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

// USA: func_020874bc
ARM void ApplyToListedCombatants020874bc(struct Party020874bc* party, int val) {
    GameState* bs = GameState::GetInstance();
    unsigned char i;
    for (i = 0; i < party->count; i++) {
        GameObject* c = GetCombatantWithFlag0x1000(bs, party->ids[i]);
        if (c != NULL) {
            ((Object3D*)((struct S02037418*)c))->SetInheritedAlpha(val);
        }
    }
}
