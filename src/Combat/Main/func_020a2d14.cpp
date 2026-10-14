#include <globaldefs.h>

#include "Graphics/Vector.h"

struct GlobalObj0202e6a8;
struct Obj0202ea4c;
struct Vec3;

struct CamState0202e6c0 {
    int unk0;
    Vector3fix target;
    Vector3fix position;
    char pad1C[0x70 - 0x1C];
    fix32_t yaw;
    fix32_t height;
    fix32_t distance;
    char pad7C[0x218 - 0x7C];
    int mode;
};

int TestFlagMask_02012430(unsigned short* obj, int mask);
void AddWrappedField0x70_0202e784(struct GlobalObj0202e6a8* obj, int val);
int GetField0x78_0202e800(void* obj);
int GetField0x74_0202e7f8(void* obj);
void ClampField74BySign(struct CamState0202e6c0* obj, int value);
void SubtractVec3Fields0202e9f4(void* obj, struct Vec3* v);
void ComputeAngleHeightDistance0202ea4c(struct Obj0202ea4c* obj);
int AddAndClampMin0202e858(void* obj, int n);
void CopyVec3ToField0x10AndCall0202e5d8_0202ec5c(char* obj, int* src);

extern unsigned short data_02114e30;

static inline fix32_t FxMul(fix32_t a, fix32_t b) {
    return (fix32_t)(((int64_t)a * b + 0x800) >> 12);
}

static inline void SetCameraPlacement(struct CamState0202e6c0* cam, const Vector3fix* position, const Vector3fix* target) {
    cam->position = *position;
    ComputeAngleHeightDistance0202ea4c((struct Obj0202ea4c*)cam);
    cam->target = *target;
}

// USA: func_020a2d14
extern "C" ARM void func_020a2d14(struct CamState0202e6c0* cam) {
    int pressA;
    int pressB;
    int pressX;
    int pressY;
    int pressL;
    int pressR;
    int pressUp;
    int pressDown;
    int pressLeft;
    int pressRight;
    int slow;
    float speed;
    float scale;
    int moved;
    fix32_t angle;

    if (cam->mode == 0) {
        return;
    }

    Vector3fix pos = cam->position;
    pressA = TestFlagMask_02012430(&data_02114e30, 1);
    pressB = TestFlagMask_02012430(&data_02114e30, 2);
    pressX = TestFlagMask_02012430(&data_02114e30, 0x400);
    pressY = TestFlagMask_02012430(&data_02114e30, 0x800);
    pressL = TestFlagMask_02012430(&data_02114e30, 0x200);
    pressR = TestFlagMask_02012430(&data_02114e30, 0x100);
    pressUp = TestFlagMask_02012430(&data_02114e30, 0x40);
    pressDown = TestFlagMask_02012430(&data_02114e30, 0x80);
    pressLeft = TestFlagMask_02012430(&data_02114e30, 0x20);
    pressRight = TestFlagMask_02012430(&data_02114e30, 0x10);
    slow = TestFlagMask_02012430(&data_02114e30, 8);
    speed = 1.0f;
    if (slow) {
        speed = 0.1f;
    }

    if (cam->mode == 2 && pressX == 0 && pressY == 0) {
        return;
    }

    if ((cam->mode == 1 && pressR == 0 && cam->mode == 1 && pressL == 0) || (cam->mode == 2 && pressY == 0)) {
        if (pressLeft) {
            AddWrappedField0x70_0202e784((struct GlobalObj0202e6a8*)cam, -(int)(4096.0f * (0.05f * speed)));
        }
        if (pressRight) {
            AddWrappedField0x70_0202e784((struct GlobalObj0202e6a8*)cam, (int)(4096.0f * (0.05f * speed)));
        }
        if (pressUp) {
            fix32_t dist = GetField0x78_0202e800(cam);
            fix32_t height = GetField0x74_0202e7f8(cam);
            fix32_t heightSq = FxMul(height, height);
            fix32_t distSq = FxMul(dist, dist);
            fix32_t horiz = fix32_Sqrt(distSq - heightSq);
            Vector3fix v = {horiz, height, 0};
            Matrix4x3 m = RotationMatrixZ((int)(178.72223f * speed));
            Mat4x3_ApplyToVector(&v, &m, &v);
            ClampField74BySign(cam, v.y);
        }
        if (pressDown) {
            fix32_t dist = GetField0x78_0202e800(cam);
            fix32_t height = GetField0x74_0202e7f8(cam);
            fix32_t heightSq = FxMul(height, height);
            fix32_t distSq = FxMul(dist, dist);
            fix32_t horiz = fix32_Sqrt(distSq - heightSq);
            Vector3fix v = {horiz, height, 0};
            Matrix4x3 m = RotationMatrixZ(fix32ReduceAngle0To2Pi((int)(-178.72223f * speed)));
            Mat4x3_ApplyToVector(&v, &m, &v);
            ClampField74BySign(cam, v.y);
        }
    }

    scale = (float)GetField0x78_0202e800(cam) / 10.0f / 4096.0f;
    moved = 0;

    if ((cam->mode == 1 && pressR) || (cam->mode == 2 && pressY)) {
        Vector3fix dir;
        SubtractVec3Fields0202e9f4(cam, (struct Vec3*)&dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, (int)(4096.0f * (0.2f * speed * scale)), &dir);
        angle = 0;
        if (pressUp && pressLeft) {
            angle = 0xC91;
            moved = 1;
        } else if (pressUp && pressRight) {
            angle = 0x57F7;
            moved = 1;
        } else if (pressDown && pressLeft) {
            angle = 0x25B3;
            moved = 1;
        } else if (pressDown && pressRight) {
            angle = 0x3ED5;
            moved = 1;
        } else if (pressUp) {
            moved = 1;
        } else if (pressDown) {
            angle = 0x3244;
            moved = 1;
        } else if (pressLeft) {
            angle = 0x1922;
            moved = 1;
        } else if (pressRight) {
            angle = 0x4B66;
            moved = 1;
        }
        if (moved) {
            Matrix4x3 m = RotationMatrixY(angle);
            Mat4x3_ApplyToVector(&dir, &m, &dir);
            Vector3fix_Add(&pos, &dir, &pos);
        }
    }

    if (cam->mode == 1 && pressL) {
        Vector3fix dir;
        Vector3fix newPos = pos;
        int changed;
        fix32_t step;
        SubtractVec3Fields0202e9f4(cam, (struct Vec3*)&dir);
        dir.y = 0;
        Vector3fix_Normalize(&dir, &dir);
        Vector3fixMultiplyScalar(&dir, (int)(4096.0f * (0.2f * speed * scale)), &dir);
        angle = 0;
        if (pressUp && pressLeft) {
            angle = 0xC91;
            moved = 1;
        } else if (pressUp && pressRight) {
            angle = 0x57F7;
            moved = 1;
        } else if (pressDown && pressLeft) {
            angle = 0x25B3;
            moved = 1;
        } else if (pressDown && pressRight) {
            angle = 0x3ED5;
            moved = 1;
        } else if (pressUp) {
            moved = 1;
        } else if (pressDown) {
            angle = 0x3244;
            moved = 1;
        } else if (pressLeft) {
            angle = 0x1922;
            moved = 1;
        } else if (pressRight) {
            angle = 0x4B66;
            moved = 1;
        }
        if (moved) {
            Matrix4x3 m = RotationMatrixY(angle);
            Mat4x3_ApplyToVector(&dir, &m, &dir);
            Vector3fix_Add(&newPos, &dir, &newPos);
            SetCameraPlacement(cam, &newPos, &cam->target);
            return;
        }
        changed = 0;
        step = (int)(4096.0f * (0.2f * speed * scale));
        if (pressX) {
            newPos.y += step;
            changed = 1;
        }
        if (pressY) {
            newPos.y -= step;
            changed = 1;
        }
        if (changed) {
            SetCameraPlacement(cam, &newPos, &cam->target);
            return;
        }
    }

    if (cam->mode == 1) {
        fix32_t step = (int)(4096.0f * (0.3f * speed * scale));
        if (pressA) {
            AddAndClampMin0202e858(cam, step);
        }
        if (pressB) {
            AddAndClampMin0202e858(cam, -step);
        }
    }

    if (cam->mode == 1) {
        fix32_t step = (int)(4096.0f * (0.2f * speed * scale));
        if (pressX) {
            pos.y += step;
        }
        if (pressY) {
            pos.y -= step;
        }
    }

    if (cam->mode == 2 && moved == 0) {
        fix32_t move = (int)(4096.0f * (0.2f * speed * scale));
        fix32_t zoom = (int)(4096.0f * (0.3f * speed * scale));
        if (pressY && pressR) {
            pos.y += move;
        } else if (pressY && pressL) {
            pos.y -= move;
        } else if (pressR) {
            AddAndClampMin0202e858(cam, zoom);
        } else if (pressL) {
            AddAndClampMin0202e858(cam, -zoom);
        }
    }

    CopyVec3ToField0x10AndCall0202e5d8_0202ec5c((char*)cam, (int*)&pos);
}
