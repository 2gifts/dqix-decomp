#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

void AddPlayClockHours020ac614(struct BattleRecordPlayClock* clock, int amount);

// USA: func_020ac644
ARM void AddPlayClockMinutes020ac644(struct BattleRecordPlayClock* clock, int amount) {
    clock->minutes = clock->minutes + amount;
    unsigned char mins = clock->minutes;
    if (mins <= 0x3b) return;

    unsigned short carryHours = mins / 0x3c;
    if ((int)(clock->hours + carryHours) > 0x270f) {
        clock->hours = 0x270f;
        clock->minutes = 0x3b;
        clock->seconds = 0x3b;
        return;
    }

    AddPlayClockHours020ac614(clock, carryHours);
    clock->minutes = clock->minutes % 0x3c;
}
