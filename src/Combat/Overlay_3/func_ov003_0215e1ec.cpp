#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue3C3_3DB = 0x3db };
#else
enum { kRegionValue3C3_3DB = 0x3c3 };
#endif


extern "C" void __clear(void* buf, int len);
unsigned char CopyOutRegion0x5718(char* obj, void* dst);

struct CombatantStatus0215e1ec {
    unsigned int flags;
    unsigned short hp;
};

struct BattleSide0215e1ec {
    char pad0[kRegionValue3C3_3DB];
    unsigned char aliveCount;
    unsigned char aliveIds[4];
};

// USA: func_ov003_0215e1ec
// JPN: func_ov003_0215f4c4
extern "C" ARM void func_ov003_0215e1ec(struct BattleSide0215e1ec* side) {
    GameState* gs = GameState::GetInstance();
    unsigned char ids[4];
    __clear(ids, 4);
    int n = CopyOutRegion0x5718((char*)gs, ids);
    side->aliveCount = 0;
    for (int i = 0; i < n; i++) {
        GameObject* c = GetCombatantWithFlag0x100(gs, ids[i]);
        if (c != NULL) {
            struct CombatantStatus0215e1ec* status = *(struct CombatantStatus0215e1ec**)((char*)c + 0x130);
            int hp = status->hp;
            if (hp > 0) {
                side->aliveIds[side->aliveCount++] = ids[i];
            }
        }
    }
}
