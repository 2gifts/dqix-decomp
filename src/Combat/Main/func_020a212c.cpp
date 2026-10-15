#include <globaldefs.h>
#include "System/Matrix.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"

struct CameraDispatch {
    int active;
    Vector3i result;
    Vector3i source;
};

struct BattleCamera {
    char pad0[0x10];
    Vector3i eye;
    char pad1c[0x70 - 0x1c];
    Vector3i target;
    char pad7c[0x21c - 0x7c];
    short followIndex;
    char pad21e[2];
    Vector3i angles;
    Vector3i offset;
    int controlActive;
    int enabledA;
    int enabledB;
    unsigned char flags244;
    unsigned char flags245;
    short homeAngle;
    CameraDispatch dispatch;
    char pad264[0x2c4 - 0x264];
    unsigned char zoomMode;
    char pad2c5;
    short zoom;
};

GameResources* GetWord0x0_0200fb8c(int* obj);
int GetField0x70_0202e7f0(void* obj);
int TestFlagMask_02012430(unsigned short* pad, int mask);
int IsBrightnessTransitionActive(GameResources* resources);
int IsChannelValueZero0203b5e0(void* resources, int axis);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
int fix32ReduceAngle0To2Pi(int angle);
void ApplyField0x70Tail(struct GlobalObj0202e6a8* obj, int value);
void ClampField74BySign(struct CamState0202e6c0* obj, int value);
void SetField78Clamped0202e71c(struct Obj0202e71c* obj, int value);
int CheckField0NonZero020a10a8(int* obj);
void DispatchMemberFn020a0dec(struct DispatchObj020a0dec* obj);
void CopyVec3ToField0x10AndCall0202e5d8_0202ec5c(char* obj, int* vec);
void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void __clear(void* ptr, int size);
extern "C" void Vector3fix_Add(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" void Vector3fix_Subtract(const Vector3i* a, const Vector3i* b, Vector3i* out);
extern "C" int Vector3fix_Length(const Vector3i* v);
extern "C" int func_020a299c(struct BattleCamera* obj, const Vector3i* v, const Object3D* target);
extern "C" void func_0202eab8(void* obj);
extern "C" void func_0202e5d8(void* obj, int x, int y, int z);

extern unsigned short data_02114e30;

static inline int FxMul(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// USA: func_020a212c
extern "C" ARM void func_020a212c(BattleCamera* self, int checkInput) {
    GameState* gs = GameState::GetInstance();
    GameObject* target = gs->GetGameObjectByIndex(self->followIndex);
    GameResources* res = GetWord0x0_0200fb8c((int*)gs);
    int angle = GetField0x70_0202e7f0(self);
    int left = 0;
    int right = 0;
    if (checkInput) {
        left = TestFlagMask_02012430(&data_02114e30, 0x200);
        right = TestFlagMask_02012430(&data_02114e30, 0x100);
    }
    if (IsBrightnessTransitionActive(res) || IsChannelValueZero0203b5e0(res, 0)) {
        left = 0;
        right = 0;
    }
    if (self->flags244 & 2) {
        left = 0;
        right = 0;
    }
    if (self->flags244 & 0x10) {
        left = 0;
        right = 0;
    }
    if (self->enabledA == 0) {
        left = 0;
        right = 0;
    }
    if (self->enabledB == 0) {
        left = 0;
        right = 0;
    }
    if (self->flags245 & 2) {
        if (left == 0 && right == 0 && angle == self->homeAngle) {
            self->flags245 &= ~2;
        }
        left = 0;
        right = 0;
    }
    unsigned int dt = gs->GetEffectiveDeltaTime();
    if (self->flags245 & 2) {
        int dist = fix32SignedAngleDistance(angle, self->homeAngle);
        int adist = fix32abs(dist);
        int step = (int)(4096.0f * (0.00225f * (float)dt));
        if (step > adist >> 1) {
            step = adist >> 1;
        }
        if (adist < 0x28) {
            ApplyField0x70Tail((struct GlobalObj0202e6a8*)self, self->homeAngle);
            self->angles.x = self->homeAngle;
        } else {
            if (dist < 0) {
                step = -step;
            }
            int a = fix32ReduceAngle0To2Pi(angle + step);
            ApplyField0x70Tail((struct GlobalObj0202e6a8*)self, a);
            self->angles.x = a;
        }
    } else if (right && left) {
        self->flags245 |= 2;
        ClampField74BySign((struct CamState0202e6c0*)self, self->angles.y);
        SetField78Clamped0202e71c((struct Obj0202e71c*)self, self->angles.z);
    } else if (left) {
        angle = fix32ReduceAngle0To2Pi(angle + (int)(4096.0f * (0.0015f * (float)dt)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0xc91;
        }
        ApplyField0x70Tail((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
    } else if (right) {
        angle = fix32ReduceAngle0To2Pi(angle - (int)(4096.0f * (0.0015f * (float)dt)));
        if (angle > 0xc91 && angle < 0x57f7) {
            angle = 0x57f7;
        }
        ApplyField0x70Tail((struct GlobalObj0202e6a8*)self, angle);
        self->angles.x = angle;
    }

    Vector3i pos;
    int blended = 0;
    __clear(&pos, 0xc);
    if (target) {
        pos = target->obj3D_.position_;
        pos.y += target->obj3D_.GetHeight() / 2;
        Vector3fix_Add(&pos, &self->offset, &pos);
        Vector3i eye = pos;
        if (CheckField0NonZero020a10a8(&self->dispatch.active)) {
            self->dispatch.source = eye;
            DispatchMemberFn020a0dec((struct DispatchObj020a0dec*)&self->dispatch);
            eye = self->dispatch.result;
        }
        CopyVec3ToField0x10AndCall0202e5d8_0202ec5c((char*)self, (int*)&eye);
        blended = func_020a299c(self, &pos, &target->obj3D_);
    }
    if (self->flags245 & 0x10) {
        Vector3fixMultiplyScalar(&self->offset, 0xccc, &self->offset);
        if (Vector3fix_Length(&self->offset) < 0x28) {
            self->offset.x = 0;
            self->offset.y = 0;
            self->offset.z = 0;
            self->flags245 &= ~0x10;
        }
    }
    if (self->zoomMode == 0) {
        return;
    }
    Vector3i look = self->angles;
    if (blended) {
        look = self->target;
    }
    int update = 1;
    if (self->zoomMode == 1) {
        self->zoom += (0x1000 - self->zoom) / 10;
    } else if (self->zoomMode == 2) {
        self->zoom += -self->zoom / 10;
        if (self->zoom < 0x28) {
            self->zoomMode = 0;
            SetField78Clamped0202e71c((struct Obj0202e71c*)self, look.z);
            ClampField74BySign((struct CamState0202e6c0*)self, look.y);
            update = 0;
        }
    }
    if (update == 0) {
        return;
    }
    if (blended) {
        Vector3i eye = self->eye;
        eye.y = pos.y + FxMul(eye.y - pos.y, 0x1000 - self->zoom);
        CopyVec3ToField0x10AndCall0202e5d8_0202ec5c((char*)self, (int*)&eye);
        func_0202eab8(self);
        look = self->target;
    }
    if (self->zoom != 0) {
        Vector3i eye = self->eye;
        Vector3i center = target->obj3D_.position_;
        center.y += target->obj3D_.GetHeight() / 2;
        Vector3i delta;
        Vector3fix_Subtract(&eye, &center, &delta);
        Vector3fixMultiplyScalar(&delta, self->zoom, &delta);
        Vector3fix_Subtract(&eye, &delta, &eye);
        CopyVec3ToField0x10AndCall0202e5d8_0202ec5c((char*)self, (int*)&eye);
    }
    int t = 0x1000 - self->zoom;
    func_0202e5d8(self, look.x, FxMul(look.y - 0x34cc, t) + 0x34cc, FxMul(look.z - 0x6000, t) + 0x6000);
}
