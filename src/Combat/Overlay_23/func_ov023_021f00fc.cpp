#include <globaldefs.h>

struct SearchStruct0202c1a4;
struct Obj021eea98;

struct GameState {
    static GameState* GetInstance();
};

struct GameResources_021f00fc {
#if defined(jpn)
    char unk_0[0x40c2];
#else
    char unk_0[0x42e2];
#endif
    unsigned char unknown_42e2;
};

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

extern "C" void _Z26GetGlobalField0x1c020421a0v();
int CheckField0NonZero(int* unknown);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* unknown);
int CollectCombatantsWithFlag0x1000(GameState* gameState, unsigned char* members);
int TestBitAt0x34(unsigned char* info, unsigned int member);
extern "C" BattleResultMember_021f00fc* _Z24FindByByteAt118_021f0360Pvi(void* end, int member);
void* GetCombatantWithFlag0x100(GameState* gameState, int member);
extern "C" unsigned int _Z25GetTableEntry138_021eea98P11Obj021eea98(Obj021eea98* member);
extern "C" void _Z27EnqueueEventTag105_021cd4c8tth(unsigned short a, unsigned short item, unsigned char mask);
void SetCombatWorkFlags0x55f4(void* scene, int flag);
int GetCombatWorkFlags0x55f4(void* scene, int flag);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* func_0202ae18();
GameResources_021f00fc* func_ov017_0218b5b0();
void func_ov017_021cd590(unsigned short a, int* experience, unsigned char b, int c);
void func_ov017_021cd35c(unsigned short a, void* drops, unsigned char count, signed char mask);
int func_ov023_021f5150(BattleScene_021f00fc* self, BattleInfo_021f00fc* info, int* experience, int* gold, int legacy);
}

// JPN: func_ov023_021efd08
// USA: func_ov023_021f00fc
extern "C" ARM int func_ov023_021f00fc(BattleScene_021f00fc* self)
{
    GameState* gameState = GameState::GetInstance();
    _Z26GetGlobalField0x1c020421a0v();
    void* unk = func_0202ae18();
    GameResources_021f00fc* resources = func_ov017_0218b5b0();
    if (!CheckField0NonZero((int*)unk) || self->info_->leader_ == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)unk))
    {
        unsigned char alive[4];
        __clear(alive, sizeof(alive));
        if (self->legacyBossLevelUp_ != 0)
        {
            unsigned char members[4];
            int count = CollectCombatantsWithFlag0x1000(gameState, members);
            for (int i = 0; i < count; i++)
                alive[members[i]] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            if (TestBitAt0x34((unsigned char*)self->info_, (unsigned char)i) && alive[i] != 0)
            {
                BattleResultMember_021f00fc* member = _Z24FindByByteAt118_021f0360Pvi(_ZZ17GetGlobal021ffefcvE1s, i);
                void* partyMember = GetCombatantWithFlag0x100(gameState, i);
                if (member != NULL)
                    member->experience_ = _Z25GetTableEntry138_021eea98P11Obj021eea98((Obj021eea98*)partyMember);
                self->experience_[i] = 0;
            }
        }
        func_ov017_021cd590(self->info_->unk_8, self->experience_, self->legacyBossLevelUp_, 0);
        func_ov017_021cd35c(self->info_->unk_8, self->drops_, self->dropCount_, self->memberMask_);
        if (self->map_ != 0)
            ((void (*)(unsigned short, unsigned short, signed char))_Z27EnqueueEventTag105_021cd4c8tth)(self->info_->unk_8, self->mapItem_, self->memberMask_);
    }
    else
    {
        if (resources->unknown_42e2 != 0)
            SetCombatWorkFlags0x55f4(self, 0x2000000);
        if (!GetCombatWorkFlags0x55f4(self, 0x4000))
            return self->endState_;
        if (!GetCombatWorkFlags0x55f4(self, 0x8000))
            return self->endState_;
    }
    _ZZ17GetGlobal021ffefcvE1s->nothing_ =func_ov023_021f5150(self, self->info_, self->experience_, &self->gold_, self->legacyBossLevelUp_) ? 1 : 0;
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        if (TestBitAt0x34((unsigned char*)self->info_, (unsigned char)i))
            total += self->experience_[i];
    }
    if (total > 0)
        return 6;
    return 0xb;
}
