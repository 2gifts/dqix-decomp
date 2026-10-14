#include <globaldefs.h>

struct Combatant_2088660 {
    unsigned char pad0[0x18];
    unsigned int flags18;
};

// USA: func_02088660
ARM int IsField0x18Flag0x80Set_02088660(struct Combatant_2088660* obj) {
    return (obj->flags18 & 0x80) != 0;
}
