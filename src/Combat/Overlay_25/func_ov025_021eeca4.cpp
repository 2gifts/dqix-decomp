#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033874;
void SetVecYFromValue02033874(struct Obj02033874* obj, int arg);

struct RotateTask021eeca4 {
    char pad0[8];
    unsigned short combatantIndex;
    unsigned short timeRemaining;
    short targetAngle;
};

// USA: func_ov025_021eeca4
extern "C" ARM int func_ov025_021eeca4(struct RotateTask021eeca4* task) {
    GameState* gs = GameState::GetInstance();
    unsigned int dt = gs->GetEffectiveDeltaTime();
    GameObject* c = gs->GetCombatantByIndex(task->combatantIndex);
    if (task->timeRemaining <= dt) {
        SetVecYFromValue02033874((struct Obj02033874*)c, task->targetAngle);
        return 1;
    }
    fix32_t angle = c->obj3D_.rotation_.y;
    float diff = fix32SignedAngleDistance(angle, task->targetAngle);
    float t = (float)dt / (float)task->timeRemaining;
    SetVecYFromValue02033874((struct Obj02033874*)c, fix32ReduceAngle0To2Pi(angle + (int)(diff * t)));
    task->timeRemaining -= dt;
    return 0;
}
