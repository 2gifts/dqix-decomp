#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"

struct CameraShakeCmd_02158494 {
    int field_0x0;
    Vector3fix amplitude;
    char pad_0x10[0xc];
    int duration;
};

struct BattleCamera_02158494 {
    char pad_0x0[0x44];
    int shakeFrame;
    char pad_0x48[0x4];
    Vector3fix eye;
    Vector3fix target;
    char pad_0x64[0xd0];
    int shakeActive;
    Vector3fix shakeAmplitude;
    Vector3fix savedEye;
    Vector3fix savedTarget;
};

// USA: func_ov001_02158494
extern "C" ARM int func_ov001_02158494(CameraShakeCmd_02158494* cmd, BattleCamera_02158494* cam) {
    int duration = cmd->duration;
    if (duration <= -1) {
        cam->shakeActive = 1;
        memcpy(&cam->savedEye, &cam->eye, sizeof(Vector3fix));
        memcpy(&cam->savedTarget, &cam->target, sizeof(Vector3fix));
        if (cam->shakeFrame % 4 == 0) {
            Vector3fix_Add(&cam->eye, &cmd->amplitude, &cam->eye);
            Vector3fix_Add(&cam->target, &cmd->amplitude, &cam->target);
        } else if (cam->shakeFrame % 4 == 2) {
            Vector3fix_Subtract(&cam->eye, &cmd->amplitude, &cam->eye);
            Vector3fix_Subtract(&cam->target, &cmd->amplitude, &cam->target);
        }
        cam->shakeFrame++;
    } else {
        if (cam->shakeFrame >= duration) {
            cam->shakeFrame = 0;
            cam->shakeActive = 0;
            return 0;
        }
        if (cam->shakeFrame <= 0) {
            cam->shakeActive = 1;
            memcpy(&cam->shakeAmplitude, &cmd->amplitude, sizeof(Vector3fix));
        }
        memcpy(&cam->savedEye, &cam->eye, sizeof(Vector3fix));
        memcpy(&cam->savedTarget, &cam->target, sizeof(Vector3fix));
        if (cam->shakeFrame % 4 == 0) {
            Vector3fix_Add(&cam->eye, &cam->shakeAmplitude, &cam->eye);
            Vector3fix_Add(&cam->target, &cam->shakeAmplitude, &cam->target);
        } else if (cam->shakeFrame % 4 == 2) {
            Vector3fix_Subtract(&cam->eye, &cam->shakeAmplitude, &cam->eye);
            Vector3fix_Subtract(&cam->target, &cam->shakeAmplitude, &cam->target);
            Vector3fix decay;
            Vector3fixDivideScalar(&cmd->amplitude, cmd->duration << 12, &decay);
            Vector3fixMultiplyScalar(&decay, cam->shakeFrame << 12, &decay);
            Vector3fix_Subtract(&decay, &cam->shakeAmplitude, &cmd->amplitude);
        }
        cam->shakeFrame++;
    }
    return 1;
}
