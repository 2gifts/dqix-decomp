#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

struct Obj021b228c;
typedef int (Obj021b228c::*Handler021b228c)();

extern const Handler021b228c data_020e6d5c;
extern Handler021b228c data_ov017_021d79e0[];

extern int data_ov017_021d83f0;

// USA: func_ov017_021b228c
extern "C" ARM void func_ov017_021b228c(unsigned char* self) {
    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
    if (combatant != NULL) {
        CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    }
    if (!(data_ov017_021d83f0 & 1)) {
        data_ov017_021d79e0[8] = data_020e6d5c;
        data_ov017_021d83f0 |= 1;
    }
    int idx = *(int*)(self + 8);
    if (data_ov017_021d79e0[idx] == 0) return;
    *(int*)(self + 8) = (((Obj021b228c*)self)->*data_ov017_021d79e0[idx])();
}
