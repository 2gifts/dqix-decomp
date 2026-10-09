#include <globaldefs.h>

extern "C" void _Z36InitArrEntriesAndClearFlag4_0217f480Pc(char* self);

struct Combatant02180394 {
    char pad0[0x4c];
    int combatantId;
    char pad1[0x87 - 0x50];
    unsigned char active;
    char pad2[0x448 - 0x88];
};

struct Battle02180394 {
    char pad0[0x6c];
    signed char order[4];
    char pad1[0x958 - 0x70];
    struct Combatant02180394 combatants[1];
};

// USA: func_ov000_02180394
extern "C" ARM void func_ov000_02180394(struct Battle02180394* battle) {
    for (int i = 0; i < 4; i++) {
        struct Combatant02180394* c = &battle->combatants[battle->order[i]];
        int valid = 0;
        int id = c->combatantId;
        if (id >= 0 && id <= 3) valid = 1;
        if (valid && c->active) {
            _Z36InitArrEntriesAndClearFlag4_0217f480Pc((char*)c);
        }
    }
}
