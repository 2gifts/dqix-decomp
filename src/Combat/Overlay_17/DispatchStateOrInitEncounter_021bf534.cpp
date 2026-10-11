#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

void SetByteField0x253(void* obj);
extern "C" void func_ov017_021bf490(void*);
int GetGlobalField0x1c020421a0();
void CallIfField498_0218d5ac(void* obj);

typedef int (*StateHandler_021bf534)(void*);
struct StateTable_021bf534 { StateHandler_021bf534 f[9]; };
extern StateTable_021bf534 data_ov017_021d6cc4;

struct Obj_021bf534 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2[8];
    unsigned char state;
};

// JPN: func_ov017_021bfae0
// USA: func_ov017_021bf534  (semantic: DispatchStateOrInitEncounter_021bf534)
extern "C" ARM void func_ov017_021bf534(struct Obj_021bf534* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x228};
#else
 enum {regionalOffset0=0x2d8};
#endif
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetUnknownGameObject();
    GameResources* ov = func_ov017_0218b5b0();
    if (ov) {
        CallIfField498_0218d5ac(ov);
    }

    StateTable_021bf534 table = data_ov017_021d6cc4;
    StateHandler_021bf534 handler = table.f[obj->state];
    if (handler) {
        obj->state = (unsigned char)handler(obj);
    } else {
        if (combatant) {
            SetByteField0x253(combatant);
        }
        func_ov017_021bf490(obj);
        obj->field1 = 1;
        *(int*)((char*)GetGlobalField0x1c020421a0() + regionalOffset0) = 0;
    }
}
