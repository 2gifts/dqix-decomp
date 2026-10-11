#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Obj_021f3440 { int field0; };
struct Buf4_021f3440 { short v[4]; };
extern struct Buf4_021f3440 data_ov024_021feb74;

// USA: func_ov024_021f3440
extern "C" ARM int func_ov024_021f3440(struct Obj_021f3440* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf4_021f3440 buf = data_ov024_021feb74;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && c->currentStats_->primaryStats.attack != 0 && c->currentStats_->attackBuff > -2) {
            int v = ((unsigned char*)c->currentStats_)[0x4f];
            if (v > 0) {
                found = 1;
                break;
            }
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
