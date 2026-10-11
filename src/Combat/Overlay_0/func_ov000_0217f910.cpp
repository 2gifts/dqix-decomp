#include <globaldefs.h>

struct Combatant0217f910 {
    char pad0[0xc];
    short hp;
    char pad1[0x4c - 0xe];
    int combatantId;
#if defined(jpn)
    char pad2[0xc7 - 0x50];
#else
    char pad2[0x87 - 0x50];
#endif
    unsigned char active;
    char pad3[0x445 - 0x88];
    unsigned char field445;
    char pad4[0x448 - 0x446];
};

struct Battle0217f910 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Combatant0217f910 combatants[1];
};

// USA: func_ov000_0217f910
extern "C" ARM int func_ov000_0217f910(struct Battle0217f910* battle) {
    struct Combatant0217f910* c;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        c = &battle->combatants[battle->order[i]];
        int valid = 0;
        int id = c->combatantId;
        if (id >= 0 && id <= 3) valid = 1;
        if (valid && c->active && c->hp != 0 && c->field445) {
            count++;
        }
    }
    return count;
}
