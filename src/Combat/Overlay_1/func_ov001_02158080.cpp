#include <globaldefs.h>
#include "GameState/GameState.h"

struct RotationCommand02158080 {
    int field_0;
    int angle;
    int pitch;
    int roll;
    char field_10[0xc];
    int duration;
    int direction;
    int snap;
};
struct RotationState02158080 {
    char field_0[0x3c];
    int elapsed;
    char field_40[0x24];
    int angle;
    int pitch;
    int roll;
    int linked;
    char field_74[0x14];
    int linkedAngle;
    int linkedPitch;
    int linkedRoll;
    char field_94[0x38];
    int angleStep;
    int field_d0;
    int pitchStep;
    int rollStep;
};

static inline int ScaleStep(int value, int scale) {
    return (int)(((long long)value * scale + 0x800) >> 12);
}

// USA: func_ov001_02158080
extern "C" ARM int func_ov001_02158080(RotationCommand02158080* command, RotationState02158080* state) {
    GameState* game = GameState::GetInstance();
    int scale = game->GetTickCount() << 12;
    int duration = command->duration;
    if (!duration) {
        state->angle = command->angle;
        state->pitch = command->pitch;
        state->roll = command->roll;
        if (state->linked) {
            state->linkedAngle = command->angle;
            state->linkedPitch = command->pitch;
            state->linkedRoll = command->roll;
        }
        state->elapsed = 0;
        return 0;
    }
    if (state->elapsed <= 0) {
        int divisor = duration << 13;
        if (command->direction == -1) {
            int forward = command->angle - state->angle;
            if (forward > 0x6488) forward -= 0x6488;
            else if (forward < 0) forward += 0x6488;
            int backward = state->angle - command->angle;
            if (backward > 0x6488) backward -= 0x6488;
            else if (backward < 0) backward += 0x6488;
            if (forward < backward) state->angleStep = fix32_Divide(forward, divisor);
            else state->angleStep = -fix32_Divide(backward, divisor);
        } else {
            int distance;
            if (command->direction == 0) distance = state->angle - command->angle;
            else distance = command->angle - state->angle;
            if (distance > 0x6488) distance -= 0x6488;
            else if (distance < 0) distance += 0x6488;
            state->angleStep = fix32_Divide(distance, divisor);
            if (command->direction == 0) state->angleStep = -state->angleStep;
        }
        state->pitchStep = fix32_Divide(command->pitch - state->pitch, divisor);
        state->rollStep = fix32_Divide(command->roll - state->roll, divisor);
    }
    state->angle += ScaleStep(state->angleStep, scale);
    if (state->angle > 0x6488) state->angle -= 0x6488;
    else if (state->angle < 0) state->angle += 0x6488;
    state->pitch += ScaleStep(state->pitchStep, scale);
    state->roll += ScaleStep(state->rollStep, scale);
    state->elapsed += game->GetTickCount();
    if (state->elapsed >= (command->duration << 1)) {
        if (command->snap) {
            state->angle = command->angle;
            state->pitch = command->pitch;
            state->roll = command->roll;
            if (state->linked) {
                state->linkedAngle = command->angle;
                state->linkedPitch = command->pitch;
                state->linkedRoll = command->roll;
            }
        }
        state->elapsed = 0;
        return 0;
    }
    return 1;
}
