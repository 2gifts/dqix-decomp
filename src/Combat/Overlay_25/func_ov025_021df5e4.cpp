#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"
#include "GameState/GameState.h"

void StoreVec3AtField0x50(unsigned char* object, int x, int y, int z);

struct Mover021df5e4 {
    Object3D body;
    Object3D shadow;
    Vector3fix direction;
    Vector3fix start;
    int arrived;
    unsigned char sourceIndex;
    unsigned char targetIndex;
    unsigned char work[0x14];
    unsigned char steps;
    unsigned char step;
};

// USA: func_ov025_021df5e4
extern "C" ARM void func_ov025_021df5e4(Mover021df5e4* self, int source, int target) {
    GameState* gs = GameState::GetInstance();
    self->sourceIndex = source;
    self->targetIndex = target;
    GameObject* src = gs->GetGameObjectByIndex(self->sourceIndex);
    GameObject* dst = gs->GetGameObjectByIndex(self->targetIndex);
    if (src == 0 || dst == 0) return;
    Vector3fix from = src->obj3D_.position_;
    from.y = 0;
    Vector3fix to = dst->obj3D_.position_;
    to.y = 0;
    fix32_t speed = 0xc00;
    fix32_t dist = Vector3fix_Distance(&from, &to);
    fix32_t radius = src->obj3D_.GetRadius();
    if (dist < radius) return;
    Vector3fix_Subtract(&to, &from, &self->direction);
    Vector3fix_Normalize(&self->direction, &self->direction);
    Vector3fix offset;
    Vector3fixMultiplyScalar(&self->direction, radius >> 1, &offset);
    Vector3fix_Add(&from, &offset, &self->start);
    fix32_t len = Vector3fix_Distance(&self->start, &to);
    self->steps = (int)((float)fix32_Divide(len, speed) / 4096.0f) + 1;
    if (self->steps > 10) {
        speed = fix32_Divide(len, 0xa000);
        self->steps = 10;
    }
    fix32_t angle = fix32ReduceAngle0To2Pi(fix32_Atan2(self->direction.x, self->direction.z));
    StoreVec3AtField0x50((unsigned char*)&self->body, 0, angle, 0);
    StoreVec3AtField0x50((unsigned char*)&self->shadow, 0, angle, 0);
    Vector3fixMultiplyScalar(&self->direction, speed, &self->direction);
    self->step = 0;
    memset(self->work, 0, 0x14);
    if (self->steps != 0) self->arrived = 0;
}
