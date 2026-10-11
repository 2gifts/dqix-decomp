#include <globaldefs.h>

#if defined(jpn)
enum { kOffset18 = 0x19 };
#else
enum { kOffset18 = 0x18 };
#endif

#include "GameState/GameState.h"

// KEEP-NAME: the ROM symbol is the mangled C++ name, not a func_ tag.
// USA: func_0201fca0


// One 32-byte record per combatant, holding two independent slots. Slot A is submitted by
// this function, slot B by SubmitFlag0x800CombatantDataB0201fd38; a negative state means
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

ARM void SubmitFlag0x800CombatantDataA0201fca0(void* a, void* b, int combatantId) {
    if (GameState::GetInstance()->GetPartyMemberByIndex(combatantId) != NULL) {
        struct CombatantSubmitEntry* entry = &data_020fdcb0[combatantId];
        int state = entry->stateA;
        if (state >= 0) {
            func_0201fdd0(a, b, combatantId, state, entry->valueA, 0x30, 0x10, 7, kOffset18, 9, 0xa, 0);
        }
    }
}
