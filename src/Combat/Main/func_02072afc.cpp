#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

struct Field150Holder02052e2c;
struct Field150Holder02052e14;
extern "C" short* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(Field150Holder02052e2c* obj);
short* GetField150Ptr0x488(Field150Holder02052e14* obj);

struct CombatantEffectIds02072afc {
    int entries[11];
};
extern CombatantEffectIds02072afc data_020e8878;

// USA: func_02072afc
extern "C" ARM void func_02072afc(int combatantId, int* outIds, short* outValues) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (combatant == NULL) return;
    short* fallback = _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c((Field150Holder02052e2c*)combatant);
    if (fallback == NULL) return;
    short* effects = GetField150Ptr0x488((Field150Holder02052e14*)combatant);
    CombatantEffectIds02072afc ids = data_020e8878;
    int base = combatantId * 12;
    ids.entries[0] = combatantId;
    ids.entries[1] = base + 19;
    ids.entries[2] = base + 20;
    ids.entries[3] = base + 21;
    ids.entries[4] = base + 22;
    ids.entries[5] = base + 23;
    ids.entries[6] = base + 25;
    ids.entries[7] = base + 27;
    ids.entries[8] = base + 28;
    ids.entries[9] = base + 29;
    short values[11] = {
        effects[0], effects[1], effects[2], effects[3], effects[3],
        effects[4], effects[5], effects[6], effects[7], effects[8], effects[9]
    };
    for (int i = 0; i < 11; i++) {
        outIds[i] = ids.entries[i];
        outValues[i] = values[i];
    }
    if (outValues[0] < 0) outValues[0] = 1000;
    if (outValues[1] < 0) outValues[1] = 8001;
    if (outValues[6] < 0) outValues[6] = 994;
    if (outValues[5] < 0) {
        outValues[5] = fallback[11];
        if (outValues[5] < 0) outValues[5] = 8010;
    }
}
