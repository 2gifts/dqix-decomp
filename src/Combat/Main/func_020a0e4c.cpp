#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct MoveState020a0e4c {
    int flag_0x0;
    Vector3i pos_0x4;
    Vector3i target_0x10;
    int speed_0x1c;
    int maxSpeed_0x20;
    int accel_0x24;
};

// USA: func_020a0e4c
extern "C" ARM void func_020a0e4c(struct MoveState020a0e4c* obj) {
    float dt = (float)GameState::GetInstance()->GetEffectiveDeltaTime() / 1000.0f;
    int accelStep = (int)(obj->accel_0x24 * dt);
    int speedStep = (int)(obj->speed_0x1c * dt);

    Vector3i dir;
    Vector3fix_Subtract(&obj->target_0x10, &obj->pos_0x4, &dir);
    Vector3fix_Normalize(&dir, &dir);
    int dist = Vector3fix_Distance(&obj->target_0x10, &obj->pos_0x4);

    float sp = (float)speedStep / 4096.0f;
    float num = sp * sp;
    float aa = (float)accelStep / 4096.0f;
    float den = 2.0f * aa;
    float ratio = num / den;

    if (dist < accelStep) {
        obj->pos_0x4 = obj->target_0x10;
        obj->flag_0x0 = 0;
    } else if ((int)(4096.0f * ratio) < dist + 0x199) {
        int step = speedStep + accelStep;
        int newSpeed = (int)(step / dt);
        obj->speed_0x1c = newSpeed;
        int maxSpeed = obj->maxSpeed_0x20;
        if (maxSpeed < newSpeed) {
            obj->speed_0x1c = maxSpeed;
            step = (int)(maxSpeed * dt);
        }
        Vector3i tmp;
        Vector3fixMultiplyScalar(&dir, step, &tmp);
        Vector3fix_Add(&obj->pos_0x4, &tmp, &obj->pos_0x4);
    } else {
        int step = speedStep - accelStep;
        int half = dist / 2;
        if (step > half) {
            step = half;
        }
        obj->speed_0x1c = (int)(step / dt);
        if (step < accelStep) {
            obj->pos_0x4 = obj->target_0x10;
            obj->flag_0x0 = 0;
        } else {
            Vector3i tmp;
            Vector3fixMultiplyScalar(&dir, step, &tmp);
            Vector3fix_Add(&obj->pos_0x4, &tmp, &obj->pos_0x4);
        }
    }
}
