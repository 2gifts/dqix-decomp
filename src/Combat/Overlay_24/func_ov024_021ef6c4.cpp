#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "std_library_functions.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
int IsCombatantFlagMask512_021eda60(GameObject* combatant);

struct Obj_021ef6c4 { int field0; };
struct Buf4_021ef6c4 { short v[4]; };
extern struct Buf4_021ef6c4 data_ov024_021feab4;

struct Bits58_021ef6c4 { signed int lowBits : 3; signed int fieldZ : 3; signed int rest : 26; };

// USA: func_ov024_021ef6c4  (semantic: CountEligibleThenCopyOrFail_021ef6c4)
extern "C" ARM int func_ov024_021ef6c4(struct Obj_021ef6c4* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Buf4_021ef6c4 buf = data_ov024_021feab4;

    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;

    int matchCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (*(unsigned short*)((char*)c->currentStats_ + 0xa) == 0) continue;
        struct Bits58_021ef6c4* bits = (struct Bits58_021ef6c4*)((char*)c->currentStats_ + 0x58);
        if (bits->fieldZ <= -2) continue;
        if (IsCombatantFlagMask512_021eda60(c)) continue;
        int byteVal = *(unsigned char*)((char*)c->currentStats_ + 0x50);
        if (byteVal > 0) matchCount++;
    }

    if (matchCount * 3 < count * 2) return 0;

    *outCount = count;
    memcpy(outArray, buf.v, 8);
    return 1;
}
