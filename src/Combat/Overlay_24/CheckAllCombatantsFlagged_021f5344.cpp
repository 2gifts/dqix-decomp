#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);
extern "C" int func_ov000_0215ec80(int a, short* buf, int max, int flagByte, int extra);
int CheckFlag0x14Bit0x10Set(unsigned char* obj);

struct Obj_021f5344 { int field0; };
struct Buf8_021f5344 { short v[8]; };
extern struct Buf8_021f5344 data_ov024_021fee4c;

// USA: func_ov024_021f5344  (semantic: CheckAllCombatantsFlagged_021f5344)
extern "C" ARM int func_ov024_021f5344(struct Obj_021f5344* obj, short id, int unused2, int* outFlag, short* outId) {
    GameObject* c = GetCombatantWithFlag0x400ByID(obj->field0, id);
    if (!c) return 0;
    int stateByte = *((unsigned char*)c + 0x17c);
    if (stateByte >= 3) return 0;
    struct Buf8_021f5344 buf = data_ov024_021fee4c;
    int count = func_ov000_0215ec80(obj->field0, buf.v, 8, stateByte & 0xff, 1);
    int matched = 0;
    for (int i = 0; i < count; i++) {
        GameObject* c2 = GetCombatantByID(obj->field0, buf.v[i]);
        if (!c2) continue;
        if (!CheckFlag0x14Bit0x10Set((unsigned char*)c2->currentStats_)) matched++;
    }
    if (matched != 8) return 0;
    *outFlag = 1;
    *outId = id;
    return 1;
}
