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

char GetField0x3acValue(GameState* gs);
void* GetData02108ea8();
extern "C" int _Z26MatchesActiveIndex020a36a8P17Combatant020A36A8(Combatant020A36A8* c);
extern "C" unsigned char _Z23AssignEntrySlot0207db58P13Entry0207d9bctc(Entry0207d9bc* arr, unsigned short key, char val);
extern "C" void _Z11Foo0216377cP14Struct0216377ch(Struct0216377c* obj, unsigned char val);
extern "C" void _Z27EnqueueEventTag130_021cc050t(unsigned short tag);

extern "C" {
int _Z13TestBitAt0x34Phj(PartyState* party, unsigned char bit);
void _Z14ClearBitAt0x34Phi(PartyState* party, unsigned char bit);
void _Z22ProcessEntries0207da94P13Entry0207da94i(void* entries, unsigned char member);
void _Z23ClearByteAtPtr_02191b40v(GameResources* res, int member);
int* func_0202ae18();
int func_0202c508(int*);
void func_ov000_02174a50(Container_021dae60*, int);
void func_ov017_021c9b90(unsigned short, int);
void func_ov000_0215fb04(BattleState*, int);
void func_ov026_021dbf04(BattleWork*);
}

// JPN: func_ov026_021dc3ec
// USA: func_ov026_021dbd1c
extern "C" ARM void func_ov026_021dbd1c(BattleWork* self, int member, int notify) {
    GameState* gs = GameState::GetInstance();
    PartyState* party = self->party;
    Container_021dae60* list = &self->list;
    BattleState* battle = self->battle;
    void* entries = GetData02108ea8();
    int* link = func_0202ae18();
    GameResources* res = func_ov017_0218b5b0();
    int wasMember = 0;

    if (_Z13TestBitAt0x34Phj(party, member)) {
        wasMember = 1;
        self->turnFlag = 1;
    }
    func_ov000_02174a50(list, member);
    _Z14ClearBitAt0x34Phi(party, member);
    _Z22ProcessEntries0207da94P13Entry0207da94i(entries, member);
    _Z23ClearByteAtPtr_02191b40v(res, member);

    if (member == party->myIndex) {
        if (func_0202c508(link)) {
            _Z11Foo0216377cP14Struct0216377ch((Struct0216377c*)self, _Z23AssignEntrySlot0207db58P13Entry0207d9bctc((Entry0207d9bc*)entries, party->netId, GetField0x3acValue(gs)));
        } else {
            func_ov017_021c9b90(party->netId, member);
        }
    }
    func_ov000_0215fb04(battle, member);

    if (notify && self->state != 0x11 && wasMember && _Z26MatchesActiveIndex020a36a8P17Combatant020A36A8((Combatant020A36A8*)party)) {
        func_ov026_021dbf04(self);
        _Z27EnqueueEventTag130_021cc050t(party->netId);
    }
}
