#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void EnqueueEventTag36_021d2c34(unsigned char a, unsigned char b, unsigned char c);

struct Obj020a8c4c {
    char pad0[4];
    unsigned char f4;
    char pad5[7];
    int fc;
};

// USA: func_020a8c4c  (semantic: SetOrClearAxisFlagAndNotify_020a8c4c)
extern "C" ARM void func_020a8c4c(struct Obj020a8c4c* obj, unsigned char axis) {
    if ((obj->f4 & (1 << axis)) != 0) {
        return;
    }
    GameState* battle = GameState::GetInstance();
    void* ov = func_ov017_0218b5b0();
    GameObject* c397c = battle->GetUnknownGameObject();
    GameObject* c800 = battle->GetPartyMemberByIndex(axis);
    GetPtrField0x2a04_02010828(battle);
    if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)ov, 0) == 0) {
        CancelPendingAction020397cc((struct Obj020397cc*)c800, 1);
        *(short*)((char*)c800 + 0xac) = 0;
        if (axis == *(short*)((char*)c397c + 4)) {
            return;
        }
        EnqueueEventTag36_021d2c34(axis, 0, 0);
        return;
    }
    obj->f4 |= (1 << axis);
    *(short*)((char*)c800 + 0xac) = -obj->fc;
    *(unsigned char*)((char*)c800 + 0xc1) |= 8;
}
