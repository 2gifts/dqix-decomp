#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void __clear(void* ptr, int size);
unsigned char CopyOutRegion0x571d_020114ec(char* obj, void* dst);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
extern "C" void func_ov017_021d6134(void*, int);

struct CurrentStats_021ea630 { char pad[4]; unsigned short maxHP; };
struct Combatant_021ea630 { unsigned short flags0; char pad[0x130 - 2]; struct CurrentStats_021ea630* current; };

// USA: func_ov023_021ea630  (semantic: CountCombatantsWithNonPositiveHP_021ea630)
extern "C" ARM int func_ov023_021ea630(void* obj) {
    GameState* bs = GameState::GetInstance();
    unsigned char buf[4];
    __clear(buf, 4);
    int n = CopyOutRegion0x571d_020114ec((char*)bs, buf);
    int count = 0;
    for (int i = 0; i < n; i++) {
        struct Combatant_021ea630* c = (struct Combatant_021ea630*)GetCombatantWithFlag0x100_0200ff1c(bs, buf[i]);
        if (c == NULL) continue;
        if (c->flags0 & 0x1000) continue;
        int hp = c->current->maxHP;
        if (hp <= 0) count++;
    }
    func_ov017_021d6134(obj, count);
    return 1;
}
