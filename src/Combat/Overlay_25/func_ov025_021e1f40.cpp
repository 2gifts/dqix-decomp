#include <globaldefs.h>
#include "GameState/GameState.h"

int GetSubstructByte0x56_02049ee8(unsigned char*);
int CheckSubstructFlag0x80_02048bd0(unsigned char*);
int GetSubstructByte0x1c_020493a4(unsigned char*);
int CheckSubstructFlag0x100_02048c68(unsigned char*);

// USA: func_ov025_021e1f40
extern "C" ARM int func_ov025_021e1f40(GameObject* obj, int targetId) {
#if defined(jpn)
 enum {regionalOffset0=0x180};
#else
 enum {regionalOffset0=0x18c};
#endif
    if (GetSubstructByte0x56_02049ee8((unsigned char*)obj) == 0) {
        return 0;
    }
    if (targetId == obj->obj3D_.unknown_4_) {
        return 0;
    }
    if (CheckSubstructFlag0x80_02048bd0((unsigned char*)obj)) {
        return 0;
    }
    if (GetSubstructByte0x1c_020493a4((unsigned char*)obj) == 0xff) {
        return 0;
    }
    if (CheckSubstructFlag0x100_02048c68((unsigned char*)obj)) {
        return 0;
    }
    int party = 0;
    if (obj->obj3D_.unknown_4_ >= 0 && obj->obj3D_.unknown_4_ <= 3) {
        party = 1;
    }
    if (party) {
        GameState* gs = GameState::GetInstance();
        GameObject* c = GetCombatantWithFlag0x100_0200ff1c(gs, obj->obj3D_.unknown_4_);
        if (c != NULL && (*(unsigned int*)((char*)c + regionalOffset0) & 1)) {
            return 0;
        }
    }
    return 1;
}
