#include <globaldefs.h>
#include "GameState/GameState.h"

struct CombatantEntry_021e1048 {
    unsigned char index;
    unsigned char adjustedIndex;
    char pad2[6];
    GameObject* object;
};

extern "C" int func_ov000_0215e9fc(void* battle, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* battle, short* buf, int max, int start);
extern "C" int _Z20AdjustIndex_021dfbd4i(int idx);

// USA: func_ov025_021e1048
extern "C" ARM int func_ov025_021e1048(void* battle, CombatantEntry_021e1048* out) {
    GameState* gs = GameState::GetInstance();
    short ids[12];
    int count = 0;
    count += func_ov000_0215e9fc(battle, ids, 12, count);
    count += func_ov000_0215ec1c(battle, ids + count, 12 - count, 0);
    int n = 0;
    for (int i = 0; i < count; i++) {
        GameObject* obj = gs->GetCombatantByIndex(ids[i]);
        if (obj == 0 || obj->obj3D_.pModel_ == 0) {
            continue;
        }
        out[n].index = ids[i];
        out[n].adjustedIndex = _Z20AdjustIndex_021dfbd4i(ids[i]);
        out[n].object = obj;
        n++;
    }
    return n;
}
