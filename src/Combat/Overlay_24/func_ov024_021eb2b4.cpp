#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);

struct Obj_021eb2b4 { char pad[0x10]; int field0x10; };
struct Buf4_021eb2b4 { short v[4]; };
extern struct Buf4_021eb2b4 data_ov024_021fe6d8;
struct StatusByte0x3b { unsigned char lowBits:3; unsigned char flag:1; unsigned char highBits:4; };

// USA: func_ov024_021eb2b4
extern "C" ARM int func_ov024_021eb2b4(struct Obj_021eb2b4* obj) {
    int result = 0;
    struct Buf4_021eb2b4 buf = data_ov024_021fe6d8;
    int count = func_ov000_0215e9fc(obj->field0x10, buf.v, 4, 1);
    for (int i = 0; i < count; i++) {
        GameObject* c = GetCombatantByID(obj->field0x10, buf.v[i]);
        struct StatusByte0x3b* sb = (struct StatusByte0x3b*)((char*)c->currentStats_ + 0x3b);
        if (sb->flag) result++;
    }
    return result;
}
