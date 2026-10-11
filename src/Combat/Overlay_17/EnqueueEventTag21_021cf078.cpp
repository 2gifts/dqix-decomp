// JPN: func_ov017_021cf520
#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Field850 = 0x7b8 };
#else
enum { Field850 = 0x850 };
#endif

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Triple10_021cf078 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

struct SrcSlot021cf078 {
    Triple10_021cf078 items[3];
};

struct EvtWord3_021cf078 {
    unsigned int lo : 8;
    unsigned int mid : 3;
    unsigned int hi : 1;
    unsigned int rest : 20;
};

struct EventBuf021cf078 {
    unsigned char tag;
    unsigned char pad0[3];
    struct {
        Triple10_021cf078 items[3];
        EvtWord3_021cf078 w3;
    } data;
};

// USA: func_ov017_021cf078  (semantic: EnqueueEventTag21_021cf078)
extern "C" ARM void func_ov017_021cf078(int combatantId, unsigned short slot, unsigned char flag) {
    void* p = GetData02100044();
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, combatantId);
    if (!combatant) return;

    int val150 = GetFieldAt0x150((unsigned char*)combatant);
    if (!val150) return;

    SrcSlot021cf078* arr = (SrcSlot021cf078*)((char*)val150 + Field850);
    SrcSlot021cf078* src = &arr[slot];

    EventBuf021cf078 buf;
    buf.tag = 0x15;
    Triple10_021cf078* dst = buf.data.items;
    dst[0].a = src->items[0].a;
    dst[0].b = src->items[0].b;
    dst[0].c = src->items[0].c;
    dst[1].a = src->items[1].a;
    dst[1].b = src->items[1].b;
    dst[1].c = src->items[1].c;
    dst[2].a = src->items[2].a;
    dst[2].b = src->items[2].b;
    dst[2].c = src->items[2].c;
    EvtWord3_021cf078* w3 = (EvtWord3_021cf078*)(dst + 3);
    w3->lo = slot;
    w3->mid = combatantId;
    w3->hi = flag;

    func_0205e330(p, &buf, 0);
}
