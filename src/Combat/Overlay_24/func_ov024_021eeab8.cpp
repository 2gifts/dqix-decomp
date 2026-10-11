#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct Obj_021eeab8 { int field0; };
struct Buf8_021eeab8 { short v[8]; };
extern struct Buf8_021eeab8 data_ov024_021feecc;

// USA: func_ov024_021eeab8  (semantic: FilterActiveOrFallbackToAll_021eeab8)
extern "C" ARM int func_ov024_021eeab8(struct Obj_021eeab8* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Buf8_021eeab8 buf = data_ov024_021feecc;

    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 1);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        if (!CheckFlag0x14Bit0x10Set((unsigned char*)c->currentStats_)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    if (*outCount * 3 < count) return 0;

    *outCount = count;
    memcpy(outArray, buf.v, 0x10);
    return 1;
}
