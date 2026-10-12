#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct CombatStatus {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
    unsigned char condition;
};
struct PartyUpdateView {
    unsigned short flags;
    unsigned char padding[0x12e];
    CombatStatus* status;
    BaseCombatStats* baseStats;
    unsigned char padding2[0x54];
    unsigned int displayFlags;
};
struct PartyStatsEvent {
    unsigned char padding[4];
    unsigned char index : 3;
    unsigned char updateVisibility : 1;
    unsigned char resetEffect : 1;
    unsigned char special : 1;
    unsigned char unused : 2;
    unsigned char condition;
    unsigned short hp;
    unsigned short maxHP;
    unsigned short mp;
    unsigned short maxMP;
    unsigned short padding2;
    unsigned int flags;
};
struct BattlePolicy {
    unsigned char padding[2];
    unsigned char enabled;
};
struct PartyControllerTail {
    unsigned char padding[0x6d0];
    unsigned char* flagTable;
    unsigned char padding2[0x44];
    BattlePolicy* policy;
};
struct PartyController {
    unsigned char padding[0x3000];
    PartyControllerTail tail;
};

void* GetFieldAt0x150(unsigned char*);
extern "C" void func_02083e28(void*, int);
extern "C" int _Z20GetField6b4_021b8480Pv(void*);
void SetFlags0x180At0x18c(void*);
void ClearFlag0x80SetFlag0x100(void*);
extern "C" void func_ov017_0218b5f8(int);
void SetBoolFlagAt558(unsigned char*, int, int);
extern "C" void _Z25SetArrayEntryFlag02026f20ii(int, int);
int GetSignedByte0x2d0(void*);
int GetField0x397cValue(GameState*);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(int, int, int, int, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);

// USA: func_ov017_021c9f18
extern "C" ARM void func_ov017_021c9f18(void* unused, const PartyStatsEvent* event, GameState* game, PartyController* controller, SearchStruct0202c1a4* search) {
    int memberIndex;
    PartyUpdateView* member;
    int changed;
    int allowVisibility;
    int index = event->index;
    int valid = index >= 0 && index <= 3;
    if (valid == 0) return;
    member = (PartyUpdateView*)game->GetPartyMemberByIndex(index);
    if (member == NULL) return;
    void* effect = GetFieldAt0x150((unsigned char*)member);
    if (effect == NULL) return;
    changed = 0;
    int wasDead = member->status->flags & 1;
    if ((wasDead != 0 && (event->flags & 1) == 0) || (wasDead == 0 && (event->flags & 1) != 0)) changed = 1;
    unsigned short oldHP = member->status->hp;
    unsigned short oldMP = member->status->mp;
    member->status->hp = event->hp;
    member->status->mp = event->mp;
    member->baseStats->primaryStats.maxHP = event->maxHP;
    member->baseStats->primaryStats.maxMP = event->maxMP;
    member->status->flags = event->flags & 0xffff;
    member->status->condition = event->condition;
    if (event->resetEffect != 0) func_02083e28(effect, 0);
    BattlePolicy* policy = controller->tail.policy;
    allowVisibility = 1;
    if (policy->enabled != 0 && _Z20GetField6b4_021b8480Pv(policy) == 0) allowVisibility = 0;
    if (event->updateVisibility != 0) {
        if (allowVisibility != 0) {
            if (event->hp == 0) member->displayFlags |= 1;
            else member->displayFlags &= ~1;
        } else {
            if (event->hp == 0) SetFlags0x180At0x18c(member);
            else ClearFlag0x80SetFlag0x100(member);
        }
    }
    if (event->special != 0) func_ov017_0218b5f8(-1);
    unsigned char* flagTable = controller->tail.flagTable;
    if (flagTable != NULL) {
        SetBoolFlagAt558(flagTable, (unsigned char)index, event->special);
        if (event->special != 0 && (oldHP != event->hp || oldMP != event->mp)) _Z25SetArrayEntryFlag02026f20ii((int)flagTable, index & 0xff);
    }
    if (changed == 0) return;
    memberIndex = index;
    if ((member->flags & 0x1000) != 0) memberIndex = GetSignedByte0x2d0(member);
    GetField0x397cValue(game);
    if (memberIndex != GetSearchStructCurrentArrEntry(search)) _Z26CallHelperWithBuf_021907dciiiii((int)controller, memberIndex, 1, 1, 1);
    else func_ov017_02191108(controller, 1, 1, 1, 1);
}
