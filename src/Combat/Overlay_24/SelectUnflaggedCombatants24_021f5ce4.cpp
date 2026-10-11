#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215eb1c(int a, short* buf, int max, int start);
struct FlagObj_021dd260;
int IsFlagBit24Set_021dd260(struct FlagObj_021dd260* obj);

struct Obj_021f5ce4 { int field0; };
struct Buf8_021f5ce4 { short v[8]; };
extern struct Buf8_021f5ce4 data_ov024_021fed9c;

// USA: func_ov024_021f5ce4  (semantic: SelectUnflaggedCombatants24_021f5ce4)
extern "C" ARM int func_ov024_021f5ce4(struct Obj_021f5ce4* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf8_021f5ce4 buf = data_ov024_021fed9c;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !IsFlagBit24Set_021dd260((struct FlagObj_021dd260*)c)) {
            (*outCount)++;
        }
    }
    if (*outCount <= 0) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 0x10);
    return 1;
}
