#include <globaldefs.h>
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "Graphics/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"

struct ViewerCameraState0218e670
{
    char field_0x0[0x24];
    Object3D* object;
    char field_0x28[0x12];
    unsigned char inputEnabled;
};

struct ViewerCamera0218e670
{
    int field_0x0;
    Vector3i eye;
    Vector3i target;
};

struct CameraOutputs0218e670
{
    Matrix4x3* target;
    Matrix4x3* position;
    Matrix4x3* eye;
};

extern CameraOutputs0218e670 data_ov015_02194564;
extern unsigned short data_02114e30;
ViewerCamera0218e670* GetFieldIfFlag2_020100cc(char*);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
extern "C" void func_020c5414();
extern "C" void func_0202eab8(ViewerCamera0218e670*);

// USA: func_ov015_0218e670
extern "C" ARM void func_ov015_0218e670(ViewerCameraState0218e670* self)
{
    Matrix4x3 eyeMatrix;
    Matrix4x3 targetMatrix;
    Matrix4x3 positionMatrix;
    GameState* game = GameState::GetInstance();
    if (game == NULL)
        return;
    ViewerCamera0218e670* camera = GetFieldIfFlag2_020100cc((char*)game);
    if (camera == NULL)
        return;
    bool update = false;
    if (self->inputEnabled)
    {
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x100))
            update = true;
    }
    else
        update = true;
    if (!update)
        return;
    data_ov015_02194564.eye = &eyeMatrix;
    data_ov015_02194564.target = &targetMatrix;
    data_ov015_02194564.position = &positionMatrix;
    func_020c5414();
    RenderConfig::SubmitToFifo();
    self->object->MaybeUpdateBonePositions();
    data_ov015_02194564.eye = NULL;
    data_ov015_02194564.target = NULL;
    data_ov015_02194564.position = NULL;
    Vector3i eye;
    Vector3i target;
    Vector3i position;
    eye.x = eyeMatrix.translation.x;
    eye.y = eyeMatrix.translation.y;
    eye.z = eyeMatrix.translation.z;
    target.x = targetMatrix.translation.x;
    target.y = targetMatrix.translation.y;
    target.z = targetMatrix.translation.z;
    position.x = positionMatrix.translation.x;
    position.y = positionMatrix.translation.y;
    position.z = positionMatrix.translation.z;
    Vector3i scale = self->object->GetScale();
    Vector3fixMultiply(&eye, &scale, &eye);
    Vector3fixMultiply(&target, &scale, &target);
    Vector3fixMultiply(&position, &scale, &position);
    Vector3i translation = self->object->position_;
    Vector3fix_Add(&eye, &translation, &eye);
    Vector3fix_Add(&target, &translation, &target);
    Vector3fix_Add(&position, &translation, &position);
    (camera->target = target, camera->eye) = eye;
    func_0202eab8(camera);
}
