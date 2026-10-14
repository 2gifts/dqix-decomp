#include <globaldefs.h>
#include "GameState/GameState.h"

struct Combatant021df9f4 {
    char pad0[0xc0];
    unsigned char state;
#if defined(jpn)
    char padc1[0x180 - 0xc1];
#else
    char padc1[0x18c - 0xc1];
#endif
    unsigned int flags;
};

int CheckHighNibble0xc1Not2To5(unsigned char*);
int CheckSubstructFlag0x200(unsigned char*);
int CheckSubstructFlag0x100(unsigned char*);

// USA: func_ov025_021df9f4
extern "C" ARM int func_ov025_021df9f4(GameObject* obj) {
    if (obj == 0) {
        return 0;
    }
    int result = 0;
    if (obj->obj3D_.IsVisible() && CheckHighNibble0xc1Not2To5((unsigned char*)obj) &&
        !CheckSubstructFlag0x200((unsigned char*)obj)) {
        if (!CheckSubstructFlag0x100((unsigned char*)obj)) {
            result = 1;
        }
    }
    bool isParty = false;
    if (obj->obj3D_.unknown_4_ >= 0 && obj->obj3D_.unknown_4_ <= 3) {
        isParty = true;
    }
    if (isParty) {
        GameState* gs = GameState::GetInstance();
        Combatant021df9f4* c = (Combatant021df9f4*)GetCombatantWithFlag0x100(gs, obj->obj3D_.unknown_4_);
        if (c != 0 && ((c->flags & 1) || c->state == 8)) {
            result = 0;
        }
    }
    return result;
}
