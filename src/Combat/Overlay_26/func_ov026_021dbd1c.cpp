#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleState;
struct Combatant020A36A8;
struct Entry0207da94;
struct Entry0207d9bc;
struct Struct0216377c;

struct PartyState {
    char pad0[0x8];
    unsigned short netId;
    char pad0a[0x20];
    signed char myIndex;
};

struct Container_021dae60 {
    char pad0[0xb8];
};

struct BattleWork {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif

    BattleState* battle;
    PartyState* party;
    char pad2a4[0xc08];
    int state;
#if defined(jpn)
    char padeb0[0x28f0];
#else
    char padeb0[0x28b0];
#endif

    Container_021dae60 list;
#if defined(jpn)
    char pad3818[0x4164];
#else
    char pad3818[0x3f30];
#endif

    unsigned char turnFlag;
};

char GetField0x3acValue_020100a8(GameState* gs);
void* GetData02108ea8_0207d78c();
int MatchesActiveIndex020a36a8(Combatant020A36A8* c);
unsigned char AssignEntrySlot0207db58(Entry0207d9bc* arr, unsigned short key, char val);
void Foo0216377c(Struct0216377c* obj, unsigned char val);
void EnqueueEventTag130_021cc050(unsigned short tag);

extern "C" {
int _Z22TestBitAt0x34_020a35e0Phj(PartyState* party, unsigned char bit);
void _Z23ClearBitAt0x34_020a367cPhi(PartyState* party, unsigned char bit);
void _Z22ProcessEntries0207da94P13Entry0207da94i(void* entries, unsigned char member);
void _Z23ClearByteAtPtr_02191b40v(GameResources* res, int member);
int* func_0202ae18();
int func_0202c508(int*);
void func_ov000_02174a50(Container_021dae60*, int);
void func_ov017_021c9b90(unsigned short, int);
void func_ov000_0215fb04(BattleState*, int);
void func_ov026_021dbf04(BattleWork*);
}

// USA: func_ov026_021dbd1c
extern "C" ARM void func_ov026_021dbd1c(BattleWork* self, int member, int notify) {
    GameState* gs = GameState::GetInstance();
    PartyState* party = self->party;
    Container_021dae60* list = &self->list;
    BattleState* battle = self->battle;
    void* entries = GetData02108ea8_0207d78c();
    int* link = func_0202ae18();
    GameResources* res = func_ov017_0218b5b0();
    int wasMember = 0;

    if (_Z22TestBitAt0x34_020a35e0Phj(party, member)) {
        wasMember = 1;
        self->turnFlag = 1;
    }
    func_ov000_02174a50(list, member);
    _Z23ClearBitAt0x34_020a367cPhi(party, member);
    _Z22ProcessEntries0207da94P13Entry0207da94i(entries, member);
    _Z23ClearByteAtPtr_02191b40v(res, member);

    if (member == party->myIndex) {
        if (func_0202c508(link)) {
            Foo0216377c((Struct0216377c*)self, AssignEntrySlot0207db58((Entry0207d9bc*)entries, party->netId, GetField0x3acValue_020100a8(gs)));
        } else {
            func_ov017_021c9b90(party->netId, member);
        }
    }
    func_ov000_0215fb04(battle, member);

    if (notify && self->state != 0x11 && wasMember && MatchesActiveIndex020a36a8((Combatant020A36A8*)party)) {
        func_ov026_021dbf04(self);
        EnqueueEventTag130_021cc050(party->netId);
    }
}
