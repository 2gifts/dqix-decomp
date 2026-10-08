#include <globaldefs.h>

struct Vec3_020a0e4c {
    int x;
    int y;
    int z;
};

extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned int _ZNK9GameState21GetEffectiveDeltaTimeEv(void* gs);
extern "C" void Vector3fix_Subtract(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b, struct Vec3_020a0e4c* out);
extern "C" void Vector3fix_Normalize(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b);
extern "C" int Vector3fix_Distance(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b);
extern "C" void Vector3fix_Add(struct Vec3_020a0e4c* a, struct Vec3_020a0e4c* b, struct Vec3_020a0e4c* out);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(struct Vec3_020a0e4c* in, int scale, struct Vec3_020a0e4c* out);

struct MoveState020a0e4c {
    int flag_0x0;
    struct Vec3_020a0e4c pos_0x4;
    struct Vec3_020a0e4c target_0x10;
    int speed_0x1c;
    int maxSpeed_0x20;
    int accel_0x24;
};

// USA: func_020a0e4c
extern "C" ARM void func_020a0e4c(struct MoveState020a0e4c* obj) {
    float dt = (float)_ZNK9GameState21GetEffectiveDeltaTimeEv(_ZN9GameState11GetInstanceEv()) / 1000.0f;
    int accelStep = (int)(obj->accel_0x24 * dt);
    int speedStep = (int)(obj->speed_0x1c * dt);

    struct Vec3_020a0e4c dir;
    Vector3fix_Subtract(&obj->target_0x10, &obj->pos_0x4, &dir);
    Vector3fix_Normalize(&dir, &dir);
    int dist = Vector3fix_Distance(&obj->target_0x10, &obj->pos_0x4);

    float sp = (float)speedStep / 4096.0f;
    float num = sp * sp;
    float aa = (float)accelStep / 4096.0f;
    float den = 2.0f * aa;
    float ratio = num / den;

    if (dist < accelStep) {
        _ZN8Vector3iaSERKS_((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
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
        struct Vec3_020a0e4c tmp;
        _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&dir, step, &tmp);
        Vector3fix_Add(&obj->pos_0x4, &tmp, &obj->pos_0x4);
    } else {
        int step = speedStep - accelStep;
        int half = dist / 2;
        if (step > half) {
            step = half;
        }
        obj->speed_0x1c = (int)(step / dt);
        if (step < accelStep) {
            _ZN8Vector3iaSERKS_((int*)&obj->pos_0x4, (int*)&obj->target_0x10);
            obj->flag_0x0 = 0;
        } else {
            struct Vec3_020a0e4c tmp;
            _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&dir, step, &tmp);
            Vector3fix_Add(&obj->pos_0x4, &tmp, &obj->pos_0x4);
        }
    }
}