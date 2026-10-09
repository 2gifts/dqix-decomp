#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct Words021edf38 { unsigned int a_, b_, c_; };
struct Pair0209a338 { int first_, second_; };
struct Actor0209c678;
struct Obj020d6f0c;
struct Container020d6d18;
struct Container0203a54c;
struct TagValueEntry020e385c;
struct BinarySearchByComparatorStruct { int fields_[4]; };
struct BattleInfo {
    char pad0[8]; unsigned short event_; char padA[2]; int type_;
    char pad10[0x25 - 0x10]; unsigned char special_; char pad26[0x678 - 0x26];
    BinarySearchByComparatorStruct rewards_;
};
struct CombatScreen {
    char pad0[0x2a0]; BattleInfo* battle_; char pad2A4[0xc18 - 0x2a4];
    int camera_[1]; char padC1C[0xea4 - 0xc1c]; Obj020d6f0c* manager_;
    char padEA8[0x6ffc - 0xea8]; char entries_[1];
};
struct CombatWork {
    int state_; int tasks_[3]; unsigned char field10_; unsigned char field11_;
    unsigned char flags_[4]; char pad16[2]; int field18_; char buffer_[0x20];
    char pad3C[0x6c - 0x3c]; int field6C_; int field70_; char pad74[0xe2 - 0x74];
    unsigned char fieldE2_; char padE3; signed char rewardIndex_; signed char fieldE5_;
    char padE6[2]; Pair0209a338 pair_; int fieldF0_; int dispatch_[6];
    Words021edf38 words_; char data_[0x2670]; unsigned char field2788_; char pad2789[7];
};
struct CombatGlobal { CombatWork* work_; int field4_; int flags_; };
struct TextRenderer {
    char pad0[0x10]; void* argument_; char pad14[0x998 - 0x14]; int active_;
};
struct ZoneData { char pad0[0x23ec]; ActiveGrottoClass grotto_; };
struct GrottoRewardView { short field0_, field2_; short ids_[3]; };
struct SoundIds { int ids_[6]; };
extern "C" CombatGlobal _ZZ17GetGlobal021ffefcvE1s;
extern Actor0209c678 data_02109bf4;
extern const SoundIds data_ov023_021fd870;
extern "C" void* func_0202ae18();
TextRenderer* GetGlobalField0x1c020421a0();
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int*, unsigned int);
void EnqueueEventTag86_021c9ad4(unsigned short);
extern "C" void func_ov017_021a23b0(GameResources*, int);
void DispatchContextByState0209c678(Actor0209c678*, int);
extern "C" void func_ov000_0216d370(void*, int, int, int);
extern "C" void* func_02057924();
extern "C" void func_02057f00(void*, int);
void DestroyAllocatorAt0xa28(Obj020d6f0c*);
void ConstructEntryManager020d6d18(Container020d6d18*);
void ResetArrayAndEntry021823a4(char*);
Container0203a54c* GetData02104b6c();
void ProcessAllSubObjects0203a54c(Container0203a54c*);
void ClearFirstTwoWords0209a338(Pair0209a338*);
void ClearField00209a804(int*);
void ResetAndInit_021f52a0(void*);
void Clear12Bytes0206efc4(void*);
void PushInputLogB(int);
void InitAndDispatch_021f52f8(void*, void*);
extern "C" int func_0202c540(void*);
extern "C" void func_02046380(TextRenderer*);
extern "C" ZoneData* func_02012fe4();
void Clear12Bytes020e46c4(void*);
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct*, int);
extern "C" Words021edf38 func_ov023_021ed804(Words021edf38, void*);
void SetWords_021edf38_021edf38(void*, Words021edf38*);
const char* CallFunc020e0434With02153694(int);
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
void ResetAndDispatchActorContext0209c6d8(void*, short);
extern "C" int func_0202c508(void*);
TagValueEntry020e385c* GetData02153660();
void ResetTaggedEntryAndNotifyOverlay020e3994(TagValueEntry020e385c*, int, int);
void RegisterTaggedEntryAndNotifyOverlay020e392c(TagValueEntry020e385c*, int, int);
void SetEntryBitUnlessMatching020e39d4(TagValueEntry020e385c*, int, int, int);

static inline SafeAllocator* GetAllocator(GameResources* resources, int index) {
    return &resources->allocator_array_38[index];
}

// USA: func_ov023_021edc08
extern "C" ARM int func_ov023_021edc08(CombatScreen* self) {
    GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    void* mode = func_0202ae18();
    TextRenderer* renderer = GetGlobalField0x1c020421a0();
    OrBitsIntoField0(GetDataPtr02114e04_020d6c00(), 0x20000);
    EnqueueEventTag86_021c9ad4(self->battle_->event_);
    func_ov017_021a23b0(resources, self->battle_->event_);
    DispatchContextByState0209c678(&data_02109bf4, 0);
    func_ov000_0216d370(self->camera_, 0, 0, 1);
    void* sound = func_02057924();
    SoundIds sounds = data_ov023_021fd870;
    for (int* id = sounds.ids_; *id >= 0; ++id) func_02057f00(sound, *id);
    if (self->manager_) {
        DestroyAllocatorAt0xa28(self->manager_);
        ConstructEntryManager020d6d18((Container020d6d18*)self->manager_);
        self->manager_ = 0;
    }
    ResetArrayAndEntry021823a4(self->entries_);
    ProcessAllSubObjects0203a54c(GetData02104b6c());
    SafeAllocator* const allocator = GetAllocator(resources, 5);
    allocator->Reset();
    CombatWork* work = (CombatWork*)allocator->Allocate(sizeof(CombatWork));
    _ZZ17GetGlobal021ffefcvE1s.work_ = work;
    work->state_ = 0;
    work->tasks_[0] = -1;
    work->tasks_[1] = -1;
    work->tasks_[2] = -1;
    work->field10_ = 0;
    work->field18_ = -1;
    work->field70_ = 0;
    work->fieldE2_ = 0;
    work->rewardIndex_ = -1;
    work->field11_ = 0;
    for (int i = 0; i < 4; ++i) work->flags_[i] = 0;
    work->fieldE5_ = -1;
    memset(work->buffer_, 0, sizeof(work->buffer_));
    memset(&work->field6C_, 0, 4);
    memset(work->data_, 0, sizeof(work->data_));
    work->field2788_ = 0;
    ClearFirstTwoWords0209a338(&work->pair_);
    ClearField00209a804(&work->fieldF0_);
    ResetAndInit_021f52a0(work->dispatch_);
    Clear12Bytes0206efc4(&work->words_);
    PushInputLogB(1);
    InitAndDispatch_021f52f8(_ZZ17GetGlobal021ffefcvE1s.work_->dispatch_, allocator);
    if (func_0202c540(mode) && self->battle_->special_) {
        func_02046380(renderer);
        GrottoRewardView* rewards = (GrottoRewardView*)&func_02012fe4()->grotto_.GetDetailedData()->regular_;
        Words021edf38 words;
        Clear12Bytes020e46c4(&words);
        BattleInfo* battle = self->battle_;
        for (int i = 0; i < 3; ++i) {
            void* found = SearchWithComparator0206f4f0(&battle->rewards_, rewards->ids_[i]);
            if (found) {
                const Words021edf38& copy = func_ov023_021ed804(words, found);
                SetWords_021edf38_021edf38(&words, const_cast<Words021edf38*>(&copy));
                renderer->argument_ = &words;
                break;
            }
        }
        char message[256];
        sprintf(message, CallFunc020e0434With02153694(200));
        func_0204500c(renderer, message, 1, 0xe3);
        renderer->active_ = 1;
        ResetAndDispatchActorContext0209c6d8(&data_02109bf4, 0x36);
    }
    if (func_0202c508(mode) && self->battle_->type_ == 19) {
        TagValueEntry020e385c* tags = GetData02153660();
        ResetTaggedEntryAndNotifyOverlay020e3994(tags, 1, -1);
        RegisterTaggedEntryAndNotifyOverlay020e392c(tags, 1, 0x71e8);
        SetEntryBitUnlessMatching020e39d4(tags, 0, 1, 0x71e8);
    }
    return 1;
}
