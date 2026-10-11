#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02061bd8;
int CheckField0x56bLowNibble(struct Obj02061bd8* obj);
extern "C" void func_ov017_02190264(void* h, int i);
void ClearCombatantSlot(GameState* battleStruct, int id);
void* GetPtrField0x2a04(GameState* battleStruct);

// JPN: func_ov017_02192068
// USA: func_ov017_02191484  (semantic: ResetCombatantSlotsAndFlags_02191484)
extern "C" ARM void func_ov017_02191484(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x980};
#else
 enum {regionalOffset0=0xba0};
#endif
    GameState* bs = GameState::GetInstance();
    int h = ((int)func_ov017_0218b5b0());
    for (int i = 0; i < 4; i++) {
        GameObject* c = GetCombatantWithFlag0x100(bs, i);
        if (c) {
            if (CheckField0x56bLowNibble((struct Obj02061bd8*)c)) {
                func_ov017_02190264((void*)h, i);
            }
        }
    }
    ClearCombatantSlot(bs, 0xce);
    unsigned char* p = (unsigned char*)GetPtrField0x2a04(bs);
    p[0xf7d] = 0;
    unsigned char* p2 = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    p2[0xb] = 0;
}
