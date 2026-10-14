#include <globaldefs.h>

struct Combatant_2088624 {
    unsigned char pad0[0x14];
    unsigned int flags14;
    unsigned int flags18;
    unsigned char pad1c[6];
    unsigned short kind : 2;
};

// USA: func_02088624
ARM void SetFlag0x2AndKind1_02088624(struct Combatant_2088624* obj) {
    obj->flags14 |= 0x2;
    obj->kind = 1;
}
