#include <globaldefs.h>

struct Combatant_20885e0 {
    unsigned char pad0[0x14];
    unsigned int flags14;
    unsigned int flags18;
    unsigned char pad1c[6];
    unsigned short kind : 2;
};

// USA: func_020885e0
ARM int CheckFlags0x1And0x1000000ClearAndKindNot2_020885e0(struct Combatant_20885e0* obj) {
    int f = obj->flags14;
    if (f & 0x1) {
        return 0;
    }
    if (f & 0x1000000) {
        return 0;
    }
    if (f & 0x2) {
        if (obj->kind == 2) {
            return 0;
        }
    }
    return 1;
}
