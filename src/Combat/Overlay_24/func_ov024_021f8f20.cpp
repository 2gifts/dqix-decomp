#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"

void* GetFieldAt0x150(unsigned char* obj);

struct AiPlanner_021f8f20;
typedef void (AiPlanner_021f8f20::*PlanFn_021f8f20)(unsigned short id, GameObject* combatant, unsigned short* state);
struct PlanTable_021f8f20 { PlanFn_021f8f20 e[6]; };

struct AiPlanner_021f8f20 {
    int owner;
    short id;
    unsigned char mode;
    char pad7[0x124 - 0x7];
    float weight;
};

extern "C" void func_ov024_021f8628(AiPlanner_021f8f20* obj, unsigned short id, GameObject* combatant, unsigned short* state);
extern "C" void func_ov024_021f7478(AiPlanner_021f8f20* obj);

extern PlanTable_021f8f20 data_ov024_021ff054;
extern PlanFn_021f8f20 data_020e6d5c;

// JPN: func_ov024_021f96ec
// USA: func_ov024_021f8f20
extern "C" ARM void func_ov024_021f8f20(AiPlanner_021f8f20* obj, int owner, int id, unsigned short* state) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    void* field = GetFieldAt0x150((unsigned char*)combatant);
    if (*state != 1) {
        return;
    }
    obj->owner = owner;
    obj->id = id;
#if defined(jpn)
    unsigned char mode = (signed char)*(int*)((char*)field + 0x8b4);
#else
    unsigned char mode = (signed char)*(int*)((char*)field + 0x94c);
#endif
    if (mode == 5) {
        return;
    }
    if (mode > 5) {
        func_ov024_021f8628(obj, id, combatant, state);
        return;
    }
    obj->weight = 0.5f;
    obj->mode = mode;
    func_ov024_021f7478(obj);
    PlanTable_021f8f20 table = data_ov024_021ff054;
    table.e[5] = data_020e6d5c;
    PlanFn_021f8f20 fn = table.e[mode];
    if (fn != 0) {
        (obj->*fn)(id, combatant, state);
    }
}
