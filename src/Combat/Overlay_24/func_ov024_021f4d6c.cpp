#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov024_021ede2c(void* obj);
struct FlagObj_021da9b0;
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(struct FlagObj_021da9b0* obj);

struct Obj_021f4d6c { int field0; };

struct Buf4_021f4d6c { short v[4]; };
extern struct Buf4_021f4d6c data_ov024_021feba4;

// JPN: func_ov024_021f5538
// USA: func_ov024_021f4d6c
extern "C" ARM int func_ov024_021f4d6c(struct Obj_021f4d6c* obj, int unused1, int unused2, int* outCount, short* outArr) {
    struct Buf4_021f4d6c buf = data_ov024_021feba4;
    int count = func_ov000_0215e9fc(obj->field0, buf.v, 4, 1);
    if (count <= 0) return 0;
    if (!func_ov024_021ede2c(obj)) return 0;
    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((struct FlagObj_021da9b0*)c)) continue;
        int value = *((unsigned char*)c->currentStats_ + 0x4e);
        if (value <= 0) continue;
        outArr[(*outCount)++] = buf.v[i];
    }
    if (*outCount <= 0) return 0;
    if (*outCount * 3 < count * 2) return 0;
    *outCount = count;
    memcpy(outArr, buf.v, 8);
    return 1;
}
