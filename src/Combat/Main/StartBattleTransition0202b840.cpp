#include <globaldefs.h>
#include "GameState/GameState.h"

extern char data_020feffc[];

int GetGlobalField0x10_0202d6a8(void);
int AdvanceStateIfState2_0202d0b4(void);
void SleepCurrentContext(unsigned int);
int Init0202dc40(int mode, void* src);
unsigned long long GetCurrentTimestamp(void);

// USA: func_0202b840
ARM int StartBattleTransition0202b840(int* state, int id) {
    int i;
    GameState* battleStruct;

    if (id < 0) {
        return 1;
    }

    i = 0;
    while (GetGlobalField0x10_0202d6a8() == 2) {
        AdvanceStateIfState2_0202d0b4();
        i++;
        if (i > 0x1388) {
            return 0;
        }
        SleepCurrentContext(1);
    }

    i = 0;
    while (GetGlobalField0x10_0202d6a8() != 1) {
        i++;
        if (i > 0x1388) {
            return 0;
        }
        SleepCurrentContext(1);
    }

    Init0202dc40(5, data_020feffc + id * 0xc0);
    *state = 6;

    battleStruct = GameState::GetInstance();
    *(unsigned long long*)((char*)battleStruct + 0x3f0) = GetCurrentTimestamp();

    return 1;
}
