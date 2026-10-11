#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

struct Obj_021f1768 { int field0; };
struct Buf4_021f1768 { short v[4]; };
extern struct Buf4_021f1768 data_ov024_021fec34;

struct BuffWord_021f1768 {
    signed int attackBuff : 3;
    signed int defenseBuff : 3;
    signed int agilityBuff : 3;
    signed int charmBuff : 3;
    signed int magicalMightBuff : 3;
    signed int magicalMendingBuff : 3;
    signed int unkBuff18 : 3;
};

// USA: func_ov024_021f1768  (semantic: FindCombatantWithLowUnkBuff18_021f1768)
extern "C" ARM int func_ov024_021f1768(struct Obj_021f1768* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf4_021f1768 buf = data_ov024_021fec34;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        struct BuffWord_021f1768* bw = (struct BuffWord_021f1768*)((char*)c->currentStats_ + 0x58);
        if (bw->unkBuff18 > -2) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
