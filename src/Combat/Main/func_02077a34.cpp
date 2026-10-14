#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"
#include "Graphics/Vector.h"

extern "C" Vector3fix func_02034104(void* combatant);

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
int CheckField0NonZero(int* obj);

struct Obj02033834;
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int arg);


struct Obj02033b68;
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int newVal);



extern "C" int _s32_div_f(int a, int b);

extern "C" void func_ov017_021c927c(int a, int b, int c, Vector3fix v, int d, int e, int f);

// USA: func_02077a34
extern "C" ARM int func_02077a34(FieldMonsterState* self) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->combatantId);
    if (combatant == 0) {
        return 0;
    }

    int scale = 0;
    self->flags |= 0x40;
    void* g = func_0202ae18();
    if (func_0202c508(g)) {
        Vector3fix posCopy = func_02034104(combatant);
        Vector3fix delta;
        Vector3fix_Subtract(&posCopy, &self->actor.base.object.position_, &delta);
        Vector3fix_Normalize(&delta, &delta);
        scale = fix32_Atan2(delta.x, delta.z);
        _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)self, scale);
        Vector3fixMultiplyScalar(&delta, 0xa000, &delta);
        Vector3fix_Add(&self->actor.base.object.position_, &delta, &self->targetPosition);
    }

    self->actor.base.fieldB4 = 0x1c2;
    self->actor.base.fieldB2 = 0x1c2;
    _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)self, 1);

    int a = battleStruct->GetProtagonist()->obj3D_.GetField06();
    int b = self->actor.base.object.GetField06();
    if (a == b) {
        self->actor.base.object.DisableFlag(0x80);
    }
    self->rising = 0;

    if (CheckField0NonZero((int*)g)) {
        if (func_0202c508(g)) {
            int c1 = self->actor.base.object.GetField06();
            int f2val = self->actor.base.object.unknown_2_;
            Vector3fix* vp = &self->targetPosition;
            int rem = (self->actor.base.object.unknown_4_ - 0x70) % 0xc;
            if (rem >= 0 && rem < 0xc) {
                Vector3fix v = *vp;
                func_ov017_021c927c(c1, rem, f2val, v, scale, 5, self->combatantId);
            }
        }
    }
    return 1;
}
