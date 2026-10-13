#ifndef GAMESTATE_OVERLAY17_DAY_CYCLE_H
#define GAMESTATE_OVERLAY17_DAY_CYCLE_H

struct Overlay17DayTiming {
#if defined(jpn)
    float nightDuration;
    int lootableLoadTask;
    float dayDuration;
    float boundaryStep;
    float eveningDuration;
    float morningDuration;
#else
    float boundaryStep;
    int lootableLoadTask;
    float nightDuration;
    float morningDuration;
    float eveningDuration;
    float dayDuration;
#endif
};

struct Overlay17DayBoundaries {
    float unknown0;
#if defined(jpn)
    float cycleLength;
#endif
    float dayStart;
    float eveningStart;
    float morningStart;
    float nightStart;
#if !defined(jpn)
    float cycleLength;
#endif
};

typedef char Overlay17DayTimingSizeCheck[sizeof(Overlay17DayTiming) == 0x18 ? 1 : -1];
typedef char Overlay17DayBoundariesSizeCheck[sizeof(Overlay17DayBoundaries) == 0x18 ? 1 : -1];

extern Overlay17DayTiming data_ov017_021d75b8;
extern Overlay17DayBoundaries data_ov017_021d837c;

#endif
