#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083e28(void* a, int arg2);

struct BitTriple10 {
    unsigned int f0 : 10;
    unsigned int f1 : 10;
    unsigned int f2 : 10;
    unsigned int : 2;
};

struct Last_ce8ac {
    unsigned int f0 : 10;
    unsigned int id : 3;
    unsigned int rest : 19;
};

struct Src021ce8ac {
    char pad[4];
    BitTriple10 w0;
    BitTriple10 w1;
    BitTriple10 w2;
    Last_ce8ac w3;
};

// USA: func_ov017_021ce8ac
extern "C" ARM void func_ov017_021ce8ac(int unused0, Src021ce8ac* src, GameState* battleStruct) {
    GameObject* c = GetCombatantWithFlag0x100(battleStruct, src->w3.id);
    if (!c) return;
    unsigned char* p = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
    if (!p) return;
    BitTriple10* stats = (BitTriple10*)(p + 0x91c);
    stats[0].f0 = src->w0.f0;
    stats[0].f1 = src->w0.f1;
    stats[0].f2 = src->w0.f2;
    stats[1].f0 = src->w1.f0;
    stats[1].f1 = src->w1.f1;
    stats[1].f2 = src->w1.f2;
    stats[2].f0 = src->w2.f0;
    stats[2].f1 = src->w2.f1;
    stats[2].f2 = src->w2.f2;
    stats[3].f0 = src->w3.f0;
    func_02083e28(p, 0);
}
