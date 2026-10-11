#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
struct FlagObj_021dd010;
int IsFlagBit8Set_021dd010(struct FlagObj_021dd010* obj);

struct Obj_021f101c { int field0; };
struct Buf8_021f101c { short v[8]; };
extern struct Buf8_021f101c data_ov024_021feeec;

// USA: func_ov024_021f101c  (semantic: FindUnflaggedCombatant8_021f101c)
extern "C" ARM int func_ov024_021f101c(struct Obj_021f101c* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf8_021f101c buf = data_ov024_021feeec;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !IsFlagBit8Set_021dd010((struct FlagObj_021dd010*)c)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 0x10);
    return 1;
}
