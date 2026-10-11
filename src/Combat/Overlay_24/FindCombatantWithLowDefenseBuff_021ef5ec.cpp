#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Obj_021ef5ec { int field0; };
struct Buf4_021ef5ec { short v[4]; };
extern struct Buf4_021ef5ec data_ov024_021feb6c;

// USA: func_ov024_021ef5ec  (semantic: FindCombatantWithLowDefenseBuff_021ef5ec)
extern "C" ARM int func_ov024_021ef5ec(struct Obj_021ef5ec* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf4_021ef5ec buf = data_ov024_021feb6c;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && c->currentStats_->primaryStats.defense != 0 && c->currentStats_->defenseBuff > -2) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
