#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);

struct Obj_021f0578 { int field0; };
struct Buf4_021f0578 { short v[4]; };
extern struct Buf4_021f0578 data_ov024_021fea34;

// USA: func_ov024_021f0578  (semantic: FindUnflaggedCombatant_021f0578)
extern "C" ARM int func_ov024_021f0578(struct Obj_021f0578* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf4_021f0578 buf = data_ov024_021fea34;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)c)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
