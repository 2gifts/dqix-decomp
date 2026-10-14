#include <globaldefs.h>

struct Combatant_20885b4 {
    unsigned char pad0[0x14];
    unsigned int flags14;
    unsigned int flags18;
    unsigned char pad1c[6];
    unsigned short kind : 2;
};

// USA: func_020885b4
ARM int CheckFlag0x2AndKind1_020885b4(struct Combatant_20885b4* obj) {
    if (obj->flags14 & 0x2) {
        if (obj->kind == 1) {
            return 1;
        }
    }
    return 0;
}
