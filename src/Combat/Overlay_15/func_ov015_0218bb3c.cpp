#if defined(jpn)
#define R(j,u) (j)
#define data_ov005_0215cbd4 data_ov005_0215dfb4
#define data_ov005_0215cd60 data_ov005_0215e140
#define data_ov014_02189480 data_ov014_0218a2c0
#define data_ov014_02189498 data_ov014_0218a2d8
#define data_ov015_02193fe0 data_ov015_02194b20
#define data_ov015_02194564 data_ov015_02195184
#define data_ov015_02194570 data_ov015_02195190
#define data_ov015_021945a0 data_ov015_021951c0
#define data_ov015_021945d0 data_ov015_021951f0
#define data_ov024_021ff17c data_ov023_021ff17c
#define func_ov005_02158560 func_ov005_02159b58
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "System/Matrix.h"
#include "Graphics/NSBXX/GeometryFifo.h"
#include "Graphics/NSBXX/RenderConfig.h"

struct Struct0218bc9c;

struct CameraOutputs
{
#if defined(jpn)
    Matrix4x3* eye_;
    Matrix4x3* position_;
    Matrix4x3* target_;
#else
    Matrix4x3* target_;
    Matrix4x3* position_;
    Matrix4x3* eye_;
#endif
    Matrix4x3 eyeMatrix_;
    Matrix4x3 targetMatrix_;
    Matrix4x3 positionMatrix_;
};

extern "C" int _Z25GetFieldOrDefault0218bc9cP14Struct0218bc9c(Struct0218bc9c* s);

extern unsigned char data_ov015_02193fe0[];
extern CameraOutputs data_ov015_02194564;

struct Handler0218bb3c
{
    char unk_0[8];
    unsigned int flags_;
};

// USA: func_ov015_0218bb3c
extern "C" ARM void func_ov015_0218bb3c(Handler0218bb3c* handler)
{
    if (!(handler->flags_ & 0x10))
        return;
    if (data_ov015_02193fe0[1] == _Z25GetFieldOrDefault0218bc9cP14Struct0218bc9c((Struct0218bc9c*)handler) && data_ov015_02194564.eye_ != NULL)
    {
        GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.eye_, NULL);
        data_ov015_02194564.eyeMatrix_ = *data_ov015_02194564.eye_;
        Mat4x3_Multiply(data_ov015_02194564.eye_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.eye_);
    }
    if (data_ov015_02193fe0[R(0, 2)] == _Z25GetFieldOrDefault0218bc9cP14Struct0218bc9c((Struct0218bc9c*)handler) && data_ov015_02194564.target_ != NULL)
    {
        GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.target_, NULL);
        data_ov015_02194564.targetMatrix_ = *data_ov015_02194564.target_;
        Mat4x3_Multiply(data_ov015_02194564.target_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.target_);
    }
    if (data_ov015_02193fe0[R(2, 0)] != _Z25GetFieldOrDefault0218bc9cP14Struct0218bc9c((Struct0218bc9c*)handler))
        return;
    if (data_ov015_02194564.position_ == NULL)
        return;
    GetCurrentPositionAndDirectionMatrices(data_ov015_02194564.position_, NULL);
    data_ov015_02194564.positionMatrix_ = *data_ov015_02194564.position_;
    Mat4x3_Multiply(data_ov015_02194564.position_, RenderConfig::GetInverseViewMatrix(), data_ov015_02194564.position_);
}
