#include <globaldefs.h>
#include "Util/Random.h"

struct Entry40 { char data[0x40]; };
struct GroupSlot { char data[0x18]; };
struct Record10 { char data[10]; };

struct PairSlot {
    unsigned char a;
    unsigned char b;
    short c;
    int d;
};

struct Battle {
    struct Random rng;
    char pad20[0x5c60 - sizeof(struct Random)];
    Entry40 entries[16];
    char pad6060[0x81b0 - 0x6060];
    unsigned char field_0x81b0;
    unsigned char aliveCount : 4;
    unsigned char groupCount : 2;
    unsigned char field_0x81b1_6 : 2;
    short field_0x81b2;
    GroupSlot groups[3];
    PairSlot pairs[4];
    char pad821c[0x8d5c - 0x821c];
    unsigned char counters[10];
    Record10 records[12];
    char pad8dde[0x8de0 - 0x8dde];
    signed char field_0x8de0[0x20];
    char pad8e00[4];
    short field_0x8e04;
    signed char field_0x8e06;
    unsigned char field_0x8e07;
    char pad8e08[0x8e14 - 0x8e08];
    signed char result;
    unsigned char field_0x8e15;
    char pad8e16[2];
    int field_0x8e18;
    int field_0x8e1c;
    int turnCount;
    char pad8e24[4];
    int field_0x8e28;
    int field_0x8e2c;
    int field_0x8e30;
    int field_0x8e34;
    char pad8e38[4];
    float field_0x8e3c;
    float field_0x8e40;
    unsigned char stack[3];
    unsigned char stackCount;
    signed char field_0x8e48;
    unsigned char mode;
    short field_0x8e4a;
    short field_0x8e4c;
    short field_0x8e4e;
    char pad8e50[0x8e84 - 0x8e50];
    unsigned char field_0x8e84[0x10];
    unsigned char field_0x8e94;
    char pad8e95[2];
    unsigned char field_0x8e97;
    char pad8e98[0x8eb0 - 0x8e98];
    int field_0x8eb0;
};

extern char data_ov000_021838c1[];

extern "C" void func_ov000_0215d090(Battle* battle);
extern "C" void* memset(void* dst, int c, unsigned int n);
unsigned long long GetCurrentTimestamp(void);

// USA: func_ov000_0215ce80
extern "C" ARM void func_ov000_0215ce80(Battle* battle) {
    func_ov000_0215d090(battle);
    battle->field_0x8e18 = 0;
    battle->field_0x8e1c = 0;
    battle->turnCount = 0;
    battle->stackCount = 0;
    battle->field_0x8e48 = -1;
    battle->field_0x8e28 = 0;
    battle->field_0x8e2c = 0;
    battle->field_0x8e30 = 0;
    battle->result = 0;
    battle->field_0x8e34 = 0;
    battle->field_0x8e15 = 0;
    battle->field_0x8e3c = 1.0f;
    battle->field_0x8e40 = 1.0f;
    battle->mode = 0;
    memset(battle->stack, 0, sizeof(battle->stack));
    memset(battle->field_0x8e84, 0, sizeof(battle->field_0x8e84));
    battle->field_0x81b0 = 0;
    battle->aliveCount = 0;
    battle->groupCount = 0;
    battle->field_0x81b1_6 = 0;
    battle->field_0x81b2 = 0;
    for (int i = 0; i < 3; i++) {
        memset(&battle->groups[i], 0, sizeof(GroupSlot));
    }
    for (int i = 0; i < 4; i++) {
        battle->pairs[i].c = 0;
        battle->pairs[i].a = 0;
        battle->pairs[i].b = 0;
        battle->pairs[i].d = 0;
    }
    memset(battle->counters, 0, sizeof(battle->counters));
    battle->field_0x8e07 = 0;
    battle->field_0x8e04 = -1;
    battle->field_0x8e06 = -1;
    battle->field_0x8e4a = 0;
    battle->field_0x8e4c = 0;
    battle->field_0x8e4e = 0;
    battle->field_0x8e97 = 0;
    for (int i = 0; i < 16; i++) {
        memset(&battle->entries[i], 0, sizeof(Entry40));
    }
    for (int i = 0; i < 12; i++) {
        memset(&battle->records[i], 0, sizeof(Record10));
    }
    battle->field_0x8e94 = 0;
    battle->field_0x8eb0 = 1;
    InitRandom(&battle->rng, GetCurrentTimestamp(), data_ov000_021838c1, 1);
    memset(battle->field_0x8de0, -1, sizeof(battle->field_0x8de0));
}
