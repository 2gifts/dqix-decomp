#include <globaldefs.h>

#include "GameState/GameState.h"
#include "Graphics/Animation3D.h"
#include "Graphics/Vector.h"
#include "World/ZoneResourceTree.h"

struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *, int, int);
int IsAnimationActive0209ca2c(void *);

extern char data_02108760[];
extern char data_02109bf4[];
extern char data_020ef1f3[];
extern char data_020ef1f8[];
extern char data_020ef1fe[];
extern char data_020ef204[];

// USA: func_02015554
extern "C" ARM void func_02015554(void *receiver, void *element) {
    ZoneResourceRuntimeNode *entry = static_cast<ZoneResourceRuntimeNode *>(element);
    GameState *state               = GameState::GetInstance();
    Struct02012ff0 *animations     = entry->tracker;
    if (!animations || !animations->field4) return;
    fix32_t delta = state->GetAnimationDeltaTime();
    if (animations->field0 == 0) {
        if (animations->field8) reinterpret_cast<Animation3D *>(animations->field8)->AdvanceTimer(delta);
        if (animations->fieldc) reinterpret_cast<Animation3D *>(animations->fieldc)->AdvanceTimer(delta);
        if (animations->field10) reinterpret_cast<Animation3D *>(animations->field10)->AdvanceTimer(delta);
        if (animations->field14) reinterpret_cast<Animation3D *>(animations->field14)->AdvanceTimer(delta);

        short angle = entry->angle;
        if (angle != fix32ReduceAngle0To2Pi(entry->targetAngle)) {
            fix32_t distance = fix32SignedAngleDistance(angle, entry->targetAngle);
            fix32_t step     = ((long long) entry->rotationSpeed * delta + 0x800) >> 12;
            if (distance > 0) {
                if (distance < step)
                    entry->angle = entry->targetAngle;
                else
                    entry->angle += step;
            } else if (distance < 0) {
                if (-distance < step)
                    entry->angle = entry->targetAngle;
                else
                    entry->angle -= step;
            }
            entry->angle = fix32ReduceAngle0To2Pi(entry->angle);
        } else if (entry->rotationSpeed != 0) {
            if (entry->flags & 0x10) {
                entry->rotationSpeed = 0;
            } else if (entry->flags & 0x80) {
                entry->flags &= ~0x80;
                entry->rotationSpeed = 0;
            } else if (entry->remaining > 0) {
                int remaining = entry->remaining - 3;
                if (remaining < 0) {
                    remaining            = 0;
                    entry->rotationSpeed = 0;
                }
                entry->remaining = remaining;
                if (entry->remaining == 0) entry->flags |= 4;
            }
        }
        if (entry->movementSpeed != 0) {
            if (Vector3fix_Distance(&entry->position, &entry->targetPosition) < entry->movementSpeed) {
                entry->position      = entry->targetPosition;
                entry->movementSpeed = 0;
            } else {
                Vector3fix step = entry->direction;
                Vector3fixMultiplyScalar(&step, entry->movementSpeed, &step);
                Vector3fix_Add(&entry->position, &step, &entry->position);
            }
        }
    }
    if ((entry->flags & 0x100) && entry->object) {
        if (entry->animationState == 0) {
            entry->object->SetAnimationPlaybackSpeed(0x1800, 0);
            if (entry->object->MaybeSetRegularAnimation(data_020ef1f3, 1))
                DispatchWithShortB4_0205eaa0(reinterpret_cast<Obj0205eaa0 *>(data_02108760), 0x12, 0);
            else if (entry->object->MaybeSetRegularAnimation(data_020ef1f8, 1))
                DispatchWithShortB4_0205eaa0(reinterpret_cast<Obj0205eaa0 *>(data_02108760), 0x62, 0);
            entry->animationState = 1;
        } else if (entry->animationState == 1) {
            if (entry->object->HasAnimationStopped()) {
                entry->delay          = 500;
                entry->animationState = 2;
            }
        } else if (entry->animationState == 2) {
            unsigned int deltaTime = state->GetEffectiveDeltaTime();
            if (deltaTime < entry->delay) {
                entry->delay -= deltaTime;
            } else if (!IsAnimationActive0209ca2c(data_02109bf4)) {
                if (entry->object->MaybeSetRegularAnimation(data_020ef1fe, 5))
                    DispatchWithShortB4_0205eaa0(reinterpret_cast<Obj0205eaa0 *>(data_02108760), 0x13, 0);
                else if (entry->object->MaybeSetRegularAnimation(data_020ef204, 5))
                    DispatchWithShortB4_0205eaa0(reinterpret_cast<Obj0205eaa0 *>(data_02108760), 0x62, 0);
                entry->flags &= ~0x100;
            }
        }
    }
}
