#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include <Filesystem/BackgroundLoader.h>

struct SearchStruct0202c1a4;
struct S_10088;
struct Obj021eea98;
struct TagValueEntry020e385c;
struct S_a0858;
struct S_a0300;

struct Flags_021ed7e0 {
    unsigned int count_ : 10;
    unsigned int flag_ : 1;
    unsigned int fieldC : 7;
    unsigned int fieldD : 7;
    unsigned int rest : 7;
};

struct Words6_021edf54 { int v[6]; };
struct Words9_021edf54 { int v[9]; };
struct Words22_021edf54 { int v[22]; };
struct Words41_021edf54 { int v[41]; };
struct Words13_021edf54 { int v[13]; };
struct Words88_021edf54 { int v[88]; };
struct Words39_021edf54 { int v[39]; };
struct Shorts13_021edf54 { short v[13]; };
struct Shorts8_021edf54 { short v[8]; };
struct Shorts14_021edf54 { short v[14]; };
struct Shorts96_021edf54 { short v[96]; };
struct Bytes13_021edf54 { char v[13]; };
struct Bytes27_021edf54 { char v[27]; };
struct Bytes384_021edf54 { char v[384]; };
struct Bytes36_021edf54 { char v[36]; };
struct Bytes9_021edf54 { char v[9]; };
struct Bytes24_021edf54 { char v[24]; };

struct Record_021edf54 {
    Words6_021edf54 m000;
    Words9_021edf54 m018;
    Words22_021edf54 m03c;
    Words41_021edf54 m094;
    Words13_021edf54 m138;
    Shorts13_021edf54 m16c;
    Bytes13_021edf54 m186;
    Words88_021edf54 m194;
    Words88_021edf54 m2f4;
    Shorts8_021edf54 m454;
    Bytes27_021edf54 m464;
    unsigned long long m480;
    Shorts14_021edf54 m488;
    Shorts96_021edf54 m4a4;
    unsigned short m564;
    unsigned short m566;
    short m568;
    unsigned char m56a;
    unsigned char m56b;
    unsigned char m56c;
    unsigned char m56d;
    unsigned char m56e;
    unsigned char m56f;
    Bytes384_021edf54 m570;
    Words88_021edf54 m6f0;
    Words39_021edf54 m850;
    Bytes36_021edf54 m8ec;
    Bytes9_021edf54 m910;
    Words6_021edf54 m91c;
    Bytes24_021edf54 m934;
    int m94c;
    int level_;
    unsigned short m954;
    short m956;
    short m958;
    short m95a;
    short m95c;
    short m95e;
    unsigned short m960;
    unsigned short m962;

};

struct Result_021edf54 {
    unsigned char member_;
    unsigned char level_;
    unsigned char vocation_;
    unsigned char flag_;
    int exp_;
    char name_[0x30];
    Record_021edf54 record_;
};

struct CombatWork_021edf54 {
    char pad0[0x10];
    unsigned char nothing_;
    char pad11[0xf4 - 0x11];
    char dispatch_[0x24];
    Result_021edf54 results_[4];
    unsigned char resultCount_;
    char region_[4];
    unsigned char regionResult_;
};

struct CombatGlobal_021edf54 {
    CombatWork_021edf54* work_;
};

struct Combatant_021edf54 {
    char pad0[0x134];
    const char* name_;
    char pad138[0x150 - 0x138];
    Record_021edf54* record_;
};

struct Reward_021edf54 {
    unsigned short pad_ : 3;
    unsigned short count_ : 11;
    unsigned short hi_ : 2;
    unsigned short id_;
    short item_;
    unsigned char flag_;
    char pad7[3];
};

struct Outcome_021edf54 {
    unsigned char level_;
    unsigned char pad_ : 6;
    unsigned char kind_ : 2;
    char pad2[0x4e - 2];
    unsigned short id_;
};

struct World_021edf54 {
    char pad0[0x81b0];
    Outcome_021edf54 outcome_;
    char pad8200[0x8d66 - 0x8200];
    Reward_021edf54 rewards_[17];
    char pad8e10[0x8e15 - 0x8e10];
    unsigned char threshold_;
    char pad8e16[0x8e20 - 0x8e16];
    int scaled_;
    char pad8e24[0x8e28 - 0x8e24];
    int baseA_;
    int baseB_;
    int rewardCount_;
    unsigned int bonus_;
    char pad8e38[0x8e3c - 0x8e38];
    float rateA_;
    float rateB_;

    unsigned char GetThreshold() const { return threshold_; }
    int GetBaseA() const { return baseA_; }
    int GetBaseB() const { return baseB_; }
};

struct BattleInfo_021edf54 {
    char pad0[8];
    unsigned short event_;
    char padA[2];
    int type_;
    char pad10[0x25 - 0x10];
    unsigned char special_;
    char pad26[0x2a - 0x26];
    signed char leader_;
};

struct Scene_021edf54 {
    char pad0[0x29c];
    World_021edf54* world_;
    BattleInfo_021edf54* info_;
    char pad2a4[0xeac - 0x2a4];
    int endState_;
    char padeb0[0x5758 - 0xeb0];
    int experience_[4];
    int gold_;
    char pad576c[0x58c0 - 0x576c];
    int valueA_;
    int valueB_;
    unsigned char memberBits_;
    unsigned char outcomeKind_;
    unsigned short outcomeId_;
    unsigned short scaled_;
    char pad58ce[0x58d0 - 0x58ce];
    char drops_[0x5900 - 0x58d0];
    unsigned char dropCount_;
    signed char memberMask_;
    char pad5902[0x6e24 - 0x5902];
    int map_;
    unsigned short mapItem_;
};

struct Resources_021edf54 {
    char pad0[0x42e2];
    unsigned char bossFlag_;
};

struct Renderer_021edf54 {
    char pad0[0x19b2];
    unsigned char active_;
};

struct BattleBlock_021edf54 {
    char pad0[0x68];
    char sub68_[0xb0 - 0x68];
};

extern "C" CombatGlobal_021edf54 _ZZ17GetGlobal021ffefcvE1s;

extern "C" {
int func_ov023_021f5340(void* dispatch);
void* func_0202ae18();
int func_ov000_0215e9fc(World_021edf54* world, short* out, int max, unsigned int flags);
int func_ov000_0215ec1c(World_021edf54* world, short* out, int max, int flags);
int func_ov023_021f4098(Scene_021edf54* self, int id, int bonus);
void func_ov023_021f454c(Scene_021edf54* self);
void func_ov017_021cd218(unsigned short event, unsigned short value, unsigned short scaled, unsigned short bits, unsigned short kind, unsigned short id);
void func_ov017_021cd590(unsigned short event, int* experience, int a, int b);
void func_ov017_021cd35c(unsigned short event, char* drops, unsigned char count, signed char mask);
void _Z27EnqueueEventTag105_021cd4c8tth(unsigned short event, unsigned short item, signed char mask);
int func_0202c540(void* mode);
int func_020abe84(void* unused, short* indices, Flags_021ed7e0* values, int count);
int func_ov023_021f5150(Scene_021edf54* self, BattleInfo_021edf54* info, int* experience, int* gold, int legacy);
}

Renderer_021edf54* GetGlobalField0x1c020421a0();
void ClearSubstructFlag0x4(unsigned char* obj);
void SetFieldForListedCombatants021f50fc();
int CheckField0NonZero(int* mode);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* mode);
int TestBitAt0x34(unsigned char* info, unsigned int index);
int GetField0x3acValue(GameState* game);
int LoadBattleBlock020ac4c0(void* dst);
void AddSaturateField0x48(S_a0858* block, unsigned int amount);
void AddClamped24BitFieldAt0x24(S_a0300* block, unsigned int amount);
int CopyInBattleField0x7540(void* src);
void SetCombatWorkFlags0x55f4(void* self, int flag);
int GetCombatWorkFlags0x55f4(void* self, int flag);
void ClearFlagBits10to24_021ed7e0(Flags_021ed7e0* flags);
int CopyIndexedRegion0x75f0(void* unused, short* indices, int* dest, int count);
unsigned short GetTableValue(void* obj);
int IsFlag10088Set(S_10088* obj);
int GetTableEntry138_021eea98(Obj021eea98* obj);
int GetFieldAt0x150(unsigned char* obj);
unsigned char CopyOutRegion0x571d(char* game, void* dst);
TagValueEntry020e385c* GetData02153660();
void SetEntryBitUnlessMatching020e39d4(TagValueEntry020e385c* tags, int a, int b, int c);

static inline unsigned int Scale(float rate, int value) {
    return value * rate;
}

static inline unsigned int ScaleU(float rate, unsigned int value) {
    return value * rate;
}

// USA: func_ov023_021edf54
extern "C" ARM int func_ov023_021edf54(Scene_021edf54* self) {
    void* mode;
    int seen[8];
    int gained[4];
    short ids[0x10];
    short members[4];
    GameState* game = GameState::GetInstance();
    if (!func_ov023_021f5340(_ZZ17GetGlobal021ffefcvE1s.work_->dispatch_))
        return self->endState_;
    if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0)
        return self->endState_;

    Resources_021edf54* resources = (Resources_021edf54*)func_ov017_0218b5b0();
    Renderer_021edf54* renderer = GetGlobalField0x1c020421a0();
    mode = func_0202ae18();

    World_021edf54* world = self->world_;
    if (world != 0) {
        int i;
        int count;
        GameState* state = GameState::GetInstance();
        count = 0;
        count += func_ov000_0215e9fc(world, ids, 0x10, count);
        count += func_ov000_0215ec1c(world, ids + count, 0x10 - count, 0);
        for (i = 0; i < count; i++) {
            GameObject* c = state->GetCombatantByIndex(ids[i]);
            if (c != 0)
                ClearSubstructFlag0x4((unsigned char*)c);
        }
    }
    SetFieldForListedCombatants021f50fc();

    if (!CheckField0NonZero((int*)mode) || self->info_->leader_ == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)mode)) {
        {
            int base = self->world_->GetBaseA();
            float rate = self->world_->rateA_;
            self->valueA_ = (unsigned int)(base * rate);
        }
        {
            int base = self->world_->GetBaseB();
            float rate = self->world_->rateB_;
            self->valueB_ = (unsigned int)(base * rate);
        }
        self->scaled_ = self->world_->scaled_;

        int memberCount = func_ov000_0215e9fc(self->world_, members, 4, 1);
        self->memberBits_ = 0;
        for (int i = 0; i < memberCount; i++)
            self->memberBits_ |= 1 << members[i];

        int none = 0;
        for (int i = 0; i < 4; i++) {
            if (TestBitAt0x34((unsigned char*)self->info_, (unsigned char)i))
                self->experience_[i] = func_ov023_021f4098(self, i, none);
        }

        World_021edf54* w = self->world_;
        int count = w->rewardCount_;
        int total;
        int unique;
        int i;
        int j;
        Reward_021edf54* rewards = w->rewards_;
        if (count == 0) {
            Outcome_021edf54* outcome = &w->outcome_;
            unsigned char threshold = w->GetThreshold();
            int high = 0;
            if (outcome->level_ <= threshold)
                high = 1;
            if (outcome->kind_ > 1) {
                if (high == 0)
                    self->outcomeKind_ = 5;
                else
                    self->outcomeKind_ = 8;
                self->outcomeId_ = 0;
            } else if (outcome->level_ > 1) {
                if (high == 0)
                    self->outcomeKind_ = 4;
                else
                    self->outcomeKind_ = 7;
                self->outcomeId_ = outcome->id_;
            } else {
                if (high == 0)
                    self->outcomeKind_ = 3;
                else
                    self->outcomeKind_ = 6;
                self->outcomeId_ = outcome->id_;
            }
        } else {
            total = 0;
            unique = 0;
            for (i = 0; i < count; i++) {
                total += rewards[i].count_;
                for (j = 0; j < unique; j++) {
                    if (rewards[i].id_ == seen[j])
                        break;
                }
                if (j == unique)
                    seen[unique++] = rewards[i].id_;
            }
            if (total == 1) {
                self->outcomeKind_ = 0;
                self->outcomeId_ = rewards[0].id_;
            } else if (unique > 1) {
                self->outcomeKind_ = 2;
                self->outcomeId_ = 0;
            } else {
                self->outcomeKind_ = 1;
                self->outcomeId_ = rewards[0].id_;
            }
        }

        func_ov023_021f454c(self);
        func_ov017_021cd218(self->info_->event_, self->valueB_, self->scaled_, self->memberBits_, self->outcomeKind_, self->outcomeId_);
        if (self->info_->special_ == 0) {
            func_ov017_021cd590(self->info_->event_, self->experience_, 0, 0);
            func_ov017_021cd35c(self->info_->event_, self->drops_, self->dropCount_, self->memberMask_);
            if (self->map_ != 0)
                _Z27EnqueueEventTag105_021cd4c8tth(self->info_->event_, self->mapItem_, self->memberMask_);
            if (self->world_->bonus_ != 0) {
                unsigned int bonus = ScaleU(self->world_->rateA_, self->world_->bonus_);
                GameState* state = GameState::GetInstance();
                for (int i = 0; i < 4; i++) {
                    if (TestBitAt0x34((unsigned char*)self->info_, (unsigned char)i))
                        gained[i] = func_ov023_021f4098(self, i, bonus);
                }
                func_ov017_021cd590(self->info_->event_, gained, 0, 1);
                int leader = GetField0x3acValue(state);
                BattleBlock_021edf54 block;
                LoadBattleBlock020ac4c0(&block);
                AddSaturateField0x48((S_a0858*)&block, gained[leader]);
                AddClamped24BitFieldAt0x24((S_a0300*)block.sub68_, gained[leader]);
                CopyInBattleField0x7540(&block);
            }
        }
    } else {
        if (resources->bossFlag_ != 0)
            SetCombatWorkFlags0x55f4(self, 0x2000000);
        if (func_0202c540(mode) && self->info_->special_ != 0)
            renderer->active_ = 0;
        if (!GetCombatWorkFlags0x55f4(self, 0x2000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4(self, 0x4000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4(self, 0x8000))
            return self->endState_;
    }

    Reward_021edf54* reward;
    int i;
    Reward_021edf54* rewards;
    int rewardCount;
    World_021edf54* w = self->world_;
    rewardCount = w->rewardCount_;
    rewards = w->rewards_;
    for (i = 0; i < rewardCount; i++) {
        reward = &rewards[i];
        Flags_021ed7e0 flags;
        ClearFlagBits10to24_021ed7e0(&flags);
        short item = reward->item_;
        if (CopyIndexedRegion0x75f0(0, &item, (int*)&flags, 1)) {
            unsigned int total = flags.count_ + reward->count_;
            if (total > 999)
                total = 999;
            flags.count_ = total;
            if (reward->flag_ != 0)
                flags.flag_ = reward->flag_;
            func_020abe84(0, &item, &flags, 1);
        }
    }

    Result_021edf54* result = _ZZ17GetGlobal021ffefcvE1s.work_->results_;
    for (int i = 0; i < 4; i++) {
        if (TestBitAt0x34((unsigned char*)self->info_, (unsigned char)i)) {
            Combatant_021edf54* c = (Combatant_021edf54*)GetCombatantWithFlag0x100(game, i);
            if (c != 0) {
                result->member_ = i;
                result->level_ = c->record_->level_;
                result->vocation_ = GetTableValue(c);
                result->flag_ = IsFlag10088Set((S_10088*)c);
                result->exp_ = self->experience_[i] + GetTableEntry138_021eea98((Obj021eea98*)c);
                Record_021edf54* src = (Record_021edf54*)GetFieldAt0x150((unsigned char*)c);
                result->record_.m000 = src->m000;
                result->record_.m018 = src->m018;
                result->record_.m03c = src->m03c;
                result->record_.m094 = src->m094;
                result->record_.m138 = src->m138;
                result->record_.m16c = src->m16c;
                result->record_.m186 = src->m186;
                result->record_.m194 = src->m194;
                result->record_.m2f4 = src->m2f4;
                result->record_.m454 = src->m454;
                result->record_.m464 = src->m464;
                result->record_.m480 = src->m480;
                result->record_.m488 = src->m488;
                result->record_.m4a4 = src->m4a4;
                result->record_.m564 = src->m564;
                result->record_.m566 = src->m566;
                result->record_.m568 = src->m568;
                result->record_.m56a = src->m56a;
                result->record_.m56b = src->m56b;
                result->record_.m56c = src->m56c;
                result->record_.m56d = src->m56d;
                result->record_.m56e = src->m56e;
                result->record_.m56f = src->m56f;
                result->record_.m570 = src->m570;
                result->record_.m6f0 = src->m6f0;
                result->record_.m850 = src->m850;
                result->record_.m8ec = src->m8ec;
                result->record_.m910 = src->m910;
                result->record_.m91c = src->m91c;
                result->record_.m934 = src->m934;
                result->record_.m94c = src->m94c;
                result->record_.level_ = src->level_;
                result->record_.m954 = src->m954;
                result->record_.m956 = src->m956;
                result->record_.m958 = src->m958;
                result->record_.m95a = src->m95a;
                result->record_.m95c = src->m95c;
                result->record_.m95e = src->m95e;
                result->record_.m960 = src->m960;
                result->record_.m962 = src->m962;
                strcpy(result->name_, c->name_);
                result++;
                _ZZ17GetGlobal021ffefcvE1s.work_->resultCount_++;
            }
        }
    }
    _ZZ17GetGlobal021ffefcvE1s.work_->regionResult_ = CopyOutRegion0x571d((char*)game, _ZZ17GetGlobal021ffefcvE1s.work_->region_);

    if (self->info_->special_ == 0)
        _ZZ17GetGlobal021ffefcvE1s.work_->nothing_ = func_ov023_021f5150(self, self->info_, self->experience_, &self->gold_, 0) ? 1 : 0;

    if (func_0202c540(mode) && self->info_->type_ == 0x13)
        SetEntryBitUnlessMatching020e39d4(GetData02153660(), 0, 1, 0x71e8);
    return 2;
}
