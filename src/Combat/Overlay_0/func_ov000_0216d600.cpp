#include <globaldefs.h>
#include "System/Matrix.h"

struct Vec3Ints0216d368 : Vector3i {};
struct AngleTrig0202e9a4 {
    unsigned int angle;
    Vector3i eye;
    Vector3i target;
    unsigned char padding[0x220 - 0x1c];
    unsigned char mode;
    unsigned char padding221[7];
    int frontWidth, frontHeight, backWidth, backHeight;
    int duration, targetDuration;
    Vector3i savedEye, savedTarget;
    int field258;
};
struct CombatWorkD600 {
    unsigned char padding[0x77f0];
    int overrideIndex;
    Vector3i eye, target;
};
extern "C" void func_ov000_0216d370(AngleTrig0202e9a4*, int, int, int);
extern "C" void _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(AngleTrig0202e9a4*, int);
extern "C" void _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(Vec3Ints0216d368*, int, int, int);
CombatWorkD600* GetActiveCombatWork();
extern "C" void func_0202eab8(AngleTrig0202e9a4*);
extern "C" int func_ov000_0216f210(AngleTrig0202e9a4*, int*);

static inline int MultiplyFixedD600(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov000_0216d600
extern "C" ARM void func_ov000_0216d600(AngleTrig0202e9a4* camera, int side, int close, int mode, float x, float y, float z, unsigned char overridePosition) {
    func_ov000_0216d370(camera, 1, 1, 1);
    camera->mode = 2;
    int width, height;
    if (side == 0) { width = camera->frontWidth; height = camera->frontHeight; }
    else { width = camera->backWidth; height = camera->backHeight; }
    int scale, factor;
    if (close == 0) { scale = 0x424; factor = scale + 0xb50; }
    else {
        _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(camera, 0x16000);
        scale = 0x5fe;
        factor = 0xed6;
    }
    width = MultiplyFixedD600(width, factor);
    int distance = fix32_Divide(width, (int)(2.2f * (float)scale)) - 0x2800;
    int scaledHeight = MultiplyFixedD600(height, factor);
    int heightDistance = fix32_Divide(scaledHeight, (int)(1.5f * (float)scale)) - 0x2800;
    if (heightDistance >= distance) distance = heightDistance;
    int minimum = 0x6800;
    if (close != 0) minimum = 0x3000;
    if (distance < minimum) distance = minimum;
    height /= 2;
    if (height < 0x1333) height = 0x1333;
    Vec3Ints0216d368 eye, target;
    int result;
    _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(&eye, 0, height, distance);
    _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(&target, 0, height, 0);
    if (eye.y > 0x2000) eye.y = 0x2000;
    if (close == 0) {
        if (mode == 1) eye.y += 0x1000;
        else if (mode == 2) {
            eye.x += (int)(4096.0f * x);
            eye.y += (int)(4096.0f * y);
            eye.z += (int)(4096.0f * z);
        } else if (mode == 3) {
            camera->duration = 28;
            camera->targetDuration = 20;
            eye.x += (int)(4096.0f * x);
            eye.y += (int)(4096.0f * y);
            eye.z += (int)(4096.0f * z);
        }
    }
    if (overridePosition) {
        CombatWorkD600* work = GetActiveCombatWork();
        if (work && work->overrideIndex != -1) {
            _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(&eye, work->eye.x, work->eye.y, work->eye.z);
            _Z22StoreVec3Words0216d368P16Vec3Ints0216d368iii(&target, work->target.x, work->target.y, work->target.z);
        }
    }
    if (side == 0) { eye.z = -eye.z; target.z = -target.z; }
    camera->eye = eye;
    camera->target = target;
    func_0202eab8(camera);
    camera->savedEye = eye;
    camera->savedTarget = target;
    camera->field258 = func_ov000_0216f210(camera, &result);
}
