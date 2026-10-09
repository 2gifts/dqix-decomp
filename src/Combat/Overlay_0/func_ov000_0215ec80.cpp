#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);

struct CombatGroup_0215ec80 {
    unsigned short field_0x0;
    unsigned char ids[8];
    unsigned char total : 4;
    unsigned char matched : 4;
    unsigned char pad[0x18 - 0xb];
};

struct Battle_0215ec80 {
    unsigned char pad[0x81b4];
    struct CombatGroup_0215ec80 groups[1];
};

// USA: func_ov000_0215ec80
extern "C" ARM int func_ov000_0215ec80(struct Battle_0215ec80* obj, short* out, int maxCount, int groupIdx, int flags) {
    int count = 0;
    int i;
    for (i = 0; i < obj->groups[groupIdx].total; i++) {
        short id = (short)(obj->groups[groupIdx].ids[i] + 0xc0);
        GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
        if (c == NULL) continue;
        if (IsFlag0x18Bit0x2000Set(c)) continue;
        if ((flags & 1) && IsFlag10088Set((struct S_10088*)c)) continue;
        out[count++] = id;
        if (count == maxCount) return count;
    }
    return count;
}
