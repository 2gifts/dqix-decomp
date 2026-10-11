#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
extern "C" float func_ov024_021db358(GameObject* obj);

struct Obj_021f3d78 { int field0; };
struct Buf8_021f3d78 { short v[8]; };
extern struct Buf8_021f3d78 data_ov024_021feefc;

// USA: func_ov024_021f3d78
extern "C" ARM int func_ov024_021f3d78(struct Obj_021f3d78* obj, int id, int unused2, int* outFlag, short* outArr) {
    struct Buf8_021f3d78 buf = data_ov024_021feefc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outFlag = 0;
    for (int i = 0; i < count; i++) {
        if (id == buf.v[i]) continue;
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (func_ov024_021db358(c) > 0.08f) continue;
        int n = *outFlag;
        *outFlag = n + 1;
        outArr[n] = buf.v[i];
    }
    int result;
    if (*outFlag <= 0) {
        result = 0;
    } else {
        *outFlag = 1;
        outArr[0] = (short)id;
        result = 1;
    }
    return result;
}
