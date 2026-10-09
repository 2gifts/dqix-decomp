#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _Z20GetSubstructByte0x56Ph(GameObject* obj);
extern "C" int _Z22CheckSubstructFlag0x80Ph(GameObject* obj);
extern "C" int _Z20GetSubstructByte0x1cPh(GameObject* obj);
extern "C" int _Z23CheckSubstructFlag0x100Ph(GameObject* obj);

// USA: func_ov025_021e1f40
extern "C" ARM int func_ov025_021e1f40(GameObject* obj, int targetId) {
    if (_Z20GetSubstructByte0x56Ph(obj) == 0) {
        return 0;
    }
    if (targetId == obj->obj3D_.unknown_4_) {
        return 0;
    }
    if (_Z22CheckSubstructFlag0x80Ph(obj)) {
        return 0;
    }
    if (_Z20GetSubstructByte0x1cPh(obj) == 0xff) {
        return 0;
    }
    if (_Z23CheckSubstructFlag0x100Ph(obj)) {
        return 0;
    }
    int party = 0;
    if (obj->obj3D_.unknown_4_ >= 0 && obj->obj3D_.unknown_4_ <= 3) {
        party = 1;
    }
    if (party) {
        GameState* gs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x100(gs, obj->obj3D_.unknown_4_);
        if (c != NULL && (*(unsigned int*)((char*)c + 0x18c) & 1)) {
            return 0;
        }
    }
    return 1;
}
