#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct Obj02033710;
struct MovingObject : Object3D {
    short field_ac, targetHeading, headingSpeed;
    short speed, maximumSpeed, acceleration;
    char paddingb8[6];
    unsigned char state, previousState;
    char paddingc0[3];
    unsigned char delay;
    unsigned short flagsc4;
    short correctionSpeed;
    Vector3fix correctionTarget;
    Vector3fix target;
    unsigned char reserved0 : 2;
    unsigned char paused : 1;
    unsigned char reserved3 : 1;
    unsigned char moving : 1;
    unsigned char teleport : 1;
    unsigned char reserved6 : 2;
};
struct AnimationNext { signed char state; char padding1[12]; };
extern AnimationNext data_020ef9d0[];
void AdvanceFacingAngleTowardTarget(Obj02033710*);
extern "C" void _Z34AdjustPositionTowardTarget02033e38Pv(void*);
extern "C" void func_0203348c(MovingObject*);
extern "C" void func_02033ce8(MovingObject*);
extern "C" void func_020339c8(MovingObject*);

// USA: func_020332ac
extern "C" ARM void func_020332ac(MovingObject* object) {
    if (!object->paused) {
        AdvanceFacingAngleTowardTarget((Obj02033710*)object);
        func_0203348c(object);
        if (object->moving) {
            object->moving = 0;
            if (object->teleport) {
                object->teleport = 0;
                object->position_ = object->target;
            } else {
                Vector3fix difference;
                Vector3fix_Subtract(&object->target, &object->position_, &difference);
                int distance = Vector3fix_Length(&difference);
                if (distance > 0) {
                    GameState* game = GameState::GetInstance();
                    int acceleration = object->acceleration * game->GetTickCount();
                    Vector3fix direction;
                    Vector3fixMultiplyScalar(&difference, fix32_Divide(0x1000, distance), &direction);
                    if (object->speed <= distance) {
                        object->speed += acceleration;
                        if (object->maximumSpeed < object->speed) object->speed = object->maximumSpeed;
                    } else {
                        object->speed -= acceleration;
                        if (object->speed < 0) object->speed = 0;
                    }
                    int speed = object->speed * game->GetTickCount();
                    if (distance < speed) speed = distance;
                    Vector3fix step;
                    Vector3fixMultiplyScalar(&direction, speed, &step);
                    Vector3fix position;
                    Vector3fix_Add(&object->position_, &step, &position);
                    object->position_ = position;
                } else object->speed = 0;
            }
        }
        _Z34AdjustPositionTowardTarget02033e38Pv(object);
        if (object->HasAnimationStopped() || object->HasAnimationReachedEnd()) {
            object->previousState = object->state;
            int state = data_020ef9d0[(short)object->state].state;
            if (state > -1) object->state = state;
            func_02033ce8(object);
        }
    }
    int delay = object->delay;
    if (delay) {
        delay -= GameState::GetInstance()->GetTickCount();
        if (delay < 0) delay = 0;
        object->delay = delay;
    }
    func_020339c8(object);
    object->AdvanceEffects();
}
