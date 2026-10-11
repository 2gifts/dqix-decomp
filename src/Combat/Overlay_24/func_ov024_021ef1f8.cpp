#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215ec80(int battle, short* buf, int max, int group, int extra);
extern "C" int _Z31IsCombatantFlagMask512_021eda60P10GameObject(GameObject* combatant);

struct Group_021ef1f8 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
};
struct Obj_021ef1f8 { int field0; };
struct Ids3_021ef1f8 { short v[3]; };
struct Buf8_021ef1f8 { short v[8]; };
extern struct Ids3_021ef1f8 data_ov024_021fea1c[4];
extern struct Buf8_021ef1f8 data_ov024_021fed2c;

// USA: func_ov024_021ef1f8
extern "C" ARM int func_ov024_021ef1f8(struct Obj_021ef1f8* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Group_021ef1f8* group = (struct Group_021ef1f8*)(obj->field0 + 0x81b0);
    if (!group) return 0;

    struct Ids3_021ef1f8 candidates = data_ov024_021fea1c[3];
    short numCandidates = 0;
    for (int g = 0; g < group->groupCount; g++) {
        struct Buf8_021ef1f8 buf = data_ov024_021fed2c;
        int count = func_ov000_0215ec80(obj->field0, buf.v, 8, g & 0xff, 1);
        if (count <= 0) continue;
        short matched = 0;
        for (int i = 0; i < count; i++) {
            GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
            if (!c) continue;
            if (c->currentStats_->primaryStats.defense >= 0xffff) continue;
            if (c->currentStats_->defenseBuff >= 2) continue;
            if (!_Z31IsCombatantFlagMask512_021eda60P10GameObject(c)) matched++;
        }
        if (matched > 0) candidates.v[numCandidates++] = g;
    }
    if (numCandidates <= 0) return 0;

    int pick = NextRandomMax((struct Random*)obj->field0, numCandidates);
    *outCount = func_ov000_0215ec80(obj->field0, outArray, 8, candidates.v[pick] & 0xff, 1);
    return 1;
}
