#ifndef GAMESTATE_BATTLE_RECORD_SNAPSHOT_H
#define GAMESTATE_BATTLE_RECORD_SNAPSHOT_H



struct BattleRecordPlayClock {
    unsigned short hours;
    unsigned char minutes;
    unsigned char seconds;
};

void ClearShortByteByte_02184598(BattleRecordPlayClock*);

struct BattleRecordClockPair {
    BattleRecordPlayClock elapsed;
    BattleRecordPlayClock committed;
};

struct BattleRecordCapture {
    BattleRecordPlayClock playClock;
    BattleRecordPlayClock committedPlayClock;
    unsigned int unknown08_0 : 17;
    unsigned int unknown08_17 : 7;
    unsigned int unknown08_24 : 7;
    unsigned int unknown08_31 : 1;
    unsigned int unknown0c_0 : 17;
    unsigned int unknown0c_17 : 7;
    unsigned int unknown0c_24 : 7;
    unsigned int unknown0c_31 : 1;
    unsigned int unknown10_0 : 9;
    unsigned int unknown10_9 : 14;
    unsigned int unknown10_23 : 9;
    unsigned int unknown14_0 : 8;
    unsigned int unknown14_8 : 14;
    unsigned int unknown14_22 : 10;
    unsigned int unknown18_0 : 24;
    unsigned int captured : 1;
    unsigned int unknown18_25 : 7;
    unsigned int unknown1c;
};

struct BattleRecordSnapshot {
    BattleRecordClockPair clocks;
    unsigned int unknown08_0 : 24;
    unsigned int unknown08_24 : 8;
    unsigned int unknown0c_0 : 14;
    unsigned int unknown0c_14 : 14;
    unsigned int unknown0c_28 : 4;
    unsigned int unknown10_0 : 9;
    unsigned int unknown10_9 : 14;
    unsigned int unknown10_23 : 9;
    unsigned int unknown14_0 : 9;
    unsigned int unknown14_9 : 9;
    unsigned int unknown14_18 : 11;
    unsigned int unknown14_29 : 3;
    unsigned int unknown18_0 : 9;
    unsigned int unknown18_9 : 7;
    unsigned int unknown18_16 : 4;
    unsigned int unknown18_20 : 12;
    unsigned int unknown1c_0 : 16;
    unsigned int unknown1c_16 : 16;
    unsigned int unknown20_0 : 16;
    unsigned int unknown20_16 : 16;
    unsigned int unknown24;
    unsigned int unknown28_0 : 12;
    unsigned int unknown28_12 : 10;
    unsigned int unknown28_22 : 10;
    unsigned int unknown2c_0 : 24;
    unsigned int unknown2c_24 : 8;
    unsigned int unknown30_0 : 24;
    unsigned int unknown30_24 : 8;
    unsigned int unknown34_0 : 24;
    unsigned int unknown34_24 : 8;
    unsigned int unknown38_0 : 24;
    unsigned int unknown38_24 : 8;
    unsigned int unknown3c_0 : 24;
    unsigned int unknown3c_24 : 8;
    unsigned int unknown40_0 : 24;
    unsigned int unknown40_24 : 8;
    unsigned int unknown44;
    unsigned int unknown48;
    unsigned char unknown4c[0x1c];
    BattleRecordClockPair secondaryClocks;
    unsigned int unknown70[5];
    unsigned int unknown84_0 : 10;
    unsigned int unknown84_10 : 16;
    unsigned int unknown84_26 : 6;
    unsigned int unknown88_0 : 24;
    unsigned int unknown88_24 : 8;
    unsigned int unknown8c_0 : 24;
    unsigned int unknown8c_24 : 8;
    BattleRecordCapture capture;
};

typedef char BattleRecordSnapshotSizeCheck[sizeof(BattleRecordSnapshot) == 0xb0 ? 1 : -1];

int LoadBattleBlock020ac4c0(void* destination);

#endif
