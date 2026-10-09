#include <globaldefs.h>
#include "GameState/GameState.h"

struct Combatant021df9f4 {
    char pad0[0xc0];
    unsigned char state;
    char padc1[0x18c - 0xc1];
    unsigned int flags;
};

extern "C" int _Z26CheckHighNibble0xc1Not2To5Ph(GameObject* obj);
extern "C" int _Z23CheckSubstructFlag0x200Ph(GameObject* obj);
extern "C" int _Z23CheckSubstructFlag0x100Ph(GameObject* obj);

// USA: func_ov025_021df9f4
extern "C" ARM int func_ov025_021df9f4(GameObject* obj) {
    if (obj == 0) {
        return 0;
    }
    int result = 0;
    if (obj->obj3D_.IsVisible() && _Z26CheckHighNibble0xc1Not2To5Ph(obj) &&
        !_Z23CheckSubstructFlag0x200Ph(obj)) {
        if (!_Z23CheckSubstructFlag0x100Ph(obj)) {
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
