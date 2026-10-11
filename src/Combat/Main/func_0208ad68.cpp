#include <globaldefs.h>

#if defined(jpn)
enum { kOffset6d0 = 0x4c0 };
#else
enum { kOffset6d0 = 0x6d0 };
#endif

#include "GameState/GameState.h"


struct Sub130_020482e0 {
    unsigned int flags;
    unsigned short count;
};
struct Combatant020482e0 {
    char pad[0x130];
    struct Sub130_020482e0* sub;
};
int ConsumeCounter020482e0(struct Combatant020482e0* c, int amount, int force);

void SetBoolFlagAt558(unsigned char* base, int index, int value);
void SetArrayEntryFlag02026f20(int a, int index);

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);

// USA: func_0208ad68
extern "C" ARM void func_0208ad68(void* obj, int id) {
    GameState* bs = GameState::GetInstance();
    char* base = (char*)func_ov017_0218b5b0() + 0x3000;
    int* target = *(int**)(base + kOffset6d0);
    struct Combatant020482e0* c = (struct Combatant020482e0*)bs->GetPartyMemberByIndex(id);
    unsigned char amount = ((unsigned char*)obj)[5];
    unsigned short oldCount = c->sub->count;
    ConsumeCounter020482e0(c, amount, 0);
    unsigned short newCount = c->sub->count;
    if (oldCount != newCount) {
        SetBoolFlagAt558((unsigned char*)target, id, 1);
        SetArrayEntryFlag02026f20((int)target, id);
    }
    if (CheckField0NonZero((int*)func_0202ae18())) {
        func_ov017_021c9e00(id, 1, 0, 1);
    }
}
