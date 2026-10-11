#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
struct Combatant_20885b4;
int CheckFlag0x2AndKind1(struct Combatant_20885b4* obj);
struct S88514;
int CheckFlag0x2AndState2(struct S88514* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Obj_021ee8b4 { int field0; };
struct Buf8_021ee8b4 { short v[8]; };
extern struct Buf8_021ee8b4 data_ov024_021fecbc;

// USA: func_ov024_021ee8b4  (semantic: FilterEligibleAndPick_021ee8b4)
extern "C" ARM int func_ov024_021ee8b4(struct Obj_021ee8b4* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Buf8_021ee8b4 buf = data_ov024_021fecbc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        if (!CheckFlag0x2AndKind1((struct Combatant_20885b4*)c->currentStats_) &&
            !CheckFlag0x2AndState2((struct S88514*)c->currentStats_)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)obj, outCount, outArray);
    return 1;
}
