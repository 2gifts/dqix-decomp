#include <globaldefs.h>

#if defined(jpn)
enum { kCombatantFlagsOffset = 0x180 };
#else
enum { kCombatantFlagsOffset = 0x18c };
#endif


#if defined(jpn)
#define SetCombatantFlag8IfField8_021d25b8 func_ov017_021d2a3c
#endif
#include "GameState/GameState.h"


struct S021d25b8 {
    unsigned char header[4];
    unsigned char partyIndex;
    unsigned char unknown005[3];
    int enabled;
};

struct CombatantFlagsView {
    unsigned char unknown000[kCombatantFlagsOffset];
    unsigned int flags;
};

// USA: func_ov017_021d25b8
#if defined(jpn)
extern "C"
#endif
ARM void SetCombatantFlag8IfField8_021d25b8(int unused, S021d25b8* event, GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(event->partyIndex);
    if (combatant == NULL) return;
    CombatantFlagsView* status = (CombatantFlagsView*)combatant;
    if (event->enabled != 0) status->flags |= 8;
    else status->flags &= ~8;
}
