#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

extern "C" float _fflt(int v);

struct MovingObjectTimer {
    char padding_00[0x24];
    int remaining;
    int threshold;
    unsigned short step;
};

struct MovingFlags0xc4 {
    unsigned short low : 15;
    unsigned short hi : 1;
};

struct MovingObject : Object3D {
    short field_ac, targetHeading, headingSpeed;
    short speed, maximumSpeed, acceleration;
    char paddingb8[6];
    unsigned char state, previousState;
    char paddingc0;
    unsigned char c1_low : 2;
    unsigned char c1_bit2 : 1;
    unsigned char c1_high : 5;
    unsigned char c2_low : 5;
    unsigned char c2_bit5 : 1;
    unsigned char c2_high : 2;
    unsigned char delay;
    MovingFlags0xc4 flagsC4;
    short correctionSpeed;
    Vector3fix correctionTarget;
    Vector3fix target;
    unsigned char e0_bit0 : 1;
    unsigned char e0_rest : 7;
    char padding_e1[0x1f];
    MovingObjectTimer timer;
};

// USA: func_0203348c
extern "C" ARM void func_0203348c(MovingObject* obj) {
    if (obj->e0_bit0 || obj->c2_bit5 || obj->c1_bit2) {
        return;
    }
    GameState* game = GameState::GetInstance();
    unsigned int delta = game->GetEffectiveDeltaTime();
    int tick = game->GetTickCount();
    int hasLow = obj->flagsC4.low != 0;
    if (hasLow) {
        if (delta >= obj->flagsC4.low) {
            obj->flagsC4.low = 0;
        } else {
            obj->flagsC4.low -= delta;
        }
    }
    int speed = obj->speed;
    int accel = obj->acceleration * tick;
    if (obj->state == 1) {
        if (speed < obj->maximumSpeed) {
            obj->speed = accel + speed;
        } else if (speed - obj->maximumSpeed < accel) {
            obj->speed = obj->maximumSpeed;
        } else {
            obj->speed = speed - accel;
        }
    } else if (speed > 0) {
        obj->speed = speed - accel;
    } else {
        obj->speed = 0;
    }
    int lowPending = obj->flagsC4.low != 0;
    if (lowPending || obj->timer.remaining != 0) {
        speed = 0;
    }
    if (0.0f < _fflt(speed)) {
        int heading = obj->rotation_.y;
        int maxSpeed = obj->maximumSpeed;
        int diff = fix32SignedAngleDistance(heading, obj->targetHeading);
        int absDiff = fix32abs(diff);
        int factor = FIX32_MULTIPLY(maxSpeed, 0x1000 - fix32_Divide(absDiff, 0x3244));
        if (factor < speed) {
            speed = factor;
        }
        speed = speed * tick;
        int angle = heading;
        if (obj->unknown_0_ & 0x100) {
            angle = obj->targetHeading;
        }
        Vector3fix dir;
        dir.x = fix32sin(angle);
        dir.y = 0;
        dir.z = fix32cos(angle);
        Vector3fixMultiplyScalar(&dir, speed, &dir);
        Vector3fix sum;
        Vector3fix_Add(&obj->position_, &dir, &sum);
        obj->position_ = sum;
    }
    Vector3fix pos = obj->position_;
    pos.y = pos.y - obj->field_ac;
    if (pos.y < -0x32000) {
        pos.y = 0x32000;
    }
    obj->position_ = pos;
    if (obj->timer.remaining != 0) {
        obj->timer.step++;
        obj->timer.remaining -= obj->timer.step * 0x51;
        if (obj->timer.remaining < obj->timer.threshold) {
            obj->timer.step = 0;
            obj->timer.remaining = 0;
            obj->timer.threshold = 0;
        }
    }
}
