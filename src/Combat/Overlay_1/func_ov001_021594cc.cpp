#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct RotationRequest021594cc { int field_0; Vector3fix angles; int duration; int reverse; };
struct RotationState021594cc {
    char field_0[0x4c];
    int elapsed;
    char field_50[0x30];
    Vector3fix angles;
    char field_8c[0x14];
    Vector3fix velocity;
};

inline int MultiplyRotation(int velocity, int tick) {
    int result = (int)(((long long)velocity * tick + 0x800) >> 12);
    return result;
}

// USA: func_ov001_021594cc
extern "C" ARM int func_ov001_021594cc(RotationRequest021594cc* request, RotationState021594cc* state) {
    GameState* game = GameState::GetInstance();
    int tick = game->GetTickCount() << 12;
    if (request->duration < 0) {
        state->angles.x += request->angles.x;
        state->angles.y += request->angles.y;
        state->angles.z += request->angles.z;
        if (state->angles.x > 0x6487) state->angles.x -= 0x6487;
        else if (state->angles.x <= 0) state->angles.x += 0x6487;
        if (state->angles.y > 0x6487) state->angles.y -= 0x6487;
        else if (state->angles.y <= 0) state->angles.y += 0x6487;
        if (state->angles.z > 0x6487) state->angles.z -= 0x6487;
        else if (state->angles.z <= 0) state->angles.z += 0x6487;
    } else {
        if (state->elapsed >= request->duration * 2) {
            memcpy(&state->angles, &request->angles, 12);
            state->elapsed = 0;
            return 0;
        }
        if (state->elapsed <= 0) {
            int duration = request->duration << 13;
            int delta_x;
            if (request->reverse) delta_x = state->angles.x - request->angles.x;
            else delta_x = request->angles.x - state->angles.x;
            if (delta_x > 0x6487) delta_x -= 0x6487;
            else if (delta_x < 0) delta_x += 0x6487;
            state->velocity.x = fix32_Divide(delta_x, duration);
            int delta_y;
            if (request->reverse) delta_y = state->angles.y - request->angles.y;
            else delta_y = request->angles.y - state->angles.y;
            if (delta_y > 0x6487) delta_y -= 0x6487;
            else if (delta_y < 0) delta_y += 0x6487;
            state->velocity.y = fix32_Divide(delta_y, duration);
            int delta_z;
            if (request->reverse) delta_z = state->angles.z - request->angles.z;
            else delta_z = request->angles.z - state->angles.z;
            if (delta_z > 0x6487) delta_z -= 0x6487;
            else if (delta_z < 0) delta_z += 0x6487;
            state->velocity.z = fix32_Divide(delta_z, duration);
            if (request->reverse) {
                state->velocity.x = -state->velocity.x;
                state->velocity.y = -state->velocity.y;
                state->velocity.z = -state->velocity.z;
            }
        } else {
            state->angles.x += MultiplyRotation(state->velocity.x, tick);
            if (state->angles.x > 0x6487) state->angles.x -= 0x6487;
            else if (state->angles.x <= 0) state->angles.x += 0x6487;
            state->angles.y += MultiplyRotation(state->velocity.y, tick);
            if (state->angles.y > 0x6487) state->angles.y -= 0x6487;
            else if (state->angles.y <= 0) state->angles.y += 0x6487;
            state->angles.z += MultiplyRotation(state->velocity.z, tick);
            if (state->angles.z > 0x6487) state->angles.z -= 0x6487;
            else if (state->angles.z <= 0) state->angles.z += 0x6487;
        }
        state->elapsed += game->GetTickCount();
    }
    return 1;
}

