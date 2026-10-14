#include "GameState/BattleRecordSnapshot.h"
#include <globaldefs.h>
#include "GameState/GameState.h"

void AddPlayClockHours020ac614(struct BattleRecordPlayClock* clock, int amount);

void AddPlayClockMinutes020ac644(struct BattleRecordPlayClock* clock, int amount);

extern "C" void func_020ac6b8(BattleRecordPlayClock* clock, int amount);

struct TimeStamp020103f0;
void ComputeElapsedPlayTimeHMS020103f0(struct TimeStamp020103f0* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

struct TimeStamp020104cc;
void ComputeElapsedPlayTimeHMS020104cc(struct TimeStamp020104cc* obj, unsigned short* outHours, unsigned char* outMinutes, unsigned char* outSeconds);

int LoadBattleBlock020ac4c0(void* dst);
int CopyInBattleField0x7540_020ac494(void* src);

unsigned long long GetCurrentTimestamp(void);

// USA: func_020ac4f8
ARM int UpdatePlayClocks020ac4f8(int commit) {
    GameState *battle;
    BattleRecordSnapshot record;
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
    unsigned long long ts;
    BattleRecordClockPair* secondaryClocks;

    battle = GameState::GetInstance();
    LoadBattleBlock020ac4c0(&record);

    hours = 0;
    minutes = 0;
    seconds = 0;
    secondaryClocks = &record.secondaryClocks;
    ComputeElapsedPlayTimeHMS020103f0((struct TimeStamp020103f0*)battle, &hours, &minutes, &seconds);

    AddPlayClockHours020ac614(&record.clocks.elapsed, hours);
    AddPlayClockMinutes020ac644(&record.clocks.elapsed, minutes);
    func_020ac6b8(&record.clocks.elapsed, seconds);

    AddPlayClockHours020ac614(&secondaryClocks->elapsed, hours);
    AddPlayClockMinutes020ac644(&secondaryClocks->elapsed, minutes);
    func_020ac6b8(&secondaryClocks->elapsed, seconds);

    ts = GetCurrentTimestamp();
    battle->mainTimestamp_ = ts;

    if (commit != 0) {
        BattleRecordPlayClock* committedClock;
        ComputeElapsedPlayTimeHMS020104cc((struct TimeStamp020104cc*)battle, &hours, &minutes, &seconds);
        committedClock = &record.clocks.committed;

        AddPlayClockHours020ac614(committedClock, hours);
        AddPlayClockMinutes020ac644(committedClock, minutes);
        func_020ac6b8(committedClock, seconds);

        AddPlayClockHours020ac614(&secondaryClocks->committed, hours);
        AddPlayClockMinutes020ac644(&secondaryClocks->committed, minutes);
        func_020ac6b8(&secondaryClocks->committed, seconds);

        ts = GetCurrentTimestamp();
        battle->altTimestamp_ = ts;
    }

    return CopyInBattleField0x7540_020ac494(&record);
}
