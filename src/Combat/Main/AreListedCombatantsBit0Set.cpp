#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02086b98 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

// USA: func_02086b98
ARM int AreListedCombatantsBit0Set(struct Obj02086b98* o) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < o->count; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, o->ids[i]);
        if (c != NULL) {
            int* p = *(int**)((char*)c + 0x130);
            if ((*p & 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}
