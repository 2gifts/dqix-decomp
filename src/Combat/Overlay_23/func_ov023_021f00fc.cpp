#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct Obj021eea98;

struct BattleInfo_021f00fc {
    char unk_0[8];
    unsigned short unk_8;
    char unk_a[0x2a - 0xa];
    signed char leader_;
};

struct BattleResultMember_021f00fc {
    char unk_0[4];
    unsigned int experience_;
};

struct BattleEnd_021f00fc {
    char unk_0[0x10];
    unsigned char nothing_;
};

struct BattleScene_021f00fc {
#if defined(jpn)
    char unk_0[0x21c];
#else
    char unk_0[0x2a0];
#endif
    BattleInfo_021f00fc* info_;
    char unk_2a4[0xeac - 0x2a4];
    int endState_;
#if defined(jpn)
    char unk_eb0[0x5948 - 0xe2c];
#else
    char unk_eb0[0x5758 - 0xeb0];
#endif
    int experience_[4];
    int gold_;
    unsigned char legacyBossLevelUp_;
    char unk_576d[0x58d0 - 0x576d];
    char drops_[0x5900 - 0x58d0];
    unsigned char dropCount_;
    signed char memberMask_;
    char unk_5902[0x6e24 - 0x5902];
    int map_;
    unsigned short mapItem_;
};

extern "C" BattleEnd_021f00fc* _ZZ17GetGlobal021ffefcvE1s;

void GetGlobalField0x1c020421a0();
int CheckField0NonZero_0202b7d8(int* unknown);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* unknown);
int CollectCombatantsWithFlag0x1000_02010038(GameState* gameState, unsigned char* members);
int TestBitAt0x34_020a35e0(unsigned char* info, unsigned char member);
BattleResultMember_021f00fc* FindByByteAt118_021f0360(void* end, int member);
unsigned int GetTableEntry138_021eea98(Obj021eea98* member);
void EnqueueEventTag105_021cd4c8(unsigned short, unsigned short, signed char);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* scene, int flag);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void* scene, int flag);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* func_0202ae18();
void func_ov017_021cd590(unsigned short a, int* experience, unsigned char b, int c);
void func_ov017_021cd35c(unsigned short a, void* drops, unsigned char count, signed char mask);
int func_ov023_021f5150(BattleScene_021f00fc* self, BattleInfo_021f00fc* info, int* experience, int* gold, int legacy);
}

// USA: func_ov023_021f00fc
extern "C" ARM int func_ov023_021f00fc(BattleScene_021f00fc* self)
{
    GameState* gameState = GameState::GetInstance();
    GetGlobalField0x1c020421a0();
    void* unk = func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    if (!CheckField0NonZero_0202b7d8((int*)unk) || self->info_->leader_ == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)unk))
    {
        unsigned char alive[4];
        __clear(alive, sizeof(alive));
        if (self->legacyBossLevelUp_ != 0)
        {
            unsigned char members[4];
            int count = CollectCombatantsWithFlag0x1000_02010038(gameState, members);
            for (int i = 0; i < count; i++)
                alive[members[i]] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            if (TestBitAt0x34_020a35e0((unsigned char*)self->info_, i) && alive[i] != 0)
            {
                BattleResultMember_021f00fc* member = FindByByteAt118_021f0360(_ZZ17GetGlobal021ffefcvE1s, i);
                GameObject* partyMember = GetCombatantWithFlag0x100_0200ff1c(gameState, i);
                if (member != NULL)
                    member->experience_ = GetTableEntry138_021eea98((Obj021eea98*)partyMember);
                self->experience_[i] = 0;
            }
        }
        func_ov017_021cd590(self->info_->unk_8, self->experience_, self->legacyBossLevelUp_, 0);
        func_ov017_021cd35c(self->info_->unk_8, self->drops_, self->dropCount_, self->memberMask_);
        if (self->map_ != 0)
            EnqueueEventTag105_021cd4c8(self->info_->unk_8, self->mapItem_, self->memberMask_);
    }
    else
    {
        if (resources->unknown_flag_42e2 != 0)
            SetCombatWorkFlags0x55f4_ov000_02160fa8(self, 0x2000000);
        if (!GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x4000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x8000))
            return self->endState_;
    }
    _ZZ17GetGlobal021ffefcvE1s->nothing_ =func_ov023_021f5150(self, self->info_, self->experience_, &self->gold_, self->legacyBossLevelUp_) ? 1 : 0;
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        if (TestBitAt0x34_020a35e0((unsigned char*)self->info_, i))
            total += self->experience_[i];
    }
    if (total > 0)
        return 6;
    return 0xb;
}
