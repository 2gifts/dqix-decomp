#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct CameraMoveCmd_02157c3c {
    int field_0x0;
    Vector3fix eye;
    Vector3fix target;
    int duration;
    int field_0x20;
    int resetOnFinish;
};

struct BattleCamera_02157c3c {
    char pad_0x0[0x38];
    int timer;
    char pad_0x3c[0x10];
    Vector3fix eye;
    Vector3fix target;
    char pad_0x64[0x50];
    Vector3fix eyeVelocity;
    Vector3fix targetVelocity;
    char pad_0xcc[0x44];
    Vector3fix eyeVelocityCopy;
    Vector3fix targetVelocityCopy;
    char pad_0x128[0x8fc];
    int field_0xa24;
};

// USA: func_ov001_02157c3c
extern "C" ARM int func_ov001_02157c3c(CameraMoveCmd_02157c3c* cmd, BattleCamera_02157c3c* cam) {
    GameState* gameState = GameState::GetInstance();
    int scale = gameState->GetTickCount() << 12;
    int duration = cmd->duration;
    if (duration == 0) {
        memcpy(&cam->eye, &cmd->eye, sizeof(Vector3fix));
        memcpy(&cam->target, &cmd->target, sizeof(Vector3fix));
        cam->timer = 0;
        return 0;
    }
    if (cam->timer <= 0) {
        Vector3fix diff;
        int denom = duration << 13;
        Vector3fix_Subtract(&cmd->eye, &cam->eye, &diff);
        cam->eyeVelocity.x = fix32_Divide(diff.x, denom);
        cam->eyeVelocity.y = fix32_Divide(diff.y, denom);
        cam->eyeVelocity.z = fix32_Divide(diff.z, denom);
        Vector3fix_Subtract(&cmd->target, &cam->target, &diff);
        cam->targetVelocity.x = fix32_Divide(diff.x, denom);
        cam->targetVelocity.y = fix32_Divide(diff.y, denom);
        cam->targetVelocity.z = fix32_Divide(diff.z, denom);
        memcpy(&cam->eyeVelocityCopy, &cam->eyeVelocity, sizeof(Vector3fix));
        memcpy(&cam->targetVelocityCopy, &cam->targetVelocity, sizeof(Vector3fix));
        cam->field_0xa24 = cmd->field_0x20;
    }
    Vector3fix eyeStep = cam->eyeVelocity;
    Vector3fix targetStep = cam->targetVelocity;
    Vector3fixMultiplyScalar(&eyeStep, scale, &eyeStep);
    Vector3fixMultiplyScalar(&targetStep, scale, &targetStep);
    Vector3fix_Add(&cam->eye, &eyeStep, &cam->eye);
    Vector3fix_Add(&cam->target, &targetStep, &cam->target);
    cam->field_0xa24 = cmd->field_0x20;
    cam->timer += gameState->GetTickCount();
    if (cam->timer >= cmd->duration << 1) {
        if (cmd->resetOnFinish != 0) {
            memcpy(&cam->eye, &cmd->eye, sizeof(Vector3fix));
            memcpy(&cam->target, &cmd->target, sizeof(Vector3fix));
        }
        cam->timer = 0;
        return 0;
    }
    return 1;
}
