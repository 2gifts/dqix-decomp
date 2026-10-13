#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct CombatStatus {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
    unsigned char condition;
};
struct PartyStatsEvent {
    unsigned char tag;
    unsigned char padding[3];
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
#if defined(jpn)
enum { DisplayFlagsOffset = 0x180 };
#else
enum { DisplayFlagsOffset = 0x18c };
#endif

void* GetFieldAt0x150(unsigned char*);
extern "C" void func_02083e28(void*, int);
extern "C" unsigned short _Z20GetField6b4_021b8480Pv(void*);
void SetFlags0x180At0x18c(void*);
void ClearFlag0x80SetFlag0x100(void*);
extern "C" void func_ov017_0218b5f8(int);
void SetBoolFlagAt558(unsigned char*, int, int);
extern "C" void _Z25SetArrayEntryFlag02026f20ii(int, int);
int GetSignedByte0x2d0(void*);
int GetField0x397cValue(GameState*);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void _Z26CallHelperWithBuf_021907dciiiii(int, int, int, int, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);

// JPN: func_ov017_021ca3c8
// USA: func_ov017_021c9f18
extern "C" ARM void func_ov017_021c9f18(void* unused, const PartyStatsEvent* event, GameState* game, GameResources* controller, SearchStruct0202c1a4* search) {
    int memberIndex;
    GameObject* member;
    int changed;
    int allowVisibility;
    int index = event->index;
    int valid = index >= 0 && index <= 3;
    if (valid == 0) return;
    member = game->GetPartyMemberByIndex(index);
    if (member == NULL) return;
    void* effect = GetFieldAt0x150((unsigned char*)member);
    if (effect == NULL) return;
    changed = 0;
    int wasDead = (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->flags & 1;
    if ((wasDead != 0 && (event->flags & 1) == 0) || (wasDead == 0 && (event->flags & 1) != 0)) changed = 1;
    unsigned short oldHP = (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->hp;
    unsigned short oldMP = (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->mp;
    (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->hp = event->hp;
    (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->mp = event->mp;
    member->baseStats_->primaryStats.maxHP = event->maxHP;
    member->baseStats_->primaryStats.maxMP = event->maxMP;
    (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->flags = event->flags & 0xffff;
    (*reinterpret_cast<CombatStatus**>(reinterpret_cast<char*>(member) + 0x130))->condition = event->condition;
    if (event->resetEffect != 0) func_02083e28(effect, 0);
    BattlePolicy* policy = static_cast<BattlePolicy*>(controller->unknown_ptr_3718);
    allowVisibility = 1;
    if (policy->enabled != 0 && _Z20GetField6b4_021b8480Pv(policy) == 0) allowVisibility = 0;
    if (event->updateVisibility != 0) {
        if (allowVisibility != 0) {
            if (event->hp == 0) (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(member) + DisplayFlagsOffset)) |= 1;
            else (*reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(member) + DisplayFlagsOffset)) &= ~1;
        } else {
            if (event->hp == 0) SetFlags0x180At0x18c(member);
            else ClearFlag0x80SetFlag0x100(member);
        }
    }
    if (event->special != 0) func_ov017_0218b5f8(-1);
    unsigned char* flagTable = static_cast<unsigned char*>(controller->unknown_ptr_36d0);
    if (flagTable != NULL) {
        SetBoolFlagAt558(flagTable, (unsigned char)index, event->special);
        if (event->special != 0 && (oldHP != event->hp || oldMP != event->mp)) _Z25SetArrayEntryFlag02026f20ii((int)flagTable, index & 0xff);
    }
    if (changed == 0) return;
    memberIndex = index;
    if ((member->obj3D_.unknown_0_ & 0x1000) != 0) memberIndex = GetSignedByte0x2d0(member);
    GetField0x397cValue(game);
    if (memberIndex != GetSearchStructCurrentArrEntry(search)) _Z26CallHelperWithBuf_021907dciiiii((int)controller, memberIndex, 1, 1, 1);
    else func_ov017_02191108(controller, 1, 1, 1, 1);
}
