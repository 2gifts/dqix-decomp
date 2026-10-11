#include <globaldefs.h>

#if defined(jpn)
enum { timerAccumulatorOffset = 0x910 };
#else
enum { timerAccumulatorOffset = 0x9bc };
#endif
#include "GameState/GameState.h"


struct BattleTimer0202441c {
    char pad[timerAccumulatorOffset];
    unsigned int accum;
    unsigned char state;
};

// USA: func_0202441c
ARM void AccumulateBattleTimer0202441c(struct BattleTimer0202441c* p) {
    p->accum += ((GameState*)(GameState::GetInstance()))->GetTrueDeltaTime();
    if (p->accum >= 0x4b0) {
        p->state = 0;
        p->accum = 0;
        return;
    }
    if (p->accum >= 0x1f4) {
        p->state = 1;
    }
}
