// JPN: func_ov017_02197d74
#if defined(jpn)
enum { RegionOffset1b2 = 0x1a6, RegionOffset4400 = 0x4200, RegionOffsetc2 = 0x12 };
#else
enum { RegionOffset1b2 = 0x1b2, RegionOffset4400 = 0x4400, RegionOffsetc2 = 0xc2 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* __clear(void* dst, int count);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra);

struct Party021971c4 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

// USA: func_ov017_021971c4  (semantic: FindNearbyCombatantWithDifferentTag_021971c4)
extern "C" ARM unsigned short func_ov017_021971c4(unsigned char* ov) {
    GameState* battleStruct = GameState::GetInstance();
    if (battleStruct == NULL) {
        return 0;
    }
    GameObject* combatant = battleStruct->GetUnknownGameObject();
    if (combatant == NULL) {
        return 0;
    }
    struct Party021971c4* party = (struct Party021971c4*)GetPtrField0x2a04(battleStruct);
    int flags[4];
    unsigned short result = 0;
    __clear(flags, 0x10);
    int i;
    for (i = 0; i < party->count; i++) {
        flags[party->ids[i]] = 1;
    }
    int j;
    for (j = 0; j < 4; j++) {
        if (flags[j] != 0) {
            continue;
        }
        GameObject* other = GetCombatantWithFlag0x100(battleStruct, j);
        if (other == NULL) {
            continue;
        }
        if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)other) != _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)combatant)) {
            continue;
        }
        if (*((unsigned char*)other + 0xbe) != 2) {
            continue;
        }
        if (CheckProximity_02196fc8((unsigned char*)combatant, (unsigned char*)other, 0x1000)) {
            unsigned short v = *(unsigned short*)((unsigned char*)other + RegionOffset1b2);
            if (*(unsigned short*)(ov + RegionOffset4400 + RegionOffsetc2) != v) {
                result = v;
                break;
            }
        }
    }
    return result;
}
