#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Util/Random.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" int func_02032370(int span);

struct S_10088;
struct Obj53dfc;
struct Container02070e60;

int GetCheckedSignedByte_02011518(void* obj, unsigned int idx);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned int index);
int IsFlag10088Set_02010088(struct S_10088* obj);
int GetField8FromField19c_02053dfc(struct Obj53dfc* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);
unsigned short GetTableValue_0202053c(void* obj);

struct Element_021f454c {
    unsigned short key;
    unsigned char type2;
    unsigned char type3;
    unsigned short item4;
    unsigned short item6;
};

struct Element_021f454c* SearchWithLow15Comparator02070fd0(struct Container02070e60* container, int key);

extern int data_ov023_021fd888[];

struct Combatant_021f454c {
    char pad0[0x150];
    unsigned char* status;
};

struct Reward_021f454c {
    unsigned short action : 3;
    unsigned short count : 11;
    unsigned short flagA : 1;
    unsigned short flagB : 1;
    unsigned short key;
    unsigned short optional;
    unsigned char flags;
    unsigned char detailFlags;
    unsigned char credited;
    unsigned char specialCount;
};

struct World_021f454c {
    char pad0[0x8d66];
    struct Reward_021f454c rewards[12];
    char pad8dde[0x8e30 - 0x8dde];
    int rewardCount;
};

struct Info_021f454c {
    char pad0[0x24];
    unsigned char f24;
    unsigned char special;
};

struct Drop_021f454c {
    unsigned short id;
    unsigned short key : 15;
    unsigned short top : 1;
    unsigned char kind;
    signed char member;
};

struct Scene_021f454c {
    char pad0[0x29c];
    struct World_021f454c* world;
    struct Info_021f454c* info;
    char pad2a4[0x58cc - 0x2a4];
    unsigned short scaled;
    char pad58ce[2];
    struct Drop_021f454c drops[8];
    unsigned char dropCount;
    signed char memberMask;
    char pad5902[0x6e24 - 0x5902];
    int map;
    unsigned short mapItem;
    unsigned char mapType;
    unsigned char mapBoss;
    unsigned short mapLegacy;
};

#define IsSpecial(info) ((info)->f24 != 0 || (info)->special != 0)

// USA: func_ov023_021f454c
extern "C" ARM void func_ov023_021f454c(struct Scene_021f454c* self) {
    unsigned char buf[4];
    GameState* gs;
    unsigned short altId;
    int count;
    float scaledF;
    int rate;
    struct Random* rng;
    int j;
    int key;
    struct Reward_021f454c* rewards;
    int tA;
    int tB;
    struct Container02070e60* table;
    DetailedTreasureMapData* detail;
    int round;
    int chance;
    struct Reward_021f454c* r;
    struct Drop_021f454c* cur;

    gs = GameState::GetInstance();
    table = (struct Container02070e60*)((char*)self->info + 0x684);
    func_0202ae18();
    detail = ((ActiveGrottoClass*)((char*)func_02012fe4() + 0x23ec))->GetDetailedData();
    altId = 0;
    if (IsSpecial(self->info)) {
        if (detail->mapType_ == 1) {
            altId = detail->regular_.bossMonsterID_;
        } else if (detail->mapType_ == 2) {
            altId = detail->legacy_.MaybeGetCurrentAlternateID();
        }
    }

    self->dropCount = 0;
    self->memberMask = 0;
    count = self->world->rewardCount;
    rewards = self->world->rewards;
    cur = self->drops;
    scaledF = (float)self->scaled;
    for (round = 0; round < 5; round++) {
        rate = 100;
        if (round > 0) {
            int member = GetCheckedSignedByte_02011518(gs, (unsigned char)(round - 1));
            struct Combatant_021f454c* c = (struct Combatant_021f454c*)GetCombatantWithFlag0x100_0200ff1c(gs, member);
            if (c == 0) continue;
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->info, (unsigned char)member)) continue;
            if (IsFlag10088Set_02010088((struct S_10088*)c)) continue;
            if ((float)(unsigned int)GetField8FromField19c_02053dfc((struct Obj53dfc*)c) / scaledF < 0.5f) continue;
            if (!TestBitInArray0x8ec_02083b00(c->status, 0xa4)) continue;
            rate = GetTableValue_0202053c(c);
            cur->member = member;
        } else {
            cur->member = -1;
        }

        if (IsSpecial(self->info)) {
            int i;
            for (i = 0; i < count; i++) {
                if (altId == rewards[i].key) break;
            }
            struct Reward_021f454c* found = 0;
            if (i < count) found = &rewards[i];
            rng = GetBTRandom();
            for (int k = 2; k >= 0; k--) {
                chance = detail->treasureDropRates_[k];
                if (round > 0) {
                    int v = chance * rate / 100;
                    if (detail->treasureDropRates_[k] >= 100) v = 0;
                    chance = v;
                } else if (found != 0) {
                    if (found->flagA && k == 2) chance = 100;
                    if (found->flagB && k == 1) chance = 100;
                }
                if (NextRandomMax(rng, 100) >= chance) continue;
                detail->discoveredTreasures_[k] = 1;
                if (GetTreasureMapTypeFromItemID(detail->treasureItemIDs_[k], buf)) {
                    if (self->map == 0) {
                        self->map = 1;
                        self->mapItem = detail->treasureItemIDs_[k];
                        self->mapType = buf[0];
                        self->mapBoss = buf[1];
                        self->mapLegacy = *(unsigned short*)&buf[2];
                    }
                    continue;
                }
                cur->id = detail->treasureItemIDs_[k];
                cur->key = altId;
                struct Element_021f454c* e = SearchWithLow15Comparator02070fd0(table, altId);
                if (e != 0) {
                    if (e->item6 == cur->id) {
                        cur->kind = 2;
                    } else if (e->item4 == cur->id) {
                        cur->kind = 1;
                    } else {
                        cur->kind = 0;
                    }
                }
                self->dropCount++;
                if (self->dropCount >= 8) break;
                signed char m = cur->member;
                cur++;
                cur->member = m;
            }
        }

        if (self->dropCount >= 8) break;

        for (j = 0; j < count; j++) {
            r = &rewards[j];
            if (r->count == r->specialCount) continue;
            key = r->key;
            struct Element_021f454c* e = SearchWithLow15Comparator02070fd0(table, key);
            if (e == 0) continue;
            if (IsSpecial(self->info) && altId == key) continue;

            tA = e->type3;
            int chanceA = data_ov023_021fd888[tA];
            if (chanceA > 0) {
                if (round > 0) {
                    int v = chanceA * 100 / rate;
                    if (tA == 0) v = 0;
                    chanceA = v;
                } else if (r->flagA) {
                    chanceA = 1;
                }
                if (chanceA > 0 && func_02032370(chanceA) == 0) {
                    cur->id = e->item6;
                    cur->key = key;
                    cur->kind = 2;
                    self->dropCount++;
                    if (self->dropCount >= 8) break;
                    signed char m = cur->member;
                    cur++;
                    cur->member = m;
                    continue;
                }
            }

            tB = e->type2;
            int chanceB = data_ov023_021fd888[tB];
            if (chanceB <= 0) continue;
            if (round > 0) {
                int v = chanceB * 100 / rate;
                if (tB == 0) v = 0;
                chanceB = v;
            } else if (r->flagB) {
                chanceB = 1;
            }
            if (chanceB <= 0) continue;
            if (func_02032370(chanceB) != 0) continue;
            cur->id = e->item4;
            cur->key = key;
            cur->kind = 1;
            self->dropCount++;
            if (self->dropCount >= 8) break;
            signed char m = cur->member;
            cur++;
            cur->member = m;
        }

        if (self->dropCount >= 8) break;
    }

    if (self->dropCount != 0 || self->map != 0) {
        for (int i = 0; i < 4; i++) {
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->info, (unsigned char)i)) continue;
            struct Combatant_021f454c* c = (struct Combatant_021f454c*)GetCombatantWithFlag0x100_0200ff1c(gs, i);
            if (c == 0) continue;
            if (!((float)(unsigned int)GetField8FromField19c_02053dfc((struct Obj53dfc*)c) / scaledF < 0.5f)) {
                self->memberMask |= 1 << i;
            }
        }
    }
}
