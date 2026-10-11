#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Ret021c6ca0 {
    unsigned char pad0[8];
    unsigned short field8;
    unsigned char pad1[0x20];
    signed char field2a;
};

struct Src021c6ca0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned short field8;
    unsigned short fielda;
    int fieldc;
    int field10;
};

// JPN: func_ov017_021c7150
// USA: func_ov017_021c6ca0  (semantic: CopyFieldsIfMatch_021c6ca0)
extern "C" ARM void func_ov017_021c6ca0(int unused0, Src021c6ca0* src, GameState* battleStruct, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
    unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
    Ret021c6ca0* r = (Ret021c6ca0*)func_ov017_021b8478(h);
    if (!r) return;
    if (!func_ov017_021b8468(h)) return;
    if (!GetField6b0_021b8470(h)) return;
    if (r->field2a == GetField0x3acValue(battleStruct)) return;
    if (r->field8 != src->field4) return;
    GameObject* c = battleStruct->GetCombatantByIndex(src->field6);
    if (!c) return;
    *(unsigned short*)((char*)c->currentStats_ + 0x0) = src->field8;
    *(unsigned short*)((char*)c->currentStats_ + 0x2) = src->fielda;
    *(int*)((char*)c->currentStats_ + 0x14) = src->fieldc;
    *(int*)((char*)c->currentStats_ + 0x18) = src->field10;
}
