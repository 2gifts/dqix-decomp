#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1f2 = 0x1ee };
#else
enum { kRegion1f2 = 0x1f2 };
#endif
#include "GameState/GameState.h"

struct CombatantStatus {
    unsigned int flags;
    unsigned short hp;
};

struct CombatantProfile {
    char name[0x30];
    unsigned short maxHP;
};

struct Combatant {
    char unk_0[0x130];
    CombatantStatus* status;
    CombatantProfile* profile;
};

struct EntryList;

struct PartyStatusPanel {
    char unk_0[0x18];
    EntryList* entries;
    char unk_1c[kRegion1f2 - 0x1c];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

extern "C" Combatant* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState*, int);
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(EntryList*, int, const char*);
extern "C" void _Z22SetEntryHighNibble0x13P17Container02080cc0ii(EntryList*, int, int);
extern "C" void func_020813ec(EntryList*, int);

// JPN: func_ov003_02159820
// USA: func_ov003_02158334
extern "C" ARM void func_ov003_02158334(PartyStatusPanel* self) {
    GameState* gs = GameState::GetInstance();
    int rows = 3;
    int id = 10;

    switch (self->memberCount) {
    case 3:
        rows = 4;
        id = 0xc;
        break;
    case 4:
        rows = 5;
        id = 0xf;
        break;
    }

    EntryList* entries = self->entries;
    for (unsigned char i = 0; i < self->memberCount; i++) {
        Combatant* member = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, self->memberIds[i]);
        if (member != NULL) {
            int color = 0xf;
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii(entries, id, member->profile->name);

            int maxHP = member->profile->maxHP;
            float ratio;
            if (maxHP == 0.0f) {
                ratio = 0.0f;
            } else {
                int hp = member->status->hp;
                ratio = (float)hp / maxHP;
            }
            if (ratio <= 0.25f) color = 0xd;
            if (ratio <= 0.08f) color = 0xb;
            if (member->status->flags & 1) color = 9;

            _Z22SetEntryHighNibble0x13P17Container02080cc0ii(entries, id, color);
        }
        id = (short)(id + 1);
    }

    func_020813ec(entries, rows);
}
