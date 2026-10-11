#include <globaldefs.h>

#if defined(jpn)
enum { kOffset1c = 0x1d, kOffset24 = 0x26 };
#else
enum { kOffset1c = 0x1c, kOffset24 = 0x24 };
#endif

#include "GameState/GameState.h"

// KEEP-NAME: the ROM symbol is the mangled C++ name, not a func_ tag.
// USA: func_0201fd38


// One 32-byte record per combatant, holding two independent slots. Slot A is submitted by
// SubmitFlag0x800CombatantDataA0201fca0, slot B by this function; a negative state means
// "nothing to submit".
struct CombatantSubmitEntry {
    int stateA;
    int stateB;
    int valueA;
    int valueB;
    int unk10[4];
};

extern struct CombatantSubmitEntry data_020fdcb0[];

extern "C" void func_0201fdd0(void* a, void* b, int combatantId, int state, int value, int arg5,
                              int arg6, int arg7, int arg8, int arg9, int arg10, int arg11);

ARM void SubmitFlag0x800CombatantDataB0201fd38(void* a, void* b, int combatantId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(combatantId) != NULL) {
        struct CombatantSubmitEntry* entry = &data_020fdcb0[combatantId];
        int state = entry->stateB;
        if (state >= 0) {
            func_0201fdd0(a, b, combatantId, state, entry->valueB, 0x30, kOffset1c, 7, kOffset24, 0xb, 0xc, 1);
        }
    }
}
