#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "System/Matrix.h"

struct Vec3
{
    int x;
    int y;
    int z;
};

struct Obj0218f44c;
struct ViewObject;

struct S02190c2c
{
    char unk_0[0x34];
    ViewObject* selected_;
};

int TestFlagMask(unsigned short* pad, int buttons);
void Vector3fixMultiplyScalar(const Vector3i* in, int scale, Vector3i* out);
extern "C" void _Z29AccumulateOffsetVec3_0218f44cP11Obj0218f44c4Vec3(Obj0218f44c* object, Vec3 offset);
extern "C" void func_ov015_0218f5f8(ViewObject* object, int angle);

extern unsigned short data_02114e30;

// USA: func_ov015_02191874
extern "C" ARM void func_ov015_02191874(S02190c2c* self)
{
    if (self->selected_ == NULL)
        return;
    GameState::GetInstance();
    Vector3fix move = {0};
    Matrix3x3 view;
    if (TestFlagMask(&data_02114e30, 0x40))
        move.z = -0x199;
    if (TestFlagMask(&data_02114e30, 0x80))
        move.z = 0x199;
    if (TestFlagMask(&data_02114e30, 0x10))
        move.x = 0x199;
    if (TestFlagMask(&data_02114e30, 0x20))
        move.x = -0x199;
    memcpy(&view, RenderConfig::GetInverseViewMatrix(), sizeof(view));
    Mat3x3_ApplyToVector(&move, &view, &move);
    move.y = 0;
    Vector3fix_Normalize(&move, &move);
    Vector3fixMultiplyScalar(&move, 0x199, &move);
    if (TestFlagMask(&data_02114e30, 0x400))
        move.y += 0x199;
    if (TestFlagMask(&data_02114e30, 0x800))
        move.y -= 0x199;
    _Z29AccumulateOffsetVec3_0218f44cP11Obj0218f44c4Vec3((Obj0218f44c*)self->selected_, *(Vec3*)&move);
    if (TestFlagMask(&data_02114e30, 0x200))
        func_ov015_0218f5f8(self->selected_, 0x199);
    if (TestFlagMask(&data_02114e30, 0x100))
        func_ov015_0218f5f8(self->selected_, -0x199);
}
