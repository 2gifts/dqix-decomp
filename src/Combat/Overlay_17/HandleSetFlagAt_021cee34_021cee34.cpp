#include <globaldefs.h>

#if defined(jpn)
enum { kCombatantFlagsOffset = 0x180 };
#else
enum { kCombatantFlagsOffset = 0x18c };
#endif

#include "GameState/GameState.h"

struct EventArgs021cee34 {
    unsigned char header[4];
    int combatantId;
    unsigned int mask;
    int enabled;
};

struct CombatantFlagsView {
    unsigned char unknown000[kCombatantFlagsOffset];
    unsigned int flags;
};

// USA: func_ov017_021cee34
ARM void HandleSetFlagAt_021cee34_021cee34(void* unused, EventArgs021cee34* args, GameState* battleStruct) {
    int enabled = args->enabled;
    unsigned int mask = args->mask;
    int id = args->combatantId;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
    if (combatant == NULL) return;
    CombatantFlagsView* status = (CombatantFlagsView*)combatant;
    if (enabled) {
        status->flags |= mask;
    } else {
        status->flags &= ~mask;
    }
}
