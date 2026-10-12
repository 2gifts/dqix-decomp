#include <globaldefs.h>

#if defined(jpn)
enum { kCombatantFlagsOffset = 0x180 };
#else
enum { kCombatantFlagsOffset = 0x18c };
#endif


#if defined(jpn)
#define HandleSetFlagAt_021cee34_021cee34 func_ov017_021cf2dc
#endif
#include "GameState/GameState.h"

struct EventArgs021cee34 {
    unsigned char pad[4];
    int id;
    unsigned int flag;
    int set;
};

// USA: func_ov017_021cee34
#if defined(jpn)
extern "C"
#endif
ARM void HandleSetFlagAt_021cee34_021cee34(void* unused, EventArgs021cee34* args, GameState* battleStruct) {
    int set = args->set;
    unsigned int flag = args->flag;
    int id = args->id;
    GameObject* combatant = GetCombatantWithFlag0x100(battleStruct, id);
    if (combatant == NULL) return;
    unsigned int* field = (unsigned int*)((char*)combatant + kCombatantFlagsOffset);
    if (set) {
        *field |= flag;
    } else {
        *field &= ~flag;
    }
}
