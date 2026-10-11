#include <globaldefs.h>

#if defined(jpn)
enum { kSubOffset = 0x144 };
#else
enum { kSubOffset = 0x150 };
#endif

#include "GameState/GameState.h"

void FilterSlotsWithFlag0x800020dc4d0(signed char* out, signed char* outCount);

struct Sub020dc428 {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};
struct Combatant020dc428 {
    unsigned char pad[kSubOffset];
    struct Sub020dc428* sub;
};

struct Buf020dc428 {
    signed char n;
    signed char ids[7];
};

// USA: func_020dc428  (semantic: CountUnflaggedFilteredSlots020dc428)
extern "C" ARM int func_020dc428(void) {
    struct Buf020dc428 buf;
    FilterSlotsWithFlag0x800020dc4d0(buf.ids, &buf.n);

    signed char active = 0;
    GameState* battle = GameState::GetInstance();
    for (int i = 0; i < buf.n; i++) {
        GameObject* c = GetCombatantWithFlag0x100(battle, buf.ids[i]);
        if (c != 0) {
            int flagSet;
            struct Sub020dc428* sub = ((struct Combatant020dc428*)c)->sub;
            if (sub != 0) {
                flagSet = sub->nibble != 0;
            } else {
                flagSet = 0;
            }
            if (flagSet) {
                active = (signed char)(active + 1);
            }
        }
    }
    buf.n = buf.n - active;
    return buf.n;
}
