#include <globaldefs.h>
#include "GameState/GameState.h"

struct Base02010834;
struct Container020e34bc;
struct Entry020e3054;
struct Combatant02048228;
struct Combatant02048284;
extern "C" void* func_0205ec34();
extern "C" void* func_0202ae18();
extern "C" void* func_02012fe4();
extern "C" void* __clear(void*, int);
extern "C" void func_0206f81c(void*);
extern "C" void func_ov017_021c9e00(int, int, int, int);
unsigned int GetBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_(Base02010834*, int, int*, int*);
int IsField0Null(void**);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void*, int, void*);
void* GetData02153637();
extern "C" int _Z28GetEntryStatusForKey020e34bcP17Container020e34bci(Container020e34bc*, int);
int CheckField0NonZero(int*);
unsigned char GetByte0x26c(char*);
extern "C" int _Z36CountFlaggedSlotBit14Matches020852a4Ph(unsigned char*);
extern "C" int _Z36CountFlaggedSlotBit15Matches02085318Ph(unsigned char*);
void StoreInFirstEmptySlot(unsigned char*, unsigned char);
void SetBoolFlagAt558(unsigned char*, int, int);
int RestoreMaxHpByAmount(Combatant02048228*, int);
int RestoreMaxMpByAmount(Combatant02048284*, int);
extern "C" void _Z16Dispatch020e3428Pvi(void*, int);
extern "C" void _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i(Entry020e3054*, int);

// Only the fields used here are modeled. In particular, the restoration
// callees use the independent current-state pointer at 0x130, not the
// canonical GameObject::currentStats_ member at 0x138.
struct Actor0208b0f8 {
    char pad0[4];
    short slot;
    char pad6[0xb2 - 6];
    short active;
    char padb4[0x130 - 0xb4];
    unsigned int* restorationState;
    char pad134[0x150 - 0x134];
    unsigned char* skills;
};
struct State0208b0f8 {
    char pad0[0x94];
    unsigned char hpTimers[4];
    unsigned char mpTimers[4];
    unsigned char enabled;
    char pad9d[0xa8 - 0x9d];
    unsigned char countdown;
};
struct Record0208b0f8 {
    char pad0[0xc];
    unsigned int zone;
    char pad10[0x30 - 0x10];
    void* nodes;
};

// USA: func_0208b0f8
extern "C" ARM void func_0208b0f8(void* receiver) {
    State0208b0f8* self = (State0208b0f8*)receiver;
    GameState* game;
    void* data;
    GameResources* resources;
    int* search;
    unsigned char* flags;
    unsigned int blocked;
    int changed;
    void** list;
    void* entries;
    unsigned char* mpTimer;
    unsigned char* hpTimer;
    Actor0208b0f8* leader;
    int i;
    int status;
    Actor0208b0f8* party;
    int hp;
    int mp;
    game = GameState::GetInstance();
    resources = func_ov017_0218b5b0();
    leader = (Actor0208b0f8*)game->GetUnknownGameObject();
    data = func_0205ec34();
    GetPtrField0x2a04(game);
    search = (int*)func_0202ae18();
    flags = (unsigned char*)resources->unknown_ptr_36d0;
    list = (void**)resources->unknown_ptr_array_36fc[0];
    if (leader == NULL) return;
    blocked = GetBitsInField4((unsigned int*)resources, 0x10);
    int ids[4];
    int count;
    __clear(ids, sizeof(ids));
    _Z34CopyCountedBytesToIntArray02010834P12Base02010834iPiS1_((Base02010834*)game, leader->slot, ids, &count);
    if (IsField0Null(list) && leader->active != 0 && self->countdown != 0) {
        self->countdown--;
        if (self->countdown == 0) {
            Record0208b0f8 record;
            record.zone = *(unsigned short*)func_02012fe4();
            if (_Z28LookupAndForEachNode020649b0PviS_(data, 0x19, &record)) {
                func_0206f81c(&record);
            }
        }
    }
    entries = GetData02153637();
    changed = 0;
    hpTimer = self->hpTimers;
    mpTimer = self->mpTimers;
    for (i = 0; i < count; i++) {
        status = _Z28GetEntryStatusForKey020e34bcP17Container020e34bci((Container020e34bc*)entries, 1);
        party = (Actor0208b0f8*)game->GetPartyMemberByIndex(ids[i]);
        if (!CheckField0NonZero(search) || (CheckField0NonZero(search) && status != 1)) {
            if (party == NULL || leader->active == 0 || GetByte0x26c((char*)leader) != 0 ||
                (party->restorationState[0] & 1) || !IsField0Null(list)) {
                changed = 1;
                continue;
            }
        }
        hp = _Z36CountFlaggedSlotBit14Matches020852a4Ph(party->skills);
        if (hp > 0 && self->enabled && !blocked) {
            if (hpTimer[i] == 0) {
                if (status != 2 && status != 1) StoreInFirstEmptySlot((unsigned char*)entries, 1);
                if (status == 1) {
                    SetBoolFlagAt558(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) RestoreMaxHpByAmount((Combatant02048228*)party, hp);
                    hpTimer[i] = 0x28;
                    if (CheckField0NonZero(search)) func_ov017_021c9e00(ids[i], 1, 0, 0);
                    changed = 1;
                }
            } else hpTimer[i]--;
        }
        mp = _Z36CountFlaggedSlotBit15Matches02085318Ph(party->skills);
        if (mp > 0 && self->enabled && !blocked) {
            if (mpTimer[i] == 0) {
                if (status != 2 && status != 1) StoreInFirstEmptySlot((unsigned char*)entries, 1);
                if (status == 1) {
                    SetBoolFlagAt558(flags, (unsigned char)ids[i], 0);
                    if (!(party->restorationState[0] & 1)) RestoreMaxMpByAmount((Combatant02048284*)party, mp);
                    mpTimer[i] = 0x28;
                    if (CheckField0NonZero(search)) func_ov017_021c9e00(ids[i], 1, 1, 0);
                    changed = 1;
                }
            } else mpTimer[i]--;
        }
    }
    if (changed) {
        int status = _Z28GetEntryStatusForKey020e34bcP17Container020e34bci((Container020e34bc*)entries, 1);
        if (status == 1) _Z16Dispatch020e3428Pvi(entries, 1);
        else if ((unsigned int)(status - 3) <= 2) _Z37ClearEntryIfCurrentArrMatches020e3468P13Entry020e3054i((Entry020e3054*)entries, 1);
    }
}
