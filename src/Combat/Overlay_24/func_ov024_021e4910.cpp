#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"

struct BattleStageState {
    unsigned char pad_00[0x8e02];
    unsigned char entryCount;
};
struct StageAction {
    unsigned char pad_00[0xc];
    void* chain;
    BattleStageState* battle;
};
struct StageParameters {
    unsigned char pad_00[0x32];
    short delta;
};
struct StatStageStruct02087860;
struct StatStageStruct02087954;
int CanAdjustStatStageBit3(StatStageStruct02087860*, int);
int CanAdjustStatStageBit6(StatStageStruct02087954*, int);
extern "C" int func_020878b4(ModifiableCombatStats*, int);
extern "C" int func_020879a8(ModifiableCombatStats*, int);
void UpdateCombatantDefense(int, int);
void UpdateCombatantAgility(int, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" int func_ov024_021e95d4(StageAction*, int, StageParameters*, unsigned char, signed char, unsigned char, unsigned char);
extern "C" int func_ov024_021e96e4(StageAction*, int, StageParameters*, unsigned char, signed char, unsigned char, unsigned char);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void*, void*, int);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void*, void*, int);

// JPN: func_ov024_021e51a8
// USA: func_ov024_021e4910
extern "C" ARM unsigned long long func_ov024_021e4910(StageAction* action, int unused, short id, StageParameters* parameters) {
    GameObject* combatant = GetCombatantByID((int)action->battle, id);
    if (!combatant) return 0;
    int delta = parameters->delta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    int decrease = 0;
    if (delta < 0) decrease = 1;
    int defenseChanged = 0;
    int result = 0;
    void* entry = func_ov000_0215e958(action->battle);
    if (!entry) return 0;
    if (CanAdjustStatStageBit3((StatStageStruct02087860*)combatant->currentStats_, (unsigned char)decrease)) {
        result = func_020878b4(combatant->currentStats_, (signed char)delta);
        UpdateCombatantDefense((int)action->battle, id);
        defenseChanged = 1;
    }
    if (defenseChanged) {
        int code = func_ov024_021e95d4(action, id, parameters, (unsigned char)decrease, (signed char)result, 1, 1);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(action->battle, entry, code);
    }
    int agilityChanged = 0;
    if (CanAdjustStatStageBit6((StatStageStruct02087954*)combatant->currentStats_, decrease & 0xff)) {
        result = func_020879a8(combatant->currentStats_, (signed char)delta);
        UpdateCombatantAgility((int)action->battle, id);
        agilityChanged = 1;
    }
    if (agilityChanged) {
        int code = func_ov024_021e96e4(action, id, parameters, (unsigned char)decrease, (signed char)result, 1, 1);
        _Z33AddEntryAndIncrementCount0215a88cPvS_i(action->battle, entry, code);
    }
    union { struct { int low; int high; }; unsigned long long value; } effects;
    effects.low = 0;
    effects.high = 0;
    if (defenseChanged || agilityChanged) {
        func_ov000_02159eac(action->battle, &effects, 0x1e);
        func_ov000_02159eac(action->battle, &effects, 0x1f);
        func_ov000_0215cd44(action->battle, entry, combatant, 0, 0, 0, 0);
        _Z32AppendToChainAndIncCount0215ffc4PvS_i(action->chain, entry, 1);
        action->battle->entryCount++;
    }
    return effects.value;
}
