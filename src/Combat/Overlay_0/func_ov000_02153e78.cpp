#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
int IsFlag10088Set(struct S_10088* obj);
int IsFlag0x18Bit0x2000Set(GameObject* combatant);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);

struct Combatant_02153e78 {
    char pad0[0x17c];
    unsigned char side;
};

struct CombatGroup_02153e78 {
    char pad0[2];
    unsigned char memberIds[8];
    unsigned char memberCount : 4;
    char padB[0x18 - 0xb];
};

struct Battle_02153e78 {
    char pad0[0x81b1];
    unsigned char : 4;
    unsigned char groupCount : 2;
    char pad81b2[0x81b4 - 0x81b2];
    struct CombatGroup_02153e78 groups[1];
};

// USA: func_ov000_02153e78
extern "C" ARM int func_ov000_02153e78(struct Battle_02153e78* battle, short* out, int max, int side, int flags) {
    GameState* bs = GameState::GetInstance();
    int found = 0;
    struct CombatGroup_02153e78* groups = battle->groups;
    int g;
    for (g = 0; g < battle->groupCount; g++) {
        unsigned char* ids = groups[g].memberIds;
        int i;
        for (i = 0; i < groups[g].memberCount; i++) {
            GameObject* c = GetCombatantWithFlag0x400(bs, ids[i] + 0xc0);
            if (c == NULL) continue;
            if (side != ((struct Combatant_02153e78*)c)->side) continue;
            if (!(flags & 0x10) && IsFlag0x18Bit0x2000Set(c)) continue;
            if ((flags & 1) && IsFlag10088Set((struct S_10088*)c)) continue;
            out[found] = ids[i] + 0xc0;
            found++;
            if (found == max) return found;
        }
    }
    return found;
}
