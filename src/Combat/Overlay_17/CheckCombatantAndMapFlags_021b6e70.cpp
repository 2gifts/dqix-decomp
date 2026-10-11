#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Grotto/Main/TreasureMapMetadata.h"

extern "C" void* func_02012fe4(void);
int IsValueInRange0201b5d8(int x);

struct Obj_021b6e70 {
    unsigned char pad0[0xc];
    unsigned char field0xc;
    unsigned char field0xd;
};

// USA: func_ov017_021b6e70  (semantic: CheckCombatantAndMapFlags_021b6e70)
extern "C" ARM bool func_ov017_021b6e70(struct Obj_021b6e70* obj, int combatantId) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetMaybeFieldMonsterByIndex(combatantId);
    if (combatant) {
        unsigned char flags = *((unsigned char*)combatant + 0x17d);
        if (flags & 0x2) {
            obj->field0xc = 1;
        } else if (flags & 0x4) {
            obj->field0xd = 1;
        }
    }

    void* misc = func_02012fe4();
    struct GrottoStruct* grotto = battleStruct->GetGrottoStruct();
#if defined(jpn)
    int mapType = ((TreasureMapMetadata*)((char*)grotto + 0x4c))->GetMapType();
#else
    int mapType = grotto->activeMapData.GetMapType();
#endif
    int val = *(unsigned short*)misc;

    if (IsValueInRange0201b5d8(val)) {
        if (mapType == 1) {
            obj->field0xc = 1;
        } else if (mapType == 2) {
            obj->field0xd = 1;
        }
    }

    return obj->field0xc != 0 || obj->field0xd != 0;
}
