#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int idx);
extern "C" void func_ov000_02170db0(void* p);

// USA: func_ov000_02174514
ARM void UpdateFieldIfDiffers_02174514_02174514(void* obj) {
    GameState* bs = GameState::GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, i);
        if (c == NULL) continue;
        void* p = func_ov000_02161318(obj, i);
        if (p != NULL) {
            int val = *(int*)(*(char**)((char*)c + 0x138) + 0x14);
            if (*(int*)((char*)p + 0x28) != val) {
                *(int*)((char*)p + 0x28) = val;
                func_ov000_02170db0(p);
            }
        }
    }
}
