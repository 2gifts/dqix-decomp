#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FieldActorState.h"
#include "Graphics/Vector.h"

struct Outer02077a20;
int GetField0x8OrDefault02077a20(struct Outer02077a20* p);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

struct BitFlag02033f44;
int* GetField0xe4IfFlag0x40(struct BitFlag02033f44* self);

void TrySetMode02076ccc(void* self, int mode);
extern "C" void func_020794f8(void* self, int a, int b);

int CheckField0NonZero(int* obj);

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" int func_020322c0(void* p, int* v);
extern "C" Vector3fix func_02034104(void* combatant);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

// USA: func_02077be0
extern "C" ARM void func_02077be0(FieldMonsterState* self) {
    GameState* battleStruct = GameState::GetInstance();
    void* mgr = func_0202ae18();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(self->combatantId);
    if (combatant == NULL) {
        return;
    }

    Vector3fix pos44 = self->actor.base.object.position_;
    pos44.y = 0;
    int flag = 0;
    Vector3fix pos158 = self->targetPosition;
    pos158.y = 0;
    Vector3fix delta;
    Vector3fix_Subtract(&pos158, &pos44, &delta);
    Vector3fix_Normalize(&delta, &delta);
    int angle = fix32_Atan2(delta.x, delta.z);
    SetVecYByMode02033834((struct Obj02033834*)self, angle);
    self->actor.base.fieldB4 = 0x1c2;
    self->actor.base.fieldB2 = 0x1c2;
    SetByteIfChanged02033b68((struct Obj02033b68*)self, 1);

    int* p = GetField0xe4IfFlag0x40((struct BitFlag02033f44*)self);
    if (p != NULL) {
        int v = (short)self->actor.base.fieldAe;
        if (func_020322c0(p, &v) < 0x199) {
            flag = 1;
        }
    }

    if (flag != 0) {
        TrySetMode02076ccc(self, 1);
        self->actor.phaseElapsedTime = 0;
        if (CheckField0NonZero((int*)mgr) == 0) {
            return;
        }
        func_020794f8(self, 0, 0);
        return;
    }

    int dist = Vector3fix_Distance(&pos44, &pos158);
    unsigned short id = self->combatantId;
    if (combatant->obj3D_.unknown_0_ & 0x1000) {
        id = 0;
    }

    if (CheckField0NonZero((int*)mgr) == 0 ||
        id == GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)mgr)) {
        Vector3fix posCopy = func_02034104(combatant);
        int radius = combatant->obj3D_.GetRadius();
        int scale15 = self->actor.base.object.GetScale().x * 15;
        int half = GetField0x8OrDefault02077a20((struct Outer02077a20*)self) >> 1;
        int threshold = (int)(((long long)half * scale15 + 0x800) >> 12) + (radius >> 1);
        int d = Vector3fix_Distance(&posCopy, &self->actor.base.object.position_);
        if (d != 0 && threshold > d) {
            TrySetMode02076ccc(self, 1);
            self->actor.phaseElapsedTime = 0;
            self->unknown17b = 1;
            if (CheckField0NonZero((int*)mgr) != 0) {
                func_020794f8(self, 1, 0);
            }
            return;
        }
    }

    if (CheckField0NonZero((int*)mgr) != 0 &&
        GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)mgr) != 0) {
        return;
    }
    if (dist >= 0x1800 && self->unknown17b == 0) {
        return;
    }
    TrySetMode02076ccc(self, 1);
    self->actor.phaseElapsedTime = 0;
    if (CheckField0NonZero((int*)mgr) == 0) {
        return;
    }
    if (func_0202c508(mgr) == 0) {
        return;
    }
    func_020794f8(self, 0, 0);
}
