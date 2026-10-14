#include <globaldefs.h>
#include "GameState/GameState.h"

struct Outer_02054000;
void* GetActiveSub_02054000(struct Outer_02054000* p);

struct Bits0217c514 {
    unsigned int nibble : 4;
    unsigned int field48 : 5;
    unsigned int rest : 23;
};

struct Sub0217c514 {
    char pad0[8];
    struct Bits0217c514 bits;
    char pad1[0x18 - 0xc];
    short field18;
};

// USA: func_ov000_0217c514  (semantic: SetFlagFromSubField0217c514)
extern "C" ARM int func_ov000_0217c514(int id, int flags) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = GetCombatantWithFlag0x100_0200ff1c(bs, id);
    if (!c) return flags;
    struct Sub0217c514* sub = (struct Sub0217c514*)GetActiveSub_02054000((struct Outer_02054000*)c);
    if (!sub) return flags;
    if (sub->field18 > 0) {
        int ok = (sub->bits.nibble <= 7);
        if (ok) {
            if (sub->bits.field48 <= 11) {
                flags |= 1 << sub->bits.field48;
            }
        }
    }
    return flags;
}
