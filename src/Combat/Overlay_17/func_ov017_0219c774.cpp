#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Overlay17DayCycle.h"
#include "Graphics/LightingManager.h"

struct TimeEntry0219c774 {
    unsigned char padding_0[12];
    unsigned char kind : 4;
    unsigned char flags : 4;
};
float GetActiveBitIndex_020103e8(GameState*);
extern "C" void func_020103c8(GameState*, float);
// USA: func_ov017_0219c774
extern "C" ARM int func_ov017_0219c774(TimeEntry0219c774* entry, int apply) {
    GameState* game = GameState::GetInstance();
    float time = GetActiveBitIndex_020103e8(game);
    float reference = time;
    if (apply && entry != 0 && entry->kind == 0) {
        game->SetDayTimer(time);
        func_020103c8(game, time);
        LightingManager* lighting = LightingManager::GetInstance();
        lighting->dayNightTimer_ = game->GetDayTimer();
        lighting->timeOfDayIndex_ = game->GetTimeOfDay();
        return 0;
    }
    int next = TimeOfDay_Night;
    if (time >= data_ov017_021d837c.eveningStart) next = TimeOfDay_Evening;
    else if (time >= data_ov017_021d837c.dayStart) next = TimeOfDay_Day;
    else if (time >= data_ov017_021d837c.morningStart) next = TimeOfDay_Morning;
    int previous = game->GetTimeOfDay();
    if (next == previous) {
        int i;
        float bounds[4] = {data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart, data_ov017_021d837c.eveningStart + data_ov017_021d75b8.eveningDuration};
        float step;
        i = 0;
        for (; i < 4; i++) {
            step = data_ov017_021d75b8.boundaryStep;
            if (bounds[i] - 2.0f * step < time && time < bounds[i]) {
                time = bounds[i] - 2.0f * step;
                reference = bounds[i];
            }
        }
        if (data_ov017_021d837c.cycleLength <= reference) reference = 0.0f;
        if (entry == 0 || entry->kind != 0) time = reference;
    }
    if ((next + 1) % 4 == previous) {
        float bounds[4] = {data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart, data_ov017_021d837c.eveningStart + data_ov017_021d75b8.eveningDuration};
        float values[4] = {data_ov017_021d837c.nightStart, data_ov017_021d837c.morningStart, data_ov017_021d837c.dayStart, data_ov017_021d837c.eveningStart};
        if (bounds[next] - 2.0f * data_ov017_021d75b8.boundaryStep < time && time < bounds[next]) {
            time = values[previous];
            reference = time;
        }
    }
    next = TimeOfDay_Night;
    if (time >= data_ov017_021d837c.eveningStart) next = TimeOfDay_Evening;
    else if (time >= data_ov017_021d837c.dayStart) next = TimeOfDay_Day;
    else if (time >= data_ov017_021d837c.morningStart) next = TimeOfDay_Morning;
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
