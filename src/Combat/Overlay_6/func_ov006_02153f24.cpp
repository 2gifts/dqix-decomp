#if defined(jpn)
#define R(j,u) (j)
#define data_ov006_0215ffb4 data_ov006_02161318
#define data_ov006_0215ffc0 data_ov006_0216131b
#define data_ov006_0215ffc4 data_ov006_02161328
#define data_ov006_0215ffca data_ov006_02161336
#define data_ov006_0215ffe2 data_ov006_0216132e
#define data_ov006_0215fff4 data_ov006_02161346
#define func_ov006_021547c8 func_ov006_02155f30
#define func_ov006_021570fc func_ov006_02158704
#define func_ov006_0215f4dc func_ov006_021608fc
#define func_ov006_0215f740 func_ov006_02160b08
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Recipe {
    short id_;
    short item_;
    short ingredients_[3];
    unsigned short amount0_ : 4;
    unsigned short amount1_ : 4;
    unsigned short amount2_ : 4;
    unsigned short stat_ : 4;
    unsigned int minRate_ : 10;
    unsigned int maxRate_ : 10;
    unsigned int kind_ : 8;
    unsigned int unk_c_28 : 4;
    unsigned int minStat_ : 10;
    unsigned int maxStat_ : 10;
    unsigned int unk_10_20 : 2;
    unsigned int known_ : 1;
    unsigned int unk_10_23 : 9;
};

struct List02071d60;

extern "C" Recipe* _Z22FindEntryByKey02071d60P12List02071d60i(List02071d60* list, int key);

struct PartyMemberData {
    unsigned int unk_0_0 : 10;
    unsigned int unk_0_10 : 10;
    unsigned int unk_0_20 : 10;
    unsigned int unk_0_30 : 2;
    unsigned int unk_4_0 : 10;
    unsigned int unk_4_10 : 10;
    unsigned int unk_4_20 : 10;
    unsigned int unk_4_30 : 2;
    unsigned int unk_8_0 : 10;
    unsigned int unk_8_10 : 22;
};

struct PrimaryCombatStats {
    unsigned short currHP;
    unsigned short currMP;
    unsigned short maxHP;
    unsigned short maxMP;
};

struct BaseCombatStats {
    char unk[0x2C];
    PrimaryCombatStats primaryStats;
};

class GameObject {
public:
    char unk_0[0x134];
    BaseCombatStats* baseStats_;
    void* currentStats_;
    char unk_13c[R(8, 0x14)];
    PartyMemberData* partyData_;
};

class GameState {
public:
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct AlchemyIngredients {
    List02071d60* table_;
};

// USA: func_ov006_02153f24
extern "C" ARM short func_ov006_02153f24(AlchemyIngredients* self, short id) {
    Recipe* recipe = _Z22FindEntryByKey02071d60P12List02071d60i(self->table_, id);
    if (recipe == 0)
        return 0;
    short rate = 100;
    if (recipe->stat_ != 0) {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        if (protagonist != 0) {
            unsigned short value = 0;
            switch (recipe->stat_) {
            case 1:
                value = protagonist->partyData_->unk_0_0;
                break;
            case 2:
                value = protagonist->partyData_->unk_0_10;
                break;
            case 3:
                value = protagonist->partyData_->unk_0_20;
                break;
            case 4:
                value = protagonist->partyData_->unk_4_0;
                break;
            case 5:
                value = protagonist->partyData_->unk_4_10;
                break;
            case 6:
                value = protagonist->partyData_->unk_4_20;
                break;
            case 7:
                value = protagonist->partyData_->unk_8_0;
                break;
            case 8:
                value = protagonist->baseStats_->primaryStats.maxHP;
                break;
            case 9:
                value = protagonist->baseStats_->primaryStats.maxMP;
                break;
            }
            unsigned int minRate = recipe->minRate_;
            unsigned int maxRate = recipe->maxRate_;
            float rateRange = maxRate - minRate;
            unsigned int minStat = recipe->minStat_;
            float statRange = recipe->maxStat_ - minStat;
            rate = (int)(((float)value - minStat) * (rateRange / statRange)) + minRate;
            if (rate > 100)
                rate = 100;
            else if (rate < 0)
                rate = 0;
            if (rate <= minRate)
                rate = minRate;
            if (maxRate <= rate)
                rate = maxRate;
        }
    }
    return rate;
}
