#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct Obj_021f0748 { int field0; };
struct Buf4_021f0748 { short v[4]; };
extern struct Buf4_021f0748 data_ov024_021feb54;

// USA: func_ov024_021f0748  (semantic: FindUnflaggedCombatantBit4_021f0748)
extern "C" ARM int func_ov024_021f0748(struct Obj_021f0748* obj, int unused1, int unused2, int* outCount, void* outArr) {
    struct Buf4_021f0748 buf = data_ov024_021feb54;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    int found = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (c && !CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_)) {
            found = 1;
            break;
        }
    }
    if (!found) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
