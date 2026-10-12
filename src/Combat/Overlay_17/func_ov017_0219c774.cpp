#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"

struct TimeEntry0219c774 {
    unsigned char padding_0[12];
    unsigned char kind : 4;
    unsigned char flags : 4;
};
float GetActiveBitIndex(GameState*);
extern "C" void func_020103c8(GameState*, float);
extern float data_ov017_021d837c[6];
struct TimeIntervals0219c774 {
    float step;
    float fields_4[3];
    float end;
    float field_14;
};
extern TimeIntervals0219c774 data_ov017_021d75b8;

// USA: func_ov017_0219c774
extern "C" ARM int func_ov017_0219c774(TimeEntry0219c774* entry, int apply) {
    GameState* game = GameState::GetInstance();
    float time = GetActiveBitIndex(game);
    float reference = time;
    if (apply && entry != 0 && entry->kind == 0) {
        game->SetDayTimer(time);
        func_020103c8(game, time);
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = game->GetDayTimer();
        lighting->timeOfDayIndex_ = game->GetTimeOfDay();
        return 0;
    }
    int next = 0;
    if (time >= data_ov017_021d837c[2]) next = 3;
    else if (time >= data_ov017_021d837c[1]) next = 2;
    else if (time >= data_ov017_021d837c[3]) next = 1;
    int previous = game->GetTimeOfDay();
    if (next == previous) {
        int i;
        float bounds[4] = {data_ov017_021d837c[3], data_ov017_021d837c[1], data_ov017_021d837c[2], data_ov017_021d837c[2] + data_ov017_021d75b8.end};
        float step;
        i = 0;
        for (; i < 4; i++) {
            step = data_ov017_021d75b8.step;
            if (bounds[i] - 2.0f * step < time && time < bounds[i]) {
                time = bounds[i] - 2.0f * step;
                reference = bounds[i];
            }
        }
        if (data_ov017_021d837c[5] <= reference) reference = 0.0f;
        if (entry == 0 || entry->kind != 0) time = reference;
    }
    if ((next + 1) % 4 == previous) {
        float bounds[4] = {data_ov017_021d837c[3], data_ov017_021d837c[1], data_ov017_021d837c[2], data_ov017_021d837c[2] + data_ov017_021d75b8.end};
        float values[4] = {data_ov017_021d837c[4], data_ov017_021d837c[3], data_ov017_021d837c[1], data_ov017_021d837c[2]};
        if (bounds[next] - 2.0f * data_ov017_021d75b8.step < time && time < bounds[next]) {
            time = values[previous];
            reference = time;
        }
    }
    next = 0;
    if (time >= data_ov017_021d837c[2]) next = 3;
    else if (time >= data_ov017_021d837c[1]) next = 2;
    else if (time >= data_ov017_021d837c[3]) next = 1;
    if (next == previous) apply = 1;
    if (apply) {
        game->SetDayTimer(time);
        func_020103c8(game, reference);
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = game->GetDayTimer();
        lighting->timeOfDayIndex_ = game->GetTimeOfDay();
    }
    return next != previous;
}
