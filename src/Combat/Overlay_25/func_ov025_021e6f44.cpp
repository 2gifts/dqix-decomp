#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchByIndex021820bc(void* obj, int unused, int index, int arg);

// USA: func_ov025_021e6f44
extern "C" ARM int func_ov025_021e6f44(void* unused0, int v1, int unused2, void* a3) {
    int local[12];
    GameState* bs = GameState::GetInstance();
    DispatchByIndex021820bc(a3, v1, 0x17, (int)&local[0]);
    int id = local[0];
    GameObject* obj = bs->GetGameObjectByIndex(id);
    if (obj == NULL) {
        return 1;
    }
    int party = (id >= 0 && id <= 3);
    if (party) {
        if (obj->obj3D_.normalizedAnimationTime_ < 0xb33) {
            return 0;
        }
    } else if (!obj->obj3D_.HasAnimationStopped() && !obj->obj3D_.HasAnimationReachedEnd()) {
        return 0;
    }
    return 1;
}
