#include <globaldefs.h>
#include "std_library_functions.h"

class GameState;

struct BattleStatus021aa1ac {
    unsigned int flags;
    short pending;
};

struct Combatant021aa1ac {
    char pad0[0x130];
    BattleStatus021aa1ac* status;
    char* name;
};

struct Party021aa1ac {
    char pad0[0xf78];
    signed char memberIds[4];
    unsigned char memberCount;
};

struct Controller021aa1ac {
    char pad0[0x998];
    int messageActive;
    char pad99c[0x19b2 - 0x99c];
    unsigned char messageFlag;
};

struct Self021aa1ac {
    unsigned char pad0;
    unsigned char done;
    char pad2[6];
    short ids[4];
    unsigned char count;
    unsigned char shown;
    unsigned short step;
};

extern "C" GameState* _ZN9GameState11GetInstanceEv(void);
Party021aa1ac* GetPtrField0x2a04(GameState* gameState);
extern "C" Controller021aa1ac* _Z26GetGlobalField0x1c020421a0v(void);
Combatant021aa1ac* GetCombatantWithFlag0x100(GameState* gameState, int combatantId);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" void func_0204500c(Controller021aa1ac* controller, const char* text, int a, int b);
extern "C" int func_ov017_021aa080(void);

extern char data_ov017_021d783c[];
extern char data_ov017_021d7868[];

// USA: func_ov017_021aa1ac
extern "C" ARM void func_ov017_021aa1ac(Self021aa1ac* self) {
    GameState* gs = _ZN9GameState11GetInstanceEv();
    Party021aa1ac* party = GetPtrField0x2a04(gs);
    Controller021aa1ac* controller = _Z26GetGlobalField0x1c020421a0v();
    int memberCount = party->memberCount;
    if (self->step == 0) {
        memset(self->ids, -1, sizeof(self->ids));
        self->shown = 0;
        self->count = 0;
        for (int i = 0; i < memberCount; i++) {
            int id = party->memberIds[i];
            Combatant021aa1ac* combatant = GetCombatantWithFlag0x100(gs, id);
            if (combatant == NULL) {
                continue;
            }
            BattleStatus021aa1ac* status = combatant->status;
            if (status->flags & 1) {
                continue;
            }
            status->pending = 1;
            func_ov017_021c9e00(id, 1, 0, 1);
            self->ids[self->count++] = id;
        }
        if (self->count != 0) {
            char text[0x100];
            __clear(text, sizeof(text));
            sprintf(text, data_ov017_021d783c, GetCombatantWithFlag0x100(gs, self->ids[0])->name);
            if (++self->shown >= self->count) {
                self->step++;
            } else {
                strcat(text, data_ov017_021d7868);
            }
            func_0204500c(controller, text, 0, 0xe3);
            controller->messageFlag = 0;
            controller->messageActive = 1;
        }
        self->step++;
    } else if (self->step == 1) {
        if (func_ov017_021aa080() == 0) {
            return;
        }
        if (self->shown >= self->count) {
            return;
        }
        char text[0x100];
        __clear(text, sizeof(text));
        sprintf(text, data_ov017_021d783c, GetCombatantWithFlag0x100(gs, self->ids[self->shown])->name);
        if (++self->shown >= self->count) {
            self->step++;
        } else {
            strcat(text, data_ov017_021d7868);
        }
        func_0204500c(controller, text, 0, 0xe3);
        controller->messageFlag = 0;
        controller->messageActive = 1;
    } else if (self->step == 2) {
        if (func_ov017_021aa080() != 0) {
            self->done = 1;
        }
    }
}
