#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/BattleSkillEligibility.h"
#include "Grotto/Main/ActiveGrottoClass.h"

GameObject* GetCombatantWithFlag0x400(GameState* gameState, int combatantId);
extern "C" void* _Z29FindEntryForCombatant02153758Pvi(void* obj, int idx);
extern "C" char* func_02012fe4(void);

struct MonsterEntry_02159dbc {
    char pad0[0xa];
    unsigned short level : 7;
};

struct PartyWork_02159dbc {
    char pad[0x25];
    unsigned char field_0x25;
};

// USA: func_ov000_02159dbc
extern "C" ARM int func_ov000_02159dbc(char* battle, int combatantId) {
    GameState* gs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x400(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 1;
    }
    struct MonsterEntry_02159dbc* entry =
        (struct MonsterEntry_02159dbc*)_Z29FindEntryForCombatant02153758Pvi(battle, combatantId);
    if (entry == 0) {
        return 1;
    }
    char* zone = func_02012fe4();
    if (IsGlobalU16InRange(gs) && (*(struct PartyWork_02159dbc**)(battle + 0x8e18))->field_0x25 != 0) {
#if defined(jpn)
        enum { grottoOffset = 0x240c };
#else
        enum { grottoOffset = 0x23ec };
#endif
        DetailedTreasureMapData* detail = ((ActiveGrottoClass*)(zone + grottoOffset))->GetDetailedData();
        short monsterId = combatant->obj3D_.unknown_2_;
        unsigned short alt = detail->legacy_.MaybeGetCurrentAlternateID();
        if (alt == monsterId) {
            return detail->legacy_.level_;
        }
    }
    return entry->level;
}
