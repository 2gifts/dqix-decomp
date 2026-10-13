#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>

void AddPlayClockMinutes020ac644(struct BattleRecordPlayClock* clock, int amount);

// USA: func_020ac6b8  (semantic: AddPlayClockSeconds020ac6b8)
extern "C" ARM void func_020ac6b8(struct BattleRecordPlayClock* clock, int amount) {
    clock->seconds = clock->seconds + amount;
    unsigned char secs = clock->seconds;
    if (secs <= 0x3b) return;

    unsigned char carry = secs / 0x3c;
    if (clock->hours == 0x270f) {
        int m = clock->minutes + carry;
        if (m > 0x3b) {
            clock->hours = 0x270f;
            clock->minutes = 0x3b;
            clock->seconds = 0x3b;
            return;
        }
    }
    AddPlayClockMinutes020ac644(clock, carry);
    clock->seconds = clock->seconds % 0x3c;
}
