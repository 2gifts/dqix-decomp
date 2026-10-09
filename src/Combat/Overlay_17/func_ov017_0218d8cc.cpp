#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

int GetField0x3b0Value(GameState* gs);
int TestFlagMask(unsigned short* obj, int mask);
void GetVec3FromShorts(unsigned char* src, int* out);

extern unsigned short data_02114e30;

struct Camera0218d8cc {
    int field_0x0;
    Vector3fix position;
};

struct Input0218d8cc {
    char pad0[0x224];
    unsigned char hasStick;
};

struct Battle0218d8cc {
    char pad0[0x4328];
    Input0218d8cc* input;
    char pad432c[0x4438 - 0x432c];
    Vector3fix moveDir;
};

// USA: func_ov017_0218d8cc
extern "C" ARM void func_ov017_0218d8cc(Battle0218d8cc* self) {
    GameState* gs = GameState::GetInstance();
    GameObject* player = gs->GetUnknownGameObject();
    Camera0218d8cc* camera = (Camera0218d8cc*)GetField0x3b0Value(gs);
    if (player == 0 || camera == 0) {
        return;
    }

    Vector3fix diff;
    Vector3fix_Subtract(&player->obj3D_.position_, &camera->position, &diff);

    Vector3fix forward;
    forward.x = diff.x;
    forward.y = 0;
    forward.z = diff.z;
    Vector3fix back;
    back.x = -diff.x;
    back.y = 0;
    back.z = -diff.z;
    Vector3fix left;
    left.x = diff.z;
    left.y = 0;
    left.z = -diff.x;
    Vector3fix right;
    right.x = -diff.z;
    right.y = 0;
    right.z = diff.x;

    self->moveDir.x = 0;
    self->moveDir.y = 0;
    self->moveDir.z = 0;

    if (TestFlagMask(&data_02114e30, 0x40)) {
        Vector3fix_Add(&self->moveDir, &forward, &self->moveDir);
    } else if (TestFlagMask(&data_02114e30, 0x80)) {
        Vector3fix_Add(&self->moveDir, &back, &self->moveDir);
    }

    if (TestFlagMask(&data_02114e30, 0x20)) {
        Vector3fix_Add(&self->moveDir, &left, &self->moveDir);
    } else if (TestFlagMask(&data_02114e30, 0x10)) {
        Vector3fix_Add(&self->moveDir, &right, &self->moveDir);
    }

    if (self->input->hasStick) {
        GetVec3FromShorts((unsigned char*)self->input, &self->moveDir.x);
    }
    Vector3fix_Normalize(&self->moveDir, &self->moveDir);
}
