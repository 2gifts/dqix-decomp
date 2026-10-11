#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValueEC_E8 = 0xe8 };
#else
enum { kRegionValueEC_E8 = 0xec };
#endif


struct Obj021727c8 {
    char unk_0[kRegionValueEC_E8];
    unsigned char state_;
    unsigned char subState_;
};

typedef void (Obj021727c8::*StateFn021727c8)();

struct StateTable021727c8 {
    StateFn021727c8 functions[7];
};

extern "C" const StateTable021727c8 data_ov003_0217fa20;
extern "C" const StateTable021727c8 data_ov003_0217fa58;
extern "C" StateFn021727c8 data_020e6d5c;

// USA: func_ov003_021727c8
// JPN: func_ov003_021716b4
extern "C" ARM bool func_ov003_021727c8(Obj021727c8* self) {
    GameState::GetInstance()->GetTickCount();
    bool done = false;
    bool subDone = false;
    StateTable021727c8 states = data_ov003_0217fa20;
    StateFn021727c8 none = data_020e6d5c;
    states.functions[6] = none;
    StateTable021727c8 subStates = data_ov003_0217fa58;
    subStates.functions[6] = none;
    if (states.functions[self->state_] != 0) {
        (self->*states.functions[self->state_])();
    } else {
        done = true;
    }
    if (subStates.functions[self->subState_] != 0) {
        (self->*subStates.functions[self->subState_])();
    } else {
        subDone = true;
    }
    if (done && subDone) {
        return false;
    }
    return true;
}
