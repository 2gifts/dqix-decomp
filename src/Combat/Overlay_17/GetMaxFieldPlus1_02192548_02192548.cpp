#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);

struct CombatantSequenceView {
#if defined(jpn)
    unsigned char unknown000[0x2c6];
#else
    unsigned char unknown000[0x2d2];
#endif
    unsigned char sequence;
};

// USA: func_ov017_02192548
ARM int GetMaxFieldPlus1_02192548_02192548(void) {
    GameState* battle = GameState::GetInstance();
    int maximumSequence = 0;
    for (int partyIndex = 1; partyIndex < 4; ++partyIndex) {
        GameObject* member = GetCombatantWithFlag0x1000(battle, partyIndex);
        if (member != NULL) {
            unsigned char sequence = ((CombatantSequenceView*)member)->sequence;
            if (maximumSequence < sequence) maximumSequence = sequence;
        }
    }
    return maximumSequence + 1;
}
