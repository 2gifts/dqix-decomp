#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

extern "C" int func_ov000_0215eb1c(int a0, short* buf, int count, int flag);
int IsFlag10088Set(struct S_10088* obj);
int PickRandomTableEntryResetCounter_021ed890(struct Random** rngPtr, int* maxAndFlag, short* table);

struct Gate_021eebbc { char pad0; unsigned char flags:4; unsigned char pad1:4; };
struct Obj_021eebbc { int field0; };
struct Buf8_021eebbc { short v[8]; };
extern struct Buf8_021eebbc data_ov024_021fecdc;

// USA: func_ov024_021eebbc  (semantic: SelectFlagged10088AndMaybePick_021eebbc)
extern "C" ARM int func_ov024_021eebbc(struct Obj_021eebbc* obj, int unused1, int unused2, int* outCount, short* outArray) {
    struct Gate_021eebbc* gate = (struct Gate_021eebbc*)((char*)obj->field0 + 0x81b0);
    if (!gate) return 0;
    int nibble = gate->flags;
    if (nibble >= 5) return 0;

    struct Buf8_021eebbc buf = data_ov024_021fecdc;
    int count = func_ov000_0215eb1c(obj->field0, buf.v, 8, 0);
    if (count <= 0) return 0;

    *outCount = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c) continue;
        if (!IsFlag10088Set((struct S_10088*)c)) continue;
        int idx = *outCount;
        *outCount = idx + 1;
        outArray[idx] = buf.v[i];
    }

    if (*outCount <= 0) return 0;
    PickRandomTableEntryResetCounter_021ed890((struct Random**)obj, outCount, outArray);
    return 1;
}
