#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
struct FlagObj_021dd010;
int IsFlagBit8Set_021dd010(struct FlagObj_021dd010* obj);

struct Obj_021f094c { int field0; };

struct Buf4_021f094c { short v[4]; };
extern struct Buf4_021f094c data_ov024_021febdc;

// USA: func_ov024_021f094c  (semantic: CheckAnyCombatantHasMP_021f094c)
extern "C" ARM int func_ov024_021f094c(struct Obj_021f094c* obj, int id) {
    GameObject* c = GetCombatantByID(obj->field0, id);
    if (!c) return 0;
    if (IsCombatantFlagMask512_021eda60(c)) return 0;
    struct Buf4_021f094c buf = data_ov024_021febdc;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c2 = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c2) continue;
        if (IsFlagBit8Set_021dd010((struct FlagObj_021dd010*)c2)) continue;
        if (c2->currentStats_->primaryStats.currMP != 0) found = 1;
    }
    return found;
}
