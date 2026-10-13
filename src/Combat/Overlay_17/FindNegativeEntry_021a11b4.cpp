#include <globaldefs.h>
#include "Resource/GameResources.h"

struct S021a11b4;
struct CombatantResourceSlotHeader {
    short combatantId;
    unsigned short slotIndex;
};

// USA: func_ov017_021a11b4
ARM void* FindNegativeEntry_021a11b4(S021a11b4* resourceStorage) {
    GameResources* resources = (GameResources*)resourceStorage;
    for (int slot = 0; slot < 4; ++slot) {
        CombatantResourceSlotHeader* header = (CombatantResourceSlotHeader*)resources->substruct_array_12c8[slot].unknown_0;
        if (header->combatantId < 0) return &resources->substruct_array_12c8[slot];
    }
    return NULL;
}
