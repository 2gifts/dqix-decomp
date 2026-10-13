#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/FormationPosition.h"
#include "Graphics/Vector.h"
#include "std_library_functions.h"

struct MovementState0204956c {
    unsigned char padding_0x0[0x20];
    unsigned int flags;
    unsigned char padding_0x24[0x2a];
    unsigned char direction, remaining;
    short speed;
    unsigned short delay;
    unsigned char iteration, field_0x55, enabled;
};
struct MovementActor0204956c { GameObject base; MovementState0204956c* state; };
struct ClipState0204956c { Vector3i start, end; int radius; unsigned char enabled; };
struct S_10088;
struct Obj020494c0;
int CheckSubstructFlag0x100(unsigned char*);
int IsFlag10088Set(S_10088*);
void ClearSubstructFlag0x4(unsigned char*);
int GetSubstructByte0x56(unsigned char*);
int GetByteWithFallback(unsigned char*);
int GetSubstructByte0x1c(unsigned char*);
extern "C" void _Z26DispatchTargetByte020494c0P11Obj020494c0(Obj020494c0*);
extern "C" int func_02031468(Vector3i*, Vector3i*, Vector3i*, Vector3i*);
extern "C" ClipState0204956c data_02107850;
namespace ClipAlias0204956c { extern "C" ClipState0204956c data_02107850; }
extern const Vector3i data_020e7b3c;
extern const Vector3i data_020e7b30;
struct DelayTable0204956c { int values[3]; };
extern const DelayTable0204956c data_020e7b54;
extern const char data_020f01a4[];
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);

static inline Vec2_0216f74c FormationPosition0204956c(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_0204956c
extern "C" ARM void func_0204956c(MovementActor0204956c* actor) {
    unsigned char* bytes = reinterpret_cast<unsigned char*>(actor);
    if (!(actor->state->flags & 4)) return;
    if (!actor->state->enabled || CheckSubstructFlag0x100(bytes) || IsFlag10088Set(reinterpret_cast<S_10088*>(actor))) {
        ClearSubstructFlag0x4(bytes);
        return;
    }
    if (!GetSubstructByte0x56(bytes)) return;
    GameState* game = GameState::GetInstance();
    MovementState0204956c* state = actor->state;
    Object3D* object = &actor->base.obj3D_;
    if (state->delay) {
        int elapsed = game->GetEffectiveDeltaTime();
        if (elapsed < state->delay) {
            state->delay -= elapsed;
            return;
        }
        state->delay = 0;
    }
    if (!state->remaining) {
        int actorId = object->unknown_4_;
        int selection = actorId + GetByteWithFallback(bytes) + state->iteration;
        int targetId = GetByteWithFallback(bytes);
        if (targetId == 0xff) { ClearSubstructFlag0x4(bytes); return; }
        GameObject* target = game->GetCombatantByIndex(targetId);
        if (!target) { ClearSubstructFlag0x4(bytes); return; }
        ClipState0204956c* clip = &ClipAlias0204956c::data_02107850;
        if (data_02107850.enabled) {
            Vector3i start = clip->start;
            Vector3i end = clip->end;
            Vector3i position = object->position_;
            Vector3i closest;
            int distance = func_02031468(&start, &end, &position, &closest);
            if (distance < clip->radius + (object->GetRadius() >> 1) + 0x2000) {
                ClearSubstructFlag0x4(bytes);
                return;
            }
        }
        Vec2_0216f74c formation = FormationPosition0204956c(GetSubstructByte0x1c(bytes));
        Vector3i origin = data_020e7b3c;
        origin.x = formation.x;
        origin.z = formation.y;
        Vector3i targetPosition = target->obj3D_.position_;
        Vector3i position = object->position_;
        Vector3i fromOrigin, toTarget;
        Vector3fix_Subtract(&position, &origin, &fromOrigin);
        Vector3fix_Subtract(&targetPosition, &origin, &toTarget);
        Vector3fix_Normalize(&fromOrigin, &fromOrigin);
        Vector3fix_Normalize(&toTarget, &toTarget);
        int parity = selection % 2;
        if (parity) {
            if (Vector3fix_InnerProduct(&fromOrigin, &toTarget) > 0) state->direction = 1;
            else state->direction = 0;
        } else {
            Vector3i cross;
            Vector3fix_CrossProduct(&fromOrigin, &toTarget, &cross);
            if (cross.y > 0) state->direction = 2;
            else state->direction = 3;
        }
        state->remaining = parity + 1;
        BCFG::AnimationRecord* animation = object->GetLoadedAnimationRecord(data_020f01a4);
        if (animation) {
            unsigned int frames = (unsigned int)((float)fix32_Divide(animation->endTime - animation->startTime, animation->frameRate) / 4096.0f);
            state->speed = 0xc00 / (frames * 17);
        }
        object->MaybeSetRegularAnimation(data_020f01a4, 1);
        _Z26DispatchTargetByte020494c0P11Obj020494c0(reinterpret_cast<Obj020494c0*>(actor));
        return;
    }
    int targetId = GetByteWithFallback(bytes);
    if (targetId == 0xff) { ClearSubstructFlag0x4(bytes); return; }
    GameObject* target = game->GetCombatantByIndex(targetId);
    if (!target) { ClearSubstructFlag0x4(bytes); return; }
    Vector3i position = object->position_;
    Vector3i targetPosition = target->obj3D_.position_;
    Vector3i direction;
    Vector3fix_Subtract(&targetPosition, &position, &direction);
    Vector3i up = data_020e7b30;
    switch (state->direction) {
    case 0: Vector3fix_Normalize(&direction, &direction); break;
    case 1:
        Vector3fixMultiplyScalar(&direction, -0x1000, &direction);
        Vector3fix_Normalize(&direction, &direction);
        break;
    case 2:
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix_CrossProduct(&direction, &up, &direction);
        Vector3fixMultiplyScalar(&direction, -0x1000, &direction);
        break;
    case 3:
        Vector3fix_Normalize(&direction, &direction);
        Vector3fix_CrossProduct(&direction, &up, &direction);
        break;
    default: ClearSubstructFlag0x4(bytes); break;
    }
    int elapsed = game->GetEffectiveDeltaTime();
    Vector3i delta;
    Vector3fixMultiplyScalar(&direction, state->speed * elapsed, &delta);
    Vector3fix_Add(&position, &delta, &position);
    object->position_ = position;
    if (object->HasAnimationStopped()) {
        --state->remaining;
        if (!state->remaining) {
            int actorId = object->unknown_4_;
            int selection = actorId + GetByteWithFallback(bytes) + state->iteration;
            DelayTable0204956c delays = data_020e7b54;
            state->delay = delays.values[selection % 3];
            ++state->iteration;
        } else {
            object->StopCurrentAnimation();
            object->MaybeSetRegularAnimation(data_020f01a4, 1);
            _Z26DispatchTargetByte020494c0P11Obj020494c0(reinterpret_cast<Obj020494c0*>(actor));
        }
    } else if (object->activeAnimationRecord_ && strcmp(object->activeAnimationRecord_->name, data_020f01a4)) {
        ClearSubstructFlag0x4(bytes);
    }
}
