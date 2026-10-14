#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_02156068(int unused0, int id, int a2, int a3);
GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);
int IsCombatantFlagMask536870912_021edbf0(GameObject* combatant);

struct Obj_021f2e88 { int field0; };
struct Buf4_021f2e88 { short v[4]; };
extern struct Buf4_021f2e88 data_ov024_021feb9c;

// USA: func_ov024_021f2e88  (semantic: CountFlaggedThenMaybeAssign_021f2e88)
extern "C" ARM int func_ov024_021f2e88(struct Obj_021f2e88* obj, int id, int unused2, int* outCount, short* outPtr) {
    struct Buf4_021f2e88 buf = data_ov024_021feb9c;

    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        int hit = func_ov000_02156068(obj->field0, buf.v[i], 8, 0);
        if (hit) {
            *outCount = *outCount + 1;
        }
    }

    if (*outCount <= 0) return 0;

    GameObject* c = GetCombatantWithFlag0x400ByID_ov000_021536f8(obj->field0, id);
    if (!c) return 0;

    int flag = IsCombatantFlagMask536870912_021edbf0(c);
    int result;
    if (flag) {
        result = 0;
    } else {
        *outPtr = id;
        *outCount = 1;
        result = 1;
    }
    return result;
}
