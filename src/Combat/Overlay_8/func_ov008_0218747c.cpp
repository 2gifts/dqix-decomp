#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include <GameState/GameState.h>

struct ClockTotals { char pad[0x3c]; BattleRecordPlayClock clocks[2]; };
#if defined(jpn)
enum { totalsOffset = 0x72c4, displayPadding = 0x14 };
#else
enum { totalsOffset = 0x7504, displayPadding = 0x18 };
#endif
struct GameClockTotals { char pad[totalsOffset]; ClockTotals totals; };
struct PlayTimeDisplay {
    char pad0[0xb10];
    signed char state;
    unsigned char phase;
    char pad1[6];
    unsigned int dirtyFlags;
    char pad2[displayPadding];
    int disabled;
    char pad3[8];
    BattleRecordPlayClock clocks[2];
};
struct SearchClock { char pad[0x100d]; unsigned char count; };
struct TimeStamp020103f0;
struct TimeStamp020104cc;
extern "C" void _Z33ComputeElapsedPlayTimeHMS020103f0P17TimeStamp020103f0PtPhS2_(TimeStamp020103f0*, unsigned short*, unsigned char*, unsigned char*);
extern "C" SearchClock* func_0202ae18();
int GetFieldAt0x0(int*);
extern "C" void _Z33ComputeElapsedPlayTimeHMS020104ccP17TimeStamp020104ccPtPhS2_(TimeStamp020104cc*, unsigned short*, unsigned char*, unsigned char*);
void AddPlayClockHours020ac614(BattleRecordPlayClock*, int);
void AddPlayClockMinutes020ac644(BattleRecordPlayClock*, int);
static inline ClockTotals* GetTotals(GameState* game) { return &((GameClockTotals*)game)->totals; }

// USA: func_ov008_0218747c
extern "C" ARM void func_ov008_0218747c(PlayTimeDisplay* display, int mode) {
    if (display->disabled) return;
    if (display->state == 12 && display->phase < 6) return;
    GameState* game = GameState::GetInstance();
    BattleRecordPlayClock* output = 0;
    ClockTotals* totals = GetTotals(game);
    BattleRecordPlayClock* saved = 0;
    unsigned short hours = 0;
    unsigned char minutes = 0;
    unsigned char seconds = 0;
    BattleRecordPlayClock* singlePlayerSaved = &totals->clocks[0];
    BattleRecordPlayClock* multiplayerSaved = singlePlayerSaved + 1;
    if (mode == 0) {
        output = &display->clocks[0];
        saved = singlePlayerSaved;
        _Z33ComputeElapsedPlayTimeHMS020103f0P17TimeStamp020103f0PtPhS2_((TimeStamp020103f0*)game, &hours, &minutes, &seconds);
    } else if (mode == 1) {
        output = &display->clocks[1];
        saved = multiplayerSaved;
        SearchClock* search = func_0202ae18();
        int state = GetFieldAt0x0((int*)search);
        int count = search->count;
        if ((state == 5 && count > 1) || state == 6) {
            _Z33ComputeElapsedPlayTimeHMS020104ccP17TimeStamp020104ccPtPhS2_((TimeStamp020104cc*)game, &hours, &minutes, &seconds);
        } else {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
    }
    if (!output || !saved) return;
    unsigned char previousMinutes = output->minutes;
    ClearShortByteByte_02184598(output);
    AddPlayClockHours020ac614(output, (unsigned short)(saved->hours + hours));
    AddPlayClockMinutes020ac644(output, (unsigned char)(saved->minutes + minutes));
    output->seconds += (unsigned char)(saved->seconds + seconds);
    unsigned char total = output->seconds;
    if (total > 59) {
        unsigned char carryMinutes = total / 60;
        if (output->hours == 9999 && output->minutes + carryMinutes > 59) {
            output->hours = 9999;
            output->minutes = 59;
            output->seconds = 59;
        } else {
            AddPlayClockMinutes020ac644(output, carryMinutes);
            output->seconds %= 60;
        }
    }
    if (output->minutes != previousMinutes) {
        if (mode == 0) display->dirtyFlags |= 0x800;
        else if (mode == 1) display->dirtyFlags |= 0x1000;
    }
}
