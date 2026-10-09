#include <globaldefs.h>
#include <GameState/GameState.h>
#include <System/Matrix.h>
#include <std_library_functions.h>

struct CameraCommand { int type; };
struct CommandQueue { CameraCommand* head; CameraCommand* tail; };
struct CameraState {
    char pad0[8];
    CommandQueue positionQueue;
    CommandQueue targetQueue;
    CommandQueue rotationQueue;
    CommandQueue field20Queue;
    CommandQueue field28Queue;
    CameraCommand* positionRedirect;
    CameraCommand* targetRedirect;
    char pad1[0x14];
    Vector3i position;
    Vector3i target;
    int yaw;
    int pitch;
    int roll;
    char pad2[0xc4];
    int overrideEnabled;
    char pad3[0xc];
    Vector3i overridePosition;
    Vector3i overrideTarget;
    char pad4[0x8c8];
    int forceRotation;
};
struct Camera { int field0; Vector3i position; Vector3i target; };
void* GetField0x3b0Value(GameState*);
extern "C" void func_ov001_021588e4(CameraState*);
void ReadFields0x70To0x78(unsigned char*, int*, int*, int*);
extern "C" CameraCommand* func_ov001_02158e8c(CameraState*, CameraCommand*, int);
extern "C" void func_0202e5d8(Camera*, int, int, int);
extern "C" void func_0202eab8(Camera*);
typedef int (*CameraCommandHandler)(CameraCommand*, CameraState*);
extern CameraCommandHandler data_ov001_02164c54[20];

// USA: func_ov001_02158ae4
extern "C" ARM void func_ov001_02158ae4(CameraState* state) {
    CameraCommand* command;
    GameState* game = GameState::GetInstance();
    if (!game) { func_ov001_021588e4(state); return; }
    Camera* camera = (Camera*)GetField0x3b0Value(game);
    if (!camera) { func_ov001_021588e4(state); return; }
    state->position = camera->position;
    state->target = camera->target;
    ReadFields0x70To0x78((unsigned char*)camera, &state->yaw, &state->pitch, &state->roll);
    Vector3i oldPosition = state->position;
    Vector3i oldTarget = state->target;
    int oldYaw = state->yaw;
    int oldPitch = state->pitch;
    int oldRoll = state->roll;
    if (state->overrideEnabled) {
        memcpy(&state->position, &state->overridePosition, sizeof(Vector3i));
        memcpy(&state->target, &state->overrideTarget, sizeof(Vector3i));
    }
    for (int queue = 0; queue < 5; queue++) {
        CameraCommand** head;
        CameraCommand** tail;
        switch (queue) {
        case 0: head = &state->positionQueue.head; tail = &state->positionQueue.tail; break;
        case 1: head = &state->targetQueue.head; tail = &state->targetQueue.tail; break;
        case 2: head = &state->rotationQueue.head; tail = &state->rotationQueue.tail; break;
        case 3: head = &state->field20Queue.head; tail = &state->field20Queue.tail; break;
        case 4: head = &state->field28Queue.head; tail = &state->field28Queue.tail; break;
        }
        command = *head;
        while (command) {
            if (command->type > 0 && command->type < 19) {
                int result = data_ov001_02164c54[command->type](command, state);
                if (result == 0) {
                } else if (result == 1) break;
                else if (result == 2) {
                    switch (queue) {
                    case 0: command = state->positionRedirect; break;
                    case 1: command = state->targetRedirect; break;
                    case 2: break;
                    }
                }
            } else {
                command = 0;
                break;
            }
            command = func_ov001_02158e8c(state, command, queue);
        }
        *head = command;
        if (!command) *tail = 0;
    }
    if (oldTarget.x != state->target.x || oldTarget.y != state->target.y || oldTarget.z != state->target.z) camera->target = state->target;
    if (oldYaw != state->yaw || oldPitch != state->pitch || oldRoll != state->roll) func_0202e5d8(camera, state->yaw, state->pitch, state->roll);
    if (oldPosition.x != state->position.x || oldPosition.y != state->position.y || oldPosition.z != state->position.z) {
        camera->position = state->position;
        func_0202eab8(camera);
    }
    if (state->forceRotation) {
        func_0202e5d8(camera, state->yaw, state->pitch, state->roll);
        state->forceRotation = 0;
    }
}
