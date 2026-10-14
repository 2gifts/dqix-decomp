#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleWork;
struct Combatant020A36A8;
struct Container_021dae60;
struct Field0x19cData;
struct Flags02033fdc;
struct Obj02039d84;
struct Bytes02033b88;
struct S_10088;
struct FlagObj_021dd3c4;

struct BattleState {
    char pad0[0x8e20];
    int turns;
};

struct PartyState {
    char pad0[0x2];
    unsigned short field2;
    char pad4[0x4];
    unsigned short netId;
    char pada[0x2];
    int field0c;
    char pad10[0x1a];
    signed char myIndex;
    char pad2b[0xa];
    unsigned char mode;
};

struct SlotWork {
    char pad0[0x10];
    unsigned char cmds[8];
    signed char cursor;
    char pad19[0xb];
    unsigned char done : 1;
    unsigned char rest : 7;
    char pad25[0x3];
    int owner;
};

struct EventCtx {
    unsigned short field06;
    char pad2[0x6];
    int handle;
};

struct ModelState { char data[0x70]; };
struct StatBlock { char data[0xc]; };

struct PartyEntry {
    Vector3i pos;
    short angle;
    short pad;
};

struct Src021cbc48 {
    unsigned short netId;
    unsigned short field2;
    int mode;
    unsigned char party;
    signed char myIndex;
    unsigned char alive;
    unsigned char visible;
    unsigned char kind;
    short field0c;
};

struct ModeBits {
    unsigned char mode : 2;
    unsigned char rest : 6;
};

struct ActorView {
    char pad0[0xbe];
    unsigned char state;
    char padbf[0x2];
    ModeBits fc1;
    unsigned char fc2_0 : 5;
    unsigned char hidden : 1;
    unsigned char fc2_6 : 2;
    char padc3[0x6d];
    unsigned int* flags;
    char pad134[0x58];
    unsigned int flags18c;
};

int MatchesActiveIndex020a36a8(Combatant020A36A8*);
int GetCombatWorkFlags0x55f4_ov000_02160fd4(void*, int);
void ClearCombatWorkFlags0x55f4_ov000_02160fbc(void*, int);
void SetBitInField0x34_020a35cc(unsigned char*, int);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned int);
SlotWork* FindSlotById_021dae60(Container_021dae60*, int);
void SetAndClearField0x19c_02053da0(char*, Field0x19cData*);
void CopyCombatantStats0208936c(char*, char*, char*);
void ResetObjectState02039d84(Obj02039d84*);
void ClearFlag0x4At0xe0(Flags02033fdc*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearField0xc4KeepBit0x8000_0203409c(unsigned char*);
void ClearFlag0x1ceBit0x4_02039d58(unsigned char*);
void AddEntry02168644(char*, int);
void SetFlag0x1ceBit0x1_02039894(unsigned char*);
void RunFlaglearAndSetMode02167e6c_02167e6c(unsigned char*);
int IsFlag10088Set_02010088(S_10088*);
int IsFlagBit8192Set_021dd3c4(FlagObj_021dd3c4*);
void EnqueueEventTag100_021cbc48(Src021cbc48*);
void DispatchAllEventStages_021cdf80(char*, unsigned char);
int ClassifyField0x81fe_ov000_0215fc60(char*);
void Process02181364(void*);
void ClearFlag_021816e8_021816e8(void*, int);
void SetFlag_02181694_02181694(void*, int);
void ClearByteField_0217f5d0_0217f5d0(void*);

extern "C" {
int* func_0202ae18();
int func_ov000_0215fad4(BattleState*);
int func_ov000_0215e9fc(BattleState*, short*, int, int);
void func_ov000_02174738(void*, int);
void* memset(void*, int, unsigned int);
void func_02049c88(void*, void*);
void func_ov026_021dc8fc(BattleWork*, BattleState*, PartyState*, void*, void*, void*, int);
void func_020531f0(void*);
void func_ov000_02167fb0(void*, GameObject*);
int func_0202c540(int*);
int func_ov017_0219c774(int, int, int);
void func_ov017_021917f0(int, int);
void func_ov000_021675a0(BattleWork*);
void func_ov026_021daec8(BattleState*, void*, int);
void func_ov000_021676a8(BattleWork*);
void func_ov000_02174b14(void*);
void func_ov000_0217a8f4(void*);
void func_ov017_021c847c();
void func_ov000_0217fcc4(void*, int);
}

// USA: func_ov026_021dce34
extern "C" ARM void func_ov026_021dce34(int mode, BattleWork* self, BattleState* battle, PartyState* party,
                                        void* list, EventCtx* events, ModelState* models, StatBlock* stats,
                                        void* scriptA, void* scriptB, PartyEntry* entries, void* view) {
    Src021cbc48 ev;
    short ids[4];
    short members[4];
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    int* link = func_0202ae18();
    if (!MatchesActiveIndex020a36a8((Combatant020A36A8*)party) && !GetCombatWorkFlags0x55f4_ov000_02160fd4(self, 0x80000000)) {
        return;
    }
    ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x80000000);
    int added = 0;
    int id = func_ov000_0215fad4(battle);
    func_ov000_0215e9fc(battle, ids, 4, 0);
    while (id >= 0) {
        SetBitInField0x34_020a35cc((unsigned char*)party, (unsigned char)id);
        func_ov000_02174738(list, id);
        SlotWork* slot = FindSlotById_021dae60((Container_021dae60*)list, id);
        if (slot) {
            GameObject* m = gs->GetPartyMemberByIndex(id);
            if (m) {
                slot->owner = *((ActorView*)m)->flags;
            }
        }
        if (mode >= 0) {
            SlotWork* s = FindSlotById_021dae60((Container_021dae60*)list, id);
            if (s) {
                s->cmds[s->cursor] = 100;
                s->done = 0;
            }
        }
        unsigned short field06 = events->field06;
        GameObject* m = gs->GetPartyMemberByIndex(id);
        if (m) {
            m->obj3D_.MakeHidden();
            m->obj3D_.SetField06(field06);
            memset(&models[id], 0, sizeof(ModelState));
            func_02049c88(m, &models[id]);
            SetAndClearField0x19c_02053da0((char*)m, (Field0x19cData*)&stats[id]);
            CopyCombatantStats0208936c((char*)m->currentStats_, (char*)((ActorView*)m)->flags, (char*)m->baseStats_);
            func_ov026_021dc8fc(self, battle, party, list, scriptA, scriptB, id);
            func_020531f0(m);
            ResetObjectState02039d84((Obj02039d84*)m);
            ((ActorView*)m)->fc1.mode |= 3;
            ((ActorView*)m)->hidden = 1;
            ClearFlag0x4At0xe0((Flags02033fdc*)m);
            SetByte0xbeShiftPrev((Bytes02033b88*)m, 0);
            ClearField0xc4KeepBit0x8000_0203409c((unsigned char*)m);
            m->obj3D_.SetInheritedAlpha(0x1f);
            ClearFlag0x1ceBit0x4_02039d58((unsigned char*)m);
            if (!(*((ActorView*)m)->flags & 1)) {
                if (((ActorView*)m)->flags18c & 1) {
                    ((ActorView*)m)->flags18c &= ~1;
                }
            }
            if (*((ActorView*)m)->flags & 1) {
                if (!(((ActorView*)m)->flags18c & 1)) {
                    ((ActorView*)m)->flags18c |= 1;
                }
            }
            entries[id].pos = m->obj3D_.position_;
            entries[id].angle = m->obj3D_.rotation_.y;
            added = 1;
            AddEntry02168644((char*)self, id);
            SetFlag0x1ceBit0x1_02039894((unsigned char*)m);
            func_ov000_02167fb0(self, m);
            if (m->obj3D_.unknown_4_ == 0 && func_0202c540(link)) {
                func_ov017_0219c774(events->handle, 0, 0);
            }
        }
        func_ov017_021917f0(id, 1);
        id = func_ov000_0215fad4(battle);
    }
    if (added) {
        ClearCombatWorkFlags0x55f4_ov000_02160fbc(self, 0x80000000);
        func_ov000_021675a0(self);
        RunFlaglearAndSetMode02167e6c_02167e6c((unsigned char*)self);
        func_ov026_021daec8(battle, view, 0);
        if (battle->turns == 0) {
            func_ov000_021676a8(self);
        }
        func_ov000_02174b14(list);
        func_ov000_0217a8f4(list);
        if (MatchesActiveIndex020a36a8((Combatant020A36A8*)party)) {
            unsigned char alive = 0;
            unsigned char visible = 0;
            int count = func_ov000_0215e9fc(battle, members, 4, 0);
            int i;
            for (i = 0; i < count; i++) {
                GameObject* c = gs->GetCombatantByIndex(members[i]);
                if (c && ((ActorView*)c)->state != 4 && ((ActorView*)c)->state != 6) {
                    alive |= 1 << i;
                }
            }
            for (i = 0; i < 8; i++) {
                GameObject* c = gs->GetCombatantByIndex(i + 0xc0);
                if (c && c->obj3D_.IsVisible() && !IsFlag10088Set_02010088((S_10088*)c) &&
                    !IsFlagBit8192Set_021dd3c4((FlagObj_021dd3c4*)c)) {
                    visible |= 1 << i;
                }
            }
            ev.netId = party->netId;
            ev.visible = visible;
            ev.alive = alive;
            ev.mode = mode;
            ev.kind = party->mode;
            ev.field0c = party->field0c;
            for (int j = 0; j < 4; j++) {
                if (TestBitAt0x34_020a35e0((unsigned char*)party, (unsigned char)j)) {
                    ev.party |= 1 << j;
                } else {
                    ev.party &= ~(1 << j);
                }
            }
            ev.myIndex = party->myIndex;
            ev.field2 = party->field2;
            EnqueueEventTag100_021cbc48(&ev);
            DispatchAllEventStages_021cdf80((char*)battle, 1);
            func_ov017_021c847c();
            if (party->mode == 2) {
                func_ov000_0217fcc4(list, -1);
            }
        }
    }
    if (ClassifyField0x81fe_ov000_0215fc60((char*)battle) != 0) {
        if (func_0202c540(func_0202ae18()) != 0) {
            Process02181364(list);
            func_ov000_0217fcc4(list, -1);
            ClearFlag_021816e8_021816e8(list, -1);
            SetFlag_02181694_02181694(list, 0);
        } else {
            for (int i = 1; i < 4; i++) {
                SlotWork* s = FindSlotById_021dae60((Container_021dae60*)list, i);
                if (s != 0) {
                    ClearByteField_0217f5d0_0217f5d0(s);
                    s->cmds[s->cursor] = 100;
                }
            }
        }
    }
}
