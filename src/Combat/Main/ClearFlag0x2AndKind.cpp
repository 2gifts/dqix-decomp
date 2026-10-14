#include <globaldefs.h>

struct Combatant_2088644 {
    unsigned char pad0[0x14];
    unsigned int flags14;
    unsigned int flags18;
    unsigned char pad1c[6];
    unsigned short kind : 2;
};

// USA: func_02088644
ARM void ClearFlag0x2AndKind_02088644(struct Combatant_2088644* obj) {
    obj->flags14 &= ~0x2;
    obj->kind = 0;
}
