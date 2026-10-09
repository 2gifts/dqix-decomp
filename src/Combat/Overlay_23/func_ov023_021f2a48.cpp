#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct Words021edf38 { unsigned int a_, b_, c_; };
struct BinarySearchByComparatorStruct { int fields_[4]; };
struct TableA68 { int fields_[4]; };
struct Flags_021ed7e0 {
    unsigned int unused0_ : 11; unsigned int first_ : 7; unsigned int second_ : 7;
    unsigned int unused19_ : 7;
};
struct Obj0205eaa0;
struct RewardEntry {
    unsigned short text_; unsigned short key_ : 15; unsigned short plural_ : 1;
    unsigned char counter_; signed char combatant_;
};
struct BattleData {
    char pad0[0x678]; BinarySearchByComparatorStruct rewards_;
};
struct RewardScreen {
    char pad0[0x2a0]; BattleData* battle_; char pad2A4[0xeac - 0x2a4]; int state_;
    char padEB0[0x58d0 - 0xeb0]; RewardEntry entries_[8]; unsigned char count_;
    char pad5901[3]; TableA68 texts_;
};
struct RewardState { int state_; char pad4[0xe4 - 4]; signed char index_; };
struct RewardGlobal { RewardState* state_; int field4_; int flags_; };
struct TextRenderer {
    void* actor_; char pad4[12]; void* recipient_; char pad14[4]; void* description_;
    char pad1C[4]; void* reward_; char pad24[0x998 - 0x24]; int active_;
    char pad99C[0x19b2 - 0x99c]; unsigned char field19B2_;
};
struct CombatStatus { unsigned int flags_; };
struct ActorView { char pad0[0x130]; CombatStatus* status_; };
struct FoundReward { char pad0[0x10]; unsigned short id_; };
struct TextBuffers { char* first_; char* second_; int field8_; };
extern "C" RewardGlobal _ZZ17GetGlobal021ffefcvE1s;
extern Obj0205eaa0 data_02108760;
extern "C" TextRenderer* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(TextRenderer*);
void CopyOutRegion0x571d(char*, void*);
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" FoundReward* _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(BinarySearchByComparatorStruct*, int);
extern "C" void _Z20Clear12Bytes020e46c4Pv(void*);
extern "C" Words021edf38 func_ov023_021ed804(Words021edf38, FoundReward*);
extern "C" void _Z26SetWords_021edf38_021edf38PvP13Words021edf38(void*, Words021edf38*);
extern "C" void _Z31DispatchIfCountPositive020dcf7ciPv(int, void*);
const char* FindEntryByKey(TableA68*, int);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void*, int);
extern "C" void _Z28InitObjFromCombatant020e4c74PvP10GameObject(void*, GameObject*);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void func_0204500c(TextRenderer*, const char*, int, int);
extern "C" void _Z28ClearFlagBits10to24_021ed7e0P14Flags_021ed7e0(Flags_021ed7e0*);
int CopyIndexedRegion0x75f0(void*, short*, int*, int);
extern "C" void func_020abe84(void*, short*, Flags_021ed7e0*, int);
extern "C" int func_ov023_021f4fc8();

// USA: func_ov023_021f2a48
extern "C" ARM int func_ov023_021f2a48(RewardScreen* self) {
    GameState* state = GameState::GetInstance();
    RewardState* work = _ZZ17GetGlobal021ffefcvE1s.state_;
    TextRenderer* renderer = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(renderer);
    if (work->state_ == 0) {
        ++work->index_;
        if (self->count_ <= work->index_) return 14;
        RewardEntry* reward = &self->entries_[work->index_];
        unsigned short key = reward->key_;
        int text = reward->text_;
        int plural = reward->plural_;
        signed char combatant = reward->combatant_;
        unsigned char order[4];
        CopyOutRegion0x571d((char*)state, order);
        GameObject* recipient = 0;
        for (int i = 0; i < 4; ++i) {
            GameObject* actor = state->GetCombatantByIndex(order[i]);
            if (!actor) continue;
            if (!TestBitAt0x34((unsigned char*)self->battle_, order[i])) continue;
            if (((ActorView*)actor)->status_->flags_ & 1) continue;
            recipient = state->GetPartyMemberByIndex(order[i]);
            break;
        }
        if (!recipient) return self->state_;
        FoundReward* found = _Z28SearchWithComparator0206f4f0P30BinarySearchByComparatorStructi(&self->battle_->rewards_, (short)key);
        if (!found) return self->state_;
        Words021edf38 words;
        TextBuffers description;
        Words021edf38 actorText;
        _Z20Clear12Bytes020e46c4Pv(&words);
        const Words021edf38& copy = func_ov023_021ed804(words, found);
        _Z26SetWords_021edf38_021edf38PvP13Words021edf38(&words, const_cast<Words021edf38*>(&copy));
        renderer->reward_ = &words;
        char first[128] = {0};
        char second[128] = {0};
        _Z20Clear12Bytes020e46c4Pv(&description);
        description.first_ = first;
        description.second_ = second;
        _Z31DispatchIfCountPositive020dcf7ciPv((short)text, &description);
        renderer->description_ = &description;
        char message[512] = {0};
        if (combatant >= 0) {
            GetCombatantWithFlag0x100(state, combatant);
            sprintf(message, FindEntryByKey(&self->texts_, 0x25));
            _Z30InitObjFromCombatantId020e4bf4Pvi(&actorText, combatant);
            renderer->actor_ = &actorText;
        } else {
            char suffix[0x164] = {0};
            sprintf(message, FindEntryByKey(&self->texts_, 0x11));
            _Z28InitObjFromCombatant020e4c74PvP10GameObject(&actorText, recipient);
            renderer->recipient_ = &actorText;
            if (!plural) sprintf(suffix, FindEntryByKey(&self->texts_, 0x12));
            else sprintf(suffix, FindEntryByKey(&self->texts_, 0x13));
            strcat(message, suffix);
            if (work->index_ < self->count_ - 1) strcat(message, FindEntryByKey(&self->texts_, 0x22));
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x15, 0);
        func_0204500c(renderer, message, 1, 0xe3);
        renderer->field19B2_ = 0;
        renderer->active_ = 1;
        if (self->entries_[work->index_].counter_) {
            Flags_021ed7e0 flags;
            _Z28ClearFlagBits10to24_021ed7e0P14Flags_021ed7e0(&flags);
            short id = found->id_;
            if (CopyIndexedRegion0x75f0(0, &id, (int*)&flags, 1)) {
                switch (self->entries_[work->index_].counter_) {
                case 1: { unsigned int count = flags.first_ + 1; if (count > 99) count = 99; flags.first_ = count; break; }
                case 2: { unsigned int count = flags.second_ + 1; if (count > 99) count = 99; flags.second_ = count; break; }
                }
                func_020abe84(0, &id, &flags, 1);
            }
        }
        ++work->state_;
    } else if (work->state_ == 1) {
        if (func_ov023_021f4fc8()) work->state_ = 0;
    }
    return self->state_;
}
