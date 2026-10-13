#include <globaldefs.h>
#include "Combat/CombatantDisplay.h"

#if defined(jpn)
enum { kOffset1c = 0x1d, kOffset24 = 0x26 };
#else
enum { kOffset1c = 0x1c, kOffset24 = 0x24 };
#endif

#include "GameState/GameState.h"

// USA: func_0201fd38

struct CombatantSubmitEntry {
    int stateA;
    int stateB;
    int valueA;
    int valueB;
    int unk10[4];
};

extern struct CombatantSubmitEntry data_020fdcb0[];

ARM void SubmitFlag0x800CombatantDataB0201fd38(Display0201fdd0* display, int row, int combatantId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(combatantId) != NULL) {
        struct CombatantSubmitEntry* entry = &data_020fdcb0[combatantId];
        int state = entry->stateB;
        if (state >= 0) {
            func_0201fdd0(display, row, combatantId, state, entry->valueB, 0x30, kOffset1c, 7, kOffset24, 0xb, 0xc, 1);
        }
    }
}
