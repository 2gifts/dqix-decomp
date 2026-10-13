#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>


// USA: func_020ac614
ARM void AddPlayClockHours020ac614(struct BattleRecordPlayClock* clock, int amount) {
    clock->hours += amount;
    if (clock->hours > 0x270f) {
        clock->hours = 0x270f;
        clock->minutes = 0x3b;
        clock->seconds = 0x3b;
    }
}
