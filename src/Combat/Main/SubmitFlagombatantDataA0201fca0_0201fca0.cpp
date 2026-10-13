#include <globaldefs.h>
#include "Combat/CombatantDisplay.h"

#if defined(jpn)
enum { kOffset18 = 0x19 };
#else
enum { kOffset18 = 0x18 };
#endif

#include "GameState/GameState.h"

// USA: func_0201fca0


struct CombatantSubmitEntry {
    int stateA;
    int stateB;
    int valueA;
    int valueB;
    int unk10[4];
};

extern struct CombatantSubmitEntry data_020fdcb0[];

ARM void SubmitFlag0x800CombatantDataA0201fca0(Display0201fdd0* display, int row, int combatantId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(combatantId) != NULL) {
        struct CombatantSubmitEntry* entry = &data_020fdcb0[combatantId];
        int state = entry->stateA;
        if (state >= 0) {
            func_0201fdd0(display, row, combatantId, state, entry->valueA, 0x30, 0x10, 7, kOffset18, 9, 0xa, 0);
        }
    }
}
