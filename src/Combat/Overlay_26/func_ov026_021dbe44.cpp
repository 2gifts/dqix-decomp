#include <globaldefs.h>
#include "Resource/GameResources.h"

struct BattleState;

struct PartyState {
    char pad0[0x2a];
    unsigned char myIndex;
};

struct BattleWork {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    BattleState* battle;
    PartyState* party;
    char pad2a4[0x974];
    char view[0x220];
    char pade38[0x60];
    char scriptA[0x8];
    char scriptB[0x8];
    char padea8[0x20];
#if defined(jpn)
    char ctxEc8[0x28d8];
    char list[0x21fc];
#else
    char ctxEc8[0x2898];
    char list[0x1fc8];
#endif
    char ctx5728[0x1e8];
    char ctx5910[0x32c];
    char ctx5c3c[0x1200];
};

extern "C" int func_ov026_021d8a40();
int IsField0Null_02046b08(void**);
int TestBitAt0x34_020a35e0(unsigned char*, unsigned int);
extern "C" void func_ov026_021dce34(int, BattleWork*, BattleState*, PartyState*, void*, void*, void*, void*, void*, void*, void*, void*);

// USA: func_ov026_021dbe44
extern "C" ARM void func_ov026_021dbe44(BattleWork* self) {
    void** field3704 = (void**)func_ov017_0218b5b0()->unknown_ptr_array_36fc[2];
    if (func_ov026_021d8a40() && IsField0Null_02046b08(field3704) && TestBitAt0x34_020a35e0((unsigned char*)self->party, self->party->myIndex)) {
        func_ov026_021dce34(-1, self, self->battle, self->party, self->list, self->ctxEc8, self->ctx5c3c, self->ctx5728, self->scriptA, self->scriptB, self->ctx5910, self->view);
    }
}
