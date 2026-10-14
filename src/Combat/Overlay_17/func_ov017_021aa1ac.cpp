#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Party021aa1ac {
    char pad0[0xf78];
    signed char memberIds[4];
    unsigned char memberCount;
};

struct Controller021aa1ac {
#if defined(jpn)
    char pad0[0x868];
#else
    char pad0[0x998];
#endif
    int messageActive;
#if defined(jpn)
    char pad99c[0x17e2 - 0x86c];
#else
    char pad99c[0x19b2 - 0x99c];
#endif
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

Controller021aa1ac* GetGlobalField0x1c020421a0(void);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
#if defined(jpn)
extern "C" void func_0204500c(Controller021aa1ac* controller, const char* text, int a);
#else
extern "C" void func_0204500c(Controller021aa1ac* controller, const char* text, int a, int b);
#endif
extern "C" int func_ov017_021aa080(void);

extern char data_ov017_021d783c[];
extern char data_ov017_021d7868[];

// USA: func_ov017_021aa1ac
extern "C" ARM void func_ov017_021aa1ac(Self021aa1ac* self) {
    GameState* gs = GameState::GetInstance();
    Party021aa1ac* party = (Party021aa1ac*)GetPtrField0x2a04_02010828(gs);
    Controller021aa1ac* controller = GetGlobalField0x1c020421a0();
    int memberCount = party->memberCount;
    if (self->step == 0) {
        memset(self->ids, -1, sizeof(self->ids));
        self->shown = 0;
        self->count = 0;
        for (int i = 0; i < memberCount; i++) {
            int id = party->memberIds[i];
            GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(gs, id);
            if (combatant == NULL) {
                continue;
            }
            CombatantStatus* status = combatant->combatFields_.savedState_130_;
            if (status->flags & 1) {
                continue;
            }
            status->hp = 1;
            func_ov017_021c9e00(id, 1, 0, 1);
            self->ids[self->count++] = id;
        }
        if (self->count != 0) {
            char text[0x100];
            __clear(text, sizeof(text));
            sprintf(text, data_ov017_021d783c, GetCombatantWithFlag0x100_0200ff1c(gs, self->ids[0])->baseStats_);
            if (++self->shown >= self->count) {
                self->step++;
            } else {
                strcat(text, data_ov017_021d7868);
            }
#if defined(jpn)
            func_0204500c(controller, text, 0);
#else
            func_0204500c(controller, text, 0, 0xe3);
#endif
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
        sprintf(text, data_ov017_021d783c, GetCombatantWithFlag0x100_0200ff1c(gs, self->ids[self->shown])->baseStats_);
        if (++self->shown >= self->count) {
            self->step++;
        } else {
            strcat(text, data_ov017_021d7868);
        }
#if defined(jpn)
        func_0204500c(controller, text, 0);
#else
        func_0204500c(controller, text, 0, 0xe3);
#endif
        controller->messageFlag = 0;
        controller->messageActive = 1;
    } else if (self->step == 2) {
        if (func_ov017_021aa080() != 0) {
            self->done = 1;
        }
    }
}
