#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"

struct Reset_021eefac { int phase_; };
struct SearchStruct0202c1a4;
struct Obj02049b54;
struct Obj02046574;
struct TableA68 { int fields_[2]; };
struct BattleActor : Object3D { char padac[0x138 - sizeof(Object3D)]; void* active_; };
struct BattleInfo { char pad0[0x2a]; signed char leader_; };
struct Obj0202ea4c { int field0_; Vector3fix position_, target_; char pad1c[0x40 - 0x1c]; };
struct BattleBossScene {
    char pad0[0x2a0]; BattleInfo* info_;
    char pad2a4[0xc18 - 0x2a4]; Obj0202ea4c camera_;
    char padc58[0xeac - 0xc58]; int endState_;
    char padeb0[0x576c - 0xeb0]; unsigned char levelledUp_;
    char pad576d[0x58c0 - 0x576d]; int experience_;
    char pad58c4[8]; unsigned short turns_;
    char pad58ce[0x5904 - 0x58ce]; TableA68 text_;
    char pad590c[0x6e2e - 0x590c]; unsigned char actorCount_; char pad6e2f;
    unsigned short actors_[3];
};
struct StoreStruct {
    char pad0[0x20]; void* actorContext_;
    char pad24[0x2c8 - 0x24]; int choice_;
    char pad2cc[0x998 - 0x2cc]; int pending_; int field99c_; int state_;
    char pad9a4[0x19b2 - 0x9a4]; unsigned char flag19b2_;
};
struct GrottoZone { char pad0[0x23ec]; ActiveGrottoClass grotto_; };
struct MoveName { char* name_; };
extern "C" Reset_021eefac* _ZZ17GetGlobal021ffefcvE1s;
extern char data_02109bf4[] __attribute__((aligned(4)));
extern char data_ov023_021fe258[];
extern "C" StoreStruct* _Z26GetGlobalField0x1c020421a0v();
int CheckField0NonZero(int*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
void ZeroFieldAndShortTriple0x6e2e(void*);
extern "C" void _Z20ResetFields_021eefacP14Reset_021eefac(Reset_021eefac*);
BattleActor* GetCombatantWithFlag0x400(GameState*, int);
const char* FindEntryByKey(TableA68*, int);
void StoreInArray0x8b0(StoreStruct*, int, int);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void*);
extern "C" void _Z21SetThreeInts_021f00f4Piiii(int*, int, int, int);
extern "C" Vector3fix _Z20GetSubTriple02049b54P11Obj02049b54(Obj02049b54*);
void SetSubstructByte0x56(unsigned char*);
extern "C" void _Z34ComputeAngleHeightDistance0202ea4cP11Obj0202ea4c(Obj0202ea4c*);
extern "C" void _Z19UpdateEntry0216d50cPv(void*);
int GetField0x3acValue(GameState*);
extern "C" void _Z36ResetAndDispatchActorContext0209c6d8Pvs(void*, short);
void DispatchAndSetTreasureMapUnknownBit(char*, int);
extern "C" void _Z31ScaleOrResetCombatants_021ed988Pci(char*, int);
char* GetData02108e10();
extern "C" MoveName* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(Obj02046574*, int, char*);
extern "C" {
void* func_0202ae18();
GrottoZone* func_02012fe4();
void __clear(void*, unsigned int);
void func_020e4ce8(void*, BattleActor*, int);
void func_0204500c(StoreStruct*, const char*, int, int);
int func_ov023_021f4fc8();
void func_ov000_0216d370(void*, int, int, int);
void func_ov000_02163b90(BattleBossScene*, int);
int func_020457e0(StoreStruct*);
void func_02011744(GameState*);
}

// USA: func_ov023_021ef6f4
extern "C" ARM int func_ov023_021ef6f4(BattleBossScene* self) {
    GameState* game = GameState::GetInstance();
    Reset_021eefac* state = _ZZ17GetGlobal021ffefcvE1s;
    StoreStruct* messages = _Z26GetGlobalField0x1c020421a0v();
    void* search = func_0202ae18();
    DetailedTreasureMapData* map = func_02012fe4()->grotto_.GetDetailedData();
    char message[0x300];
    __clear(message, sizeof(message));
    int actorContext[3];
    if (state->phase_ == 0) {
        if (!CheckField0NonZero((int*)search) || self->info_->leader_ == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
            ZeroFieldAndShortTriple0x6e2e(self);
            state->phase_ = 1;
        } else { _Z20ResetFields_021eefacP14Reset_021eefac(state); return 5; }
    } else if (state->phase_ == 1) {
        int count = 1;
        if (map->legacy_.bossID_ == 9) count = 3;
        for (int i = 0; i < count; ++i) {
            BattleActor* actor = GetCombatantWithFlag0x400(game, i + 0xc0);
            if (actor && actor->active_) {
                self->actors_[self->actorCount_] = actor->unknown_4_;
                ++self->actorCount_;
            }
        }
        if ((!map->legacy_.minTurns_ || self->turns_ < map->legacy_.minTurns_) && self->turns_ < 1000) {
            BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            sprintf(message, FindEntryByKey(&self->text_, 0x23));
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0(messages, 0, self->turns_);
            StoreInArray0x8b0(messages, 1, map->legacy_.level_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            state->phase_ = 2;
        } else state->phase_ = 3;
    } else if (state->phase_ == 2) {
        if (!_Z25IsAnimationActive0209ca2cPv(data_02109bf4) && func_ov023_021f4fc8()) state->phase_ = 3;
    } else if (state->phase_ == 3) {
        func_ov000_0216d370(&self->camera_, 1, 1, 1);
        int scale = 0x3000;
        if (map->legacy_.bossID_ == 9) scale = 0x2333;
        int radius = 0;
        int height = 0;
        Vector3fix average;
        _Z21SetThreeInts_021f00f4Piiii(&average.x, 0, 0, 0);
        for (int i = 0; i < self->actorCount_; ++i) {
            BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[i]);
            actor->position_ = _Z20GetSubTriple02049b54P11Obj02049b54((Obj02049b54*)actor);
            actor->rotation_.x = 0;
            actor->rotation_.y = 0;
            actor->rotation_.z = 0;
            Vector3fix_Add(&average, &actor->position_, &average);
            radius += actor->GetRadius();
            if (height < actor->GetHeight()) height = actor->GetHeight();
            actor->MaybeSetRegularAnimation(data_ov023_021fe258, 8);
            actor->TransitionInheritedAlpha(31, 200);
            actor->MakeVisible();
            SetSubstructByte0x56((unsigned char*)actor);
        }
        average.x = fix32_Divide(average.x, self->actorCount_ << 12);
        average.y = fix32_Divide(average.y, self->actorCount_ << 12);
        average.z = fix32_Divide(average.z, self->actorCount_ << 12);
        func_ov000_02163b90(self, 0);
        int halfHeight = fix32_Divide(height, 0x2000);
        Vector3fix target;
        _Z21SetThreeInts_021f00f4Piiii(&target.x, average.x, average.y + halfHeight, average.z);
        int distance = FIX32_MULTIPLY(radius, scale);
        Vector3fix position;
        _Z21SetThreeInts_021f00f4Piiii(&position.x, target.x, target.y, target.z + distance);
        self->camera_.target_ = target;
        self->camera_.position_ = position;
        _Z34ComputeAngleHeightDistance0202ea4cP11Obj0202ea4c(&self->camera_);
        _Z19UpdateEntry0216d50cPv(&self->camera_);
        sprintf(message, FindEntryByKey(&self->text_, 0x1b));
        BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
        if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
        func_020e4ce8(actorContext, actor, 1);
        messages->actorContext_ = actorContext;
        func_0204500c(messages, message, 1, 0xe3);
        messages->flag19b2_ = 0;
        messages->pending_ = 1;
        state->phase_ = 4;
    } else if (state->phase_ == 4) {
        if (func_ov023_021f4fc8()) {
            if (map->legacy_.level_ >= 99) {
                sprintf(message, FindEntryByKey(&self->text_, 0x1d));
                BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
                func_020e4ce8(actorContext, actor, 1);
                messages->actorContext_ = actorContext;
                func_0204500c(messages, message, 1, 0xe3);
                messages->flag19b2_ = 0;
                messages->pending_ = 1;
                state->phase_ = 8;
            } else {
                sprintf(message, FindEntryByKey(&self->text_, 0x1c), map->legacy_.bossName_);
                BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
                func_020e4ce8(actorContext, actor, 1);
                messages->actorContext_ = actorContext;
                func_0204500c(messages, message, 1, 0xe3);
                messages->flag19b2_ = 0;
                messages->pending_ = 1;
                state->phase_ = 5;
            }
        }
    } else if (state->phase_ == 5) {
        if (func_ov023_021f4fc8()) {
            GetCombatantWithFlag0x100(game, GetField0x3acValue(game));
            sprintf(message, FindEntryByKey(&self->text_, 0x1e));
            BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0(messages, 0, self->experience_);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            messages->choice_ = 1;
            state->phase_ = 6;
        }
    } else if (state->phase_ == 6) {
        if (messages->state_ != 3) return self->endState_;
        if (!func_020457e0(messages)) state->phase_ = 7; else state->phase_ = 8;
    } else if (state->phase_ == 7) {
        if (func_ov023_021f4fc8()) {
            self->levelledUp_ = 1;
            sprintf(message, FindEntryByKey(&self->text_, 0x1f));
            BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
            if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
            func_020e4ce8(actorContext, actor, 1);
            messages->actorContext_ = actorContext;
            StoreInArray0x8b0(messages, 0, map->legacy_.level_ + 1);
            func_0204500c(messages, message, 1, 0xe3);
            messages->flag19b2_ = 0;
            messages->pending_ = 1;
            _Z36ResetAndDispatchActorContext0209c6d8Pvs(data_02109bf4, 0x35);
            map->UpdateFollowingCompletion(true, 0);
            DispatchAndSetTreasureMapUnknownBit((char*)game, (int)map);
            func_02011744(game);
            if (map->legacy_.GetLearnedMove(map->legacy_.level_, -1)) state->phase_ = 9;
            else state->phase_ = 11;
        }
    } else if (state->phase_ == 8) {
        _Z31ScaleOrResetCombatants_021ed988Pci((char*)self, 1500);
        map->UpdateFollowingCompletion(false, self->turns_);
        DispatchAndSetTreasureMapUnknownBit((char*)game, (int)map);
        func_02011744(game);
        state->phase_ = 10;
    } else if (state->phase_ == 9) {
        if (func_ov023_021f4fc8()) {
            int move = map->legacy_.GetLearnedMove(map->legacy_.level_, 1);
            if (move) {
                MoveName* name = _Z24SearchBothTables02079e2cPci(GetData02108e10(), (short)move);
                sprintf(message, FindEntryByKey(&self->text_, 0x20));
                BattleActor* actor = GetCombatantWithFlag0x400(game, self->actors_[0]);
                if (map->legacy_.bossID_ == 9) actor = GetCombatantWithFlag0x400(game, self->actors_[1]);
                func_020e4ce8(actorContext, actor, 1);
                messages->actorContext_ = actorContext;
                _Z22SetIndexedName02046574P11Obj02046574iPc((Obj02046574*)messages, 1, name->name_);
                func_0204500c(messages, message, 1, 0xe3);
                messages->flag19b2_ = 0;
                messages->pending_ = 1;
            }
            state->phase_ = 11;
        }
    } else if (state->phase_ == 10) {
        if (!GetCombatantWithFlag0x400(game, self->actors_[0])->GetInheritedAlpha() || !self->actorCount_) state->phase_ = 11;
    } else if (state->phase_ == 11) {
        if (func_ov023_021f4fc8()) { _Z20ResetFields_021eefacP14Reset_021eefac(state); return 5; }
    }
    return self->endState_;
}
